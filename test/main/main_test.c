#include "main_test.h"

void app_main(void)
{
	UNITY_BEGIN();

	test_conf_run();
	test_open_file_run();
	test_file_write_text_run();
	test_file_write_line_run();
	test_file_open_and_write_run();
	test_file_mount_and_write_run();
	test_file_open_and_write_all_run();
	test_file_mount_and_write_all_run();
	test_fs_file_write_text_run();
	test_fs_file_write_line_run();
	test_fs_file_write_all_texts_run();
	test_fs_file_write_all_lines_run();
	test_fs_file_append_text_run();
	test_fs_file_append_line_run();
	test_fs_file_append_all_texts_run();
	test_fs_file_append_all_lines_run();

	UNITY_END();
}
