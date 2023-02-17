#include "main_test.h"

static void test_open_file_IsNullIFNotMounted(void)
{
	const char* file_path = "/spiffs/test";
	const char* mode = "w";

	TEST_ASSERT_NULL(fs_file_open(file_path, mode));
}

static void test_open_file_OpenFile(void)
{
	const char* mode = "w";
	fs_conf_t fs_conf = FS_DEFAULT_CONF_INIT();
	const char* file_path = "/spiffs/test";

	TEST_ASSERT_EQUAL(esp_vfs_spiffs_register(&fs_conf), ESP_OK);
	FILE* f = fs_file_open(file_path, mode);
	TEST_ASSERT_NOT_NULL(f);
	TEST_ASSERT_EQUAL(remove(file_path), 0);
	fclose(f);
	TEST_ASSERT_EQUAL(esp_vfs_spiffs_unregister(fs_conf.partition_label), ESP_OK);
}

void test_open_file_run(void)
{
	RUN_TEST(test_open_file_IsNullIFNotMounted);
	RUN_TEST(test_open_file_OpenFile);
}
