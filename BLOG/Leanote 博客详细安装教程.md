### 0. 写在前面

本教程仅适合Mac, linux用户。


----------


### 1. 下载leanote二进制版

下载 [leanote 最新二进制版](http://leanote.org/#download)

假设将文件下载到 /home/user1下, 解压文件 
```
$> cd /home/user1
$> tar -xzvf leanote-.tar.gz
```
此时在/home/user1目录下有leanote目录, 可以看看里面有什么:
```
$> cd leanote
$> ls
app  bin  conf  messages  mongodb_backup  public
```
leanote暂时到这里, 下面安装数据库mongodb


----------


### 2. 安装mongodb
到 http://www.mongodb.org/downloads 去下载

* 64位linux mongodb下载链接: http://www.mongodb.org/dr//fastdl.mongodb.org/linux/mongodb-linux-x86_64-2.6.4.tgz/download
* 64位linux mongodb 3.0.1下载链接: https://fastdl.mongodb.org/linux/mongodb-linux-x86_64-3.0.1.tgz

下载到/home/user1下, 直接解压即可
```
$> cd /home/user1
$> tar -xzvf mongodb-linux-x86_64-2.6.4.tgz/
```
为了快速使用mongodb的命令, 可以配置环境变量,

编辑 ~/.profile或/etc/profile 将mongodb bin路径加入即可.
```
$> sudo vim /etc/profile
添加:
export PATH=$PATH:/home/user1/mongodb-linux-x86_64-2.6.4/bin
```
使环境变量生效:
```
$> source /etc/profile
```


----------


### 3. 简单使用mongodb
先在/home/user1下新建一个目录data存放mongodb数据
```
mkdir /home/user1/data
```
```
# 开启mongodb
mongod --dbpath /home/user1/data
```

这时mongod已经启动了

重新打开一个终端, 使用下mongodb
```
$> mongo
> show dbs
...数据库列表
```
mongodb安装到此为止, 下面为mongodb导入数据leanote初始数据


----------


### 4. 导入初始数据
leanote初始数据在 /home/user1/leanote/mongodb_backup/leanote_install_data中

打开终端, 输入以下命令导入数据.

mongodb v2 与 v3 版本导入数据会有些区别.

mongodb v2 导入数据命令:
```
$> mongorestore -h localhost -d leanote --directoryperdb /home/user1/leanote/mongodb_backup/leanote_install_data/
```
mongodb v3 导入数据命令:
```
mongorestore -h localhost -d leanote --dir /home/user1/leanote/mongodb_backup/leanote_install_data/
```
现在在mongodb中已经新建了leanote数据库, 可用命令查看下leanote有多少张表
```
$> mongo
> show dbs #　查看数据库
leanote	0.203125GB
local	0.078125GB
> use leanote # 切换到leanote
switched to db leanote
> show collections # 查看表
files
has_share_notes
note_content_histories
note_contents
....
```

初始数据users表中已有2个用户:
```
user1 username: admin, password: abc123 (管理员, 只有该用户才有权管理后台, 请及时修改密码)
user2 username: demo@leanote.com, password: demo@leanote.com (仅供体验使用)
```


----------


### 5. 配置leanote
文件: conf/app.conf

请修改要修改app.secret, 请随意修改一个值, 若不修改, 会有安全问题!

其它的配置请保持不变, 若需要配置数据库信息, 请查看下文 "问题3"


----------


### 6. 运行leanote

**注意** 在此之前请确保mongodb已在运行!

新开一个窗口, 运行:

```
$> cd /home/user1/leanote/bin
$> bash run.sh (或 sh run.sh)
# 最后出现以下信息证明运行成功
...
TRACE 2013/06/06 15:01:27 watcher.go:72: Watching: /home/life/leanote/bin/src/github.com/leanote/leanote/conf/routes
Go to /@tests to run the tests.
Listening on :9000...
```
恭喜你, 打开浏览器输入: `http://localhost:9000` 体验leanote吧!

如果出现:

* "no reachable server" 请修改conf/app.conf中的 db.host=localhost 为 db.host=127.0.0.1 再重启leanote


----------


### 7. leanote博客主题
博客主题[下载地址](https://github.com/Aaron0927/Leanote-themes)

----------
【完】