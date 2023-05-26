#include <iostream>
using namespace std;
int top = -1;
int top1 = -1;
int top2 = -1;

struct tree {
	char data;
	tree *left;
	tree *right;
};
class Stack {
	public:
		tree *root = NULL;
		int count;
		int j;
		tree *st[10];
		tree *s[10];
		tree *st1[10];
		string exp;
		void push(tree *root) {
			top++;
			st[top] = root;
		}
		tree *pop() {
			tree *ptr = st[top];
			top--;
			return ptr;
		}
		void push1(tree *root) {
			top1++;
			s[top1] = root;
		}
		void pop1() {
			top1--;
		}
		void push2(tree *root) {

			top2++;
			st1[top2] = root;
		}
		void pop2() {
			top2--;
		}
		void inorder(tree *root) {
			if(root != NULL) {
				inorder(root -> left);
				cout<<root -> data;
				inorder(root -> right);
			}
		}
		void postorder(tree *root) {
			if(root != NULL) {
				inorder(root -> left);
				inorder(root -> right);
				cout<<root -> data;
			}
		}

		void process();
		void postorderT(tree *root);
		void del(tree *root);
		tree *create(char data) {
			tree *newnode = new(struct tree);
			newnode -> data = data;
			newnode -> left = NULL;
			newnode -> right = NULL;
			return newnode;
		}
};
void Stack :: postorderT(tree *root) {
	if(root == NULL)
		return;
	push1(root);

	tree *ntr;
	while(top1 != -1) {
		ntr = s[top1];
		pop1();
		push2(ntr);
		if(ntr -> left)
			push1(ntr -> left);
		if(ntr -> right)
			push1(ntr -> right);
	}
	while(top2 != -1) {
		ntr = st1[top2];
		pop2();
		cout<<ntr -> data;
	}
}
void Stack :: del(tree *root) {
	if(root != NULL) {
		del(root -> left);
		del(root -> right);
		cout<<endl;
		cout<<"The deleted data is"<<root -> data<<endl;
		delete root;
	}
}
void Stack :: process() {
	cout<<"Enter the Prefix Expression"<<endl;
	cin>>exp;
	count = 0;
	for(int i = 0; exp[i]; i++) {
		count++;
	}
	j = count - 1;
	while(j >= 0) {
		if(exp[j] >= '0' && exp[j] <= '9') {
			tree *node = create(exp[j]);
			push(node);
		}

		else {
			tree *temp = pop();
			tree *temp1 = pop();
			tree *newnode2 = create(exp[j]);
			newnode2 -> left = temp;
			newnode2 -> right = temp1;
			push(newnode2);
		}
		j--;
	}
	tree *newnode1 = pop();
	inorder(newnode1);
	cout<<endl;
	cout<<"The postorder without recurssion is: ";
	postorderT(newnode1);
	del(newnode1);
}
int main() {
	Stack st;
	st.process();
	return 0;
}