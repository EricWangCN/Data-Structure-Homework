#include "stdio.h"
#define  n  9          /* n-1为皇后个数，m为摆法计数*/
int m=0,a[n];           /* a[i]存放第i个皇后放置的行号*/

int ok(int i, int j)         /*检查(i,j)上能否放棋子*/
{
    int j1,i1,ok1;
    j1=j; //表示行
    i1=i; //表示列
    ok1=1;   /*检查第i行上能否放棋子*/
    while( (j1>1) && ok1 )
    {
        j1--;
        ok1=a[j1]!=i;//判断是否有相等
    }
    j1=j;
    i1=i;          /*检查对角线上能否放棋子*/
    while( (j1>1) && (i1>1) && ok1)
    {
        j1--; i1--;
        ok1=a[j1]!=i1;
    }
    j1=j;
    i1=i;          /*检查另一对角线上能否放棋子*/
    while( (j1>1) && (i1<n-1) && ok1)
    {
        j1--;
        i1++;
        ok1=a[j1]!=i1;
    }
    return  ok1;//返回值
}

void  queen(int j)      /*从第j列开始逐个试探*/
{
    int i;
    if (j>=n) //这里的j为形参
    {
        m++;  printf("m=%d   ",m);
        for (i=1;i<n;i++)
            printf("    %d",a[i]);//输出行号
        printf("\n");
    }
    else
        for( i=1; i<n;i++)
            if(ok(i,j))      /*检查(i,j)上能否放棋子*/
            {
                a[j]=i;    /*在(i,j)上放一个棋子*/
                queen(j+1);//j+1在这里完成
            }

}

int main()
{
    printf("八皇后问题的解:\n");
    queen(1);
    getchar();

}