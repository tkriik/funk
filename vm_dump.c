#include <assert.h>
#include <ctype.h>
#include <stdio.h>

#include "obj.h"
#include "vm.h"

static void
dump_escaped_char(char c)
{
	if (isprint(c)) {
		fputc(c, stderr);
		return;
	}

	switch (c) {
	case '\n':
		fprintf(stderr, "\\n");
		break;
	case '\t':
		fprintf(stderr, "\\t");
		break;
	case '\r':
		fprintf(stderr, "\\r");
		break;
	default:
		fprintf(stderr, "\\x%u", (unsigned int)c);
		break;
	}
}

static void
dump_escaped_string(const char *s, size_t len)
{
	assert(s != NULL);
	fputc('"', stderr);
	for (size_t i = 0; i < len; i++)
		dump_escaped_char(s[i]);
	fputc('"', stderr);
}

void
vm_dump(struct vm *vm)
{
	assert(vm != NULL);

	fprintf(stderr, "-----BEGIN DUMP-----\n");

	fprintf(stderr, "in: %p\n", (void *)vm->in);

	fprintf(stderr, "src: ");
	dump_escaped_string(vm->src, vm->src_len);
	fputc('\n', stderr);
	fprintf(stderr, "src_len: %zu\n", vm->src_len);
	fprintf(stderr, "src_cap: %zu\n", vm->src_cap);

	fprintf(stderr, "pc: %zu\n", vm->pc);
	fprintf(stderr, "prog:\n");
	for (size_t i = 0; i < vm->prog_len; i++) {
		fprintf(stderr, "    " VM_ADDR_FMT ": ", i);
		obj_dump(vm->prog[i]);
		fputc('\n', stderr);
	}
	fprintf(stderr, "prog_len: %zu\n", vm->prog_len);
	fprintf(stderr, "prog_cap: %zu\n", vm->prog_cap);

	fprintf(stderr, "-----END DUMP-----\n");
}
