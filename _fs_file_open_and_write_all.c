#include "fs.h"

esp_err_t _fs_file_open_and_write_all(const char* file_path, const char** srcs, const char* mode, bool is_line)
{
	FILE* f = NULL;

	if (file_path == NULL || srcs == NULL || mode == NULL)
		return (ESP_ERR_INVALID_ARG);

	if ((f = _fs_file_open(file_path, mode)) == NULL)
		return (ESP_FAIL);

	while ((*srcs))
	{
		if (is_line)
		{
			if (_fs_file_write_line(f, (*srcs)) <= -1)
			{
				_fs_file_close(&f);
				break;
			}
		}
		else
		{
			if (_fs_file_write_text(f, (*srcs)) <= -1)
			{
				_fs_file_close(&f);
				break;
			}
		}
		(srcs)++;
	}

	if (f == NULL)
		return (ESP_FAIL);

	_fs_file_close(&f);
	return (ESP_OK);
}
