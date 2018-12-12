def out(f,tup,ans):
    def g(x):
        if x in tup:
            return ans
        else:
            return f(x)
    return g

from math import *

a = out(sqrt, (7,), 2)
print(a(9))