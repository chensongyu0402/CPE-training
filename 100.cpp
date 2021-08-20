#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	
	long max; 
	long i,j; 
	long k;
	long n=0;
	long length;
	int flag;
	
	while(cin >> i >> j && i && j)
	{

	flag=0;
	max=0;
	length=1;
	
	if(i>j)
	{
		int temp;
		temp=i;
		i=j;
		j=temp;
		flag=1;
	}
	
	for(k=i;k<=j;k++)
	{
		n=k;
		length=1;
		
		while(1)
		{
			if(n==1)
			{
				if(length>max)
				max=length;
				
				break;
			}
			else if(n%2==1)
			{
				length++;
				n=3*n+1;
			}
			else
			{
				length++;
				n=n/2;
			}
		}
	}
	
	if(flag==0)
	cout << i <<" " << j <<" "<< max << endl;
	else
	cout << j <<" " << i <<" "<< max << endl;
	
   }
	return 0;
	
}
 
