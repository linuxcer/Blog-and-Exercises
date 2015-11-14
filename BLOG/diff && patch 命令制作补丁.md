## diff 命令

`diff`可以比较两个文件，并可同时记录下二者的区别。制作补丁时的一般用法和常见选项为：

> diff 【选项】 源文件（夹） 目的文件（夹）
**-r**：递归，设置后`diff`会将两个不同版本源代码目录中的所有对应文件都进行一次比较，包括子目录文件；
**-N**：确保补丁文件将正确地处理已经创建或删除文件的情况；
**-u**：一体化`diff`输出（参见例1）
-E, -b, -w, -B, --strip-trailing-cr
忽略各种空白，可参见文档，按需选用。

例1，有如下两个差异文件：
``` markdown
# version1.txt
this is the original text
line2
line3
line4
happy hacking!

#version2.txt
this is the original text
line2
line4
happy hacking!
GNU is not UNIX
```
非一体化`diff`输出：
![非一体化`diff`输出](http://img.blog.csdn.net/20151028140514966)

一体化`diff`输出（加`-u`参数）：
![一体化`diff`输出](http://img.blog.csdn.net/20151028140945475)

将上面的差异输出重定向到一个文件中，
``` SHELL
diff -u version1.txt version2.txt > version.patch
```
这个文件就是**补丁文件**，可以用patch命令将修改应用与任意文件。

## patch 命令
`patch`的作用则是将`diff`记录的结果（即补丁）应用到相应文件（夹）上。最常见的用法为：
>  patch -pNUM <补丁文件
**-p Num**：忽略几层文件夹，随后详解；
**-E**：说明如果发现了空文件，那么就删除它；
**-R**：取消打过的补丁。

为了解释 -p 参数，需要看看如下patch文件片段：
``` SHELL
--- old/modules/pcitable       Mon Sep 27 11:03:56 1999
+++ new/modules/pcitable       Tue Dec 19 20:05:41 2000
```
+ 如果使用参数`-p0`，那就表示忽略当前old文件夹开始执行`patch`操作；

+ 如果使用参数`-p1`，表示忽略第一层目录（即不管old），从 modules 文件夹开始进行`patch`操作。

## 应用

利用以上命令，处理单个文件补丁的方法：
``` SHELL
# 产生补丁
diff -uN file1 file2 >file.patch
 
# 打补丁
patch -p0 < file.patch
 
# 取消补丁
patch -RE -p0 < file.patch
```

对整个文件夹打补丁的情况：
``` SHELL
# 产生补丁
diff -uNr dir1 dir2  >dir.patch
 
# 打补丁
cd dir2
patch -p1 < dir.patch
 
# 取消补丁
patch -R -p1 <dir.patch
```

## patch 文件构成
补丁文件里到底存储了哪些信息呢？看看这个例子：

``` SHELL
--- test0       2006-08-18 09:12:01.000000000 +0800
+++ test1       2006-08-18 09:13:09.000000000 +0800
@@ -1,3 +1,4 @@
+222222
 111111
-111111
+222222
 111111
```
 
 **补丁头**
 补丁头是分别由---/+++开头的两行，用来表示要打补丁的文件。---开头表示旧文件，+++开头表示新文件。
 
**一个补丁文件中的多个补丁**
一个补丁文件中可能包含以---/+++开头的很多节，每一节用来打一个补丁。所以在一个补丁文件中可以包含好多个补丁。

**块**
块是补丁中要修改的地方。它通常由一部分不用修改的东西开始和结束。他们只是用来表示要修改的位置。他们通常以`@@`开始，结束于另一个块的开始或者一个新的补丁头。

**块的缩进**
块会缩进一列，而这一列是用来表示这一行是要增加还是要删除的。

**块的第一列**
+号表示这一行是要加上的。-号表示这一行是要删除的。没有加号也没有减号表示这里只是引用的而不需要修改。

