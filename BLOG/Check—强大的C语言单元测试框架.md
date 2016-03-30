## 1. 前言
在看*基数树*源码时，发现源码里面有个deps的依赖文件夹，deps里是一个叫Check的源码安装包，Google之后发现Check原来是C语言单元测试框架。关于单元测试，Wikipedia的介绍点[这里][1]。

> Check 最主要的优点是对于每一个测试用例的运行都 fork 一个子进程，这么做的原因是因为 C 语言的独特性：
(1) 其它语言如 Java，Python，Ruby等，单元测试出错最多不过是抛出异常；
(2) C 语言如果指针操作错误，乱指一气，可是会 coredump的。测试框架因此直接退出，用户是看不到任何返回的，只有郁闷的 coredump；
(3) Check 的单元测试运行在 fork 的子进程中，可以避免测试框架由于 coredump 而崩溃。


网上介绍Check的使用基本都是同一例子，但如何使用没有说明，下面就详细介绍下如何利用Check进行单元测试。

----------
## 2. Check简单使用
在使用Check前要安装Check，可以直接在终端输入：`sudo apt-get install check`进行安装，也可以使用源码包安装，源码具体安装方法可以参考[官网][2]。

我们现在也是要做一个只做加法的工程，整个工程的文件目录如下图所示，具体代码参考[Github][3]。工程文件夹里的*TestAdd.c*文件是将整个工程都放到了一个文件中，可以直接在终端运行：`gcc TestAdd.c -lcheck`进行编译，然后运行`./test`。
<center>
![结构图](http://img.blog.csdn.net/20151228200137222)
</center>

**TestAdd.c文件**
``` c
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
```

下面介绍下工程中的文件夹功能，add目录下是功能函数，include中是头文件，测试文件在unit_test文件夹，makefile是整个项目的make文件。

**makefile文件**
``` makefile
	vpath %.h include  #vpath 指定搜索路径
	vpath %.c add
	vpath %.c unit_test
	
	objects = add.o test_add.o
	test: test_main.c $(objects)
		gcc -I include $^ -o test -lcheck 
	
	all: $(objects)
	$(objects): %.o: %.c
		gcc -c -I include $< -o $@
	
	.PHONY: clean
	clean:
		rm *.o test
```

**add.c文件**
``` c
	#include "add.h"
	int add(int x1, int x2) {
	    return 0;
	}
```

**add.h文件**
``` c
	#ifndef _ADD_H
	#define _ADD_H
	int add(int x1, int x2);
	#endif
```

**uni_test.h文件**
``` c
	#ifndef _UNI_TEST_H
	#define _UNI_TEST_H
	#include "check.h"
	Suite *make_add_suite(void);
	#endif
```

**test_add.c文件**
``` c
	#include "check.h"
	#include "uni_test.h"
	#include "add.h"
	START_TEST(test_add) {
	    fail_unless(add(2, 3) == 5, "error, 2 + 3 != 5"); // "error, 2 + 3 != 5"是出错提示信息 
	}
	END_TEST
	
	Suite * make_add_suite(void) {
	    Suite *s = suite_create("add");       // 建立Suite
	    TCase *tc_add = tcase_create("add");  // 建立测试用例集
	    suite_add_tcase(s, tc_add);           // 将测试用例加到Suite中
	    tcase_add_test(tc_add, test_add);     // 测试用例加到测试集中
	    return s;
	}
```

**test_main.c文件**
``` c
	#include "uni_test.h"
	#include <stdlib.h>
	
	int main(void) {
	    int n;
	    SRunner *sr;
	    sr = srunner_create(make_add_suite()); // 将Suite加入到SRunner
	    srunner_run_all(sr, CK_NORMAL);
	    n = srunner_ntests_failed(sr);         // 运行所有测试用例
	    srunner_free(sr);
	    return (n == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
	}
```

`make test` 可以编译生成可执行文件**test**，`./test` 运行单元测试程序。

----------
【完】

[1]: https://en.wikipedia.org/wiki/List_of_unit_testing_frameworks
[2]: https://libcheck.github.io/check

[3]: https://github.com/Aaron0927/test/tree/master/C/CheckTEST