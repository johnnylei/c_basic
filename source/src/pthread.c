#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

struct ThreadParam {
	int id;
	char name[20];
	pthread_mutex_t *mutex;
};

void * thread_main(void * context) {
	struct ThreadParam * param = (struct ThreadParam *)context;
	if (pthread_mutex_lock(param->mutex) == 0) {
		printf("thread id is %d and name is %s\n", param->id, param->name);
		sleep(1);
		pthread_mutex_unlock(param->mutex);
	}
	return NULL;
}

int main() {
	pthread_t handle;
	pthread_mutex_t mutex;
	pthread_mutex_init(&mutex, NULL);
	struct ThreadParam *param = (struct ThreadParam *)malloc(sizeof(struct ThreadParam));
	param->id = 1;
	strcpy(param->name, "johnny");
	param->mutex = &mutex;
	if(pthread_create(&handle, NULL, thread_main, param) < 0) {
		printf("create thread failed\n");
		return 0;
	}
	
	pthread_t handle_1;
	struct ThreadParam *param_1 = (struct ThreadParam *)malloc(sizeof(struct ThreadParam));
	param_1->id = 2;
	strcpy(param_1->name, "wesley");
	param_1->mutex = &mutex;
	if(pthread_create(&handle_1, NULL, thread_main, param_1) < 0) {
		printf("create thread failed\n");
		return 0;
	}
	printf("end\n");
	pthread_join(handle, NULL);
	return 0;
}
