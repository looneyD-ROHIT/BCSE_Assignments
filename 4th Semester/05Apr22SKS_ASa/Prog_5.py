def gen_fib():
    "Generator function to generate an indefinite sequence of fibonacci numbers"
    a = 0
    b = 1
    while True:
        yield a
        c = a + b
        a = b
        b = c
print("First seven fibonacci number: ")

i = 0
for num in gen_fib():
    if i > 7:
        break
    print(num, end =" ")
    i += 1
print("")