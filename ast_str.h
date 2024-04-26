#ifndef AST_STR_H
#define AST_STR_H

#include<iostream>
#include<vector>
extern int yylineno;

void yyerror(char *s, ...);

enum NodeT {
  NT_NUM,
  NT_UNDEF,
  NT_ADD,
  NT_SUB,
  NT_MUL,
  NT_DIV,
  NT_ABS,
  NT_NEG,
  NT_ASSIGN,
  NT_INIT_LIST,
  NT_IDENT,
  NT_VARDECL,
  NT_CALCLIST
};
struct AST_base{
    int nodetype;
};
struct AST_leaf:public AST_base{
    char* value;
};
std::ostream& operator<<(std::ostream& ost, const AST_leaf& nd);

struct AST_node:public AST_base{
    std::vector<AST_base*> subtrees;
};
std::ostream& operator<<(std::ostream& ost, const AST_node& nd);

AST_node *newast(int nodetype, std::vector<AST_base*> vec);

AST_leaf *newleaf(int nodetype, char* chr);
#endif
