/*************************************************************************
  > File Name: client.c
  > Author: Arwen
  > Mail:745529725@qq.com 
  > Created Time: Fri 27 Feb 2015 10:43:15 AM CST
 ************************************************************************/

#include"FTP_client.h"
int main(int argc ,  char *argv[])
{
	int fd_client;
	char buf[1024];
	char line[128]= "0";
	char name[128]= "0";
	char stat;
	unsigned long size ;
	MY_ASSERT((fd_client = socket(AF_INET,SOCK_STREAM ,0))!=-1 ,"listen socket init");
	struct sockaddr_in cliaddr ,seraddr;
	memset(&seraddr, 0, sizeof(seraddr));
	memset(&cliaddr, 0, sizeof(cliaddr));
	cliaddr.sin_family = AF_INET;
	cliaddr.sin_port = htons(atoi(argv[2]));
	cliaddr.sin_addr.s_addr = inet_addr(argv[1]);

	MY_ASSERT(connect(fd_client, (struct sockaddr*)&cliaddr,sizeof(cliaddr)) ==0,"connect");
	while(1)
	{
		memset(buf ,0 , 1024);
		fgets(buf ,1024, stdin);
		send(fd_client, buf, 1024, 0);
		if(strncmp(buf,"ls",2)==0)//ls
		{
			system("clear\n");
			while(memset(buf,0 ,sizeof(buf)),recv(fd_client, buf, sizeof(buf),0)!=-1)
			{
				if(strncmp(buf,"OK",2)!=0)
				{
					sscanf(buf, "%s %c %lu",name,&stat,&size);
					if(stat & DT_DIR)
						printf("    \033[34m%-30s\033[0m -------- %lu b\n",name,size);
					else
						printf("    %-30s -------- %lu b\n",name,size);
				}else{
					break;
				}
			}
		}
		else if(strncmp(buf,"cd",2)==0)//cd
		{
		
			recv(fd_client, line, sizeof(line), 0);
			printf("%s\n", line);
		}else if(strncmp(buf,"pwd",3)==0)//pwd
		{

			recv(fd_client, line, sizeof(line), 0);
			printf("%s\n",line);

		}else if(strncmp(buf,"gets",4)==0)//gets
		{
			client_gets(fd_client);

		}else if(strncmp(buf,"puts",4)==0)
		{
            client_puts(fd_client);

		}else if(strncmp(buf,"remove",6)==0)
		{
			
			client_remove(fd_client);

		}else if(strncmp(buf, "clear", 5) == 0)
		{
			system("clear");		
		}
		else{
			printf("error command!\n");
		}
	}
	return 0;
}

