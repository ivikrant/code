#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

struct tree
{
	int data;
	struct tree *l;
	struct tree *r;
};

struct tree *h, *ptr, *prev, *t;

int isEmpty()
{
	if(h == '\0')
		return 1;
	return 0;
}

void insert(int x)
{
	t = new tree;
	
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

void pre(tree *r)
{
	if( r == '\0')
	{
		return;
	}
	cout<<r->data<<" ";
	pre(r->l);
	pre(r->r);
}

void post(tree *r)
{
	if( r == '\0')
	{
		return;
	}
	post(r->l);
	post(r->r);
	cout<<r->data<<" ";
}

void inOrder(tree *r)
{
	if( r == '\0')
	{
		return;
	}
	
	inOrder(r->l);
	cout<<r->data<<" ";
	inOrder(r->r);
}

int height(tree *r)
{
	if(r=='\0')
		return 0;
	
	int x = height(r->l);
	int y = height(r->r);
	if( x>y)
	{
		return 1 + x;
	}
	
	return 1 + y;
}

int nodes(tree *r)
{
	if(r != '\0')
		return 1 + nodes( r->l) + nodes( r->r);
}

int main()
{
	int n,x;
	cin>>n;
	h='\0';
	
	for(int i=0;i<n;i++)
	{
		cin>>x;
		insert(x);
	}
	
	cout<<"\n\n";
	
	cout<<"Preorder Traversal : ";
	pre(h);
	
	cout<<"\n\n";
	
	cout<<"InOrder Traversal : ";
	inOrder(h);
		
	cout<<"\n\n";
	
	cout<<"Postorder Traversal : ";
	post(h);
	
	cout<<"\n\n";
	
	cout<<"Height of tree : "<<height(h);
	
	cout<<"\n\n";
	
	cout<<"Edges in largest Path in tree : "<<height(h)-1;
	
	cout<<"\n\n";
	
	cout<<"Total nodes in tree : "<<nodes(h);
}