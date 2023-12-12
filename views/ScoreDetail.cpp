//
// Created by Dustella on 12/10/2023.
//

#include "ScoreDetail.h"
#include "../models/Score.h"
#include "../stores/Store.h"
#include "MainMenu.h"
#include <iostream>

using namespace std;

void ScoreAddView::show() {
    cout << "成绩添加" << endl;

    auto new_score = new Score();
    new_score->fromUserInput();

    auto store = Store::getScore();
    store->add(*new_score);

}

UI *ScoreAddView::getNextFrame() {
    cout << "成功添加，输入任意内容返回" << endl;
    string dummy;
    cin >> dummy;
    return new ScoreActionMenu();
}

void ScoreEditView::show() {
    cout << "编辑成绩" << endl;

    int id;
    cout << "输入成绩编号" << endl;
    cin >> id;

    auto store = Store::getScore();
    auto score = store->get(id);

    if (score.getId() == 0) {
        cout << "未找到成绩信息" << endl;
        return;
    }

    cout << "查找到的成绩信息" << endl;

    Score::showHeader();
    score.show();

    cout << "请输入修改后的成绩信息" << endl;
    score.fromUserInput();
    store->update(score);
    cout << "修改成功" << endl;
}

UI *ScoreEditView::getNextFrame() {
    cout << "输入任意内容返回" << endl;
    string dummy;
    cin >> dummy;
    return new ScoreActionMenu();
}

void ScoreDeleteView::show() {
    cout << "Delete Student View" << endl;
    int id;
    cout << "请输入成绩编号" << endl;
    cin >> id;
    auto store = Store::getScore();
    auto score = store->get(id);
    if (score.getId() == 0) {
        cout << "未找到成绩" << endl;
        return;
    }
    store->remove(id);

    cout << "删除成功" << endl;
}

UI *ScoreDeleteView::getNextFrame() {
    cout << "输入任意内容返回" << endl;
    string dummy;
    cin >> dummy;
    return new ScoreActionMenu();
}