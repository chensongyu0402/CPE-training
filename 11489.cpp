#include<stdio.h>
#include<string.h>
#include<stdbool.h>

const int N=1005;
int sum,c[10],length;

/*�p��r�ꤺ����*/

void inpu(){
	
	/*��l��*/ 
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
		sum+=j; //�i�H�Ψӭp��֭p�ȡA���Q�����P�_�O�_��3������ 
		c[j]++; // �u�n�J��0-9�Y�ӼơA�N�barray��+1�A�ӥN��ӼƭȥX�{���� 
	}
	
}

/*�P�_��Ĺ*/

bool judge(){
	
	/*��l��*/
	int t=sum%3;
	int count=0;
	int i;
	int temp=0;
	count=c[3]+c[6]+c[9];
	
	if(length==1)
	return true;
	
	if(t==0)  //3������ 
	{
		if(count%2==1) //�_�Ƭ�SĹ (True) 
		return true;
		else
		return false; //���Ƭ�TĹ (False)
	} 
	else  //���O3������  
	{
		
        for(i=0;i<=9;i++)
		{
			if(c[i]>0) //�O�_���@�ӼƬ�3������ 
			{
				temp=sum-i;
				if(temp%3==0) //�i�H���� 
				{
					if(count%2==1) 
		            return false; //�_�Ƭ�TĹ (False)  
		            else
		            return true; //���Ƭ�SĹ (True)
				}
			}
		}
		
		return false;	//�L�צ������ӼơA���L�k�O3�����ơA��M�N�OTĹ(False) 
	}
	
}

/*main*/

int main(){
	
	/*��l��*/
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
