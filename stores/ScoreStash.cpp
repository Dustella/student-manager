//
// Created by Dustella on 12/9/2023.
//

#include "ScoreStash.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

ScoreStash::ScoreStash() {

}

bool ScoreStash::add(const Score &score) {
    scores.push_back(score);
    flushStorage();
    return true;
}

bool ScoreStash::remove(int id) {
    for (auto it = scores.begin(); it != scores.end(); it++) {
        if (it->getId() == id) {
            scores.erase(it);
            break;
        }
    }
    flushStorage();
    return true;
}

Score ScoreStash::get(int id) {
    for (auto &it: scores) {
        if (it.getId() == id) {
            return it;
        }
    }
    return *new Score();
}

vector<Score> ScoreStash::getAll() {
    return scores;
}

bool ScoreStash::update(const Score &score) {
    for (auto &it: scores) {
        if (it.getId() == score.getId()) {
            it = score;
            return true;
        }
    }
    flushStorage();
    return false;
}

void ScoreStash::loadStorage() {
    fstream file;
    file.open("scores.csv");
    if (!file) {
        cout << "File not found" << endl;
        ofstream newFile;
        newFile.open("scores.csv");
        newFile.close();
        file.open("scores.csv");
    }
    string line;
    string Filestring;
    while (getline(file, line)) {
        Filestring += line + "\n";
    }
    fromRecordLines(Filestring);
    file.close();

}

void ScoreStash::flushStorage() {
    ofstream file;
    file.open("scores.csv");
    if (!file) {
        cout << "File not found" << endl;
        return;
    }
    for (auto &it: scores) {
        file << it.toRecordLine() << endl;
    }
    file.close();
}

bool ScoreStash::fromRecordLines(string lines) {
    stringstream ss(lines);
    string line;
    while (getline(ss, line)) {
        scores.push_back(Score::fromRecordLine(line));
    }
    return true;
}

string ScoreStash::toRecordLines() {
    stringstream ss;
    for (auto &it: scores) {
        ss << it.toRecordLine() << endl;
    }
    return ss.str();
}

vector<Score> ScoreStash::getScoreByStudent(int studentId) {
    vector<Score> result;
    for (const auto &item: scores) {
        if (item.getStudentId() == studentId) {
            result.push_back(item);
        }
    }
    return result;
}

float ScoreStash::getAverageScoreByStudent(int studentId) {
    auto byStudent = getScoreByStudent(studentId);
    float sum = 0;
    for (const auto &item: byStudent) {
        sum += item.getMark();
    }
    return sum / byStudent.size();
}

map<int, float> ScoreStash::getAverageMapping() {
    map<int, vector<int>> mapping;
    for (const auto &item: scores) {
        int stuId = item.getStudentId();
        mapping[stuId].push_back(item.getMark());

    }

    map<int, float> result;
    for (auto [studentId, allScores]: mapping) {
        int sum = 0;
        for (auto mark: allScores) {
            sum += mark;
        }
        result[studentId] = sum / allScores.size();
    }
    return result;
}

vector<Score> ScoreStash::getFailedScores() {
    vector<Score> result;
    for (auto item: scores) {
        int mark = item.getMark();
        if (mark < 60) {
            result.push_back(item);
        }
    }
    return result;
}
