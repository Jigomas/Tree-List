#ifndef TREE
#define TREE



typedef int comparing_t(const int a, const int b);



struct tree_t
{
    int data;
    tree_t *left;
    tree_t *right;
};



enum order_of_writing
{
    IN_ORDER,
    PRE_ORDER,
    POST_ORDER
};


tree_t *TreeCtor(int value);

void TreeDtor(tree_t *tree);

tree_t *TreeAdd(tree_t *tree, int value, comparing_t *compare);

tree_t *SearchInTheTree(tree_t *tree, int value);

tree_t *TreePrint(tree_t *tree, int level);

tree_t *TheBracketPrinting(tree_t *tree, int level);

int LeftIsSmaller(int first_number, int second_number);



#endif //TREE
