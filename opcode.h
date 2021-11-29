#ifndef PYTHON_INTERPRETER_OPCODE_H
#define PYTHON_INTERPRETER_OPCODE_H

#define POP_TOP                           1
#define ROT_TWO                           2
#define ROT_THREE                         3
#define DUP_TOP                           4
#define DUP_TOP_TWO                       5
#define ROT_FOUR                          6
#define NOP                               9
#define UNARY_POSITIVE                   10
#define UNARY_NEGATIVE                   11
#define UNARY_NOT                        12
#define UNARY_INVERT                     15
#define BINARY_MULTIPLY                  20
#define BINARY_MODULO                    22
#define BINARY_ADD                       23
#define BINARY_SUBTRACT                  24
#define BINARY_SUBSCR                    25
#define BINARY_FLOOR_DIVIDE              26
#define BINARY_TRUE_DIVIDE               27
#define INPLACE_FLOOR_DIVIDE             28
#define INPLACE_TRUE_DIVIDE              29
#define GET_LEN                          30
#define INPLACE_ADD                      55
#define INPLACE_SUBTRACT                 56
#define INPLACE_MULTIPLY                 57
#define INPLACE_MODULO                   59
#define STORE_SUBSCR                     60
#define DELETE_SUBSCR                    61
#define BINARY_LSHIFT                    62
#define BINARY_RSHIFT                    63
#define BINARY_AND                       64
#define BINARY_XOR                       65
#define BINARY_OR                        66
#define INPLACE_LSHIFT                   75
#define INPLACE_RSHIFT                   76
#define INPLACE_AND                      77
#define INPLACE_XOR                      78
#define INPLACE_OR                       79
#define RETURN_VALUE                     83
#define STORE_NAME                       90
#define DELETE_NAME                      91
#define STORE_GLOBAL                     97
#define DELETE_GLOBAL                    98
#define LOAD_CONST                      100
#define LOAD_NAME                       101
#define COMPARE_OP                      107
#define LOAD_GLOBAL                     116
#define LOAD_FAST                       124
#define STORE_FAST                      125
#define DELETE_FAST                     126

#endif //PYTHON_INTERPRETER_OPCODE_H
