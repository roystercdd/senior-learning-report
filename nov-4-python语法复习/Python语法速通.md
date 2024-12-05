# Python基础速通

[toc]

> 本文代码均基于 Thonny IDE 实现，并且只对本人不熟悉的部分或总结性质知识记笔记

## 1. Hello World

* cmd命令提示符→输入python进入交互解释器模式（执行单行）
* 退出则输入exit()

![image-20241031094647666](https://gitee.com/RoysterCDD/figurebed/raw/master/img/image-20241031094647666.png)

* 执行py文件（执行多行）

``` python
print("Hello World!!!")
print("Stardew Valley")
```

![image-20241031100144963](https://gitee.com/RoysterCDD/figurebed/raw/master/img/image-20241031100144963.png)



## 2. Python解释器

* python解释器就是python.exe，负责将python代码转换为二进制让计算机运行



## 3. Python开发环境

* 此处只介绍Pycharm

* 新建项目：指定工程路径→选择python解释器→书写代码→run
* 常用快捷键

``` 
ctrl + alt + s : 打开软件设置
ctrl + d ：复制当前行代码
shift + alt + 上\下 ： 将当前行代码上移或下移
crtl + shift + f10 : 运行当前代码文件
shift + f6 ：重命名文件
ctrl + a : 全选
ctrl + c\v\x : 复制、粘贴、剪切
ctrl + f : 搜索
```



## 4. Python数据类型

![image-20241111113854719](https://gitee.com/RoysterCDD/figurebed/raw/master/img/image-20241111113854719.png)

* type函数查看数据类型

``` python
print(type(123)) # 打印数据类型

a=3.14
print(type(a))
```

* 强制类型转换，如：`s=str(123), num=float("3.14"), num=int(3.14)`
  1. 任何类型可以转换为str，加上`""`即可
  2. str转换成数值类型要求字符串中内容为数字
  3. float到int之间依然存在精度丢失问题
* 标识符：可以用中文作标识符但存在很多潜在问题，其他同C++



## 5. Python算数运算符

* 只需要注意python中地板除是`//`，`pow(a,b)`可以用`a**b`表示
* 每种算术运算符都可以和赋值运算符组成复合赋值运算符，复合赋值运算符中只有`+=, -=`，没有`++, --`了

![image-20241111200450672](https://gitee.com/RoysterCDD/figurebed/raw/master/img/image-20241111200450672.png)



## 6. 字符串

* 可以用单引号、双引号、三引号
* 三引号写法不赋值给变量可以当多行注释`### 我是注释 ###`来用，并且支持换行
* 如果字符串中本身就有多种引号，可以用`\`转义字符解除引号的效用，也可以合理搭配使用多种引号，满足引号表达式匹配即可

``` python
name='cdd'
name="cdd"
name="""cdd"""
name="""
Royster
CDD
"""
```

* 字符串拼接直接使用`+`即可，字符串无法直接与数值类型拼接

``` python
name="cdd"
address="四川"
tel=157
print("我是：" + name + "，地址是：" + address + "，电话是：" + tel) # 报错
```

* 但是可以用占位的形式格式化输出，`%s:字符串, %d:整数, %f:浮点数`（输出浮点数时会自动补充到有效数据位数）
* 除了变量也可以用表达式

``` python
name="cdd"
# % 是占位符
msg="我的名字是：%s" % name 
# 如果有多个变量拼接则用括号
address="四川"
msg="我的名字是：%s，地址是：%s" % (name,address)
```

* 使用辅助符号`m.n`可以控制数据的宽度和精度

``` python
num=11.111
print("宽度为5，精度为2：%5.2d" % num)
```

* 还有一种格式化代码的方式，语法：`f"内容{变量}"`，f(format)表示接下来的字符串里有占位符，这种方式不限制数据类型、不做精度控制（写作什么就输出什么）
* 除了变量也可以用表达式

``` python
name="cdd"
age="21"
salary="22500.55"
print(f"我是{name}，年龄是{age}，月薪是{salary}") # 22500.55不补充后置0
```



## 7. input & print

* `print()`是数据输出，自带换行

``` python
print("Hello", end='') # 结束符替换为空字符，即不换行

print("Royster\tCDD") # \t是制表符，两行字符间会自动上下对齐
print("Hello\tWorld")

# 如：输出九九乘法表时
print(f"{j} * {i} = {j*i}", end='\t')
```



* `input()`用于从键盘获取输入，返回的数据类型是`str`，要其他类型要自行强转

``` python
name=input("who are you?") # 提示语句可以写在input的'()'中
age=int(input("how old are you?")) # 强转为int
```



## 8. Python判断

* python中的if语句不需要花括号，所以通过缩进来判断代码的作用域
* 布尔类型的真和假用`True`和`False`，首字母大写不同于C
* `elif`是`else if`的缩写，互斥且有序
* 可以在if语句中使用input()函数，节约代码量

``` python
if int(input("请输入您的年龄："))>=18:
    print("您已成年")
```



## 9. Python循环

* `while`：知道循环的结果，`for`：知道循环的次数

``` python
name="cdd"
# 类似于C++11加强for循环
for x in name:
    print(x, end=' ')
```

* `for`循环配合`range`语句可以遍历序列类型循环处理，常见的序列类型有：字符串、列表、元组等
* `range`的特性是左闭右开，语法：
  1. `range(5)`：{0, 1, 2, 3, 4}
  2. `range(3,5)`：{3, 4, 5}
  3. `range(5,10,2)`：{5, 7, 9}

* 注意临时变量作用域的问题

``` python
for i in range(5): # i作用域在for循环内
    print(i)
print(i) # 这里依然会打印出4，这样写在py中是被允许的，但是不规范，不建议
```

* `break`和`continue`同`C/C++`



## 10. Python函数

* 如果函数没有返回值可以`return None`，若函数没有`return`语句也默认返回`None`
* `None`关键字可以赋值给变量表示暂无具体值，可以当函数返回值表示空函数，可以用在`if`语句中等同于`False`
* 在函数内部定义的

``` python
def 函数名(形参1, 形参2):
    函数体
    return 返回值
```

* 函数的说明文档：Pycharm环境下在函数体中输入`""" """`（多行注释）即可自动补充以下模板说明文档
* 随后在任意调用函数的地方，鼠标悬停在代码上即可看到函数的说明文档

![image-20241114095701882](https://gitee.com/RoysterCDD/figurebed/raw/master/img/image-20241114095701882.png)

* 变量定义域问题

``` python
# 全局变量，注意全局变量与局部变量
num=200

def fun_A():
    print(f"fun_A: {num}") # 200
    
def fun_B():
    num=500 # 在函数内部num为局部变量
    print(f"fun_B: {num}") # 500

fun_A()
fun_B()
print(num) # 200 
```

* 可以使用`global`关键字将函数体中的局部变量提升为	全局变量

![image-20241114101937786](https://gitee.com/RoysterCDD/figurebed/raw/master/img/image-20241114101937786.png)



## 11. Python数据容器

### 11.1. list 列表

* 一次存储多个数据，可以为不同类型，支持嵌套

``` python
# 不同类型元素
lst=["Royster", "CDD", "Python", 666]
print(lst)
print(type(lst))

# 嵌套
lst=[[1, 2, 3], [4, 5, 6]]
print(lst)
```

* 支持正序（从0开始）和倒序（从-1开始），嵌套列表用多重下标

``` python
lst=["Tom","Lily","Rose"]
# 正序
print(lst[0]) # Tom
# print(lst[5]) # 数组越界
print(lst[-3]) # Tom

lst=[[1,2,3],[4,5,6]]
print(lst[0][2]) # 3
```

* 列表的方法，注意函数和方法（定义在`class`中的`def`函数）的区别

![image-20241114102146566](https://gitee.com/RoysterCDD/figurebed/raw/master/img/image-20241114102146566.png)

``` python
lst=["Tom","Lily","Rose"]

# 1. index 查找元素在列表中的下标
# 若有多个返回第一个元素下标
# 若找不到则Value Error
idx=lst.index("Tom")
print(idx)

# 2. 通过索引修改指定位置元素
lst[0]="Jack"
print(lst)

# 3. insert 在指定位置插入元素
lst.insert(1,"Mike") # 下标1的元素变为Mike，往后元素顺延
print(lst)

# 4. append 在列表末尾追加单个元素
lst.append("Joe")
print(lst)

# 5. extend 在列表末尾追加多个元素
tmp=[1,2,3]
lst.extend(tmp) # 追加 1 2 3 这三个元素
print(lst)

# 6. del 通过下标在列表删除指定下标元素
del lst[0]
print(lst)

# 7. pop 通过下标在列表删除指定下标元素并取出
it=lst.pop(0)
print(it, lst)

# 8. remove 通过元素值在列表删除第一个匹配项
lst=[1,1,2,3,5,5,5]
it=1
print(lst)
lst.remove(1)
print(lst)

# 9. clear 清空列表
lst.clear()
print(lst)

# 10. count 通过具体值统计某元素在列表中的数量
lst=[1,1,2,3,5,5,5]
cnt=lst.count(5)
print(cnt)

# 11. len 取出列表长度（总元素个数）
print(len(lst))

# while 循环遍历列表
i=0
while i<len(lst):
    print(lst[i], end=' ')
    i+=1

print()

# for 循环遍历列表
for it in lst:
    print(it, end=' ')
    
print()

for i in range(0,len(lst)):
    print(lst[i], end=' ')
```



### 11.2. 元组

* 不允许被修改的列表，当需要在程序内封装数据但又不希望封装的数据被篡改时使用

* 因为元组中的数据不允许被修改，所以方法比较少

``` python
# 1. 定义
tp1=(1,"Hello",True)
tp2=() # 空元组 或 tp2=tuple()
print(tp1)

# 当定义单个元素时需要加"," 否则认为是这个元素的数据类型
tp3=("hello")
print(type(tp3))
tp3=("hello",)
print(type(tp3))

# 2. 根据下标索引取值
tp4=((1,2,3),(4,5,6))
print(tp4[0][2])

# 3. index 通过下标查找数据元素，找不到ValueError
tp5=("Royster","CDD","Python")
print(tp5.index("CDD"))

# 4. count 通过值统计个数
print(tp5.count("Python"))

# 5. len 获取元组元素数量
print(len(tp5))

# 6. while 循环遍历
i=0
while i<len(tp5):
    print(f"第{i}个元素是：{tp5[i]}")
    i+=1
    
# 7. for 循环遍历
for x in tp5:
    print(x,end=' ')

print()

for i in range(0,len(tp5)):
    print(tp5[i],end=' ')

print()

# 8. 实际上tuple中的list是可以被修改的
tp6=(1,2,["Royster","CDD"])
tp6[2][0]="Sapphire"
print(tp6)
```



### 11.3. 字符串

* 字符串是字符的容器，同元组，无法被修改，因此接口返回的都是新字符串，而非在原字符串上进行修改

``` python
s1="Royster CDD"
# 1. 通过下标索引
val=s1[-3]
print(val)

# 2. index 查找子串返回首元素下标
val=s1.find("CDD")
print(val)

# 3. replace 将串1全部内容替换成串2
# 因为字符串不可修改性 不是修改字符串本身 而是得到一个新串
s2=s1.replace("CDD","Lee")
print(s1) # 并未被修改
print(s2)

# 4. split 按照自定分隔符(字符串)将字符串划分为多个子串，返回列表
s3="Dirty Deeds Done Dirty Cheep"
lst=s3.split(" ")
print(lst)
for it in lst:
    print(it,end=' ')
print()

# 5. strip 去除前后空格/换行符或其他指定字符(重载)
s4="   Dirty Deeds Done Dirty Cheep   "
print(s4.strip())
s5="666Hello World666"
print(s5.strip('6'))
s6="123Hello World321"
print(s6.strip('123')) # 这里指删除'1' '2' '3'

# 6. 统计某字符(串)出现次数
print(s4.count('D'))
print(s4.count("Dirty"))

# 7. 统计字符串长度
print(len(s4))

# 8. 遍历不演示了
```



### 11.4. 序列切片

* 序列指：内容连续、有序可用下标索引的一类数据容器，所以列表、元组、字符串都是序列
* 序列支持切片操作，即从序列中取出子序列
* 语法：`序列[起始下标:结束下标:步长]`，切片操作不影响序列本身，而是得到一个新的序列
  1. 起始下标：留空视作从0开始
  2. 结束下标：留空视作截取到-1
  3. 步长为N：每次跳过N-1个元素取；步长可以为负数，表示反向取，前提是起始下标和结束下标也是反向的

``` python
# 切片是左闭右开的 [a,b)
lst=[0,1,2,3,4,5]

# 常规情况，[a,b,step] 略

lst1=lst[:4] # 默认从0开始
print(lst1)

lst2=lst[4:] # 默认截取到0
print(lst2)

lst3=lst[::-1] # 相当于逆置
print(lst3)
```



### 11.5. 集合

* 之前学习过的三种数据容器都支持重复元素且有序，而集合具有确定性、无序性、互异性

``` python
# 定义
s={"Royster","CDD","CDD","Python","Python"}
print(s, type(s))
ss=set() # 定义空集合唯一方法

# 1. 无序→故不支持下标索引

# 2. 添加元素
s.add("阿sir")
print(s) # 注意，因为无序，所以每次打印出来的结果可能不一样

# 3. 移除元素
s.remove("Royster")
print(s)

# 4. 从集合中随机弹出一个元素并获取返回值
it=s.pop()
print(it, s)

# 5. 清空
s.clear()
print(s)

# 6. 取两个集合的差集
s1={1,2,3}
s2={1,5,6}
s3=s1.difference(s2) # s1有的s2没有的，A-AB
print(s3)

# 7. 合并两个集合
s1={1,2,3}
s2={1,5,6}
s3=s1.union(s2) # 1 2 3 5 6 去重且无序
print(s3)

# 8. 统计集合元素数量
s1={1,2,3,4,5,5,5}
print(len(s1))

# 9. 遍历
# 集合无序不支持下标索引，不能用while循环或for+下标
for it in s1:
    print(it,end=' ')

print()
```



### 11.6. 字典

* 字典即C++中的map，键值对，{Key: Value}

``` python
# 定义，和集合一样都是 {}
dct={"王力鸿":99, "周杰轮":88, "林俊节": 77}
print(dct)
dct={} # 空字典，注意集空集合是set()
dct=dict()
print(dct)

# 字典不允许Key重复，后者覆盖
# 注意！key必须是可哈希对象（完全不可变），列表、含列表元组、字典均不可为键
# value可以是任意数据类型
dct={"王力鸿":99, "王力鸿":88 ,"周杰轮":88, "林俊节": 77}
print(dct)

# 1. 从字典基于Key获取Value
score=dct["王力鸿"]
print(score)

# 2. 字典嵌套（json）
# dist²感觉不如list+dict
stu_score_dict={
    "王力鸿": {"语文": 77, "数学": 66, "英语": 33},
    "周杰轮": {"语文": 88, "数学": 86, "英语": 55},
    "林俊节": {"语文": 99, "数学": 96, "英语": 66}
}
print(stu_score_dict)
score=stu_score_dict["周杰轮"]["英语"]
print(score)

# 3. 新增元素
# 若Key不存在，新建；已存在，覆盖
dct={"张学油":99, "周杰轮":88, "林俊节": 77}
dct["张信折"]=66
print(dct)

# 4. 删除元素
# 获取并删除
score=dct.pop("周杰轮")
print(dct)
print(score)

# 5. 清空
dct.clear()
print(dct)

# 6. 获取全部Key
dct={"张学油":99, "周杰轮":88, "林俊节": 77}
keys=dct.keys()
print(keys)
# 随后可以用keys进行遍历
for key in keys:
    print(f"键是{key}, 值是{dct[key]}")

print()

# 可以直接对字典进行for循环，必须写死key
for key in dct:
    print(f"键是{key}, 值是{dct[key]}")
```



### 11.7. 五类数据容器对比

![image-20241115110907164](https://gitee.com/RoysterCDD/figurebed/raw/master/img/image-20241115110907164.png)

* 除了以上异同点以外，5类数据容器之间也有一些通用的方法，比如：`len(), max(), min()`，其中对`str`使用`max(), min()`基于ASCII码

* 通用容器类型转换函数
  * `list()`：转为列表
    1. `str`转换成其他类型是把每个字符都拆开作为独立元素
    2. `dict`因数据结构特殊性，没有`dict()`函数，但若将`dict`转换成其他数据容器会丢失`value`，只保留`key`
  * `str()`：转为字符串
    1. 和原数据容器`print`出来结果一致，不过带双引号，`dict`不丢失
  * `tuple()`：同`list()`
  * `set()`：转为集合
    1. `str`转换成其他类型是把每个字符都拆开作为独立元素
    2. `dict`丢失，自动去重+无序化
  * `dict()`：转为字典
    1. 这个函数实际存在，但是`list, tuple, set`都无法转为`dict`，不满足键值对
* 通用排序函数：`sorted()`，PS：
  1. 排序结果会变为`list`
  2. 字符串按ASCII码，字典序按位比较
  3. `dict`丢失`value`
  4. 默认从小到大，加上参数`reverse=True`从大到小
* 对列表使用`sort`函数时，可以类似于C++中的`cmp`来自定义排序`key`，非常优雅

``` python
# 1. 带名函数形式
my_lst=[["a",33],["b",55],["c",11]]
# 自定义排序
def cmp(lst):
    return lst[1] # 每一项为列表，按照列表下标为1的元素进行排序

my_lst.sort(key=cmp,reverse=True)
print(my_lst)

# 2. 匿名函数形式
my_lst=[["a",33],["b",55],["c",11]]
my_lst.sort(key=lambda it:it[1], reverse=True)

print(my_lst)
```



## 12. Python函数进阶

### 12.1. 多返回值

``` python
# 函数多个返回值 逗号分割 多个变量承接即可
def test():
    return 1, "hello", True

x,y,z=test()
print(x, y, z)
```



### 12.2. 多参数传递形式

* 位置参数：顾名思义，按位置传递参数

``` py
def info(name, age, gender):
    print(f"名字是{name}, 年龄是{age}, 性别是{gender}")
    
info('TOM',20,'男')
```

* 关键字参数：调用时通过 “键=值” 传递参数，更加清晰，消除了参数的顺序需求

``` python
def info(name, age, gender):
    print(f"名字是{name}, 年龄是{age}, 性别是{gender}")

# 关键字参数
info(age=20, name="TOM", gender="男")
# 关键字参数与位置参数混用
# 位置参数必须在关键字参数之前，且关键字参数间不存在先后顺序
info("TOM", gender="男", age=20)
```

* 缺省参数：默认参数，为参数提供默认值，如果没有传递这个参数，就使用默认值

``` python
def info(name, age, gender='男'):
    print(f"名字是{name}, 年龄是{age}, 性别是{gender}")

info("TOM", 20)
```

* 不定长参数：用于不确定调用的时候传递多少个参数（包括不传参）
* 可分为位置传递（*）和关键字传递（**）

``` python
### 位置传递
# 所有参数被*args收集 且合并成为一个元组
# 注意*args的写法是一种约定俗成
def test(*args):
    print(args)

test('TOM')
test('TOM',18)

### 关键字传递
# 同样数量不受限 需要传入键值对 且合并为字典
# kwargs同样是约定俗成的写法 不固定
def test(**kwargs):
    print(kwargs)
    
test(name='TOM',age=20,gender="male")
```

* 函数也可以作为参数去传递，表示传入计算逻辑而非传递数据，个人觉得类似于函数的嵌套，提高可读性

``` c++
# 函数作为参数
def test(add):
    res=add(1,2)
    print(type(add))
    print(f"计算结果{res}")

def add(a,b):
    return a+b

# 调用并传入函数
test(add)
```



### 12.3. 匿名函数

* 所谓匿名就是没有具体名称，特性是只能被临时使用，代码只能有一行

``` python
add=lambda x,y : x+y

res=add(3,4)
print(res)
```



## 13. Python文件

* 计算机只能识别0和1，文本是通过编码技术（密码本）将字符翻译成二进制，常用的可用编码有：UTF-8【通用编码】、GBK、Big5，99%的情况都是UTF-8
* 文件的操作包括：打开、读写、关闭

1. 读文件案例：open只读方式打开，read方法读取，close关闭

![image-20241118131326360](https://gitee.com/RoysterCDD/figurebed/raw/master/img/image-20241118131326360.png)

``` python
# 打开文件 - open() 只读 (相对路径)
f=open("test.txt", "r", encoding="UTF-8")
print(type(f)) # TextIO对象

# 读取文件 - read() 固定字符或全部内容
print(f"读取9个字节的结果：{f.read(9)}")
# 内置文件指针，直接从上次读完的位置继续读
print(f"读取全部内容的结果：\n{f.read()}")
print()

# 读取文件 - readLines() 所有行
lines=f.readlines() # 读取全部行并封装到列表
print(type(lines))
print(lines) # 什么都没有是因为文件指针，重新读取一下

f=open("test.txt", "r", encoding="UTF-8")
lines=f.readlines()
print(lines)
print()

# 读取文件 - readline() 读取一行
f=open("test.txt", "r", encoding="UTF-8")
line1=f.readline()
line2=f.readline()
print(f"第一行数据{line1}")
print(f"第二行数据{line2}")

# for循环读取文件所有行
for line in f:
    print(line)
    
# 关闭文件 - close() 解除文件占用才可删除、重命名等
f.close()

# with open 语句，当代码块执行完后自动close文件 (绝对路径)
with open("D:/test.txt", "r", encoding="utf-8") as f:
    for line in f:
        print(line)
```

2. 覆盖写入文件案例：open写入模式打开，write方法写入缓存区，flush刷新，将缓存区数据真正写入文件

* PS：注意写入模式"w" 当文件不存在时会自动创建该文件，若已存在时进行写入实际是覆盖写入！会清除原有内容

``` python
f=open("D:/ttest.txt", "w", encoding="UTF-8")
# write写入 覆盖写入 清除原内容
f.write("Hello World!!!")
f.write("S.H.I.T")
# flush刷新
f.flush()

f.close() # close自带flush功能!!
```

3. 追加写入文件案例：open追加写模式打开，其他均同覆盖写

``` python
f=open("D:/ttest.txt", "a", encoding="UTF-8")
# write写入 追加写入
f.write("\n我是世界的终结者！")
# 刷新
f.close()
```



## 14. Python异常

* 如打开一个不存在的文件，IDE会告诉你哪个文件哪一行报错，异常类型是什么

![image-20241120190116194](https://gitee.com/RoysterCDD/figurebed/raw/master/img/image-20241120190116194.png)

* 当程序遇到BUG会停止，但实际项目中遇到BUG不应该让整个程序崩溃，所以需要捕获异常再进行处理【提前假设异常→做好后续手段】

``` python
# 1. 基本语法
try:
    # 可能发生错误的代码
    f=open('linux.txt', 'r')
except:
    # 如果出现异常执行的代码
    print('r模式无法打开说明文件不存在，改用w模式')
    f=open('linux.txt', 'w') # 文件不存在会创建

# 2. 捕获指定异常
try:
    print(name)
except NameError as e: # e为异常取别名
    print('name变量未定义错误')
    print(e) # 将原本在日志中的报错打印出来
    
# 3. 捕获多个异常
try:
    1/0
except (NameError, ZeroDivisionError) as e:
    print('出现变量未定义 或 除0异常')

# 4. 捕获所有异常
try:
    1/0
except Exception as e: 
    # 和 except: 等价
    # Exception 是所有异常类型的父类
    print('出现异常')

# 5. 未出现异常，一个标准的异常处理通常这样写
# else: 没有出现异常执行
# finally: 无论是否出现异常都执行
try:
    f=open('test.txt', "r")
except Exception as e:
    print('捕获到了异常')
    f=open('test.txt', "w")
else:
    print('未捕获到异常')
finally:
    f.close()
```

* 异常具有传递性，日志中最底层的报错通常是异常的根源，能够帮助有效锁定异常

![image-20241120193545355](https://gitee.com/RoysterCDD/figurebed/raw/master/img/image-20241120193545355.png)



## 15. Python模块

* 模块（Module），本质上就是Python文件，定义了相关函数、类、变量或其他可执行代码

``` python
# "[]" 表示可写可不写
[from 模块名] import [模块 | 类 | 变量 | 函数 | *] [as 别名]
# 常用方式
import 模块名
from 模块名 import 类、变量、方法等
from 模块名 import * # 导入全部
import 模块名 as 别名
from 模块名 import 功能名 as 别名
```

* 案例如下，在pycharm中按住ctrl再点击模块名，可以打开该模块文件，看到内部实现细节，如time等等

``` python
### 注意模块导入一般都写在开头位置
# 理论上导入功能比导入整个模块的速度更快

# 1. 导入整个模块，可通过"."使用包下所有功能
import time
print("你好")
time.sleep(5) # 睡眠5秒
print("我好")

# 2. 导入模块中的具体功能
from time import sleep
print("你好")
sleep(5) # 无需time.sleep()
print("我好")

# 3. 导入模块全部功能
from time import * # 和import time的区别在于不用写"time."
print("你好")
sleep(5)
print("我好")

# 使用as取别名
# 模块别名
import time as t
t.sleep(1)

# 功能别名
from time import sleep as sl
sl(1)
```

* 自定义模块：在一个py文件中正常写代码，再于其他py文件中import导入进来，调用其方法等
* PS：需要注意的一点是，因为模块py文件将被导入，所以模块名应符合标识符命名规则

* 如创建my_module.py，内容如下，并在其他py文件中调用该模块：

``` python
# my_module.py
def test(a, b):
    print(a+b)
 
---------------

# test.py
import my_module # 注意文件名就是模块名
from my_module import test # 或直接导入功能
test(1,2)
```

* 但当my_module.py中就已经调用自身定义的方法，此时在test.py引入该模块时就会执行my_module.py这整个文件，这是`import 自定义模块名`自身性质决定的
* 可以使用语句`if __name__=='__main__'`解决，`__name__`是python的内置变量，表示：，当该py文件直接被运行时，内置变量`__name__`的值被修改为`__main__`，即是说只有当主动运行该py文件时，才会执行`if`语句下的代码（可以书写为主体部分），此时就避免了`import 自定义模块名`也会运行该py文件的主体部分
* 所以模块的`if __name__=='main'`下通常写该模块的测试

``` python
# my_module.py
def test(a,b):
    print(a+b)

# test(1,2) # 若不封装在__name__=='__main__'下，作为模块被导入时会直接执行这句代码

if __name__=='__main__':
    test(1,2) 

---------------

# test.py
import my_module # 此时__name__不等于my_module中的__main__变量
test(1,2)
```

* 除了`__main__`变量以外，在介绍一个`__all__`变量，当使用`from xxx import *`导入时，只能导入该模块中的`__all__`列表下的元素

```  python
# my_module.py 只将test_A暴露给外部py使用，其他私有化
# 如果不写__all__则都能用
__all__=['test_A']

def test_A():
    print('testA')

def test_B():
    print('testB')
    
---------------

from my_module import *

test_A()
test_B() # 报错！但是可以手动导入

from my_module import test_B
test_B()
```



## 16. Python包

* 如果Python的模块过多会导致不好管理的情况，此时可以通过包来管理模块
* Python包（package）由一堆`module.py`文件和`__init__.py`构成，若无`__init__.py`文件则是普通文件夹
* Pycharm中可以直接右键新建包，再在包下书写各个模块文件就完成了自定义Python包
* 导入一个包通常有如下方式，也可以通过`from`语句导入

``` python
import my_package # 导包
import my_package.my_module1 # 导包下的模块
import my_package.my_module1.my_def1() # 导包下模块下的功能
```

* 在Python的生态中，有中有很多好用的第三方包帮助开发效率的提升

![image-20241121162756840](https://gitee.com/RoysterCDD/figurebed/raw/master/img/image-20241121162756840.png)

* 可以通过Python内置的`pip`程序使用`pip`指令安装第三方包

``` python
pip install 包名
```

* 但是在下载时使用的是国外的网站，可以使用清华源镜像

``` python
pip install -i https://pypi.tuna.tsinghua.edu.cn/simple 包名称
```

* 在Pycharm中可以对解释器进行设置从而进入包管理面板，安装第三方包的流程如下：

![image-20241121163525945](https://gitee.com/RoysterCDD/figurebed/raw/master/img/image-20241121163525945.png)

![image-20241121163540010](https://gitee.com/RoysterCDD/figurebed/raw/master/img/image-20241121163540010.png)

![image-20241121163640859](https://gitee.com/RoysterCDD/figurebed/raw/master/img/image-20241121163640859.png)



## 17. Python面向对象

### 17.1 类与对象

* 类是对一类事物的总体描述，由属性和方法构成，对象是类的实例

``` python
# 定义类
class Student:
    name=None
    gender=None

    # 成员方法必须携带self
    def say_hi(self):
        print(f"我是{self.name}") # 成员方法中访问成员变量需要使用self关键字
        
    def say_hi2(self,msg):
        print(f"我是{self.name},{msg}") # msg是方法的形参，与成员变量无关
    
# 实例一个对象
stu=Student()
stu.name="周杰轮"
print(stu.name)

stu.say_hi() # self参数不需要传值
stu.say_hi2("不是吧阿sir")
```



### 17.2. 魔术方法

* 接下来介绍类的构造方法`__init__()`，可以实现在创建类对象时自动执行，并将参数自动传递给`__init__`方法使用

``` python
class Student:
    # 有了构造方法后，可以不在此处声明成员变量
    # 在__init__方法中相当于声明+赋值
#    name=None
#    age=None
#    tel=None

    # 构造方法也是成员，同样也必须携带self
    def __init__(self,name,age,tel):
        self.name=name
        self.age=age
        self.tel=tel
        print("自动执行")

stu=Student("周杰轮",31,"1850006666")
print(stu) # 打印出来的是地址
print(stu.name)
```

* `__init__`构造方法是Python类内置的方法之一，除此以外还有很多内置方法各自有特殊的功能，这些内置方法被称作魔术方法，接下来介绍较为常用的几个（命名规范为：`__xxx__`），魔术方法都会在创建对象时自动执行
* `__str__`：将类转为字符串，类似于JAVA类中的`toString`

``` python
class Student:
    # __init__构造方法
    def __init__(self,name,age):
        self.name=name
        self.age=age
    
    # __str__转字符串魔术方法
    def __str__(self):
        return f"Student类对象, name:{self.name}, age:{self.age}"

stu=Student("周杰轮", 31)
print(stu) # 打印的不是地址而是字符串

```

* `__lt__`：less than，判断小于，类似于C++中的运算符重载
* `__le__`：less than or equal，判断小于等于，此处不再演示
* `__eq__`：equal，判断相等，此处不再演示
* 需要强调的是，如果不使用以上三个比较类魔术方法，类之间进行比较实际上比较的是内存地址

``` python
class Student:
    # __init__构造方法
    def __init__(self,name,age):
        self.name=name
        self.age=age
    
    # __str__转字符串魔术方法
    def __str__(self):
        return f"Student类对象, name:{self.name}, age:{self.age}"

    # __lt__内置判断小于
    def __lt__(self, other):
        return self.age<other.age

stu1=Student("周杰轮", 31)
stu2=Student("林俊节", 36)

print(stu1) # 打印的不是地址而是字符串

print(stu1<stu2) # 返回bool
```



### 17.3. 面向对象特性

* 接下来围绕面向对象三大特性来介绍Python中的类

#### 17.3.1. 封装

* 首先是封装，即不对外暴露使用接口的私有成员变量和私有成员方法，只需要在变量或方法前加上`__`即可
* 封装的实际意义：在类中提供仅供内部使用的属性和方法，而不对外开放（类对象无法使用）

``` python
# 手机的运行电压和CPU运行模式是不给公开的
class Phone:
    __vol=5 # 默认值
    
    def __core(self):
        print("让CPU单核模式运行")
        
    def call(self):
        # 2. 私有成员对类对象来说无法直接使用，但是类中其他成员是可以访问的
        if self.__vol>=1:
            print("通话已开启")
        else:
            self.__core()
            print("电量不足无法通话，已设置为单核方式运行")

phone=Phone()
# print(phone.__vol) # 1. 使用私有成员变量报错
# phone.__core() # 1. 使用私有成员方法报错

phone.call()
```

#### 17.3.2. 继承

* 接着是继承，在原有类的功能基础上扩展
  1. 单继承：子类继承一个父类
  2. 多继承：子类继承多个父类

``` python
### 单继承
# 2022年的手机引入了新功能5g通话和人脸识别
class Phone:
    IMEI=None #序列号
    producer="Apple" # 厂商
    
    def call_by_4g(self):
        print("4g通话")

# 表示PhonePlus继承Phone
class PhonePlus(Phone):
    face_id="114514" # 面部识别ID
    
    def call_by_5g(self):
        print("5g通话")

phone=PhonePlus()
print(phone.producer) # 使用父类中的属性
phone.call_by_4g() # 调用父类中的方法

### 多继承
# 手机继承NFC读卡器、红外遥控
class Phone:
    IMEI=None # 序列号
    producer=None # 厂商

# NFC
class NFCReader:
    nfc_type="第五代"
    producer="Apple"
    
    def read(self):
        print("读卡")

# 远程操控
class RemoteControl:
    rc_type="红外"
    producer="小米"
    
    def control(self):
        print("红外开启")

# 1. 多继承 父类(子类1, 子类2, 子类3)
class PhonePlusProMax(Phone, NFCReader, RemoteControl):
    pass # 2. 补全语句，空语句，纯占位

# 3. 若多个父类中有同名的成员变量（三者都有producer），则
# PhonePlusProMax(Phone, NFCReader, RemoteControl) 就近原则，继承Phone
pppm=PhonePlusProMax()
print(pppm.producer)
```

* 子类还可以复写父类的成员变量或成员方法作为自己的成员变量或方法，类似于JAVA的覆盖
* 子类也可以在类中调用父类的成员变量和成员方法

``` python
# 父类
class Phone:
    producer="Apple"
    
    def fun(self):
        print("我是奶龙")

# 子类
class PhonePlus(Phone):
    producer="小米"
    
    def fun(self):
        print("我是雷军")
        
    def test(self):
        # 2. 调用父类成员
        # 2.1. 方式1→类名形参
        print(Phone.producer)
        
        # 加self的目的是说明调用的不是当前类中的fun 
        Phone.fun(self) # 3. 注意此处加上self
        
        # 2.2. 方式2→super()超类
        print(super().producer)
        super().fun()
        
phone=PhonePlus()
# 1. 复写覆盖
print(phone.producer)
phone.fun()
phone.test()
```

#### 17.3.3. 多态

* 最后是多态，多态即完成某个行为时，不同的对象会得到不同的状态
* 简单说来是：函数（方法）形参声明接收父类对象，实际传入父类的子类进行工作并得到不同的状态，与继承强相关

* 梦回JAVA，通过多态特性，我们可以引入抽象类，如下例中的Animal
  1. 抽象类：包含抽象方法的类，抽象方法即没有具体的实现方法（pass）
  2. 抽象类多用于作顶层设计（设计标准），以便子类具体实现，是对子类的软性约束，要求子类必须复写（实现）父类的一些方法

``` python
# 此时Animal变为抽象类（或者接口）
class Animal:
    def speak(self):
        pass
    
class Dog(Animal):
    def speak(self):
        print("汪汪汪")

class Cat(Animal):
    def speak(self):
        print("喵喵喵")

class Otto(Animal):
    def speak(self):
        print("哇袄!!!!!")

# 该函数承接父类，但实际传递子类对象
def make_noise(animal: Animal):
    animal.speak()

dog=Dog()
cat=Cat()
otto=Otto()

make_noise(dog)
make_noise(cat)
make_noise(otto)
```



## 18. 类型注解

* 如在Pycharm中，在知道变量类型后（如list等）会有补全提示，这就是基于类型注解实现的，类型注解支持对变量、函数（方法）形参列表以及返回值的类型进行注解，可以帮助IDE做补全提示以及帮助开发者对变量自身进行类型注释

``` python
变量名: 类型 = 值 # 就是在"变量=值"中间加上了类型规范一下
```

``` python
import random
import json

# 1: 变量类型注释
# 一般来说pycharm可以显式的看出来，具备补全提示功能，可以不写
# a:int=10
# b:str="Royster"
# c:bool=True

# 2: 基础容器类型注解，当然pycharm也看得出来
lst:list=[1,2,3]
tpl:tuple=(1,2,3)
dct:dict={"CDD":666}

# 3: 可以对基础容器进行更详细的注解
lst:list[int]=[1,2,3] # 每个元素都是int型
tpl:tuple[int,str,bool]=(1,"CDD",True)
dct:dict[str,int]={"CDD",666}

# 4: 类对象类型注解
class Student:
    pass
stu:Student=Student()

# 以上四种情况pycharm都能显示看出来
# 通常来说对于类型不那么明显的变量，我们才使用手动类型注解，如：
var_1:int=random.randint(1,10) # type: int (通过注释的方式注解，尚不清楚有没有实际作用）
var_2:json.loads('{"name":"Jack"}') # type: dict[]
def fun():
    stu=Student()
    return stu
var_3:Student=fun()

# 需要注意，类型注释仅仅是提示性的，不是决定性的
var_4:int="royster" # 并不会报错哦！
```

* 对函数（方法）的形参和返回值打上注解用处可就大咯！因为在传入参数的时候pycharm可不知道你传入的是什么类型的变量！举个例子

``` python
def fun(data):
    data.app # data是list，此处想补全append()方法，但是pycharm不认识data的类型！
```

* 再看一个场景，在调用完函数用变量承接时，pycharm也不能直接看出来变量的类型

``` python
def fun(data):
    data.append(1)
    return str(data)

lst=[]
s=fun(lst) # s也没有补全提示
```

* 语法类似，同样提示性，非决定性，

``` python
def 函数方法名(形参名:类型, 形参名:类型, ... ) -> 返回值类型 :
    ...
```

* 介绍`Union`联合类型，可以定义联合类型注释，配合pycharm完成补全提示

``` python
from typing import Union
lst:list[Union[int,str]]=[1,2,"Jump!"] # 可能是int 也可能是str

# 形参可能是int或str，返回值可能是int或str
def fun(data:Union[int,str])→Union[int,str]:
    pass
```

