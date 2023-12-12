//
// Created by Dustella on 12/9/2023.
//

#ifndef STUDENTMANAGER_SCORESTASH_H
#define STUDENTMANAGER_SCORESTASH_H


#include <vector>
#include <map>
#include "../models/Score.h"
using namespace std;

class ScoreStash {
private:
    vector<Score> scores;
public:
    ScoreStash();
    ~ScoreStash();

    bool add(const Score& score);
    bool remove(int id);
    Score get(int id);
    vector<Score> getAll();
    vector<Score> getScoreByStudent(int studentId);
    vector<Score> getFailedScores();
    float getAverageScoreByStudent(int studentId);
    map<int,float> getAverageMapping();


    bool update(const Score& score);
    string toRecordLines();
    bool fromRecordLines(string lines);
    void flushStorage();
    void loadStorage();

};


#endif //STUDENTMANAGER_SCORESTASH_H
