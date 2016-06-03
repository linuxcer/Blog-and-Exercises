
对于在对数坐标系中出现一条直线而言，三种分布都是可能的：`Zipf`，`Power-laws`和 `Pareto`。这三种分布都是用于描述同一种现象：大量事件是稀少的，而一些小事件确是很普遍的。
例如：成绩非常优异的学生是少数，但是成绩中等的学生却很多。
 
### (1)`Zipf`分布
描述事件出现平率$y$与其由下优先级$r(Rank)$之间的关系，按照`Zipf`模型，事件出现的平率与其优先级$r$成反比:
           $$y\thicksim r^{(-b)}$$
其中$b$近似为1
 
### (2)`Pareto`分布
用于描述大于$x$的事件的数量，按照`Pareto`模型，事大于$x$的事件数量与$x$成反比例:
    $$P\{X>x\} \thicksim x^{(-k)}$$
以职员收入为例，千万富翁是少数，而中等收入的人却很多。
 
### (3)`Power-laws`分布
与`parto`规律不同，`Power-laws`分布不仅描述等于$x$的事件数量。按照`Power-lays`模型，
    $$P\{X=x\} \thicksim x^{(-(k+1))}$$

即：对于指数为$k$的`Pareto`分布，也是指数为$(K+1)$的`Power-laws`分布。


[参考](http://www.hpl.hp.com/research/idl/papers/ranking/ranking.html)


----------
【完】