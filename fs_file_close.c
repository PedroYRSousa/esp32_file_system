#include "fs.h"

void fs_file_close(FILE** f)
{
	fclose((*f));
	(*f) = NULL;
}
