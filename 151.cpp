#include<iostream>
#include<cstdio>
using namespace std;

int Josephus(int n,int k)
{
    if (n == 1)
		return 1;
	else
		return (Josephus(n-1, k) + k-1) % n+1;
}

int main()
{
	int N;
	int i;
	
	while(cin >> N && N)
	{
		for(i=1;i<=1000;i++)
		{
			if(Josephus(N-1,i)==12)
			{
				break;
			}
		}
		
		cout << i << endl;
	}
	
	return 0;
}
