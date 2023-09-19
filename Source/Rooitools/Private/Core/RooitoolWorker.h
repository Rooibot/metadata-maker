// Copyright 2022 Rooibot Games

#pragma once

#include "CoreMinimal.h"
#include "RooitoolWorker.h"

template <class TData, ENamedThreads::Type NThread = ENamedThreads::AnyThread, ESubsequentsMode::Type SMode = ESubsequentsMode::TrackSubsequents>
class ROOITOOLS_API FRooitoolTask
{
public:
	TData TaskData;

	FRooitoolTask(const TData& InputTaskData) : TaskData(InputTaskData) {}
	virtual ~FRooitoolTask() {};
	
	FORCEINLINE static TStatId GetStatId()
	{
		RETURN_QUICK_DECLARE_CYCLE_STAT(FRooitoolTask, STATGROUP_TaskGraphTasks);
	}

	static ENamedThreads::Type GetDesiredThread() { return NThread; }

	static ESubsequentsMode::Type GetSubsequentsMode() { return SMode; }
	
	void DoTask(ENamedThreads::Type CurrentThread, const FGraphEventRef& CompletionGraphEvent)
	{
		PerformTask();
	}

	/** Actual task body, overridden in subclass implementations. */
	virtual void PerformTask() {};
	
};


/**
 * 
 */
template<class TTask, class TJobData, int MaxPoolSize = 1>
class ROOITOOLS_API FRooitoolWorker
{
	
public:
	FRooitoolWorker()
	{
		PendingJobCount = TotalJobCount = 0;
	}
	virtual ~FRooitoolWorker() {};


	/** Add a new task to our queue. */
	void QueueJob(TJobData& NewTask)
	{
		PendingJobs.Enqueue(NewTask);
		PendingJobCount++;
		TotalJobCount++;
	}

	/** Attempts to start a task for the next bit of data in our queue. */
	bool TryStartNextTask()
	{
		// If we're below our maximum task pool size and have a job pending, create and dispatch an
		// appropriate task.
		if ((GetRunningTasksCount() < MaxPoolSize) && !PendingJobs.IsEmpty())
		{
			TJobData JobData;
			if (PendingJobs.Dequeue(JobData))
			{
				PendingJobCount--;
				RunningTasks.Add(TGraphTask<TTask>::CreateTask(NULL, ENamedThreads::GameThread)
					.ConstructAndDispatchWhenReady(JobData));
				return true;
			}
		}
	
		return false;			
	}

	bool IsFinished() const
	{
		return (GetRunningTasksCount() + PendingJobCount) == 0;		
	}

	void GetTaskCount(int32& OutTotalTasks, int32& OutFinishedTasks, int32& OutRunningTasks, int32& OutPendingTasks) const
	{
		OutTotalTasks = TotalJobCount;
		OutPendingTasks = PendingJobCount;
		OutRunningTasks = GetRunningTasksCount();
		OutFinishedTasks = TotalJobCount - (OutRunningTasks + PendingJobCount);		
	}
	
	/** Return the total number of tasks this worker has running right now. */
	int32 GetRunningTasksCount() const
	{
		int32 RunningCount = 0;
		for (int32 i = 0; i < RunningTasks.Num(); i++)
		{
			if (!RunningTasks[i]->IsComplete())
			{
				RunningCount++;
			}
		}

		return RunningCount;		
	}
	
	/** Return whether or not this work is currently running. */
	bool IsRunning() const
	{
		int32 RunningCount = 0;
		for (int32 i = 0; i < RunningTasks.Num(); i++)
		{
			if (!RunningTasks[i]->IsComplete())
				return true;
		}

		return false;		
	}

	/** Attempts to halt any currently running tasks and gets rid of any still pending. */
	void Cancel()
	{
		RunningTasks.Empty();
		PendingJobs.Empty();
		TotalJobCount = PendingJobCount = 0;		
	}
	
protected:

	/** The array of tasks we're executing on for this session. */
	FGraphEventArray RunningTasks;

	/** A queue of jobs we still need to start. */
	TQueue<TJobData, EQueueMode::Mpsc> PendingJobs;

	/** A count of jobs in the pending queue. */
	int32 PendingJobCount;

	/** All the jobs we've been given in this session. */
	int32 TotalJobCount;
	
};


