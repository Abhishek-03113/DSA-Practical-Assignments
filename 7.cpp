#include<iostream>
using namespace std;
class prim {
		int visited[20],m[20][20],mincost,min,edges;
	public:
		int n;
		prim() {
			edges=1;
			min=0;
			mincost=0;
			n=0;
			for(int i=1; i<=n; i++) {
				visited[i]=0;
			}
		}
		void insert();
		void display();
		void findcost(int);
};

void prim::insert() {
	cout<<"\nEnter the number of vertices: ";
	cin>>n;
	for(int i=1; i<=n; i++) {
		visited[i]=0;
	}
	cout<<"\nEnter the adjacency matrix: ";
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			cin>>m[i][j];
			if(m[i][j]==0) {
				m[i][j]=999;
			}
		}
	}
}


void prim::display() {
	cout<<"\nThe Adjacency Matrix: ";
	for(int i=1; i<=n; i++) {
		cout<<"\n";
		for(int j=1; j<=n; j++) {
			cout<<"\t"<<m[i][j];
		}
	}
}

void prim::findcost(int n) {
	visited[1]=1;
	int y,z;
	while(edges<=(n-1)) {
		min=999;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				if(m[i][j]<min) {
					if(visited[i]!=0) {
						min=m[i][j];
						y=i;
						z=j;
					}
				}
			}
		}
		if(visited[y]==0||visited[z]==0) {
			cout<<"\nSubpath"<<edges<<" : "<< y <<" to "<< z <<" = "<<min;
			edges++;
			mincost+=min;
			visited[z]=1;
		}
		m[y][z]=m[z][y]=999;
	}
	cout<<"\nThe Minimum Cost: "<<mincost;
}

int main() {
	int ch;
	prim g;
	char ans;
	do {
		cout<<"\nMENU"<<"\n1.Accept"<<"\n2.Display"<<"\n3.Find Minimum Cost"<<"\n4.Exit";
		cout<<"\n\nEnter your choice: ";
		cin>>ch;
		switch(ch) {
			case 1:
				g.insert();
				break;
			case 2:
				g.display();
				break;
			case 3:
				g.findcost(g.n);
				break;
			case 4:
				cout<<"\n\nThank You, Visit Again :)";
				break;
		}
		cout<<"\n\nDo you want to continue further? (y/n) = ";
		cin>>ans;
	} while(ans=='y');
	{
		cout<<"\n\nThank You, Visit Again :)";
		return 0;
	}
}