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
    cout << "====���˵�====" << endl;
    cout << "1. ѧ������" << endl;
    cout << "2. �ɼ�����" << endl;
    cout << "3. ͳ������" << endl;
    cout << "4. �˳�����" << endl;
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
    cout << "====ѧ������====" << endl;
    auto studentStore = Store::getStudent();

    auto allInfo = studentStore->getAll();
    Student::showHeader();
    for (const auto &item: allInfo) {
        item.show();
    }
    cout << "1. ���ѧ��   ";
    cout << "2. ɾ��ѧ��   ";
    cout << "3. �޸�ѧ��   ";
    cout << "4. ������һ��" << endl;
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
    cout << "�ɼ�����" << endl;
    auto scoreStore = Store::getScore();
    auto allItems = scoreStore->getAll();
    for (auto item: allItems) {
        item.show();
    }

    cout << "Score Action Menu" << endl;
    cout << "1. ��ӳɼ�" << endl;
    cout << "2. ɾ���ɼ�" << endl;
    cout << "3. �޸ĳɼ�" << endl;
    cout << "4. ������һ��" << endl;
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
    cout << "====ͳ������====" << endl;
    cout << "1. Ժϵͳ��" << endl;
    cout << "2. �ҿƷֲ�" << endl;
    cout << "3. �����ѯ" << endl;
    cout << "4. ������һ��" << endl;
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






