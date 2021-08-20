#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

/*
idea:
對四個方位做RL處理 
*/

int main()
{
  int max_x,max_y;
  
  while(cin >> max_x >> max_y)
  {
  	int lost_x[max_x+1];
    int lost_y[max_y+1];
    int lost=0;
  	
  	int initial_x,initial_y;
	char orientation;
	
  	while(cin >> initial_x >> initial_y >> orientation)
  	{
	  string input;
	  int i=0;
	  int current_x=initial_x;
	  int current_y=initial_y;
	  int lost=0;
	  cin >> input;
	  
	  while(i<input.size())
	  {
		switch(orientation)
		{
			case 'N':
				switch(input[i])
				{
					case 'R':
						orientation='E';
				        i++;
				        break;
					case 'L':
						orientation='W';
				        i++;
				        break;
					case 'F':
						if((current_y+1)>max_y)
						{
							if(lost_x[current_x]==1&&lost_y[current_y]==1)
							{
					            i++;
				                break;
							}
							else
							{
								lost_x[current_x]=1;
								lost_y[current_y]=1;
								lost=1;
								break;
							}
						}
						current_y++;
					    i++;
				        break;
			    }
			    break;
		    case 'S':
				switch(input[i])
				{
					case 'R':
						orientation='W';
						i++;
						break;
					case 'L':
						orientation='E';
						i++;
						break;
					case 'F':
						if((current_y-1)<0)
						{
							if(lost_x[current_x]==1&&lost_y[current_y]==1)
							{
					            i++;
				                break;
							}
							else
							{
								lost_x[current_x]=1;
								lost_y[current_y]=1;
								lost=1;
								break;
							}
						}
						current_y--;
					    i++;
				        break;
				}
				break;
						
			case 'E':
				switch(input[i])
				{
					case 'R':
						orientation='S';
						i++;
						break;
					case 'L':
						orientation='N';
						i++;
						break;
					case 'F':
						if((current_x+1)>max_x)
						{
							if(lost_x[current_x]==1&&lost_y[current_y]==1)
							{
					            i++;
				                break;
							}
							else
							{
								lost_x[current_x]=1;
								lost_y[current_y]=1;
								lost=1;
								break;
							}
						}
						current_x++;
					    i++;
				        break;
			    }
			    break;
						
			case 'W':
				switch(input[i])
				{
					case 'R':
						orientation='N';
						i++;
						break;
					case 'L':
						orientation='S';
						i++;
						break;
					case 'F':
						if((current_x-1)<0)
						{
							if(lost_x[current_x]==1&&lost_y[current_y]==1)
							{
					            i++;
				                break;
							}
							else
							{
								lost_x[current_x]=1;
								lost_y[current_y]=1;
								lost=1;
								break;
							}
						}
						current_x--;
					    i++;
				        break;
			    }
			    break;
	    }
	    
	   if(lost==1)
	   {
	   	 cout << current_x <<" "<< current_y <<" "<< orientation <<" "<<"LOST" <<endl;
	   	 break;
	   }
	   
    }
    
    if(lost==0)
	{
	   	cout << current_x <<" "<< current_y <<" "<< orientation <<endl;
	}
  }
}
return 0;
} 
