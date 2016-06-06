#include<iostream>

using namespace std;

struct stack{
	int val[100];
	int Top;
}s;

struct stacksum{
	int sum ;
	int min ;
}ss;

int isEmpty()
{
	if(s.Top == -1)
		return 1;
	return 0;
}

int isFull()
{
	if(s.Top == 99)
		return 1;
	return 0;
}

void push(int x)
{
	if ( isFull())
	{
		cout<<endl<<"Overflow, please free some space...";
		return;
	}
	s.val[++s.Top] = x;
}

int pop()
{
	if ( isEmpty())
	{
		cout<<endl<<"Underflow, please insert some items...";
		return -1;
	}
	return s.val[s.Top--];
}

void peek()
{
	if ( isEmpty())
	{
		cout<<endl<<"Stack is empty, please insert some items...";
		return;
	}
	cout<<endl<<s.val[s.Top];
}

void insertion(int x)
{
	push(x);
}

void deletion()
{
	int x = pop();
	if(isEmpty())
	{
		return;
	}
	deletion();
	push(x);
}

void traversal()
{
	if(isEmpty())
		return;
	int x = pop();
	traversal();
	cout<<x<<" ";
	push(x);
	
}

int main()
{
	s.Top = -1;
	insertion(5);
	insertion(3);
	insertion(2);
	
	traversal();
	cout<<endl<<"**************************************"<<endl;
	deletion();
	traversal();
	cout<<endl<<"**************************************"<<endl;
	insertion(8);
	traversal();
	cout<<endl<<"**************************************"<<endl;
	deletion();
	traversal();
	
}