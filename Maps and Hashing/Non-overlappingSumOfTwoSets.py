def nonOverlapSum(a,b):
    hashMap = {}
    for i,j in zip(a,b):
        if i in hashMap:
            hashMap[i] += 1
        else:
            hashMap[i] = 1

        if j in hashMap:
            hashMap[j] += 1
        else:
            hashMap[j] = 1

    sum = 0
    for i in hashMap:
        if hashMap[i] == 1:
            sum += i

    print sum
    return sum

a = [1,5,3,8]
b = [5,4,6,7]
nonOverlapSum(a,b)
