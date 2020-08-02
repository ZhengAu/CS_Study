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

## 暂停与退出

```shell
pause

exit
```