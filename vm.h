#ifndef VM_H
#define VM_H

#include <stdio.h>

#include "obj.h"

#define VM_ADDR_FMT "0x%zx"

struct vm {
	FILE	*in;

	char	*src;
	size_t	 src_len;
	size_t	 src_cap;

	size_t	 pc;
	struct	 obj *prog;
	size_t	 prog_len;
	size_t	 prog_cap;
};

void vm_init(struct vm *, FILE *);
void vm_dump(struct vm *);

#endif
