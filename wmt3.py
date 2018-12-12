from math import *

'''
def exception_function(f, tup, new_output):
    
    pass



def test1(f, tup, new_ans):
    print(f.__dir__)
    if (f in tup):
        print(2)
        return new_ans
    else:
        return f

a = test1(tan,(7,),2)
print(a)
print(type(a(7)))

def exception_function(f, rejected_input, new_output):
    def inner_function(x):
        if x in rejected_input:
            return new_output
        else:

            return f(x)
    return inner_function

new_sqrt = exception_function(sqrt, (7,), 2)
print(new_sqrt(7))
'''
def atest(n):
    def ff(x):
        def ii(y):
            print(y)
            print(x)
            print(n)
            return y+x+n
        return ii
    return ff
a = atest(555)
b=a(2)
print(b(5))
   
