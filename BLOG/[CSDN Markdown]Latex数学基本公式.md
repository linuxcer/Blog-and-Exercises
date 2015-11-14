

## 基本表示方式
*LaTeX*公式有两种，一种是用在**正文**中的，一种是**单独显示**的。正文中的公式用 `$...$` 来定义，单独显示的用`$$...$$`来定义，其中 ... 表示的是LaTeX 的公式命令。例如：（这里只需要理解这两种表示方式即可，具体公式解释下文会详细介绍）

``` markdown 
定义：$f(x) = \sum_{i=0}^{N}\int_{a}^{b} g(t,i) \text{ d}t$. (行内公式)
或者定义（行间公式）: 
$$f(x) = \sum_{i=0}^{N}\int_{a}^{b} g(t,i) \text{ d}t{6}\tag{1}$$
```
得到结果如下：
定义：$f(x) = \sum_{i=0}^{N}\int_{a}^{b} g(t,i) \text{ d}t$. (行内公式)
或（行间公式）: 
$$f(x) = \sum_{i=0}^{N}\int_{a}^{b} g(t,i) \text{ d}t\tag{1}$$


----------

## 希腊字母
| 命令 | 显示 | 命令 | 显示|
|:-----:|:-----:|:---:|:-----:|
|`\alpha`|$\alpha$|`\beta`|$\beta$|
|`\gamma`|$\gamma$|`\delta`|$\delta$|
|`\epsilon`|$\epsilon$|`\zeta`|$\zeta$|
|`\eta`|$\eta$|`\theta`|$\theta$|
|`\iota`|$\iota$|`\kappa`|$\kappa$|
|`\lambda`|$\lambda$|`\mu`|$\mu$|
|`\xi`|$\xi$|`\nu`|$\nu$|
|`\pi`|$\pi$|`\rho`|$\rho$|
|`\sigma`|$\sigma$|`\tau`|$\tau$|
|`\upsilon`|$\upsilon$|`\phi`|$\phi$|
|`\chi`|$\chi$|`\psi`|$\psi$|
|`\omega`|$\omega$|`\Gamma`|$\Gamma$|
|`\Delta`|$\Delta$|`\Theta`|$\Theta$|
|`\Lambda`|$\Lambda$|`\Xi`|$\Xi$|
|`\Sigma`|$\Sigma$|`\Upsilon`|$\Upsilon$|
|`\Phi`|$\Phi$|`\Psi`|$\Psi$|
|`\Omega`|$\Omega$|||

> 说明：
1. 将上面的命令放到`$...$`或`$$...$$`中就能看到结果；
2. 如果使用大写希腊字母，只要把命令的首字母变成大写即可，例如`\Gamma`输出的是$\Gamma$，并不是所有的字母都有大写；
3. 如果使用斜体大写希腊字母，再在大写希腊字母的LaTeX命令前加上**var**，例如`\varGamma` 生成$\varGamma$。


----------


## 常用数学函数
| 命令 | 显示 | 命令 | 显示|
|:-----:|:-----:|:---:|:-----:|
|`\sum`|$\sum$|`\int`|$\int$|
|`\sum_{i=1}^{N}`|$\sum_{i=1}^{N}$|`\int_{a}^{N}`|$\int_{a}^{N}$|
|`\prod`|$\prod$|`\iint`|$\iint$|
|`\prod_{i=1}^{N}`|$\prod_{i=1}^{N}$|`\iint_{a}^{b}`|$\iint_{a}^{b}$|
|`\bigcup`|$\bigcup$|`\bigcap`|$\bigcap$|
|`\bigcup_{i=1}^{N}`|$\bigcup_{i=1}^{N}$|`\bigcap_{i=1}^{N}`|$\bigcap_{i=1}^{N}$|
|`\sqrt[3]{2}`|$\sqrt[3]{2}$|`\sqrt{5}`|$\sqrt{5}$|
|`\lim_{x \to 0}`|$\lim_{x \to 0}$|`\frac{1}{2}`|$\frac{1}{2}$|
|`\sin`|$\sin$|`\cos`|$cos$|
|`\tan`|$\tan$|`\log`|$log$|
|`x^{3}`|$x^{3}$|`x_{3}`|$x_{3}$|
> 说明：
1. 用 `^` 来表示上标，用 `_` 来表示下标；
2. 上标和下标在只有一个字符时，可以不用中括号，例如：`x^2`和`x^{2}`的结果都是$x^2$；
3. 最后一行中上标和下标是不需要加`\`。


----------


## 其他常用表示
| 命令 | 显示 | 命令 | 显示|
|:-----:|:-----:|:---:|:-----:|
|`1 \ldots N`|$1 \ldots N$|`1 \cdots N`|$1 \cdots N$|
|`\\|`|$\|$|`\{ \}`|$\{ \}$|
|`()`|$()$|`[]`|$[]$|
|`\|`|$|$|`\left( \right)` |$\left( \right)$|
> 说明
1. `\ldots`表示跟文本底线对齐的省略号；`\cdots`表示跟文本中线对齐的省略号；
2. () 和 [ ] 和 ｜ 这三个符号可以直接用；
3. {} 对应于 \{ \}；|| 对应于 \|；
4. 有时需要根据公式自适应调整括号大小，可以使用`\left` 和 `\right`；本命令分别放在左、右定界符前，自动随着公式内容大小调整符号大小。


----------

## 关系符号

|命令|显示|命令|显示|
|:-----:|:-----:|:---:|:-----:|
|`\leq`|$\leq$|`\geq`|$\geq$|
|`\not =`|$\not =$|`\neq`|$\neq$|
|`<`|$<$|`>`|$>$|
|`\ni`|$\ni$|`\in`|$\in$|
|`\propto`|$\propto$|`\approx`|$\approx$|
|`\subseteq`|$\subseteq$|`\supseteq`|$\supseteq$|


----------


## 对齐和标签
除了上面提到的两种基本表示之外，其实还可以用`\begin{equation}`和` \end{equation}`，公式除了独占一行还会自动被添加序号， 如何公式不想编号可以用 `\begin{equation*}` 和 `\end{equation*}`，例如：
``` markdown
\begin{equation*}
f(x) = \sum_{i=0}^{N}\int_{a}^{b} g(t,i) \text{ d}t
\end{equation*}
```
显示效果如下：
\begin{equation}
f(x) = \sum_{i=0}^{N}\int_{a}^{b} g(t,i) \text{ d}t
\end{equation}

### **对齐**
``` markdown
\begin{eqnarray*}
\cos 2\theta & = & \cos^2 \theta - \sin^2 \theta \\
& = & 2 \cos^2 \theta - 1.
\end{eqnarray*}
```

\begin{eqnarray*}
\cos 2\theta & = & \cos^2 \theta - \sin^2 \theta \\
& = & 2 \cos^2 \theta - 1.
\end{eqnarray*}
eqnarray表示对齐，其中&是对其点，表示在此对齐。

### **标签**
``` markdown
\begin{equation*}
f(x) = \sum_{i=0}^{N}\int_{a}^{b} g(t,i) \text{ d}t\tag{1}
\end{equation*}
```

\begin{equation}
f(x) = \sum_{i=0}^{N}\int_{a}^{b} g(t,i) \text{ d}t\tag{1}
\end{equation}

`\tag{number}`可以用来指定一个标签。


----------


## 总结
本文介绍的是一些基本的LaTeX 公式命令。未尽之处，大家可以参考[这里](http://meta.math.stackexchange.com/questions/5020/mathjax-basic-tutorial-and-quick-reference)。CSDN Markdown基本语法可以参考[这里](http://blog.csdn.net/zcf1002797280/article/details/49404329)。