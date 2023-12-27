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
  cout << "������ѧ��" << endl;
  cin >> id;
  cout << "id: " << id << endl;
  Student stu = *new Student(id);
  stu.fromUserInput();
  cout << stu.toRecordLine() << endl;

  auto studentStore = Store::getStudent();
  studentStore->add(stu);
  cout << "��ӳɹ�" << endl;
}

UI *StudentAddView::getNextFrame() {
  UI *nextFrame = new StudentActionMenu();
  return nextFrame;
}

void StudentEditView::show() {
  cout << "Student Edit View" << endl;
  int id;
  cout << "������ѧ��" << endl;
  cin >> id;
  cout << "id: " << id << endl;
  auto studentStore = Store::getStudent();
  auto stu = studentStore->get(id);
  if (stu.getId() == 0) {
    cout << "δ�ҵ�ѧ����Ϣ" << endl;
    cout << "�����������" << endl;
    string dummy;
    cin >> dummy;
    return;
  }
  cout << "���ҵ���ѧ����Ϣ" << endl;
  Student::showHeader();
  stu.show();
  cout << "�������޸ĺ��ѧ����Ϣ" << endl;
  stu.fromUserInput();
  studentStore->update(stu);
  cout << "�޸ĳɹ�" << endl;
}

UI *StudentEditView::getNextFrame() {
  UI *nextFrame = new StudentActionMenu();
  return nextFrame;
}

void StudentDeleteView::show() {
  cout << "Student Delete View" << endl;
  int id;
  cout << "������ѧ��" << endl;
  cin >> id;
  cout << "id: " << id << endl;
  auto studentStore = Store::getStudent();
  auto stu = studentStore->get(id);
  if (stu.getId() == 0) {
    cout << "δ�ҵ�ѧ����Ϣ" << endl;
    cout << "�����������ݷ���" << endl;
    string dummy;
    cin >> dummy;
    return;
  }
  studentStore->remove(id);
  cout << "ɾ���ɹ�" << endl;
}

UI *StudentDeleteView::getNextFrame() {
  UI *nextFrame = new StudentActionMenu();
  return nextFrame;
}