# C++基础入门

## 1. C++初识

### 1.1 Hello World

```c++
#include<iostream>
using namespace std;
int main() {
    cout << "Hello World." << endl;
    return 0;
}
```

### 1.2 注释

C++ 有两种注释：单行注释和多行注释。

单行注释使用 `//`

多行注释使用 `/**/`

### 1.3 变量

使用变量来命名内存空间，好方便管理内存。

```c++
int num = 10;
// int 类型的变量名，在内存中开辟一个空间存放数值10，使用一个变量名来指向这个空间，方便管理。
```

### 1.4 常量

常量有两种类型： `#define` 声明的常量和 `const` 声明的常量。常量一旦声明不可修改。

`#define 常量名 常量值`，一般声明在文件顶部。

`const 变量名 = 变量值` ，一般声明在函数的内部。

```c++
#define WEEK 7

const month = 12;
```

### 1.5 关键字

关键字是 C++ 中预先保留的标识符。**在定义变量或常量的时候，不可使用关键字。**

|  do   |   if    | return |  typedef  | break |
| :---: | :-----: | :----: | :-------: | :---: |
|  int  |  long   |  bool  |  double   | float |
| char  | private | public | protected | void  |
| class |  const  | catch  |   case    | enum  |
|  ...  |         |        |           |       |

### 1.6 标识符命名规则

- 标识符不能是关键字
- 标识符只能由数字、字母、下划线组成
- 第一个字母必须是字母或下划线
- 标识符中字母区分大小写

> 建立：给标识符命名时，尽量做到见名知意的效果，方便阅读。

## 2. 数据类型

C++ 规定在创建一个变量或常量时，必须要指定出相应的数据类型，否则无法给变量或常量分配内存空间。

数据类型存在意义：给变量分配合适的内存空间。

### 2.1 整型

| 整型数据               | 占用空间 | 取值范围         |
| ---------------------- | -------- | ---------------- |
| short（短整型）        | 2字节    | （-2^15~2^15-1） |
| int（整型）            | 4字节    | （-2^31~2^31-1） |
| long（长整型）         | 4字节    | （-2^31~2^31-1） |
| long long （长长整型） | 8字节    | （-2^63~2^63-1） |

### 2.2 sizeof关键字

利用 `sizeof` 关键字可以统计 **数据类型所占内存大小** 。

> sizeof(数据类型 | 变量)

```c++
sizeof(int); //4
sizeof(long);//4
sizeof(long long);//8
```

### 2.3 实型（浮点型）

作用：用于表示小数。

浮点型变量分为两种：

- 单精度float
- 双精度double

| 数据类型 | 占用空间 | 有效数字范围 |
| -------- | -------- | ------------ |
| float    | 4字节    | 7位          |
| double   | 8字节    | 15~16位      |

```c++
float f1 = 3.14f;
double d1 = 3.14;
```

### 2.4 字符型

作用：字符型变量用于显示单个字符。

> char ch = 'a';

- 注意1：在显示字符串变量时，用 **单引号** 将字符括起来，**不要用双引号**
- 注意2：单引号内 **只能有一个字符** ，不可以是字符串

C 和 C++ 中字符型变量只占用一个字节。

字符型变量并不是把字符本身放到内存中存储，而是将对应的ASCII编码放入到存储单元。

```c++
char ch = 'a';
sizeof(char);// 1
(int) ch //97，对应的ASCII编码
// a - 97
// A - 65
```

### 2.5 转义字符

作用：用于表示一些不能显示出来的ASCII字符。

`\`

### 2.6 字符串型

作用：用于表示一串字符。

C风格字符串：`char ch[] = ""`。用双引号括起来。

C++：`string str = ""`

```c++
char ch = 'a';//必须要用单引号
char str1[] = "Hello World";//必须要用双引号，用单引号报错

#include<string>
string str2 = "Hello C++";
```

### 2.7 bool

一个字节

### 2.8 cout,cin

```c++
int a;
cout << "input int number: " << endl;
cin >> a;
```

## 3. 运算符

### 3.1 算术运算符

### 3.2 赋值运算符

### 3.3 比较运算符

### 3.4 逻辑运算符

| 运算符 | 术语 | 示例   | 结果                    |
| ------ | ---- | ------ | ----------------------- |
| !      | 非   | !a     | a为真，!a为假；反之亦可 |
| &&     | 与   | a&&b   | 一假为假                |
| \|\|   | 或   | a\|\|b | 一真为真                |

## 4. 程序流程结构

### 4.1 选择结构

- if语句：if...else if ... else
- 三目运算符：? :
- switch语句：switch...case

### 4.2 循环结构

- while
- do...while
- for

### 4.3 跳转结构

- break
- continue
- goto

## 5. 数组

### 5.1 概述

所谓数组，就是一个集合，里面放着相同类型的数据元素。

- 数组中每个数据元素都是相同的数据类型
- 数组是由连续的内存位置组成的
- 定义数组的时候，必须初始长度

### 5.2 一维数组

三种定义：

- `数据类型 数组[数组长度];`
- `数据类型 数组名[数组长度] = {value1, value2, ...}`
- `数据类型 数组名[] = {value1, value2, ...}`

### 5.3 二维数组

## 6. 函数

### 6.1 概述

作用：将一段经常使用的代码封装起来，减少重复代码。

一个较大的程序，一般分为若干个程序块，每个模块实现特定的功能。

函数主要有三步：

- 函数声明
- 函数定义
- 函数调用

### 6.2 函数的定义

函数的定义一般分为5个步骤：

- 返回值类型
- 函数名
- 参数列表
- 函数体
- return

```c++
void getMyName(Person person) {
    // todo
    return person.getName();
}
```

### 6.3 函数调用

### 6.4 值传递

形参发生的改变不会影响实参。

### 6.5 函数的常见样式

- 无参无返
- 有参无返
- 无参有返
- 有参有返

### 6.6 函数声明

### 6.7 函数的分文件编写

作用：让代码结构更加清晰

函数分文件编写一般有4个步骤：

- 创建后缀名为.h的头文件
- 创建后缀名为.cpp的源文件
- 在头文件中写函数的声明
- 在源文件中写函数的定义

示例：

```c++
// swap.h
#include<iostream>
using namespace std;

void swap(int a, int b);

// swap.cpp
#include "swap.h"

void swap(int *a, int *b) {
    int *temp = 0;
    temp = a;
    a = b;
    b = temp;
}

// main.cpp
#include<iostream>
#include "swap.h"
using namespace std;

int main() {

}
```

## 7.  指针

### 7.1 指针的基本概念

指针的作用：可以通过指针间接访问内存

- 内存编号从0开始记录，一般用十六进制数字表示
- 可以利用指针变量保存地址

### 7.2 指针变量的定义和使用

指针变量定义语法：`数据类型 *变量名`

```c++
int main() {
    int a = 10;
    int *p;//定义指针
    p = &a;//指针指向变量a的地址

    // &a和p输出值一样
    cout << &a << endl;
    cout << p << endl;

    // 通过*操作符操作指针变量指向的内存
    cout << *p << endl;

    return 0;
}
```

### 7.3 指针所占内存空间

32位系统：4字节（1字节8位 ）

### 7.4 空指针和野指针

空指针：指针变量指向内存中编号为0的空间。

用途：初始化指针变量

注意：空指针指向的内存是不可以访问的

```c++
int main() {
    // 空指针
    int *p = NULL;
}
```

野指针：指针变量指向非法的内存空间

```c++
int main() {
    //指针变量p指向内存地址编号为0x1110的空间
    //直接指向一块内存，无访问权限
    int *p = (int *)0x1110;
    //访问野指针报错
    cout << *p << endl;
}
```

### 7.5 const修饰指针

const修饰指针有三种情况：

1. const修饰指针——常量指针
2. const修饰常量——指针常量
3. const即修饰指针，又修饰常量

- 常量指针：指针的指向可以修改，但是指针指向的值不可以修改。 `const int *p =&a;`
- 指针常量：指针的指向不可以改，但指针指向的值可以改。`int * const p = &a;`
- 即修饰指针又修饰常量：指针的指向和指针指向的值都不可修改。`const int * const p = &a;`

记忆：看const右侧紧跟着的是指针还是常量，是指针就是常量指针，是常量就是指针常量。

`const *` ==> 常量指针，p可改，*p不可改

`* const` ==> 指针常量，*p可改，p不可改

```C++
int main() {
    int a = 10;
    int b = 20;

    //1. 常量指针，指针指向可改，指针指向的值不可改
    const int * p = &a;
    p = &b;//正确
    //*p = 100;//错误

    //2. 指针常量，指针指向不可改，指针指向的值可改
    int * const p2 = &a;
    *p2 = 200;//正确
    //p2 = &b;//错误

    //3. 即修饰指针又修饰常量，指针指向和指针指向的值都不可修改
    const int * const p3 = &a;
    // *p3 = 1000;//错误
    // p = &b;//错误
}
```

### 7.6 指针和数组

作用：利用指针访问数组中的元素。

```c++
int main() {
    int arr[] = {1,2,3,4,5};
    int * p = arr;//arr就是数组首地址
    cout << "指针访问第一个元素：" << *p << endl;
    cout << *(p + 1) << endl;
}
```

### 7.7 指针和函数

作用：利用指针作函数参数，可以修改实参的值。

```c++
void swap(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
int main() {
    int a = 10;
    int b = 10;
    // 地址传递
    swap(&a, &b);
}
```

### 7.8 指针、数组、函数

```c++
// int *arr ==> int arr[]
int bubbleSort(int *arr, int len) {
    for (let i = 0; i < len; i++) {
        for (let j = 0; j < len - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int tem = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
```

## 8.  结构体

### 8.1 结构体基本概念

结构体属于用户自定义的数据类型，允许用户存储不同的数据类型。

### 8.2 结构体的定义和使用

语法：`struct 结构体名 {结构体成员列表}`

通过结构体创建变量的方式有三种：（struct 关键字可以省略）

- struct 结构体名 变量名
- struct 结构体名 变量名 = {成员1值，成员2值}
- 定义结构体时顺便创建变量

```c++
// 定义结构体
struct Student {
    string name;
    int age;
    int gender;
    //...
} stu4;

int main() {
    //通过结构体创建具体变量
    // 方式1
    struct Student stu1;
    stu1.name = "xxx";
    stu1.age = 18;
    stu1.gender = 1;

    // 方式2
    struct Student stu2 = {
        "yyy",
        19,
        1
    }

    //方式3
    // stu4就是定义结构体时顺便创建变量
    // struct Strudent {} stu3;
}

```

> 注意1：定义结构体时的关键字是struct，不可胜利
>
> 注意2：创建结构体变量时，关键字struct可以省略
>
> 注意3：结构体变量利用操作符 "." 访问成员

### 8.3 结构体数组

作用：将自定义的结构体放入到数组中方便维护

语法：`struct 结构体名 数组名[元素个数] = {{}, {}, ...}`

```c++
struct Student stu[3] = {
    {"zzz", 18, 1},
    {"xxx", 18, 0},
    {"ccc", 19, 1}
};
```

### 8.4 结构体指针

作用：通过指针访问结构体中的成员

- 利用操作符 `->` 可以通过结构体指针访问结构体属性

```c++
struct Student stu = {"zzz", 19, 1};
// 指针指向结构体变量
struct Student * p = &stu;
p->name;
p->age;
p->gender;
```

### 8.5 结构体嵌套结构体

作用：结构体中的成员可以是另一个结构体

```c++
struct Teacher {
    int id;
    string name;
    int age;
    struct Student stu;
}

struct Student {
    int id;
    string name;
    int age;
}

struct Teacher tea;
tea.id = 1001;
tea.name = "dawang";
tea.age = 60;
tea.stu.id = 111001;
tea.stu.name = "xiaowang";
tea.stu.age = 18;
```

### 8.6 结构体做函数参数

作用：将结构体作为参数向函数中传递

传递方法有两种：

- 值传递
- 地址传递

```c++
struct Student {
    int id;
    string name;
    int age;
}
// 值传递
void printStudentInfo(student stu) {
    stu.age = 30;//不影响实参
    cout << stu.id << endl;
    cout << stu.name << endl;
    cout << stu.age << endl;
}
// 地址传递
void printStudentInfo2(student * p) {
    stu.age = 33;//影响实参
    cout << p->id << endl;
    cout << p->name << endl;
    cout << p->age << endl;
}

int main() {
    student stu = {1001, "zzz", 18};

    printStudentInfo(stu);
}
```

> 注意：如果不想修改主函数中的数据，用值传递，反之用地址传递。

### 8.7 结构体中const只用场景

作用：用 const 来防止误操作。

```c++
struct Student {
    int id;
    string name;
    int age;
}

// 加const避免修改实参
void printStuInfo(const student * stu) {
    //stu.age = 100;//错误，用 const 修饰不可更改
    cout << stu->id << endl;
    cout << stu->name << endl;
    cout << stu->age << endl;
}
```
