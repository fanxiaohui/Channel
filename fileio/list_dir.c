/*
 * =====================================================================================
 *
 *       Filename:  list_dir.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/12/2018 02:59:49 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
void listDir(char *path)
{
	struct dirent* ent = NULL;
	DIR *pDir;
	pDir=opendir(path);
	while (NULL != (ent=readdir(pDir)))
	{
	if (ent->d_reclen==24)
	{
	if (ent->d_type==8)
		printf("%s\n", ent->d_name);
	else
	{
		printf("子目录：%s\n",ent->d_name);
		printf("子目录：%s\n",ent->d_name);
		listDir(ent->d_name);
		printf("返回%s\n",ent->d_name);
	}
	}
	}
	listDir(ent->d_name);
	printf("返回%s\n",ent->d_name);
}

int main(int argc,char *argv[])
{
    listDir(argv[1]);
    return 0;
}

