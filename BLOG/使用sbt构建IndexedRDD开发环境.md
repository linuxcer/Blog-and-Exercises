## 1. 开发环境
|软件|版本号|
|:---:|:---:|
|Ubuntu|15.04|
|JDK|1.7.0_79|
|Scala|2.10.4|
|spark-assembly|1.3.1-hadoop2.4.0|

**注意**：这里spark-assembly-1.31.-hadoop2.4.0必须要用scala2.10.4，用其他高版本会报错。


----------


## 2. linux 下安装sbt && 配置Intellij环境

+ linux安装sbt详细过程见[这里][1]。

+ 找到文件夹`~/.sbt/0.13/plugins`下的`plugins.sbt`配置文件，如果没有相应文件夹和文件则创建。添加插件：
```
addSbtPlugin("com.typesafe.sbteclipse" % "sbteclipse-plugin" % "2.5.0")

addSbtPlugin("com.github.mpeltonen" % "sbt-idea" % "1.6.0")
```

**注**：之间必须有**空行**，SBT语法要求。第一行用来生成eclipse项目配置文件，第三行用来生成Intellij IDEA的项目配置文件。

----------

## 3. 用sbt创建scala项目

+ **项目结构如下：**
```
├── src
│　 ├── main
│　 │　 ├── java
│　 │　 ├── resources
│　 │　 └── scala
│　 ├── test
│　 │　 ├── java
│　 │　 ├── resources
│　 │　 └── scala
├── build.sbt
├── project
│　 ├── build.properties
│　 ├── plugins.sbt
```

SBT使用的目录结构和MAVEN类似，在`src/main/scala`和`src/test/scala`下编写scala代码。

+ **build.sbt文件修改**
```
name := "spark"

version := "1.0"

scalaVersion := "2.10.4"

libraryDependencies += "org.apache.spark" % "spark-core_2.10" % "1.1.0"
```
设置项目名称、版本、依赖，空行不能省略。如果所有依赖包已经下载下来，这个文件可以为空。

+ **project/build.properties文件修改**
```
sbt.version=0.13.9
```
设置SBT的版本号。

+ **project/build.properties文件修改**
```
addSbtPlugin("com.github.mpeltonen" % "sbt-idea" % "1.6.0")
```
设置插件，如果在sbt安装时已经配置了，此处可以不写。

+ **生成IDE配置**
```
// 如果你使用的是Eclipse：
sbt eclipse

// 如果你使用的是Intellij IDEA项目
sbt gen-idea
```

----------
## 4. Intellij 打开项目

+ 在Intellij中找到刚才建的项目路径，可能提示intellij与`sbt gen-idea`产生的项目版本不兼容需要转换，点击转换项目。老的版本配置被保存到`projectFilesBackup`中。

+ 添加依赖包：

	`file --> Project Structure --> Libraries `
	
	依次添加`spark-assembly-1.3.1-hadoop2.4.0`，`scala2.10.4`，还有项目需要的一些其他jar包

+ 配置打包项

	`file --> Project Structure --> Artifacts --> green + --> JAR --> From modules with dependencies... --> OK`

+ 在需要运行的文件上右键，选择run，配置到此结束，程序成功跑起来。折腾一上午，心里一万个×××，终于配置成功了。


----------
【完】

[1]: http://blog.csdn.net/zcf1002797280/article/details/49677881