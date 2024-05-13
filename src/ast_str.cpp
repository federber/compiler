#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "ast_str.h"
#include<vector>
#include<iostream>
#include<unistd.h>
int yyparse(void);

std::string input_value; // см. readme
AST_base* last_node; // см. readme

std::ostream& operator<<(std::ostream& ost, const AST_leaf& nd)
{
    ost << "\tLEAF, nodetype: " << nd.nodetype << ";   value: " << nd.value << " that's all"<< std::endl;
    return ost;
}

std::ostream& operator<<(std::ostream& ost, const AST_node& nd)
{
    ost << std::endl << "=======================node=========================" << std::endl;

    ost << "\nNODE, nodetype: " << nd.nodetype << std::endl;
    ost << "SUBTREES: " << std::endl;
    std::cout << "size: " << nd.subtrees.size() << std::endl;
    /*
    if ((AST_node*)nd.prev != nullptr)
        ost << "~~~~~~~~~prev~~~~~~~~\n"  << *(AST_node*)nd.prev << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        */

    if ((AST_node*)nd.next != nullptr)
        ost << "~~~~~~~~~next~~~~~~~~\n"  << *(AST_node*)nd.next << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

    if (nd.nodetype != NT_NULL)
        for(int i = 0; i < nd.subtrees.size();++i){
            auto el = nd.subtrees[i];
            if(el->nodetype <= NodeT_CONSTANT)
            {
                ost << *(AST_leaf*)el;
                continue;
            }
            ost << *(AST_node*)el;




        }
    else {ost << "wtht parameters" << std::endl; }
    ost << std::endl << "================================================" << std::endl;


    return ost;
}

AST_node *newast(int nodetype, std::vector<AST_base*> vec) {
    AST_node* nd1 = new AST_node;
    nd1->subtrees = vec;
    nd1->nodetype = nodetype;
    return nd1;
}

AST_leaf *newleaf(int nodetype, char* chr) {
  AST_leaf* lf = new AST_leaf;
  lf->nodetype = nodetype;
  lf->value = chr;
  return lf;
}


void yyerror(char *s, ...) {
  va_list ap;
  va_start(ap, s);
  fprintf(stderr, "%d: error: ", yylineno);
  vfprintf(stderr, s, ap);
  fprintf(stderr, "\n");
}

AST_node* find_start_symbol(AST_node* last_symb)
{
    AST_node* start_symb = last_symb;
    while(start_symb->prev != nullptr)
        start_symb = (AST_node*)start_symb->prev;
    return start_symb;
}
void print_tree(AST_node* start_node)
{
    std::cout << "FULL TREE: \n";
     AST_node* curr_node = start_node;
     std::cout << *curr_node;
     while(curr_node->next != nullptr)
     {
        std::cout << *(AST_node*)curr_node->next;
        curr_node = (AST_node*)curr_node->next;
        std::cout << "+++++++++++++++++++++++++++++++++++++++++++++\n";
     }
}
AST_node* get_AST(std::string code_buffer)
{
    input_value = code_buffer;
    yyparse();
    return find_start_symbol((AST_node*)last_node);
}
/* example uf using get_AST
int main() {
  printf(">>> ");
  std::string a;
  a = "let r=9; if a==e {a=ss; let r=p;} else {let a=c;}";
  std::cout << *get_AST(a);
}
*/


