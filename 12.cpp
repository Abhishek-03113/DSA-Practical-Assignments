#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
class Employee {
	private:
		int id;
		char name[50];
		char designation[50];
		double salary;
	public:
		void addEmployee();
		void deleteEmployee();
		void search();
		void display();
};
void Employee:: addEmployee() {
	ofstream file("employee_data.dat", ios::binary | ios::app);
	Employee emp;
	cout << "Enter employee ID: ";
	cin >> emp.id;
	cout << "Enter employee name: ";
	cin.ignore();
	cin.getline(emp.name, 50);
	cout << "Enter employee designation: ";
	cin.getline(emp.designation, 50);
	cout << "Enter employee salary: ";
	cin >> emp.salary;
	file.write((char *)&emp,sizeof(emp));
	file.close();
	cout << "Employee added successfully!" << endl;
}
void Employee:: deleteEmployee() {
	int id;
	cout << "Enter employee ID to delete: ";
	cin >> id;
	ifstream file("employee_data.dat", ios::binary);
	ofstream temp("temp.dat", ios::binary);
	Employee emp;
	bool found = false;
	while (file.read((char *)&emp,sizeof(emp))) {

		if (emp.id != id) {
			temp.write((char *)&emp,sizeof(emp));
		} else {
			found = true;
		}
	}
	file.close();
	temp.close();
	remove("employee_data.dat");
	rename("temp.dat", "employee_data.dat");
	if (found) {
		cout << "Employee deleted successfully!" << endl;
	} else {
		cout << "Employee not found." << endl;
	}
}
void Employee::search() {
	int id;
	cout << "Enter employee ID to display: ";
	cin >> id;
	ifstream file("employee_data.dat", ios::binary);
	Employee emp;
	bool found = false;
	while (file.read((char *)&emp,sizeof(emp))) {
		if (emp.id == id) {
			found = true;
			cout << "Employee ID: " << emp.id << endl;
			cout << "Name: " << emp.name << endl;
			cout << "Designation: " << emp.designation << endl;
			cout << "Salary: " << emp.salary << endl;
			break;
		}
	}
	file.close();
	if (!found) {
		cout << "Employee not found." << endl;
	}
}

void Employee:: display() {
	Employee emp;
	ifstream file("employee_data.dat", ios::binary);
	if(!file) {
		cout<<"\nError in opening file.\n";
		return;
	}
	while(file) {
		if(file.read((char *)&emp,sizeof(emp))) {
			cout << "Employee ID: " << emp.id << endl;
			cout << "Name: " << emp.name << endl;
			cout << "Designation: " << emp.designation << endl;
			cout << "Salary: " << emp.salary << endl;
		}
	}
	file.close();
}
int main() {
	Employee emp;
	int choice;
	do {
		cout << "\n--- Employee Information System ---" << endl;
		cout << "1. Add Employee\n2. Delete Employee\n3. Search Employee\n4. Display \n5. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice) {
			case 1:
				emp.addEmployee();
				break;
			case 2:
				emp.deleteEmployee();
				break;
			case 3:
				emp.search();
				break;
			case 4:
				emp.display();
				break;
			case 5:
				cout << "Exiting..." << endl;
				break;
			default:
				cout << "Invalid choice. Please try again." << endl;
				break;
		}
	} while (choice != 5);
	return 0;
}