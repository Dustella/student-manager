//
// Created by Dustella on 12/9/2023.
//

#include "Student.h"
#include <sstream>
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

#include <codecvt>
#include <locale>



string Student::toRecordLine() {
    stringstream ss;
    ss << id << ",";
    ss << name << ",";
    ss << sex << ",";
    ss << grade << ",";
    ss << school << ",";
    ss << major << ",";
    ss << className << ",";
    ss << room << ",";
    ss << phone << ",";
    ss << birthplace;
    return ss.str();
}

Student *Student::fromRecordLine(const string &line) {
//    split line with seperator ,
    // use getline()
    // example line 1,duste,0,2,NUIST,CS,1,217,110,Suzhou
    vector<string> tokens;
    stringstream ss(line);
    string token;
    while (getline(ss, token, ',')) {
        tokens.push_back(token);
    }
    if (tokens.size() != 10) {
        cout << "Invalid record line" << endl;
        return nullptr;
    }
    auto *stu = new Student(stoi(tokens[0]));
    stu->setGrade(tokens[3]);
    stu->setName(tokens[1]);
    stu->setSchool(tokens[4]);
    stu->setMajor(tokens[5]);
    stu->setClassName(tokens[6]);
    stu->setRoom(tokens[7]);
    stu->setPhone(tokens[8]);
    stu->setBirthplace(tokens[9]);
    int sex_raw = stoi(tokens[2]);
    Sex sex = sex_raw == 1 ? Male : Female;
    stu->setSex(sex);
    return stu;
}

void Student::showHeader() {
    cout << setw(10) << setfill(' ')
         << "ID" << setw(10) << setfill(' ')
         << "Name" << setw(10) << setfill(' ')
         << "Sex" << endl;
}

void Student::show() const {
    string sex_string = sex == Male ? "男" :"女";

    cout << setw(10) << setfill(' ')
         << id << setw(10) << setfill(' ' )
         << name << setw(10) << setfill(' ' )
         << sex_string << endl;
}

void Student::fromUserInput() {
    int sex_raw;
    cout << "请输入姓名" << endl;
    cin >> name;
    cout << "请输入性别" << endl;
    cout << "1. 男" << endl;
    cout << "2. 女" << endl;
    cin >> sex_raw;
    cout << "请输入年级" << endl;
    cin >> grade;
    cout << "请输入学校" << endl;
    cin >> school;
    cout << "请输入专业" << endl;
    cin >> major;
    cout << "请输入班级" << endl;
    cin >> className;
    cout << "请输入宿舍" << endl;
    cin >> room;
    cout << "请输入电话" << endl;
    cin >> phone;
    cout << "请输入籍贯" << endl;
    cin >> birthplace;
    sex = sex_raw == 1 ? Male : Female;
}

#pragma region Setters

Student::Student(int id) {
    this->id = id;
}

Student Student::setGrade(string grade) {
    this->grade = grade;
    return *this;
}

Student Student::setName(string Name) {
    this->name = Name;
    return *this;
}

Student Student::setSex(Sex sex1) {
    this->sex = sex1;
    return *this;
}

Student Student::setSchool(string school) {
    this->school = school;
    return *this;
}

Student Student::setMajor(string major) {
    this->major = major;
    return *this;
}

Student Student::setClassName(string className) {
    this->className = className;
    return *this;
}

Student Student::setRoom(string room) {
    this->room = room;
    return *this;
}

Student Student::setPhone(string phone) {
    this->phone = phone;
    return *this;
}

Student Student::setBirthplace(string birthplace) {
    this->birthplace = birthplace;
    return *this;
}

#pragma endregion Setters


int Student::getId() const {
    return id;
}