#pragma once
#define Balanced(x) (stature((x).lc) == stature((x).rc)) // ����ƽ������
#define BalFac(x) (stature((x).lc) - stature((x).rc)) // ƽ������
#define AvlBanced(x) ((-2 < BalFac(x)) && (BalFac(x) < 2)) // AVL ƽ������
#define IsLChild(x) ((x)->parent && ((x)->parent)->lc == (x))
#define tallerChild(x) ( \
   stature( (x)->lc ) > stature( (x)->rc ) ? (x)->lc : ( /*���*/ \
   stature( (x)->lc ) < stature( (x)->rc ) ? (x)->rc : ( /*�Ҹ�*/ \
   IsLChild( x ) ? (x)->lc : (x)->rc /*�ȸߣ��븸��xͬ���ߣ�zIg-zIg��zAg-zAg������*/ \
   ) \
   ) \
)
