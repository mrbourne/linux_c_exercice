/*************************************************************************
	> File Name: ./src/main.c
	> Author: Zason
	> Mail:343466249@qq.com 
	> Created Time: 2014年06月20日 星期五 09时20分34秒
 ************************************************************************/

#include <unistd.h>

int main(int argc, char *argv[])
{
	char *path;
	path = getcwd(NULL, 0);
	printf("%s\n", path);
}
