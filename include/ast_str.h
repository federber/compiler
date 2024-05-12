#ifndef AST_STR_H
#define AST_STR_H

#include<iostream>
#include<vector>
extern int yylineno;

void yyerror(char *s, ...);
#define NodeT_CONSTANT 4 // первые <NodeT_CONSTANT> членов enum NodeT могут использоваться в AST_leaf,
                         //остальные - в AST_node. Введение константы помогает проще различать листья и узлы.
enum NodeT {
    NT_NUM,
    NT_COMPARE,
    NT_IDENT,
    NT_DATA_TYPE,
    NT_ADD,
    NT_SUB,
    NT_MUL,
    NT_DIV,
    NT_ABS,
    NT_NEG,
    NT_ASSIGN,
    NT_INIT_LIST,
    NT_VARDECL,
    NT_CALCLIST,
    NT_IFELSE,
    NT_COND,
    NT_FNDECL,
    NT_TYPED_VAR,
    NT_IL_conc,
    NT_FN_CALL,
    NT_NOT,
    NT_LOOP,
    NT_NULL
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
    AST_base* prev = nullptr; //указатель на предыд. узел (подробнее - см. readme)
    AST_base* next = nullptr; //указатель на след. узел
};
std::ostream& operator<<(std::ostream& ost, const AST_node& nd);

AST_node *newast(int nodetype, std::vector<AST_base*> vec);

AST_leaf *newleaf(int nodetype, char* chr);
#endif
