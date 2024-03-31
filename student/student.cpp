#include "student.hpp"

// Định nghĩa phương thức showInformation() cho lớp Student
void Student::showInformation() {
    cout << "Full Name: " << fullName << endl;
    cout << "Date of Birth: " << doB << endl;
    cout << "Gender: " << sex << endl;
    cout << "Phone Number: " << phoneNumber << endl;
    cout << "University Name: " << universityName << endl;
    cout << "Grade Level: " << gradeLevel << endl;
}

// Định nghĩa phương thức showInformation() cho lớp GoodStudent
void GoodStudent::showInformation() {
    // Gọi phương thức showInformation() của lớp cha
    Student::showInformation(); 
    cout << "GPA: " << gpa << endl;
    cout << "Best Reward Name: " << bestRewardName << endl;
}

// Định nghĩa phương thức showInformation() cho lớp NormalStudent
void NormalStudent::showInformation() {
    // Gọi phương thức showInformation() của lớp cha
    Student::showInformation();
    cout << "English Score: " << englishScore << endl;
    cout << "Entry Test Score: " << entryTestScore << endl;
}