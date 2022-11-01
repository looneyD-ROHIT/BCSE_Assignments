
import time
def generate_terms(a, r):
    term = a
    yield a
    start_time = time.time()
    while True:
        term = term*r
        if term > 100000:
            print(f"Term reached greater than 100000({term}) Time in loop: {time.time() - start_time} secs.")
            break
        yield term


a = int(input("Enter the first term:"))
r = int(input("Enter the ratio:"))
start_time = time.time()
li = list(generate_terms(a, r))
print(f"{li} Total time: {time.time() - start_time} secs.")
