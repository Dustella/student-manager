//
// Created by Dustella on 12/9/2023.
//

#include "Score.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

Score Score::fromRecordLine(string line) {
    vector <string> tokens;
    stringstream ss(line);
    string token;
    while (getline(ss, token, ',')) {
        tokens.push_back(token);
    }
    if (tokens.size() != 4) {
        cout << "Invalid record line" << endl;
        return *new Score();
    }
    auto *score = new Score();
    score->setMark(stoi(tokens[0]));
    score->setSection(tokens[1]);
    score->setLesson(tokens[2]);
    score->setStudentId(stoi(tokens[3]));
    return *score;
}

string Score::toRecordLine() {
    stringstream ss;
    ss << mark << "," << section << "," << lesson << "," << studentId;
    return ss.str();
}

void Score::showHeader() {
    cout << setw(10) << setfill(' ')
         << "Score" << setw(10) << setfill(' ')
         << "Term" << setw(10) << setfill(' ')
         << "Lesson" << setw(10) << setfill(' ')
         << "StudentID" << endl;

}

void Score::setMark(int mark) {
    this->mark = mark;
}

void Score::show() {
    cout << setw(10) << setfill(' ')
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
