l = [2,5,4,7,12,1,6]
#bubble sort
"""for i in range(len(l)):
     for j in range(i):
          if l[j] > l[i]:
               l[i], l[j] = l[j], l[i]
               print(l,"i = ", i, " j = ", j) """

#counting sort
l = [0, 1, 3, 4, 5, 2, 3, 4, 1, 1, 5, 5, 5]
n = len(l)
max = 5
count = [0]*(max + 1)
for i in range(n):
    count[l[i]] += 1
print(count)
for i in range(1, max+1):
    count[i] += count[i - 1]
print(count)
oparray = [0]*(n)
for i in range(n-1, -1, -1):  
#for i in range(n): 
 
#if u do like this, the index gets swapped- like in the above example we have val "4" at index 4 and 7. 
#if u traverse in positive way, the index 7 "4" will be added first then index "4" ka 4. even though they are the same value, the order should be preserved. 
    oparray[ count[l[i]] - 1] = l[i]
    count[l[i]] -= 1
    print(oparray, l[i], i)