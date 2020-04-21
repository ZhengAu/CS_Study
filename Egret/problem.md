# Egret

> 锚点

代码设置锚点居中时，注意x,y是否要设置成居中。

> list

替换list的data时，可用replaceAll()，也可 new eui.ArrayCollection(sources);

两者在对待数据渲染方面有不一样之处，具体我也说不上，就是有点效果要用后面的new才可以实现。

> 回调函数

有的方法里面有函数参数，可以通过bind等绑定this。

> Ts增量编译模式

在 `tsconfig.json` 文件的 `compilerOptions` 中添加 `"incremental": true,"tsBuildInfoFile": "./file"`。然后使用 `tsc -w` 启动增量编译模式。

项目大的情况下，采用此模式可以减少代码编译时间。

> `config.ts` 添加新的 `build` 模式

在 `config.ts` 中添加如下编译模式

```javascript
let isDebugCode: boolean = false;
if (command == 'build') {
    if (isDebugCode) {
        const outputDir = './bin-release/main';
        return {
            outputDir,
            commands: [
                // new IncrementCompilePlugin(),
                new CompilePlugin({ libraryType: "debug", defines: { DEBUG: true, RELEASE: false } }),
            ]
        }
    } else {
        // 其他默认编译模式
    }
}
```

在 `index.html` 中，加载上面编译产生的文件，不用默认的单独文件。

此种模式下加载的速度会加快，但是不能在浏览器中打开单独的源代码文件，只能打开上面编译产生的文件，对debug不够友好。
