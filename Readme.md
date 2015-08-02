# RustyKext

A currently very minimal OS X kernel extension written partly in the Rust programming language.

 * Writes "hello from rust" to the kernel log when the kext is loaded. That's it.
 * Xcode project assumes that rustc is installed at `/usr/local/bin/rustc`.
 * Uses a variety of features marked as "unstable", so you need a nightly build. Relying on unstable features means this may no longer compile with the latest nightly. I promise it did work with the x86-64 OSX build from 1st August 2015.
 * This currently depends on the "core" library, but it doesn't actually link against it, it only uses some inline functions. I don't know if that's a good idea in the long term.
 * I use the following command line arguments for `rustc`:
	- `--emit obj` - generate .o files, to be linked by Apple's own clang linker.
	- `--crate-type staticlib` - Not sure if this is actually needed.
	- `-C soft-float` - emulate floating-point code and don't use float registers for arguments. Kexts written in C or C++ likewise use -msoft-float with clang to avoid accidentally using floats in the kernel. (It's not disallowed, but doing so has implications.)
	- `-C no-redzone=y` - This is super important: don't use the [x86-64 red zone](https://en.wikipedia.org/wiki/Red_zone_%28computing%29), as interrupt handlers will trample over it.
	- `-C no-stack-check` - Otherwise `___morestack` is an undefined symbol, which we can't really do anything about in the kernel.
 * The panic etc. language features aren't properly wired up yet.
 * Still uses the wrapper RustyKext.c, although I could get rid of that if I knew how to call variadic C functions from Rust.

I wrote [a thing on this](http://philjordan.eu/article/a-minimal-osx-kext-written-in-rust)  back in the Rust 0.9 days. Things have changed quite a bit in Rust-land since then, so it's probably not much use.
