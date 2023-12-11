//
// Created by Dustella on 12/9/2023.
//

#ifndef STUDENTMANAGER_STORE_H
#define STUDENTMANAGER_STORE_H


#include "StudentStash.h"
#include "ScoreStash.h"

class Store {
//    使用单例模式，初始化ScoreStash和StudentStash
protected:
    static ScoreStash* scoreStash;
    static StudentStash* studentStash;
    Store();
public:

    static ScoreStash *getScore();

    static StudentStash *getStudent();

    ~Store();
};



#endif //STUDENTMANAGER_STORE_H
