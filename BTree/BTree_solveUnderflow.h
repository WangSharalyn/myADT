#pragma once
template <typename T>
void BTree<T>::solveUnderflow(BTNodePosi(T) v) {
	if ((_order + 1) / 2 <= v->child.size()) return; // �ݹ��
	BTNodePosi(T) p = v->parent;
	if (!p) {// �ݹ�����ѵ����ڵ㣬û�к��ӵ�����
		if (!v->key.size() && v->child[0]) {
			// ��Ϊ������v�����ؼ��룬ȴ�У�Ψһ�ģ��ǿպ���
			_root = v->child[0]; _root->parent = nullptr; // ����ڵ㱻����
			v->child[0] = nullptr;
			delete v;
		}
		return;
	}
	Rank r = 0; while (p->child[r] != v) r++; // ȷ��v��p�ĵ�r�����ӡ�����ʱv���ܲ����ؼ��룬����ͨ���ؼ������
	// ���1�������ֵܽ�ؼ���
	if (0 < r) {// v����p�ĵ�һ������
		BTNodePosi(T) ls = p->child[r - 1]; // ���ֵ�
		if ((_order + 1) / 2 < ls->child.size()) {// ���ֵܹ���
			v->key.insert(p->key[r - 1], 0);
			p->key[r - 1] = ls->key.remove(ls->key.size() - 1);
			v->child.insert(ls->child.remove(ls->child.size() - 1), 0);
			if (v->child[0]) v->child[0]->parent = v;
			return;
		}
	}
	// ���2�������ֵܽ�ؼ���
	if (r < p->child.size() - 1) {// v�������һ������
		BTNodePosi(T) rs = p->child[r + 1];
		if ((_order + 1) / 2 < rs->child.size()) {// ���ֵܹ���
			v->key.insert(p->key[r - 1]);
			p->key[r - 1] = rs->key.remove(0);
			v->child.insert(rs->child.remove(0));
			if (v->child[v->child.size() - 1])
				v->child[v->child.size() - 1]->parent = v;
			return;
		}
	}
	// ���3�������ֵ�Ϊ�գ���̫�ݡ����ϲ�
	if (0 < r) {// �����ֵܺϲ�
		BTNodePosi(T) ls = p->child[r - 1];// ���ֵ�
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
	else {// �����ֵܺϲ�
		BTNodePosi(T) rs = p->child[r + 1]; // ���ֵ�
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