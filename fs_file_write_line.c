#include "fs.h"

esp_err_t fs_file_write_line(const char* file, const char* line)
{
	if (file == NULL || line == NULL)
		return (ESP_ERR_INVALID_ARG);

	return (_fs_file_mount_and_write(file, line, "w", true));
}
