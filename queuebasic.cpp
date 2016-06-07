#include<iostream>

using namespace std;

struct queue{
	int val[100];
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

void enqueue(int x)
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

int dequeue()
{
	if ( isEmpty())
	{
		cout<<endl<<"Underflow, please insert some items...";
		return -1;
	}
	if ( q.f == q.r)
	{
		int x = q.val[q.f];
		q.f = q.r = -1;
		return x;
		
	}
	return q.val[q.f++];
}

int peek()
{
	if ( isEmpty())
	{
		cout<<endl<<"Queue is empty, please insert some items...";
		return -1;
	}
	cout<<endl<<q.val[q.r];
}

int main()
{
	q.f = q.r = -1;
	enqueue(5);
	peek();
	enqueue(3);
	peek();
	enqueue(8);
	peek();
	
	cout<<"\n\n Dequeue elements :\n";
	
	peek();
	cout << "\nDequeing : "<<dequeue();
	peek();
	cout << "\nDequeing : "<<dequeue();
	peek();
	cout << "\nDequeing : "<<dequeue();
	peek();
}