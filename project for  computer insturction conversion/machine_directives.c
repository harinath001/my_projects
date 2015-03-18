#include<stdio.h>
#include<string.h>
#include "machine_directives.h"

typedef struct node_type
{
	char name[10];
}node;

int num_count=2;
node no[2];

void load_tab()
{
	int i=0;
	strcpy(no[i].name,".DATA");
	i++;
	strcpy(no[i].name,".CODE");
	i++;
	
}

int check_machine_directives(char* instruction)
{
	load_tab();
	int i;
	for(i=0;i<num_count;i++)
	{
		if(strstr(instruction,no[i].name)!=NULL)
		{
			return 1;
		}
	}
	return 0;
}
