#include<iostream>
#include<fstream>
#include <string>

using namespace std;

class temp {
    string studentName,studentId,staffId,staffName;
    string course;
    fstream file;

public :
    void addStudent();
    void display();
};

int main(){
    temp system;
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
            system.display();
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
void temp ::addStudent() {
    cout<<"\n Enter the student name ::";
    getline(cin,studentName);
    cout<<"\n Enter the student ID::";
    getline(cin,studentId);
    cout<<"\n Enter the course of student::";
    getline(cin,course);

    file.open("studentSystem.txt",ios :: out | ios::app);
    if (file.is_open()){
        file<<studentId<<"\t"<<studentName<<"\t"<<course<<endl;
        file.close();
    }else{
        cout<<"Error opening file\n";
    }
}

void temp:: display() {
    file.open("staffSystem.txt",ios :: in);
    if(file.is_open()) {
        cout<<"\n\nStudent ID\tStudent Name \tCourse\n";

        while(getline(file,studentId, '*')&& getline(file,studentName, '*') && getline(file,course, '*'))
        {
    cout<<studentId<<" "<<studentName<<" "<<course<<endl;
        }
        file.close();
    }else{
        cout<<"Error opening file\n";

    }

    }

