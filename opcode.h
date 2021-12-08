#ifndef PYTHON_INTERPRETER_OPCODE_H
#define PYTHON_INTERPRETER_OPCODE_H

#define POP_TOP                           1
#define ROT_TWO                           2
#define ROT_THREE                         3
#define DUP_TOP                           4
#define DUP_TOP_TWO                       5
#define ROT_FOUR                          6
#define NOP                               9
#define UNARY_NEGATIVE                   11
#define UNARY_NOT                        12
#define UNARY_INVERT                     15
#define BINARY_MULTIPLY                  20
#define BINARY_ADD                       23
#define BINARY_SUBTRACT                  24
#define BINARY_SUBSCR                    25
#define BINARY_TRUE_DIVIDE               27
#define INPLACE_TRUE_DIVIDE              29
#define GET_LEN                          30
#define INPLACE_ADD                      55
#define INPLACE_SUBTRACT                 56
#define INPLACE_MULTIPLY                 57
#define BINARY_AND                       64
#define BINARY_OR                        66
#define GET_ITER                         68
#define RETURN_VALUE                     83
#define STORE_NAME                       90
#define DELETE_NAME                      91
#define FOR_ITER                         93
#define STORE_GLOBAL                     97
#define DELETE_GLOBAL                    98
#define LOAD_CONST                      100
#define LOAD_NAME                       101
#define BUILD_LIST                      103
#define COMPARE_OP                      107
#define JUMP_FORWARD                    110
#define JUMP_IF_FALSE_OR_POP            111
#define JUMP_IF_TRUE_OR_POP             112
#define JUMP_ABSOLUTE                   113
#define POP_JUMP_IF_FALSE               114
#define POP_JUMP_IF_TRUE                115
#define LOAD_GLOBAL                     116
#define LOAD_FAST                       124
#define STORE_FAST                      125
#define DELETE_FAST                     126
#define CALL_FUNCTION                   131
#define MAKE_FUNCTION                   132
#define LIST_APPEND                     145
#define LOAD_METHOD                     160
#define CALL_METHOD                     161
#define LIST_EXTEND                     162

#endif //PYTHON_INTERPRETER_OPCODE_H
