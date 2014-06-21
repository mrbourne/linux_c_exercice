/************************************************************************
  > File Name: ./src/myls.c
  > Author: Zason
  > Mail:343466249@qq.com 
  > Created Time: 2014年06月20日 星期五 11时21分15秒
 ************************************************************************/

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <grp.h>
#include <pwd.h>

//version 1.1.0
void mode_to_str(mode_t mod, char *str)
{
	strcpy(str, "----------");
	if (S_ISDIR(mod))
		str[0] = 'd';
	if (mod & S_IRUSR)
		str[1] = 'r';
	if (mod & S_IWUSR)
		str[2] = 'w';
	if (mod & S_IXUSR)
		str[3] = 'x';
	if (mod & S_IRGRP)
		str[4] = 'r';
	if (mod & S_IWGRP)
		str[5] = 'w';
	if (mod & S_IXGRP)
		str[6] = 'x';
	if (mod & S_IROTH)
		str[7] = 'r';
	if (mod & S_IWOTH)
		str[8] = 'w';
	if (mod & S_IXOTH)
		str[9] = 'x';
}
void format_time(char **str)
{
	int i;
	char *p = *str;
	while (*p++);
	while (*p != ':')
	{
		--p;
	}
	*p = '\0';
	for (i = 0; i < 4; ++(*str), ++i);
}
int main(int argc, char *argv[])
{
	DIR *pDIR;
	struct dirent* myent;
	struct stat statbuf;
	char file_mode[32];	//文件模式
	char *owner;	//创建者
	char *group;	//群组
	char *last_time;//上次访问时间
	int i;
	char path[256];

	if (argc < 2)
		sprintf(path, ".");
	else
	{	
		sprintf(path, "%s", argv[1]);
		printf("%s\n", path);
	}
	pDIR = opendir(path);
	if (pDIR == NULL)
	{
		perror("open dir fail:");
		return -1;
	}
	while ( (myent = readdir(pDIR)) != NULL)
	{
		if ( strncmp(myent -> d_name, ".", 1) != 0 && strncmp(myent -> d_name, "..", 2) != 0)
		{
			memset(&statbuf, 0, sizeof(struct stat) * 1);
			memset(file_mode, 0, sizeof(char) * 32);
			printf("%s\n", myent -> d_name);
			sprintf(path, "%s/%s", path, myent -> d_name);
			printf("%s\n", path);
			stat(path, &statbuf);
			mode_to_str(statbuf.st_mode, file_mode);
			last_time = ctime(&statbuf.st_atime);
			format_time(&last_time);
			owner = getpwuid(statbuf.st_uid) -> pw_name;
			group = getgrgid(statbuf.st_gid) -> gr_name;
			printf("%s %d %-5s %-5s %6d %s %-10s \n", file_mode, statbuf.st_nlink, owner, group, statbuf.st_size, last_time, myent -> d_name);
		}
	}
	closedir(pDIR);	
	return 0;
}
