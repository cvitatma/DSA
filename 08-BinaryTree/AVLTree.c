include "AVLTree.h"

int Height(Position P)
{
	if( P == NULL )
		return -1;
	else
		return P->Height;
}

/*
SearchTree MakeNode(ElementType X)
{
    SearchTree T = (SearchTree)malloc(sizeof(struct TreeNode));
    assert( T != NULL);

    T->Element = X;
    T->Left = NULL;
    T->Right = NULL;

    return T;
}
*/

SearchTree Insert(SearchTree T, ElementType X)
{

    if( T == NULL)
        T = MakeNode(X);
    else if ( IsSmaller(X,T->Element) ) // X < T->Element
        T->Left = Insert(T->Left,X);
    else if ( IsLarger(X,T->Element) )  // X > T->Element
        T->Right = Insert(T->Right,X);
    // else X == T->Element ; do nothing

    return T;
}


AVLTree Insert(AVLTree T, ElementType X)
{
	
    if( T == NULL)
        T = MakeNode(X);
    else if ( IsSmaller(X,T->Element) ) // X < T->Element
    {
        T->Left = Insert(T->Left,X);
	// Check if AVL Property has been violated after insertion into left subtree
	if ( (Height(T->Left) - Height(T->Right)) == 2 ) // Violation ! Adjust tree
	{
		if ( IsSmaller(X,T->Left->Element) ) // insertion into left subtree of left child of T
			T = SingleRotateWithLeft(T);
		else  // insertion into right subtree of left child of T
			T = DoubleRotateWithLeft(T);
			
	}
    }
    else if ( IsLarger(X,T->Element) )  // X > T->Element
    {
        T->Right = Insert(T->Right,X);
	// Check if AVL Property has been violated after insertion into right subtree
	if ( (Height(T->Right) - Height(T->Left)) == 2 ) // Violation ! Adjust tree
	{
		if ( IsSmaller(X,T->Right->Element) ) // insertion into left subtree of right child of T
			T = DoubleRotateWithRight(T);
		else  // insertion into right subtree of right child of T
			T = DoubleRotateWithRight(T);
	}
    }
    // else X == T->Element ; do nothing
    T->Height = max(Height(T->Left), Height(T->Right)) + 1;

    return T;
	
}

Position SingleRotateWithLeft(Position k2)
{
	Position k1;
	
	k1 = k2->Left;
	k2->Left = k1->Right;
	k1->Right = k2;

	k2->Height = max(Height(k2->Left),Height(k2->Right)) + 1;
	k1->Height = max(Height(k1->Left),k2->Height) + 1;

	return k1; // new root
}

Position DoubleRotateWithLeft(Position k2)
{
	// Rotate between k3 and k1
	k2->Left = SingleRotateWithRight(k2->Left);

	// Rotate between k1 and k2
	return SingleRotateWithLeft(k2)
}
