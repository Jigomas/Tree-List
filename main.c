#include <stdio.h>



#include "tree.h"



int main(int argc, char* argv[])
{

    tree_t *tree = NULL;

    tree = TreeAdd(tree, 5, LeftIsSmaller); //where to add, what to add, function of choosing how to add
    tree = TreeAdd(tree, 3, LeftIsSmaller);
    tree = TreeAdd(tree, 6, LeftIsSmaller);
    tree = TreeAdd(tree, 1, LeftIsSmaller);

    // TreeSearch(tree, 6);
    TreePrint(tree, 0);
    //TreeDump(tree, "out.dot", tree->left->left);
    TreeDtor(tree);

}
