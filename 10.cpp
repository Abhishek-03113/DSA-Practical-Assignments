include<iostream>
using namespace std;
class heap {
		int n;
		int maxh[30];
		int h[30];
	public:
		void create1();
		void insert1(int);
		void upAdjust1(int);
		void display1();
		void create2();
		void insert2(int);
		void upAdjust2(int);
		void display2();
};
void heap::create1() {
	int x;
	cout<<"\nEnter the size of array:";
	cin>>n;
	cout<<"\nEnter marks of "<<n-1<<" students:"<<endl;
	for(int i=1; i<n; i++) {
		cin>>maxh[i];
		x=maxh[i];
		insert1(x);
	}
}
void heap::insert1(int x) {
	int m;
	m=maxh[0];
	maxh[m+1]=x;
	maxh[0]=m+1;
	upAdjust1(m+1);
}
void heap::upAdjust1(int i) {
	int temp;
	while(i>1 && maxh[i]>maxh[i/2]) {
		temp=maxh[i];
		maxh[i]=maxh[i/2];
		maxh[i/2]=temp;
		i=i/2;
	}
}
void heap::display1() {
	cout<<"\nNumber of students:"<<maxh[0];
	cout<<"\nTheir marks:";
	for(int i=1; i<n; i++) {
		cout<<"\n"<<maxh[i];
	}
	cout<<"\nMaximum Marks:"<<maxh[1];
}
void heap::create2() {
	int x;
	cout<<"\nEnter the size of array:";
	cin>>n;
	cout<<"\nEnter marks of "<<n-1<<" students:"<<endl;
	for(int i=1; i<n; i++) {
		cin>>h[i];
		x=h[i];
		insert2(x);
	}
}
void heap::insert2(int x) {
	int m;
	m=h[0];
	h[m+1]=x;
	h[0]=m+1;
	upAdjust2(m+1);
}
void heap::upAdjust2(int i) {
	int temp;
	while(i>1 && h[i]<h[i/2]) {
		temp=h[i];
		h[i]=h[i/2];
		h[i/2]=temp;
		i=i/2;
	}
}
void heap::display2() {
	cout<<"\nNumber of students:"<<h[0];
	cout<<"\nTheir marks:";
	for(int i=1; i<n; i++) {
		cout<<"\n"<<h[i];
	}
	cout<<"\nMinimum Marks:"<<h[1];
}
int main() {
	heap h1;
	int ch;
	char ans;
	do {
		cout<<"\nMenu"<<"\n1:Create max heap"<<"\n2:Display max heap"<<"\n3:Create min heap"<<"\n4:Displ
		    ay min heap";
		    cout<<"\nEnter choice:";
		cin>>ch;
		switch(ch) {
			case 1:
				h1.create1();
				break;
			case 2:
				h1.display1();
				break;
			case 3:
				h1.create2();
				break;
			case 4:
				h1.display2();
				break;
		}
		cout<<"\nWant to continue?(y/n):";
		cin>>ans;
	} while(ans!=’n’);
	return 0;
}