#include "ast_str.h"
#include "ast_test.h"

    bool Test::compare_leafs(AST_base* ast1, AST_base* ast2)
    {
        if(((AST_leaf*)ast1)->nodetype != ((AST_leaf*)ast2)->nodetype or std::string(((AST_leaf*)ast1)->value) != std::string(((AST_leaf*)ast2)->value)){
            std::cout << "p1" << std::endl;
            std::cout <<"leaf nodetype: " << ((AST_leaf*)ast1)->nodetype << " but " << ((AST_leaf*)ast2)->nodetype << ";" << std::endl;
            std::cout <<"leaf value: " << ((AST_leaf*)ast1)->value << " but " << ((AST_leaf*)ast2)->value << ";" << std::endl;
            return false;
        }
        return true;
    }

    bool Test::comp_func(AST_node* n1,  AST_node* n2)
    {
        if(n1->nodetype != n2->nodetype or ((AST_node*)n1)->subtrees.size() != ((AST_node*)n2)->subtrees.size()){
            std::cout << "p2" << std::endl;
            std::cout <<"nodetype: " << n1->nodetype << " but " << n2->nodetype << std::endl;
            std::cout <<"size: " << ((AST_node*)n1)->subtrees.size() << " but " << ((AST_node*)n2)->subtrees.size() << std::endl;

            return false;
        }
        for(int i = 0; i < n1->subtrees.size(); ++i)
            if((n1->subtrees[i])->nodetype <= NodeT_CONSTANT and (n2->subtrees[i])->nodetype <= NodeT_CONSTANT){
                if(not compare_leafs(n1->subtrees[i], n2->subtrees[i])){
                    std::cout << "p3" << std::endl;
                    return false;
                }
            }
            else{
                if(not compare_nodes(n1->subtrees[i], n2->subtrees[i])){
                    std::cout << "p4" << std::endl;
                    return false;
                }
            }
        return 1;
    }

    bool Test::compare_nodes(AST_base* ast1, AST_base* ast2)
    {
        AST_node* curr_node_1 = (AST_node*)ast1;
        AST_node* curr_node_2 = (AST_node*)ast2;

        if (curr_node_1 == nullptr and curr_node_2 == nullptr)
            return true;
        auto n1 = curr_node_1;
        auto n2 = curr_node_2;
        if(not comp_func(n1,n2)){
            std::cout << "p5" << std::endl;
            return false;
        }
        while(curr_node_1->next != nullptr and curr_node_2->next != nullptr)
        {
            n1 = (AST_node*)(curr_node_1->next);
            n2 = (AST_node*)(curr_node_2->next);
            if(not comp_func(n1,n2)){
                std::cout << "p6" << std::endl;
                return false;
            }
            curr_node_1 = n1;
            curr_node_2 = n2;
            
         }
         if (curr_node_1->next != nullptr or curr_node_2->next != nullptr){
             std::cout << "p7" << std::endl;
            return false;
         }
         return true;
    }


void test_base()
{
    Test t;
    std::cout << "Проверка адекватности функции сравнения деревьев:" << std::endl;
    AST_leaf* l1 = newleaf(NT_IDENT, "v1");
    AST_leaf* l2 = newleaf(NT_NUM, "7");
    AST_node* nd1 = newast(NT_VARDECL, {l1,l2});

    AST_leaf* l3 = newleaf(NT_IDENT, "v1");
    AST_leaf* l4 = newleaf(NT_NUM, "7");
    AST_node* nd2 = newast(NT_VARDECL, {l3,l4});

    std::cout << "result: " << std::boolalpha << t.compare_nodes((AST_base*)nd1,(AST_base*)nd2) <<", predicted: " << "true" << std::endl;
    l4->value = "99";
    std::cout << "result: " << std::boolalpha << t.compare_nodes((AST_base*)nd1,(AST_base*)nd2) <<", predicted: " << "false" << std::endl;
}

void test_ifelse()
{
    Test t;
    std::cout << "Проверка построения дерева (IF_ELSE): " << std::endl;

    std::string str;
    str = "let z=9; if q==m {e=ss; let r=p;} else {let a=c;}";
    AST_node* res = get_AST(str);

    AST_leaf* c = newleaf(NT_IDENT,"c");
    AST_leaf* a = newleaf(NT_IDENT,"a");
    AST_leaf* p = newleaf(NT_IDENT,"p");
    AST_leaf* r = newleaf(NT_IDENT,"r");
    AST_leaf* ss = newleaf(NT_IDENT,"ss");
    AST_leaf* e = newleaf(NT_IDENT,"e");
    AST_leaf* m = newleaf(NT_IDENT,"m");
    AST_leaf* q = newleaf(NT_IDENT,"q");
    AST_leaf* z = newleaf(NT_IDENT,"z");
    AST_leaf* nm = newleaf(NT_NUM,"9");

    AST_node* assign_in_let_ac = newast(NT_ASSIGN,{a,c});
    AST_node* let1 = newast(NT_VARDECL,{assign_in_let_ac});

    AST_node* assign_in_let_rp = newast(NT_ASSIGN,{r,p});
    AST_node* let2 = newast(NT_VARDECL,{assign_in_let_rp});

    AST_node* assign_in_let_z9 = newast(NT_ASSIGN,{z,nm});
    AST_node* let3 = newast(NT_VARDECL,{assign_in_let_z9});

    AST_node* assign1 = newast(NT_ASSIGN,{e,ss});

    AST_leaf* compare1 = newleaf(NT_COMPARE,"==");
    AST_node* condition1 = newast(NT_COND,{compare1,q,m});

    AST_node* ifelse1 = newast(NT_IFELSE,{condition1,assign1,let1});

    let3->next = ifelse1;
    ifelse1->prev = let3;

    assign1->next = let2;
    assign1->prev = ifelse1;
    let2->prev = assign1;

    let1->prev = ifelse1;

    AST_node* pred_res = let3;

    std::cout << "result: " << std::boolalpha << t.compare_nodes((AST_base*)res,(AST_base*)pred_res) <<", predicted: " << "true" << std::endl;
    remove_ast(res);
}

void test_for(){
    std::cout << "Проверка построения дерева (FOR): " << std::endl;
    Test t;
    std::string str = "for s in 1..7 {c=o;i=p;}";
    AST_node* res = get_AST(str);

    AST_leaf* c = newleaf(NT_IDENT,"c");
    AST_leaf* o = newleaf(NT_IDENT,"o");
    AST_node* assign1 = newast(NT_ASSIGN,{c,o});

    AST_leaf* i = newleaf(NT_IDENT,"i");
    AST_leaf* p = newleaf(NT_IDENT,"p");
    AST_node* assign2 = newast(NT_ASSIGN,{i,p});

    AST_leaf* nm1 = newleaf(NT_NUM,"1");
    AST_leaf* nm7 = newleaf(NT_NUM,"7");

    AST_leaf* s = newleaf(NT_IDENT,"s");
    AST_node* interv1 = newast(NT_INTERV,{nm1,nm7});
    AST_node* inint1 = newast(NT_ININT,{s,interv1});

    AST_leaf* loopname1 = newleaf(NT_IDENT,"for");
    AST_node* for1 = newast(NT_LOOP,{loopname1,inint1,assign1});


    inint1->prev = for1;
    assign1->prev = for1;
    assign1->next = assign2;
    assign2->prev = assign1;

    AST_node* pred_res = for1;

    std::cout << "result: " << std::boolalpha << t.compare_nodes((AST_base*)res,(AST_base*)pred_res) <<", predicted: " << "true" << std::endl;

    remove_ast(res);
}
