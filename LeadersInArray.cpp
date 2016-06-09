//Leaders in array, all those elements in array which have elements smaller than them on their right side.
// 9 17 4 8 13 11 1 , ans = 1 11 13 17

#include<iostream>
#include<stdlib.h>

using namespace std;

int main()
{
	int n, max = -9999;
	cin>>n;
	
	int a[n];
	
	for ( int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	cout<<"\n\n";
	
	max = a[n-1];
	cout<<a[n-1]<<" ";
	for(int i = n-2; i >= 0 ; i--)
	{
		if(a[i] > max)
		{
			max = a[i];
			cout<<a[i]<<" ";
		}
		
	}
	
}