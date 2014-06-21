/*************************************************************************
	> File Name: ./src/myrmdir.c
	> Author: Zason
	> Mail:343466249@qq.com 
	> Created Time: 2014年06月20日 星期五 10时14分49秒
 ************************************************************************/

#include "unistd.h"

int main(int argc, char *argv[])
{
	int iret;
	if (argc == 1)
	{
		printf("too few args!\n");
		exit(-1);
	}
	else
	{
		iret = rmdir(argv[1]);
	}
	if (iret != 0)
		perror("can't rmdir!\n'");
	return 0;
}
