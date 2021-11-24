#ifndef PYTHON_INTERPRETER_OPCODE_H
#define PYTHON_INTERPRETER_OPCODE_H

#define POP_TOP                           1
#define ROT_TWO                           2
#define ROT_THREE                         3
#define DUP_TOP                           4
#define DUP_TOP_TWO                       5
#define ROT_FOUR                          6
#define NOP                               9
#define RETURN_VALUE                     83
#define STORE_NAME                       90
#define DELETE_NAME                      91
#define STORE_GLOBAL                     97
#define DELETE_GLOBAL                    98
#define LOAD_CONST                      100
#define LOAD_NAME                       101
#define LOAD_GLOBAL                     116
#endif //PYTHON_INTERPRETER_OPCODE_H
