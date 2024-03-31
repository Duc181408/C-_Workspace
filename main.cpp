#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

// Định nghĩa lớp sinh viên và các lớp con
class Student {
public:
    string fullName; // Thay thế bằng fullName để lưu cả họ và tên  
protected:
    string doB;
    string sex;
    string phoneNumber;
    string universityName;
    string gradeLevel;

public:
    // Constructor mặc định
    Student() {}

    // Constructor với tham số
    Student(const string& fullName, const string& doB, const string& sex, const string& phoneNumber, const string& universityName, const string& gradeLevel)
        : fullName(fullName), doB(doB), sex(sex), phoneNumber(phoneNumber), universityName(universityName), gradeLevel(gradeLevel) {}

    // Hàm hiển thị thông tin sinh viên
    virtual void showInfo() const {
        cout << "Full Name: " << fullName << endl;
        cout << "Date of Birth: " << doB << endl;
        cout << "Sex: " << sex << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "University Name: " << universityName << endl;
        cout << "Grade Level: " << gradeLevel << endl;
    }
    virtual ~Student() {}
};

// Lớp sinh viên giỏi kế thừa từ lớp sinh viên
class GoodStudent : public Student {
public:
    double gpa;
    string bestRewardName;

public:
    // Constructor với tham số
    GoodStudent(const string& fullName, const string& doB, const string& sex, const string& phoneNumber, const string& universityName, const string& gradeLevel, double gpa, const string& bestRewardName)
        : Student(fullName, doB, sex, phoneNumber, universityName, gradeLevel), gpa(gpa), bestRewardName(bestRewardName) {}

    // Hàm hiển thị thông tin sinh viên giỏi
    void showInfo() const override {
        Student::showInfo();
        cout << "GPA: " << gpa << endl;
        cout << "Best Reward Name: " << bestRewardName << endl;
    }
    virtual ~GoodStudent() {}
};

// Lớp sinh viên bình thường kế thừa từ lớp sinh viên
class NormalStudent : public Student {
public:
    int englishScore;
    int entryTestScore;

public:
    // Constructor với tham số
    NormalStudent(const string& fullName, const string& doB, const string& sex, const string& phoneNumber, const string& universityName, const string& gradeLevel, int englishScore, int entryTestScore)
        : Student(fullName, doB, sex, phoneNumber, universityName, gradeLevel), englishScore(englishScore), entryTestScore(entryTestScore) {}

    // Hàm hiển thị thông tin sinh viên bình thường
    void showInfo() const override {
        Student::showInfo();
        cout << "English Score: " << englishScore << endl;
        cout << "Entry Test Score: " << entryTestScore << endl;
    }
    virtual ~NormalStudent() {}
};

// Hàm so sánh để sắp xếp sinh viên theo điểm GPA và họ tên
bool compareByGPA(const GoodStudent& a, const GoodStudent& b) {
    if (a.gpa == b.gpa) {
        return a.fullName < b.fullName;
    }
    return a.gpa > b.gpa;
}

// Hàm so sánh để sắp xếp sinh viên trung bình theo điểm thi đầu vào, điểm TOEIC và họ tên
bool compareByEntryTestAndTOEIC(const NormalStudent* a, const NormalStudent* b) {
    // if (a->entryTestScore == b->entryTestScore) {
    //     if (a->englishScore == b->englishScore) {
    //         return a->fullName < b->fullName;
    //     }
    //     return a->englishScore > b->englishScore;
    // }
    return a->entryTestScore > b->entryTestScore;
}

int main() {
    // Mảng lưu trữ sinh viên giỏi và sinh viên bình thường
    vector<GoodStudent*> goodStudents;
    vector<NormalStudent*> normalStudents;
    vector<Student> selectedStudents;

    // Mở tệp đầu vào
    ifstream filein("D:\\C++Worksapce\\list.txt");
    if (!filein.is_open()) {
        cout << "Unable to open file!" << endl;
        return 1;
    }
    
    // Đọc từng dòng từ tệp và tạo sinh viên tương ứng
    string line;
    while (getline(filein, line)) {
        stringstream ss(line);
        string type, fullName, doB, sex, phoneNumber, universityName, gradeLevel, bestRewardName;
        double gpa;
        int englishScore, entryTestScore;

        getline(ss, type, ',');
        getline(ss, fullName, ',');
        getline(ss, doB, ',');
        getline(ss, sex, ',');
        getline(ss, phoneNumber, ',');
        getline(ss, universityName, ',');
        getline(ss, gradeLevel, ',');

        // Kiểm tra loại sinh viên
        if (type == "Good") {
            // numberGood++;
            ss >> gpa;
            // Xử lý trường hợp tên sinh viên chứa dấu ","
            getline(ss >> ws, bestRewardName, ',');
            getline(ss, bestRewardName);
            goodStudents.push_back(new GoodStudent(fullName, doB, sex, phoneNumber, universityName, gradeLevel, gpa, bestRewardName));
        } else if (type == "Normal") {
            // numberNomal++;
            ss >> englishScore;
            ss.ignore();
            ss >> entryTestScore;
            normalStudents.push_back(new NormalStudent(fullName, doB, sex, phoneNumber, universityName, gradeLevel, englishScore, entryTestScore));
        } else {
            cout << "Invalid student type!" << endl;
        }
    }

    // Đóng tệp
    filein.close();
    
    cout << "How many student you need: "<<endl;
    int number;
    cin >> number;
    if((number<5)||(number>10)) cout<<"Invalid! Please re-enter"<<endl;
    else //do nothing
    
        // Sắp xếp danh sách sinh viên khá giỏi theo GPA và họ tên
    sort(goodStudents.begin(), goodStudents.end(), [](const GoodStudent * a , const GoodStudent * b){
        return a->gpa > b->gpa ;
    });
    for (int i = 0; i < min(number, (int)goodStudents.size()); ++i) {
        selectedStudents.push_back(*goodStudents[i]);
    }

    // Nếu vẫn cần tuyển thêm sinh viên
    if (selectedStudents.size() < static_cast<size_t>(number)) {
        // Lấy số lượng sinh viên cần tuyển dụng từ danh sách sinh viên trung bình
        int remaining = number - selectedStudents.size();
        sort(normalStudents.begin(), normalStudents.end(), compareByEntryTestAndTOEIC);
        for (int i = 0; i < min(remaining, (int)normalStudents.size()); ++i) {
            selectedStudents.push_back(*normalStudents[i]);
        }
    }

    // Hiển thị thông tin của từng sinh viên giỏi
    // cout << "selectedStudents:" << endl;
    // for (const auto& student : selectedStudents) {
    //     student->showInfo();
    //     cout << endl;
    // }



    // // Hiển thị thông tin của từng sinh viên giỏi
    // cout << "Good Students:" << endl;
    // for (const auto& student : goodStudents) {
    //     student->showInfo();
    //     cout << endl;
    // }

    // // Hiển thị thông tin của từng sinh viên bình thường
    // cout << "Normal Students:" << endl;
    // for (const auto& student : normalStudents) {
    //     student->showInfo();
    //     cout << endl;
    // }

    // Giải phóng bộ nhớ
    for (auto& student : goodStudents) {
        delete student;
    }

    for (auto& student : normalStudents) {
        delete student;
    }

    return 0;
}
