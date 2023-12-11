//
// Created by Dustella on 12/9/2023.
//

#include <sstream>
#include <iostream>
#include <fstream>
#include "StudentStash.h"

using namespace std;

StudentStash::StudentStash() {
    

}

bool StudentStash::add(const Student &student) {
    stash.push_back(student);
    flushStorage();
    return true;
}

bool StudentStash::remove(int id) {
    for (auto it = stash.begin(); it != stash.end(); it++) {
        if (it->getId() == id) {
            stash.erase(it);
            break;
        }
    }
    flushStorage();
    return true;
}

Student StudentStash::get(int id) {
    for (auto &it: stash) {
        if (it.getId() == id) {
            return it;
        }
    }
    return *new Student(0);
}

bool StudentStash::update(const Student &student) {
    for (auto &it: stash) {
        if (it.getId() == student.getId()) {
            it = student;
            return true;
        }
    }
    flushStorage();
    return false;
}

vector<Student> StudentStash::getAll() {
    return stash;
}


void StudentStash::loadStorage() {
    ifstream file;
    file.open("students.csv");
    if (!file) {
        cout << "Unable to open file students.csv";
        exit(1); // terminate with error
    }
    string line;
    string fileString;
    while (getline(file, line)) {
        fileString += line + "\n";
    }
    fromRecordLines(fileString);
    file.close();
}

void StudentStash::flushStorage() {
    ofstream file;
    file.open("students.csv");
    if (!file) {
        cout << "Unable to open file student.csv";
        exit(1); // terminate with error
    }
    file << toRecordLines();
    file.close();
}


bool StudentStash::fromRecordLines(std::string lines) {
//    use getline to split lines
    stringstream ss(lines);
    string line;

    while (getline(ss, line)) {
        auto newStudent = Student::fromRecordLine(line);
        if (newStudent == nullptr) {
            cout << "Invalid record line" << endl;
            return false;
        } else {
            stash.push_back(*newStudent);
        }
    }
    return true;
}

string StudentStash::toRecordLines() {
    string lines;
    for (auto &it: stash) {
        lines += it.toRecordLine() + "\n";
    }
    return lines;
}

StudentStash::~StudentStash() = default;
