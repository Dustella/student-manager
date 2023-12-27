//
// Created by Dustella on 12/9/2023.
//

#ifndef STUDENTMANAGER_STUDENT_H
#define STUDENTMANAGER_STUDENT_H


#include <string>

using namespace std;

enum Sex {
    Male, Female
};

class Student {
private:
    int id;
    string name;
    Sex sex;
    string grade;
    string school;
    string major;
    string className;
    string room;
    string phone;
    string birthplace;
public:
    Student(int id);

    string toRecordLine();

    void show() const;

    static void showHeader();

    static Student* fromRecordLine(const string& line);

    void fromUserInput();

    Student setName(string name);

    Student setSex(Sex sex1);

    Student setGrade(string grade);

    Student setSchool(string school);

    Student setMajor(string major);

    Student setClassName(string className);

    Student setRoom(string room);

    Student setPhone(string phone);

    Student setBirthplace(string birthplace);

    int getId() const;

    string getBirthplace() const;

    string getSchool() const;

    string getClassName() const;


};

#endif //STUDENTMANAGER_STUDENT_H
