//
// Created by Dustella on 12/10/2023.
//

#include "StudentDetail.h"
#include "../models/Student.h"
#include "../stores/Store.h"
#include "MainMenu.h"
#include <iostream>

using namespace std;

void StudentAddView::show() {

  cout << "Student Add View" << endl;
  int id;
  cout << "请输入学号" << endl;
  cin >> id;
  cout << "id: " << id << endl;
  Student stu = *new Student(id);
  stu.fromUserInput();
  cout << stu.toRecordLine() << endl;

  auto studentStore = Store::getStudent();
  studentStore->add(stu);
  cout << "添加成功" << endl;
}

UI *StudentAddView::getNextFrame() {
  UI *nextFrame = new StudentActionMenu();
  return nextFrame;
}

void StudentEditView::show() {
  cout << "Student Edit View" << endl;
  int id;
  cout << "请输入学号" << endl;
  cin >> id;
  cout << "id: " << id << endl;
  auto studentStore = Store::getStudent();
  auto stu = studentStore->get(id);
  if (stu.getId() == 0) {
    cout << "未找到学生信息" << endl;
    cout << "按任意键返回" << endl;
    string dummy;
    cin >> dummy;
    return;
  }
  cout << "查找到的学生信息" << endl;
  Student::showHeader();
  stu.show();
  cout << "请输入修改后的学生信息" << endl;
  stu.fromUserInput();
  studentStore->update(stu);
  cout << "修改成功" << endl;
}

UI *StudentEditView::getNextFrame() {
  UI *nextFrame = new StudentActionMenu();
  return nextFrame;
}

void StudentDeleteView::show() {
  cout << "Student Delete View" << endl;
  int id;
  cout << "请输入学号" << endl;
  cin >> id;
  cout << "id: " << id << endl;
  auto studentStore = Store::getStudent();
  auto stu = studentStore->get(id);
  if (stu.getId() == 0) {
    cout << "未找到学生信息" << endl;
    cout << "输入任意内容返回" << endl;
    string dummy;
    cin >> dummy;
    return;
  }
  studentStore->remove(id);
  cout << "删除成功" << endl;
}

UI *StudentDeleteView::getNextFrame() {
  UI *nextFrame = new StudentActionMenu();
  return nextFrame;
}