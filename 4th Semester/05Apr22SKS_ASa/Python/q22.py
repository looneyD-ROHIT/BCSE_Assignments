
import cProfile


def pythagoreanTriplets(limits):
    c, m = 0, 2
    while c < limits:
        for n in range(1, m):
            a = m * m - n * n
            b = 2 * m * n
            c = m * m + n * n
            if c > limits:
                break
            li = [a, b, c]
            yield li
        m = m + 1


def main():
    limit = 100
    l1 = list(pythagoreanTriplets(limit))


if __name__ == '__main__':
    cProfile.run('main()')
