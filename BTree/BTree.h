#pragma once
#include "BTNode.h"
template <typename T> class BTree {
protected:
	int _size; // 存放关键码总数
	int _order; // B-树的阶次， 至少为3——创建时指令，一般不能修改
	BTNodePosi(T) _root; // 根节点
	BTNodePosi(T) _hot; // BTree::search()最后访问的非空（除非树空）的节点位置
	void solveOverflow(BTNodePosi(T)); // 因插入而上溢之后的分裂处理
	void solveUnderflow(BTNodePosi(T)); // 因删除而下溢之后的合并处理
public:
	BTree(int order = 3) :_order(order), _size(0) {// 构造函数：默认最低阶为3阶
		_root = new BTNode<T>();
	}
	~BTree() { if (_root) delete _root; }// 析构函数
	int order() const { return _order; }
	int size() const { return _size; }
	BTNodePosi(T)& root() { return _root; }
	bool empty() { return !_root; }
	BTNodePosi(T) search(const T& e); // 查找
	bool insert(const T& e); // 插入
	bool remove(const T& e); // 删除
};

#include "BTree_search.h"
#include "BTree_insert.h"
#include "BTree_remove.h"
#include "BTree_solveOverflow.h"
#include "BTree_solveUnderflow.h"
