#pragma once
#include "../Queue/Queue_list.h"
enum VStatus { UNDISCOVERD, DISCOVERD, VISITED};
enum Etype { UNDETERMINED, TREE, CROSS, FORWARD, BACKWARD};

template <typename Tv, typename Te> class Graph {// ͼģ��
public:
	// ����
	int n; // ��������
	virtual int insert(Tv const&) = 0; // ���붥�㣬���ر��
	virtual Tv remove(int) = 0; // ɾ�����㼰������ߣ����ظö�����Ϣ
	virtual Tv& vertex(int) = 0; // ����v������
	virtual int inDegree(int) = 0; // ��������
	virtual int outDegree(int) = 0;// ����ĳ���
	virtual int firstNbr(int) = 0; // ��һ�����ڵĵ�
	virtual int nextNbr(int, int) = 0; // ��һ�����ڵĵ�
	virtual VStatus& status(int) = 0; // ���״̬
	virtual int& dTime(int) = 0; // �����ֵ�ʱ��dTime
	virtual int& fTime(int) = 0; // �����ʵ�ʱ��fTime
	virtual int& parent(int) = 0; // �ڱ������еĸ���
	// �ߣ�����߾�ת��Ϊ�������һ�������
	int e; // �ߵ�����
	virtual bool exists(int, int) = 0; // �Ƿ����
	virtual void insert(Te const&, int, int, int) = 0; // �����
	virtual Te remove(int, int) = 0; // ɾ���ߣ����ظñ���Ϣ
	virtual Etype& type(int, int) = 0; // �ߵ�����
	virtual Te& edge(int, int) = 0; // �ߵ���Ϣ
	virtual int& weight(int, int) = 0;// �ߵ�Ȩ��
	// �㷨
	void bfs(int);
	void dfs(int);
	void prim(int);// ��С֧����Prim�㷨
	void dijkstra(int); // ���·��dijkstra�㷨
private:
	void reset() {
		for (int i = 0; i < n; i++) {
			status(i) = DISCOVERD; // ״̬
			dTime(i) = fTime(i) = -1; // ʱ��
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