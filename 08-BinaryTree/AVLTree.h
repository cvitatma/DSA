#ifndef __AVLTREE_H
#define __AVLTREE_H

typedef int ElementType;
typedef struct AVLNode* AVLTree;
typedef AVLTree Position;

struct AVLNode {
    ElementType Element;
    AVLTree Left;
    AVLTree Right;
    int Height;
};

AVLTree Insert(AVLTree T, ElementType X);
AVLTree Delete(AVLTree T, ElementType X);

Position Find(AVLTree T, ElementType X);
Position FindMin(AVLTree T);
Position FindMax(AVLTree T);

ElementType GetElement(Position P);

#endif
