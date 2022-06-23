#include <stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *link;
}sll;

void create_sll(sll **head,int data);
void create_cll(sll **head1,int data);
void is_linkedlist_circular(sll **head);

int main()
{
	sll *head=NULL,*head1=NULL;
	int option,data;
	while(1)
	{
		printf("1.create sll\n2.create cll\n3.is_linkedlist_circular\n4.exit\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				printf("Enter data:");
				scanf("%d",&data);
				create_sll(&head,data);
				break;
			case 2:
				printf("Enter data:");
				scanf("%d",&data);
				create_cll(&head1,data);
				break;
			case 3:
				is_linkedlist_circular(&head1); //pass &head1 to check cll and &head to check sll
				break;
			case 4:
				exit(0);
				break;

		}
	}

	return 0;
}

void create_sll(sll **head,int data)
{
	sll *newnode=(sll *)malloc(sizeof(sll));
	if(newnode==NULL)
	{
		printf("Memory is not allocated\n ");
	}
	else
	{
		newnode->data=data;
		newnode->link=NULL;
		if(*head==NULL)
		{
			*head=newnode;
		}
		else
		{
			sll *temp = *head;
			while(temp->link != NULL)
			{
				temp=temp->link;
			}
			temp->link=newnode;
		}
	}
}


void create_cll(sll **head1,int data)
{
	sll *newnode=(sll *)malloc(sizeof(sll));
	if(newnode==NULL)
	{
		printf("Memory is not allocated\n");
	}
	else
	{
		sll *temp;
		newnode->data=data;
		newnode->link=NULL;
		if(*head1==NULL)
		{
			*head1 = newnode;
			newnode->link= *head1;
		}
		else
		{
			temp=*head1;
			while(temp->link!= *head1)
			{
				temp=temp->link;
			}
			temp->link=newnode;
			newnode->link = *head1;
		}
	}
}


void is_linkedlist_circular(sll **head)
{

	if(*head==NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		sll *temp = (*head)->link;
		while(temp != NULL && temp != *head)
		{
			temp=temp->link;
		}
		if(temp == *head)
		{
			printf("It is a circular linked list\n");
		}
		else
		{
			printf("It is not a circular linked list\n");
		}
	}
}





