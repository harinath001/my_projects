#include<stdio.h>
#include<string.h>
#include "psudo_ops.h"


typedef struct node_type
{
	char name[20];
	int size;
}psudo_ops_node;

int psudo_ops_count=10;
psudo_ops_node no[10];


void load_psudo_ops_table()
{
	int i=0;
	strcpy(no[i].name,"BYTE PTR");
	no[i].size=1;
	i++;
	strcpy(no[i].name,"WORD PTR");
	no[i].size=2;
	i++;
	strcpy(no[i].name,"DWORD PTR");
	no[i].size=4;
	i++;
	strcpy(no[i].name,"QWORD PTR");
	no[i].size=8;
	i++;
	strcpy(no[i].name,"DB");
	no[i].size=11;
	i++;
	strcpy(no[i].name,"DW");
	no[i].size=12;
	i++;
	strcpy(no[i].name,"DD");
	no[i].size=14;
	i++;
	strcpy(no[i].name,"DQ");
	no[i].size=18;
	i++;
	strcpy(no[i].name,"EQU");
	no[i].size=10;
	i++;
	strcpy(no[i].name,"END");
	no[i].size=0;
	
}

int check_psudo_ops(char* instruction)
{
	load_psudo_ops_table();
	int i;
	for(i=0;i<psudo_ops_count;i++)
	{
		//printf("checking for %s\n",no[i].name);
		if(strstr(instruction,no[i].name)!=NULL)
		{
			
			return no[i].size;
		}
	}
	return -1;
}
int calculate_length_of_datafield(char * instruction,char * symbol,int status)
{
	/*char temp[10];
	//if()
	if(strncmp(instruction,"DW",2)==0||strncmp(instruction,"DD",2)==0||strncmp(instruction,"DB",2)==0||strncmp(instruction,"DQ",2)==0)
	{
		strcpy(symbol,"");
		
		
	}*/
	return -1;
}
