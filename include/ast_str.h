#ifndef AST_STR_H
#define AST_STR_H

#include<iostream>
#include<vector>
extern int yylineno;

void yyerror(char *s, ...);
#define NodeT_CONSTANT 4 // первые <NodeT_CONSTANT> членов enum NodeT могут использоваться в AST_leaf,
                         //остальные - в AST_node. Введение константы помогает проще различать листья и узлы.
enum NodeT {
    NT_NUM, // число
    NT_COMPARE, // символ сравнения(<,>,==,<=,>=)
    NT_IDENT, // идентификатор переменной/функции
    NT_DATA_TYPE, // название типа данных
    NT_ADD, //сложение
    NT_SUB, // вычитание
    NT_MUL, // умножение
    NT_DIV, // деление
    NT_ABS, // модуль
    NT_NEG, // отрицательное число
    NT_ASSIGN, // присваивание
    NT_INIT_LIST, // список инициализации
    NT_VARDECL, // объявление переменной (начинается с let)
    NT_IFELSE, // конструкция if-else
    NT_COND, // сравнение (a>=b)
    NT_FNDECL, // объявление функции
    NT_TYPED_VAR, // при объявлении функции x: i32
    NT_IL_conc, // при объявлении функции список входных параметров
    NT_FN_CALL, // вызов функции (не обязательно оканчивается на ; может и вызов в выражении)
    NT_NOT, // логическое отрицание
    NT_LOOP, // цикл
    NT_NULL // пустой узел(без свойств)
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
