#include "main_test.h"
#include <string.h>

static void test_file_open_and_write_MustBeReturnESP_OK(void)
{
	const char* mode = "w";
	fs_conf_t fs_conf = FS_DEFAULT_CONF_INIT();
	const char* file_path = "/spiffs/test";
	const char* text = "Lorem Ipsum";

	TEST_ASSERT_EQUAL(esp_vfs_spiffs_register(&fs_conf), ESP_OK);
	TEST_ASSERT_EQUAL(_fs_file_open_and_write(file_path, text, mode, true), ESP_OK);
	TEST_ASSERT_EQUAL(esp_vfs_spiffs_unregister(fs_conf.partition_label), ESP_OK);
}

static void test_file_open_and_write_MustBeReturnESP_ERR_INVALID_ARG(void)
{
	const char* mode = "w";
	fs_conf_t fs_conf = FS_DEFAULT_CONF_INIT();
	const char* file_path = "/spiffs/test";
	const char* text = "Lorem Ipsum";

	TEST_ASSERT_EQUAL(esp_vfs_spiffs_register(&fs_conf), ESP_OK);
	TEST_ASSERT_EQUAL(_fs_file_open_and_write(NULL, text, mode, true), ESP_ERR_INVALID_ARG);
	TEST_ASSERT_EQUAL(_fs_file_open_and_write(file_path, NULL, mode, true), ESP_ERR_INVALID_ARG);
	TEST_ASSERT_EQUAL(_fs_file_open_and_write(file_path, text, NULL, true), ESP_ERR_INVALID_ARG);
	TEST_ASSERT_EQUAL(_fs_file_open_and_write(NULL, NULL, NULL, true), ESP_ERR_INVALID_ARG);
	TEST_ASSERT_EQUAL(esp_vfs_spiffs_unregister(fs_conf.partition_label), ESP_OK);
}

static void test_file_open_and_write_MustBeReturnESP_FAIL(void)
{
	const char* mode = "w";
	fs_conf_t fs_conf = FS_DEFAULT_CONF_INIT();
	const char* file_path = "/spiffs/test_file_open_and_write_MustBeReturnESP_ERR_INVALID_ARG";
	const char* text = "Lorem Ipsum";

	TEST_ASSERT_EQUAL(esp_vfs_spiffs_register(&fs_conf), ESP_OK);
	TEST_ASSERT_EQUAL(_fs_file_open_and_write(file_path, text, mode, true), ESP_FAIL);
	TEST_ASSERT_EQUAL(_fs_file_open_and_write("test", text, mode, true), ESP_FAIL);
	TEST_ASSERT_EQUAL(esp_vfs_spiffs_unregister(fs_conf.partition_label), ESP_OK);
}

void test_file_open_and_write_run(void)
{
	RUN_TEST(test_file_open_and_write_MustBeReturnESP_OK);
	RUN_TEST(test_file_open_and_write_MustBeReturnESP_ERR_INVALID_ARG);
	RUN_TEST(test_file_open_and_write_MustBeReturnESP_FAIL);
}
