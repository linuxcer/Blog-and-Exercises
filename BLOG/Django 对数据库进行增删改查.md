## 引言
假设有如下的model定义，下面将对该model对应的数据库进行增删改查操作。

```
	class Student():
		name = models.CharFiled(max_length = 30)
		age = models.IntegerFiled()
```


----------


## 增
方法一：

```
	stu1 = Student(name="Aaron", age=23)
	stu1.save() # flush到数据库中
```

方法二：

```
	Student.objects.create(name="Aaron", age=23)
```


----------


## 删

删除表中所有数据：

```
	Student.objects.all().delete()
```

删除name等于Aaron的数据：

```
	Student.objects.get(name='Aaron').delete()
```

删除age等于20的多条数据：

```
	Student.objects.filter(age=20).delete()
```


----------
## 改

方法一：

```
	stu = Student.objects.get(name='Aaron') # 查询该条记录
	stu.name = 'Zhang'                      # 修改
	stu.save()                              # 保存
```

方法二，更新多个字段：

```
	Student.objects.get(name='Aaron').update(name='Zhang', age=20)
```

方法三，更新所有字段：

```
	Student.objects.all().update(name='Zhang')
```


----------


## 查

1. 查表中所有记录
	```
		Student.objects.all()
	```
	
2. 查询带字段名的所有记录，就是将所有记录以key-value的形式保存在字典中
	```
		Student.objects.all().values()
	```
3.	查询单条记录
	```
		Student.objects.get(name='Aaron') 
	```
	
	查询name字段是Aaron的这条数据，如果返回多条记录或没有会报错，需结合`try/except`一起使用。

4. 	查询匹配条件的多条数据
	```
		Student.objects.filter(name='Aaron')
	```			
	查询name字段值为Aaron的所有匹配数据，括号中匹配条件可多个，以逗号分隔。注意`filter`与上面`get`方法的区别！！

5. 模糊查询
	```
		Student.objects.filter(name__contains="A")
	```
	查询name字段中值包含`A`的记录。

6. 	将字段内容排序后显示
	```
		Student.objects.order_by('age')
	```
	根据Aaron字段的内容进行排序后输出结果。

7. 将字段内容逆序后显示
	```
		Student.objects.order_by('-age')
	```
	只需要加一个`-`号就可以达到逆序输出的效果。

8. 多重查询，比如过滤后逆序输出
	```
		Student.objects.filter(age=20).order_by("-age")
	```
9. 限制数据条数
	```
		Student.objects.filter(age=20)[0]  # [0]取第一条记录，[0:2]取前两条记录
		Student.objects.filter(age=20).order_by("‐age")[0] 
		
	```
	切片不支持负数，可以使用上面先逆序排列后再输出达到这个效果。


----------


【完】
	