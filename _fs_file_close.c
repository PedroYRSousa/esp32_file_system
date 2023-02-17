#include "fs.h"

void _fs_file_close(FILE** f)
{
	fclose((*f));
	(*f) = NULL;
}
