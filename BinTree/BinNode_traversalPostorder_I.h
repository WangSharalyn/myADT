#pragma once
// �������������
template <typename T>
void BinNode<T>::traversalPostorder_I(BinNodePosi(T) x) {
	Stack<BinNodePosi(T)> S;
	if (x) S.push(x);// ���ڵ���ջ
	while (!S.empty()) {
        if (S.top() != x->parent)
            gotoHLVFL(S);
        x = S.pop();
        std::cout << x->data << ' ';
	}
}

template <typename T> //����Sջ���ڵ�Ϊ���������У��ҵ�������ɼ�Ҷ�ڵ�
static void gotoHLVFL(Stack<BinNodePosi(T)>& S) { //��;�����ڵ�������ջ
    while (BinNodePosi(T) x = S.top()) //�Զ����£�������鵱ǰ�ڵ㣨��ջ����
        if (x->lc) { //����������
            if (x->rc) S.push(x->rc); //�����Һ��ӣ�������ջ
            S.push(x->lc); //Ȼ���ת������
        }
        else //ʵ������
            S.push(x->rc); //������
    S.pop(); //����֮ǰ������ջ���Ŀսڵ�
}