/*************************************************************************
	> File Name: ./include/head.h
	> Author: Arwen
	> Mail:745529725@qq.com 
	> Created Time: Thu 19 Mar 2015 09:47:39 PM CST
 ************************************************************************/
#ifndef __HEAD_H__
#define __HEAD_H__
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/wait.h>
#include<sys/select.h>
#include<sys/time.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#define FILE_NAME "main.c"
typedef struct child_tag
{
	int ch_fd ;
	pid_t ch_pid ;
	int ch_busy ;
}child_t, *pchild_t;

void make_child(pchild parr, int nchild);
static void child_main(int fd);

#endif

