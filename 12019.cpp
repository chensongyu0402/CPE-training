#include<stdio.h>
#include<stdlib.h>

int main(){
	
    char weeks[7][10]={"Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"};
    int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    
    int number=0;
    int months=0;
    int days=0;
    int i,j;
    

    scanf("%d",&number);
    char ans[number];
    

    for(i=0;i<number;i++)
    {
    	int sum=0;
    	scanf("%d %d",&months,&days);
    	for(j=0;j<months-1;j++)
    	{
    		sum+=month[j];
		}
    	sum=sum+days-1;
		printf("%s\n",weeks[sum%7]);
	}
	

} 
