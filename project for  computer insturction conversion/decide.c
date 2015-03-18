#include<stdio.h>
#include<string.h>
#include "decide.h"

typedef struct n_type
{
	char name[6];
	char  w[3];
}N;
N regs[35];
int total_count;
void make_table();
int decide()
{
	FILE* fp;
	int count16,count32,i;
	make_table();
	//printf("total count=%d\n",total_count);
	char s[30];
	fp=fopen("code.txt","r");
	count16=0;
	count32=0;
	while(fscanf(fp,"%s",s)==1)
	{
		//
		for(i=0;i<total_count;i++)
		{
			//printf("-\n");
			if(strstr(s,regs[i].name)!=NULL)
			{
				if(regs[i].w[0]=='1')
				{
					count16++;
				}
				else if(regs[i].w[0]=='2')
				{
					count32++;
				}
				break;
			}
		}
	}
	fclose(fp);
	printf("16 count =%d 32 count= %d\n",count16,count32);
	if(count16>=count32)
	{
		
		return 1;
	}
	return 2;
}
void make_table()
{
	int i;
	i=0;
	strcpy(regs[i].name,"EAX");
	strcpy(regs[i].w,"2");
	i++;
	strcpy(regs[i].name,"AX");
	strcpy(regs[i].w,"1");
	i++;
	strcpy(regs[i].name,"AL");
	strcpy(regs[i].w,"0");
	i++;
	strcpy(regs[i].name,"ECX");
	strcpy(regs[i].w,"2");
	i++;
	strcpy(regs[i].name,"CX");
	strcpy(regs[i].w,"1");	
	i++;
	strcpy(regs[i].name,"CL");
	strcpy(regs[i].w,"0");
	i++;
	strcpy(regs[i].name,"EDX");
	strcpy(regs[i].w,"2");
	i++;
	strcpy(regs[i].name,"DX");
	strcpy(regs[i].w,"1");
	i++;
	strcpy(regs[i].name,"DL");
	strcpy(regs[i].w,"0");
	i++;
	strcpy(regs[i].name,"EBX");
	strcpy(regs[i].w,"2");
	i++;
	strcpy(regs[i].name,"BX");
	strcpy(regs[i].w,"1");
	i++;
	strcpy(regs[i].name,"BL");
	strcpy(regs[i].w,"0");
	i++;
	strcpy(regs[i].name,"ESP");
	strcpy(regs[i].w,"2");
	i++;
	strcpy(regs[i].name,"SP");
	strcpy(regs[i].w,"1");
	i++;
	strcpy(regs[i].name,"AH");
	strcpy(regs[i].w,"0");
	i++;
	strcpy(regs[i].name,"EBP");
	strcpy(regs[i].w,"2");
	i++;
	strcpy(regs[i].name,"ESI");
	strcpy(regs[i].w,"2");
	i++;
	strcpy(regs[i].name,"EDI");
	strcpy(regs[i].w,"2");
	i++;
	strcpy(regs[i].name,"CH");
	strcpy(regs[i].w,"0");
	i++;
	strcpy(regs[i].name,"BP");
	strcpy(regs[i].w,"1");
	i++;
	
	strcpy(regs[i].name,"DH");
	strcpy(regs[i].w,"0");
	i++;
	strcpy(regs[i].name,"SI");
	strcpy(regs[i].w,"1");
	i++;
	
	strcpy(regs[i].name,"BH");
	strcpy(regs[i].w,"0");
	i++;
	strcpy(regs[i].name,"DI");
	strcpy(regs[i].w,"1");
	i++;
	
	strcpy(regs[i].name,"ES");
	strcpy(regs[i].w,"1");
	i++;
	strcpy(regs[i].name,"CS");
	strcpy(regs[i].w,"1");
	i++;
	strcpy(regs[i].name,"SS");
	strcpy(regs[i].w,"1");
	i++;
	strcpy(regs[i].name,"DS");
	strcpy(regs[i].w,"1");
	i++;
	strcpy(regs[i].name,"FS");
	strcpy(regs[i].w,"1");
	i++;
	strcpy(regs[i].name,"GS");
	strcpy(regs[i].w,"1");
	i++;
	total_count=i;
}

