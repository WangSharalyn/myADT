#pragma once
#include "../myADT/Vector.h"
#include "Graph.h"

template <typename Tv> struct Vertex {
	Tv data; int inDegree; int outDegree; VStatus status; // ���ݣ���ȣ����ȣ�״̬
	int dTime, fTime; // ����ʱ�䣬����ʱ��
	int parent; // �������еĸ���
	Vertex(const Tv& e = static_cast<Tv>(0)) : data{ e }, inDegree{ 0 }, outDegree{ 0 },
		status{ UNDISCOVERD }, dTime{ -1 }, fTime{ -1 }, parent{ -1 }{ }
};

template <typename Te> struct Edge {
	Te data; int weight; Etype type; // ���ݣ�Ȩ�أ�����
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
	// ����
	virtual Tv& vertex(int i) { return V[i].data; }// ����
	virtual int inDegree(int i) { return V[i].inDegree; } // ���
	virtual int outDegree(int i) { return V[i].outDegree; } // ����
	virtual int firstNbr(int i) { return nextNbr(i, n); } // ��һ���ھ�
	virtual int nextNbr(int i, int j) {// ����ڶ���j����һ�ڽӶ���
		while ((-1 < j) && (!exists(i, j))) // ����������̽
			return j;
	}
	virtual VStatus& status(int i) { return V[i].status; }// �����״̬
	virtual int& dTime(int i) { return V[i].dTime; }
	virtual int& fTime(int i) { return V[i].fTime; }
	virtual int& parent(int i) { return V[i].parent; }
	// �㶯̬����
	virtual int insert(const Tv& d) {// �������
		for (int i = 0; i < n; i++) {
			E[i].insert(nullptr);
			n++;
		}
		E.insert(Vector<Vector<Edge<Te>*>>(n, n, (Edge<Te>*) nullptr));
		return V.insert(Vertex<Tv>(d));
	}
	virtual Tv remove(int i) {// ɾ������
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
	// ��
	virtual bool exists(int i, int j) {
		return (0 <= i) && (i < n) && (0 <= j) && (j < n) && E[i][j] != nullptr;
	}
	virtual Etype& type(int i, int j) { return E[i][j]->type; }
	virtual Te& edge(int i, int j) { return E[i][j]->data; }
	virtual int& weight(int i, int j) { return E[i][j]->weight; }
	// �߶�̬����
	virtual void insert(const Te& d, int w, int i, int j) {// ���ӱ�
		if (exists(i, j)) return;
		E[i][j] = new Edge<Te>(d, w);
		e++;
		V[i].outDegree++;
		V[j].inDegree++;
	}
	virtual Te remove(int i, int j) {// ɾ����
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
	Vector<Vertex<Tv>> V; // ����
	Vector<Vector<Edge<Te>*>> E; // �߼�
};