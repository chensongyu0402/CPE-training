#include<iostream>
#include<cstdio>
#include<string>
#include<queue>
using namespace std;

/*create structure*/
struct Point{
	int l;
	int r;
	int c;
	int value;
	
	Point(int l,int r,int c,int value):l(l),r(r),c(c),value(value){}
}; 

/*BFS找unweight最短距離*/
int BFS(string map[][35],
        int L,int R,int C,
		int pos_l,int pos_r,int pos_c)
{
	/*BFS用queue*/
	queue<Point>BFS_mem;
	BFS_mem.push(Point(pos_l,pos_r,pos_c,0));
	
	while(!BFS_mem.empty())
	{
		
		Point p=BFS_mem.front();
		
		/*超出邊界的不要*/
		if(p.l<0||p.r<0||p.c<0||
		   p.l>=L||p.r>=R||p.c>=C)
		{
			BFS_mem.pop();
			continue;
		}
		
		/*遇到出口*/ 
		if(map[p.l][p.r][p.c]=='E')
		{
			return p.value;
		}
		
		/*遇到#直接放棄該路線*/ 
		if(map[p.l][p.r][p.c]!='.')
		{
			BFS_mem.pop();
			continue;
		}
		
		/*把走過的設為#*/ 
		map[p.l][p.r][p.c]='#';
		
		/*往四面趴放走，所以類似BFS*/ 
		BFS_mem.push(Point(p.l+1,p.r,p.c,p.value+1));
	    BFS_mem.push(Point(p.l-1,p.r,p.c,p.value+1));
	    BFS_mem.push(Point(p.l,p.r+1,p.c,p.value+1));
	    BFS_mem.push(Point(p.l,p.r-1,p.c,p.value+1));
	    BFS_mem.push(Point(p.l,p.r,p.c+1,p.value+1));
	    BFS_mem.push(Point(p.l,p.r,p.c-1,p.value+1));
	    
	    BFS_mem.pop();
	    
	}
	
	return -1;
	
}

int main()
{
	int L,R,C;
	
	while(cin>>L>>R>>C)
	{
		
		if(L==0&&R==0&&C==0)
		break;
		
		string map[35][35];
		
		int start_l,start_r,start_c;
		int i,j,k;
		
		for(i=0;i<L;i++)
		{
			for(j=0;j<R;j++)
			{
				cin >> map[i][j];
				
				for(k=0;k<C;k++)
				{
					/*找起點*/ 
					if(map[i][j][k]=='S')
					{
						start_l=i;
						start_r=j;
						start_c=k;
						map[i][j][k]='.';
					}
				}
			}
		}
		
		int ans=BFS(map,L,R,C,start_l,start_r,start_c);
	
	    if(ans==-1)
	    cout << "Trapped!" << endl;
	    else
	    cout <<"Escaped in "<< ans << " minute(s)." << endl;
		
	}
	
	return 0;  
}
