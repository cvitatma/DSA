#include "BinaryTree.h"
#include <stdio.h>

SearchTree MakeNode(ElementType X)
{
    SearchTree T = (SearchTree)malloc(sizeof(struct TreeNode));
    assert( T != NULL);

    T->Element = X;
    T->Left = NULL;
    T->Right = NULL;

    return T;
}

SearchTree Insert(SearchTree T, ElementType X)
{

    if( T == NULL)
        T = MakeNode(X);
    else if ( IsSmaller(X,T->Element) ) // X < T->Element
        T = Insert(T->Left,X);
    else if ( IsLarger(X,T->Element) )  // X > T->Element
        T = Insert(T->Right,X);
    // else X == T->Element ; do nothing

    return T;
}

Position Find(SearchTree T, ElementType X)
{
    if(T == NULL )
        return T;
    else if( IsEqual(X,T->Element) )
        return T;
    else if ( IsSmaller(X,T->Element) ) // X < T->Element
        return Find(T->Left,X);
    else if ( IsLarger(X,T->Element) )
        return Find(T->Right,X);    
}

Position FindMin(SearchTree T)
{
    if( T == NULL )
        return T;    
    else if ( T->Left == NULL ) 
        return T;
    else
        return FindMin(T->Left);
}

SearchTree Delete(SearchTree T, ElementType X)
{
    SearchTree TmpNode;
    assert(T != NULL);
    
    if ( IsSmaller(X,T->Element) )
        T->Left = Delete(T->Left,X);
    else if (IsGreater(X,T->Element))
        T->Right = Delete(T->Right,X);
    else // Found the node to delete
    {
        // case-1: node has at least one null child
        if(T->Left == NULL || T->Right == NULL)
        {
            TmpNode = T;
            if(T->Left == NULL)
                T = T->Right;
            else if(T->Right == NULL)
                T = T->Left;
            free(TmpNode);
        }
        else // case-2: node has two children        
        {
            // Replace with smallest element in 
            // right subtree
            TmpNode = FindMin(T->Right);
            CopyNode(T,TmpNode); // T = TmpNode
            T->Right = Delete(T->Right,TmpNode->Element);
        }
    }
    return T;    
}
