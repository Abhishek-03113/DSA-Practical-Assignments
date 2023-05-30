#include<iostream>
using namespace std;
class graph {
		int m[20][20];
		int visited[20],n;
	public:
		void accept();
		void display();
		void dfs(int);
		void dfsnr(int);
		int returnN() {
			return n;
		}
};
class stack {
		int st[20];
		int top;
	public:
		stack() {
			top=-1;

		}
		bool isEmpty() {
			if(top==-1) {
				return true;
			} else {
				return false;
			}
		}
		bool isFull() {
			if(top==19) {
				return true;
			} else {
				return false;
			}
		}
		void push(int z) {
			if(isFull()) {
				cout<<"\nOverflow!";
				return;
			} else {
				st[++top]=z;
			}
		}
		int pop() {
			if(isEmpty()) {
				cout<<"\nUnderflow!";
				return -1;
			} else {
				return(st[top--]);
			}
		}

};
void graph::accept() {
	cout<<"\nEnter the no of vertices=";
	cin>>n;
	for(int i=1; i<=n; i++) {
		visited[i]=0;
	}
	cout<<"\nEnter the adjacency Matrix:";
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			cin>>m[i][j];
		}
	}
}

void graph::display() {
	cout<<"\nThe adjacency matrix is=";
	for(int i=1; i<=n; i++) {
		cout<<"\n";
		for(int j=1; j<=n; j++) {
			cout<<"\t"<<m[i][j];
		}
	}
}
void graph::dfs(int vertex) {
	cout<<"\n"<<vertex;
	visited[vertex]=1;
	for(int i=1; i<=n; i++) {
		if(m[vertex][i]==1) {
			if(visited[i]==0) {
				dfs(i);
			}
		}
	}
}
void graph::dfsnr(int i) {
	for(int i=1; i<=n; i++) {
		visited[i]=0;
	}
	i=1;
	stack s;
	s.push(i);
	while(!s.isEmpty()) {
		i=s.pop();

		if(visited[i]==0) {
			visited[i]=1;
			cout<<"\n"<<i;

			for(int j=n; j>=1; j--) {
				if(m[i][j]==1) {
					if(visited[j]==0)
						s.push(j);
				}
			}
		}
	}
}
int main() {
	int ch;
	graph g;
	char ans;
	do {
		cout<<"\nMenu"<<"\n1:Accept"<<"\n2:Display"<<"\n3:DFS recursive"<<"\n4:DFS non-recursive";
		cout<<"\nEnter your choice:";
		cin>>ch;
		switch(ch) {
			case 1:
				g.accept();
				break;

			case 2:
				g.display();
				break;

			case 3:
				cout<<"\nDepth first display of vertices=";
				g.dfs(1);
				break;

			case 4:
				cout<<"\nNon-recursive DFS display=";
				g.dfsnr(1);
				break;
		}
		cout<<"\nWant to continue(y/n)=";
		cin>>ans;

	} while(ans=='y');

	return 0;
}