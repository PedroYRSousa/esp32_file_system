#include "fs.h"

FILE* fs_file_open(const char* file_path, const char* mode)
{
	FILE* f = NULL;

	f = fopen(file_path, mode);
	if (f == NULL)
		ESP_LOGE(FS_TAG, "Error to open the file %s in mode %s", file_path, mode);

	return (f);
}
