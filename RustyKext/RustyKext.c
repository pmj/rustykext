//
//  RustyKext.c
//  RustyKext
//
//  Created by Phil Jordan on 27/03/2014.
//
//

#include <mach/mach_types.h>

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

