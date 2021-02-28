#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

class Student {
	char name [30];
	int id;
	int eng, math, sci, cs;
	double average;
	char grade;

	public:
		Student();
		~Student();
		void getData();
		void showData();
		void calculate();
		char* getName();
		double getAverage();
		int getId();
};

Student::Student()
{
	int check;
	cout << "Creating student" << endl;

}

Student::~Student()
{
	cout << "Destroying student" << endl;
}


int Student::getId()
{
	return id;
}

double Student::getAverage()
{
	return average;
}


char* Student::getName()
{
	return name;
}


void Student::getData()
{
	cout << "Enter id: ";
	cin >> id;
	cout << "Enter name: ";
	cin.ignore();
	cin.getline(name, 30);
	cout << "Enter english grade: ";
	cin >> eng;
	cout << endl;
	cout << "Enter math grade: ";
	cin >> math;
	cout << endl;
	cout << "Enter science grade: ";
	cin >> sci;
	cout << endl;
	cout << "Enter computer science grade: ";
	cin >> cs;
	cout << endl;
	calculate();
}

void Student::showData()
{
	cout << "ID: " << id << endl;
	cout << "Name: " << name << endl;
	cout << "Math grade: " << math << endl;
	cout << "English grade: " << eng << endl;
	cout << "Science grade: " << sci << endl;
	cout << "Computer science grade: " << cs << endl;
	cout << "Average grade: " << average << endl;
	cout << "Overall grade: " << grade << endl;
}

void Student::calculate()
{
	average = (math + eng + sci + cs) / 4.0;
	if (average >= 90.0) {
		grade = 'A';
	}
	else if (average >= 80) {
		grade = 'B';
	}
	else if(average >= 70) {
		grade = 'C';
	}
	else if(average >= 60){
		grade = 'D';
	}
	else if (average >= 55) {
		grade = 'E';
	}
	else {
		grade = 'F';
	}
}


void createStudent(Student *students, bool *isExist)
{
	int size = sizeof(students) / sizeof(Student);
	
	for (int i = 0; i < 2; i++) {
		if (!isExist[i]) {
			students[i].getData();
			isExist[i] = true;
		}
	}
}

void showStudent(Student *students, int id, bool *isExist)
{
	int check;
	for (int i = 0; i < 2; i++) {
		if(&students[i] != NULL && students[i].getId() == id && isExist[i] == true) {
			students[i].showData();
			cin >> check;
		}
	}
	cout << "No student with the given id was found" << endl;
	cin >> check;
}

void deleteStudent(Student *students, int id, bool *isExist)
{
	int check;
	for (int i = 0; i < 2; i++) {
		if (&students[i] != NULL && students[i].getId() == id) {
			cout << &students[i];
			students[i] = Student();
			isExist[i] = false;
			//delete(&students[i]);
			cout << &students[i];
			students[i].showData();
			cin >> check;
		}
	}
}

void bestStudent(Student *students, bool *isExist)
{
	int check;
	Student best;
	double bestAverage = -1;
	int bestIndex = -1;
	if (students == NULL) {
		cout << "Not initialized" << endl;
		return;
	}
	if (&students[0] != NULL && isExist[0] == true) {
		best = Student();
		best = students[0];
		bestAverage = students[0].getAverage();
		bestIndex = 0;
	}
	
	for (int i = 0; i < 2; i++) {
		if (&students[i] != NULL && isExist[i] == true) {
			if (students[i].getAverage() > bestAverage) {
				best = students[i];
				bestAverage = students[i].getAverage();
				bestIndex = i;
			}
		}
	}

	if (&best == NULL) {
		cout << "No students in database" << endl;
	}
	else {
		best.showData();
		cin >> check;
	}
}


int main()
{
	Student *arr = new Student[2];
	bool isStuds[2] = { false, false };
	char ch = ' ';
	do {
		int n = 0;
		int num = 0;
		int id;
		system("cls");
		cout << "\n\n\n\tMENU";
		cout << "\n\n\t1.Create students record";
		cout << "\n\n\t2. Search student record";
		cout << "\n\n\t3. Display all students records ";
		cout << "\n\n\t4.Delete student record";
		cout << "\n\n\t5.Get best student data";
		cout << "\n\n\t6.Exit";
		cout << "\n\nWhat is your Choice (1/2/3/4/5/6) ";
		cin >> ch;
		system("cls");
		switch (ch)
		{
		case '1': 
			createStudent(arr, isStuds); 
			break;
		case '2': cout << "\n\n\tEnter The ID of the student ";
			cin >> id;
			showStudent(arr, id, isStuds); 
			break;
		case '3':  
			for (int i = 0; i < 2; i++)
			{
				if (&arr[i] != NULL && isStuds[i] == true) {
					arr[i].showData();
				}
			}
			cin >> n;
			break;
		case '4': cout << "\n\n\tEnter The ID number: ";
			cin >> id;
			deleteStudent(arr, id, isStuds); 
			break;
		case '5': cout << "\n\n\tbest student ";
			bestStudent(arr, isStuds); 
			break;
		case '6': cout << "Exiting, Thank you!"; 
			exit(0);
		}
	} while (ch != '6');
	return 0;

}
