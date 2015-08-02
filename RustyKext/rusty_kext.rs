#![crate_type="lib"]
#![feature(lang_items, start, no_std, core, core_str_ext)]
#![no_std]
extern crate core;

use core::str::*;

extern "C" {
	pub fn IOLogString(str: *const i8, len: i32);
}

unsafe fn print(s: &str) {
	IOLogString(s.as_ptr() as *const i8, s.len() as i32);
}

#[no_mangle]
pub unsafe fn rust_main() {
	print("hello from rust\n\0");
}

#[lang = "stack_exhausted"] extern fn stack_exhausted() {}
#[lang = "eh_personality"] extern fn eh_personality() {}
#[lang = "panic_fmt"] fn panic_fmt() -> ! { loop {} }
