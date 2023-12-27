//
// Created by Dustella on 12/12/2023.
//

#include "StatisticsDetail.h"
#include "../stores/Store.h"
#include "MainMenu.h"
#include <iostream>

using namespace std;

void StatisticsCountingView::show() {
  cout << "ͳ����Ϣ" << endl;

  auto store = Store::getStudent();
  auto students = store->getAll();

  cout << "ѧ��������" << students.size() << endl;

  auto schoolMapping = store->getSchoolCountMapping();
  auto classMapping = store->getClassCountMapping();

  cout << "��ѧУͳ�ƣ�" << endl;
  for (auto &item : schoolMapping) {
    cout << item.first << ": " << item.second << endl;
  }

  cout << "���༶ͳ�ƣ�" << endl;
  for (auto &item : classMapping) {
    cout << item.first << ": " << item.second << endl;
  }
}

UI *StatisticsCountingView::getNextFrame() {
  cout << "�����������ݷ���" << endl;
  string dummy;
  cin >> dummy;
  return new StatisticMenu();
}

void StatisticsFailuresView::show() {
  cout << "ͳ����Ϣ" << endl;

  auto store = Store::getScore();

  auto failed = store->getFailedScores();

  cout << "������������" << failed.size() << endl;

  cout << "������ɼ���Ϣ��" << endl;
  for (auto &item : failed) {
    item.show();
  }
}

UI *StatisticsFailuresView::getNextFrame() {
  cout << "�����������ݷ���" << endl;
  string dummy;
  cin >> dummy;
  return new StatisticMenu();
}

void StatisticsAverageView::show() {
  cout << "ͳ����Ϣ" << endl;

  auto store = Store::getScore();

  auto average = store->getAverageScores();

  cout << "ƽ���ɼ���Ϣ��" << endl;
  for (auto &item : average) {
    item.show();
  }
}