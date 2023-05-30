#include<iostream>
#include<math.h>
using namespace std;

class bnode
{
	int data;
	bnode *left;
	bnode *right;
	bnode *parent;
	friend class bst;
	
};

class bst{
	public:
		int n,x;
		bnode *root;
		bnode *parent;
		bst()
		{
			root=NULL;
		}
		bnode *getnode(int ndata)
		{
			bnode *temp=new bnode;
			temp->data=ndata;
			temp->left=NULL;
			temp->right=NULL;
			return temp;	
		}


	bnode *insert(bnode *temp, int in_data)
	{
		if(temp==NULL){
			temp=getnode(in_data);
		}
		else if(temp->data>in_data){
			temp->left=insert(temp->left,in_data);
		}
		else if(temp->data<in_data)
		{
			temp->right=insert(temp->right,in_data);
		}
		else
		{
			cout<<"Already existing data"<<endl;
		}
		return temp;
		
	}
	
	void input()
	{
		cout<<"Enter the number of elements in the BST = ";
		cin>>n;
		for (int i=0;i<n;i++)
		{
			cout<<"Number = ";
			cin>>x;
			root=insert(root,x);
		}
	}
	
	void display()
	{
		int ch;
		do{
			cout<<endl<<"----Menu----"<<endl;
			cout<<endl<<"Select Option"<<endl;
			cout<<"Inorder Traversal"<<endl;
			cout<<"Postorder Traversal"<<endl;	
			cout<<"Preorder"<<endl;	
			cout<<"Min term"<<endl;	
			cout<<"Max term"<<endl;	
			cout<<"Depth of tree"<<endl;	
			cout<<"Search an element"<<endl;	
			cout<<"Mirror Tree"<<endl;	
			cout<<"Exit"<<endl;
			cin>>ch;
			switch(ch){
				case 1:
					inorder(root);
					cout<<endl;
					break;
				case 2:
					postorder(root);
					cout<<endl;
					break;
				case 3:
					preorder(root);
					cout<<endl;
					break;
				case 4:
					min(root);
					cout<<endl;
					break;
				case 5:
					maxi(root);
					cout<<endl;
					break;
				case 6:
					cout<<depth(root)<<endl;
					break;
				case 7:
					int key;
					cout<<"Enter key to search";
					cin>>key;
					search(root,key,parent);
					cout<<endl;
					break;
				case 8:
					mirror(root);
					inorder(root);
					break;
			}	
		}while(ch!=9);
	}
	
	void inorder(bnode *temp)
	{
		if(temp!=NULL)
		{
			inorder(temp->left);
			cout<<temp->data<<" ";
			inorder(temp->right);
		}
	}
	
	void postorder(bnode *temp)
	{
		if(temp!=NULL)
		{
			postorder(temp->left);
			postorder(temp->right);
			cout<<temp->data<<endl;
		}
	}
	
	void preorder(bnode *temp)
	{
		if(temp!=NULL)
		{
			cout<<temp->data<<endl;
			preorder(temp->left);
			preorder(temp->right);
		}
		
	}
	
	void min (bnode *temp){
		while(temp->left !=NULL)
		{
			temp=temp->left;
		}
		cout<<"Minimum Value :"<<temp->data;
	}
	
	void maxi(bnode *temp){
		while(temp->right!=NULL)
		{
			temp=temp->right;
		}
		cout<<"Maximum Value :"<<temp->data;
	}
	
	int depth(bnode *temp){
		if(temp==NULL){
			return 0 ;
		}
		return(max((depth(temp->left)),depth(temp->right))+1);
	}
	
	void mirror(bnode *temp)
	{
		if(temp==NULL){
			return;
		}
		else
		{
			bnode *ptr;
			mirror(temp->left);
			mirror(temp->right);
			ptr=temp->left;
			temp->left=temp->right;
			temp->right=ptr;
		}
	}
	
	void search(bnode *temp,int key,bnode *parent)
	{
		int count=0;
		while(temp!=NULL){
			if(temp->data ==key)
			{
				cout<<"Search after pass : "<<count<<endl;
				cout<<"\n Element "<<temp->data<<"is present and its parent is"<<parent->data;
		
			}
			parent=temp;
			if(temp->data>key)
			{
				temp=temp->left;
			}
			else
			{
				temp=temp->right;
			}
			count++;
		}
	}
};

int main(){
	bst obj;
	obj.input();
	obj.display();
	return 0;
}



