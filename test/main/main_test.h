#pragma once
#ifndef MAIN_TEST_H
# define MAIN_TEST_H

# include <unity.h>
# include <esp_err.h>
# include <esp_log.h>
# include "fs.h"

void test_conf_run(void);
void test_open_file_run(void);
void test_file_write_text_run(void);
void test_file_write_line_run(void);
void test_file_open_and_write_run(void);
void test_file_mount_and_write_run(void);
void test_file_open_and_write_all_run(void);
void test_file_mount_and_write_all_run(void);
void test_fs_file_write_text_run(void);
void test_fs_file_write_line_run(void);
void test_fs_file_write_all_texts_run(void);
void test_fs_file_write_all_lines_run(void);
void test_fs_file_append_text_run(void);
void test_fs_file_append_line_run(void);
void test_fs_file_append_all_texts_run(void);
void test_fs_file_append_all_lines_run(void);

#endif

