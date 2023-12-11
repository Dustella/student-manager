//
// Created by Dustella on 12/9/2023.
//

#ifndef STUDENTMANAGER_SCORE_H
#define STUDENTMANAGER_SCORE_H
#include <string>
using namespace std;

class Score {
private:
    int mark;
    string section;
    string lesson;
    int studentId ;
public:
    string toRecordLine();
    bool fromRecordLine(string line);
};


#endif //STUDENTMANAGER_SCORE_H
