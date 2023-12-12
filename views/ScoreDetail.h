//
// Created by Dustella on 12/10/2023.
//

#ifndef STUDENTMANAGER_SCOREDETAIL_H
#define STUDENTMANAGER_SCOREDETAIL_H


#include "UI.h"

class ScoreEditView: public UI{
public:
    void show() override;

    UI* getNextFrame() override;

};

class ScoreAddView: public UI {
public:
    void show() override;

    UI* getNextFrame() override;
};

class ScoreDeleteView: public UI {
public:
    void show() override;

    UI* getNextFrame() override;
};


#endif //STUDENTMANAGER_SCOREDETAIL_H
