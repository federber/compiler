# compiler
## Формирование AST дерева
### Сборка
Для сборки(отдельно блока для формирования дерева) необходимо выполнить следующие команды:

```
	mkdir build
    cd build
    cmake ..
    make
```
### Описание алгоритма

```
	std::string input_value;
	AST_base* last_node;
```
В глобальную переменную input_value записывается буффер с кодом, на основе которого необходимо построить дерево.
Для возможности считывания даннных из std::string переопределена функция YY_INPUT (см. lexer_ast.l)
last_node - глобальная переменная, хранит в себе указатель на последнее обработанное правило (правила обрабатываются
не в порядке следования во входной строке, а в поредке их определения в .y файле).

```
struct AST_base{
    int nodetype;
};
struct AST_leaf:public AST_base{
    char* value;
};

struct AST_node:public AST_base{
    std::vector<AST_base*> subtrees;
    AST_base* prev = nullptr; //указатель на предыд. узел
    AST_base* next = nullptr; //указатель на след. узел
};
```

Про свойства, предыдущий(prev) и следующий(next) узел см. пример и ниже:

```
...
if a==w {
	let f=o;
	i=e;
}
let r=h;
...
```

Здесь:

prev:
if для let f=o;
if для let r=h;

next:
let r=h; для if

свойства:
a==w, {let f=o;i=e;} для if

(!)  if не является prev для a==w, так как правило верхнего уровня commands не включает в себя правило нижнего уровня compare,
и нет необходимости подниматься из compare выше. В данном случае не будем выполнять лишнее действие


Блоки вида:

```
((AST_node*)$7)->prev = $$; 
```

нужны для возможности подняться вверх к корню из любого узла. По это причине данные блоки присутствуют не только commands:<...>(правиле верхнего уровня),
но и в правилах нижнего уровня, вроде

```
if_else: IFTOK condition '{' commands '}'
    {
        auto b = newast(NT_NULL, {});
        $$ = newast(NT_IFELSE, {$2, $4, b});
        ((AST_node*)$4)->prev = $$;
    }
```
Хотя токен commands в данном случае не является коммандой, выполняемой после блока if-else, а является поддеревом этого блока, 
переопределение prev помогает подняться из блока кода, выполняемого при истинности условия if, во внешний блок кода. 
При необходимости отличать поддерево(свойство) узла, от следующего за ним узла, можно посмотреть на указатель next (см (*) ниже).

Пусть el1 - некий узел
el2 - другой узел,и el2.prev = el1 (формально, здесь опускаются операторы взятия адреса, преобразования типов и т.д.)
el2 не следует за el1, а является его свойством (свойством if называется в т.ч. блок кода, выполняемый при истинности условия if)
Пусть el3 - узел, следующий за el1
Тогда:
el2.prev = el1
el3.prev = el1
el1.next = el3 (*)
если бы после el1 не шел el3, то было бы el1.next = nullptr
