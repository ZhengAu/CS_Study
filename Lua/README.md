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

### 3.1 变量

变量分为全局变量，局部变量，表中的域

使用 **local** 定义的是局部变量，其他的为全局变量

### 3.2 循环

```lua
while (true) do
  -- ...
end

-- for 循环分为数值和泛型循环
for i = 1, 100 do
  -- ...
end

for key, value in pairs(xxx) do
  -- ...
end
```

### 3.3 流程控制

```lua
if (true) then
  -- ...
elseif (xxx)
  -- ...
elseif (xxx)
  -- ...
else
  -- ...
end
```

### 3.4 函数

```lua
-- 可变参数 ...
function funcName(...)
local arg = {...} -- arg为一个表，接收可变参数
  -- ...
  return 11, 22, 33 -- 返回多个值
end

local myfunc = function ()
  -- ...
end
```

### 3.5 运算符

```lua
~=  -- 不等于
and, or, not -- 逻辑与，或，非
```

### 3.6 输出

```lua
print()
```

### 3.7 注释

```lua
-- 单行注释

--[[
多行注释
-- ]]
```

## 4. 模块与包

模块类似于一个封装库，从 Lua 5.1 开始，Lua 加入了标准的模块管理机制，
可以把一些公用的代码放在一个文件里，以 API 接口的形式在其他地方调用，有利于代码的重用和降低代码耦合度。

Lua 的模块是由变量、函数等已知元素组成的 table，因此创建一个模块很简单，就是创建一个 table，然后把需要导出的常量、函数放入其中，最后返回这个 table 就行。

```lua
-- mymodule.lua
-- 创建模块
mymodule = {}
mymodule.name = 'myname'

-- 公有方法
function mymodule.func1()
  -- ...
end

-- 私有方法
local function func2()
  -- ...
end

function mymodule.func3()
  func2()
end

return mymodule

-- testmymodule.lua
-- 导入模块
require('mymodule') -- 通过 mymodule 调用模块内容

local testModule = require('mymodule') -- 通过 testModule 调用
```

## 5. 高级

## 6. 注意点

1. 文件以 **lua** 结尾
2. 控制台输入 **lua xxx.lua** 即可执行 lua 文件
