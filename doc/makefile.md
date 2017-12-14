```
target:dependences # target表示目标,dependences表示依赖,实现增量编译的依据，若果dependences里面的文件最近更新过，make命令的时候就会增量编译，将最近更新过的文件编译一下
<tab>system command # 要执行的系统命令
<tab>system command
<tab>system command
...
```
examples
```
file_ergodic:
  gcc file_ergodic.c -o file_tree
```
examples
```
file_ergodic:
    gcc file_ergodic.c -o file_tree
    sudo ln -s /home/johnny/github/c_basic/source/file_tree /usr/bin/file_tree
sort:
    gcc sort.c _sort.c -o sort
```
make #默认执行第一个target
make sort; # 执行sort规则

## 编译
- 增量编译:全部编译
- 全量编译:只编译改动过的文件

举例，比如有
```
main.c a.c, b.c c.c, e.c, f.c, g.c
a.c -> a.o
b.c -> b.o
c.c -> c.o
e.c -> e.o
f.c -> f.o
g.c -> g.o
main.c -> main.o
a.o b.o c.o d.o e.o f.o g.o main.o -> application
```
** 依据dependences,check这些文件最近更新时间，来决定那些文件需要从新编译 **
## 时间比较
target(T1):dependences(T2)
- 若target文件不存在折T1为0
- 若dependences为空折T2为0

比较T1, T2
```
if(T1==0) :
执行
else if(T2>T1) :
执行
else:
已经是最新
endif;
```
##注释变量函数
"#"注释
### 变量(通常纯大写)
CURRENT_PATH=${shell pwd} # 当前路径
```
# make var运行
# 运行结果:src xml osapi
SUBDIR = src xml
SUBDIR += osapi
var:
    @echo $(SUBDIR) #"@"不显示命令行本身
```

#### 特殊变量
- $@上下文target
- $^依赖列表
- $<依赖的第一项

## 函数
```
$(函数名 param1, param2, ...)　#函数名只能是makefile内部自带的函数，不能自定义，参数以逗号隔开
CURRENT_PATH = $(shell pwd) #函数调用,获取当前路径
CPP_FILE_LIST = $(wildcard ./*.cpp) #获取(./)路劲下，*.cpp的文件列表
```
## makefile 优化
```
sort:sort.h sort.o _sort.o
    gcc sort.o _sort.o -o sort

sort.o:sort.c
    gcc -c sort.c -o sort.o

_sort.o:_sort.c
    gcc -c _sort.c -o _sort.o

clean:
    rm *.o sort
```
step1:使用通配符
```
sort:sort.h sort.o _sort.o
    gcc sort.o _sort.o -o sort

%.o:%.c # "%"匹配一个单词
    gcc -c $^ -o $@

clean:
    rm *.o sort
```
step2:简化依赖文件
```
C_FILE_LIST = $(wildcard *.c)
#O_FILE_LIST = $(wilecard *.o)
O_FILE_LIST = $(patsubst %.c, %.o, $(C_FILE_LIST))
sort:sort.h $(O_FILE_LIST)
    gcc $^ -o sort

%.o:%.c
    gcc -c $< -o $@

clean:
    rm *.o sort
```
- patsubst 格式
  - 源格式
  - 目标格式
  - 源列表
```
O_FILE_LIST = $(patsubst %.c, %.o, $(C_FILE_LIST))
```
step3自动生成头文件依赖

** 使用编译选项，-MMD;g++/gcc在编译xxx.c时，自动提取里面包含的头文件（双引号包含头文件）**
```
#include "other.h"
```
生成相应的.d文件，在生成main.o的同时，生成一个main.d文件
```
gcc -c -MMD main.c -o main.o
```
优化之后结果
```
SUBDIR = src xml
SUBDIR += osapi
C_FILE_LIST = $(wildcard *.c)
#O_FILE_LIST = $(wilecard *.o)
O_FILE_LIST = $(patsubst %.c, %.o, $(C_FILE_LIST))
D_FILE_LIST = $(patsubst %.c, %.d, $(C_FILE_LIST))
APPLIACTION = sort
$(APPLIACTION):sort.o _sort.o
    gcc $^ -o $(APPLIACTION)

%.o:%.c
    gcc -c -MMD $< -o $@

-include $(D_FILE_LIST)

#sort.o:sort.h

clean:
    rm -rf *.o *.d $(APPLIACTION)

var:
    @echo $(SUBDIR)

wild_card:
    @echo $(C_FILE_LIST)
    @echo $(O_FILE_LIST)
```

step4:支持子目录
- 使用子目录
```
SUBDIR=src
C_FILE_LIST=$(foreach dir, $(SUBDIR), $(wildcard $(dir)/*.c))
```

编译前文件结构
```
├── bin
├── complied
├── file_tree
├── header
│   └── sort.h
├── Makefile
├── sort
├── src
│   ├── _sort.c
│   ├── sort.c
├── tags
└── tmp
```

```
COMPLIED = complied # complied 相对路径
SRC = src # src相对路径
C_FILE_LIST = $(foreach dir, $(SRC), $(wildcard $(dir)/*.c)) # 列出src下面所有c文件
O_FILE_LIST = $(patsubst $(SRC)/%.c, $(COMPLIED)/%.o, $(C_FILE_LIST)) # 列出complied下面所有.o文件
D_FILE_LIST = $(patsubst $(SRC)/%.c, $(COMPLIED)/%.d, $(C_FILE_LIST)) # 列出complied下面所有.d文件
APPLICATION = sort # application name
APPLICATION_DEPENDENCE = $(COMPLIED)/sort.o $(COMPLIED)/_sort.o # application dependences
$(APPLICATION):$(APPLICATION_DEPENDENCE)
    gcc $^ -o $(APPLICATION)

$(COMPLIED)/%.o:$(SRC)/%.c #编译.o文件,依据application dependences 来确定要编译那些.o文件,并且写入到complied文件夹下面
    gcc -c -MMD $< -o $@

-include $(D_FILE_LIST) # -MMD会自动提取.c文件里面.h文件,写入到.d文件里,这里引入即可

clean:
    rm -rf *.o *.d $(APPLICATION)
    rm -rf $(COMPLIED)/*

var: #打印变量
    @echo $(C_FILE_LIST)
    @echo $(O_FILE_LIST)
    @echo $(D_FILE_LIST)
    @echo $(APPLICATION)
    @echo $(APPLICATION_DEPENDENCE)
```
编译后文件结构
```
├── bin
├── complied
│   ├── _sort.d
│   ├── sort.d
│   ├── _sort.o
│   └── sort.o
├── file_tree
├── header
│   └── sort.h
├── Makefile
├── sort
├── src
│   ├── _sort.c
│   ├── sort.c
├── tags
└── tmp
```
