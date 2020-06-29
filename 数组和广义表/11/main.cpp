#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct {
    int line;
    int row;
    int data;
}ArrayElem;

typedef struct {
    ArrayElem a[100];
    int lines;
    int rows;
    int notzero;
}Array;

void Transpose(Array* a, Array* b);

int main() {
    Array origin, transpose;
    origin.notzero = 0;
    transpose.notzero = 0;
    cout << "请输入行数和列数" << endl;
    cin >> origin.lines >> origin.rows;

    int inRow, inLine, inData;
    for (int i = 0; ; i++) {
        cout << "输入数据（行、列、数值（0 0 0退出））:" << endl;
        cin >> inLine >> inRow >> inData;
        if (inLine == 0 && inRow == 0 && inData == 0) {
            break;
        }
        origin.a[i].line = inLine;
        origin.a[i].row = inRow;
        origin.a[i].data = inData;
        origin.notzero++;
    }
    cout << "转置前：\n";
    for (int i = 0; i < origin.notzero; i++) {
        cout << origin.a[i].line << "," << origin.a[i].row << ":" << origin.a[i].data << endl;
    }
    cout << "转置后：\n";
    Transpose(&origin, &transpose);
    for (int i = 0; i < transpose.notzero; i++) {
        cout << transpose.a[i].line << "," << transpose.a[i].row << ":" << transpose.a[i].data << endl;
    }
}

void Transpose(Array* a, Array* b) {
    b->lines = a->rows;
    b->rows = a->lines;
    b->notzero = a->notzero;
    if (b->notzero) {
        int k = 0;
        for (int i = 1; i <= a->lines; i++) {
            for (int j = 0; j < a->notzero; j++) {
                if (a->a[j].row == i) {
                    b->a[k].line = a->a[j].row;
                    b->a[k].row = a->a[j].line;
                    b->a[k].data = a->a[j].data;
                    k++;
                }
            }
        }
    }
}