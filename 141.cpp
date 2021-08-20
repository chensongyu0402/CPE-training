#include<iostream>
#include<map>
#include<string>
#include<cstdio>
using namespace std;

map<string,int>mymap;
string str,str1,str2,str3;
int n;

void rot1()
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		    str1[n*j+n-i-1]=str[n*i+j];
}

void rot2()
{
	int i,j;
	for(i=0;i<n;i++)
	    for(j=0;j<n;j++)
	        str2[n*(n-i-1)+n-j-1]=str[n*i+j];
}

void rot3()
{
	int i,j;
	for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            str3[n*(n-j-1)+i]=str[n*i+j];
}

int main()
{
	int a,b,temp,sign;
	char c;
	
	while(cin>>n)
	{
		if(n==0)
		break;
		
		mymap.clear();
		temp=0;
		sign=0;
		str='0';
		
		int k;
		for(k=0;k<n*n;k++)
		str.push_back('0');
		
		str1=str;
		str2=str;
		str3=str;
		
		for(k=0;k<2*n;k++)
		{
			cin >>a >>b >>c;
			
			if(c=='+')str[(a-1)*n+b-1]='1';
			else if(c=='-')str[(a-1)*n+b-1]='0';
			
			rot1();
			rot2();
			rot3();
			
			mymap[str]++;
			if(str1!=str)mymap[str1]++;
			if(str2!=str1&&str2!=str)mymap[str2]++;
			if(str3!=str1&&str3!=str2&&str3!=str)mymap[str3]++;
			
			if(mymap[str]>1&&sign==0)
			{
				temp=k;
				sign=1;
			}
		}
		
		if(sign==0)
		cout << "Draw" << endl;
		else
		cout <<"Player "<< (temp+1)%2+1 <<" wins on move "<<temp+1<<endl;
	}
	
	return 0;
}
