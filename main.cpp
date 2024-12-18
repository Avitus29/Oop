#include<iostream>
#include<fstream>
#include <string>

using namespace std;
//opening class
class ManagementSystem{
    string studentName,studentId,staffName,staffId,date;
    string course;
    fstream file;

public:
    void addStudent();

    void display();
    void studentAttendance();
    void DisplayStudentAttendance();
    void studentManagementMenu();
    void staffManagement();
    void staffDisplay();
    void staffAttendance();
    void DisplayStaffAttendance();
};

//calling function for the systrm menu
void ManagementSystem::studentManagementMenu() {

}

int main(){
    ManagementSystem system;
    char choice;

    while(true){
        cout<<".................Choose the action....................\n";
        cout<<"1.Student Management\n";
        cout<<"2.Staff Management\n";
        cout<<"3.Exit Program\n";
        cin>>choice;
        cin.ignore();

        switch (choice) {
            case'1':
                system.studentManagementMenu();
                break;
            case '2':
                system.staffManagement();
                break;
            case '3':
                return 0;
                break;
            default:
                cout<<"Incorrect choice!";

        }
    }
    return 0;
}



void studentManagementMenu(ManagementSystem system){
    char studentChoice;
    while(true){
        cout<<".................STUDENT MANAGEMENT MENU....................\n";
        cout<<"1.Add student\n";
        cout<<"2.View all students\n";
        cout<<"3.Add Student Attendance\n";
        cout<<"4.Display Student Attendance\n";
        cout<<"5.Return to main menu\n";
        cin>>studentChoice;
        cin.ignore();

        switch (studentChoice) {
            case '1':
                system.addStudent();
                break;
            case'2':
                system.display();
                break;
            case '3':
                system.studentAttendance();
                break;
            case '4':
                system.DisplayStudentAttendance();
            case '5':
                return;
            default:
                cout<<"Incorrect choice!";
        }
    }
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
    }else{
        cout<<"if student not seen contact school admin";
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
    }else {
        cout<<"Error opening file\n";
    }
}

 void ManagementSystem::staffManagement() {
    char staffChoice;
    while(true){
        cout<<".................STAFF MANAGEMENT MENU....................\n";
        cout<<"1.Add staff\n";
        cout<<"2.View all staff\n";
        cout<<"3.Add Staff Attendance\n";
        cout<<"4.Display Staff Attendance\n";
        cout<<"5.Return to main menu\n";
        cin>>staffChoice;
    }

}