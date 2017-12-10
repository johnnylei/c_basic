数组指针:指针指向数组的某个元素
**数组作为函数参数,传递的是引用**
```
// 两种形式do
void test(int arr[]);
void test(int *arr);
```
```
int a[] = {1, 2, 3, 4};
int *p;

// 两种都是可以的,指针指向数组的第一个元素
p = a;
p = &a[0];
// 指针指向数组最后一个元素
p = &a[sizeof(a)/sizeof(int) - 1]
```
指针数组:数组里面的每个元素都是指针
```
#define MAX + 3

int a = {1, 2, 3};
int *p[MAX];

for(int i = 0; i < MAX; i++) {
  p[i] = &a[i]; // 为每个指针赋值
}

for (int i = 0; i < MAX; i++) {
  printf("pointer is %d and address is %x\n", *p[i], p[i]);
}
```
```
int str_arr() {
    char *names[] = {
        "johnny",
        "nicoals",
        "wesley"
    };  

    for(int i = 0; i < 3; i++) {
        printf("hello %s\n", names[i]);
    }   
    return 0;
}

```
二级指针
指向指针的指针是一种多级间接寻址的形式，或者说是一个指针链。通常，一个指针包含一个变量的地址。当我们定义一个指向指针的指针时，第一个指针包含了第二个指针的地址，第二个指针指向包含实际值的位置。
![img](http://www.runoob.com/wp-content/uploads/2014/09/pointer_to_pointer.jpg)

## 函数指针与指针函数
- 指针函数:是一个函数,返回值位指针
- 函数指针:是一个指针,指针指向函数

### 函数指针
指向函数的指针变量
函数指针可以像一般函数一样,用于调用函数,传递参数
```
typedef int (*func_ptc)(int, int);
// 实例
int max(int x, int y) {
    return x > y ? x : y;
}

int (*m)(int, int);
m = &max;
```
### 回调函数
** 函数指针作为某个函数的参数 **
函数指针变量可以作为某个函数的参数来使用的，回调函数就是一个通过函数指针调用的函数。
回调函数是由别人的函数执行时调用你实现的函数。
>你到一个商店买东西，刚好你要的东西没有货，于是你在店员那里留下了你的电话，过了几天店里有货了，店员就打了你的电话，然后你接到电话后就到店里去取了货。在这个例子里，你的电话号码就叫回调函数，你把电话留给店员就叫登记回调函数，店里后来有货了叫做触发了回调关联的事件，店员给你打电话叫做调用回调函数，你到店里去取货叫做响应回调事件。

```
#include <stdlib.h>  
#include <stdio.h>

// 回调函数
void target(char *str, int size) {
    for(int i = 0; i < size; i++) {
        printf("%c", str[i]);
    }   
    printf("\n");
}

void _log (void (*target)(char *, int)) {
    char str[] = "hello johnny, i am wesley, nice to see you";
    target(str, sizeof(str)/sizeof(char));
}

_log(target);
```
