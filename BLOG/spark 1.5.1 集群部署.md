## 实验环境

操作系统：ubuntu 14.04 64位
|主机名|IP|
|:---:|:---:|
|Master|10.107.12.10|
|Worker1|10.107.12.20|
|Worker2|10.107.12.50|
|Worker3|10.107.12.60|


----------


## JDK 安装

实验安装的是jdk1.7.0_71版本，具体安装步骤及环境变量设置参考[这里][1]。


----------


## SSH 无密登录

下面是我写的一个自动化SSH 无密登录脚本，运行脚本前需要安装`expect`包，ubuntu 系统下直接执行：`sudo apt-get install expect`就可以了。该脚本运行在namenode上，运行时只需要将**IP_1**改成对应的datanode地址，**PWD_1**是对应datanode密码。

``` SHELL
# NO_PWD_SSH
#!/bin/sh 
IP_1=10.107.12.20,10.107.12.50,10.107.12.60
PWD_1=111111

key_generate() {
    expect -c "set timeout -1;
        spawn ssh-keygen -t dsa;
        expect {
            {Enter file in which to save the key*} {send -- \r;exp_continue}
            {Enter passphrase*} {send -- \r;exp_continue}
            {Enter same passphrase again:} {send -- \r;exp_continue}
            {Overwrite (y/n)*} {send -- n\r;exp_continue}
            eof             {exit 0;}
    };"
}

auto_ssh_copy_id () {
    expect -c "set timeout -1;
        spawn ssh-copy-id -i $HOME/.ssh/id_dsa.pub root@$1;
            expect {
                {Are you sure you want to continue connecting *} {send -- yes\r;exp_continue;}
                {*password:} {send -- $2\r;exp_continue;}
                eof {exit 0;}
            };"
}

rm -rf ~/.ssh

key_generate

ips_1=$(echo $IP_1 | tr ',' ' ')
for ip in $ips_1
do
    auto_ssh_copy_id $ip  $PWD_1
done

eval &(ssh-agent)
ssh-add
```


----------
## 安装 scala
### 1. 下载 scala 2.11.4

下载地址点[这里][2]。

### 2. 解压
`tar zxvf scala-2.11.4.tgz`解压，解压后放在了`/root/spark_sdk/`目录下。

``` SHELL
tar zxvf scala-2.11.4.tgz
```
	
### 3. 设置环境变量
在`~/.bashrc`文件中加入如下命令：

``` SHELL
export SCALA_HOME=/root/spark_sdk/scala-2.11.4
PATH=$PATH:$SCALA_HOME/bin
```
使环境变量生效：` source ~/.bashrc`


----------


## 安装 Spark 1.5.1

### 1. 下载 Spark 1.5.1

下载地址点[这里][3]。

### 2. 解压
`tar zxvf spark-1.5.1-bin-hadoop2.6.tgz`解压，解压后放在了`/root/spark_sdk/`目录下。

### 3. 设置环境变量

在`~/.bashrc`文件中加入如下命令：

``` SHELL
export SPARK_HOME=/root/spark_sdk/spark-1.5.1-bin-hadoop2.6 
PATH=$PATH:$SPARK_HOME/bin:$SPARK_HOME/sbin
```

使环境变量生效：` source ~/.bashrc`


### 4. 修改Spark 配置文件

**spark-env.sh 文件**

```
export JAVA_HOME=/root/spark_sdk/jdk1.7.0_71
```

**yarn-env.sh 文件**

```
export SCALA_HOME=/root/spark_sdk/scala-2.11.4
export JAVA_HOME=/root/spark_sdk/jdk1.7.0_71
export SPARK_MASTER_IP=10.107.12.10
export SPARK_WORKER_MEMORY=2048m
export HADOOP_CONF_DIR=/root/spark_sdk/hadoop-2.7.1/etc/hadoop
```

这里10.107.12.10是Master节点IP

**slaves 文件**

```
10.107.12.20
10.107.12.50
10.107.12.60
```
上面3个IP分别对应的是Worker节点的IP。

### 5. 启动Spark

```
./sbin/start-all.sh
```

### 6. 集群启动验证

执行`jps`命令，可以查询到有如下进程说明集群部署成功！
```
Master
Worker
```

**运行SparkPi**

``` SHELL
spark-submit  --master spark://10.107.12.10:7077 --class org.apache.spark.examples.SparkPi --name Spark-Pi /root/spark_sdk/spark-1.5.1-bin-hadoop2.6/lib/spark-examples-1.5.1-hadoop2.6.0.jar
```

**使用web查看Spark运行状态**
```
http://10.107.12.10:8080
```
这里的IP就是Master节点地址。

### 7.  关闭集群

关闭集群执行`sbin/stop-all.sh`。


----------


【完】
[1]: http://blog.csdn.net/zcf1002797280/article/details/49450075
[2]: http://downloads.typesafe.com/scala/2.11.4/scala-2.11.4.tgz
[3]: http://www.apache.org/dyn/closer.lua/spark/spark-1.5.1/spark-1.5.1-bin-hadoop2.6.tgz