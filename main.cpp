#include<iostream>
#include<fstream>
#include <string>

using namespace std;

class ManagementSysytem {
    string studentName,studentId,staffId,staffName;
    string course;
    fstream file;

public :
    void addStudent();
    void addStaff();
    void display();
    void staffDisplay();
};

void ManagementSysytem::addStaff() {
    cout<<"\n Enter the staff name ::";
    getline(cin, staffName);
    cout<<"\n Enter the staff ID::";
    getline(cin, staffId);

    file.open("staffSystem.csv", ios :: out | ios::app);
    if (file.is_open()) {
        file << staffId << "\t" << staffName << endl;
        file.close();
    } else {
        cout << "Error opening file\n";
    }
}

int main(){
    ManagementSysytem system;
    char choice;

while(true) {
    cout << ".................Choose the action.\n";
    cout << "1.Add student\n";
    cout << "2.Add staff\n";
    cout << "3.Exit\n";
    cin >> choice;
    cin.ignore();

    switch (choice) {
        case'1':
            system.addStudent();
            break;
        case '2':
            system.addStaff();
            break;
        case '3':
            return 0;
            break;
        default:
            cout<<"Incorrect choice!\n";
    }
}

    return 0;
}
void ManagementSysytem ::addStudent() {
    cout<<"\n Enter the student name ::";
    getline(cin,studentName);
    cout<<"\n Enter the student ID::";
    getline(cin,studentId);
    cout<<"\n Enter the course of student::";
    getline(cin,course);

    file.open("studentSystem.csv",ios :: out | ios::app);
    if (file.is_open()){
        file<<studentId<<","<<studentName<<","<<course<<endl;
        file.close();
    }else{
        cout<<"Error opening file\n";
    }
}

void ManagementSysytem:: display() {
    file.open("studentSystem.csv",ios :: in);
    if(file.is_open()) {
        cout<<".................WELCOME TO STUDENT MANAGEMENT SYSTEM.........";
        cout<<"\n\nStudent ID Student Name Course\n";

        while(getline(file,studentId, ',')&& getline(file,studentName, ',') && getline(file,course, ','))
        {
    cout<<studentId<<" ,"<<studentName<<", "<<course<<endl;
        }
        file.close();
    }else{
        cout<<"Error opening file\n";

    }

    }
void ManagementSysytem :: staffDisplay() {
    file.open("staffSystem.csv", ios ::in);
    if (file.is_open()){
        cout<<"..........WELCOME TO STAFF MANAGEMENT........";
        cout<<"\nstaff ID \t Staff Name\n";

        if (getline(file, staffId, ',')) {
            while (getline(file, staffName, ','))
                cout<<staffId<<","<<staffName<<endl;
        }
        file.close();
    }else{
        cout<<"Error\n";
    }
}
