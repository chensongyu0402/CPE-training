#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

//example
int adj[5][5]=
{
	{0,1,1,0,0},
	{1,0,0,1,0},
	{1,0,0,0,1},
	{0,1,0,0,0},
	{0,0,1,0,0}
};

bool visit[5];

void BFS()
{
	/*initial*/
	queue<int>q;
	int i,j;
	
	for(i=0;i<5;i++)
	visit[i]=false;
	
	/*processing*/
	for(i=0;i<5;i++)//�]�����@�w�u���@��component�A�ҥH�C���I���n�h�T�{ 
	{
		if(!visit[i])
		{
			/*start point*/
			q.push(i);
			visit[i]=true;
			
			while(!q.empty())
			{
				int k=q.front();
				cout << k <<endl;
				q.pop();
				
				for(j=0;j<5;j++)
				{
					if(adj[k][j]&&!visit[j])
					{
						q.push(j);
						visit[j]=true;
					}
				}
			}
		}
	}
	
}

int main()
{
	BFS();
	return 0;
}
