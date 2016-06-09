#include<iostream>
#include<stdlib.h>

using namespace std;

int main()
{
	int n;
	cin>>n;
	
	int a[n+2+1];
	
	//For Hashing purpose, we add one index to array, otherwise array size will be n+2, and index will be a[i]-1.
	for ( int i=1;i<=(n+2);i++)
	{
		cin>>a[i];
	}
	
	cout<<"\n\n";
	for ( int i=1;i<=(n+2);i++)
	{
		if(a[abs(a[i])] > 0)
		{
			a[abs(a[i])] = 0-a[abs(a[i])];
		}
		else
		{
			cout<<abs(a[i])<<endl;
		}
	}
}