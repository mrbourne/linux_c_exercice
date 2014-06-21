/*************************************************************************
	> File Name: ./src/searchdir.c
	> Author: Zason
	> Mail:343466249@qq.com 
	> Created Time: 2014年06月20日 星期五 14时36分30秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>

void printfdir(char *dirname, int depth)
{
	struct dirent* entry;
	struct stat statbuf;
	DIR *pDir = opendir(dirname);
	if (pDir == NULL)
	{
		fprintf(stderr, "cannot open directory %s \n", dirname);
		return;
	}
	chdir(dirname);
	while ((entry = readdir(pDir)) != NULL)
	{
		stat(entry -> name, &statbuf);
		if (S_ISDIR(statbuf.st_mode))	//如果是文件夹
		{

		}
	}

}
