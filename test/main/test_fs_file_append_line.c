#include "main_test.h"
#include <string.h>

static void test_fs_file_append_line_MustBeReturnESP_OK(void)
{
	const char* file = "test";
	const char* text = "Lorem Ipsum";

	TEST_ASSERT_EQUAL(fs_file_append_text(file, text), ESP_OK);
}

static void test_fs_file_append_line_MustBeReturnESP_FAIL(void)
{
	const char* file = "test_fs_file_append_line_MustBeReturnESP_ERR_INVALID_ARG";
	const char* text = "Lorem Ipsum";

	TEST_ASSERT_EQUAL(fs_file_append_text(file, text), ESP_FAIL);
}

static void test_fs_file_append_line_MustBeReturnESP_ERR_INVALID_ARG(void)
{
	const char* file = "test";
	const char* text = "Lorem Ipsum";

	TEST_ASSERT_EQUAL(fs_file_append_text(NULL, text), ESP_ERR_INVALID_ARG);
	TEST_ASSERT_EQUAL(fs_file_append_text(file, NULL), ESP_ERR_INVALID_ARG);
	TEST_ASSERT_EQUAL(fs_file_append_text(NULL, NULL), ESP_ERR_INVALID_ARG);
}

void test_fs_file_append_line_run(void)
{
	RUN_TEST(test_fs_file_append_line_MustBeReturnESP_OK);
	RUN_TEST(test_fs_file_append_line_MustBeReturnESP_FAIL);
	RUN_TEST(test_fs_file_append_line_MustBeReturnESP_ERR_INVALID_ARG);
}
