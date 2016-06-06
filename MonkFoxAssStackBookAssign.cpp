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

int stacksum()
{
	if(isEmpty())
	{
		return 0;
	}
	
	int x = pop();
	int y = stacksum();
	
	int s1 = x+y;
	int s2 = ss.sum - s1;
	
	if ( s1>s2 && s1 < ss.min)
		ss.min = s1;
	else if ( s2>s1 && s2 < ss.min )
		ss.min = s2;
		
	return s1;
}

int main()
{
	s.Top = -1;
	ss.min = 10000;
	ss.sum = 0;
	
	int n;
	cin>>n;
	int a[n];
	for ( int i=0;i<n;i++)
	{
		cin>>a[i];
		push(a[i]);
		ss.sum += a[i];
	}	
	
	stacksum();
	cout<<ss.min;
}