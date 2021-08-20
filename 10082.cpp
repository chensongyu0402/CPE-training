#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;

string type="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

int inString(char ch,string type)
{
	int i;
	
	for(i=0;i<type.size();i++)
	{
		if(ch==type[i]&&(ch!='Q')&&(ch!='A')&&(ch!='Z')&&(ch!='`'))
		{
			return i;
		    break;
		}
	}
	
	return 0;

}

int main()
{
	char ch;
	int i;
	
	while((ch=getchar())!=EOF)
	{
		i=inString(ch,type);
		
		if(i!=0)
		putchar(type[i-1]);
		else
		putchar(ch);
	}
	
	return 0;

}
