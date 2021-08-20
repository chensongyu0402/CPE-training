#include<iostream>
#include<string>
#include<cstdio>
#include<queue>
using namespace std;

/*�إ�struct*/
struct POS
{
	int x;
	int y;
	int step;
};

/*�U�ب��k(�i�H�Q���H�Ѫ� "��")*/
int direction[8][2]=
{
	{1,2},
	{2,1},
	{2,-1},
	{1,-2},
	{-1,-2},
	{-2,-1},
	{-2,1},
	{-1,2}
};

/*BFS�i�H�Ψӭp��unweight��shortest path*/
/*BFS��queue�B�z*/
int BFS(POS src,POS dst)
{
	
	if(src.x==dst.x&&src.y==dst.y)
	return src.step;
	
	bool isVisited[8][8]={ false };
	
	queue<POS>que;
	que.push(src);
	
	while(!que.empty())
    {
    	
    	POS cur=que.front();
    	isVisited[cur.x][cur.y]=true;
    	que.pop();
    	
        POS next;
        int i;
        
        /*��U�ر���(�@8��)���|�ҥX�ӡA�A�Q��if and else �D��*/ 
        for(i=0;i<8;i++)
        {
        	next.x=cur.x+direction[i][0];
        	next.y=cur.y+direction[i][1];
        	next.step=cur.step+1;
        	
        	if(next.x>=0 && next.x<8 && next.y>=0 && next.y<8 && !isVisited[next.x][next.y])
        	{
        		isVisited[next.x][next.y]=true;
        		
        		if(next.x==dst.x&&next.y==dst.y)
        		return next.step;
        		
        		que.push(next);
			}
		}
    	
    }
    
    return 0;
	
}


int main()
{
	string src1,dst1;
	POS src,dst;
	int step;
    
    while(cin >> src1 >>dst1)
    {
    	src.x=src1[0]-'a';//�]���Ĥ@�Ӭ�a 
    	src.y=src1[1]-'1';//�]���Ĥ@�Ӭ�1
    	src.step=0;
    	dst.x=dst1[0]-'a';
    	dst.y=dst1[1]-'1';
    	
    	
    	cout << "To get from "<< src1 <<" to " << dst1 <<" takes " << BFS(src,dst) <<" knight moves."<<endl;
	}
	
	return 0;
}

