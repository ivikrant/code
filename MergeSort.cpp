#include<iostream>
#include<stdio.h>

using namespace std;

int merge(int arr[], int l, int m, int r)
{
	int i=0,j=0,k=0;
	
	int n1 = m-l+1;
	int n2 = r-m;
	
	int a[ n1];
	int b[n2];
	
	i= l;
	while( k < n1)
	{
		a[k++] = arr[i++];
	}
	
	k=0;
	j=m+1;
	while( k < n2)
	{
		b[k++] = arr[j++];
	}
	
	i=0;
	j=0;
	k=l;
	
	while( i< n1 && j < n2)
	{
		if(a[i] < b[j])
		{
			arr[k++] = a[i++];
		}
		else
		{
			arr[k++] = b[j++];
		}
	}
	
	while ( i < n1)
	{
		arr[k++] = a[i++];
	}
	
	while( j < n2 )
	{
		arr[k++] = b[j++];
	}
}

int mergesort(int arr[], int l, int r)
{
	if( l < r)
	{
		int m = (l + r)/2;
	
		mergesort(arr, l, m);
		mergesort(arr, m+1, r);
	
		merge(arr, l, m, r);
	}
}

int main()
{
	int arr[] = {1, 2, 5, 9, 3, 4};
	
	for( int i=0;i<6;i++)
		cout << arr[i]<<endl;
		
	cout<<endl<<"**************************************"<<endl;
	
	mergesort(arr,0,5);
	
	for( int i=0;i<6;i++)
		cout << arr[i]<<endl;
	
}