//Test statics: 53 17 78 9 45 65 87 23
#include <bits/stdc++.h>
using namespace std;
typedef struct BinarySortTree{
    int val;
    struct BinarySortTree* lChild;
    struct BinarySortTree* rChild;
}*BSTree;

bool insert(BSTree &root, int value);
bool deleteElement(BSTree &root, int value);
void print(BSTree root);

int main() {
    int n, num;
    BSTree root = nullptr;
    cout << "请输入二叉排序树的结点数：";
    cin >> n;
    cout << "请依次输入结点值：";
    while (n-- > 0) {
        scanf("%d", &num);
        if (!insert(root, num)) cout << num << "：插入失败！\n";
    }
    print(root);
    while (true) {
        cout << "请输入要删除的数据，输入\"-1\"以退出：";
        cin >> num;
        if (num == -1) return 0;
        if (!deleteElement(root, num)) cout << num << "：删除失败！（不存在）\n";
        print(root);
    }
}

bool insert(BSTree &root, int value) {
    if (root == nullptr) {
        root = (BSTree)malloc(sizeof(BinarySortTree));
        root->val = value;
        root->rChild = nullptr;
        root->lChild = nullptr;
    } else {
        if (value < root->val) return insert(root->lChild, value);
        else if (value > root->val) return insert(root->rChild, value);
        else return false;
    }
    return true;
}

bool deleteElement(BSTree &root, int value) {
    if (root->val == value) {
        if (root->lChild == nullptr && root->rChild == nullptr) {
            root = nullptr;
        } else if (root->rChild == nullptr && root->lChild != nullptr) {
            BSTree tmp = root;
            root = root->lChild;
            free(tmp);
        } else if (root->rChild != nullptr && root->lChild == nullptr) {
            BSTree tmp = root;
            root = root->rChild;
            free(tmp);
        } else {
            BSTree q = root, p = root->lChild;
            while (p->rChild) {
                q = p;
                p = p->rChild;
            }
            root->val = p->val;
            if (q != root) q->rChild = p->lChild;
            else q->lChild = p->lChild;
            delete p;
        }
    } else {
        if (value > root->val) {
            if (root->rChild == nullptr) return false;
            else return deleteElement(root->rChild, value);
        } else {
            if (root->lChild == nullptr) return false;
            else return deleteElement(root->lChild, value);
        }
    }
    return true;
}

void a1(BSTree root) {
    cout << root->val << " ";
    if (root->lChild != nullptr) a1(root->lChild);
    if (root->rChild != nullptr) a1(root->rChild);
}
void a2(BSTree root) {
    if (root->lChild != nullptr) a2(root->lChild);
    cout << root->val << " ";
    if (root->rChild != nullptr) a2(root->rChild);
}

void print(BSTree root) {
    cout << "前序遍历：";
    a1(root);
    cout << "\n中序遍历：";
    a2(root);
    cout << "\n\n";
}