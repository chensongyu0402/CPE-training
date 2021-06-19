#include<stdio.h>
#include <stdbool.h>

bool norepeat(int a,int b)
{
	int n[10];
	int i;
	
	for(i=0;i<10;i++)
	n[i]=0;
	
	if(a<10000 && b<10000)
	return false;
	
	if(a<10000 || b<10000)
	n[0]=1;
	
	while(a>0)
	{
		if(n[a%10]==1)return false;
		else
		n[a%10]=1;

		a/=10;
	}
	
    while(b>0)
	{
		if(n[b%10]==1)
		return false;
		else
		n[b%10]=1;
		
		b/=10;
	}
	
	return true;
	
}

int main()
{
	int number1;
	int number2=0;
	int i;
	int start=1;
	
	while(scanf("%d", &number1))
   {
    		
	int flag=0;
	
	if (number1 == 0)break;
	
	if(!start)printf("\n");
	start=0;
	
	for(i=1234;i<=98765;i++)
	{
		number2=number1*i;
		                
		if(norepeat(number2,i))   
		{
			
			printf("%05d /",number2);
			
			if(i<10000)
			printf(" %05d = %d\n",i,number1);
			else
			printf(" %05d = %d\n",i,number1);
			
			flag=1;
		}
	}
	
	if(flag==0)
	{		
		printf("There are no solutions for %d.\n",number1);
	}
	
	
	}

	return 0;
}
