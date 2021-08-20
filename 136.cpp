#include<iostream>
#include<cstdio>
#include<set>
#include<queue>
using namespace std;

/*優點在於處理過程不需要比大小*/
 
int main()
{
	/*initial*/ 
    priority_queue<long long,vector<long long>,greater<long long> >pq;//可以由小到大儲存(小的在上) 
    set<long long>s;//利用set去確認是否有重複 
    
    int i=0;
    int j;
    int m[3]={2,3,5};
    long long x,y;
    
    pq.push(1);
    s.insert(1);
    
    /*processing*/
    while(1)
    {
    	x=pq.top();
    	i++;
    	
    	if(i==1500)
    	{
    		cout << "The 1500'th ugly number is "<< x <<"."<<endl;
    		break;
		}
		
		pq.pop();
		for(j=0;j<3;j++)
		{
			y=x*m[j];
			if(s.count(y)==0)//確認是否有重複，沒有重複==>個數為0 
			{
				pq.push(y);
				s.insert(y);
			}
		}
	}
	
	return 0;
} 
