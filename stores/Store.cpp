//
// Created by Dustella on 12/9/2023.
//

#include "Store.h"

ScoreStash *Store::getScore() {
    if (scoreStash == nullptr) {
        scoreStash = new ScoreStash();
    }
    return scoreStash;
}

StudentStash *Store::getStudent() {
    if (studentStash == nullptr) {
        studentStash = new StudentStash();
    }
    return studentStash;
}


StudentStash* Store::studentStash = nullptr;;
ScoreStash* Store::scoreStash = nullptr;;