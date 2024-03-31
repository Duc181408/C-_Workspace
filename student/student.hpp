#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
#include <iostream>

using namespace std;

class Student {
public: 
    string fullName;
    string doB;
    string sex;
    string phoneNumber;
    string universityName;
    string gradeLevel;
public:
    virtual void showInformation();
};

class GoodStudent : public Student {
private:
    float gpa;
    string bestRewardName;
public:
    // Constructor với tham số
    GoodStudent(const string& fullName, const string& doB, const string& sex, const string& phoneNumber, const string& universityName, const string& gradeLevel, double gpa, const string& BestRewardName)
        : Student(fullName, doB, sex, phoneNumber, universityName, gradeLevel), gpa(gpa), bestRewardName(BestRewardName) {}
    void showInformation() override; // Ghi đè phương thức ảo từ lớp cha
};

class NormalStudent : public Student {
private:
    int englishScore;
    float entryTestScore;
public:
    NormalStudent(const string& fullName, const string& doB, const string& sex, const string& phoneNumber, const string& universityName, const string& gradeLevel, int englishScore, int entryTestScore_val)
        : Student(fullName, doB, sex, phoneNumber, universityName, gradeLevel), englishScore(englishScore), entryTestScore(entryTestScore_val) {}
    void showInformation() override; // Ghi đè phương thức ảo từ lớp cha
};

#endif /* STUDENT_HPP */
