## 单步调试
两种调试方式:
- 使用调试器结合断点观察变量和内存的值
- 打印调试

## gdb(gcc debug)
在complied的这一步,添加选项-g
```
gcc -g  main.c -o main
gdb ./main
```
进入gbd界面以后(可以输入简称,也可以输入全称)
- b(break):添加断点
  - b function b加函数名称表示在哪个函数打断点
  - b main.c:12 #文件名加行号
  - b 12 #当前文件添加断点
  - b Object::Create #类名+成员变量
- r(run)重头开始运行程序
- n(next)下一步
  - n #往下一部
  - n 2 #往下2步
- c(continue)程序继续运行,直到下一处断点
- q(quit):退出程序
- p(print):打印变量
  - p a #打印变量
  - p a+b #打印a+b
- info break #打印断点信息
- del
  - del break 1 #删除1号断点
  - del display 1
- **disp(display)监测变量,用法参照p**
- x显示内存的值
  - x/16xb buf #查看buf,查看16字节,x表示以16进制呈现
  - x:十六进制(x(16进制) o(8进制) d(十进制) u(unsigned) f s(signed))
  - b:单位是字节(b(bute) h(half-word) w(word) g(giant word))
- help info/x/q/p # 帮助命令
- bt(back trance),错误信息栈
流程
```
b main # 在mian函数打断点
r # run
n # 下一步
c # 到下一处断点
p a #打印变量a的值
quit
```

## 应用场景
当程序编译时带-g选项时,程序才可以被调试

**实际上,当以-g选项编译时,编译器将调试信息加在了目标程序里面,因此目标程序的体积会变大**
```
objdump -h hello_word # 查看hello_word是否-g编译的
// 或者
gdb hello_word # no debugging symbols found , 不可以debug
```
### gdb适用场景
- 单元测试(较短的代码,功能单纯的函数)
- 段错误的定位

### gdb不适用场景
- 大型程序
- 尤其是多线程
适用打印调试, 日志输出
