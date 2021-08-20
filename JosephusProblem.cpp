#include <iostream>
using namespace std;

/*
example:
n=5,k=2
initial:1、2、3、4、5
剩下n-1也就是4個人:3、4、5、1
剩下3個人:5、1、3
剩下2個人:3、5
最後:3 is winner

explanation: 
josephus(n,k)表示倖存的人
josephus(n-1,k)表n-1個人當中倖存的人
因為倖存的人最終必須拿刀殺死往下數第k-1個人
所以 josephus(n-1,k)+(k-1)
又因為總共為N
所以 (josephus(n-1,k)+(k-1))%n
最後要知道倖存者是誰
所以 (josephus(n-1,k)+(k-1))%n+1

*/ 
int josephus(int n, int k)
{
	if (n == 1)
		return 1;
	else
		return (josephus(n - 1, k) + k-1) % n+1;
}

int main()
{
	int n = 166;
	int k = 166;
	cout << "The chosen place is " << josephus(n, k);
	return 0;
}


