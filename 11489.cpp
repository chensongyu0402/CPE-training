#include<stdio.h>
#include<string.h>
#include<stdbool.h>

const int N=1005;
int sum,c[10],length;

/*璸衡﹃ず场*/

void inpu(){
	
	/*﹍*/ 
	int i;
	sum=0;
	memset(c,0,sizeof(c));
	
	/*input*/
	char str[N];
	scanf("%s",str);
	
	length=strlen(str);
	
	for(i=0;i<length;i++)
	{
		int j=str[i]-'0';
		sum+=j; //ノㄓ璸衡仓璸Τ尿耞琌3计 
		c[j]++; // 璶笿0-9琘计碞array讽い+1ㄓ赣计瞷Ω计 
	}
	
}

/*耞街墓*/

bool judge(){
	
	/*﹍*/
	int t=sum%3;
	int count=0;
	int i;
	int temp=0;
	count=c[3]+c[6]+c[9];
	
	if(length==1)
	return true;
	
	if(t==0)  //3计 
	{
		if(count%2==1) //计S墓 (True) 
		return true;
		else
		return false; //案计T墓 (False)
	} 
	else  //ぃ琌3计  
	{
		
        for(i=0;i<=9;i++)
		{
			if(c[i]>0) //琌Ι计3计 
			{
				temp=sum-i;
				if(temp%3==0) //杠 
				{
					if(count%2==1) 
		            return false; //计T墓 (False)  
		            else
		            return true; //案计S墓 (True)
				}
			}
		}
		
		return false;	//礚阶Ι奔计常礚猭琌3计讽礛碞琌T墓(False) 
	}
	
}

/*main*/

int main(){
	
	/*﹍*/
	int number;
	int k;
	bool result;
	
	/*input*/
	scanf("%d",&number);
	
	for(k=1;k<=number;k++)
	{
		
		inpu();
		result=judge();
		
		if(result==true)
		printf("Case %d: S\n",k);
		else
		printf("Case %d: T\n",k);
		
	}
	
	return 0;
} 
