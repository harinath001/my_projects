#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include "syspro_move.h"
#include "machine_directives.h"
#include "psudo_ops.h"
#include "sub.h"
#include "decide.h"
typedef struct node_type
{
	char SYMBOL[30];
	char COUNTER[20];
}NODE;
int mode;
int status;
int count;
int L;
int symbol_count;
int und_count;
char counter[50];
char symbol[50];
NODE nd[50];
NODE und[20];
FILE* inst,*res,*symtab;
void tohex(char* s,int num)
{
	int i=0,count;
	int temp;
	
	while(num>0)
	{
		temp=num%16;
		if(temp>9)
		{
			s[i]=temp-10+'A';
		}
		else
		{
			s[i]=temp+'0';
		}
		i++;
		num=num/16;
	}
	while(i<16)
	{
		s[i]='0';
		i++;
	}
	s[16]='\0';
	//strrev(s);
}


void increment_counter(int k)
{
	int value;
	int i,j;
	i=0;
	value=0;
	while(counter[i]!='\0')
	{
		j=counter[i]-'A';
		if(j>=0)
		{
			j=j+10;
			value=value*16+j;
		}
		else
		{
			j=counter[i]-'0';
			value=value*16+j;
		}
		i++;
	}
	value=value+k;
	//printf("the new value is %d ",value);
	strcpy(counter,"");
	i=0;
	while(value>0)
	{
		j=value%16;
		if(j<=9)
		{
			counter[i]=j+'0';
			i++;
		}
		else
		{
			j=j-10;
			//printf("j is %d\n",j);
			counter[i]=j+'A';
			i++;
		}
		value=value/16;
	}
	counter[i]='\0';
	j=strlen(counter);
	if(j<4)
	{
		for(i=0;i<4-j;i++)
		{
			strcat(counter,"0");
		}
	}
	strrev(counter);
	//printf("-- %s\n",counter);
}

int count_instruction_length(char* instruction)
{
	int length=0;
	while(instruction[length]!='\0')
	{
		if(instruction[length]==' '||instruction[length]=='\t'||instruction[length]=='\n')
		{
			
		}
		else
		{
			length++;
		}
		
	}
	if(length==0||length%2!=0)
	{
		printf("LENGTH OF MACHINE CODE CANNOT BE CALCULATED\n");
		return (length+1)/2;
	}
	else
	{
		return length/2;
	}
}

int check_in_symbol_table(char* s)
{
	int i;
	for(i=0;i<symbol_count;i++)
	{
		if(strcmp(s,nd[i].SYMBOL)==0)
		{
			
			return i;
		}
	}
	return -1;
}



int main()
{
	char instruction[50],result[50];
	mode=decide();
	if(mode==1)
	{
		printf("MORE INSTRUCTIONS ARE 16 BIT\n");
		getch();
	}
	else
	{
		printf("MORE INSTRUCTIONS ARE 32 BIT\n");
		getch();
	}
	symbol_count=0;
	und_count=0;
	int length,i,j,k;
	inst=fopen("code.txt","r");
	if(inst!=NULL)
	{
		res=fopen("pass1.txt","w");
		symtab=fopen("symbol_table.txt","w");
		fclose(symtab);
		symtab=fopen("symbol_table.txt","r+");
		count=0;
		while(fgets(instruction,1000,inst)!=NULL)
		{
			//printf("the instruction read from file is %s\n",instruction);
			length=strlen(instruction);
			if(length>0)
			{
				if(instruction[length-1]=='\n')
				{
					instruction[length-1]='\0';
				}
				length--;
				if(length>0)
				{
					status=check_machine_directives(instruction);
				//	printf("the status of checking in machine directives is %d\n");
					if(status==1||strcmp(instruction,".DATA")==0||strcmp(instruction,".CODE")==0)
					{
						if(strstr(instruction,".DATA")!=NULL)
						{
							fputs("4000 0000",res);
							count=0;
							strcpy(counter,"0000");
						}
						else if(strstr(instruction,".CODE")!=NULL)
						{
							fputs("\n",res);
							fputs("5000 0000",res);
							count=0;
							strcpy(counter,"0000");
						}
						else
						{
							
						}
					}
					else if((status=check_psudo_ops(instruction))&&status!=-1)//search for psudoops
					{
						
						if(status==0)
						{
							printf("END INSTRUCTION CAME SO STOPPING!!!!!\n");
							break;//because "END" came in the instruction
						}
						if(status==10)
						{
						
							//the psuod op found is EQU
							/*char temp[30];
							strcpy(temp,"");
							strcpy(temp,counter);
							strcat*/
							char s1[10],s2[10];
							i=0;
							while(instruction[i]!=' ')
							{
								s1[i]=instruction[i];
								i++;
							}
							s1[i]='\0';
							while(instruction[i]==' ')
							{
								i++;
							}
							if(strncmp(instruction+i,"EQU",3)==0)
							{
								i=i+3;
								while(instruction[i]==' ')
								{
									i++;
								}
								j=0;
								while(instruction[i]!='\0')
								{
									s2[j]=instruction[i];
									i++;
									j++;
								}
								s2[j]='\0';
								//printf("%s is going to be written in symtab\n");
								//getch();
								//fputs(counter,symtab);
								//fputs(" ",symtab);
								fputs(s1,symtab);
								fputs(" ",symtab);
								fputs(s2,symtab);
								fputs("\n",symtab);
								strcpy(nd[symbol_count].SYMBOL,s1);
								strcpy(nd[symbol_count].COUNTER,s2);
								symbol_count++;
								
							}
							
							
						}
						else if(status>=1 && status<=8)
						{
							printf("BYTE PTR , WORD PTR , ..... etc comes in immediate addressing mode....\n");
							printf("SO THIS CASE IS NOT SEEN\n");
						}
						else if(status>=11 && status<=18)
						{
							if(strstr(instruction,"DUP")!=NULL)
							{
								//printf("DUP IS IN INSTRUCTION\n");
								//getch();
								i=0;
								while(instruction[i]!=' ')
								{
								
									i++;
								}
								strncpy(symbol,instruction,i);
								symbol[i]='\0';
								
								
								if(strcmp(symbol,"DB")!=0&&strcmp(symbol,"DW")!=0&&strcmp(symbol,"DD")!=0&&strcmp(symbol,"DQ")!=0)
								{
								fputs(symbol,symtab);	
								fputs(" ",symtab);
								fputs(counter,symtab);
								fputs("\n",symtab);
								
								strcpy(nd[symbol_count].SYMBOL,symbol);
								strcpy(nd[symbol_count].COUNTER,counter);
								symbol_count++;
								
								
								while(instruction[i]==' ')
								{
									i++;
								}
								while(instruction[i]!=' ')
								{
									i++;
								}
								}
								
								
								
								while(instruction[i]==' ')
								{
									i++;	
								}
							//printf("came out of loops\n");
							//getch();
							
							
								int temp=0;
								while(instruction[i]!=' ')
								{
									temp=temp*10+instruction[i]-'0';
									i++;
								}
							//	printf("%d elements are intialised as array\n",temp);
								
								
								
								count=(status%10)*temp;
								
								while(count>0)
								{
									for(i=0;i<4;i++)
									{
										fputs(" 00",res);
									}
									fputs("\n",res);
									increment_counter(4);
									fputs("     ",res);
									fputs(counter,res);
									count=count-4;
								}
								
								
							}
							else
							{
							//	printf("this is not a dup instruction\n");
							//	getch();
								strcpy(symbol,"");
								i=0;
							
								while(instruction[i]!=' ')
								{
								
									i++;
								}
								
								strncpy(symbol,instruction,i);
								symbol[i]='\0';
								//printf("the symbol used in non dup instruction is %s\n",symbol);
							//	getch();
								
								if(strcmp(symbol,"DB")!=0&&strcmp(symbol,"DW")!=0&&strcmp(symbol,"DD")!=0&&strcmp(symbol,"DQ")!=0)
								{
									
								fputs(symbol,symtab);
								fputs(" ",symtab);
								fputs(counter,symtab);
								fputs("\n",symtab);
								
								strcpy(nd[symbol_count].SYMBOL,symbol);
								strcpy(nd[symbol_count].COUNTER,counter);
								symbol_count++;
								
								
								while(instruction[i]==' ')
								{
									i++;
								}
								while(instruction[i]!=' ')
								{
									i++;
								}
								}
								
								
								
								
								
								while(instruction[i]==' ')
								{
									i++;	
								}
								
							//	printf("the remaining instruction is %s\n",instruction+i);
							//	printf("the remaining instruction length is %d\n",strlen(instruction+i));
							//	getch();
								int temp=0;
								
								while(instruction[i]!=' '&&instruction[i]!='\0')
								{
									if(instruction[i]=='?')
									{
										temp=0;
										break;
									}
									temp=temp*10+instruction[i]-'0';
									i++;
								}
								char cc[50];
								
								count=status%10;
								//printf("\n--------the temp is %d\n",temp);	
							//	getch();
								tohex(symbol,temp);
								//strrev(symbol);
							//	printf("----------------the symbol is %s\n",symbol);
						
								//strncpy(cc,symbol,2*count);
								j=0;
								for(i=2*count-1;i>=0;i--)
								{
									cc[j]=symbol[i];
									j++;
									if((i)%2==0)
									{
										cc[j]=' ';
										j++;
									}
								}
								cc[j]='\0';
								//printf("-----------------the cc string is %s\n",cc);
								//getch();
								//strrev(cc);
							//	printf("after reversing the string cc is %s\n",cc);
							
									fputs(" ",res);
								
									fputs(cc,res);
									fputs("\n",res);
								increment_counter(count);
								fputs("     ",res);
								fputs(counter,res);	
							}
						}
						//L=calculate_length_of_datafield(instruction,symbol,status);//this function gives length of data field and give symbol if any symbol is there
					}
					else if(strstr(instruction,"MOV ")!=NULL)//instruction came from code section
					{
						char ins2[50];
						i=0;
						while(instruction[i]==' '||instruction[i]=='\t')
						{
							
							i++;
						}
						j=0;
						while(instruction[i]!='\0')
						{
							
							if(instruction[i]!='\n')
							{
								ins2[j]=instruction[i];
								j++;
							}
							i++;	
						}
						ins2[j]='\0';
						
					
						printf("PRINTING THE INSTRUCTION BEFORE SENDING\n");
						printf("%s and mode is %d\n",ins2,16*mode);
						getch();
						Main(ins2,result,mode);
						count=0;
						i=0;
						while(result[i]!='\0')
						{
							if(result[i]!=' ')
							{
								count++;
							}
							i++;
						}
						increment_counter(count/2);
						fputs(" ",res);
						fputs(result,res);
						fputs("\n",res);
						fputs("     ",res);
						fputs(counter,res);
						
						//fputs("\t \t",res);
						//fputs(result,res);
					//	fputs("\n",res);
					}
					else if(strstr(instruction,"JZ ")!=NULL)
					{
					//	printf("JZ INSTRUCTION IS FOUND\n");
						
						i=0;
						while(instruction[i]!=' ')
						{
							i++;
						}
						while(instruction[i]==' ')i++;
						j=0;
						while(instruction[i]!='\0')
						{
							if(instruction[i]!='\n')
							{
								symbol[j]=instruction[i];
								j++;
							}
							
							i++;
						}
						symbol[j]='\0';
						i=check_in_symbol_table(symbol);
						//printf("the symbol that is going to check in symbol table is %s\n",symbol);
					//	getch();
					///	printf("the fifth symbol in symbol table is %s\n",nd[4].SYMBOL);
					//	printf("the symbol_count is %d and i=%d\n",symbol_count,i);
					//	getch();
						if(i==-1)
						{
							fputs(" ",res);
							fputs("74 ",res);
							fputs("???????? ",res);
							fputs(symbol,res);
							fputs("\n",res);
							increment_counter(5);
							strcpy(und[und_count].SYMBOL,symbol);
							strcpy(und[und_count].COUNTER,counter);
							und_count++;
							fputs("     ",res);
							fputs(counter,res);
						}
						else
						{
							fputs(" ",res);
							fputs("74 ",res);
							fputs("FFFF",res);
							increment_counter(4);
							substraction(nd[i].COUNTER,counter,symbol);
							
							fputs(symbol,res);
							fputs("\n",res);
							fputs("     ",res);
							fputs(counter,res);	
						}
					}
					else
					{
						int length=strlen(instruction);
						if(instruction[length-1]==':')
						{
							instruction[length-1]='\0';
						}
						fputs(instruction,symtab);
						fputs(" ",symtab);
						fputs(counter,symtab);
						fputs("\n",symtab);
						strcpy(nd[symbol_count].SYMBOL,instruction);
						strcpy(nd[symbol_count].COUNTER,counter);
						symbol_count++;
					}	
				}
				else
				{
					
				}
			}
			
			
		}
		fclose(inst);
		fclose(res);
		fclose(symtab);
		system("cls");
		printf("PASS 1 IS COMPLETED...........\n");
		getch();
		system("cls");
		printf("\t \t \t PASS 2 STARTED\n");
		FILE* pass2;
		res=fopen("pass1.txt","r");
		pass2=fopen("pass2.txt","w");
		if(res==NULL)
		{
			printf("pass1 file is missing\n");
		}
		char new_ins[30];
		while(fgets(instruction,1000,res)!=NULL)
		{
			if(strstr(instruction,"???")!=NULL)
			{
				
				i=0;
				while(instruction[i]==' '||instruction[i]=='\t')
				{
					i++;
				}
				//strcpy(new_ins,instruction+i);
				strcpy(counter,"");
				j=0;
				while(instruction[i]!=' ')
				{
					counter[j]=instruction[i];
					i++;
					j++;
				}
				counter[j]='\0';
				
				//printf("this counter is %s\n",counter);
				increment_counter(5);
			//	printf("AFTER INCREMENTING THE COUNTER VALUE IS %s\n",counter);
				while(instruction[i]==' ')
				{
					i++;
					//printf("loop1\n");
				}
				while(instruction[i]!=' ')
				{
					i++;
					//printf("loop2\n");
				}
				while(instruction[i]==' ')
				{
					i++;
				//	printf("loop3\n");
				}
				
				
				strncpy(new_ins,instruction,i);
				new_ins[i]='\0';
				//printf("the new instruction is %s\n",new_ins);
				
				while(instruction[i]==' ')
				{
					i++;
					//printf("loop4\n");
				}
				strcpy(symbol,"");
				j=0;
				while(instruction[i]!=' ')
				{
					i++;
				}
				while(instruction[i]==' ')
				{
					i++;
				}
				while(instruction[i]!=' '&&instruction[i]!='\0')
				{
					symbol[j]=instruction[i];
					j++;
					i++;
					//printf("loop5\n");
				}
				symbol[j-1]='\0';
				//printf("THE SYMBOL TO SEARCH IS %s\n",symbol);
				i=check_in_symbol_table(symbol);
				if(i==-1)
				{
					printf("ERROR SYMBOL EVEN AFTER 1ST PASS NOT RECOGNISED\n");
					printf("AND THE SYMBOL IS %s\n",symbol);
				}
				else
				{
					strcpy(symbol,"");
					//printf("SUBSTRACTING %s FROM %s\n",nd[i].COUNTER,counter);
					substraction(nd[i].COUNTER,counter,symbol);
					//printf("the substraction resulted into %s\n",symbol);
					//getch();
				}
				fputs(new_ins,pass2);
				fputs(" ",pass2);
				fputs("0000",pass2);
				fputs(symbol,pass2);
				fputs("\n",pass2);
				
				
			}
			else
			{
				fputs(instruction,pass2);
				//fputs("\n",pass2);
			}
		}
		fclose(res);
		fclose(pass2);
	}
	else
	{
		printf("THERE IS NO FILE WHICH CONTAIN THE CODE\n");
	}
	return 0;
}
