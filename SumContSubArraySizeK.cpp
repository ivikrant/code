#include<iostream>

using namespace std;

int main()
{
	int n,k, sum =0, max=-9999;
	cin>>n;
	cin>>k;
	
	int a[n];
	
	if( k > n)
	{
		cout<<"K is greater...";
		return 0;
	}
	
	for ( int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	sum = 0;
	for(int i=0;i<k;i++)
	{
		sum += a[i];
	}
	for(int i=0;i<(n-k);i++)
	{
		sum = sum - a[i] + a[i+k];
		if(sum > max)
		{
			max = sum;
		}
			
	}

	cout<<"\n\nMaximum sum of cont. subarray of size k= "<<k<<", is : "<<max;		
}