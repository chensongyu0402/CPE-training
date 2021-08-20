#include<iostream>
#include<string.h>
#include<cstdio>
using namespace std;

/*建立Linklist的結構*/ 
struct Node
{
	string word;
	Node*next;
};

/*判斷是否為數字*/ 
bool is_number(char ch)
{
	return (ch>='0') && (ch<='9');
}

/*判斷是否為字母*/ 
bool is_alphabet(char ch)
{
	return ('a'<=ch && ch <= 'z')||('A'<=ch && ch <= 'Z');
}

/*利用getchar()讀取每個character*/ 

int main()
{
	Node*head=NULL;
	string word;
	char ch;
	
	ch=getchar();
	
	while(1)
	{
		if(is_number(ch))
		{
			if(ch=='0')break;
			
			int num=0;
			
			while(is_number(ch))
			{
				num=num*10+(ch-'0');
				ch=getchar();
			}
			
			Node*now=head;
			Node*prev=NULL;
			int i;
			
			/*找*/
			for(i=1;i<num;i++)
			{
				prev=now;
				now=now->next;
			}
			
			cout << now->word;
			
			/*把找到的，放在第一個*/ 
			if(now!=head)
			{
				prev->next=now->next;
				now->next=head;
				head=now;
			}
					
		}
		else if(is_alphabet(ch))
		{
			string word;
			
			/*從有字母的開始讀取character*/ 
			while(is_alphabet(ch))
			{
				word+=ch;
			    ch=getchar();
			}
			
			cout << word;
			
			/*再將string放入LinkList中*/
			Node*n=new Node;
			n->word=word;
			n->next=head;
			head=n;
		}
		else
		{
			/*其他符號，直接輸出*/ 
			putchar(ch);
			ch=getchar();
		}
		
	}
	
	return 0;
} 
