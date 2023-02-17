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

typedef esp_vfs_spiffs_conf_t fs_conf_t;

#endif

