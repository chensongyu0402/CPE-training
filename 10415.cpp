#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

/*建立table*/
char table[14][11]={
	"0111001111",
	"0111001110",
	"0111001100",
	"0111001000",
	"0111000000",
	"0110000000",
	"0100000000",
	"0010000000",
	"1111001110",
	"1111001100",
	"1111001000",
	"1111000000",
	"1110000000",
	"1100000000"};
		
/*main*/		
int main()
{
	
	/*cahr mapped table index*/
	int mapped[128];
    mapped['c']=0,mapped['d']=1;
    mapped['e']=2,mapped['f']=3;
    mapped['g']=4,mapped['a']=5;
    mapped['b']=6,mapped['C']=7;
    mapped['D']=8,mapped['E']=9;
    mapped['F']=10,mapped['G']=11;
    mapped['A']=12,mapped['B']=13;
    
    /*參數*/
	int number;
	int i,j,k;
	char input[205];
	int press[10];
	int len;
	
	cin >> number;
	
	cin.ignore();
	
    for(i=0;i<number;i++)
    {	
    
        string str;
		getline(cin,str);
		strcpy(input,str.c_str());
		
		len=strlen(input);
    	  	
        if(len==0)//有可能全是空的 
		{
			for(j=0;j<10;j++)
		    press[j]=0;
		} 
		else
		
		{
        
		for(j=0;j<len;j++)
		{
			if(j==0)//一開始直接把第一步的按鍵當初始值 
			{
				for(k=0;k<10;k++)
				{
				    if(table[mapped[input[j]]][k]=='1')
				    press[k]=1;
				    else
				    press[k]=0;
				}
			}
			else //確認現在這個是否比前面多一個按鍵，有表示要按 
			
			{
				for(k=0;k<10;k++)
				{
					if(table[mapped[input[j]]][k] > table[mapped[input[j-1]]][k])
					press[k]++;
				}
				 
			}
			
		}
		
	    }
		
		/*output*/ 
		for(j=0;j<10;j++)
		{
			if(j==9)
			{
				cout <<press[j];
				break;
			}
			
			cout <<press[j]<<" " ;
		}
		
		cout <<endl;
		
	}
	
	return 0;
	
}
