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
    return *new Score(0);
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

ScoreStash::loadStorage(){
    fstream file;
    file.open("scores.csv");
    if (!file){
        cout << "File not found" << endl;
        return;
    }
    string line;
    string Filestring;
    while (getline(file, line)){
        Filestring += line + "\n";
    }
    fromRecordLines(Filestring);
    file.close();

}

Score::flushStorage() {
    ofstream file;
    file.open("scores.csv");
    if (!file) {
        cout << "File not found" << endl;
        return;
    }
    for (auto &it: stash) {
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

