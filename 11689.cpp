#include<stdio.h>
#include<stdlib.h>

int main(){
	
	int number;
	int i;
	
	scanf("%d",&number);
	
	for(i=1;i<=number;i++)
	{
		
		int empty,found,bottle;
		int total=0;
		int q,r,temp;
		
		scanf("%d %d %d",&empty,&found,&bottle);
		
		temp=empty+found;
		
		while(1)
		{
			
			q=temp/bottle;
			r=temp%bottle;
			total+=q;
			temp=q+r;
		    if(q==0)break;
		}
		
		printf("%d\n",total);
		
	}
	
	return 0;
} 
