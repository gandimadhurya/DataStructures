'''
Problem
Calculate (x^y)%z without pow()
'''

def evaluate(x,y,z):
    if y==1:
        return x%z
    elif x%z == 0:
        return 0
    else:
        return evaluate(x,y-1,z) * (x%z)%z


print evaluate(1,2,3)
print evaluate(11,21,31)
print evaluate(10,20,30)
print evaluate(2,2,3)
print evaluate(3,2,3)
print evaluate(5,1,3)
