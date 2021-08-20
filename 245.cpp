#include<iostream>
#include<string.h>
#include<cstdio>
using namespace std;

/*�إ�Linklist�����c*/ 
struct Node
{
	string word;
	Node*next;
};

/*�P�_�O�_���Ʀr*/ 
bool is_number(char ch)
{
	return (ch>='0') && (ch<='9');
}

/*�P�_�O�_���r��*/ 
bool is_alphabet(char ch)
{
	return ('a'<=ch && ch <= 'z')||('A'<=ch && ch <= 'Z');
}

/*�Q��getchar()Ū���C��character*/ 

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
			
			/*��*/
			for(i=1;i<num;i++)
			{
				prev=now;
				now=now->next;
			}
			
			cout << now->word;
			
			/*���쪺�A��b�Ĥ@��*/ 
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
			
			/*�q���r�����}�lŪ��character*/ 
			while(is_alphabet(ch))
			{
				word+=ch;
			    ch=getchar();
			}
			
			cout << word;
			
			/*�A�Nstring��JLinkList��*/
			Node*n=new Node;
			n->word=word;
			n->next=head;
			head=n;
		}
		else
		{
			/*��L�Ÿ��A������X*/ 
			putchar(ch);
			ch=getchar();
		}
		
	}
	
	return 0;
} 
