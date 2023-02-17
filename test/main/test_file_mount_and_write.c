#include "main_test.h"
#include <string.h>

static void test_file_mount_and_write_MustBeReturnESP_OK(void)
{
	const char* mode = "w";
	const char* file = "test";
	const char* text = "Lorem Ipsum";

	TEST_ASSERT_EQUAL(fs_file_mount_and_write(file, text, mode, true), ESP_OK);
}

static void test_file_mount_and_write_MustBeReturnESP_ERR_INVALID_ARG(void)
{
	const char* mode = "w";
	const char* file = "test";
	const char* text = "Lorem Ipsum";

	TEST_ASSERT_EQUAL(fs_file_mount_and_write(NULL, text, mode, true), ESP_ERR_INVALID_ARG);
	TEST_ASSERT_EQUAL(fs_file_mount_and_write(file, NULL, mode, true), ESP_ERR_INVALID_ARG);
	TEST_ASSERT_EQUAL(fs_file_mount_and_write(file, text, NULL, true), ESP_ERR_INVALID_ARG);
	TEST_ASSERT_EQUAL(fs_file_mount_and_write(NULL, NULL, NULL, true), ESP_ERR_INVALID_ARG);
}

static void test_file_mount_and_write_MustBeReturnESP_FAIL(void)
{
	const char* mode = "w";
	const char* file = "/spiffs/test_file_mount_and_write_MustBeReturnESP_ERR_INVALID_ARG";
	const char* text = "Lorem Ipsum";

	TEST_ASSERT_EQUAL(fs_file_mount_and_write(file, text, mode, true), ESP_FAIL);
}

void test_file_mount_and_write_run(void)
{
	RUN_TEST(test_file_mount_and_write_MustBeReturnESP_OK);
	RUN_TEST(test_file_mount_and_write_MustBeReturnESP_ERR_INVALID_ARG);
	RUN_TEST(test_file_mount_and_write_MustBeReturnESP_FAIL);
}
