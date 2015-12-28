/*************************************************************************
 *  --------->    FILE: test_add.c
 *  --------->    AUTHOR: Aaron
 *  --------->    MAIL: chengfeizh@gmail.com
 *  --------->    DATE: 12/28/2015    TIME:16:06:36
 ************************************************************************/

#include "check.h"
#include "uni_test.h"
#include "add.h"
START_TEST(test_add) {
    fail_unless(add(2, 3) == 5, "error, 2 + 3 != 5");
}
END_TEST

Suite * make_add_suite(void) {
    Suite *s = suite_create("add");
    TCase *tc_add = tcase_create("add");
    suite_add_tcase(s, tc_add);
    tcase_add_test(tc_add, test_add);
    return s;
}
