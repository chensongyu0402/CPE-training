#include<stdio.h>
int main(){
	char str[100];
	while(scanf("%s",&str)==1)
	{
		int i;
		int capital=0;
		int hyphen=0;
		
		for(i=0;str[i];i++)
		{
			if(str[i]>='A' && str[i] <='C')
			{
				printf("2");
				capital++;
			}
			
			else if(str[i]>='D' && str[i] <='F')
			{
				printf("3");
				capital++;
			}
			else if(str[i]>='G' && str[i] <='I')
			{
				printf("4");
				capital++;
			}
			else if(str[i]>='J' && str[i] <='L')
			{
				printf("5");
				capital++;
			}
			else if(str[i]>='M' && str[i] <='O')
			{
				printf("6");
				capital++;
			}
			else if(str[i]>='P' && str[i] <='S')
			{
				printf("7");
				capital++;
			}
			else if(str[i]>='T' && str[i] <='V')
			{
				printf("8");
				capital++;
			}
			else if(str[i]>='W' && str[i] <='Z')
			{
				printf("9");
				capital++;
			}
			else if(str[i]=='-')
			{
				printf("-");
				hyphen++;
			}
			else
			printf("%c",str[i]);
		}
		printf(" %d %d",capital,hyphen);
		printf("\n");
		
		
	}
	
	return 0;
	
}
