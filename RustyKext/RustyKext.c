//
//  RustyKext.c
//  RustyKext
//
//  Created by Phil Jordan on 27/03/2014.
//
//

#include <mach/mach_types.h>
#include <IOKit/IOLib.h>

void rust_main(void);

kern_return_t RustyKext_start(kmod_info_t * ki, void *d);
kern_return_t RustyKext_stop(kmod_info_t *ki, void *d);

kern_return_t RustyKext_start(kmod_info_t * ki, void *d)
{
	rust_main();
	return KERN_SUCCESS;
}

kern_return_t RustyKext_stop(kmod_info_t *ki, void *d)
{
	return KERN_SUCCESS;
}

/* I currently can't find a way to declare variadic C functions in rust, so I've
 * added this wrapper function. Note also that rust strings are not
 * \0-terminated, so I'm using using the %*s format string to pass the length
 * in explicitly. */
void IOLogString(const char* str, int len)
{
	IOLog("%*s", len, str);
}
