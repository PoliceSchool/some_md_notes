#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>

// 执行命令：gcc hellothread.c -o hellothread -pthread

void* hello(void* arg){
	for (int i = 0; i < 30; ++i){
		printf("hello(%d)\n", rand()%100);
	}
}

void* world(void* arg){
	for (int i = 0; i < 30; ++i){
		printf("world(%d)\n", rand()%100);
	}
}

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	pthread_t tid1, tid2;

	// 线程创建函数
	pthread_create(&tid1, NULL, hello, NULL);
	pthread_create(&tid2, NULL, world, NULL);
	
	// 等待指定的线程结束
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	printf("In main thread\n");
	return 0;
}
