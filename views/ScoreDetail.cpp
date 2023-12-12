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
    cout << "�ɼ����" << endl;

    auto new_score = new Score();
    new_score->fromUserInput();

    auto store = Store::getScore();
    store->add(*new_score);

}

UI *ScoreAddView::getNextFrame() {
    cout << "�ɹ���ӣ������������ݷ���" << endl;
    string dummy;
    cin >> dummy;
    return new ScoreActionMenu();
}

void ScoreEditView::show() {
    cout << "�༭�ɼ�" << endl;

    int id;
    cout << "����ɼ����" << endl;
    cin >> id;

    auto store = Store::getScore();
    auto score = store->get(id);

    if (score.getId() == 0) {
        cout << "δ�ҵ��ɼ���Ϣ" << endl;
        return;
    }

    cout << "���ҵ��ĳɼ���Ϣ" << endl;

    Score::showHeader();
    score.show();

    cout << "�������޸ĺ�ĳɼ���Ϣ" << endl;
    score.fromUserInput();
    store->update(score);
    cout << "�޸ĳɹ�" << endl;
}

UI *ScoreEditView::getNextFrame() {
    cout << "�����������ݷ���" << endl;
    string dummy;
    cin >> dummy;
    return new ScoreActionMenu();
}

void ScoreDeleteView::show() {
    cout << "Delete Student View" << endl;
    int id;
    cout << "������ɼ����" << endl;
    cin >> id;
    auto store = Store::getScore();
    auto score = store->get(id);
    if (score.getId() == 0) {
        cout << "δ�ҵ��ɼ�" << endl;
        return;
    }
    store->remove(id);

    cout << "ɾ���ɹ�" << endl;
}

UI *ScoreDeleteView::getNextFrame() {
    cout << "�����������ݷ���" << endl;
    string dummy;
    cin >> dummy;
    return new ScoreActionMenu();
}