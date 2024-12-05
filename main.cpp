#include<iostream>
#include<fstream>

using namespace std;

class temp{
    string studentName,studentId,staffName,staffId;
    string course;
    fstream file;

public:
    void addStudent();
    void addStaff();
};
int main(){
    char choice;


    cout<<".................Choose the action.\n";
    cout<<"1.Add student\n";
    cout<<"2.Add staff\n";
    cout<<"3.Exit\n";
    cin>>choice;

    switch (choice) {
        case'1':

            break;
        case '2':

            break;
        case '3':

            break;
        default:
            cout<<"Incorrect choice!";


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

    file.open("student system.txt",ios :: out | ios::app);
    file<<studentId<<"*"<<studentName<<"*"<<course<<endl;
    file.close();

}

void temp::addStaff() {

}
