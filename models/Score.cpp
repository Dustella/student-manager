//
// Created by Dustella on 12/9/2023.
//

#include "Score.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>

int Score::maxId = 0;

Score Score::fromRecordLine(string line) {
    vector<string> tokens;
    stringstream ss(line);
    string token;
    while (getline(ss, token, ',')) {
        tokens.push_back(token);
    }
    if (tokens.size() != 5) {
        cout << "Invalid record line" << endl;
        return *new Score();
    }
    auto *score = new Score();
    score->setId(stoi(tokens[0]));
    score->setMark(stoi(tokens[1]));
    score->setSection(tokens[2]);
    score->setLesson(tokens[3]);
    score->setStudentId(stoi(tokens[4]));
    if (score->getId() > Score::maxId) {
        Score::maxId = score->getId();
    }
    return *score;
}

void Score::fromUserInput() {
    int newId = Score::maxId + 1;
    setId(newId);
    cout << "输入课程" << endl;
    cin >> lesson;
    cout << "输入学生ID" << endl;
    cin >> studentId;
    cout << "输入成绩" << endl;
    cin >> mark;
    cout << "输入学期" << endl;
    cin >> section;

}

string Score::toRecordLine() {
    stringstream ss;
    ss << id << "," << mark << "," << section << "," << lesson << "," << studentId;
    return ss.str();
}

void Score::showHeader() {
    cout << setw(10) << setfill(' ')
         << "ID" << setw(10) << setfill(' ')
         << "Score" << setw(10) << setfill(' ')
         << "Term" << setw(10) << setfill(' ')
         << "Lesson" << setw(10) << setfill(' ')
         << "StudentID" << endl;


}

void Score::setMark(int mark) {
    this->mark = mark;
}

int Score::getId() const {
    return id;
}

void Score::setId(int id) {
    this->id = id;
}

void Score::show()  {
    cout << setw(10) << setfill(' ')
         << id << setw(10) << setfill(' ')
         << mark << setw(10) << setfill(' ')
         << section << setw(10) << setfill(' ')
         << lesson << setw(10) << setfill(' ')
         << studentId << endl;
}

void Score::setSection(string section) {
    this->section = section;
}

void Score::setLesson(string lesson) {
    this->lesson = lesson;
}

void Score::setStudentId(int studentId) {
    this->studentId = studentId;
}

int Score::getMark() const {
    return mark;
}

int Score::getStudentId() const {
    return studentId;
}


