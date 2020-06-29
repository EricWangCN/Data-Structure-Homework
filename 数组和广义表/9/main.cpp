#include <iostream>

using namespace std;

void get_next(char *T,int next[]);
void get_nextval(char *T,int nextval[]);

int main() {
    char str[100];
    int next[100], nextval[100];
    cout << "请输入要判断的字符串:\n";
    cin >> str;
    get_next(str, next);
    get_nextval(str, nextval);
    cout << "next:";
    for (int i = 0; i < strlen(str); ++i) {
        cout << next[i] << " ";
    }
    cout << "\nnextval:";
    for (int i = 0; i < strlen(str); ++i) {
        cout << nextval[i] << " ";
    }
    return 0;
}


void get_next(char *T,int next[]) {
    int i = 1,j = 0;
    next[0] = -1;
    next[1] = 0;
    int m = strlen(T);
    while(i < strlen(T) - 1) {
        if (j == -1 || T[j] == T[i]) {
            ++i;
            ++j;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
    for (int i = 0; i < m; ++i) {
        next[i]++;
    }
}

void get_nextval(char *T,int nextval[]) {
    int i = 1,j = 0;
    nextval[0] = -1;
    nextval[1] = 0;
    int m = strlen(T);
    while (i < strlen(T) - 1) {
        if (j == -1 || T[j] == T[i]) {
            ++i;
            ++j;
            if (T[i] != T[j]) nextval[i] = j;
            else nextval[i] = nextval[j];
        } else {
            j = nextval[j];
        }
    }
    for (int i = 0; i < m; ++i) {
        nextval[i]++;
    }
}