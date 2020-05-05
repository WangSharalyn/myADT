#pragma once
#include "AVLNode.h"

template <typename T> class AVLT {
protected:
	Position(T) _root; // 根节点
	Position(T) _hot; // “命中”节点的父亲
	int remove(Position(T) x); // 删除以 x 为根节点的子树
public:
	AVLT():_root(nullptr), _hot(nullptr){} // 构造函数
	~AVLT() { remove(_root); }; // 析构函数
	friend Position(T) succ(Position(T) x); // 中序遍历的后继
	Position(T)& search(const T& e); // 搜索
	Position(T) insert(const T& e); // 插入
	bool remove(const T& e); // 删除节点
};

#include "AVLT_succ.h"
#include "AVLT_removeAt.h"
#include "AVLT_search.h"
#include "AVLT_insert.h"
#include "AVLT_remove.h"