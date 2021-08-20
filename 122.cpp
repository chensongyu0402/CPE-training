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
	
	/*輸入值的方法*/
	/*
	如果 new Node(-1)
	表value=-1,left=NULL,right=NULL 
	*/ 
	Node(int value): value(value),left(NULL),right(NULL){}

};

/*確認全部的點都有值*/
bool isAllNodeHasValue(Node*root){
	
	if(root==NULL)return true;
	if(root->value==-1)return false;
	
	bool hasValue=isAllNodeHasValue(root->left)&&isAllNodeHasValue(root->right);
	
	return hasValue;
}

/*清空tree*/ 
void destroyTree(Node*root)
{
	if(root==NULL)return;
	
	destroyTree(root->left);
	destroyTree(root->right);
	
	free(root); //這個版本好像不能用free 但onlineJudge可以 
}

/*
輸出樹的內容
利用queue 
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
	bool isValid=true; //用來判斷有沒有重複輸入的問題 
	
	/*process*/
	while(cin >> node)
	{
		
		/*遇到停止符號判斷是否為一棵樹*/
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
		
		/*取值*/ 
		for(index=1;node[index]!=',';index++)
		{
			value=value*10+(node[index]-'0');
		}
		
		/*initial*/ 
		if(tree==NULL)tree=new Node(-1);
		
		Node*currentNode=tree;
		
		/*
		處理LR問題
		藉由把經過的點都建立Node(-1)來做記號
		因為最後要確認所有記號上都必須要有值才行 
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
		
		/*如果原本就有值的話，就是不合法*/ 
		if(currentNode->value!=-1)
		{
			isValid=false;
			continue;
		}
		
		currentNode->value=value;
		
	}
	
	return 0;
	
}
