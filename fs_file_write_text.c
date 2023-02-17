#include "fs.h"

int fs_file_write_text(FILE* f, const char* text)
{
	return (fprintf(f, "%s", text));
}
