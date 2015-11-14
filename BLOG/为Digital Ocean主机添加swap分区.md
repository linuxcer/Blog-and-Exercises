## 起因
Digital Ocean基础配置(512MB内存，20G固态硬盘，每月1TB流量)才5刀/月的价格让人想抗拒都难。不过512MB的内存用起来还是有点紧张的，今天用`free -h`查看内存使用情况时，发现居然没有swap分区。不知道DigitalOcean是什么打算（--__--）。


----------


## swap分区

当系统的物理内存不够用的时候，就需要将物理内存中的一部分空间释放出来，以供当前运行的程序使用。那些被释放的空间可能来自一些很长时间没有什么操作的程序，这些被释放的空间被临时保存到Swap空间中，等到那些程序要运行时，再从Swap中恢复保存的数据到内存中。系统总是在物理内存不够时，才进行Swap交换。基础配置的VPS启用Swap空间能有效提高主机的性能。


----------


## swap分区大小
实际上，我们更关注的应该是SWAP分区的大小问题。 设置多大才是最优的。
 
 > 
一般来说可以按照如下规则设置swap大小：
4G以内的物理内存，SWAP 设置为内存的2倍。
4-8G的物理内存，SWAP 等于内存大小。
8-64G 的物理内存，SWAP 设置为8G。
64-256G物理内存，SWAP 设置为16G。
 
实际上，系统中交换分区的大小并不取决于物理内存的量，而是取决于系统中内存的负荷，所以在安装系统时要根据具体的业务来设置SWAP的值。这里我们设置swap分区大小为1GB。


----------

## 启用swap分区

**检查是否已经适用了Swap空间**
打开终端，输入`swapon -s`命令，如果没有任何的信息返回，那就是还没有启用Swap空间。


**检查文件系统**
知道我们还没有启动Swap空间后，我们再检查一下我们的硬盘还剩下多少空间可以使用，使用`df`命令查看。在本例中，我们将创建一个1GB大小的Swap空间文件。

**创建并使用Swap空间文件**

1. 创建swap文件
	`dd if=/dev/zero of=/swapfile bs=1024 count=1M`

	> 该命令将创建一个大小为1GB，文件名为swapfile的Swap空间文件；
	> 
	> of=/swapfile参数指定了文件的创建位置和文件名；
	
	> count=1M指定了文件的大小。 

2. 格式化swap分区
	`mkswap /swapfile`
	
3. 激活swap分区	
	`swapon /swapfile`

4. 查询swap分区
	`swapon -s`
	
但以上的设置是一次性的，重启后将失效。想要确保系统永久的启用Swap交换空间，可以通过编辑fstab文件。
			
		vim /etc/fstab
		在最后一行添加上下面一条：
		/swapfile     swap     swap     defaults     0  0

添加成功后给swap赋予相关权限：

		chown root:root /swapfile
		chmod 0600 /swapfile


----------

## 配置swappiness

实际上，并不是等所有的物理内存都消耗完毕之后，才去使用swap的空间，什么时候使用是由swappiness 参数值控制。
 
	`cat /proc/sys/vm/swappiness`

默认值是60.

**swappiness=0** 的时候表示最大限度使用物理内存，然后才是 swap空间，

**swappiness＝100** 的时候表示积极的使用swap分区，并且把内存上的数据及时的搬运到swap空间里面。
 
**临时性修改**

	sysctl vm.swappiness=10
	cat /proc/sys/vm/swappiness

这里我们的修改已经生效，但是如果我们重启了系统，又会变成60.
 
**永久修改**

在`/etc/sysctl.conf `文件里添加如下参数：`vm.swappiness=10`
 
 保存，重启。