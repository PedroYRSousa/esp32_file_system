#include "fs.h"

esp_err_t _fs_file_mount_and_write(const char* file, const char* src, const char* mode, bool is_line)
{
	char file_path[1024] = "";
	fs_conf_t fs_conf = FS_DEFAULT_CONF_INIT();

	if (file == NULL || src == NULL || mode == NULL)
		return (ESP_ERR_INVALID_ARG);

	if (esp_vfs_spiffs_register(&fs_conf) != ESP_OK)
	{
		ESP_LOGE(FS_TAG, "Error to mount the SPIFFS");
		return (ESP_FAIL);
	}

	strcat(file_path, fs_conf.base_path);
	strcat(file_path, "/");
	strcat(file_path, file);

	if (_fs_file_open_and_write(file_path, src, mode, is_line) != ESP_OK)
	{
		ESP_LOGE(FS_TAG, "Error to write the file %s in mode %s", file_path, mode);
		if (esp_vfs_spiffs_unregister(fs_conf.partition_label) != ESP_OK)
		{
			ESP_LOGE(FS_TAG, "Error to unmount the SPIFFS");
			return (ESP_FAIL);
		}
		return (ESP_FAIL);
	}

	if (esp_vfs_spiffs_unregister(fs_conf.partition_label) != ESP_OK)
	{
		ESP_LOGE(FS_TAG, "Error to unmount the SPIFFS");
		return (ESP_FAIL);
	}

	return (ESP_OK);
}
