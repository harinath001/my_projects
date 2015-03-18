#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

#define admin_password "vnit"
typedef struct node
{
	long access_number;
	char book_name[20];
	char author[20];
	long isbn_number;
	char publisher[20];
	int price;
	int copy_number;
	struct node* next;
}node_type;

typedef struct node2
{
	char password[20];
	int total_books;
	int total_books_used;
}admin_type;
typedef struct node3
{
	int total_books;
	int taken_books;
	int reserved_books;
	char branch_used[10];	
}book_type;



node_type* make_new_node(node_type* head,node_type temp);
node_type* delete(node_type* head);
int get_num_records(node_type* head);
int remove_duplicates(node_type* head);
node_type* union_of_lists(node_type* head1,node_type* head2);
node_type* intersection(node_type* head1,node_type* head2);
node_type* difference(node_type* head1,node_type* head2);
node_type* symmetric_difference(node_type* head1,node_type* head2);
int main()
{
	int flag[5],i,j,k,l,options=100;
	node_type* head1=NULL,*head2=NULL,*head3=NULL,*tempo,*tempo2;
	int max1,max2;
	node_type temp,null;
	null.access_number=1234;
	strcpy(null.author,"notmentioned");
	strcpy(null.book_name,"notmentioned");
	strcpy(null.publisher,"publisher");
	null.isbn_number=100000;
	null.copy_number=100;
	null.next=NULL;
	null.price=10;
	temp.next=NULL;
	char words[20],option[10][10],pass[20],admin_pass[20];
	FILE* fp;
	fp=fopen("list1","r");
	fscanf(fp,"%d",&max1);
	for(i=0;i<max1;i++)
	{
		fscanf(fp,"%s",temp.book_name);
		fscanf(fp,"%s",temp.author);
		fscanf(fp,"%ld",&temp.access_number);
		fscanf(fp,"%d",&temp.copy_number);
		fscanf(fp,"%ld",&temp.isbn_number);
		fscanf(fp,"%s",temp.publisher);
		fscanf(fp,"%d",&temp.price);
		head1=make_new_node(head1,temp);
	}
	fclose(fp);	
	fp=fopen("list2","r");
	fscanf(fp,"%d",&max2);
	for(i=0;i<max2;i++)
	{
		fscanf(fp,"%s",temp.book_name);
		fscanf(fp,"%s",temp.author);
		fscanf(fp,"%ld",&temp.access_number);
		fscanf(fp,"%d",&temp.copy_number);
		fscanf(fp,"%ld",&temp.isbn_number);
		fscanf(fp,"%s",temp.publisher);
		fscanf(fp,"%d",&temp.price);
		head2=make_new_node(head2,temp);
	}
	fclose(fp);	
/*	strcpy(admin_pass,admin_password);
	
	printf(" \n \n \n \n \n \n ");
	printf("****************PLEASE ENTER YOUR PASSWORD******************\n");
	scanf("%s",pass);
	while(strcmp(pass,admin_pass)!=0)
	{
		system("cls");
		printf(" \n \n \n \n \n \n ");
		printf("****************PLEASE ENTER YOUR PASSWORD******************\n");
		scanf("%s",pass);
	}
	system("cls");
	printf("*************WELCOME ADMIN**************\n"); */
	strcpy(option[0],"yes");
	while(strcmp(option[0],"yes")==0)
	{
		printf("YOUR OPTIONS : \n");
		printf("\t \t 1)INSERT DETAILS OF A BOOK INTO A LIST \n \n");
		printf("\t \t 2)DELETE A PARTICULAR BOOK FROM A LIST \n \n");
		printf("\t \t 3)GET THE NUM RECORDS \n \n");
		printf("\t \t 4)IS LIST IS EMPTY ? \n \n");
		printf("\t \t 5)REMOVE THE DUPLICATES OF THE PARTICULAR LIST \n \n");
		printf("\t \t 6)MAXIMUM NUMBER OF BOOKS WRITTEN BY A PARTICULAR AUTHOR \n \n");
		printf("\t \t 7)GIVE THE UNION OF TWO LISTS \n \n");
		printf("\t \t 8)GIVE THE INTERSECTION OF TWO LISTS \n \n");
		printf("\t \t 9)GIVE THE SET DIFFERENCE OF TWO LISTS \n \n");
		printf("\t \t 10)GIVE THE SYMMETRIC DIFFERENCE OF TWO LISTS \n \n");
		printf("\t \t 11)LOGOUT\n");
		printf("********THE PRINTING OPTIONS**************\n \n");
		printf("\t \t 12)PRINT LIST1 \n");
		printf("\t \t 13)PRINT LIST2 \n");
		printf("\t \t 14)PRINT LIST3 \n");
	//	printf("%d",strcmp("a","b"));
		scanf("%s",option[1]);
		system("cls");
		if(strcmp(option[1],"1")==0)
		{
			int number,i;
			printf("how many values you are going to give \n");
			scanf("%d",&number);
			for(i=0;i<number;i++)
			{
				system("cls");
				strcpy(option[2],"10");
				while(strcmp("1",option[2])!=0 && strcmp("2",option[2])!=0)
				{
					printf(" \nYOU HAVE THE FOLLOWING OPTIONS \n \n");
					printf("1)LIST 1 \n \n ");
					printf("2)LIST 2 \n \n");
					scanf("%s",option[2]);
				}
				
				if(strcmp(option[2],"1")==0)
				{
					node_type temperory;
					temperory=null;
				/*	printf("NOW ENTER THE FOLLOWING DETAILS \n \n ");
					printf("ENTER THE BOOK NAME WITHOUT SPACES \n");
					scanf("%s",temperory.book_name);
					printf("ENTER THE AUTHOR NAME: \n \n ");
					scanf("%s",temperory.author);*/
					printf("NOW ENTER THE FOLLOWING DETAILS \n \n ");
					printf("ENTER THE BOOK NAME WITHOUT SPACES \n");
					scanf("%s",temperory.book_name);
					printf("ENTER THE AUTHOR NAME: \n \n ");
					scanf("%s",temperory.author);
					printf("GIVE THE ACCESS NUMBER\n");
					scanf("%ld",&temperory.access_number);
					printf("GIVE THE COPY NUMBER\n");
					scanf("%d",&temperory.copy_number);
					printf("GIVE ISBN NUMBER\n");
					scanf("%d",&temperory.isbn_number);
					printf("GIVE THE PRICE OF THE BOOK\n");	
					scanf("%d",&temperory.price);
					printf("PLEASE ENTER THE PUBLLISHER OF THE BOOK:\n");
					scanf("%s",temperory.publisher);	
					head1=make_new_node(head1,temperory);
				}
				else
				{
					node_type temperory=null;
					printf("NOW ENTER THE FOLLOWING DETAILS \n \n ");
					printf("ENTER THE BOOK NAME WITHOUT SPACES \n");
					scanf("%s",temperory.book_name);
					printf("ENTER THE AUTHOR NAME: \n \n ");
					scanf("%s",temperory.author);
					printf("GIVE THE ACCESS NUMBER\n");
					scanf("%ld",&temperory.access_number);
					printf("GIVE THE COPY NUMBER\n");
					scanf("%d",&temperory.copy_number);
					printf("GIVE ISBN NUMBER\n");
					scanf("%d",&temperory.isbn_number);
					printf("GIVE THE PRICE OF THE BOOK\n");	
					scanf("%d",&temperory.price);
					printf("PLEASE ENTER THE PUBLLISHER OF THE BOOK:\n");
					scanf("%s",temperory.publisher);	
					head2=make_new_node(head2,temperory);
				}	
			}
			
		}
		if(strcmp(option[1],"2")==0)
		{
			printf("GIVE THE LIST NO. TO DELETE: \n");
			printf("1)LIST 1\n");
			printf("2)LIST 2\n");
			scanf("%s",option[2]);
			if(strcmp(option[2],"1")==0)
			{
				system("cls");
				printf("LIST 1 IS SELECTED :\n \n \n \n");
				head1=delete(head1);
			}
		else if(strcmp(option[2],"2")==0)
			{
				system("cls");
				printf("LIST 2 IS SELECTED:\n \n \n \n");
				head2=delete(head2);
			}
			else
			{
				system("cls");
				printf("YOUR LIST SELECTION IS INVALID \n \n");
				printf("PLEASE SELECT A VALID LIST \n \n");
				getch();
			}
		}
		if(strcmp(option[1],"3")==0)
		{
			printf("*********************************************************\n");
			printf("SELECT THE LIST NUMBER TO FIND NUMBER OF ITEMS IN IT\n");
			printf("*********************************************************\n");
			printf("**********\n");
			printf("**1)LIST 1**\n");
			printf("**********\n");
			printf("**2)LIST 2**\n");
			printf("*********************************************************\n");
			strcpy(option[1],"10");
			while(strcmp(option[1],"1")!=0&&strcmp(option[1],"2")!=0)
			{
				printf("SELECT A VALID OPTION \n");
				scanf("%s",option[1]);
			}
			if(strcmp(option[1],"1")==0)
			{
				int n;
				printf("PRESS ANY KEY TO CONTINUE\n");
				getch();
				system("cls");
				n=get_num_records(head1);
				printf("THE NO. OF ACTIVE RECORDS IN LIST 1 IS:%d\n",n);
				
			}
			if(strcmp(option[1],"2")==0)
			{
				{
					int n;
					printf("PRESS ANY KEY TO CONTINUE\n");
					getch();
					system("cls");
					n=get_num_records(head2);
					printf("THE NO. OF ACTIVE RECORDS IN LIST 2 IS:%d\n",n);
				
				}
			}
		}
		if(strcmp(option[1],"4")==0)
		{
			system("cls");
			printf("**************************************************\n");
			printf("\n \n \n WANT TO KNOW WHETHER A LIST IS EMPTY OR NOT \n \n \n");
			printf("***************************************************\n");
			printf("THEN CHOOSE THE LIST : \n");
			
			strcpy(option[1],"10");
			while(strcmp(option[1],"1")!=0&&strcmp(option[1],"2")!=0)
			{
				printf("PLEASE SELECT A VALID OPTION\n");
				printf("1) LIST 1 \n");
				printf("2) LIST 2 \n");
				scanf("%s",option[1]);
			}
			if(strcmp(option[1],"1")==0)
			{
				int n;
				n=get_num_records(head1);
				if(n==0)
				{
					printf("THE LIST IS EMPTY\n");
				}
				else
				{
					printf("THE LIST IS NOT EMPTY\n");
					
				}
			}
			if(strcmp(option[1],"2")==0)
			{
				int n;
				n=get_num_records(head2);
				if(n==0)
				{
					printf("THE LIST IS EMPTY\n");
				}
				else
				{
					printf("THE LIST IS NOT EMPTY\n");
					
				}
			}
		}
		if(strcmp(option[1],"5")==0)
		{
			
			
			system("cls");
			printf("**************************************************\n");
			printf("\n \n \n WANT TO KNOW REMOVE THE DUPLICATES \n \n \n");
			printf("***************************************************\n");
			printf("THEN CHOOSE THE LIST : \n");
			
			strcpy(option[1],"10");
			while(strcmp(option[1],"1")!=0&&strcmp(option[1],"2")!=0)
			{
				printf("PLEASE SELECT A VALID OPTION\n");
				printf("1) LIST 1 \n");
				printf("2) LIST 2 \n");
				scanf("%s",option[1]);
			}
			if(strcmp(option[1],"1")==0)
			{
				int n;
				if(head1!=NULL &&  head1->next!=NULL)
				{
					n=remove_duplicates(head1);
				}
				else
				{
					n=0;
				}
				
				if(n==1)
				{
					printf("***************************************\n");
					printf("SUCCESSFULLY REMOVED DUPLICATES\n");
					printf("***************************************\n");
				}
				else
				{
					printf("***************************************\n");
					printf("NO DUPLICATES FOUND IN THE LIST\n");
					printf("***************************************\n");
				}
				
			}
			if(strcmp(option[1],"2")==0)
			{
				int n;
				if(head2!=NULL &&  head2->next!=NULL)
				{
					n=remove_duplicates(head2);
				}
				else
				{
					n=0;
				}
				
				if(n==1)
				{
					printf("***************************************\n");
					printf("SUCCESSFULLY REMOVED DUPLICATES\n");
					printf("***************************************\n");
				}
				else
				{
					printf("***************************************\n");
					printf("NO DUPLICATES FOUND IN THE LIST\n");
					printf("***************************************\n");
				}
			}
			
			
		}
		if(strcmp(option[1],"6")==0)
		{
			int n;
			char author[20];
			strcpy(option[1],"10");
			printf("GIVE THE AUTHOR NAME\n \n");
			scanf("%s",author);
			printf("NOW SELECT A LIST:\n \n");
			while(strcmp(option[1],"1")!=0&&strcmp(option[1],"2")!=0)
			{
				printf("PLEASE SELECT A VALID OPTION\n \n");
				printf("1) LIST 1 \n \n");
				printf("2) LIST 2 \n \n");
				scanf("%s",option[1]);
			}
			if(strcmp(option[1],"1")==0)
			{
				if(head1==NULL)
				{
					n=0;
				}
				else
				{
					n=get_max_books(head1,author);
				}	
				if(n==0)
				{
					printf("NO BOOKS IN THE LIST IS WRITTEN BY THE GIVEN AUTHOR\n \n");
				}
				else
				{
					printf("THE MAXIMUM NUMBER OF  COPIES WRITTEN BY THE AUTHOR IN THE GIVEN LIST IS %d\n \n",n);
				}
			}
			if(strcmp(option[1],"2")==0)
			{
				if(head2==NULL)
				{
					n=0;
				}
				else
				{
					n=get_max_books(head2,author);
				}	
				if(n==0)
				{
					printf("NO BOOKS IN THE LIST IS WRITTEN BY THE GIVEN AUTHOR\n \n");
				}
				else
				{
						printf("THE MAXIMUM NUMBER OF  COPIES WRITTEN BY THE AUTHOR IN THE GIVEN LIST IS %d\n \n",n);
				}
			}
			
		}
		if(strcmp(option[1],"7")==0)
		{
			node_type* t;
			if(head3!=NULL)
			{
				while(head3!=NULL)
				{
					t=head3;
					head3=head3->next;
					free(t);
				}
			}
			printf("*************************************************\n \n \n");
			printf("*************UNION OF TWO LISTS******************\n\n\n");
			printf("*************************************************\n \n \n");
			if(head1==NULL && head2==NULL)
			{
				printf("\n \n \n NO ITEMS ARE FOUND IN THE BOTH LISTS \n");
				head3=NULL;
			}
			 if(head1==NULL && head2!=NULL)
			{
				tempo=head2;
				while(tempo!=NULL)
				{
					temp=*tempo;
					head3=make_new_node(head3,temp);
					tempo=tempo->next;
				}
			}
			if(head2==NULL && head1!=NULL)
			{
				tempo=head1;
				while(tempo!=NULL)
				{
					temp=*tempo;
					head3=make_new_node(head3,temp);
					tempo=tempo->next;
				}
			}
			if(head2!=NULL && head1!=NULL)
			{
				head3=union_of_lists(head1,head2);
			}
			t=head3;
			while(t!=NULL)
			{
				
				printf("THE BOOK NAME:%s \n",t->book_name);
				printf("THE AUTHOR NAME IS %s\n",t->author);
				printf("-------------------------------------\n");
				t=t->next;
			}
		}
		if(strcmp(option[1],"8")==0)
		{
			
			if(head3!=NULL)
			{
				node_type* t;
				while(head3!=NULL)//loop 8.1
				{
				//	printf("8.1 \n");
					t=head3;
					head3=head3->next;
					free(t);
				}
			}
			if(head1==NULL||head2==NULL)
			{
				printf("**********************************************\n\n");
				printf("********THE INTERSECTION IS A NULL SET********\n\n");
				printf("**********************************************\n\n");
			}
			else
			{
				head3=intersection(head1,head2);
				node_type* t;
				if(head3!=NULL)
				{
					t=head3;
					while(t!=NULL)
					{
						printf("THE BOOK IS: %s\n",t->book_name);
						printf("THE AUTHOR IS:%s \n",t->author);
						printf("----------------------------------\n\n");
						t=t->next;
					}
				}
				else
				
				{
					printf("*************************************************************\n\n");
					printf("********THE INTERSECTION OF THE TWO LIST IS A NULL SET*******\n\n");
					printf("*************************************************************\n\n");
				}
			}	
		}
		if(strcmp(option[1],"9")==0)
		{
			printf("***************************************************\n\n");
			printf("*********PLEASE SELECT THE LIST DIFFERENCE*********\n\n");
			printf("***************************************************\n\n");
			printf("OPTIONS:\n\n\n");
			printf("1)LIST1-LIST2 \n\n");
			printf("2)LIST2-LIST1\n\n");
			scanf("%s",option[1]);
			while(strcmp(option[1],"1")!=0&&strcmp(option[1],"2")!=0)
			{
				printf("PLEASE SELECT A VALID OPTION\n\n");
				printf("OPTIONS:\n\n\n");
				printf("1)LIST1-LIST2 \n\n");
				printf("2)LIST2-LIST1\n\n");
				scanf("%s",option[1]);
			}
			while(head3!=NULL)
				{
					
					tempo=head3;
					head3=head3->next;
					free(tempo);
				}
				
			if(strcmp(option[1],"1")==0)
			{
				if(head2==NULL)
				{
					tempo=head1;
					head3=NULL;
					while(tempo!=NULL)
					{
						temp=*tempo;
						head3=make_new_node(head3,temp);
						tempo=tempo->next;
					}
				}
		    	else if(head1==NULL)
				{
					printf("THE DIFFERENCE SET IS AN EMPTY SET\n");
				}
				else
				{
					head3=difference(head1,head2);
				}	
			}
			if(strcmp(option[1],"2")==0) 
			{
				if(head1==NULL)
				{
					tempo=head2;
					while(tempo!=NULL)
					{
						temp=*tempo;
						head3=make_new_node(head3,temp);
						tempo=tempo->next;
					}
				}
		    	else if(head2==NULL)
				{
					printf("THE DIFFERENCE SET IS AN EMPTY SET\n");
				}
				else
				{
					head3=difference(head2,head1);
				}	
			}
			
			if(head3==NULL)
			{
				printf("THE DIFFERENCE SET IS AN EMPTY SET\n");
			}
			else
			{
			
				tempo=head3;
				printf("********************************************\n\n");
				printf("******THE DIFFERENCE LIST IS AS FOLLOWS*****\n\n");
				printf("********************************************\n\n");
				while(tempo!=NULL)
				{
					printf("THE BOOK NAME IS %s \n \n",tempo->book_name);
					printf("THE AUTHOR NAME IS %s \n \n",tempo->author);
					printf("-----------------------------\n \n");
					tempo=tempo->next;
				}
			}
		}
		if(strcmp(option[1],"10")==0)
		{
			node_type* p;
			 while(head3!=NULL)
			 {
			 	p=head3;
			 	head3=head3->next;
			 	free(p);
			 }
			 if(head1==NULL&&head2==NULL)
			 {
			 	head3=NULL;
			 }
			 else if(head1==NULL && head2!=NULL)
			 {
			 	tempo=head2;
			 	while(tempo!=NULL)
			 	{
			 		temp=*tempo;
			 		head3=make_new_node(head3,temp);
			 		tempo=tempo->next;
			 	}
			 }
			 else if(head2==NULL && head1!=NULL)
			 {
			 	tempo=head1;
			 	while(tempo!=NULL)
			 	{
			 		temp=*tempo;
			 		head3=make_new_node(head3,temp);
			 		tempo=tempo->next;
			 	}
			 }
			 else 
			 {
			 	head3=symmetric_difference(head1,head2);
			 }
			 p=head3;
			 if(head3!=NULL)
			 {
			 	printf("*******************************************************\n\n");
			 	printf("******THE SYMMETRIC LIST DIFFERENCE LIST IS AS FOLLOWS******\n\n");
			 	printf("*******************************************************\n\n");
			 }
			 while(p!=NULL)
			 {
			 	printf("THE BOOK NAME IS: %s \n\n",p->book_name);
			 	printf("THE AUTHOR NAME IS %s \n\n",p->author);
			 	printf("--------------------------------\n\n");
			 	p=p->next;
			 }
		}
		if(strcmp(option[1],"11")==0)
		{
			printf("\n \n \n \n \n \t \t \t \t*****THANKYOU*****\n \n \n \n \n \n ");
			strcpy(option[0],"no");
		}
		if(strcmp(option[1],"12")==0)
		{
			tempo=head1;
			while(tempo!=NULL)
			{
				if(tempo!=NULL)
				{
					printf("the book name is %s \n",tempo->book_name);
					printf("the author name is %s \n",tempo->author);
					printf("the cost is: %d \n",tempo->price);
					printf("the isbn number is %ld \n",tempo->isbn_number);
					printf("the copy number is %d \n",tempo->copy_number);
					printf("------------------------\n");
				}
				tempo=tempo->next;
			}
		}
		if(strcmp(option[1],"13")==0)
		{
			tempo=head2;
			while(tempo!=NULL)
			{
				printf("the book name is %s \n",tempo->book_name);
					printf("the author name is %s \n",tempo->author);
					printf("the cost is: %d \n",tempo->price);
					printf("the isbn number is %ld \n",tempo->isbn_number);
					printf("the copy number is %d \n",tempo->copy_number);
					printf("------------------------\n");
					tempo=tempo->next;
			
			}
		}
		if(strcmp(option[1],"14")==0)
		{
			tempo=head3;
			while(tempo!=NULL)
			{
				printf("the book name is %s \n",tempo->book_name);
					printf("the author name is %s \n",tempo->author);
					printf("the cost is: %d \n",tempo->price);
					printf("the isbn number is %ld \n",tempo->isbn_number);
					printf("the copy number is %d \n",tempo->copy_number);
					printf("------------------------\n");
					tempo=tempo->next;
			
			}
		}
		getch();
	}
	fp=fopen("list1","w");
	
	if(fp==NULL)
	{
		printf("DATA FILE 'LIST 1' IS MISSING \n");
		printf("SO THE DATA IS NOT GOING TO SAVE \n");
		getch();
	}
	
	max1=get_num_records(head1);
	max2=get_num_records(head2);
	fprintf(fp,"%d \n",max1);
	while(head1!=NULL)
	{
		tempo=head1;
		fprintf(fp,"%s\n",head1->book_name);
		fprintf(fp,"%s\n",head1->author);
		fprintf(fp,"%ld\n",head1->access_number);
		fprintf(fp,"%d\n",head1->copy_number);
		fprintf(fp,"%ld\n",head1->isbn_number);
		fprintf(fp,"%s\n",head1->publisher);
		fprintf(fp,"%d\n",head1->price);
			
		head1=head1->next;
		free(tempo);
	}
	fclose(fp);
	
	fp=fopen("list2","w");
	fprintf(fp,"%d \n",max2);
	while(head2!=NULL)
	{
		tempo=head2;
		fprintf(fp,"%s\n",head2->book_name);
		fprintf(fp,"%s\n",head2->author);
		fprintf(fp,"%ld\n",head2->access_number);
		fprintf(fp,"%d\n",head2->copy_number);
		fprintf(fp,"%ld\n",head2->isbn_number);
		fprintf(fp,"%s\n",head2->publisher);
		fprintf(fp,"%d\n",head2->price);
				
		head2=head2->next;
		free(tempo);
	}
	fclose(fp);
	while(head3!=NULL)
	{
		tempo=head3;
		head3=head3->next;
		free(tempo);
	}
	return 0;
	
}
node_type* make_new_node(node_type* head,node_type temp)
{
	node_type* lptr,*p,*prev;
	char option[5];
	
			
	if(head==NULL)
	{
		//printf("entered into loop 1 \n");//loop1
	//	getch();
		p=(node_type*)malloc(sizeof(node_type));
		*p=temp;
		p->next=NULL;
		head=p;
	}
	else if(head->next==NULL || strcmp(head->book_name,temp.book_name)>0 || (strcmp(head->book_name,temp.book_name)==0 &&  strcmp(head->author,temp.author)>0))
	{
			
			
	//	printf("entered into loop 2 \n");//loop 2
	//	getch();
	 if(strcmp(head->book_name,temp.book_name)==0 && strcmp(head->author,temp.author)==0)
			{
				system("cls");
			//	printf("entered loop 3 because equal \n");//loop3
			//	getch();
			//	printf("%s \n",head->book_name);
			//	printf("%s \n",temp.book_name);
			//	printf("%s \n",head->author);
			//	printf("%s \n",temp.author);
			//	printf("second node \n");
			
			printf("\n \n \n \n");
			printf("THE AUTHOR NAME AND THE BOOK NAME IS ALREADY IN THE LIST \n");
			printf("NOW CHOOSE THE OPTION \n\n\n");
			printf("1)LET IT BE..... MAKE A DUPLICATE NODE IN THE LIST \n\n\n");
			printf("2)JUST UPDATE THE REMAINING INFORMATION \n");
			scanf("%s",option);
			if(strcmp(option,"1")==0)
			{
				p=(node_type*)malloc(sizeof(node_type));
				*p=temp;
				p->next=head->next;
				head->next=p;
				
				printf("A DUPLICATE IS SUCCESSFULLY CREATED \n");
				getch();
	
			}
			else
			{
				printf("ACCORDING TO YOUR OPINON THE INFORMATION IS UPDAtED \n");
				*head=temp;
				getch();
		
			}
			
			}
			p=(node_type*)malloc(sizeof(node_type));
			*p=temp;
			if(strcmp(head->book_name,temp.book_name)>0)
			{
				p->next=head;
				head=p;
			}
			if(strcmp(head->book_name,temp.book_name)<0)
			{
				p->next=head->next;
				head->next=p;
				
			}
			
			if(strcmp(head->book_name,temp.book_name)==0)
			{
				
				if(strcmp(head->author,temp.author)>0)
				{
					p->next=head;
					head=p;
				}
				if(strcmp(head->author,temp.author)<0)
				{
					p->next=head->next;
					head->next=p;
					
				}
			}
		
			
			
			
	}
	
	else
	{
	//printf("enterd loop 4\n");//loop4
	//getch();
	int flag=1;

		lptr=head;
		flag=1;
		while(lptr->next != NULL  && flag==1 )
		{
		//	printf("enterd loop 5 \n");//loop5
		//	getch();
		/*	if(strcmp(lptr->book_name,temp.book_name)==0 && strcmp(lptr->author,temp.author)==0)
			{
				
				flag=5;
			}*/
		 if(strcmp(lptr->book_name,temp.book_name)<=0 || strcmp(lptr->author,temp.author)>0 )
			{
				if(strcmp(lptr->book_name,temp.book_name)<=0&& strcmp((lptr->next)->book_name,temp.book_name)>0)
				{
					prev=lptr;
					flag=0;	
				//	printf("5.1 loop\n");
				}
						
			}   
				if(((strcmp((lptr->next)->book_name,temp.book_name)>0 || strcmp((lptr->next)->author,temp.author)>0))&&flag==1)
			{
				if(strcmp((lptr->next)->book_name,temp.book_name)>=0)
				{
					prev=lptr;
					flag=0;
				//	printf("5.2 loop \n");	
				}	
			}
			if(strcmp(lptr->book_name,temp.book_name)==0 && strcmp(lptr->author,temp.author)==0)
			{
				
				flag=5;
			}
			if(flag!=5)
			{
					lptr=lptr->next;
			}			
							
		}	
		if(flag==0)
		{
		//	printf("enterd loop 6 \n");//loop6
		//	getch();
				p=(node_type*)malloc(sizeof(node_type));
				*p=temp;
				p->next=prev->next;
				prev->next=p;	
		}
		
	 if(flag==5)
		{
			//printf("enterd loop 7 \n");//loop7a
			//getch();
			system("cls");
			printf("\n \n \n \n");
			printf("THE AUTHOR NAME AND THE BOOK NAME IS ALREADY IN THE LIST \n");
			printf("NOW CHOOSE THE OPTION \n\n\n");
			printf("1)LET IT BE..... MAKE A DUPLICATE NODE IN THE LIST \n\n\n");
			printf("2)JUST UPDATE THE REMAINING INFORMATION \n");
			scanf("%s",option);
			if(strcmp(option,"1")==0)
			{
				p=(node_type*)malloc(sizeof(node_type));
				*p=temp;
				p->next=lptr->next;
				lptr->next=p;
				
				printf("A DUPLICATE IS SUCCESSFULLY CREATED \n");
				getch();
	
			}
			else
			{
				printf("ACCORDING TO YOUR OPINON THE INFORMATION IS UPDAtED \n");
				p=(node_type*)malloc(sizeof(node_type));
				*p=temp;
				p->next=lptr->next;
				*lptr=*p;
				getch();
		
			}
			
		}
	     if(lptr->next==NULL && flag==1)
		{
		//	printf("enterd loop 8 \n");//loop80
		//	getch();
		
			p=(node_type*)malloc(sizeof(node_type));
			*p=temp;
			if(strcmp(lptr->book_name,temp.book_name)>0)
			{
				p->next=lptr;
				
				
				lptr=p;
			}
			if(strcmp(lptr->book_name,temp.book_name)<0)
			{
				lptr->next=p;
				p->next=NULL;
			}
			
			if(strcmp(lptr->book_name,temp.book_name)==0)
			{
				if(strcmp(lptr->author,temp.author)>0)
				{
					p->next=lptr;
					lptr=p;
				}
				if(strcmp(lptr->author,temp.author)<0)
				{
					lptr->next=p;
					p->next=NULL;
				}
			}
			if(strcmp(lptr->book_name,temp.book_name)==0 && strcmp(lptr->author,temp.author)==0)
			{
				system("cls");
			
			printf("\n \n \n \n");
			printf("THE AUTHOR NAME AND THE BOOK NAME IS ALREADY IN THE LIST \n");
			printf("NOW CHOOSE THE OPTION \n\n\n");
			printf("1)LET IT BE..... MAKE A DUPLICATE NODE IN THE LIST \n\n\n");
			printf("2)JUST UPDATE THE REMAINING INFORMATION \n");
			scanf("%s",option);
			if(strcmp(option,"1")==0)
			{
				p=(node_type*)malloc(sizeof(node_type));
				*p=temp;
				p->next=lptr->next;
				lptr->next=p;
				
				printf("A DUPLICATE IS SUCCESSFULLY CREATED \n");
				getch();
			}
			else
			{
				printf("ACCORDING TO YOUR OPINON THE INFORMATION IS UPDAtED \n");
				p=(node_type*)malloc(sizeof(node_type));
				*p=temp;
				p->next=lptr->next;
				*lptr=*p;
				getch();
		
			}
			
			}			
		}
	}
	return head;
}
node_type* delete(node_type* head)
{
	node_type*lptr,temp,*tempo;
	int flag=1;
	printf("GIVE THE BOOK NAME :\n \n");
	scanf("%s",temp.book_name);
	printf(" \n \n GIVE THE AUTHOR NAME \n \n");
	scanf("%s",temp.author);
	lptr=head;
	if(lptr==NULL)
	{
		system("cls");
		printf("LIST IS EMPTY FIRST ENTER SOME ITEMS TO DELETE \n");
		
		
	}
	else
	{
		if(strcmp(head->book_name,temp.book_name)==0 && strcmp(head->author,temp.author)==0)
		{
			
			tempo=head;
			if(head->next==NULL)
			{
			//	printf("this is the first node so now list is empty \n");
				head=NULL;
				
			}
			else
			{
				head=head->next;
				
				
			}
			free(tempo);
			printf("DATA IS FOUND AND SUCCESSFULLY DELETED \n");
			getch();
			flag=0;
		}
		node_type* prev;
		while(strcmp(lptr->book_name,temp.book_name)<=0 && flag==1)
		{
			if(strcmp((lptr)->book_name,temp.book_name)==0 && strcmp((lptr)->author,temp.author)==0)
			{
				
				
				flag=2;
			}
			if(flag!=2)
			{
				
				prev=lptr;
				lptr=lptr->next;
				
			}	
		}
		if(flag==2)
		{
				
				
			tempo=lptr;
			//printf(" previous node data %s %s \n",prev->book_name,prev->author);
		//	printf(" present node data %s %s \n",lptr->book_name,lptr->author);
			getch();
			prev->next=lptr->next;
			if(lptr->next==NULL)
			{
	
				
				prev->next=NULL;
			}
			free(tempo);
			printf("DATA IS FOUND AND SUCCESSFULLY DELETED \n");
			getch();
			
		}
		else if(flag!=0)
		{
			system("cls");
			printf("\n \n \n \n \n \n ");
			printf("\t \t \t \t \t OOPS!!!!! \n");
			printf("*********************************************************\n");
			printf("****DATA IS NOT FOUND IN THIS LIST PLEASE CHECK!!! ****\n ");
			printf("*********************************************************\n");
		}
		
	}
	return head;
}
int get_num_records(node_type* head)
{
	int count=0;
	if(head==NULL)
	{
		return 0;
	}
	while(head!=NULL)
	{
		head=head->next;
		count++;
	}
	return count;
}
int remove_duplicates(node_type* head)
{
	int flag=0;
	node_type* lptr,*temp;
	lptr=head;
	while(lptr->next!=NULL)
	{
		if(strcmp((lptr->next)->book_name,lptr->book_name)==0 && strcmp((lptr->next)->author,lptr->author)==0)
		{
			temp=lptr->next;
			lptr->next=(lptr->next)->next;
			free(temp);
			flag=1;
		}
		else
		{
			lptr=lptr->next;
		}
				
	}
	return flag;
}
int get_max_books(node_type* head,char author[])
{
	int max=0;
	node_type*lptr,*temp=NULL;
	lptr=head;
	while(lptr!=NULL)
	{
		if(strcmp(lptr->author,author)==0)
		{
			if(lptr->copy_number>max)
			{
				max=lptr->copy_number;
			}
		}
		lptr=lptr->next;
	}
	return max;
	
}
node_type* union_of_lists(node_type* head1,node_type* head2)
{
	node_type* lptr1,*lptr2,*lptr3,temp;
	int n;
	lptr1=head1;
	lptr2=head2;
	lptr3=NULL;
	n=remove_duplicates(head1);
	n=remove_duplicates(head2);
	while(lptr1!=NULL && lptr2!=NULL)
	{
		if(strcmp(lptr1->book_name,lptr2->book_name)==0&&strcmp(lptr1->author,lptr2->author)==0)
		{
			temp=*lptr1;
			lptr3=make_new_node(lptr3,temp);
			lptr1=lptr1->next;
			lptr2=lptr2->next;
		}
	else if(strcmp(lptr1->book_name,lptr2->book_name)>0 || (strcmp(lptr1->book_name,lptr2->book_name)==0)&&strcmp(lptr1->author,lptr2->author)>0)
		{
			temp=*lptr2;
			lptr3=make_new_node(lptr3,temp);
			lptr2=lptr2->next;
		}
	else if(strcmp(lptr1->book_name,lptr2->book_name)<0 || (strcmp(lptr1->book_name,lptr2->book_name)==0)&&strcmp(lptr1->author,lptr2->author)<0)
		{
			temp=*lptr1;
			lptr3=make_new_node(lptr3,temp);
			lptr1=lptr1->next;
		}
		
	}
	while(lptr1!=NULL)
	{
		temp=*lptr1;
		lptr3=make_new_node(lptr3,temp);
		lptr1=lptr1->next;
	}
		while(lptr2!=NULL)
	{
		temp=*lptr2;
		lptr3=make_new_node(lptr3,temp);
		lptr2=lptr2->next;
	}
	return lptr3;
}
node_type* intersection(node_type* head1,node_type* head2)
{
	node_type* lptr3=NULL;
	node_type t;
	int n;
	n=remove_duplicates(head1);
	n=remove_duplicates(head2);
	while(head1!=NULL && head2!=NULL)
	{
		if(strcmp(head1->book_name,head2->book_name)>0||(strcmp(head1->book_name,head2->book_name)==0&&strcmp(head1->author,head2->author)>0))
		{
		//	printf("if 1\n");
			head2=head2->next;
		}
		else if(strcmp(head1->book_name,head2->book_name)<0||(strcmp(head1->book_name,head2->book_name)==0&&strcmp(head1->author,head2->author)<0))
		{
		//	printf("if 2\n");
			head1=head1->next;
		}
		else if(strcmp(head1->book_name,head2->book_name)==0&&strcmp(head1->author,head2->author)==0)
		{
		//	printf("if 3\n");
			t=*head1;
			lptr3=make_new_node(lptr3,t);
			head1=head1->next;
			head2=head2->next;
		}
		
	}	
	return lptr3;
}
node_type* difference(node_type* head1,node_type* head2)
{
	node_type* lptr3,p;
	int n;
	n=remove_duplicates(head1);
	n=remove_duplicates(head2);
	while(head1!=NULL && head2!=NULL)
	{
		if(strcmp(head1->book_name,head2->book_name)<0||(strcmp(head1->book_name,head2->book_name)==0&&strcmp(head1->author,head2->author)<0))
		{
			p=*head1;
			lptr3=make_new_node(lptr3,p);
			head1=head1->next;
		}
		else if((strcmp(head1->book_name,head2->book_name)==0&&strcmp(head1->author,head2->author)==0))
		{
			head2=head2->next;
			head1=head1->next;
		}
		else
		{
			head2=head2->next;
		}
	}
	if(head1!=NULL)
	{
		while(head1!=NULL)
		{
			p=*head1;
			lptr3=make_new_node(lptr3,p);
			head1=head1->next;
		}
	}
	
	return lptr3;
}
node_type* symmetric_difference(node_type* head1,node_type* head2)
{
	node_type* lptr3=NULL,t;
	while(head1!=NULL && head2!=NULL)
	{
		if(strcmp(head1->book_name,head2->book_name)>0||(strcmp(head1->book_name,head2->book_name)==0&&strcmp(head1->author,head2->author)>0))
		{
			t=*head2;
			lptr3=make_new_node(lptr3,t);
		
			head2=head2->next;
		}
		else if(strcmp(head1->book_name,head2->book_name)<0||(strcmp(head1->book_name,head2->book_name)==0&&strcmp(head1->author,head2->author)<0))
		{
			t=*head1;
			lptr3=make_new_node(lptr3,t);
			head1=head1->next;
		}
		else if(strcmp(head1->book_name,head2->book_name)==0&&strcmp(head1->author,head2->author)==0)
		{	
			head1=head1->next;
			head2=head2->next;
		}
		
	}
	while(head1!=NULL)
	{
		t=*head1;
		lptr3=make_new_node(lptr3,t);
		head1=head1->next;
	}
	while(head2!=NULL)
	{
		t=*head1;
		lptr3=make_new_node(lptr3,t);
		head2=head2->next;
	}
	return lptr3;
}
