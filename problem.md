# 日常工作或学习遇到的问题总结

## 1. 运算符优先级问题

```javascript
let a = null;
a ? true : false; // false
'test' + a ? true : false; // true
'test' + a && 1 ? true : false; // true
'test' + (a ? true : false); // 字符串"testfalse"
// 注意：这个时候 + 号优先级高于 &&，这种时候最好加上括号
```
