#pragma once
template <typename T>
void BTree<T>::solveUnderflow(BTNodePosi(T) v) {
	if ((_order + 1) / 2 <= v->child.size()) return; // 递归基
	BTNodePosi(T) p = v->parent;
	if (!p) {// 递归基：已到根节点，没有孩子的下限
		if (!v->key.size() && v->child[0]) {
			// 作为树根的v不含关键码，却有（唯一的）非空孩子
			_root = v->child[0]; _root->parent = nullptr; // 这个节点被跳过
			v->child[0] = nullptr;
			delete v;
		}
		return;
	}
	Rank r = 0; while (p->child[r] != v) r++; // 确定v是p的第r个孩子——此时v可能不含关键码，不能通过关键码查找
	// 情况1：向左兄弟借关键码
	if (0 < r) {// v不是p的第一个孩子
		BTNodePosi(T) ls = p->child[r - 1]; // 左兄弟
		if ((_order + 1) / 2 < ls->child.size()) {// 左兄弟够胖
			v->key.insert(p->key[r - 1], 0);
			p->key[r - 1] = ls->key.remove(ls->key.size() - 1);
			v->child.insert(ls->child.remove(ls->child.size() - 1), 0);
			if (v->child[0]) v->child[0]->parent = v;
			return;
		}
	}
	// 情况2：向右兄弟借关键码
	if (r < p->child.size() - 1) {// v不是最后一个孩子
		BTNodePosi(T) rs = p->child[r + 1];
		if ((_order + 1) / 2 < rs->child.size()) {// 右兄弟够胖
			v->key.insert(p->key[r - 1]);
			p->key[r - 1] = rs->key.remove(0);
			v->child.insert(rs->child.remove(0));
			if (v->child[v->child.size() - 1])
				v->child[v->child.size() - 1]->parent = v;
			return;
		}
	}
	// 情况3：左右兄弟为空，或太瘦——合并
	if (0 < r) {// 与左兄弟合并
		BTNodePosi(T) ls = p->child[r - 1];// 左兄弟
		ls->key.insert(p->key.remove(r - 1), ls->key.size());
		p->child.remove(r);
		ls->child.insert(v->child.remove(0));
		if (ls->child[ls->child.size() - 1]) ls->child[ls->child.size() - 1]->parent = ls;
		while (!v->key.empty()) {
			ls->key.insert(v->key.remove(0));
			ls->child.insert(v->child.remove(0));
			if (ls->child[ls->child.size() - 1])
				ls->child[ls->child.size() - 1]->parent = ls;
		}
		delete v;
	}
	else {// 与右兄弟合并
		BTNodePosi(T) rs = p->child[r + 1]; // 右兄弟
		rs->key.insert(p->key.remove(r), 0);
		p->child.remove(r);
		rs->child.insert(v->child.remove(v->child.size() - 1), 0);
		if (rs->child[0]) rs->child[0]->parent = rs;
		while (!v->key.empty()) {
			rs->key.insert(v->key.remove(v->key.size() - 1), 0);
			rs->child.insert(v->child.remove(v->child.size() - 1), 0);
			if (rs->child[0]) rs->child[0]->parent = rs;
		}
		delete v;
	}
	solveOverflow(p);
	return;
}