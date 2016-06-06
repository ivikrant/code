#include<iostream>

using namespace std;

int partition( int a[], int l, int h)
{
	int pivit = a[h];
	int i = l -1;
	int temp = 0;
	
	for(int j= l; j <= h-1;j++)
	{
		if( a[j] <= pivit)
		{
			i++;
			temp = a[j];
			a[j] = a[i];
			a[i] = temp;
		}
	}
	
	temp = a[i + 1];
	a[i+1] = a[h];
	a[h] = temp;
	
	return i+1;
}

void quicksort(int a[], int l,int h)
{
	if ( l < h)
	{
		int piv = partition( a, l, h);
		
		quicksort( a, l, piv-1);
		quicksort( a, piv+1, h);
	}
	
}

int main()
{
	int arr[] = { 1, 6, 9, 4, 5};
	
	quicksort(arr, 0, 4);
	
	for ( int i=0; i <5; i++)
		cout<< arr[i] << endl;
}