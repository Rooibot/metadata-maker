# Rooitools Editor Plugin

This project contains a slimmed-down version of the "Rooitools" editor plugin used internally by Rooibot, with any of the tools that depend on other Rooibot plugins or modules stripped out. At present, the only tool left is the Metadata Maker tool, but as that's the one other people might find useful it seemed worth sticking into a public repository.

Currently, the plugin requires Unreal Engine 5.2 or later to run.

### Installation

Basically just take the contents of this repository and put them into a `Plugins/Rooitools` directory within your project. Recompile and, bam, you should have a "Rooitools" menu option on the end of your menubar, which provides exactly one thing (Metadata Maker). Sorry about that being in its own menu; since the real Rooitools has a whole bunch of other internal tools in there, the menu _is_ normally useful... and I didn't bother to change that when I slimmed this down. 

(Sorry. But on the other hand, free editor plugin, so... yay?)

## Metadata Maker

### Functionality

The "Metadata Maker" tool is designed to take root-motion animations and convert them to in-place, while generating a whole mess of metadata about what the root motion used to contain. Some example common operations are:

* Generating a curve that tracks the overall movement speed.
* Generating a curve that details how far forward the character has moved from the start.
* Generating a curve that details how much the character's yaw has changed since the start.
* Generating Lyra-style distance-matching curves (e.g. `Distance` and `YawRemaining`).
* Generating 'breakpoint' tracks, such as for ALS. (Note: I don't use this one, but a friend asked for it. Perhaps not as tested as the others.)

Unfortunately, the portion that generates animation notify events and animation sync markers relies on the specific Rooibot notifies/sync markers, so I've stripped that out here.

This is presented pretty much 'as-is'; feel free to use, tweak, and contribute back patches, but I'm not super interested in turning this into a paid marketplace plugin (or providing that level of support). I'm releasing this mostly because I got a request from a _third_ friend to give them a copy, at which point I decided I might as well just toss this up on a public repository.

### Future Plans

The number of times someone asked for a copy of the metadata tool has been high enough that I've decided it's probably worth taking the metadata maker portion of this and rewriting it almost from-scratch to be more flexible (and to make it possible to define new track tasks without having to edit the source code). As such, I'm probably not going to add a ton of additional functionality to this little slimmed-down fork of Rooitools.

I _do_ plan to release whatever more-generalized metadata tool replaces this as an open source project as well, so there's that.