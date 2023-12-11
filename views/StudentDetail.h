//
// Created by Dustella on 12/10/2023.
//

#ifndef STUDENTMANAGER_STUDENTDETAIL_H
#define STUDENTMANAGER_STUDENTDETAIL_H


#include "UI.h"

class StudentAddView : public UI {
public:
    void show() override;

    UI *getNextFrame() override;

};


class StudentEditView : public UI {
public:
    void show() override;

    UI *getNextFrame() override;
};

class StudentDeleteView : public UI {
public:
    void show() override;

    UI *getNextFrame() override;
};


#endif //STUDENTMANAGER_STUDENTDETAIL_H
