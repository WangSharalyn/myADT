#pragma once
#include "../Queue/Queue_list.h"
enum VStatus { UNDISCOVERD, DISCOVERD, VISITED};
enum Etype { UNDETERMINED, TREE, CROSS, FORWARD, BACKWARD};

template <typename Tv, typename Te> class Graph {// 图模板
public:
	// 顶点
	int n; // 顶点总数
	virtual int insert(Tv const&) = 0; // 插入顶点，返回编号
	virtual Tv remove(int) = 0; // 删除顶点及其关联边，返回该顶点信息
	virtual Tv& vertex(int) = 0; // 顶点v的数据
	virtual int inDegree(int) = 0; // 顶点的入度
	virtual int outDegree(int) = 0;// 顶点的出度
	virtual int firstNbr(int) = 0; // 第一个相邻的点
	virtual int nextNbr(int, int) = 0; // 下一个相邻的点
	virtual VStatus& status(int) = 0; // 点的状态
	virtual int& dTime(int) = 0; // 被发现的时间dTime
	virtual int& fTime(int) = 0; // 被访问的时间fTime
	virtual int& parent(int) = 0; // 在遍历树中的父亲
	// 边（无向边均转换为方向互逆的一对有向边
	int e; // 边的总数
	virtual bool exists(int, int) = 0; // 是否存在
	virtual void insert(Te const&, int, int, int) = 0; // 插入边
	virtual Te remove(int, int) = 0; // 删除边，返回该边信息
	virtual Etype& type(int, int) = 0; // 边的类型
	virtual Te& edge(int, int) = 0; // 边的信息
	virtual int& weight(int, int) = 0;// 边的权重
	// 算法
	void bfs(int);
	void dfs(int);
	void prim(int);// 最小支撑树Prim算法
	void dijkstra(int); // 最短路径dijkstra算法
private:
	void reset() {
		for (int i = 0; i < n; i++) {
			status(i) = DISCOVERD; // 状态
			dTime(i) = fTime(i) = -1; // 时间
			parent(i) = -1;
			for (int j = 0; j < n; j++)
				if (exists(i, j)) type(i, j) = UNDETERMINED;
		}
	}
	void BFS(int, int&);
	void DFS(int, int&);
};

#include "Graph_BFS.h"
#include "Graph_DFS.h"