#include<iostream>
#include<fstream>
#include <string>

using namespace std;

class ManagementSystem{
    string studentName,studentId,staffName,staffId,date;
    string course;
    fstream file;

public:
    void addStudent();
    void addStaff();
    void display();
    void staffDisplay();
    void staffAttendance();
    void studentAttendance();
    void DisplayStudentAttendance();
    void DisplayStaffAttendance();

};


int main(){
    ManagementSystem system;
    char choice;

    while(true){
        cout<<".................Choose the action....................\n";
        cout<<"1.Add student\n";
        cout<<"2.Take staff\n";
        cout<<"3.Student Attendance\n";
        cout<<"4.Staff Attendance\n";
        cout<<"5.Exit\n";
        cin>>choice;
        cin.ignore();

        switch (choice) {
            case'1':
                system.addStudent();
                break;
            case '2':
                system.addStaff();
                break;
            case '3':
               system.studentAttendance();
                break;
            case '4':
                system.staffAttendance();
                break;
            case '5':
                return 0;
                break;
            default:
                cout<<"Incorrect choice!";

        }


    }
    return 0;
}
void ManagementSystem::addStudent() {
    cout<<"\n Enter the student name ::";
    getline(cin,studentName);
    cout<<"\n Enter the student ID::";
    getline(cin,studentId);
    cout<<"\n Enter the course of student::";
    getline(cin,course);

    file.open("studentsytem.txt",ios :: out | ios::app);
    file<<studentId<<"\t"<<studentName<<"\t"<<course<<endl;
    file.close();

}

void ManagementSystem::display() {
    file.open("studentsytem.txt",ios :: in);
    if (file.is_open()) {
        cout<<"...............WELCOME TO STUDENT MANAGEMENT SYSTEM...........";
        cout<<"\n\nStudent ID\tStudent Name\tCourse\n";
        while(!file.eof()) {
            string line;
            getline(file,line);
            cout<<line<<endl;
        }
        file.close();
} else{
        cout<<"Error opening file\n";
    }
}

void ManagementSystem::staffDisplay() {
        file.open("staff system.txt",ios :: in);
        if(file.is_open()) {
            cout<<"...............WELCOME TO STAFF MANAGEMENT SYSTEM...........";
            cout<<"\n\nStaff ID\tStaff Name\n";
            while(!file.eof()) {
                string line;
                getline(file,line);
                cout<<line<<endl;
            }
            file.close();
        }else {
            cout<<"Error opening file\n";
        }

}
void ManagementSystem ::addStaff() {
    cout<<"\n Enter the staff name ::";
    getline(cin,staffName);
    cout<<"\n Enter the staff ID::";
    getline(cin,staffId);

    file.open("staff system.txt",ios :: out | ios::app);
    if (file.is_open()) {
        file<<staffId<<"\t"<<staffName<<endl;
        file.close();
    }else {
        cout<<"Error opening file\n";
    }
}
void ManagementSystem::studentAttendance() {
    cout<<"Enter the student ID to check attendance";
    getline(cin,studentId);
    cout<<"Enter the date in the YY-MM-DD format";
    getline(cin, date);

    file.open("student_attendance.txt",ios :: out | ios::app);
    if (file.is_open()) {
        file<<studentId<<"\t"<<date<<endl;
        file.close();
        cout<<"Attendance recorded successfully:"<<studentId<<"\t"<<date<<endl;
    }else {
        cout<<"Error opening file\n";
    }
}

void ManagementSystem::staffAttendance() {
    cout<<"Enter the staff ID to check attendance";
    getline(cin,staffId);
    cout<<"Enter the date in the YY-MM-DD format";
    getline(cin, date);


    file.open("staff_attendance.txt",ios :: out | ios::app);
    if(file.is_open()) {
        file<<staffId<<"\t"<<date<<endl;
        file.close();
        cout<<"Attendance recorded successfully:"<<staffId<<"\t"<<date<<endl;
    }else{
        cout<<"Error opening file\n";
    }

}
void ManagementSystem :: DisplayStudentAttendance() {
    file.open("student_attendance.txt",ios :: in);
    if(file.is_open()) {
        cout<<"...............WELCOME TO STUDENT ATTENDANCE SYSTEM...........";
        cout<<"\n\nStudent ID\tDate\n";
        while(!file.eof()) {
            string line;
            getline(file,line);
            cout<<line<<endl;
        }
    }
}

void ManagementSystem::DisplayStaffAttendance() {
    file.open("staff_attendance.txt",ios :: in);
    if(file.is_open()) {
        cout<<"...............WELCOME TO STAFF ATTENDANCE SYSTEM...........";
        cout<<"\n\nStaff ID\tDate\n";
        while(!file.eof()) {
            string line;
            getline(file,line);
            cout<<line<<endl;


        }
    }

}

