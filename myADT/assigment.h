#pragma once
// ���
template <typename T>
Vector<T>& Vector<T>::operator= (const Vector<T>& A) {
	if (_elem) delete[]_elem; // �ͷ�ԭ������
	copyFrom(A._elem, 0, A._size);
	return *this;
}