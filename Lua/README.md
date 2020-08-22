# Lua

## 1. 介绍

Lua是一种轻量小巧的脚本语言，用标准C语言编写并以源代码形式开放，
其设计目的是为了嵌入应用程序中，从而为应用程序提供灵活的扩展和定制功能。

## 2. 数据类型

### 2.1 空类型nil

把全局变量或table的某个变量设为nil，相当于删除功能

定义的变量未初始化，默认为nil

### 2.2 boolean

nil和false为false

其他的都是true，0也是true

### 2.3 string

由单引号，双引号或 **[[ ]]** 来表示的字符串

### 2.4 table

table 是 Lua 的一种数据结构用来帮助我们创建不同的数据类型，如：数组、字典等。

Lua table 使用关联型数组，你可以用任意类型的值来作数组的索引，但这个值不能是 nil。

Lua table 是不固定大小的，你可以根据自己需要进行扩容。

```lua
-- 初始化
local mytable = {}

-- table的内置方法
table.concat()
table.insert()
table.remove()
table.sort()
```

### 2.5 userdata

任意存储在变量中的C数据结构

### 2.6 funtion

### 2.7 thread

### 2.8 其他

```lua
-- 使用 type(xxx) 来确定xxx的类型
type(AA) -- nil, AA未定义
type(AA) == nil -- false，type(type(AA)) 为 string
type(AA) == 'nil' -- true
```

## 3. 语法

## 4. 模块和函数方法

## 5. 高级

## 6. 注意点
