#include <iostream>
#include <stdlib.h>
#include <queue>
#define MaxVertexNum 100 //最大顶点数
//#define INFINITY 0  //无穷大设为无符号整数的最大值
typedef char VertexType;  //顶点类型设为字符类型
typedef int EdgeType; ///边的权值设为整形
enum GraphType{DG, UG, DN, UN}; //有向图，无向图，有向网图，无向网图
using namespace std;

typedef struct
{
    VertexType Vertices[MaxVertexNum]; //顶点表
    EdgeType Edges[MaxVertexNum][MaxVertexNum]; //邻接矩阵，即边表
    int n, e; //顶点数n和边数e
    enum GraphType GType;
}MGraph;

void CreateMGraph(MGraph *G)
{
    int  i, j, k, w;
    G->GType = UN;    /* Undirected Network  无向网图  */
    cout << "请输入顶点数和边数(输入格式为:顶点数, 边数):" << endl;
    cin >> G->n >> G->e; /* 输入顶点数和边数 */
    cout << "请输入顶点信息(输入格式为:顶点号<CR>):" << endl;
    for (i = 0; i < G->n; i++)
        cin >> &(G->Vertices[i]); /*  输入顶点信息，建立顶点表  */
    for (i = 0; i < G->n; i++)
        for (j = 0; j < G->n; j++)
            G->Edges[i][j] = 0; /* 初始化邻接矩阵 */
    cout << "请输入每条边对应的两个顶点的序号和权值，输入格式为:i, j, w:" << endl;
    for (k = 0; k < G->e; k++) {
        cin >> i >> j >> w; /* 输入e条边上的权，建立邻接矩阵 */
        G->Edges[i][j] = w;
        G->Edges[j][i] = w; /* 因为无向网图的邻接矩阵是对称的 */
    }
}

void Print(MGraph *G)
{
    cout << "   ";
    for (int i = 0; i < G->n; i++)
        cout << G->Vertices[i] << "  ";
    cout << endl;
    for (int i = 0; i < G->n; i++)
    {
        cout << G->Vertices[i] << "  ";
        for (int j = 0; j < G->n; j++)
        {
            cout << G->Edges[i][j] << "  ";
        }
        cout << endl;
    }
}

//邻接矩阵存储的图 - DFS
bool Visited[100] = { false };
void DFS(MGraph *G, int k)
{
    cout << G->Vertices[k] << " ";
    Visited[k] = true;
    for (int i = 0; i < G->n; i++)
    {
        if (G->Edges[k][i] == 1 && Visited[i] == false)
        {
            DFS(G, i);
        }
    }
}

//邻接矩阵存储的图 - BFS
void BFS(MGraph *G, int k)
{
    bool Visited[100] = { false };
    queue<int> q;
    for (int i = 0; i < G->n; i++)
        Visited[i] = false;

    if (Visited[k] == false) //如果节点未访问
    {
        Visited[k] = true;
        cout << " visit vertex: " << G->Vertices[k] << endl;
        q.push(k); //u入队列
    }
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        for (int w = 0; w < G->n; w++)
        {
            if (G->Edges[t][w] != 0 && Visited[w] == false)
            {
                Visited[w] = true;
                cout << " visited vertex: " << G->Vertices[w] << endl;
                q.push(w);
            }
        }
    }
}
int main()
{
    MGraph *G = new MGraph;
    CreateMGraph(G);
    Print(G);
    cout << endl;
    DFS(G, 0);
    BFS(G, 0);
    return 0;
}