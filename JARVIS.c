#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *add;
};
void display(struct node *head,struct node *cur,int size){

	cur=head;

	printf("\nJARVIS\n");	
	printf("------\n");

	printf("Here's Our Link List :)\n");
	printf("-----------------------\n");
	for (int i = 0; i < size; ++i)
	{
		printf("Node %d: Data : %d\n",i+1,cur->data);
		cur=cur->add;

	}
	printf("\n");
}
int insertOption(){
	int insertChoice;

	printf("\nJARVIS\n");	
	printf("------\n");

	printf("INSERT OPERATIONS\n");
	printf("1.At Begining\n");
	printf("2.At Ending\n");
	printf("3.At Index\n");
	printf("\n\n");	

	scanf("%d",&insertChoice);

	return insertChoice;

}

int deleteOption()
{
	int deleteChoice;

	printf("\nJARVIS\n");	
	printf("------\n");

	printf("DELETE OPERATIONS\n");
	printf("1.At Begining\n");
	printf("2.At Ending\n");
	printf("3.At Index\n");
	printf("\n");	

	scanf("%d",&deleteChoice);

	return deleteChoice;
}

void insertAtBeginning(struct node **head)
{
	struct node *cur=malloc(sizeof(struct node));

	printf("\nJARVIS\n");	
	printf("------\n");

	printf("Enter Data for Node 1\n");
	scanf("%d",&cur->data);
	cur->add=*head;
	*head=cur;	
}
void insertAtEnding(struct node **head,struct node **cur,int size)
{
	struct node *ptr=malloc(sizeof(struct node));

	printf("\nJARVIS\n");	
	printf("------\n");

	printf("Enter Data for Node %d\n",size);
	scanf("%d",&ptr->data);
	ptr->add=NULL;

	for (int i = 0; i < size; ++i)
	{
		*cur=*head;
		while((*cur)->add!=NULL)
		{
			*cur=(*cur)->add;
		}	
	}
	(*cur)->add=ptr;
	*cur=(*cur)->add;
}
void insertAtIndex(struct node **head,struct node **cur,int size)
{
	int index;
	struct node *ptr=malloc(sizeof(struct node));

	printf("\nJARVIS\n");	
	printf("------\n");

	printf("NOTE: Insert Index!\n");

	printf("Enter Index Number for New Node\n");
	scanf("%d",&index);
	
	if(index==0)
	{
		insertAtBeginning(head);
	}
	else if(index==size-1)
	{
		insertAtEnding(head,cur,size);
	}
	else if(index<0 || index>size-1)
	{
		printf("\nJARVIS\n");	
		printf("------\n");

		printf("Invailed Index :(\n");
		insertAtIndex(head,cur,size);
	}
	else
	{
		struct node *ptr=malloc(sizeof(struct node));
		struct node *ptr2;
		*cur=*head;

		for (int i = 0; i < size; ++i)
		{
			*cur=(*cur)->add;
			if(i==index-1)
			{
				ptr2->add=(*cur)->add;
				(*cur)->add=ptr;
			}	
			if(i==index)
			{
				ptr->add=ptr2->add;
			}	
		}
	}
}	
void deleteAtBeginning(struct node **head)
{
	printf("\nJARVIS\n");	
	printf("------\n");

	printf("\nNode 1 Has Been Deleted\n");
	struct node *cur=*head;

	cur=cur->add;
	(*head)->add=NULL;	
	*head=cur;
}
void deleteAtEnding(struct node **head,struct node **cur,int size)
{//totalsize=4,size=3,index=012-3,trasfer-req=2

	printf("\nJARVIS\n");	
	printf("------\n");

	printf("\nNode %d Has Been Deleted\n",size+1);

	for (int i = 0; i < size-1; ++i)
	{
		*cur=*head;
		
		*cur=(*cur)->add;	
	}
	(*cur)->add=NULL;

}
void deleteAtIndex(struct node **head,struct node **cur,int size)
{
	int index;

	printf("\nJARVIS\n");	
	printf("------\n");

	printf("NOTE: Insert Index!\n");
	
	printf("\nEnter Index Number to Delete \n");
	scanf("%d",&index);
	
	if(index==0)
	{
		deleteAtBeginning(head);
	}
	else if(index==size)
	{
		deleteAtEnding(head,cur,size);
	}//ts=5,s=4,i=0123-4
	else if(index<0 || index>size)
	{

		printf("\nJARVIS\n");	
		printf("------\n");	
		
		printf("Invailed Index :(\n");
		deleteAtIndex(head,cur,size);
	}
	else
	{
		struct node *ptr;

		*cur=*head;
		//ts=5,s=4,i=0-123-4,(a)=2.add-and-NULL{rt=2,},(b)=1.add->2.add
		for (int i = 0; i <= index; ++i)
		{
			*cur=(*cur)->add;
		}
			ptr->add=(*cur)->add;
			(*cur)->add=NULL;
		*cur=*head;	
		for (int i = 0; i < index; ++i)
		{
			*cur=(*cur)->add;			
		}		
		(*cur)->add=ptr->add;
		*cur=*head;

		printf("\nJARVIS\n");	
		printf("------\n");

		printf("Node %d Has Been Deleted :)\n",index+1);
	}	
}	
void search(struct node *head,struct node *cur)
{
	int search,i=0,flag=0,node;
	cur=head;

	printf("\nJARVIS\n");	
	printf("------\n");

	printf("\nEnter Data To Be Searched\n");
	scanf("%d",&search);

	while(cur!=NULL)
	{	i++;
		if (cur->data==search)
		{
			flag++;
			node=i;
		}
		cur=cur->add;
	}
	if(flag>0)
	{	
		printf("\nJARVIS\n");	
		printf("------\n");

		printf("\nData: %d Is Found At Node:%d  :)\n",search,node);
	}
	else
	{	
		printf("\nJARVIS\n");	
		printf("------\n");

		printf("\nData: %d Is Not Found :(\n",search);	
	}		
}


void main()
{

	int choice,size,iChoice,dChoice; 
	char name[20];

	printf("\nJARVIS\n");	
	printf("------\n");
	printf("Hello Sir! My Name is JARVIS :)\n\n");
	printf("What Can I Call You Master \n");
	scanf("%s",name);

	printf("\nJARVIS\n");	
	printf("------\n");
	printf("%s, I Will Be Your Assistant In This Program\n", name);
	printf("This Program Is Called 'Linked List'\n");

	printf("\nJARVIS\n");	
	printf("------\n");
	printf("So Lets Start The Program By Creating A Link List ;)\n\n");
	printf("Enter size of Link List\n");
	scanf("%d",&size);

	struct node *head=malloc(sizeof(struct node));
	struct node *cur=head;

	if(size>0)
	{	
	printf("\nJARVIS\n");	
	printf("------\n");
	}

	for (int i = 0; i < size; ++i)
	{
		printf("Enter data of Node:%d\n",i+1);
		scanf("%d",&cur->data);

		if (i!=size-1)
		{
			cur->add=malloc(sizeof(struct node));
			cur=cur->add;
		}
	}
	
	cur->add=NULL;
	cur=head;

	do{
		printf("\n\nJARVIS\n");	
		printf("------\n");
			
		printf("OPERATIONS\n");
		printf("1.Display\n");
		printf("2.Insert\n");
		printf("3.Delete\n");
		printf("4.Search\n");
		printf("5.About Me ;)\n");
		printf("6.Exit\n");
		printf("\n");	

		scanf("%d",&choice);

		if(choice==1)
		{
			display(head,cur,size);
		}
		if(choice==2)
		{
			iChoice=insertOption();

			if(iChoice>3 || iChoice<1 || iChoice==0	)
			{
				printf("\nJARVIS\n");	
				printf("------\n");
				printf("Invailed choice\n");
			}

			if(iChoice==1)
			{
					size++;
				insertAtBeginning(&head);
			}
			if(iChoice==2)
			{		size++;
				insertAtEnding(&head,&cur,size);
			}
			if(iChoice==3)
			{
				size++;
				insertAtIndex(&head,&cur,size);
			}
		}		
		if(choice==3)
		{
			dChoice=deleteOption();

			if(dChoice>3 || dChoice<1 || dChoice==0	)
			{
				printf("\nJARVIS\n");	
				printf("------\n");
				printf("Invailed choice\n");
			}

			if(dChoice==1)
			{
					size--;
				deleteAtBeginning(&head);
			}
			if(dChoice==2)
			{		size--;
				deleteAtEnding(&head,&cur,size);
			}
			if(dChoice==3)
			{
				size--;
				deleteAtIndex(&head,&cur,size);
			}
		}	
		if(choice==4)
		{
			search(head,cur);
		}
		if(choice==5)
		{
			printf("\nJARVIS\n");	
			printf("------\n");

			printf("Oh! Hello, My Name Is JARVIS.\n");	
			printf("I Am A Program To Use Link List.\n");
			printf("I Have Been Created By GARV :)\n");	
			printf("Thanks For Using Me :)\n");			
		}	
		
		if(choice<1 || choice >6)
			{
				printf("\nJARVIS\n");	
				printf("------\n");
				printf("Invailed choice\n");
			}

	}
	while(choice!=6 ); 
	if(choice==6)
	{
		printf("\nJARVIS\n");	
		printf("------\n");

		printf("See You! %s.\n", name);
		printf("JARVIS Signing Off...\n");
	}
	

}
