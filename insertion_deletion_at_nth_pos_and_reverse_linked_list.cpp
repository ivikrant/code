#include<iostream>
using namespace std;
struct node
{
	int data;
    node *next;
	
}s;
struct node *head;

void insert(int value,int pos)
{
	int i=0;
	node *temp;
	node *ptr = new node();
	temp=head;
	if(pos==1)	
	{
		ptr->data=value;
		ptr->next=NULL;
		head=ptr;
	}
    
	else
	{
		while(i<pos-2)
		{
			temp=temp->next;
			i++;
			
		}
		ptr->data=value;
		ptr->next=temp->next;
		temp->next=ptr;
	}
}
void deletion(int pos)
{
	node *temp;
	temp=head;
	int i=0;
	if(pos==1)
	{
		
		head=temp->next;
		
	}
	else
	{
		while(i<pos-2)
		{
			temp=temp->next;
			i++;
		}
		temp->next=temp->next->next;	
	}
	
	
	
}
void display()
{
	node *ptr=NULL;
	ptr=head;
	while(ptr!=NULL)
	{
		cout<<ptr->data<<" ";
		ptr=ptr->next;
	}
	
}
void reverse()
{
	node *current=NULL;
	node *prev=NULL;
	node *next=NULL;
	current=head;
	while(current!=NULL)
	{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
	}
	head=prev;
}
int main()
{
	int n,no,pos;
	while(1){
	
	cout<<"enter selection :";
	cin>>n;
	
	switch(n)
	{
		case 1:
			cout<<"enter no:";
			cin>>no;
			cout<<"enter pos :";
			cin>>pos;
			insert(no,pos);
			break;
			
		case 2:
			cout<<"enter position :";
			cin>>pos;
			deletion(pos);
			break;
			
		case 3:		
			display();
			break;
		case 4:
			reverse();
			break;
				
	}
}
	
}
