#include<iostream>
#include<cstdio>
using namespace std;

/*struct*/

struct Node
{
	
	int number;
	Node*next;
	
	/*µ¥¦P©óNode(int number): number(number),next(NULL){}*/
	Node(int number)
	{
		this->number=number;
		this->next=NULL;
	} 

};

/*initial*/
Node*head=NULL;

/*print*/
void printALL()
{
	
	Node*temp=head;
	
	cout << "Number:" << endl;
	
	while(temp->next!=NULL)
	{
		
		cout<< temp->number<<"->";
		temp=temp->next;
		
	}
	
	cout << temp->number<<endl;
	
}

/*create New Number*/
void createNewDataAtLast(int number)
{
	
	Node*temp=head;
	
	if(head==NULL)
	head=new Node(number);
	else
	{
		while(temp->next!=NULL)
	    temp=temp->next;
		
		temp->next=new Node(number);
	}
}


/*main*/
int main()
{
	
	while(1)
	{
		int choice;
		
		cout << "Choose the function you want:"<<endl;
	    cout << "1. Add data" << endl;
        cout << "2. Print All datas" << endl;
        cout << "3. Exit" << endl;
        
        cin >> choice;
        
        switch(choice)
        {
        	case 1:
        		int number;
        		cout<<"Input Number:";
        		cin >> number;
        		createNewDataAtLast(number);
        		cout << "Add number successfully"<<endl;
        		break;
        	case 2:
        		printALL();
        	case 3:
        		exit(0);
        	default:
        		cout << "Error!"<<endl;
        		break;	
		}
		
		cout<< endl;
	}
	
	return 0;
	
}
