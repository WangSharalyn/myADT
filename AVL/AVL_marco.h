#pragma once
#define Balanced(x) (stature((x).lc) == stature((x).rc)) // 理想平衡条件
#define BalFac(x) (stature((x).lc) - stature((x).rc)) // 平衡因子
#define AvlBanced(x) ((-2 < BalFac(x)) && (BalFac(x) < 2)) // AVL 平衡条件
#define IsLChild(x) ((x)->parent && ((x)->parent)->lc == (x))
#define tallerChild(x) ( \
   stature( (x)->lc ) > stature( (x)->rc ) ? (x)->lc : ( /*左高*/ \
   stature( (x)->lc ) < stature( (x)->rc ) ? (x)->rc : ( /*右高*/ \
   IsLChild( x ) ? (x)->lc : (x)->rc /*等高：与父亲x同侧者（zIg-zIg或zAg-zAg）优先*/ \
   ) \
   ) \
)
