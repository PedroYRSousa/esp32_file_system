#include "main_test.h"
#include <string.h>

static void test_file_write_text_OpenAndWriteText(void)
{
	const char* mode = "w";
	fs_conf_t fs_conf = FS_DEFAULT_CONF_INIT();
	const char* file_path = "/spiffs/test";
	const char* text = "Lorem Ipsum";

	TEST_ASSERT_EQUAL(esp_vfs_spiffs_register(&fs_conf), ESP_OK);
	FILE* f = _fs_file_open(file_path, mode);
	TEST_ASSERT_NOT_NULL(f);
	TEST_ASSERT_EQUAL(_fs_file_write_text(f, text), strlen(text));
	TEST_ASSERT_EQUAL(remove(file_path), 0);
	_fs_file_close(&f);
	TEST_ASSERT_NULL(f);
	TEST_ASSERT_EQUAL(esp_vfs_spiffs_unregister(fs_conf.partition_label), ESP_OK);
}

void test_file_write_text_run(void)
{
	RUN_TEST(test_file_write_text_OpenAndWriteText);
}
