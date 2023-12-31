//
// Created by Dustella on 12/9/2023.
//

#include "MainMenu.h"
#include "UI.h"
#include "StudentDetail.h"
#include "../stores/Store.h"
#include "ScoreDetail.h"
#include <iostream>

using namespace std;

void MainMenu::show() {
    cout << "====主菜单====" << endl;
    cout << "1. 学生操作" << endl;
    cout << "2. 成绩操作" << endl;
    cout << "3. 统计数据" << endl;
    cout << "4. 退出程序" << endl;
}

UI *MainMenu::getNextFrame() {
    int action;
    cin >> action;
    switch (action) {
        case 1: {
            auto studentActionMenu = new StudentActionMenu();
            return studentActionMenu;
        }
        case 2: {
            auto scoreActionMenu = new ScoreActionMenu();
            return scoreActionMenu;
        }
        case 3: {
            auto statisticMenu = new StatisticMenu();
            return statisticMenu;
        }
        case 4: {
            exit(0);
        }
        default: {
            cout << "Invalid action" << endl;
            return this;
        }
    }

}

void StudentActionMenu::show() {
    cout << "====学生操作====" << endl;
    auto studentStore = Store::getStudent();

    auto allInfo = studentStore->getAll();
    Student::showHeader();
    for (const auto &item: allInfo) {
        item.show();
    }
    cout << "1. 添加学生   ";
    cout << "2. 删除学生   ";
    cout << "3. 修改学生   ";
    cout << "4. 返回上一级" << endl;
}

UI *StudentActionMenu::getNextFrame() {
    int action;
    cin >> action;
    switch (action) {
        case 1:
            return new StudentAddView();
        case 2:
            return new StudentDeleteView();
        case 3:
            return new StudentEditView();
        case 4:
            return new MainMenu();
        default: {
            cout << "Invalid action" << endl;
            return this;
        }
    }
}

void ScoreActionMenu::show() {
    cout << "成绩操作" << endl;
    auto scoreStore = Store::getScore();
    auto allItems = scoreStore->getAll();
    for (auto item: allItems) {
        item.show();
    }

    cout << "Score Action Menu" << endl;
    cout << "1. 添加成绩" << endl;
    cout << "2. 删除成绩" << endl;
    cout << "3. 修改成绩" << endl;
    cout << "4. 返回上一级" << endl;
}

UI *ScoreActionMenu::getNextFrame() {
    int action;
    cin >> action;
    switch (action) {
        case 1:
            return new ScoreAddView();
        case 2:
            return new ScoreDeleteView();
        case 3:
            return new ScoreEditView();
        case 4:
            return new MainMenu();
        default:
            return this;
    }
}

void StatisticMenu::show() {
    cout << "====统计数据====" << endl;
    cout << "1. 院系统计" << endl;
    cout << "2. 挂科分布" << endl;
    cout << "3. 籍贯查询" << endl;
    cout << "4. 返回上一级" << endl;
}

UI *StatisticMenu::getNextFrame() {
    int action;
    cin >> action;
    switch (action) {

        default: {
            cout << "Invalid action" << endl;
            return this;
        }
    }
}






