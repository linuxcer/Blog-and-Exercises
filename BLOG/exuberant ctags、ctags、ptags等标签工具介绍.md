## 标签工具介绍

>  
 **ctags**：大多数 Unix 系统都能找到。只支持 C。只有基本的功能；
>  
**Exuberant_ctags**：它支持 C、C++、Java、Fortran、Python、Eiffel、PHP等41种语言，详见[这里][1]；
>
**etags**：和 Emacs 有关，支持很多语言；
>
**JTags**：用 Java 编写，为 Java 而设计，可以在[这里][2]找到；
>
**ptags.py**：用 Python 编写，为 Python 而设计，它位于你的 Python 源代码目录 Tools/scripts/ptags.py。
>
**ptags**：用 Perl 编写，为 Perl 而设计，可以在[这里][3]找到；
>
**gnatxref**：为 Ada 而设计，详见[这里][4]。


----------


## Exuberant ctags
1. [下载][1]Exuberant ctags

2. 解压并安装
	`./configure && make && make install`

3. 进入项目目录，执行下面命令：
	`ctags -R`


----------


## ptags.py

1. 找到`ptags.py`，它是在python源码下的`./Tools/scripts/`目录中；

2.  把该文件拷贝到项目目录下，执行下面命令：
	`ptags.py *py`


----------


## cstag: tag not found 解决方案

1. 启动vim之后输入：`:set tags=tags`

2. 在home目录下的.vimrc文件中加入：`set tags=tags`





[1]: http://ctags.sourceforge.net
[2]: http://www.fleiner.com/jtags/
[3]: http://www.eleves.ens.fr:8080/home/nthiery/Tags/
[4]: http://www.gnuada.org/