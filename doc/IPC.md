**IPC inter process communication**
- 线程内存共享，所以不存在通信
- 进程是内存不共享，所以需要进程间通信

## IPC
- pipe(fifo 有名管道)
  - pipe 内存文件
```
mkfifo /var/xxx_fifo
进程a:打开/var/xxx_fifo,写入数据
进程b:打开/var/xxx_fifo，读取数据
```
- message que
- shared memory
- socket

### pipe　是一个特殊的内存文件
- open是阻塞的
- read是阻塞的
- 数据传输是单向的<br>
**普通文件是做不到这些特性的**
```
open();　# open操作pipe是阻塞式，除非两端同时打开，才往下执行
read(); # read操作pipe是阻塞式
write();
close();
```
**pipe是单向的，进程a->b是管道，进程b->a需要另外打开一个管道**
