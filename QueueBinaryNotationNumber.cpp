#include<iostream>
#include<String.h>

using namespace std;

struct queue{
	string val[50];
	int f,r;
}q;

int isEmpty()
{
	if(q.f == -1 && q.r == -1)
		return 1;
	return 0;
}

int isFull()
{
	if(q.r == 99)
		return 1;
	return 0;
}

void enqueue(string x)
{
	if ( isFull())
	{
		cout<<endl<<"Overflow, please free some space...";
		return;
	}
	if( isEmpty())
	{
		q.val[++q.r] = x;
		++q.f;
	}
	else
		q.val[++q.r] = x;
}

string dequeue()
{
	if ( isEmpty())
	{
		cout<<endl<<"Underflow, please insert some items...";
		return "\0";
	}
	if ( q.f == q.r)
	{
		string x = q.val[q.f];
		q.f = q.r = -1;
		return x;
		
	}
	return q.val[q.f++];
}

void peek()
{
	if ( isEmpty())
	{
		cout<<endl<<"Queue is empty, please insert some items...";
		return ;
	}
	cout<<endl<<q.val[q.r];
}

void binary(int n)
{
	if (n == 0)
		return;
	string x = dequeue();
	string y = x;
	cout<<endl<<x;
	x += "0";
	y += "1";
	
	enqueue(x);
	enqueue(y);
	binary(--n);
}

int main()
{
	q.f = q.r = -1;
	enqueue("1");
	binary(5);
	
}