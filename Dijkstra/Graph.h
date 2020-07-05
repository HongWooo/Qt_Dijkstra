#pragma once
#include"qstring.h"
//记录起点到每个顶点的最短路径的信息
struct Dis {
	int value;
	bool visit;
	QString path;
	Dis() {
		visit = false;
		value = 0;
		path = "";
	}
};

class Graph {
public:
	int vexnum;	//图顶点个数
	int edge;	//图边的个数
	int **arc;   //邻接矩阵 
	Dis * dis;	//记录各个顶点最短路径的信息 
public:
	Graph(int v);
	~Graph();
	bool check_edge_value(int start, int end, int weight);// 判断我们每次输入的的边的信息是否合法
	void createGraph(QString s);	 //创建图
	void show();	//打印邻接矩阵
	void dijkstra(int begin);	//求最短路径
	void print_path(int); 	//打印最短路径 
	int getDis(int v1, int v2);
};



