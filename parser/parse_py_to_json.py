#!/usr/bin/python3
import json
from argparse import ArgumentParser
import os

parser = ArgumentParser()
parser.add_argument("--path", "-p", type=str)

path = parser.parse_args().path
with open(path) as f:
    source = f.read()

code = compile(source, path, "exec")

code.co_code

attrs = ['co_argcount',
 'co_cellvars',
 'co_code',
 'co_consts',
 'co_filename',
 'co_firstlineno',
 'co_flags',
 'co_freevars',
 'co_kwonlyargcount',
 'co_lnotab',
 'co_name',
 'co_names',
 'co_nlocals',
 'co_posonlyargcount',
 'co_stacksize',
 'co_varnames']

def code_to_dict(code):
    code_dict = {}
    iterable = {'co_cellvars', 'co_varnames', 'co_names', 'co_lnotab', 'co_freevars', 'co_code', 'co_consts'}
    for key in attrs:
        x = getattr(code, key)
        if key in iterable:
            x = list(x)
        if key == 'co_consts':
            for i, j in enumerate(x):
                if type(j) is type(code):
                    x[i] = code_to_dict(j)
        code_dict[key] = x
    return code_dict

code_dict = code_to_dict(code)

with open(os.path.basename(path)+'.cjson', 'w') as f:
    json.dump(code_dict, f, indent=4)

