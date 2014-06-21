/*************************************************************************
	> File Name: ./src/mymkdir.c
	> Author: Zason
	> Mail:343466249@qq.com 
	> Created Time: 2014年06月20日 星期五 09时40分05秒
 ************************************************************************/

#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
	int iret;
	if (argc == 1)
	{
		printf("too few args!\n");
		exit(0);
	}
	else
	{
		iret = mkdir(argv[1] ,0777);
	}
}
