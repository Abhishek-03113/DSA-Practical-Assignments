#include<iostream>
#include<fstream>
using namespace std;
class student {
	public:
		int rollno;
		char div;
		bool flag;
		char name[20];
		char addr[20];
		void getdata();
		void display_data();
		int return_rno();
};
void student::getdata() {
	cout << "Enter roll number: ";
	cin >> rollno;
	cout << "Enter name: ";
	cin >> name;
	cout << "Enter division: ";
	cin >> div;
	cout << "Enter address: ";
	cin >> addr;
}
void student::display_data() {
	cout << "\nRoll Number: " << rollno << endl;
	cout << "Name: " << name << endl;
	cout << "Division: " << div << endl;
	cout << "Address: " << addr << endl;
}
int student::return_rno() {
	return rollno;
}
void write_rec() {

	ofstream fobj;
	fobj.open("Info.txt",ios::app);
	student s1;
	s1.getdata();
	fobj.write((char *)&s1, sizeof(s1));
	fobj.close();
}
void display_rec() {
	ifstream f1;
	f1.open("Info.txt");
	student s1;
	while(f1.read((char *)&s1, sizeof(s1)))
		s1.display_data();
	f1.close();
}
void search_rec() {
	int rno;
	cout << "\nEnter rollno to be searched: ";
	cin >> rno;
	ifstream f1;
	f1.open("Info.txt",ios::in);
	student s1;
	while(f1.read((char *)&s1, sizeof(s1))) {
		if (s1.return_rno() == rno) {
			s1.flag = true;
			s1.display_data();
			f1.close();
			return;
		}
	}
	f1.close();
	if(s1.flag == false)
		cout << "Data not found" << endl;
}
void delete_rec() {
	student s1;

	int r1no;
	cout << "\nEnter rollno to be deleted: ";
	cin >> r1no;
	ifstream f1;
	ofstream f2;
	f1.open("Info.txt",ios::in);
	f2.open("temp.txt",ios::out);
	f1.read((char *)&s1, sizeof(s1));
	while(!f1.eof()) {
		if(s1.return_rno() != r1no)
			f2.write((char *)&s1,sizeof(s1));
		f1.read((char *)&s1, sizeof(s1));
	}
	cout << "Record with rollno " << r1no << " has been deleted" << endl;
	f1.close();
	f2.close();
	remove("Info.txt");
	rename("temp.txt", "Info.txt");
}
int main() {
	int count;
	cout << "Enter number of records to be entered: ";
	cin >> count;
	for(int i=0; i<count; i++)
		write_rec();
	cout << "\nRecords entered are: ";
	display_rec();
	search_rec();
	delete_rec();
	display_rec();
	return 0;
}