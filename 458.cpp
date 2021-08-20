#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
 
int main()
{
	char ch;
	
	while((ch=getchar())!=EOF)
	{
		if(ch=='\n')
		putchar('\n');
		else
		putchar(ch-7);
    }
    
	return 0;
}
