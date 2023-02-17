#include "main_test.h"
#include <string.h>

static void test_file_mount_and_write_all_MustBeReturnESP_OK(void)
{
	const char* mode = "w";
	const char* file = "test";
	const char* texts[] = { "Lorem Ipsum", "a", "b", "c", "d", "1", "2", "3", NULL };

	TEST_ASSERT_EQUAL(_fs_file_mount_and_write_all(file, texts, mode, true), ESP_OK);
}

static void test_file_mount_and_write_all_MustBeReturnESP_ERR_INVALID_ARG(void)
{
	const char* mode = "w";
	const char* file = "test";
	const char* texts[] = { "Lorem Ipsum", "a", "b", "c", "d", "1", "2", "3", NULL };

	TEST_ASSERT_EQUAL(_fs_file_mount_and_write_all(NULL, texts, mode, true), ESP_ERR_INVALID_ARG);
	TEST_ASSERT_EQUAL(_fs_file_mount_and_write_all(file, NULL, mode, true), ESP_ERR_INVALID_ARG);
	TEST_ASSERT_EQUAL(_fs_file_mount_and_write_all(file, texts, NULL, true), ESP_ERR_INVALID_ARG);
	TEST_ASSERT_EQUAL(_fs_file_mount_and_write_all(NULL, NULL, NULL, true), ESP_ERR_INVALID_ARG);
}

static void test_file_mount_and_write_all_MustBeReturnESP_FAIL(void)
{
	const char* mode = "w";
	const char* file = "/spiffs/test_file_mount_and_write_all_MustBeReturnESP_ERR_INVALID_ARG";
	const char* texts[] = { "Lorem Ipsum", "a", "b", "c", "d", "1", "2", "3", NULL };

	TEST_ASSERT_EQUAL(_fs_file_mount_and_write_all(file, texts, mode, true), ESP_FAIL);
}

void test_file_mount_and_write_all_run(void)
{
	RUN_TEST(test_file_mount_and_write_all_MustBeReturnESP_OK);
	RUN_TEST(test_file_mount_and_write_all_MustBeReturnESP_ERR_INVALID_ARG);
	RUN_TEST(test_file_mount_and_write_all_MustBeReturnESP_FAIL);
}
