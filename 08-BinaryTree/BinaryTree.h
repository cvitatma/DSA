#ifndef __BINARYTREE_H
#define __BINARYTREE_H

typedef int ElementType;
typedef struct TreeNode* SearchTree;
typedef SearchTree Position;

struct TreeNode {
    ElementType Element;
    SearchTree Left;
    SearchTree Right;
};

SearchTree MakeNode(ElementType X);
SearchTree Insert(SearchTree T, ElementType X);
SearchTree Delete(SearchTree T, ElementType X);

Position Find(SearchTree T, ElementType X);
Position FindMin(SearchTree T);

#endif
