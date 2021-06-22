#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

/*參數*/
char ans[110][150],test[110][150];
char num_1[15000],num_2[15000]; //store interger
int num_ans,num_test; //length

/*Accept*/
int is_ac()
{
	int i;
	
	if(num_ans!=num_test)
	return 0;
    
    /*一個個比對看是否完全一樣*/
    for(i=0;i<num_ans;i++)
        if(strcmp(ans[i],test[i])!=0)
        return 0;
    
    return 1;
	
}

/*Presentation Error*/ 
int is_pe()
{
	int i,j;
	int len_1=0,len_2=0,len=0;
	
	for(i=0;i<num_ans;i++)
	{
		len=strlen(ans[i]);
		for(j=0;j<len;j++)
		    if(ans[i][j]>='0'&&ans[i][j]<='9')
		    num_1[len_1++]=ans[i][j];
	}
	
	num_1[len_1]='\0';
	
	for(i=0;i<num_test;i++)
	{
		len=strlen(test[i]);
		for(j=0;j<len;j++)
		    if(test[i][j]>='0'&&test[i][j]<='9')
		    num_2[len_2++]=test[i][j];
	}
	
	num_2[len_2]='\0';
	
	if(strcmp(num_1,num_2)==0)
	return 1;
	
	return 0;
}

/*main*/

int main(){
	
	int length,i,flag,num=1;
	
	while(cin>>num_ans&&num_ans)
	{
		
		/*input*/
		cin.ignore();
		flag=1;
		
		for(i=0;i<num_ans;i++)
		{
			string str;
			getline(cin,str);
			length+=str.length();
			strcpy(ans[i],str.c_str());
		}
		
		cin >>num_test;
		cin.ignore();
		
		/*judge*/
		for(i=0;i<num_test;i++)
		{
			string str;
			getline(cin,str);
			strcpy(test[i],str.c_str());
		}
		
		if(is_ac())
		flag=1;
		else
		{
			if(is_pe())
			flag=2;
			else
			flag=3;
		}
		
		cout<<"Run #"<< num++ <<":";
		if(flag==1)
		cout <<"Accepted"<<length<<endl;
		else if(flag==2)
		cout <<"Presentation Error"<<length<<endl;
		else
		cout <<"Wrong Answer"<<length<<endl;
	}
	
	return 0;
}
