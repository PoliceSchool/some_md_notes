#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

// 执行命令：gcc hellothread.c -o hellothread -pthread

void* threadFunc(void* arg){
	printf("In NEW thread\n");
}

int main(int argc, char const *argv[])
{
	pthread_t tid; //Thread id

	// 线程创建函数
	/** 参数列表
	1. Thread id address
	2. Thread attribute address
	3. Thread function address
	4. Thread parameters address
	*/
	pthread_create(&tid, NULL, threadFunc, NULL);
	
	// 等待指定的线程结束
	pthread_join(tid, NULL);
	printf("In main thread\n");
	return 0;
}
