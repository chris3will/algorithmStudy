def quick_sort(lst, b, e):
    print(b,e)
    
    if(b<e):
        temp = lst[b]
        i = b
        j = e
        while i < j:
            print(1)
            while (i < j and lst[j] >= temp):
                j -= 1
            if(i<j):
                lst[i] = lst[j]
            while (i < j and lst[i] <= temp):
                i += 1
            if(i<j):
                lst[j] = lst[i]
    
        lst[i] = temp
        quick_sort(lst,b, i - 1)
        quick_sort(lst, i + 1, e)

a = [1, 3,3,412,3,2,123]
quick_sort(a, 0, len(a)-1)
print(a)    
