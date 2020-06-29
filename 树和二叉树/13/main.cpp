//Programmed by Zilong Wang, E-mail:wangzilong@bjtu.edu.cn, SCIT, BJTU, 2020-05-02
#include<bits/stdc++.h>

using namespace std;

typedef struct BinaryTree {
    BinaryTree* sLeftSubtree;
    BinaryTree* sRightSubtree;
    char cValue;
} BTree;

BinaryTree * CreateBinaryTree();
void Recursive_PreOrderTraversal(BTree* node);
void Recursive_InOrderTraversal(BTree* node);
void Recursive_PostOrderTraversal(BTree* node);
void NonRecursive_InOrderTraversal(BTree* root);
void NonRecursive_LevelOrderTraversal(BTree* root);
int GetTreeDepth(BTree* root);

int main () {
    BTree* root;
    vector<char> cValues;
    string temp;

    cout << "请输入先序遍历的扩展序列：\n";
    root = CreateBinaryTree();
    cout << "正在按照该序列建立二叉树......\n";

    cout << "递归先序遍历结果：\n";
    Recursive_PreOrderTraversal(root);

    cout << "\n递归中序遍历结果：\n";
    Recursive_InOrderTraversal(root);

    cout << "\n递归后序遍历结果：\n";
    Recursive_PostOrderTraversal(root);

    cout << "\n非递归中序遍历结果：\n";
    NonRecursive_InOrderTraversal(root);

    cout << "\n非递归层次遍历结果：\n";
    NonRecursive_LevelOrderTraversal(root);

    cout << "\n二叉树深度为:\n" << GetTreeDepth(root);

    return 0;
}

BTree * CreateBinaryTree() {
    BTree* node;
    char ch;
    scanf("%c", &ch);
    if (ch == '#') {
        node = nullptr;
    } else {
        node = new BTree ;
        node->cValue = ch;
        node->sLeftSubtree = CreateBinaryTree();
        node->sRightSubtree = CreateBinaryTree();
    }
    return node;
}

void Recursive_PreOrderTraversal(BTree* node) {
    if (node) {
        cout << node->cValue;
        Recursive_PreOrderTraversal(node->sLeftSubtree);
        Recursive_PreOrderTraversal(node->sRightSubtree);
    }
}

void Recursive_InOrderTraversal(BTree* node) {
    if (node) {
        Recursive_InOrderTraversal(node->sLeftSubtree);
        cout << node->cValue;
        Recursive_InOrderTraversal(node->sRightSubtree);
    }
}

void Recursive_PostOrderTraversal(BTree* node) {
    if (node) {
        Recursive_PostOrderTraversal(node->sLeftSubtree);
        Recursive_PostOrderTraversal(node->sRightSubtree);
        cout << node->cValue;
    }
}

void NonRecursive_InOrderTraversal(BTree* root) {
    stack<BTree *> stack;
    BTree *T = root;
    while (T || !stack.empty()) {
        while (T) {
            stack.push(T);
            T = T->sLeftSubtree;
        }
        if (!stack.empty()) {
            T = stack.top();
            stack.pop();
            cout << T->cValue;
            T = T->sRightSubtree;
        }
    }
}

void NonRecursive_LevelOrderTraversal(BTree* root) {
    queue<BTree *> queue;
    BTree * T;
    queue.push(root);
    bool flag = true;
    while (queue.front() != queue.back() || flag) {
        flag = false;
        T = queue.front();
        queue.pop();
        cout << T->cValue;
        if (T->sLeftSubtree) {
            queue.push(T->sLeftSubtree);
        }
        if (T->sRightSubtree) {
            queue.push(T->sRightSubtree);
        }
    }
    cout << queue.front()->cValue;
}

int GetTreeDepth(BTree* root) {
    if (!root) {
        return 0;
    } else {
        return max(GetTreeDepth(root->sLeftSubtree), GetTreeDepth(root->sRightSubtree))+1;
    }
}