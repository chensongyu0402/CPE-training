#include<iostream>
#include<cstdio>
#include<set>
#include<queue>
using namespace std;

/*�u�I�b��B�z�L�{���ݭn��j�p*/
 
int main()
{
	/*initial*/ 
    priority_queue<long long,vector<long long>,greater<long long> >pq;//�i�H�Ѥp��j�x�s(�p���b�W) 
    set<long long>s;//�Q��set�h�T�{�O�_������ 
    
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
			if(s.count(y)==0)//�T�{�O�_�����ơA�S������==>�ӼƬ�0 
			{
				pq.push(y);
				s.insert(y);
			}
		}
	}
	
	return 0;
} 
