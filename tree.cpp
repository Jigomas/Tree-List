#include <stdio.h>
#include <stdlib.h>

#include "tree.h"



tree_t *TreeCtor(int value) {
    tree_t *tree = (tree_t *)calloc(1, sizeof(tree_t));

    tree->data   = value;
    tree->left   = NULL;
    tree->right  = NULL;

    return tree;
}



void TreeDtor(tree_t *tree) {
    if (tree) {
        TreeDtor(tree->left);
        TreeDtor(tree->right);
    }

    free(tree);
}



tree_t *TreeAdd(tree_t *tree, int value, comparing_t *how_to_compare) {
    if (!tree)
        return TreeCtor(value);

    if (how_to_compare(value, tree->data))
        tree->left  = TreeAdd(tree->left, value, how_to_compare);

    else
        tree->right = TreeAdd(tree->right, value, how_to_compare);

    return tree;
}



tree_t *TreePrint(tree_t *tree, int level) {
    if (!tree)
        return tree;

    printf("tree[%p] %*stree.data = %d tree.left[%p] tree.right[%p]\n",
                 tree, 9 * level, "", tree->data, tree->left, tree->right);

    TreePrint(tree->left,  level + 1);
    TreePrint(tree->right, level + 1);

    return tree;
}



tree_t *TheBracketPrinting(tree_t *tree, int order) {
    if (!tree)
        return tree;

    printf("( ");

    if (order == PRE_ORDER)
        printf("%d ", tree->data);

    TheBracketPrinting(tree->left, order);

    if (order == IN_ORDER)
        printf("%d ", tree->data);

    TheBracketPrinting(tree->right, order);

    if (order == POST_ORDER)
        printf("%d ", tree->data);

    printf(") ");

    return tree;
}



tree_t *SearchInTheTree(tree_t *tree, int value) {
    if (!tree)
        return NULL;

    if (tree->data == value)
        return tree;

    tree_t *left = SearchInTheTree(tree->left, value);

    if (left)
        return left;

    tree_t *right = SearchInTheTree(tree->right, value);

    if (right)
        return right;

    return NULL;
}



int *ListOfLevelsCtor(int max_depth) {
    int *list_of_levels = (int *)calloc(max_depth, sizeof(int));

    return list_of_levels;
}


void LevelCounter(int **list_of_levels, int level) {
    *(list_of_levels[level]) ++;
}



int LeftIsSmaller(int first_number, int second_number) {
    return first_number < second_number;
}
