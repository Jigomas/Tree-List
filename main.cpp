#include <stdio.h>



#include "tree.h"



int main(int argc, char* argv[]) {
    tree_t *tree = NULL;

    tree = TreeAdd(tree, 5, LeftIsSmaller); //where to add, what to add, function of choosing how to add
    tree = TreeAdd(tree, 3, LeftIsSmaller);
    tree = TreeAdd(tree, 6, LeftIsSmaller);
    tree = TreeAdd(tree, 1, LeftIsSmaller);

    TreePrint(tree, 0); //what to print, and where to start

    TreeDtor(tree);
}
