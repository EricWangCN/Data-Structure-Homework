// Test : 5 12 3 76 2 9 16
#include <bits/stdc++.h>
#define MAP_LENGTH 11
#define NULLKEY -1
#define Hash(a) a%MAP_LENGTH
using namespace std;

typedef struct HashTable {
    int *elem;
    int count;
    int sizeIndex;
}HTable;

int InitTable (HTable& table);
bool SearchHash (HTable H, int K, int& p, int& c);
bool InsertHash (HTable& H, int e);

int main() {
    HTable table;
    InitTable(table);
    int n, num;

    cout << "请输入序列长度：";
    cin >> n;
    cout << "请依次输入序列中数字：";
    for (int i = 0; i < n; ++i) {
        cin >> num;
        if (!InsertHash(table, num)) cout << "数字" << num << "插入失败！\n";
    }
    cout << "Hash表为：";
    for (int i = 0; i < 11; ++i) cout << table.elem[i] << " ";
    cout << '\n';
    while (true) {
        cout << "请输入需要查询的数字（以\"-1\"为结束）：";
        cin >> num;
        if (num == -1) return 0;
        int p = 0, c = 0;
        if (SearchHash(table, num, p, c)) cout << "找到" << num << "！\n";
        else cout << num << "没有找到！\n";
    }
    return 0;
}

int InitTable (HTable& table) {
    table.sizeIndex = MAP_LENGTH;
    table.count = 0;
    table.elem = (int*)malloc(table.sizeIndex * sizeof(int));
    for (int i = 0; i < table.sizeIndex; ++i) table.elem[i] = -1;
}

bool SearchHash (HTable H, int K, int& p, int& c) {
    p = Hash((K + c));
    if (c > H.sizeIndex) return false;
    if (H.elem[p] != NULLKEY && K != H.elem[p]) {
        return SearchHash(H, K, p, ++c);
    } else return H.elem[p] != NULLKEY && K == H.elem[p];
}

bool InsertHash (HTable& H, int e) {
    int c = 0;
    int p;
    if (SearchHash(H, e, p, c)) return false;
    else {
        if (H.count < H.sizeIndex) {
            H.count++;
            H.elem[Hash((c+e))] = e;
            return true;
        } else {
            return false;
        }
    }
}
