def add(a, b):
    return a+b

def fib(n):
    if n==0 or n==1:
        return 1
    return add(fib(n-1),fib(n-2))

print(fib(0))
print(fib(1))
print(fib(5))