
import math


def is_square(i: int) -> bool:
    return i == math.isqrt(i) ** 2


l1 = [9, 169, 25, 4, 10, 5, 16]
filtered_list = filter(lambda x: x % 2 != 0 and is_square(x), l1)
print(list(filtered_list))
