#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;

/*create structure of node*/
struct Node{
	
	int value;
	Node*left;
	Node*right;
	
	/*��J�Ȫ���k*/
	/*
	�p�G new Node(-1)
	��value=-1,left=NULL,right=NULL 
	*/ 
	Node(int value): value(value),left(NULL),right(NULL){}

};

/*�T�{�������I������*/
bool isAllNodeHasValue(Node*root){
	
	if(root==NULL)return true;
	if(root->value==-1)return false;
	
	bool hasValue=isAllNodeHasValue(root->left)&&isAllNodeHasValue(root->right);
	
	return hasValue;
}

/*�M��tree*/ 
void destroyTree(Node*root)
{
	if(root==NULL)return;
	
	destroyTree(root->left);
	destroyTree(root->right);
	
	free(root); //�o�Ӫ����n�������free ��onlineJudge�i�H 
}

/*
��X�𪺤��e
�Q��queue 
*/ 
void printTree(Node*root)
{
	
	queue<Node*>nodeQueue;
	nodeQueue.push(root);
	
	bool isPrint=false;
	
	while(!nodeQueue.empty())
	{
		
		if(isPrint)
		cout<<" ";
		
		Node*currentNode=nodeQueue.front();
		nodeQueue.pop();
		
		cout<< currentNode->value;
		
		if(currentNode->left!=NULL)nodeQueue.push(currentNode->left);
		if(currentNode->right!=NULL)nodeQueue.push(currentNode->right);
		
		isPrint=true;
		
	}
	
	cout << endl;
	
}

int main()
{
	/*initial*/
	string node;
	Node*tree=NULL;
	bool isValid=true; //�ΨӧP�_���S�����ƿ�J�����D 
	
	/*process*/
	while(cin >> node)
	{
		
		/*�J�찱��Ÿ��P�_�O�_���@�ʾ�*/
		if(node=="()")
		{
			if(isValid&&isAllNodeHasValue(tree))
			printTree(tree);
			else
			cout << "not complete" << endl;
			
			destroyTree(tree);
			tree=NULL;
			isValid=true;
			continue;
		}
		
		if(!isValid)continue;
		
		int value=0;
		int index;
		
		/*����*/ 
		for(index=1;node[index]!=',';index++)
		{
			value=value*10+(node[index]-'0');
		}
		
		/*initial*/ 
		if(tree==NULL)tree=new Node(-1);
		
		Node*currentNode=tree;
		
		/*
		�B�zLR���D
		�ǥѧ�g�L���I���إ�Node(-1)�Ӱ��O��
		�]���̫�n�T�{�Ҧ��O���W�������n���Ȥ~�� 
		*/
		for(++index;node[index]!=')';index++)
		{
			
			if(node[index]=='L')
			{
				if(currentNode->left==NULL)currentNode->left=new Node(-1);
				currentNode=currentNode->left;
			}	
			else if(node[index]=='R')
			{
				if(currentNode->right==NULL)currentNode->right=new Node(-1);
				currentNode=currentNode->right;
			} 
		}
		
		/*�p�G�쥻�N���Ȫ��ܡA�N�O���X�k*/ 
		if(currentNode->value!=-1)
		{
			isValid=false;
			continue;
		}
		
		currentNode->value=value;
		
	}
	
	return 0;
	
}
