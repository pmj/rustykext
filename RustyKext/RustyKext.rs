#[allow(ctypes)];
#[no_std];

extern "rust-intrinsic" {
	pub fn transmute<T,U>(val: T) -> U;
}

extern "C" {
	pub fn IOLog(fmt: *u8);
}

#[no_split_stack]
unsafe fn print(s: &str) {
	let (ptr, _): (*u8, uint) = transmute(s);
	IOLog(ptr);
}

#[no_mangle]
#[no_split_stack]
pub unsafe fn rust_main() {
	print("hello from rust\n\0");
}
