## 1. 下载sbt安装包
下载地址点[这里][1]。


----------


## 2. 解压文件
	tar zxvf sbt-0.13.9.tgz
 


----------


## 3. 建立启动sbt的脚本文件
在`./sbt`目录下面新建文件名为sbt的文本文件
```
$ cd ./sbt
$ vim sbt
# 在sbt文本文件中添加如下信息：
BT_OPTS="-Xms512M -Xmx1536M -Xss1M -XX:+CMSClassUnloadingEnabled -XX:MaxPermSize=256M"
java $SBT_OPTS -jar /home/zhangchengfei/Tools/sbt/bin/sbt-launch.jar "$@" 
```
这里路径需要需改为你自己对应的文件路径，只要能够正确的定位到解压的sbt文件包中的sbt-launch.jar文件即可

修改sbt文件权限

	$ chmod u+x sbt 
	


----------


	
## 4. 配置PATH环境变量
```
$ vim ~/.bashrc
# 在文件尾部添加如下代码后，保存退出
export PATH=/home/zhangchengfei/Tools/sbt/:$PATH
```

使配置文件立刻生效

	$ source ~/.bashrc
 


----------
## 5. sbt设置
+ 配置文件的目录在`./sbt/conf/sbtconfig.txt`

+ 设置网络代理，在配置中添加：
```	
-Dhttp.proxyHost=proxy.zte.com.cn
-Dhttp.proxyPort=80
```

+ 安装完成后会在用户的根目录生成两个文件夹，sbt工作文件夹`.sbt`和lvy缓存目录`.ivy2`，修改默认路径，在配置中添加：
```
-Dsbt.global.base=/home/zhangchengfei/Tools/sbt/.sbt
-Dsbt.ivy.home=/home/zhangchengfei/Toos/sbt/.ivy2
```
**注意：**上面这种方式修改路径我尝试过并没有成功，网上说需要重启系统才能生效。由于电脑当前状态信息太多（开的应用太多）重启后很难恢复，并且这并不影响实验结果，所以没有进一步测试验证。

----------


## 6. 测试sbt是否安装成功
第一次执行时，会下载一些文件包，然后才能正常使用，要确保联网了，安装成功后显示如下
```
$ sbt sbt-version
[info] Set current project to sbt (in build file:/opt/scala/sbt/)
[info] 0.13.9
```


----------
【完】

[1]: http://www.scala-sbt.org/download.html