/*************************************************************************
 *  --------->    FILE: test_main.c
 *  --------->    AUTHOR: Aaron
 *  --------->    MAIL: chengfeizh@gmail.com
 *  --------->    DATE: 12/28/2015    TIME:16:14:00
 ************************************************************************/

#include "uni_test.h"
#include <stdlib.h>

int main(void) {
    int n;
    SRunner *sr;
    sr = srunner_create(make_add_suite());
    srunner_run_all(sr, CK_NORMAL);
    n = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (n == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
