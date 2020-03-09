#pragma once
// 后序遍历迭代版
template <typename T>
void BinNode<T>::traversalPostorder_I(BinNodePosi(T) x) {
	Stack<BinNodePosi(T)> S;
	if (x) S.push(x);// 根节点入栈
	while (!S.empty()) {
        if (S.top() != x->parent)
            gotoHLVFL(S);
        x = S.pop();
        std::cout << x->data << ' ';
	}
}

template <typename T> //在以S栈顶节点为根的子树中，找到最高左侧可见叶节点
static void gotoHLVFL(Stack<BinNodePosi(T)>& S) { //沿途所遇节点依次入栈
    while (BinNodePosi(T) x = S.top()) //自顶而下，反复检查当前节点（即栈顶）
        if (x->lc) { //尽可能向左
            if (x->rc) S.push(x->rc); //若有右孩子，优先入栈
            S.push(x->lc); //然后才转至左孩子
        }
        else //实不得已
            S.push(x->rc); //才向右
    S.pop(); //返回之前，弹出栈顶的空节点
}