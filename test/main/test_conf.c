#include "main_test.h"

static void test_conf_CheckDefaultValues(void)
{
	fs_conf_t conf = FS_DEFAULT_CONF_INIT();

	TEST_ASSERT_EQUAL(conf.base_path, "/spiffs");
	TEST_ASSERT_NULL(conf.partition_label);
	TEST_ASSERT_EQUAL(conf.max_files, 5);
	TEST_ASSERT_EQUAL(conf.format_if_mount_failed, true);
}

void test_conf_run(void)
{
	RUN_TEST(test_conf_CheckDefaultValues);
}
