## 变量
```
name="johnny"
echo $name
unset name
echo $name

qmg_erp="http://www.qmgxxx.com"
readonly qmg_erp
# qmg_erp="http:www.qmxx.com"

# 输出字符串长度
echo ${#qmg_erp}

# 截取字符串
echo ${qmg_erp:0:4}

# 数组
score=(100 60 500 95)
echo ${score[@]}

# 元数个数
length=${#score[@]}
echo $length
```

## 外部参数
|参数处理|说明|
|-|-|
|$#|参数个数|
|$*|打印出所有参数|
|$0|打印命令名字|
|$1|打印第一个参数|
|$$|进程ID|
|$@|与$*类似|

```
echo "shell params"
echo "pid is $$"
echo "the number of params:$#"
echo "the params:$*"
echo "the params:$@"
echo "program : $0"
echo "first param: $1"
echo "second param: $2"
echo "third param: $3"

echo "-- \$* 演示 ---"
for i in "$*"; do
    echo $i
done
```

## 数组
```
arr=(johnny nioclas "lei")

echo ${arr[0]}
echo ${arr[1]}
echo ${arr[2]}

# 输出所有元数
echo "输出所有元数"
echo ${arr[*]}
echo ${arr[@]}

# 输出数组长度
echo "输出数组长度"
echo ${#arr[*]}
echo ${#arr[@]}
```

## 运算
- 算数运算符
- 关系运算符
- 布尔运算符
- 字符串运算符
- 文件测试运算符

### 要点
- 表达式和运算符之间要有空格，例如 2+2 是不对的，必须写成 2 + 2，这与我们熟悉的大多数编程语言不一样。
- 完整的表达式要被 ` ` 包含，注意这个字符不是常用的单引号，在 Esc 键下边。

### 关系运算符
|运算符|说明|举例|
|-|-|-|
|-eq	|检测两个数是否相等，相等返回 true。	|[ $a -eq $b ] 返回 false。|
|-ne	|检测两个数是否相等，不相等返回 true。	|[ $a -ne $b ] 返回 true。|
|-gt	|检测左边的数是否大于右边的，如果是，则返回 true。	|[ $a -gt $b ] 返回 false。|
|-lt	|检测左边的数是否小于右边的，如果是，则返回 true。	|[ $a -lt $b ] 返回 true。|
|-ge	|检测左边的数是否大于等于右边的，如果是，则返回 true。	|[ $a -ge $b ] 返回 false。|
|-le	|检测左边的数是否小于等于右边的，如果是，则返回 true。	|[ $a -le $b ] 返回 true。|

### 布尔运算符
|运算符|说明|举例|
|-|-|-|
|!	|非运算，表达式为 true 则返回 false，否则返回 true。	|[ ! false ] 返回 true。|
|-o	|或运算，有一个表达式为 true 则返回 true。	|[ $a -lt 20 -o $b -gt 100 ] 返回 true。|
|-a	|与运算，两个表达式都为 true 才返回 true。	|[ $a -lt 20 -a $b -gt 100 ] 返回 false。|

### 文件测试运算符
|运算符|说明|举例|
|-|-|-|
|-b file|	检测文件是否是块设备文件，如果是，则返回 true。	|[ -b $file ] 返回 false。|
|-c file|	检测文件是否是字符设备文件，如果是，则返回 true。	|[ -c $file ] 返回 false。|
|-d file|	检测文件是否是目录，如果是，则返回 true。	|[ -d $file ] 返回 false。|
|-f file|	检测文件是否是普通文件（既不是目录，也不是设备文件），如果是，则返回 true。	|[ -f $file ] 返回 true。|
|-g file|	检测文件是否设置了 SGID 位，如果是，则返回 true。	|[ -g $file ] 返回 false。|
|-k file|	检测文件是否设置了粘着位(Sticky Bit)，如果是，则返回 true。	|[ -k $file ] 返回 false。|
|-p file|	检测文件是否是有名管道，如果是，则返回 true。	|[ -p $file ] 返回 false。|
|-u file|	检测文件是否设置了 SUID 位，如果是，则返回 true。	|[ -u $file ] 返回 false。|
|-r file|	检测文件是否可读，如果是，则返回 true。|	[ -r $file ] 返回 true。|
|-w file|	检测文件是否可写，如果是，则返回 true。|	[ -w $file ] 返回 true。|
|-x file|	检测文件是否可执行，如果是，则返回 true。|	[ -x $file ] 返回 true。|
|-s file|	检测文件是否为空（文件大小是否大于0），不为空返回 true。	|[ -s $file ] 返回 true。|
|-e file|	检测文件（包括目录）是否存在，如果是，则返回 true。	|[ -e $file ] 返回 true。|
