#pragma once
#ifndef FS_H
# define FS_H

# ifndef FS_TAG
#  define FS_TAG "FileSystem"
# endif

# ifndef FS_DEFAULT_CONF_INIT
#  define FS_DEFAULT_CONF_INIT()		\
	{									\
		.base_path = "/spiffs",			\
		.partition_label = NULL,		\
		.max_files = 5,					\
		.format_if_mount_failed = true	\
	}
# endif

# include <string.h>
# include <esp_log.h>
# include <esp_err.h>
# include <esp_spiffs.h>

typedef esp_vfs_spiffs_conf_t fs_conf_t;

void _fs_file_close(FILE** f);
FILE* _fs_file_open(const char* file_path, const char* mode);

int _fs_file_write_text(FILE* f, const char* text);
int _fs_file_write_line(FILE* f, const char* line);

esp_err_t _fs_file_open_and_write(const char* file_path, const char* src, const char* mode, bool is_line);
esp_err_t _fs_file_mount_and_write(const char* file, const char* src, const char* mode, bool is_line);

esp_err_t _fs_file_open_and_write_all(const char* file_path, const char** srcs, const char* mode, bool is_line);
esp_err_t _fs_file_mount_and_write_all(const char* file, const char** srcs, const char* mode, bool is_line);

esp_err_t fs_file_write_text(const char* file, const char* text);
esp_err_t fs_file_write_line(const char* file, const char* line);
esp_err_t fs_file_write_all_texts(const char* file, const char** texts);
esp_err_t fs_file_write_all_lines(const char* file, const char** lines);
esp_err_t fs_file_append_text(const char* file, const char* text);
esp_err_t fs_file_append_line(const char* file, const char* line);
esp_err_t fs_file_append_all_texts(const char* file, const char** texts);
esp_err_t fs_file_append_all_lines(const char* file, const char** lines);

#endif

