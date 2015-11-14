## 1. 论“备份”的重要性
今天手真快，Tab补全文件名后回车，昨天一天写的代码就被我remove了。虽然自己写了脚本备份系统和home目录，但系统是1天一备份，home是2天一次增量备份。又恰巧昨晚没有备份home，并且git也没有提交，欲哭无泪的感觉5555~~。

被remove掉的文件其实是可以恢复的，删除命令**只是在文件节点中作了删除标记，并不是真正清空内容**，但是其他用户和一些有写盘动作的进程会很快覆盖这些数据。所以要想恢复磁盘信息，必须马上**停止任何写磁盘操作**。

我是将整个磁盘卸载下来，用转接线挂到同学笔记本上才恢复成功的，下面将介绍具体的恢复过程。

----------
## 2. 恢复工具介绍

针对Linux下的EXT文件系统来说，常用的误删恢复工具有`debugfs`、`ext3grep`、`extundelete`等等。`extundelete`是一个开源的数据恢复工具，支持**ext3、ext4**文件系统。

我的系统是Ubuntu15.04，文件系统是ext4。尝试了debugfs来恢复，但*没有成功*。如果文件系统不是ext4的同学可以尝试下该方式，这里有篇[参考文档][1]。


----------


## 3. extundelete恢复文件
+ 安装extundelete

		sudo apt-get install extundelete		
			
+ 任何的文件恢复工具，在使用前，均要将要恢复的**分区卸载**或**挂载为只读**，防止数据被覆盖使用。		

		umount /dev/sdb2 
		mount -o remount,ro /dev/sdb2

+ 如果删的文件和操作系统是在同一个分区上，就只有把硬盘卸下来，挂载到另一台主机上。我就是这么干的^_^。

+ 在另一台主机上用`df -h`查看挂载分区。我的分区是`/dev/sdb2`。

+ 在该主机上执行：
	
		extundelete /dev/sdb2 --restore-file /home/zhangchengfei/server.scala
		
+ `extundelete`执行完毕后在当前目录生产一个`RECOVERED_FILES`目录，里面即是恢复出来的文件。

+ 如果想恢复某个文件夹的内容，可以使用下面命令：

		extundelete /dev/sdb2 --restore-directory /hom/zhangchengfei/tmp

+ 关于`extundelete`更多的使用细节，可以用`extundelete -h`进行查看，本文不再叙述。


----------


## 4. 总结经验

其实良好的备份和同步习惯才是最重要的，绝对比恢复数据要更简单。常见的备份策略有tar，rsync，git等等。为了防止以后`rm`误删数据，还有种做法是自己重新定义`rm`，每次不是直接删除文件或文件夹，而是将它们move到你指定的一个目录下存放。具体的实现可以上google搜索。

看这篇博客的朋友一定是遇到和我一样的窘境，祝好运O(∩_∩)O~~

----------
【完】


----------
[1]: http://jingyan.baidu.com/article/2f9b480d6c2bcd41cb6cc223.html

