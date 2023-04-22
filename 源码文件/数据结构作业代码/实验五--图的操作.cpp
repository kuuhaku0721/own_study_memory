/*
*（1）采用邻接矩阵/邻接表建立图；
*（2）采用深度优先/广度优先搜索方式遍历图；
*（3）编程实现Dijkstra最短路径算法。
*/
#include <iostream>
#include <string>
#include<queue>
using namespace std;
#define INFINITY 65535  //用INFINITY代表无穷，用于初始化
#define MAXVEX 20
/*邻接矩阵*/
typedef struct
{
	char vexs[100]; //顶点表，暂且定义最大为100
	int arc[100][100]; //边表，即邻接矩阵
	int numNodes, numEdges; //定点数和边数
}MGraph;

/*邻接表*/
typedef struct EdgeNode  //边表结点
{
	int adjvex;  //邻接点域，存储该顶点对应下标
	int info; //存储边的权值
	struct EdgeNode* next; //链域，指向下一个邻接点
}EdgeNode;
typedef struct VertexNode  //顶点表结点
{
	char data; //顶点域，存储顶点数据
	EdgeNode* firstEdge;  //边表头指针
}VertexNode, AdjList[100]; //最大存储100个数据
typedef struct
{
	AdjList adjList;
	int numNodes, numEdges; //图中的顶点数和边数
}GraphAdjList;

//建立无向网图的邻接矩阵结构
void createMGraph(MGraph* G)
{
	int i, j, k, w;
	cout << "请输入定点数和边数：" << endl;
	cin >> G->numNodes >> G->numEdges;
	cout << "输入顶点信息，建立顶点表：" << endl;
	for ( i = 0; i < G->numNodes; i++)
	{
		cin >> G->vexs[i];
	}
	for ( i = 0; i < G->numNodes; i++)
	{
		for ( j = 0; j < G->numNodes; j++)
		{
			G->arc[i][j] = INFINITY; //邻接矩阵初始化,用无穷大表示两点之间没有边
		}
	}
	for ( k = 0; k < G->numEdges; k++)
	{
		cout << "输入边(Vi,Vj)上的下标i，下标j和权w：" << endl;
		cin >> i >> j >> w;  //i j 是确定的顶点，w确定的两点间边的权值
		G->arc[i][j] = w;  //用矩阵中的点表示这两点之间有边，矩阵中的值代表这条边的权值
		G->arc[j][i] = G->arc[i][j]; //无向图，矩阵对称
	}

	cout << "邻接矩阵信息如下：" << endl;
	for (i = 0; i < G->numNodes; i++)
	{
		for (j = 0; j < G->numNodes; j++)
		{
			if (G->arc[i][j] == INFINITY)
			{
				cout << "#" << " ";
			}
			else
			{
				cout << G->arc[i][j] << " ";
			}
		}
		cout << endl;
	}

	system("pause");
	system("cls");
	return;
}
void createMGraphModified(MGraph* G)
{
	int i, j, k, w;
	G->numNodes = 6;  //6个顶点，10条边
	G->numEdges = 10;

	G->vexs[0] = 'A';
	G->vexs[1] = 'B';
	G->vexs[2] = 'C';
	G->vexs[3] = 'D';
	G->vexs[4] = 'E';
	G->vexs[5] = 'F';

	for (i = 0; i < G->numNodes; i++)
	{
		for (j = 0; j < G->numNodes; j++)
		{
			G->arc[i][j] = INFINITY; //邻接矩阵初始化,用无穷大表示两点之间没有边
		}
	}

	i = 0; j = 1; w = 7;
	G->arc[i][j] = w; G->arc[j][i] = G->arc[i][j];
	
	i = 0; j = 2; w = 1;
	G->arc[i][j] = w; G->arc[j][i] = G->arc[i][j];
	
	i = 0; j = 3; w = 9;
	G->arc[i][j] = w; G->arc[j][i] = G->arc[i][j];
	
	i = 1; j = 2; w = 2;
	G->arc[i][j] = w; G->arc[j][i] = G->arc[i][j];
	
	i = 1; j = 4; w = 3;
	G->arc[i][j] = w; G->arc[j][i] = G->arc[i][j];
	
	i = 2; j = 3; w = 11;
	G->arc[i][j] = w; G->arc[j][i] = G->arc[i][j];
	
	i = 2; j = 4; w = 8;
	G->arc[i][j] = w; G->arc[j][i] = G->arc[i][j];
	
	i = 2; j = 5; w = 4;
	G->arc[i][j] = w; G->arc[j][i] = G->arc[i][j];
	
	i = 3; j = 5; w = 5;
	G->arc[i][j] = w; G->arc[j][i] = G->arc[i][j];

	i = 4; j = 5; w = 15;
	G->arc[i][j] = w; G->arc[j][i] = G->arc[i][j];


	cout << "邻接矩阵信息如下：" << endl;
	for (i = 0; i < G->numNodes; i++)
	{
		for (j = 0; j < G->numNodes; j++)
		{
			if (G->arc[i][j] == INFINITY)
			{
				cout << "#" << " ";
			}
			else
			{
				cout << G->arc[i][j] << " ";
			}
		}
		cout << endl;
	}

	system("pause");
	system("cls");
	return;
}
//邻接矩阵的深度优先递归算法
bool visited[MAXVEX]; //访问标志的数组    -----------这个要换，不能用9个，万一输入数据大于9了呢？
void DFS(MGraph G, int i)
{
	int j;
	visited[i] = true;
	cout << G.vexs[i] << " ";  //打印顶点
	for (j = 0; j < G.numNodes; j++)
	{
		if (G.arc[i][j] != INFINITY && !visited[j]) //有边且未访问过
		{
			DFS(G, j);  //对未访问的顶点递归调用
		}
	}
}
//邻接矩阵的深度遍历操作
void DFSTraverse(MGraph G)
{
	int i;
	for (i = 0; i < G.numNodes; i++)
	{
		visited[i] = false; //初始所有顶点都是未访问状态
	}
	for (i = 0; i < G.numNodes; i++)
	{
		if (!visited[i])   //对未访问的顶点调用DFS
		{
			DFS(G, i);
		}
	}
}
//邻接矩阵的广度遍历算法  -- 借助queue队列容器实现  
void BFSTraverse(MGraph G)
{
	int i, j;

	for (i = 0; i < G.numNodes; i++)
	{
		visited[i] = false;
	}
	queue<int> q;  //辅助队列
	for (i = 0; i < G.numNodes; i++)  //对每一个顶点作循环处理
	{
		if (!visited[i])   //当前顶点未访问过就执行操作
		{
			visited[i] = true;   //设置当前顶点访问过了
			cout << G.vexs[i] << " ";  //打印
			q.push(i);
			while (!q.empty())  //若当前队列不为空 !QueueEmpty(Q)
			{
				i = q.front(); //首元素出队，赋值给i
				q.pop();
				for (j = 0; j < G.numNodes; j++)
				{
					if (G.arc[i][j] = 1 && !visited[j])  //判断其他顶点，若与当前顶点之间存在边且未访问过则执行
					{
						visited[j] = true;  //标记已访问并打印
						cout << G.vexs[j] << " ";
						q.push(j);//然后将此顶点入队
					}
				}
			}
		}
	}
}

//建立图的邻接表结构
void createALGraph(GraphAdjList* G)
{
	int i, j, k;
	EdgeNode* e;
	cout << "请输入定点数和边数：" << endl;
	cin >> G->numNodes >> G->numEdges;
	cout << "请输入顶点数据：" << endl;
	for ( i = 0; i < G->numNodes; i++)  //建立顶点表
	{
		cin >> G->adjList[i].data;  
		G->adjList[i].firstEdge = NULL;  //先将边表置空
	}

	for ( k = 0; k < G->numEdges; k++)  //建立边表
	{
		cout << "请输入边(Vi,Vj)上的顶点序号：" << endl; //先输入序号确定哪个点，因为用了链表所以要申请空间
		cin >> i >> j;
		e = (EdgeNode*)malloc(sizeof(EdgeNode));  //申请空间生成边表结点
		e->adjvex = j; //邻接序号为j
		e->next = G->adjList[i].firstEdge;  //将e的指针指向当前顶点指向的结点
		G->adjList[i].firstEdge = e;		//将当前顶点的指针指向e
		e = new EdgeNode;   //申请空间生成边表结点                            **这里的两步开辟空间操作，因为一条边是两个顶点
		e->adjvex = i;  //邻接序号为i
		e->next = G->adjList[j].firstEdge;  //将e的指针指向当前顶点指向的结点
		G->adjList[j].firstEdge = e;		//将当前顶点的指针指向e
	}
}

//邻接表的深度优先递归算法
void DFSAdj(GraphAdjList GL, int i)
{
	EdgeNode* p;
	visited[i] = true;
	cout << GL.adjList[i].data << " ";  //打印顶点
	p = GL.adjList[i].firstEdge;
	while (p)
	{
		if (!visited[p->adjvex])
		{
			DFSAdj(GL, p->adjvex);   //未访问的邻接顶点递归调用
		}
		p = p->next;
	}
}

//邻接表的深度遍历操作
void DFSAdjTraverse(GraphAdjList GL)
{
	int i;
	for ( i = 0; i < GL.numNodes; i++)
	{
		visited[i] = false;  //初始都是未访问状态
	}
	for ( i = 0; i < GL.numNodes; i++)
	{
		if (!visited[i])
		{
			DFSAdj(GL, i);   //对未访问的顶点调用DFSAdj
		}
	}
}

//邻接表的广度遍历算法
void BFSAdjTraverse(GraphAdjList GL)
{
	int i;
	EdgeNode* p;
	queue<int> q;
	for (i = 0; i < GL.numNodes; i++)
	{
		visited[i] = false;
	}
	for (i = 0; i < GL.numNodes; i++)
	{
		if (!visited[i])   //当前顶点未访问过就执行操作
		{
			visited[i] = true;   //设置当前顶点访问过了
			cout << GL.adjList[i].data << " ";  //打印
			q.push(i);  //将当前顶点入队
			while (!q.empty())  //若当前队列不为空
			{
				i = q.front();   //首元素出队，赋值给i
				q.pop();
				p = GL.adjList[i].firstEdge; //找到当前顶点的边表链的表头指针
				while (p)
				{
					if (!visited[p->adjvex])  //该顶点未被访问过
					{
						visited[p->adjvex] = true;
						cout << GL.adjList[p->adjvex].data << " ";
						q.push(p->adjvex);
					}
					p = p->next;
				}
			}
		}
	}
}


/*迪杰斯特拉算法*/
 int Path[MAXVEX];			//用于存储最短路径下标的数组
 int ShortWeight[MAXVEX];  //用于存储到各点最短路径的权值和
void ShortestPath_Dijkstra(MGraph G, int v0)
{
	int v, w, k, min;
	bool final[MAXVEX];  //final[w] = 1表示已求得顶点v0 至 vw 的最短路径
	for ( v = 0; v < G.numNodes; v++) //初始化数据
	{
		final[v] = false;  //全部顶点初始化为未知最短路径状态
		ShortWeight[v] = G.arc[v0][v]; //将与v0有连线的顶点加上权值
		//Path[v] = -1;  //初始化路径数组Path为-1
		Path[v] = ShortWeight[v] < INFINITY ? 1 : -1;
	}

	ShortWeight[v0] = 0;  //v0至v0的路径长度为0
	final[v0] = true; //v0至v0不需要求路径, 在循环开始前直接跳过v0,也就是自身

	/*开始主循环，每次求得v0到某个顶点v的最短路径*/
	for ( v = 1; v < G.numNodes; v++)
	{
		min = INFINITY;  //当前所知的离v0顶点的最近距离
		for ( w = 1; w <= G.numNodes; w++)  //寻找离v0最近的顶点
		{
			if (!final[w] && ShortWeight[w] < min)
			{
				k = w;
				min = ShortWeight[w];  //说明w顶点离v0顶点更近
			}
		}
		final[k] = true;    //将目前找到的最近的顶点置1
		for ( w = 1; w <= G.numNodes; w++)  //修正当前最短路径及距离
		{
			/*如果经过v顶点的路径比现在这条路径长度短的话*/
			if (!final[w] && (min + G.arc[k][w] < ShortWeight[w]))  //说明找到了更短的路径，修改Weight[w] 和 Path[w]
			{
				ShortWeight[w] = min + G.arc[k][w];  //修改当前路径长度
				Path[w] = k;
			}
		}
	}
}
//递归输出最短路径
void findNode(int x)
{
	if (Path[x] == 1) {
		cout << 1;
	}
	else {
		findNode(Path[x]);
	}
	cout << " -> " << x + 1;
	return;
}
//输出
void putoutMinPath(MGraph& G)
{
	cout << "起点 v1 到各点的最短路程为: " << endl;
	for (int i = 0; i < G.numNodes; i++)
	{
		cout << G.vexs[0] << "->" << G.vexs[i] << "权值：" << ShortWeight[i] << endl;
	}
	for (int i = 1; i < G.numNodes; i++)
	{
		cout << "起点 " << G.vexs[0] << " 到 " << G.vexs[i] << " 的路径为： ";
		findNode(i);
		cout << endl;
	}
}

void start()
{
	MGraph G;
	int Patharc[MAXVEX];
	int ShortPathTable[MAXVEX];

	while (1)
	{
		cout << "*********************************" << endl;
		cout << "*| 1----邻接矩阵创建图         |*" << endl;
		cout << "*| 2----邻接表创建图           |*" << endl;
		cout << "*| 3----深度优先的方式遍历图   |*" << endl;
		cout << "*| 4----广度优先的方式遍历图   |*" << endl;
		cout << "*| 5----Dijkstra最短路径算法   |*" << endl;
		cout << "*| 6----退出                   |*" << endl;
		cout << "*********************************" << endl;
		cout << "请输入：" << endl;
		int command;
		cin >> command;
		switch (command)
		{
		case 1:  //创建图--邻接矩阵
			cout << "请选择创建方式：" << endl;
			cout << "1---默认数据方式创建" << endl;
			cout << "2---自定义输入数据" << endl;
			int n;
			cin >> n;
			if (n == 1)
			{
				createMGraphModified(&G);
			}
			else if (n == 2)
			{
				createMGraph(&G);
			}
			else
			{
				system("pause");
				system("cls");
				break;
			}
			break;
		case 2:  //创建图--邻接表
			break;
		case 3:  //深度遍历
			DFSTraverse(G);
			cout << endl;
			system("pause");
			system("cls");
			break;
		case 4:  //广度遍历
			BFSTraverse(G);
			cout << endl;
			system("pause");
			system("cls");
			break;
		case 5:  //Dijkstra最短路径
			ShortestPath_Dijkstra(G, 0);
			putoutMinPath(G);
			system("pause");
			system("cls");
			break;
		case 6:
			cout << "已退出" << endl;
			return;
		default:
			system("pause");
			system("cls");
			break;
		}
	}
}

int main()
{


	start();
	//MGraph G;
	////createMGraph(&G);  //创建图 //打印一下子矩阵
	////用默认数据创建图
	//createMGraphModified(&G);
	//cout << endl << "----------------------------------------------------" << endl;
	//


	//cout << "深度遍历：" << endl;
	//DFSTraverse(G);
	//cout << endl << "----------------------------------------------------" << endl;


	//cout << "广度遍历：" << endl;
	//BFSTraverse(G);
	//cout << endl << "----------------------------------------------------" << endl;


	//cout << "最短路径：" << endl;
	//int Patharc[MAXVEX];
	//int ShortPathTable[MAXVEX];
	//ShortestPath_Dijkstra(G, 0, &Patharc, &ShortPathTable);
	////ShortestPath_DIJ(G, 0, &Patharc, &ShortPathTable);

	//cout << "保存的最短路径下标：" << endl;
	//for (int i = 0; i < MAXVEX; i++)
	//{
	//	cout << Patharc[i] << " " << ShortPathTable[i] << endl;
	//}
	//cout << endl << "----------------------------------------------------" << endl;



	system("pause");
	return 0;
}

