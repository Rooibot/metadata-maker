#pragma once

#include "CoreMinimal.h"

#if defined(_MSC_VER)
	#define CurrentFunctionName _T(__FUNCSIG__)
#else
	#if defined(__GNUC__) || defined(__clang__)
	#define CurrentFunctionName __PRETTY_FUNCTION__
	#else
	#warning "Unknown platform, falling back to __FUNCTION__, disabling typename feature ..."
	#define CurrentFunctionName __FUNCTION__
	#define NoFunctionNameContext
	#endif
#endif

template <typename _Get_TypeName>
FString GetNativeTypeName(bool bStripContainerSpecifier = false)
{
	static FString TypeName;

	if (TypeName.IsEmpty())
	{
#if defined(NoFunctionNameContext)
		TypeName = TEXT("TYPE_NAME_NOT_SUPPORTED");
#else

#if defined(_MSC_VER)
		const FString SignatureBegin = TEXT("GetNativeTypeName<");
		const FString SignatureEnd = TEXT(">");
#else
		const FString SignatureBegin = TEXT("[_Get_TypeName = ");
		const FString SignatureEnd = TEXT("]");
#endif
		const FString CurrentSignature = CurrentFunctionName;

		// Move cursor to the last character of the signature begin token.
		const int32 TypeNameStartPos = CurrentSignature.Find(SignatureBegin) + SignatureBegin.Len();
		// Move cursor to the signature end token.
		const int32 TypeNameEndPos = CurrentSignature.Find(*SignatureEnd, ESearchCase::IgnoreCase, ESearchDir::FromStart, TypeNameStartPos);
		// Calculate length of the type name by subtracting end of the signature from the start position.
		const int32 TypeNameLength = TypeNameEndPos - TypeNameStartPos;

		// Raw type name. Might include container specifier like 'class', 'struct' or 'enum'.
		TypeName = CurrentSignature.Mid(TypeNameStartPos, TypeNameLength);

#if defined(_MSC_VER)
		if (bStripContainerSpecifier)
		{
			TypeName.RemoveFromStart(TEXT("class "));
			TypeName.RemoveFromStart(TEXT("struct "));
			TypeName.RemoveFromStart(TEXT("enum "));
		}
#endif

#endif
	}

	return TypeName;
}