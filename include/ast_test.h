#ifndef AST_TEST_H
#define AST_TEST_H
#include "ast_str.h"
class Test
{
public:
    bool compare_leafs(AST_base*, AST_base*);

    bool compare_nodes(AST_base*, AST_base*);
    bool comp_func(AST_node*,AST_node*);
};

void test_base();
void test_ifelse();
void test_for();

#endif // AST_TEST_H
