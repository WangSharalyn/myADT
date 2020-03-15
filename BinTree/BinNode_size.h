#pragma once
// 返回该节点子树的规模
template <typename T>
int BinNode<T>::size() {
	int s = 1;// 计入本身
	if (lc) s += lc->size();
	if (rc) s += rc->size();
	return s;
}