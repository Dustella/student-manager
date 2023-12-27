//
// Created by Dustella on 12/12/2023.
//

#ifndef STUDENTMANAGER_STATISTICSDETAIL_H
#define STUDENTMANAGER_STATISTICSDETAIL_H


#include "UI.h"

class StatisticsCountingView : public UI {
public:
    void show() override;

    UI *getNextFrame() override;

};

class StatisticsFailuresView : public UI {
public:
    void show() override;

    UI *getNextFrame() override;

};

class StatisticsBirthplaceView : public UI {
public:
    void show() override;

    UI *getNextFrame() override;

};


#endif //STUDENTMANAGER_STATISTICSDETAIL_H
