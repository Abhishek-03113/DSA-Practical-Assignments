#include<iostream>
using namespace std;

class graph {
		int m[20][20];
		int visited[20],n;
	public:
		void accept();
		void display();
		void bfs(int);
		int returnN() {
			return n;
		}
};

class queue {
		int que[20];
		int front,rear;
	public:
		queue() {
			front=-1;
			rear=-1;
		}
		bool isEmpty() {
			if((rear==-1)||(front>rear))
				return true;
			else
				return false;
		}
		void enque(int);
		int deque();
};
void queue::enque(int i) {
	if(front==-1) {
		front++;
	}
	que[++rear]=i;
}
int queue::deque() {
	return(que[front++]);
}

void graph::accept() {
	cout<<"Enter the No. of Vertices: ";
	cin>>n;
	for(int i=1; i<=n; i++) {
		visited[i]=0;
	}
	cout<<"\nEnter the Adjacency Matrix:";
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			cin>>m[i][j];
		}
	}
}
void graph::display() {
	cout<<"\nThe Adjacency Matrix is: ";
	for(int i=1; i<=n; i++) {
		cout<<"\n";
		for(int j=1; j<=n; j++) {
			cout<<"\t"<<m[i][j];
		}
	}
}

void graph::bfs(int v) {
	queue q;
	visited[v]=1;
	cout<<"\n"<<v;
	q.enque(v);
	while(!q.isEmpty()) {
		v=q.deque();
		for(int j=1; j<=n; j++) {
			if(m[v][j]==1) {
				if(visited[j]==0) {
					q.enque(j);
					visited[j]=1;
					cout<<"\n"<<j;
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
		cout<<"\nMenu"<<endl;
		cout<<"1. Accept"<<endl;
		cout<<"2. Display"<<endl;
		cout<<"3. BFS Traversal"<<endl;
		cout<<"Enter your Choice: ";
		cin>>ch;
		switch(ch) {
			case 1:
				g.accept();
				break;
			case 2:
				g.display();
				break;
			case 3:
				cout<<"\nBreadth First Display of Vertices: ";
				g.bfs(1);
				break;
		}
		cout<<"\nWant to continue (y/n)=";
		cin>>ans;
	} while(ans=='y');
	return 0;
}