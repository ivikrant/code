#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

struct list
{
	int data;
	struct list *l;
	struct list *r;
};

struct globalvarialble
{
	int max;
}m;

struct list *h, *ptr, *prev, *t;

int isEmpty()
{
	if(h == '\0')
		return 1;
	return 0;
}

void insert(int x)
{
	t = new list;
	
	t->data = x;
	t->l = '\0';
	t->r = '\0';
	
	if( isEmpty())
	{
		h = t;
		return;
	}
	else
	{
		ptr = h;
		prev=h;
		while(ptr!='\0')
		{
			if(ptr->data > x)
			{
				prev = ptr;
				ptr = ptr->l;
			}
			else 
			{
				prev = ptr;
				ptr = ptr->r;
			}
		}
		
		if(prev->data > x)
		{
			prev->l = t;
		}
		else
		{
			prev->r = t;
		}
	}
}

void traversal(list *r)
{
	if( r == '\0')
	{
		return;
	}
	cout<<r->data;
	traversal(r->l);
	traversal(r->r);
}

void left(list *r,int n)
{
	if( r == '\0')
	{
		if( n > m.max)
			m.max=n-1;
		
		return ;
	}
	if( n > m.max)
		cout<<r->data << " ";
	n++;
	left(r->l,n);
	left(r->r,n);
}

void right(list *r,int n)
{
	if( r == '\0')
	{
		if( n > m.max)
			m.max=n-1;
		
		return ;
	}
	if( n > m.max)
		cout<<r->data << " ";
	n++;
	right(r->r,n);
	right(r->l,n);
	
}


int main()
{
	int n,x;
	cin>>n;
	h='\0';
	
	m.max=-1;
	
	for(int i=0;i<n;i++)
	{
		cin>>x;
		insert(x);
	}
	
	//traversal(h);
		
	cout<<"\n\n";
	
	left(h,0);
	
	cout<<"\n\n";
	m.max=-1;
	right(h,0);
}