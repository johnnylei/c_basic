## 标准c(适用于各种平台)
fopen, fclose, fwrite, fread

## Linux API(仅适用于Linux)
open, close, write, read

# linux 下面设备文件
/dev目录下面
```
crw-rw-rw-   1 root root      1,   5 12月 12 09:47 zero # c(character)
brw-rw----   1 root disk      7,   1 12月 12 09:47 loop1 #b(block)
```
设备文件代表物理设备,对文件的操作,就是对设备的操作
```
/dev/snd #声卡
/dev/sda1 # 磁盘
/dev/printer # 打印机
```
## linux api 函数,操作设备(嵌入式开发需要用到)
```
open 打开设备
read 读取设备
write 写入设备
close 关闭设备
ioctl
```
