#include "fs.h"

esp_err_t _fs_file_open_and_write(const char* file_path, const char* src, const char* mode, bool is_line)
{
	FILE* f = NULL;

	if (file_path == NULL || src == NULL || mode == NULL)
		return (ESP_ERR_INVALID_ARG);

	if ((f = _fs_file_open(file_path, mode)) == NULL)
		return (ESP_FAIL);

	if (is_line)
	{
		if (_fs_file_write_line(f, src) <= -1)
			_fs_file_close(&f);
	}
	else
	{
		if (_fs_file_write_text(f, src) <= -1)
			_fs_file_close(&f);
	}

	if (f == NULL)
		return (ESP_FAIL);

	_fs_file_close(&f);
	return (ESP_OK);
}
