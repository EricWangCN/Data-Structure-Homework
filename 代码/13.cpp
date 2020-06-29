//Programmed by Zilong Wang, E-mail:wangzilong@bjtu.edu.cn, SCIT, BJTU, 2020-05-02
#include<bits/stdc++.h>

using namespace std;

typedef struct BinaryTree {
    BinaryTree* sLeftSubtree;
    BinaryTree* sRightSubtree;
    char cValue;
} BTree;

void CreateBinaryTree(BTree* node);
void Recursive_PreOrderTraversal(BTree* node);
vector<char> Recursive_InOrderTraversal(BTree* node);
vector<char> Recursive_PostOrderTraversal(BTree* node);
vector<char> NonRecursive_InOrderTraversal(BTree* root);
vector<char> NonRecursive_LevelOrderTraversal(BTree* root);
int GetTreeDepth(BTree* root);
void DisplayResult(vector<char> cValues);

int main () {
    BTree* root;
    vector<char> cValues;
    string temp;
    int iIter = 0;

    cout << "请输入先序遍历的扩展序列：\n";
    CreateBinaryTree(root);
    cout << "正在按照该序列建立二叉树......\n";
    

    cout << "\n递归先序遍历结果：\n";
    //cValues = Recursive_PreOrderTraversal(root);
    //DisplayResult(cValues);

    cout << "\n递归中序遍历结果：\n";
    cValues = Recursive_InOrderTraversal(root);
    DisplayResult(cValues);

    cout << "\n递归后序遍历结果：\n";
    cValues = Recursive_PostOrderTraversal(root);
    DisplayResult(cValues);

    cout << "\n非递归中序遍历结果：\n";
    cValues = NonRecursive_InOrderTraversal(root);
    DisplayResult(cValues);

    cout << "\n非递归层次遍历结果：\n";
    cValues = NonRecursive_LevelOrderTraversal(root);
    DisplayResult(cValues);

    cout << "\n二叉树深度为:\n" << GetTreeDepth(root);

    return 0;
}

void CreateBinaryTree(BTree* node) {
    char ch;
    scanf("%c", &ch);
    if (ch == '#') {
        node = NULL;
    } else {
        node = new BTree;
        node->cValue = ch;
        CreateBinaryTree(node->sLeftSubtree);
        CreateBinaryTree(node->sRightSubtree);
    }
    /*
    int iMaxSize = cValues.size();
    if (iIter >= iMaxSize) {
        return;
    }
    if (cValues[iIter] != '.') {
        node = new BTree;
        node->cValue = cValues[iIter++];
    }
    CreateBinaryTree(cValues, node->sLeftSubtree, iIter);
    CreateBinaryTree(cValues, node->sRightSubtree, iIter);
    */
}

void Recursive_PreOrderTraversal(BTree* node) {
    cout << node->cValue;
    Recursive_PostOrderTraversal(node->sLeftSubtree);
    Recursive_PostOrderTraversal(node->sRightSubtree);
}

vector<char> Recursive_InOrderTraversal(BTree* node) {
    vector<char> cResults;

    return cResults;   
}

vector<char> Recursive_PostOrderTraversal(BTree* node) {
    vector<char> cResults;

    return cResults;    
}

vector<char> NonRecursive_InOrderTraversal(BTree* root) {
    vector<char> cResults;

    return cResults;    
}

vector<char> NonRecursive_LevelOrderTraversal(BTree* root) {
    vector<char> cResults;

    return cResults;    
}

int GetTreeDepth(BTree* root) {
    int iDepth;

    return iDepth;
}

void DisplayResult(vector<char> cValues) {
    for (int i = 0; i < cValues.size(); ++i) {
        cout << cValues[i] << ' ';
    }
    cout << '\n';
}