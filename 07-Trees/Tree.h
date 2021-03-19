#ifndef __TREE_H
#define __TREE_H

typedef double ElementType;
typedef struct TreeNode *PtrToNode;

struct TreeNode {
    ElementType Element;
    PtrToNode FirstChild;
    PtrToNode NextSibling;
};

// man dirent 
void ListDir(DirOrFile D,int Depth)
{
    if ( IsValid(D) )
    {
        PrintName(D,Depth); // use depth for number of spaces
        if ( IsDir(D) ) 
        {
            // For each child C
            Dir C = D->FirstChild;
            while( C != NULL)
            {
                ListDir(C,Depth + 1);
                C = C->NextSibling;
            }
        }
    }
}
void ListDirectory(DirOrFile D) // ADT
{
    ListDir(D,0);
}

size_t DirSize(DirOrFile D)
{
    size_t totalSize = 0;
    if ( IsValid(D) )
    {
        totalSize = FileSize(D);
        if ( IsDir(D) )
        {
            // For each child C
            Dir C = D->FirstChild;
            while( C != NULL)
            {
                totalSize += DirSize(C);
                C = C->NextSibling;
            }
        }        
    }
    return totalSize;
}
#endif 
