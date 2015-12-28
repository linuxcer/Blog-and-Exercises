/*************************************************************************
 *  --------->    FILE: TestAdd.c
 *  --------->    AUTHOR: Aaron
 *  --------->    MAIL: chengfeizh@gmail.com
 *  --------->    DATE: 12/28/2015    TIME:16:52:24
 ************************************************************************/

#include <stdio.h>
#include "check.h"
#include <stdlib.h>

int add(int x1, int x2) {
    return 0;
}

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

int main(void) {
    int n;
    SRunner *sr;
    sr = srunner_create(make_add_suite());
    srunner_run_all(sr, CK_NORMAL);
    n = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (n == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
