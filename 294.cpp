#include<iostream>
#include<cstdio>
using namespace std;

/*10^9�̦h�u��34000�ӽ��(���}��)*/ 

int visit[34000];
int prime[34000];//���� 

/*��X�]�ƭӼ�*/ 
int total_factor(int number,int index)
{
	int sum=1;
	int i;
	
	for(i=0;number>1&&i<index;i++)
	{
		if(number%prime[i]==0)
		{
			int count=1;
			
			/*��]�Ƥ���(�i�H�Q�ν�]�Ƥ��ѧ��]�ƭӼ�)*/  
			while(number%prime[i]==0)
			{
				count++;
				number/=prime[i];
			}
			sum*=count;
		}
	}
	
	return sum;
} 


int main()
{
	/*initial*/ 
	int i;
	
	for(i=0;i<34000;i++)
	    visit[i]=0;
	
	int index=0;
	
	/*��X34000�H�������*/
	for(i=2;i<34000;i++)
	{
		if(visit[i]==0)//���O��ƴN�аO��1 
		{
			prime[index++]=i;//�N����x�s��prime array�� 
			
			int j;
			
			for(j=i*2;j<34000;j+=i)//��ӽ�ƪ����Ƴ��аO��1 
			    visit[j]=1;
		}
	}
	
	long line,L,U;
	
	cin >> line;
	
	while(line)
	{
		cin >> L>>U;
		long k,total;
		long max=0;
		long result_number;
		
		for(k=L;k<=U;k++)
		{
			total=total_factor(k,index-1);
			if(total>max)
			{
				max=total;
				result_number=k;
			}
		}
		
		
		cout << "Between " << L << " and " << U << ", " << result_number << " has a maximum of " << max << " divisors.\n";
		
		line--;
		
	}

	return 0;
}
