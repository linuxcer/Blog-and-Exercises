 ## Java历史

Java语言是Sun公司于1990开发的，2009年4月20日，Sun公司被Oracle公司收购，官方网站参考[这里][1]。


----------

## JDK和SDK区别


很多程序员会用Java，但一些基本概念不是很清楚，比如什么是JDK和SDK，以及两者的区别。

> JDK(Java Development Kit) 是Java语言的软件开发工具包(Software Development Kit, SDK)。

+ 软件开发工具包，是一个广义的概念，任何编程工具几乎都可以看成SDK。而JDK是Java Development Kit，是Sun公司针对Java编程的产品，范围仅限于Java。

+ 也就是说，JDK是SDK的一种，两者不是完全一样的。所以需要去sun公司官网下载jdk，才能正常编写java程序。

+ 从概念上打比如`SDK=人`，`JDK=张三`，你可以让`张三`干活，但你不可以让`人`去干活。


----------

## JDK版本介绍

根据不同的开发需求，JDK主要分为3个方向：

1. *SE(J2SE)，standard edition*，标准版，是我们通常用的一个版本，从JDK 5.0开始，改名为**Java SE**。

2. *EE(J2EE)，enterprise edition*，企业版，使用这种JDK开发J2EE应用程序，从JDK 5.0开始，改名为**Java EE**。

3. *ME(J2ME)，micro edition*，主要用于移动设备、嵌入式设备上的java应用程序，从JDK 5.0开始，改名为**Java ME**。


----------

## linux下JDK环境变量设置
1. 下载JDK，下载地址参见[这里][2]。

2. 将下载文件拷贝到/home/zhangchengfei/目录下，这里是我自己的home目录。

3. 在home目录下`.bashrc`中加入如下代码：

	``` bash 
	export JAVA_HOME=/home/zhangchengfei/jdk1.7.0_71
	export PATH=$PATH:$JAVA_HOME/bin
	export CLASSPATH=.:$JAVA_HOME/jre/lib/rt.jar:$JAVA_HOME/jre/lib/dt.jar:$JAVA_HOME/jre/lib/tools.jar
	```
4. 使`.bashrc`文件生效，执行命令：`source .bashrc`


[1]: http://www.oracle.com/technetwork/cn/java/javase/downloads/jdk7-downloads-1880260.html
[2]: http://download.oracle.com/otn-pub/java/jdk/7u79-b15/jdk-7u79-linux-x64.tar.gz