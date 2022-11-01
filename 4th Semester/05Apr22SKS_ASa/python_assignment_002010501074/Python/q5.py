

def fib(n):
    a, b = 0, 1
    for _ in range(n):
        yield a
        a, b = b, a + b


fibonacci_num = list(fib(10))
print(fibonacci_num)
