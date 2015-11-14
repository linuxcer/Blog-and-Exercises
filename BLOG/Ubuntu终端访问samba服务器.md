> 习惯终端访问文件和目录，每次访问实验室samba服务器都要动鼠标，好麻烦～_~，呵呵，发现自己好懒。在google搜索找到终端访问samba好多方法，下面整理了两种方法：第一种是使用smbclient访问samba服务器，第二种是直接将共享目录挂载到自己的电脑上，强烈推荐第二种。


----------


## 1. smbclient安装

		sudo apt-get install smbclient


----------


## 2. 查看目录的所有共享目录

		smbclient -L 10.0.0.11 # 10.0.0.11是samba服务器IP
![这里写图片描述](http://img.blog.csdn.net/20151112211533186)

注：敲入上面命令后，在出现提示输入密码时，直接按Enter键（因为此处是匿名访问），结果会显示指定Samba服务器上当前全部的共享目录。（还发现一个小秘密，原来我们服务器Jing的文件夹原来是精华的意思，真佩服我们大师兄+_+。）


----------


## 3. 连接共享目录

		smbclient //10.0.0.11/Jing  # IP地址后接共享目录

成功后出现提示符`smb:\>`，下面就可以开始操作。


----------


## 4. smbclient 常用命令
```
	?或help [command]         提供关于帮助或某个命令的帮助
	
	![shell command]        执行所用的SHELL命令，或让用户进入 SHELL提示符
	
	cd [目录]        切换到服务器端的指定目录，如未指定，则 smbclient 返回当前本地目录
	
	lcd [目录]        切换到客户端指定的目录；
	
	dir 或ls        列出当前目录下的文件；
	
	exit 或quit        退出smbclient     
	
	get file1  file2        从服务器上下载file1，并以文件名file2存在本地机上；如果不想改名，可以把file2省略
	
	mget file1 file2 file3  filen        从服务器上下载多个文件；
	
	md或mkdir 目录        在服务器上创建目录
	
	rd或rmdir   目录        删除服务器上的目录
	
	put file1 [file2]        向服务器上传一个文件file1,传到服务器上改名为file2；
	
	mput file1 file2 filen  向服务器上传多个文件
```


----------


## 5. 将共享目录挂载到本地
		
		mount -t cifs -o username=xxx,password=xxx //10.0.0.11/Jing /home/zhangchengfei/tmp

我的系统环境是Ubuntu15.04，内核版本3.19，挂载方式已经不支持`smbfs`，最新内核使用`cifs`。

【注】我的环境上实际环境下执行的是下面语句，不需要指定`password`，并且`username`可以任意命名：

		mount -t cifs -o username=abc //10.0.0.11/Jing /home/zhangchengfei/tmp


----------


【完】