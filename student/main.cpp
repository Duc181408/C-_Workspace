#include <iostream>
#include <fstream>
#include "student.hpp"

using namespace std;

class ListStudent {
public:
    Student* arr;
    int numberStudent;
};

void readStudentInfo(ifstream& filein, Student& sv) {
    getline(filein, sv.fullName, ',');
    getline(filein, sv.doB, ',');
    getline(filein, sv.gender, ',');
    getline(filein, sv.phoneNumber, ',');
    getline(filein, sv.universityName, ',');
    getline(filein, sv.gradeLevel);
}

// void readFile(ifstream& filein, ListStudent& ds) {
//     ds.arr = new Student[ds.numberStudent];
//     for(int i = 0; i < ds.numberStudent; i++) {
//         readStudentInfo(filein, ds.arr[i]);
//     }
// }




int main() {
    ifstream filein("D:\\C++Worksapce\\student\\list.txt");
    if (!filein.is_open()) {
        cout << "Khong the mo file!" << endl;
        return 1;
    }

    ListStudent ds;
    int count = 0;
    string line;
    while (getline(filein, line)) {
        count++;
    }

    cout<<count;

    filein.close();
    delete[] ds.arr;

    return 0;
}
