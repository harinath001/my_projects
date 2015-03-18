#include<stdio.h>
#include<math.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include"syspro_move.h"
#define code_mode reg_mode
typedef struct reg_tag
{
	char code[5];
	char w[2];
	char name[5];
}reg;
typedef struct mem_tag
{
	char code[5];
	char name[10];
	char mode[3];
}r_m;
char opcode[10];
char arg1[15] ;
char arg2[15];
char args[20];
int d_bit;
int w_bit;
int mem_mode;
//char s1[35];
//char s2[20];
int mode;
int reg_prefix=0;
int mem_prefix=0;
int status;
int reg_count=30;
int mem_count=15;
reg regs[30];
r_m mems[15];
char disp[10];
int regis;
int IMMEDIATE=0;
int DIRECT=0;
void make_table_for_reg();
void make_table_for_mem();
int code_mode;
void printing()
{
	printf("this is printing\n");
}
void prints(int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf(" ");
	}
}
void printt(int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("\t");
	}
}
int is_num_or_not(char* c,int length)
{
	int i,num_length,num;
	char new_s[16];
	strncpy(new_s,c,length);
	for(i=0;i<length;i++)
	{
		if(c[i]=='0')
		{
			if(i==length-1)
			{
				return 1;
			}
		}
		else
		{
			break;
		}
	}
	num=atoi(new_s);
	i =0;
	while(num>0)
	{
		i++;
		num=num/10;
	}
	if(i==length)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	
}

int split(char* arg)
{
	int i;
	i=0;
	//printf("CHECK HERE : the arguments came is %s\n",arg);
	//getch();
	while(arg[i]!='\0')
	{
		if(arg[i]==',')
		{
			strncpy(arg1,arg,i);
			arg1[i]='\0';
			strcpy(arg2,arg+i+1);
			//printf("the two arguments are %s , %s\n",arg1,arg2);
			return 1;
		}
		i++;
	}
	return 0;
}
int check_reg_or_not(char*regi)
{
	int i;

	for(i=0;i<reg_count;i++)
	{
		if(stricmp(regi,regs[i].name)==0)
		{
			
			return i;
		}
	}
	return -1;
}
void set_d_bit(char*s1)
{
	//int length=strlen(s1);
	
	int i=check_reg_or_not(arg1);
	if(i>-1)
	{
		strcat(s1,"1");
		d_bit=1;
		
	}
	else
	{
		//s1[length]=0-'0';
	//	s1[length+1]='\0';
	    strcat(s1,"0");
		d_bit=0;
	}
}
void set_w_bit(char*s1)
{
	int i=check_reg_or_not(arg1);
	if(i>-1)
	{
		if(stricmp(arg1,"ES")==0||stricmp(arg1,"CS")==0||stricmp(arg1,"SS")==0||stricmp(arg1,"DS")==0||stricmp(arg1,"FS")==0||stricmp(arg1,"GS")==0)
			{
				s1[5]='1';
				//printf("THIS CONTAINS 'SEGMENT' REGISTERS SO MACHINE CODE FOR OPCODE IS 100011\n");
				//getch();
			}
		if(stricmp(arg1,"AL")==0||stricmp(arg1,"CL")==0||stricmp(arg1,"DL")==0||stricmp(arg1,"BL")==0||stricmp(arg1,"AH")==0||stricmp(arg1,"CH")==0||stricmp(arg1,"DH")==0||stricmp(arg1,"BH")==0)
		{
			w_bit=0;
			strcat(s1,"0");
		}
		else
		{
			w_bit=1;
			strcat(s1,"1");
		}
	}
	else
	{
		if(stricmp(arg2,"ES")==0||stricmp(arg2,"CS")==0||stricmp(arg2,"SS")==0||stricmp(arg2,"DS")==0||stricmp(arg2,"FS")==0||stricmp(arg2,"GS")==0)
			{
				s1[5]='1';
				//printf("THIS CONTAINS 'SEGMENT' REGISTERS SO MACHINE CODE FOR OPCODE IS 100011\n");
				//getch();
			}
		if(stricmp(arg2,"AL")==0||stricmp(arg2,"CL")==0||stricmp(arg2,"DL")==0||stricmp(arg2,"BL")==0||stricmp(arg2,"AH")==0||stricmp(arg2,"CH")==0||stricmp(arg2,"DH")==0||stricmp(arg2,"BH")==0)
		{
			w_bit=0;
			strcat(s1,"0");
		}
		else
		{
			w_bit=1;
			strcat(s1,"1");
		}
	}
	//printf("THE W BIT IS %d\n",w_bit);
}
int displacement(char* mem)
{
	
	int i,j;
	i=0;
	while(mem[i]!='[')
	{
		i++;
	}
	j=i;
	char new_mem[20];
	strcpy(new_mem,mem+i);
	for(i=0;i<mem_count;i++)
	{
		if(stricmp(mems[i].name,new_mem)==0)
		{
			if(stricmp("[BP]",new_mem)==0||stricmp("[EBP]",new_mem)==0)
			{
				strcpy(disp,"00");
				return 2;
		
			}
		
			return -1;
		}
	}
	
	i=0;
	j=-1;
	
	while(new_mem[i]!='\0')
	{
		if(new_mem[i]=='+')
		{
			j=i;
		}
		i++;
	}
	if(j==-1)
	{
		int length=strlen(mem);
		if(mem[0]!='['&&mem[length-1]==']')
		{
			printf("THIS CASE IS NOT SEEN\n");
			//getch();
			status=-1;
			return 10;
		}
		else if(mem[0]!='['&&mem[length-1]!=']')
		{
			printf("THIS IS IMMMEDIATE ADDRESSSING MODE IT IS NOT ALLOWED IN THIS PROGRAM\n");
			IMMEDIATE=1;
			
			return 10;
		}
		else if(mem[0]=='['&&mem[length-1]==']')
		{
			
			DIRECT=1;
			if(mem[length-2]=='H'||mem[length-2]=='h')
			{
				strncpy(disp,mem+1,length-3);
				if(is_num_or_not(disp,strlen(disp))==0)
				{
					printf("YOUR INSTRUCTION IS WRONG PLEASE CHECK\n");
					status=-1;
					return -1;
				}
				///printf("THIS IS DIRECT ADDRESSING MODE\n");
				return -1;
			}
			else
			{
				strncpy(disp,mem+1,length-2);
				if(is_num_or_not(disp,strlen(disp))==0)
				{
					printf("YOUR INSTRUCTION IS WRONG PLEASE CHECK\n");
					status=-1;
					return -1;
				}
				//printf("THIS IS DIRECT ADDRESSING MODE\n");
				return -1;
			}
			
		}
		else
		{
			printf("THIS CASE IS NOT EXPECTED\n");
			status=-1;
			getch();
			return 10;
		}
		
	}
	int count=0;
	j++;
	i=j;
	
	while(new_mem[j]!='H'&&new_mem[j]!='h'&&new_mem[j]!=']')
	{
		if(new_mem[j]=='\0')
		{
			printf("\nERROR WHILE CALCULATING DISPLACEMENT\nPLASE CHECK THE BRACKETS AND %d\n",count);
			status=-1;
			strcpy(disp,"");
			return -1;
		}
		//printf("%c",new_mem[j]);
		j++;
		count++;
	}
	strncpy(disp,new_mem+i,count);
	return count;
	//return strlen();
	
	
}
void set_mod(char*s1)
{
	int i=check_reg_or_not(arg1);
	int j=check_reg_or_not(arg2);
	char *temp;
	
	if(i>-1&&j>-1)
	{
		//printf("MOD IS 11\n");
		strcat(s1,"11");
	}
	else
	{
		if(i>-1)
		{
			temp=arg2;
		}
		else
		{
			temp=arg1;
		
		}
		if(displacement(temp)<0)
			{
				if(DIRECT==1&&mode==2)
				{
					//printf("MOD IS 01\n");
					strcat(s1,"01");
				}
				else
				{
				//	printf("MOD IS 00\n");
				strcat(s1,"00");
				}
				
			}
			else
			{
				int z=displacement(temp);
				if(z==2||z==1)
				{
				//	printf("MOD IS 01 AND DISPLACEMENT IS  %s\n",disp);
					strcat(s1,"01");
				}
				else if(z<=4&&z>2)
				{
					//printf("MOD IS 10 AND DISPLACEMENT IS  %s\n",disp);
					strcat(s1,"10");
				}
				else
				{
					printf("YOUR DISPLACEMENT IS WRONG\n");
					status=-1;
				}
			}
		
	}
}
void set_reg(char*s1)
{
	
	int i=check_reg_or_not(arg1);
	int j=check_reg_or_not(arg2);

		if(i>-1)
		{
			
		//	printf("THE REGISTER CODE IS %s\n",regs[i].code);
			strcat(s1,regs[i].code);
			regis=1;
			reg_mode=atoi(regs[i].w);
		//	printf("THE REGISTER MODE IS %d\n",reg_mode);
			
		}
		else if(j>-1)
		{
		//	printf("THE REGISTER CODE IS %s\n",regs[j].code);
			strcat(s1,regs[j].code);
			reg_mode=atoi(regs[j].w);
		//	printf("THE REGISTER MODE IS %d\n",reg_mode);
			
			regis=2;
		}
		else
		{
		
			printf("NONE OF THE OPERANDS ARE REGISTERS PLEASE CHECK\nAT LEAST ONE OPERAND SHOULD BE A REGISTER\n");
			status=-1;
			strcat(s1,"000");
			regis=0;
			code_mode=0;
		}
		
	
}
void set_rm(char* s1)
{
	int i=0;
	if(DIRECT>0)
	{
		if(mode==0||mode==1)
		{
			strcat(s1,"110");
		//	printf("the code for the memory/register bits is 110\n");
			mem_mode=mode;
		//	printf("memory mode is %d\n",mem_mode);
		}
		else
		{
			strcat(s1,"101");
		//	printf("the code for the memory/register bits is 101\n");
			mem_mode=mode;
		//	printf("memory mode is %d\n",mem_mode);
		}
		
		return ;
	}
	char* temp;
	if(regis==1)
	{
		temp=arg2;
	}
	else if(regis==2)
	{
		temp=arg1;
	}
	else
	{
		printf("memory/register bits are not set because of some error\n");
		return ;
	}
		if(strncmp(s1+8,"11",2)==0)
	{
		int reg_mode2;
		for(i=0;i<reg_count;i++)
		{
			if(stricmp(temp,regs[i].name)==0)
			{
			//	printf("the code for the memory/register bits is %s\n",regs[i].code);
			//	printf("BOTH ARE REGISTERS\n");
				reg_mode2=atoi(regs[i].w);
				mem_mode=reg_mode2;//because both are registers 
				//printf("THE MEMORY MODE IS %d\n",mem_mode);
			//	getch();
				strcat(s1,regs[i].code);
				if(reg_mode2!=reg_mode)
				{
					printf("YOUR INSTRUCTION IS NOT VALID INSTRUCTION,DATA SIZE IS NOT MATCHING\n");
					status=-1;
				    getch();
				}
				return ;
			}
		}
	}
	else if(strncmp(s1+8,"01",2)==0||strncmp(s1+8,"10",2)==0)
	{
		char str[13];
		i=0;
		while(temp[i]!='[')
		{
			i++;
		}
		strcpy(str,temp+i);
		int count=0;
		i=0;
		while(str[i]!='\0')
		{
			if(str[i]=='+')
			{
				count++;
			}
			i++;
		}
		int k=3;////// 3 or 6
		if(strlen(disp)>=1&&count>0)
		{
			k=3*count;
		}
		else
		{
			if(count==2)
			{
				printf("there is no displacement still your instruction contain 2 '+'\n");
				status=-1;
				getch();
				return ;
			}
			else
			{
				k=3+3*count;
			}
			
		}
		for(i=0;i<mem_count;i++)
		{
			if(strnicmp(str,mems[i].name,k)==0&&strlen(mems[i].name)==k+1)
			{
				strcat(s1,mems[i].code);
				mem_mode=atoi(mems[i].mode);
			//	printf("THE MEMORY MODE IS %d\n",mem_mode);
				
				//printf("the code for the memory/register bits is %s\n",mems[i].code);
				return ;
			}
		}
		printf("THIS TYPE OF INSTRUCTION IS SEEN ONLY IN 32 BIT MODE\n");
		if(mode!=2)
		{
			printf("YOUR MODE DOES NOT SUIT THIS INSTRUCTION TRY 32 BIT MODE\n");
			return ;
		}
		///////////////////////////////////////////////////////////////see here
		k=3;
		//printf("the string is %s\n",str);
		for(i=0;i<reg_count;i++)
		{
			if(strnicmp(str+1,regs[i].name,k)==0)
			{
				strcat(s1,regs[i].code);
				mem_mode=2;
			//	printf("THE MEMORY MODE IS %d\n",mem_mode);
				
			//	printf("the code for the memory/register bits is %s\n",regs[i].code);
				return ;
			}
		}
		printf("unexpected error in knowing memory bits\n");
		getch();
		
	}
	for(i=0;i<mem_count;i++)
	{
		if(stricmp(temp,mems[i].name)==0)
		{
		//	printf("the code for the memory/register bits is %s\n",mems[i].code);
			mem_mode=atoi(mems[i].mode);
			//printf("THE MEMORY MODE IS %d\n",mem_mode);
			
			strcat(s1,mems[i].code);
			return ;
		}
	}
}
int opcode_check(char* ocode)
{
	if(stricmp(ocode,"MOV")==0)
	{
		return 1;
	}
	return 0;
}
void convert_opcode(char* ocode,char* s1)
{
	if(stricmp(ocode,"MOV")==0)
	{
		
		strcpy(s1,"100010");
	}
}
int str_to_code(char*s1,char*s2)
{
	int length=strlen(s1),n;
	if(length%4!=0)
	{
		printf("ERROR OCCURED WHILE CONVERTING BINARY BITS TO STRING\n");
		s2[0]=='\0';
		return -1;
	}
	n=length/4;
	
	int i,j,sum;
	for(i=0;i<n;i++)
	{
		sum=0;
		for(j=0;j<4;j++)
		{
			if(s1[4*i+j]=='1')
			{
				sum=sum+pow(2,3-j);
			}
		}
		if(sum<=9)
		{
			s2[i]=sum+'0';
		}
		else
		{
			sum=sum-10;
			s2[i]=sum+'A';
		}
	}
	s2[n]='\0';

	return n;
}
void print_displacement(char* result)
{
	int i,j,k,count=0;
	int length=strlen(disp);
	char temp[10];
	strcpy(temp,"");
	i=length-2;
	while(i>=0)
	{
		j=i;
		k=2;
		while(k--)
		{
			//printf("%c",disp[j]);
			temp[count]=disp[j];
			count++;
			j++;
		}
		i=i-2;
	}
	if(length%2!=0)
	{
		//printf("%c",disp[0]);
		temp[count]=disp[j];
			count++;
	}
	temp[count]='\0';
	strcat(result,temp);
}
//void Main();
/*int main()
{
	Main();
	return 0;
}*/
void Main(char* instruction,char*result,int MODE)
{
	strcpy(result,"error");
	//printf("the instruction came is %s\n",instruction);
	//getch();
	char s1[64],s2[16];
	int i,j;
	make_table_for_reg();
	make_table_for_mem();
	//printf("enter how many test cases you are giving\n");
//	scanf("%d",&t);

	
	
		/*system("cls");
		int x=55;
		prints(x);
		printf("------------------------\n");
		prints(x);
		printf("| NAME : HARINATH KANCHU\n");
		prints(x);
		printf("|\n");
		prints(x);
		printf("| ROLL : 12BT04CSE039\n");
		prints(x);
		printf("------------------------\n");
		printf("\n");
		//return 0;
		
		printf("PLEASE SELECT THE MODE OF THE PROCESSSOR FIRST\n");
		
		scanf("%d",&status);
		if(status==16)
		{
			mode=1;
		}
		else
		{
			mode=2;
		}
		printf("GIVE YOUR INSTRUCTION\n");*/
		DIRECT=0;
		IMMEDIATE=0;
		strcpy(disp,"");
		mode=MODE;
		i=0;
		while(instruction[i]!=' ')
		{
			i++;
		}
		strncpy(opcode,instruction,i);
	//	printf("opcode is %s\n",opcode);
		
		i++;
		strcpy(args,instruction+i);
		//scanf("%s",opcode);
	//	printf("arguments of instuction are %s\n",args);
		status=opcode_check(opcode);
		if(status==1)
		{
			convert_opcode(opcode,s1);
		//	printf("your opcode is correct\n");
		//	scanf("%s",args);
		strcpy(arg1,"");
		strcpy(arg2,"");
			status=split(args);
			if(status==1)
			{
				set_d_bit(s1);
			//	printf("the d bit is %d\n",d_bit);
			//	getch();
				//return 0;
				set_w_bit(s1);
			//	getch();
				set_mod(s1);
			///	getch();
				set_reg(s1);
			//	getch();
				set_rm(s1);
			//	getch();
			//	printf("the final string is %s\n",s1);
				if(status!=-1)
				{
				//	printf("it entered here\n");
					status=str_to_code(s1,s2);
				}
				
				if(status==-1)
				{
					//printf("error in converting binary string to hex code\n");
					printf("ERROR AND RETURNED STATUS -1\n");
				}
				else if(stricmp(arg1,"CS")!=0)
				{
				//	system("cls");
					
				//	printf("\n\n\nTHE  FINAL HEX CODE IS :\n\n");
					strcpy(result,"");
					if(reg_mode!=0&&mem_mode!=mode)
					{
					//	printf("67 ");
						strcat(result,"67 ");
						
					}
					if(reg_mode!=0&&(reg_mode!=mode||mem_mode!=mode))
					{
						//printf("66 ");
						strcat(result,"66 ");
					}
					//printf("%s ",s2);
					strcat(result,s2);
					print_displacement(result);
					//printf("H\n");
					strcat(result,"H");
					system("cls");
				}
				else if(stricmp(arg1,"CS")==0)
				{
					system("cls");
					printf("THIS INSTRUCTION IS MODIFYING 'CS' SO IT IS NOT DESIRABLE\n");
					getch();
				}
				///////////////////////////
			}
			else
			{
				system("cls");
				printf("ERROR CREPT IN YOUR INSTRUCTION. PLEASE CHECK\n");
				getch();
			}
		}
		else
		{
			printf("PLEASE CHECK YOUR OPCODE,THIS OPCODE IS UNAVAILABLE\n");
		}
		
	//	printf("\n \n \nENTER TO PROCEED.................\n");
	//	getch();
		return ;
	
//	return 0;
}
void make_table_for_reg()
{
	int i;
	i=0;
	strcpy(regs[i].name,"AL");
	strcpy(regs[i].w,"0");
	strcpy(regs[i].code,"000");
	i++;
	strcpy(regs[i].name,"AX");
	strcpy(regs[i].w,"1");
	strcpy(regs[i].code,"000");
	i++;
	strcpy(regs[i].name,"EAX");
	strcpy(regs[i].w,"2");
	strcpy(regs[i].code,"000");
	i++;
	strcpy(regs[i].name,"CL");
	strcpy(regs[i].w,"0");
	strcpy(regs[i].code,"001");
	i++;
	strcpy(regs[i].name,"CX");
	strcpy(regs[i].w,"1");
	strcpy(regs[i].code,"001");
	i++;
	strcpy(regs[i].name,"ECX");
	strcpy(regs[i].w,"2");
	strcpy(regs[i].code,"001");
	i++;
	strcpy(regs[i].name,"DL");
	strcpy(regs[i].w,"0");
	strcpy(regs[i].code,"010");
	i++;
	strcpy(regs[i].name,"DX");
	strcpy(regs[i].w,"1");
	strcpy(regs[i].code,"010");
	i++;
	strcpy(regs[i].name,"EDX");
	strcpy(regs[i].w,"2");
	strcpy(regs[i].code,"010");
	i++;
	strcpy(regs[i].name,"BL");
	strcpy(regs[i].w,"0");
	strcpy(regs[i].code,"011");
	i++;
	strcpy(regs[i].name,"BX");
	strcpy(regs[i].w,"1");
	strcpy(regs[i].code,"011");
	i++;
	strcpy(regs[i].name,"EBX");
	strcpy(regs[i].w,"2");
	strcpy(regs[i].code,"011");
	i++;
	strcpy(regs[i].name,"AH");
	strcpy(regs[i].w,"0");
	strcpy(regs[i].code,"100");
	i++;
	strcpy(regs[i].name,"SP");
	strcpy(regs[i].w,"1");
	strcpy(regs[i].code,"100");
	i++;
	strcpy(regs[i].name,"ESP");
	strcpy(regs[i].w,"2");
	strcpy(regs[i].code,"100");
	i++;
	strcpy(regs[i].name,"CH");
	strcpy(regs[i].w,"0");
	strcpy(regs[i].code,"101");
	i++;
	strcpy(regs[i].name,"BP");
	strcpy(regs[i].w,"1");
	strcpy(regs[i].code,"101");
	i++;
	strcpy(regs[i].name,"EBP");
	strcpy(regs[i].w,"2");
	strcpy(regs[i].code,"101");
	i++;
	strcpy(regs[i].name,"DH");
	strcpy(regs[i].w,"0");
	strcpy(regs[i].code,"110");
	i++;
	strcpy(regs[i].name,"SI");
	strcpy(regs[i].w,"1");
	strcpy(regs[i].code,"110");
	i++;
	strcpy(regs[i].name,"ESI");
	strcpy(regs[i].w,"2");
	strcpy(regs[i].code,"110");
	i++;
	strcpy(regs[i].name,"BH");
	strcpy(regs[i].w,"0");
	strcpy(regs[i].code,"111");
	i++;
	strcpy(regs[i].name,"DI");
	strcpy(regs[i].w,"1");
	strcpy(regs[i].code,"111");
	i++;
	strcpy(regs[i].name,"EDI");
	strcpy(regs[i].w,"2");
	strcpy(regs[i].code,"111");
	i++;
	strcpy(regs[i].name,"ES");
	strcpy(regs[i].w,"1");
	strcpy(regs[i].code,"000");
	i++;
	strcpy(regs[i].name,"CS");
	strcpy(regs[i].w,"1");
	strcpy(regs[i].code,"001");
	i++;
	strcpy(regs[i].name,"SS");
	strcpy(regs[i].w,"1");
	strcpy(regs[i].code,"010");
	i++;
	strcpy(regs[i].name,"DS");
	strcpy(regs[i].w,"1");
	strcpy(regs[i].code,"011");
	i++;
	strcpy(regs[i].name,"FS");
	strcpy(regs[i].w,"1");
	strcpy(regs[i].code,"100");
	i++;
	strcpy(regs[i].name,"GS");
	strcpy(regs[i].w,"1");
	strcpy(regs[i].code,"101");
}
void make_table_for_mem()
{
	int i=-1;
	i++;
	strcpy(mems[i].code,"000");
	strcpy(mems[i].name,"[BX+SI]");
	strcpy(mems[i].mode,"1");
	i++;
	strcpy(mems[i].code,"001");
	strcpy(mems[i].name,"[BX+DI]");
	strcpy(mems[i].mode,"1");
	i++;
	strcpy(mems[i].code,"010");
	strcpy(mems[i].name,"[BP+SI]");
	strcpy(mems[i].mode,"1");
	i++;
	strcpy(mems[i].code,"011");
	strcpy(mems[i].name,"[BP+DI]");
	strcpy(mems[i].mode,"1");
	i++;
	strcpy(mems[i].code,"100");
	strcpy(mems[i].name,"[SI]");
	strcpy(mems[i].mode,"1");
	i++;
	strcpy(mems[i].code,"101");
	strcpy(mems[i].name,"[DI]");
	strcpy(mems[i].mode,"16");
	i++;
	strcpy(mems[i].code,"110");
	strcpy(mems[i].name,"[BP]");
	strcpy(mems[i].mode,"1");
	i++;
	strcpy(mems[i].code,"111");
	strcpy(mems[i].name,"[BX]");
	strcpy(mems[i].mode,"1");
	//////////////////////////////////////////NOW 32 BIT TABLE
	i++;
	strcpy(mems[i].code,"000");
	strcpy(mems[i].name,"[EAX]");
	strcpy(mems[i].mode,"2");
	i++;
	strcpy(mems[i].code,"001");
	strcpy(mems[i].name,"[ECX]");
	strcpy(mems[i].mode,"2");
	i++;
	strcpy(mems[i].code,"010");
	strcpy(mems[i].name,"[EDX]");
	strcpy(mems[i].mode,"2");
	i++;
	strcpy(mems[i].code,"011");
	strcpy(mems[i].name,"[EBX]");
	strcpy(mems[i].mode,"2");
	i++;
	strcpy(mems[i].code,"101");
	strcpy(mems[i].name,"[EBP]");
	strcpy(mems[i].mode,"2");
	i++;
	strcpy(mems[i].code,"110");
	strcpy(mems[i].name,"[ESI]");
	strcpy(mems[i].mode,"2");
	i++;
	strcpy(mems[i].code,"111");
	strcpy(mems[i].name,"[EDI]");
	strcpy(mems[i].mode,"2");
}

