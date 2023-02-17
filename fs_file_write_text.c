#include "fs.h"

esp_err_t fs_file_write_text(const char* file, const char* text)
{
	if (file == NULL || text == NULL)
		return (ESP_ERR_INVALID_ARG);

	return (_fs_file_mount_and_write(file, text, "w", false));
}
