#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;

int main()
{
	/*initial*/
	int i,j;
	stack<int>st1;
	
	//input element
	for(i=0;i<5;i++)
	st1.push(i);
	
	cout << st1.top() << endl;//stack最上面
	cout << st1.size() << endl;//stack元素個數
	
	/*判斷是否為空*/
	if(!st1.empty())
	cout << "stack is not empty" << endl;
	else
	cout << "stack is empty" << endl;
	
	//兩個stack互換
	stack<int>st2;
	
	for(i=0;i<10;i++)
	st2.push(i);
	
	swap(st1,st2);
	
	cout << "st1:";
	
	while(!st1.empty())
	{
		j=st1.top();
		cout << j << " ";
		st1.pop();
	}
	
	cout << endl;	
	
	cout << "st2:";
	
	while(!st2.empty())
	{
		j=st2.top();
		cout << j << " ";
		st2.pop();
	}
	
	cout << endl;
	
	return 0;
	
} 
