#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

// Practice: How to create a child process!

int main(int argc, char const *argv[])
{
	// pid_t是数据类型，实际上是一个整型
	// 通过typedef重新定义了一个名字，用于存储进程id
	pid_t pid; // parent pid
	pid_t cid; // child pid
	// getpid()函数返回当前进程的id号
	printf("Before fork Process id: %d\n", getpid());
	//
	// fork()函数用于创建一个新的进程，该进程为当前进程的子进程，创建的方法是：fork函数
	// fork()的返回值：
	// 	如果成功创建子进程，对于父子进程fork会返回不同的值，对于父进程他的返回值是子进程的id号，对于子进程它的返回值是0
	// 	如果创建失败，返回值为-1
	cid = fork();
	printf("After fork, Process id: %d\n", getpid());
	printf("After fork, Current id: %d\n", cid);
	pause();
	return 0;
}
