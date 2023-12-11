//
// Created by Dustella on 12/9/2023.
//

#ifndef STUDENTMANAGER_MAINMENU_H
#define STUDENTMANAGER_MAINMENU_H


#include "UI.h"

class MainMenu : public UI {
public:
    void show() override;

    UI *getNextFrame() override;
};

class StudentActionMenu : public UI {
public:
    void show() override;

    UI *getNextFrame() override;
};

class ScoreActionMenu : public UI {
public:
    void show() override;

    UI *getNextFrame() override;
};

class StatisticMenu : public UI {
public:
    void show() override;

    UI *getNextFrame() override;
};


#endif //STUDENTMANAGER_MAINMENU_H
