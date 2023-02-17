#include "main_test.h"
#include <string.h>

static void test_file_open_and_write_all_MustBeReturnESP_OK(void)
{
	const char* mode = "w";
	fs_conf_t fs_conf = FS_DEFAULT_CONF_INIT();
	const char* file_path = "/spiffs/test";
	const char* texts[] = { "Lorem Ipsum", "a", "b", "c", "d", "1", "2", "3", NULL };

	TEST_ASSERT_EQUAL(esp_vfs_spiffs_register(&fs_conf), ESP_OK);
	TEST_ASSERT_EQUAL(_fs_file_open_and_write_all(file_path, texts, mode, true), ESP_OK);
	TEST_ASSERT_EQUAL(esp_vfs_spiffs_unregister(fs_conf.partition_label), ESP_OK);
}

static void test_file_open_and_write_all_MustBeReturnESP_ERR_INVALID_ARG(void)
{
	const char* mode = "w";
	fs_conf_t fs_conf = FS_DEFAULT_CONF_INIT();
	const char* file_path = "/spiffs/test";
	const char* texts[] = { "Lorem Ipsum", "a", "b", "c", "d", "1", "2", "3", NULL };

	TEST_ASSERT_EQUAL(esp_vfs_spiffs_register(&fs_conf), ESP_OK);
	TEST_ASSERT_EQUAL(_fs_file_open_and_write_all(NULL, texts, mode, true), ESP_ERR_INVALID_ARG);
	TEST_ASSERT_EQUAL(_fs_file_open_and_write_all(file_path, NULL, mode, true), ESP_ERR_INVALID_ARG);
	TEST_ASSERT_EQUAL(_fs_file_open_and_write_all(file_path, texts, NULL, true), ESP_ERR_INVALID_ARG);
	TEST_ASSERT_EQUAL(_fs_file_open_and_write_all(NULL, NULL, NULL, true), ESP_ERR_INVALID_ARG);
	TEST_ASSERT_EQUAL(esp_vfs_spiffs_unregister(fs_conf.partition_label), ESP_OK);
}

static void test_file_open_and_write_all_MustBeReturnESP_FAIL(void)
{
	const char* mode = "w";
	fs_conf_t fs_conf = FS_DEFAULT_CONF_INIT();
	const char* file_path = "/spiffs/test_file_open_and_write_all_MustBeReturnESP_ERR_INVALID_ARG";
	const char* texts[] = { "Lorem Ipsum", "a", "b", "c", "d", "1", "2", "3", NULL };

	TEST_ASSERT_EQUAL(esp_vfs_spiffs_register(&fs_conf), ESP_OK);
	TEST_ASSERT_EQUAL(_fs_file_open_and_write_all(file_path, texts, mode, true), ESP_FAIL);
	TEST_ASSERT_EQUAL(_fs_file_open_and_write_all("test", texts, mode, true), ESP_FAIL);
	TEST_ASSERT_EQUAL(esp_vfs_spiffs_unregister(fs_conf.partition_label), ESP_OK);
}

void test_file_open_and_write_all_run(void)
{
	RUN_TEST(test_file_open_and_write_all_MustBeReturnESP_OK);
	RUN_TEST(test_file_open_and_write_all_MustBeReturnESP_ERR_INVALID_ARG);
	RUN_TEST(test_file_open_and_write_all_MustBeReturnESP_FAIL);
}
