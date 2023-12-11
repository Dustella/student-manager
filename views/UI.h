//
// Created by Dustella on 12/9/2023.
//

#ifndef STUDENTMANAGER_UI_H
#define STUDENTMANAGER_UI_H

class UI {
public:
    virtual void show() = 0;
    virtual UI* getNextFrame() = 0;
    virtual ~UI() = default;

};


#endif //STUDENTMANAGER_UI_H
