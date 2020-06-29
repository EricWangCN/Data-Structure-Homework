/*Programed by Zilong Wang, CS1804, e-mail: wangzilong@bjtu.edu.cn, TEL: 17610100201*/
#include <bits/stdc++.h>
#define MAXTREESIZE 100

typedef struct PTNode{//结点结构
    char data;
    int parent;//双亲位置域
}PTNode;
typedef struct {//树结构
    PTNode nodes[MAXTREESIZE];
    int r,n;//根结点位置和数量
}PTree;

void createTree(PTNode *T, int n)//建立树，双亲表示法
{
    char data;
    int i, parent;
    for(i = 0; i < n; i++)
    {
        scanf("%c %d", &data, &parent);
        getchar();
        T[i].data = data;
        T[i].parent = parent;
    }
}

int Depthtree(PTNode *T, int n)//求树的深度
{
    int i, j, max, depth;
    max = 0;
    for(i = 0; i < n; i++)//循环找双亲结点，每次都令深度为1，在1的基础上能找到几次双亲深度就是几
    {
        depth = 1;
        j = i;
        while(T[j].parent != -1)
        {
            if(j < 0 || j >= n)
            {
                printf("双亲结点超出范围！\n");
                return -1;
            }
            depth++;
            j = T[j].parent;
        }
        max = depth > max ? depth : max;
    }
    return max;
}

int main()
{
    PTNode *T;
    int n;

    printf("请输入结点个数n；\n");
    scanf("%d", &n);
    printf("接下来的 %d 行，每行输入格式为结点内容+空格+双亲结点位置，根节点的双亲位置为-1；\n",n);
    getchar();
    T = (PTNode*)malloc(n * sizeof(PTNode));
    createTree(T, n);//建立树

    printf("该树的深度为：\n");
    printf("%d\n", Depthtree(T, n));

    return 0;
}

