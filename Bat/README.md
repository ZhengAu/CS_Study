# BAT文件

## 路径

```shell
%cd%

%~dp0

%~sdp0
```

## 输出

```shell
# bat 文件开头的这句话，表示只有写了 echo 的才输出，
# 否则 bat 文件中的每一句话都会进行输出并且前面都会加上当前 bat 文件路径
@echo off

# 若是没有 @ ，第一行输出可能会有一个空行
echo off

echo 这里是输出内容
```

## 注释

```shell
::

rem
```

## 文件夹及文件

```shell
# 全路径，包括文件夹名或文件名
%1

# 文件全名
%~nx1

# 文件名，不包括扩展名
%~n1

# 文件扩展名
%~x1
```

## 设置 **set**

```shell
# 注意 = 号左右两边不能有空格
set newName=%~x1
```

## 调用其他文件或程序

```shell
# 进入到相应的路径，再使用 call xxx.bat 即可
call xxx.bat
# 首先进入要调用程序的路径，使用 start xxx.exe 即可
cd xxxx
start xxx.exe
```

## 参数与传参

```shell
# 字符串或字符使用单引号，bat 会默认单引号也是字符串的一部分，只能使用双引号
# 使用 set 定义参数，使用时必须在变量的两边加上 % 才能使用
set username="myname"
echo %username%

# 使用或不使用 单引号
echo 'abcde输出'  //输出 'abcde输出'
echo 输出内容xxx //输出 输出内容xxx

# 结合 node 一起使用的情况：
set str="AAABBB"
node xxx.js %str% 1122 2233 "abcdefghijk" [1, 2, 3, 4]
```

```javascript
# xxx.js中使用 process.argv 接受参数，第二个参数开始
# process.argv 的第一个参数是 node.exe 的路径，第二个参数是 xxx.js 文件的路径
console.log(process.argv)
console.log(process.argv.splice(2))
```

## 暂停与退出

```shell
pause

exit
```
