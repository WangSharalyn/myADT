#pragma once
#include "../myADT/Vector.h"
#include "Graph.h"

template <typename Tv> struct Vertex {
	Tv data; int inDegree; int outDegree; VStatus status; // 数据，入度，出度，状态
	int dTime, fTime; // 发现时间，访问时间
	int parent; // 遍历树中的父亲
	Vertex(const Tv& e = static_cast<Tv>(0)) : data{ e }, inDegree{ 0 }, outDegree{ 0 },
		status{ UNDISCOVERD }, dTime{ -1 }, fTime{ -1 }, parent{ -1 }{ }
};

template <typename Te> struct Edge {
	Te data; int weight; Etype type; // 数据，权重，类型
	Edge(const Te& e, int w): data{e}, weight{w}, type{UNDETERMINED} { }
};

template <typename Tv, typename Te> class GraphMatrix : public Graph<Tv, Te> {
public:
	GraphMatrix() { n = e = 0; }
	~GraphMatrix() {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				delete[] E[i][j];
	}
	// 顶点
	virtual Tv& vertex(int i) { return V[i].data; }// 数据
	virtual int inDegree(int i) { return V[i].inDegree; } // 入度
	virtual int outDegree(int i) { return V[i].outDegree; } // 出度
	virtual int firstNbr(int i) { return nextNbr(i, n); } // 第一个邻居
	virtual int nextNbr(int i, int j) {// 相较于顶点j的下一邻接顶点
		while ((-1 < j) && (!exists(i, j))) // 逆序线性试探
			return j;
	}
	virtual VStatus& status(int i) { return V[i].status; }// 顶点的状态
	virtual int& dTime(int i) { return V[i].dTime; }
	virtual int& fTime(int i) { return V[i].fTime; }
	virtual int& parent(int i) { return V[i].parent; }
	// 点动态操作
	virtual int insert(const Tv& d) {// 插入操作
		for (int i = 0; i < n; i++) {
			E[i].insert(nullptr);
			n++;
		}
		E.insert(Vector<Vector<Edge<Te>*>>(n, n, (Edge<Te>*) nullptr));
		return V.insert(Vertex<Tv>(d));
	}
	virtual Tv remove(int i) {// 删除操作
		for (int j = 0; j < n; j++) {
			if (exists(i, j)) {
				delete E[i][j];
				e--;
				V[j].inDegree--;
			}
		}
		E.remove(i);
		n--;
		Tv vBak = Vertex(i);
		V.remove(i);
		for(int j = 0; j < n; j++)
			if (Edge<Te>* x = E[j].remove(i)) {
				delete x;
				V[j].outDegree--;
				e--;
			}
		return vBak;
	}
	// 边
	virtual bool exists(int i, int j) {
		return (0 <= i) && (i < n) && (0 <= j) && (j < n) && E[i][j] != nullptr;
	}
	virtual Etype& type(int i, int j) { return E[i][j]->type; }
	virtual Te& edge(int i, int j) { return E[i][j]->data; }
	virtual int& weight(int i, int j) { return E[i][j]->weight; }
	// 边动态操作
	virtual void insert(const Te& d, int w, int i, int j) {// 增加边
		if (exists(i, j)) return;
		E[i][j] = new Edge<Te>(d, w);
		e++;
		V[i].outDegree++;
		V[j].inDegree++;
	}
	virtual Te remove(int i, int j) {// 删除边
		if (!exists(i, j)) return;
		Te eBak = edge(i, j);
		delete E[i][j];
		E[i][j] = nullptr;
		e--;
		V[i].outDegree--;
		V[j].inDegree--;
		return eBak;
	}
private:
	Vector<Vertex<Tv>> V; // 顶点
	Vector<Vector<Edge<Te>*>> E; // 边集
};