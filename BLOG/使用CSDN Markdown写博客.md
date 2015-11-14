

## １. Markdown介绍

> Markdown 是一种轻量级标记语言，它允许人们使用易读易写的纯文本格式编写文档，然后转换成格式丰富的HTML页面。    —— [ 维基百科 ][1]

> CSDN提供编辑器支持 **Markdown Extra** , 　扩展了很多好用的功能。具体代码请参考[Github][2].  


----------


## ２. 语法说明

### **标题**

在 Markdown 中，你只需要在文本前面加上`#`即可，同理、你还可以增加二级标题、三级标题、四级标题、五级标题和六级标题，总共六级，只需要增加`#`即可，标题字号相应降低。例如：
``` markdown
# 一级标题
## 二级标题
### 三级标题
#### 四级标题
##### 五级标题
###### 六级标题
```



### **链接和图片**
在 Markdown 中，插入链接不需要其他按钮，你只需要使用 `[显示文本](链接地址) `这样的语法即可，例如：
``` markdown
[百度](https://www.baidu.com)
```
显示效果：[百度](https://www.baidu.com)

在 Markdown 中，插入图片不需要其他按钮，你只需要使用 `![](图片链接地址)`这样的语法即可，例如：
``` markdown
![](http://ww4.sinaimg.cn/bmiddle/aa397b7fjw1dzplsgpdw5j.jpg)
```
显示效果：

![](http://ww4.sinaimg.cn/square/7f9d3ecfjw8erq862jl8mj20sg0iyn1r.jpg)

Markdown 支持自动链接形式来处理网址和电子邮件信箱，只要是用尖括号包起来， Markdown 就会自动把它转成链接。例如：`<https://www.baidu.com>`
　
### **引用**
在我们写Blog的时候经常需要引用他人的文字，这个时候引用这个格式就很有必要了，在 Markdown 中，只需要在你希望引用的文字前面加上`>`就好了，例如：

```　markdown
> 矛盾说：我从来不梦想，我只是在努力认识现实；戏剧家洪深说：我的梦想是明年吃苦的能力比今年更强；鲁迅说：人生最大的痛苦是梦醒了无路可走；苏格拉底说：人类的幸福和欢乐在于奋斗，而最有价值的是为了理想而奋斗。
```

显示效果：
> 矛盾说：我从来不梦想，我只是在努力认识现实；戏剧家洪深说：我的梦想是明年吃苦的能力比今年更强；鲁迅说：人生最大的痛苦是梦醒了无路可走；苏格拉底说：人类的幸福和欢乐在于奋斗，而最有价值的是为了理想而奋斗。

### **粗体和斜体**
Markdown 的粗体和斜体也非常简单，用两个`*`包含一段文本就是粗体的语法，用一个`*`包含一段文本就是斜体的语法。例如：　

``` markdown
大概是任何一件不起眼的小事被某个人有意识地重复了*几十年*，*甚至一生*，而形成的某个**传说**。
```
大概是任何一件不起眼的小事被某个人有意识地重复了*几十年*，*甚至一生*，而形成的某个**传说**。

### **分割线**
你可以在一行中用**三个以上**的星号、减号、底线来建立一个分隔线，可以在星号或是减号中间插入空格，例如：

``` markdown
***
* * * 
*******
---
_____	
```

### **中文首行缩进**
两种方法可以实现：

+ 把输入法由半角改为**全角**。 两次空格之后就能够有两个汉字的缩进。
+ 在段落开头的时候，先输入：`&#160; &#160; &#160; &#160;`，然后紧跟着输入文本即可。


### **表格**

表格代码：
``` markdown
项目     | 价格
-------- | ---
Computer | $1600
Phone    | $12
Pipe     | $1
```


显示效果：
项目     | 价格
-------- | ---
Computer | $1600
Phone    | $12
Pipe     | $1

可以使用冒号来定义对齐方式：

表格代码：
``` markdown
| 项目      |    价格 | 数量  |
| :-------- | --------:| :--: |
| Computer  | 1600 元 |  5   |
| Phone     |   12 元 |  12  |
| Pipe      |    1 元 | 234  |
```
显示效果：
| 项目      |    价格 | 数量  |
| :-------- | --------:| :--: |
| Computer  | 1600 元 |  5   |
| Phone     |   12 元 |  12  |
| Pipe      |    1 元 | 234  |

### **定义列表**
**无序列表**：只需要在文字前面加上`-` 、`*`、`+`就可以了，它们效果是一样的，例如：
``` markdown
+ 语文
+ 数学
+ 英语
```
显示效果：

+ 语文
+ 数学
+ 英语

**有序列表**：用数字加英文的句点，这里数字不会影响输出，比如：
``` markdown
1. 机器学习
5. 模式识别
3. 人工智能
```
显示效果：

1. 机器学习
5. 模式识别
3. 人工智能

**缩进列表**：用`:`标记要缩进的行，例如：
``` markdown
项目１
: 定义 A
: 定义 B

项目２
: 定义 C
: 定义 D
```
显示效果：
项目１
: 定义 A
: 定义 B

项目２
: 定义 C
: 定义 D

### **代码**
如果要标记一小段行内代码，你可以用反引号把它包起来，例如：
``` markdown
C语言中使用`printf()`进行格式化输出。
```

显示效果：　C语言中使用`printf()`进行格式化输出。


### **代码块**
将要显示的代码块放在`３对反引号`中间，CSDN提供的编译器支持不同的语法高亮，只要在反引号后接上语言，例如：
``` markdown
 ``` python
 @requires_authorization
 def somefunc(param1='', param2=0):
     '''A docstring'''
     if param1 > param2: # interesting
         print 'Greater'
     return (param2 - param1 + 1) or None
 class SomeClass:
     pass
 >>> message = '''interpreter
 ... prompt'''
 ```
```
显示效果：
``` python
@requires_authorization
def somefunc(param1='', param2=0):
    '''A docstring'''
    if param1 > param2: # interesting
        print 'Greater'
    return (param2 - param1 + 1) or None
class SomeClass:
    pass
>>> message = '''interpreter
... prompt'''
```


### **脚注**
markdown 代码：
``` markdown
生成一个脚注[^footnote].
  [^footnote]: 这里是 **脚注** 的 *内容*.
  
注：footnote是自定义变量  
```
显示效果：
生成一个脚注[^footnote].
  [^footnote]: 这里是 **脚注** 的 *内容*.
  
### **目录**
用 `[TOC]`来生成目录，现在默认会生成目录。

[TOC]




### **UML 图**

可以渲染序列图，例如：
``` markdown
```sequence
张三->李四: 嘿，小四儿, 写博客了没?
Note right of 李四: 李四愣了一下，说：
李四-->张三: 忙得吐血，哪有时间写。
 ```
```
显示效果：
```sequence
张三->李四: 嘿，小四儿, 写博客了没?
Note right of 李四: 李四愣了一下，说：
李四-->张三: 忙得吐血，哪有时间写。
```

流程图markdown代码如下：
``` markdown 
```flow
st=>start: 开始
e=>end: 结束
op=>operation: 我的操作
cond=>condition: 确认？

st->op->cond
cond(yes)->e
cond(no)->op
 ```
```
显示效果：
```　flow
st=>start: 开始
e=>end: 结束
op=>operation: 我的操作
cond=>condition: 确认？

st->op->cond
cond(yes)->e
cond(no)->op
```

- 关于 **序列图** 语法，参考 [这儿][3],
- 关于 **流程图** 语法，参考 [这儿][4].


## ３. 离线写博客

即使在没有网络的情况下，也可以通过本编辑器离线写博客（直接在曾经使用过的浏览器中输入[write.blog.csdn.net/mdeditor][5]即可。**Markdown编辑器**使用浏览器离线存储将内容保存在本地。

在写博客的过程中，内容会实时保存在浏览器缓存中，在关闭浏览器或者其它异常情况下，内容都不会丢失。再次打开浏览器时，会显示上次正在编辑的没有发表的内容。

博客发表后，本地缓存将被删除。　

可以选择 <i class="icon-disk"></i> 把正在写的博客保存到服务器草稿箱，即使换浏览器或者清除缓存，内容也不会丢失。

----------

## ４. 浏览器兼容

 1. 目前，CSDN提供的编辑器对Chrome浏览器支持最为完整。建议大家使用较新版本的Chrome。
 3. IE９以下不支持
 4. IE９，１０，１１存在以下问题
    1. 不支持离线功能
    1. IE9不支持文件导入导出
    1. IE10不支持拖拽文件导入


----------


## ５. 快捷键

 - 加粗    `Ctrl + B` 
 - 斜体    `Ctrl + I` 
 - 引用    `Ctrl + Q`
 - 插入链接    `Ctrl + L`
 - 插入代码    `Ctrl + K`
 - 插入图片    `Ctrl + G`
 - 提升标题    `Ctrl + H`
 - 有序列表    `Ctrl + O`
 - 无序列表    `Ctrl + U`
 - 横线    `Ctrl + R`
 - 撤销    `Ctrl + Z`
 - 重做    `Ctrl + Y`

---------
## ６. 总结
CSDN提供的Markdown编辑器使用[StackEdit][6]修改而来，它有如下特点：

- **Markdown和扩展Markdown简洁的语法**
- **代码块高亮**
- **图片链接和图片上传**
- ***LaTex*数学公式**
- **UML序列图和流程图**
- **离线写博客**
- **导入导出Markdown文件**
- **丰富的快捷键**

[1]: https://zh.wikipedia.org/wiki/Markdown
[2]: https://github.com/jmcmanus/pagedown-extra
[3]: http://bramp.github.io/js-sequence-diagrams/
[4]: http://adrai.github.io/flowchart.js/
[5]: http://write.blog.csdn.net/mdeditor
[6]: https://github.com/benweet/stackedit