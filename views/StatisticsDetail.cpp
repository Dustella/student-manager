//
// Created by Dustella on 12/12/2023.
//

#include "StatisticsDetail.h"
#include "../stores/Store.h"
#include "MainMenu.h"
#include <iostream>

using namespace std;

void StatisticsCountingView::show() {
  cout << "统计信息" << endl;

  auto store = Store::getStudent();
  auto students = store->getAll();

  cout << "学生总数：" << students.size() << endl;

  auto schoolMapping = store->getSchoolCountMapping();
  auto classMapping = store->getClassCountMapping();

  cout << "按学校统计：" << endl;
  for (auto &item : schoolMapping) {
    cout << item.first << ": " << item.second << endl;
  }

  cout << "按班级统计：" << endl;
  for (auto &item : classMapping) {
    cout << item.first << ": " << item.second << endl;
  }
}

UI *StatisticsCountingView::getNextFrame() {
  cout << "输入任意内容返回" << endl;
  string dummy;
  cin >> dummy;
  return new StatisticMenu();
}

void StatisticsFailuresView::show() {
  cout << "统计信息" << endl;

  auto store = Store::getScore();

  auto failed = store->getFailedScores();

  cout << "不及格人数：" << failed.size() << endl;

  cout << "不及格成绩信息：" << endl;
  for (auto &item : failed) {
    item.show();
  }
}

UI *StatisticsFailuresView::getNextFrame() {
  cout << "输入任意内容返回" << endl;
  string dummy;
  cin >> dummy;
  return new StatisticMenu();
}

void StatisticsAverageView::show() {
  cout << "统计信息" << endl;

  auto store = Store::getScore();

  auto average = store->getAverageScores();

  cout << "平均成绩信息：" << endl;
  for (auto &item : average) {
    item.show();
  }
}