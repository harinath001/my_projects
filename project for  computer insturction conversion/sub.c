#include<stdio.h>
#include<string.h>
#include "sub.h"

void substraction(char* a,char* b,char* c)
{
	int a1[20];
	int a2[20];
	int a3[20];
	int i,j,k,temp1,temp2;
	j=0;
	
	for(i=0;i<4;i++)
	{
		if(a[i]-'A'>=0)
		{
			temp1=a[i]-'A'+10;
			
		}
		else
		{
			temp1=a[i]-'0';
		}
		if(b[i]-'A'>=0)
		{
			temp2=b[i]-'A'+10;
		}
		else
		{
			temp2=b[i]-'0';
		}
		//printf("temp1=%d temp2=%d\n",temp1,temp2);
		j=j+4;
		for(k=j-1;k>=j-4;k--)
		{
			a1[k]=temp1%2;
			temp1=temp1/2;
			a2[k]=temp2%2;
			temp2=temp2/2;
		}
	}
	for(i=0;i<16;i++)
	{
		if(a2[i]==0)
		{
			a2[i]=1;
		}
		else
		{
			a2[i]=0;
		}
	}
	//printf("the complement is \n");
	//for(i=0;i<16;i++)printf("%d ",a2[i]);
	//printf("\n");
	a2[15]=a2[15]+1;
	if(a2[15]==2)
	{
		a2[15]=0;
		temp1=1;
	}
	else
	{
		temp1=0;
	}
	for(i=14;i>=0;i--)
	{
		a2[i]=a2[i]+temp1;
		if(a2[i]==2)
		{
			temp1=1;
			a2[i]=0;
		}
		else
		{
			temp1=0;
		}
	}
//	printf("the 2's complement is\n ");
	//for(i=0;i<16;i++)printf("%d ",a2[i]);
//	printf("\n");
	temp1=0;
	for(i=15;i>=0;i--)
	{
		a3[i]=a1[i]+a2[i]+temp1;
		if(a3[i]==2)
		{
			a3[i]=0;
			temp1=1;
		}
		else if(a3[i]==3)
		{
			a3[i]=1;
			temp1=1;
		}
		else
		{
			temp1=0;
		}
		
	}
	j=0;
	int count=0;
	for(i=0;i<16;i=i+4)
	{
		temp1=4;
		temp2=0;
		for(j=i;temp1!=0;temp1--,j++)
		{
			temp2=temp2*2+a3[j];
		}
		if(temp2>=10)
		{
			c[count]=temp2-10+'A';
		}
		else
		{
			c[count]=temp2+'0';
		}
		count++;
	}
	c[4]='\0';
}

