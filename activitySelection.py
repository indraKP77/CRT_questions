def event_count(e):
    e.sort(key=lambda x:x[1])
    result = []
    et = e[0][1]
    result.append(e[0])
    for p in range(1,len(e)):
        if(e[p][0]>et):
            result.append(e[p])
            et = e[p][1]
    print(result)
    return len(result)

start=[1,3,0,5,8,5]
finish =[2,4,6,7,9,9]
e = list(zip(start,finish))
c=event_count(e)
print(c)
