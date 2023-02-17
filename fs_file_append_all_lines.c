#include "fs.h"

esp_err_t fs_file_append_all_lines(const char* file, const char** lines)
{
	if (file == NULL || lines == NULL)
		return (ESP_ERR_INVALID_ARG);

	return (_fs_file_mount_and_write_all(file, lines, "a", true));
}
