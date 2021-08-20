#include <iostream>
using namespace std;

/*
example:
n=5,k=2
initial:1�B2�B3�B4�B5
�ѤUn-1�]�N�O4�ӤH:3�B4�B5�B1
�ѤU3�ӤH:5�B1�B3
�ѤU2�ӤH:3�B5
�̫�:3 is winner

explanation: 
josephus(n,k)��ܭƦs���H
josephus(n-1,k)��n-1�ӤH���Ʀs���H
�]���Ʀs���H�̲ץ������M�������U�Ʋ�k-1�ӤH
�ҥH josephus(n-1,k)+(k-1)
�S�]���`�@��N
�ҥH (josephus(n-1,k)+(k-1))%n
�̫�n���D�Ʀs�̬O��
�ҥH (josephus(n-1,k)+(k-1))%n+1

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


