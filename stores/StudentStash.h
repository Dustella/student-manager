//
// Created by Dustella on 12/9/2023.
//

#ifndef STUDENTMANAGER_STUDENTSTASH_H
#define STUDENTMANAGER_STUDENTSTASH_H
#include <vector>
#include "../models/Student.h"

class StudentStash {
private:
    vector<Student> stash;
public:
    StudentStash();
    ~StudentStash();
    bool add(const Student& student);
    bool remove(int id);
    Student get(int id);
    vector<Student> getAll();
    bool update(const Student& student);
    string toRecordLines();
    bool fromRecordLines(string lines);
    void flushStorage();
    void loadStorage();

};


#endif //STUDENTMANAGER_STUDENTSTASH_H
