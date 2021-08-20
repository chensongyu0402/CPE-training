#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int result[10001];
	
	int left,height,right;
	int i;
	int start=1;
	int end=1;
	
	for(i=1;i<=10000;i++)
	result[i]=0;
	
	while(cin >>left>>height>>right)
	{
		for(i=left;i<right;i++)
		{
			if(height>result[i])
			result[i]=height;
		}
	}
	
	while(end<10000)
	{
		
		if(result[end]==result[end+1])
		{
			end++;
		}
		else
		{
			cout << start <<" " << result[end] <<" ";
			start=end+1;
			end++;
		}
			
	}
	
	cout << start <<" " << "0"<<endl;
	
	return 0;	
} 
