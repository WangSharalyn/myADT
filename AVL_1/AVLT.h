#pragma once
#include "AVLNode.h"

template <typename T> class AVLT {
protected:
	Position(T) _root; // ���ڵ�
	Position(T) _hot; // �����С��ڵ�ĸ���
	int remove(Position(T) x); // ɾ���� x Ϊ���ڵ������
public:
	AVLT():_root(nullptr), _hot(nullptr){} // ���캯��
	~AVLT() { remove(_root); }; // ��������
	friend Position(T) succ(Position(T) x); // ��������ĺ��
	Position(T)& search(const T& e); // ����
	Position(T) insert(const T& e); // ����
	bool remove(const T& e); // ɾ���ڵ�
};

#include "AVLT_succ.h"
#include "AVLT_removeAt.h"
#include "AVLT_search.h"
#include "AVLT_insert.h"
#include "AVLT_remove.h"