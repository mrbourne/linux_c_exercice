/*************************************************************************
	> File Name: ./src/change_dir.c
	> Author: Zason
	> Mail:343466249@qq.com 
	> Created Time: 2014年06月20日 星期五 09时28分08秒
 ************************************************************************/

#include "unistd.h"

int main(int argc, char *argv[])
{
	int iret;
	if (argc ==1)
	{
		iret = chdir("/home");
	}
	else
	{
		iret = chdir(argv[1]);
	}
	if (iret != 0)
		perror("chdir fail.\n");

	return 0;

}
