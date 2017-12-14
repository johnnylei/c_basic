**pthread库**

**linux 库文件路劲/usr/include/; /usr/lib/;**

- makefile
```
LDFLAGS += lpthread #表示使用pthread这个库
gcc -pthread pthread.c
```
- 头文件
```
#include <unistd.h>
#include <pthread.h>
```

## pthread_create
```
void * thread_main(void * context);
pthread_t handle;
pthread_create(&handle, NULL, thread_main, NULL);
```

## pthread_join
- 等待线程退出
- 回收线程资源

## 线程mutex
```
pthread_mutex_init(pthread_mutex_t *__mutex, contst pthread_mutexattr_t *__mutexattr);
pthread_mutex_destroy(pthread_mutex_t *); #阻塞
pthread_mutex_trylock(pthread_mutex_t *); #非阻塞
pthread_mutex_lock(pthread_mutex_t *);
pthread_mutex_unlock(pthread_mutex_t *);
```

## semaphore
```
sem_t hSem;
sem_init(&hSem, 1, initial_value);
sem_destroy(&hSem);
sem_wait(&hSem);
sem_post(&hSem); # 给信号
sem_timedwaite(&hSem);
```
