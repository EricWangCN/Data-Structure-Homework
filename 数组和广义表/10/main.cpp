#include <stdio.h>

int main() {
    int a[1000][1000],line,row;
    printf("请输入矩阵的列数:");
    scanf("%d",&line);
    printf("请输入矩阵的行数:");
    scanf("%d",&row);
    for (int i = 0; i < line; ++i) {
        printf("请输入第%d行数字:",i+1);
        for (int j = 0; j < row; ++j) {
            scanf("%d",&a[i][j]);
        }
    }
    for (int i = 0; i < line; ++i) {
        int m = 0,max = 0;
        for (int j = 0; j < row; ++j) {
            if (a[i][j] > a[i][max]) max = j;
        }
        for (int k = 0; k < line; ++k) {
            if (a[i][max] > a[k][max]) m = 1;
        }
        if (!m) {
            printf("(%d,%d)=%d 是鞍点\n",i+1,max+1,a[i][max]);
            return 0;
        }
    }
    printf("没有鞍点!\n");
    return 0;
}