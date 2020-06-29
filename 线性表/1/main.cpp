/***********************************
 Author: Zilong Wang
 E-mail: wangzilong@bjtu.edu.cn
 Student ID: 18281218
 Class: CS1804
 Date: Mar.9th, 2020
***********************************/
#include <bits/stdc++.h>

#define LIST_INIT_SIZE 2 //初始分配存储空间
#define LIST_INCREASE 2 //存储空间分配增量

using namespace std;

//声明员工信息结构体
typedef struct EmployeeInformation {
    char name[30];
    int ID;
    char position[30];
} EmInfo;

//声明线性表结点
typedef struct EmployeeList {
    EmInfo *elem;
    int length;
    int listSize;
} EmList;

int ListInit(EmList *L); //初始化线性表
int ListInsert(EmList *L, EmInfo elem); //插入元素
int ListDelete(EmList *L, int pos); //删除元素
void ListPrint(EmList *L); //打印线性表

int main() {
    EmList *emList;
    ListInit(emList);
    int choose = 1;
    while (choose != 0) {
        cout << "\n\n选择功能\n";
        cout << "1. 员工入职\n";
        cout << "2. 员工离职\n";
        cout << "0. 退出\n";
        cin >> choose;
        if (choose == 1) {
            EmInfo emInfo;
            char str[30];
            int ID;
            cout << "请输入员工姓名: ";
            cin >> str;
            strcpy(emInfo.name, str);
            cout << "请输入员工工号: ";
            cin >> ID;
            emInfo.ID = ID;
            cout << "请输入员工职务: ";
            cin >> str;
            strcpy(emInfo.position, str);
            ListInsert(emList, emInfo);
            ListPrint(emList);
        } else if (choose == 2) {
            int pos;
            cout << "请输入离职员工序号: ";
            cin >> pos;
            ListDelete(emList, pos);
            ListPrint(emList);
        }
    }
    return 0;
}

////////////////////////////////////// - Functions - ///////////////////////////////////////

int ListInit(EmList *L) {
    L->elem = (EmInfo *)malloc(LIST_INIT_SIZE * sizeof(EmInfo));
    if (!L->elem) {
        exit(-1); //储存分配失败
    }
    L->length = 0;
    L->listSize = LIST_INIT_SIZE;

    return 1;
}

int ListInsert(EmList *L, const EmInfo elem) {
    if (L->length >= L->listSize) { //线性表空间不足，增加空间分配
        auto *newBase = (EmInfo *)malloc((L->listSize + LIST_INCREASE) * sizeof(EmInfo));
        if (!newBase) {
            exit(-1);
        }
        for (int i = 0; i < L->length; ++i) {
            newBase[i] = L->elem[i];
        }
        L->elem = newBase;
        L->listSize += LIST_INCREASE;
    }
    L->elem[L->length++] = elem;

    return 1;
}

int ListDelete(EmList *L, int pos) {
    if (pos < 1 || pos > L->length) {
        return -1;
    }
    for (int i = pos - 1; i < L->length - 1; ++i) {
        L->elem[i] = L->elem[i + 1];
    }
    L->length--;

    return 1;
}

void ListPrint(EmList *L) {
    cout << "\n---------------------------------------\n序号\t姓名\t工号\t职务\n";
    for (int i = 0; i < L->length; ++i) {
        cout << i+1 << '\t' << L->elem[i].name << '\t' << L->elem[i].ID << '\t' << L->elem[i].position << '\n';
    }
}