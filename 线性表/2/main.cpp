/*
 * Author: Wang Zilong
 * E-mail: wangzilong@bjtu.edu.cn
 * Class: CS1804
 * Student ID: 18281218
 */
#include<cstdio>
#include<mm_malloc.h>
#include <time.h>
typedef struct node   //线性表的单向循环链式存储结构
{	int data;                   //数据域
    struct node *next;    //指向后继结点的指针域
}Lnode,*LinkList;

void CreatList(LinkList L,int n) {  //表尾插入结点构造指定长度的单向循环链表
    int i;
    Lnode *p,*s;
    srand(time(NULL));
    p=L;   //p表示表尾结点
    for(i=1;i<n;i++)
    {
        s=(LinkList)malloc(sizeof(Lnode));
        int num = rand() % 100;
        s->data=num;
        s->next=p->next;
        p->next=s;
        p=s;
    }
}

void printList(LinkList L,int n) {  //输出单向循环链表
    Lnode *p=L;
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d  ",p->data);
        p=p->next;
    }
}

void LinkListDelete(LinkList L,int n,int m)  //依次删除线性表的第m个元素
{	Lnode *p,*s;
    int i,j;  //p指向单向循环链表的第一个结点，j为计数器
    p=L;
    for(i=0;i<n;i++) {
        j = 1;
        while (j < m - 1)   //沿指针向后查找，直到p指向第m-1个元素
        {
            p = p->next;
            j++;
        }
        //s指向第m个元素,删除该结点
        s=p->next;
        p->next=s->next;
        m = s->data;
        printf("%d出列，密码变更为：%d\n",m ,m );
        free(s);
        p=p->next;
    }
}


int main() {
    LinkList L;
    int m,n;
    L=(LinkList)malloc(sizeof(Lnode)); //构造不带头结点的单链表
    srand(time(nullptr));
    L->data=rand()%100;
    L->next=L;

    printf("请输入参与游戏的初始人数：\n");
    scanf("%d",&n);	CreatList(L,n);
    printf("\n参与游戏人员编号分别为：\n");
    printList(L,n);
    printf("\n");
    m = rand()%100;
    printf("\n随机报数上限为：%d\n游戏开始！\n",m);
    LinkListDelete(L,n,m);
    printf("\n");

    return 0;
}