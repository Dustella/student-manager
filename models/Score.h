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
    static Score fromRecordLine(string line);

    static void showHeader();
    void show() const;

    void fromUserInput();

    void setMark(int mark);
    void setSection(string section);
    void setLesson(string lesson);
    void setStudentId(int studentId);

    int getMark() const;
    int getStudentId() const;
};


#endif //STUDENTMANAGER_SCORE_H
