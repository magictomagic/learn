# Hello World

到 https://github.com/denoland/deno 参考 README 运行 `deno run  --allow-net helloWorld.ts`

# [基本盘][1]

## Toolkit

`deno-cli` 提供了一组集成功能，让你可以沉浸在 Deno 的专有开发环境中

```shell
SUBCOMMANDS:
  bundle         Bundle module and dependencies into single file
  cache          Cache the dependencies
  completions    Generate shell completions
  doc            Show documentation for a module
  eval           Eval script
  fmt            Format source files
  help           Prints this message or the help of the given subcommand(s)
  info           Show info about cache or info related to source file
  install        Install script as an executable
  repl           Read Eval Print Loop
  run            Run a program given a filename or url to the module
  test           Run tests
  types          Print runtime TypeScript declarations
  upgrade        Upgrade deno executable to given version
```

## [VScode extension][2]

把上面的工具整合进了`VScode`

## [缓存][3]

+ Deno 的所有模块都要通过入口脚本加载，不能通过模块名加载，所以必须带有脚本后缀名。(node v15也是这样，估计是借鉴`Deno`的)

+ 所有模块通过 URL 加载，比如`import { bar } from "https://foo.com/bar.ts"`（绝对 URL）或`import { bar } from './foo/bar.ts'`。Deno 下载模块以后，依然会有一个总的目录，在本地缓存模块，因此可以离线使用。如果在命令行重新运行上一次的命令，则会执行缓存中已生成的文件，并不会再次从网上下载 。

+ `--reload` `标志`告诉 Deno 需要重新刷新指定文件 e.g. `deno run --reload https://deno.land/std/examples/welcome.ts`

+ `deno run --help` 查看更多`标志`

## 安全控制

- `--allow-read`：打开读权限，可以指定可读的目录，比如`--allow-read=/temp`。
- `--allow-write`：打开写权限。
- `--allow-net=google.com`：允许网络通信，可以指定可请求的域，比如`--allow-net=google.com`。
- `--allow-env`：允许读取环境变量。

## TODO

- [ ] 在 VSCode 或 Chrome Devtools 中调试(--inspect` 或 `--inspect-brk)
- [ ] 第三方库`Oak`等
- [ ] 看看什么时候支持React, 和Node的差距趋势

# 体验

`choco `直接安装，TS原生支持`Top-Level await`，import直接下载运行，语法简洁，**爽**

# 计划

+ 他们的官网居然没有RSS，只能用RSSHUB追踪他们的推特了，效果是一样的。
+ deno必然会迅速发展到支持React等主流框架，会慢慢追上Node生态，node生态的各种插件搞得人很烦，新增加一个功能不但要命令行安装，还要改配置文件，配置文件还有各种参数与格式。。。gasby, mdx 想玩一玩安装半天东西还可能安装失败。连Python都不如。无论它们如何繁荣，大多数都是基于React的，所以应该先精通React，练好内功。
+ 还是像大多数人一样继续观望它的发展吧，太激进伤不起。

[1]: https://juejin.cn/post/6844904162321252360
[2]: https://github.com/denoland/vscode_deno/
[3]: https://www.ruanyifeng.com/blog/2020/01/deno-intro.html