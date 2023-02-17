#include "fs.h"

esp_err_t fs_file_append_all_texts(const char* file, const char** texts)
{
	if (file == NULL || texts == NULL)
		return (ESP_ERR_INVALID_ARG);

	return (_fs_file_mount_and_write_all(file, texts, "a", false));
}
