#include "fs.h"

int fs_file_write_line(FILE* f, const char* line)
{
	return (fprintf(f, "%s\n", line));
}
