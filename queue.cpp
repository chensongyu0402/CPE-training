#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

int main()
{
	queue<int>q;
	q.push(1);//[1]
	q.push(2);//[1,2]
	q.push(3);//[1,2,3]
	
	cout << q.front() <<endl;//1
	cout << q.back() <<endl;//3
	cout << q.size() << endl;//3
	
	int a=q.front();//copy
	int &b=q.front();//referencea(±Ä¥Î§O¦W) 
	
	cout << q.front() << " " << &q.front() << endl;
	cout << a << " " << &a <<endl;
	cout << b << " " << &b <<endl;
	
	//print all value
	int size=q.size();
	int i;
	for(i=1;i<size;i++)
	{
		cout << q.front() <<" ";
		q.pop();
	}
	
	cout << q.front() <<endl;
	
	return 0;
}
