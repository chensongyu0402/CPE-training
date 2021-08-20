#include<iostream>
#include<cstdio>
using namespace std; 

long long funt(long long B,long long P,long long M)
{
	if(P==0)
	return 1;
	else if(P==1)
	return B%M;
    else
    {
    	if(P%2==0)
    	return funt(B,P/2,M)*funt(B,P/2,M) %M;
    	else
    	return funt(B,P/2,M)*funt(B,P/2,M)*B %M;
	}
}

int main()
{
		
	long long B,P,M;
	
    while(cin >> B >> P >> M)
    cout << funt(B,P,M) <<endl;
	
	return 0;
	
}


