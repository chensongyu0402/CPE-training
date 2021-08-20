#include<iostream>
#include<cstdio>
using namespace std;

int adj[8][8]=
{
	{0,0,0,0,1,0,0,0},
	{0,0,1,1,0,0,0,0},
	{0,1,0,1,0,0,0,0},
	{0,1,0,0,0,0,0,0},
	{1,0,0,0,0,0,1,1},
	{0,0,0,0,0,0,1,0},
	{0,0,0,0,1,1,0,0},
	{0,0,0,0,1,0,0,0}
};

bool visit[8];

//�q�Ii�}�l DFS 
void DFS(int i)
{
	cout << i <<endl;
	int j;
	
	for(j=0;j<8;j++)
	{
		if(!visit[j]&&adj[i][j])
		{
			visit[j]=true;
			DFS(j);
		} 
	}	
}

void travel()
{
	/*inital*/
	int i,j;
	
	for(j=0;j<8;j++)
	visit[j]=false;
	
	/*��S�����X�L���I��DFS*/
	for(i=0;i<8;i++)
	{
		if(!visit[i])
		{
			visit[i]=true;
			DFS(i);
		}
	}
} 

int main()
{
	travel();
	return 0;
}
