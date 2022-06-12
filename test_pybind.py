import sys
from concurrent.futures import ThreadPoolExecutor
import hle

print(f"nogil={getattr(sys.flags, 'nogil', False)}")


def func():
    sum_value = 0
    for _ in range(100):
        sum_value += hle.Fib(3).run()
        # print(sum_value)
    return sum_value


threads = 2
if len(sys.argv) > 1:
    threads = int(sys.argv[1])

import time
t = time.time()
with ThreadPoolExecutor(max_workers=threads) as executor:
    for _ in range(threads):
        executor.submit(lambda: print(func()))

print(f"time: {time.time() - t:.5f}")
