#include "main_test.h"
#include <string.h>

static void test_fs_file_append_all_lines_MustBeReturnESP_OK(void)
{
	const char* file = "test";
	const char* texts[] = { "Lorem Ipsum", "a", "b", "c", "d", "1", "2", "3", NULL };

	TEST_ASSERT_EQUAL(fs_file_append_all_lines(file, texts), ESP_OK);
}

static void test_fs_file_append_all_lines_MustBeReturnESP_FAIL(void)
{
	const char* file = "test_fs_file_append_all_lines_MustBeReturnESP_ERR_INVALID_ARG";
	const char* texts[] = { "Lorem Ipsum", "a", "b", "c", "d", "1", "2", "3", NULL };

	TEST_ASSERT_EQUAL(fs_file_append_all_texts(file, texts), ESP_FAIL);
}

static void test_fs_file_append_all_lines_MustBeReturnESP_ERR_INVALID_ARG(void)
{
	const char* file = "test";
	const char* texts[] = { "Lorem Ipsum", "a", "b", "c", "d", "1", "2", "3", NULL };

	TEST_ASSERT_EQUAL(fs_file_append_all_texts(NULL, texts), ESP_ERR_INVALID_ARG);
	TEST_ASSERT_EQUAL(fs_file_append_all_texts(file, NULL), ESP_ERR_INVALID_ARG);
	TEST_ASSERT_EQUAL(fs_file_append_all_texts(NULL, NULL), ESP_ERR_INVALID_ARG);
}

void test_fs_file_append_all_lines_run(void)
{
	RUN_TEST(test_fs_file_append_all_lines_MustBeReturnESP_OK);
	RUN_TEST(test_fs_file_append_all_lines_MustBeReturnESP_FAIL);
	RUN_TEST(test_fs_file_append_all_lines_MustBeReturnESP_ERR_INVALID_ARG);
}
