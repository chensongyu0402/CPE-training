#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int d;
	int i,j,k;
	cin >> d;
	
	int array[d+1][d+1];
	
	for(i=1;i<=d;i++)
	{
		for(j=1;j<=d;j++)
		{
			int number;
			cin >> number;
			array[i][j]=number; 
		}
	}
	
	for(j=1;j<=d;j++)
	{
		for(i=2;i<=d;i++)
		{
			array[i][j]+=array[i-1][j];
		}
	}
		
	int max=0;
    int sum;

	for(k=1;k<=d;k++)
	{
		for(i=k;i<=d;i++)
		{
			sum=0;
			
			for(j=1;j<=d;j++)
			{
				sum+=array[i][j]-array[k-1][j];
				if(sum>max)max=sum;
				if(sum<0)sum=0;
			}
		}
	}
	
	cout << max << endl;
	
	return 0;
} 
