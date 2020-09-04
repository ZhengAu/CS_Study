# Egret

> 锚点

代码设置锚点居中时，注意x,y是否要设置成居中。

> list

替换list的data时，可用replaceAll()，也可 new eui.ArrayCollection(sources);

两者在对待数据渲染方面有不一样之处，具体我也说不上，就是有点效果要用后面的new才可以实现。

> 回调函数

有的方法里面有函数参数，可以通过bind等绑定this。

> list滚动

一般是控制 scroller 的滚动，把 list 添加到 scroller 下，控制 scroller 的 **scrollPolicyV**, **scrollerPolicyH** 为 **eui.ScrollPolicy.ON/OFF/AUTO** 来控制垂直或水平方向的滚动。

> 遮罩

遮罩的作用是指定一个显示对象的可见区域，所有显示对象都具备遮罩功能。设置显示对象的 **mask** 来控制可见区域，其余地方就不可见了。若要删除遮罩，就把 **mask** 置为 **null** 即可。

注意：不能使用一个遮罩对象来遮罩另一个遮罩对象。
