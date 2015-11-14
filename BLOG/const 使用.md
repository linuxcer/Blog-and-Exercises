## 作用
　　它限定一个**变量**不允许被改变。使用`const`在一定程度上可以提高程序的安全性和可靠性。 常类型是指使用类型修饰符`const`说明的类型，常类型的变量或对象的值是**不能被更新的**。
        
## 指针举例

#### **例一：下面分别用const限定不可变的内容是什么？**
+ const在前面
``` C
	const int nValue;                // nValue是const
	const char *pContent;            // *pContent是const, pContent可变
	const char* const pContent;      // pContent和*pContent都是const
``` 
 
+ const在后面，与上面的声明对等
``` C
	int const nValue;                //nValue是const
	char const * pContent;           //*pContent是const, pContent可变
	char* const pContent;            //pContent是const,*pContent可变
	char const* const pContent;      //pContent和*pContent都是const
```                

答案与分析：
　　const和指针一起使用是C语言中一个很常见的困惑之处，在实际开发中，特别是在看别人代码的时候，常常会因为这样而不好判断作者的意图，下面讲一下我的判断原则：
　　**const只修饰其后的变量，至于const放在类型前还是类型后并没有区别**。如：`const int a`和`int const a`都是修饰a为const。注意*不是一种类型，如果*pType之前是某类型，那么pType是指向该类型的指针
　　 一个简单的判断方法：指针运算符*，是从右到左，那么如：`char const * pContent`，可以理解为`char const (* pContent)`，即* pContent为const，而pContent则是可变的。
 
#### **例二**
``` C
	int const * p1,p2;
```        
　　p2是const；(\*p1)是一整体，因此(\*p1)是const，但p1是可变的。`int * p1,p2`只代表p1是指向整型的指针，要表示p1、p2都是指针是需写成`int * p1,* p2`。所以无论是`* const p1,p2`还是`const * p1,p2`，里面的*都是属于p1的。

#### **例三**
``` C
	int const * const p1,p2;
```
　　p2是const，是前一个const修饰的，*p1也被前一个const修饰，而p1被后一个const修饰。

#### **例四**
``` C
	int * const p1,p2;
```
　　p1是const，（* const p1）是整体，所以const不修饰p2。

#### **例五**
　　指针指向及指向变量的值的变化，const在\*的左边，则**指针指向的变量的值**不可直接通过指针改变（可以通过其他途径改变）；在\*的右边，则**指针的指向**不可变。
+ 指针指向的变量的值不能变，指向可变
``` C
	int x = 1;
	int y = 2;
	const int* px = &x;
	int const* px = &x; //这两句表达式一样效果
	px = &y;            //正确，允许改变指向
	*px = 3;            //错误，不允许改变指针指向的变量的值
```

+ 指针指向的变量的值可以改变，指向不可变
``` C
	int x = 1;
	int y = 2;
	int* const px = &x;
	px = &y; //错误，不允许改变指针指向
	*px = 3; //正确，允许改变指针指向的变量的值
```
3）指针指向的变量的值不可变，指向不可变
``` C
	int x = 1;
	int y = 2;
	const int* const px = &x;
	int const* const px = &x;
	px = &y;  //错误，不允许改变指针指向
	*px = 3;  //错误，不允许改变指针指向的变量的值
```

## 补充

在Ｃ中，对于const定义的指针，不赋初值编译不报错，
`int* const px;`这种定义是不允许的。（指针常量定义的时候对其进行初始化）
`int const *px;`这种定义是允许的。（常指针可以再定义的时候不初始化）

在C++中
`int* const px;`和`const int* const px;`均会报错，`const int* px;`不报错。
必须初始化指针的指向`int* const px = &x;const int* const px=&x;`
强烈建议在初始化时说明指针的指向，防止出现野指针！


## 总结
**在const右边整体就是常量！！！！**
