#DataStructures
#---------------------------------------------------------------------------------------
class vector:
    def __init__(self, *values):
        j=0
        self.a=[]
        for i in values:
            self.a.append(i)
            j+=1
    def __add__(self, b):
        for i in range(min(len(self.a), len(b))):
            self.a[i]+=b[i]
        return self.a
        
class stack:
    def __init__(self):
        self.__heap=[]
    def push(self, x):
        self.__heap.append(x)
    def pop(self):
        return self.__heap.pop()
    def peek(self):
        return self.__heap[-1]
    def isEmpty(self):
        return self.__heap==[]
    def size(self):
        return len(self.__heap)

class queue:
    def __init__(self):
        self.__items=[]
    def isEmpty(self):
        return self.__items==[]
    def enqueue(self, n):
        self.__items.insert(0, i)
    def dequeue(self):
        return self.__items.pop()
    def size(self):
        return len(self.__items)
        
class poly: #polynom
    def __init__(self, *args):
        self.val=[]
        for i in args:
            self.val.append(i)
    def __add__(self, b):
        while len(self.val)<len(b.val):
            self.val.append(0)
        for i in range(len(b.val)):
            self.val[i]+=b.val[i]
    def printf(self):
        for i in range(len(self.val)):
            if self.val[i]>=0 and i!=0:
                print('+'+str(self.val[i])+"x^"+str(i), end="")
            elif i==0:
                print(str(self.val[i]), end="")
            #elif self.val[i]==0:
                #print('+0', end="")
            else:
                print(str(self.val[i])+"x^"+str(i), end="")
        print()
    def mult(self, b):
        ans=poly()
        for i in range(2*max(len(self.val), len(b.val))):
            ans.val.append(0)
        while len(self.val)<len(b.val):
            self.val.append(0)
        for i in range(len(b.val)):
            for j in range(len(b.val)):
                ans.val[j+i]+=self.val[i]*b.val[j]
        self.val=ans.val
#Algorhitms
#---------------------------------------------------------------------------------------

#insertion sort
def insort(a, reverse=False):
    n=len(a)
    if not reverse:
        for i in range(1, n):
            x=a[i]
            j=i-1
            while a[j]>x and j>=0:
                a[j], a[j+1] = a[j+1], a[j]
                j-=1
            #print(a)
    else:
        for i in range(1, n):
            x=a[i]
            j=i-1
            while a[j]<x and j>=0:
                a[j], a[j+1] = a[j+1], a[j]
                j-=1
            #print(a)
    return a

#linear search
def lsearch(a, x, last=False):
    n=len(a)
    t=-1
    if not last:
        for i in range(n):
            if a[i]==x:
                t=i
                break
    else:
        for i in range(n-1, -1, -1):
            if a[i]==x:
                t=i
                break
    return t
    
#selection sort
def ssort(a, reverse=False):
    if not reverse:
        n=len(a)
        for i in range(n-1):
            m=i
            for j in range(i, n):
                if a[m]>a[j]:
                    m=j
            a[i], a[m] = a[m], a[i]
    else:
        n=len(a)
        for i in range(n-1):
            m=i
            for j in range(i, n):
                if a[m]<a[j]:
                    m=j
            a[i], a[m] = a[m], a[i]
    return a
    
#merge sort O(n*log2 n)
def msort(a, x, z, reverse=False):
    def merge(a, x, y, z):
        b=a[x:y]
        c=a[y:z]
        b.append(float('inf'))
        c.append(float('inf'))
        i, j = 0, 0
        if not reverse:
            for k in range(x, z):
                if b[i]<c[j]:
                    a[k]=b[i]
                    i+=1
                else:
                    a[k]=c[j]
                    j+=1
        else:
            b[-1]*=-1
            c[-1]*=-1
            for k in range(x, z):
                if b[i]>c[j]:
                    a[k]=b[i]
                    i+=1
                else:
                    a[k]=c[j]
                    j+=1
        #print(b, c, a)
    if x<z and len(a[x:z])>1:
        y=(x+z)//2
        msort(a, x, y, reverse)
        msort(a, y, z, reverse)
        merge(a, x, y, z)
    return a
'''            
def test(a):
    def merge(a, z, b):
        i, j = 0, 0
        z.append(float('inf'))
        b.append(float('inf'))
        #print('l=', a, 'r=', b)
        for k in range(len(z)+len(b)-2):
            #print('i=',i,'j=', j,'k=', k)
            if z[i]<b[j]:
                a[k]=z[i]
                i+=1
            else:
                a[k]=b[j]
                j+=1
        print('a=', a)
        return a
        
    if len(a)>1:
        t=len(a)//2
        l=test(a[:t])
        r=test(a[t:])
        print('l=', l, 'r=', r)
        a=merge(a, l, r)
    return a'''
'''
#recursive insertion sort
def risort(a):
    def ins(a, x):
        j=len(a)-1
        a.append(x)
        #print(x)
        while a[j]>x and j>=0:
            a[j], a[j+1] = a[j+1], a[j]
            j-=1
            #print(j)
        #print(a)
        return a
    if len(a)>1:            
        a=ins(risort(a[:-1]), a[-1])
        #k(a[:-1])
    #print(a)
    return a
    '''
#binary search
def bsearch(a, x):
    t=len(a)//2
    while a[t]!=x and t>0 and t<len(a)-1:
        if a[t]>x:
            t=t//2
        else:
            t=t+(len(a)-t)//2
    if a[t]==x:
        return t
    else:
        return -1
        
#bubble sort
def bsort(a, reverse=False):
    n=len(a)
    if not reverse:
        for i in range(n):
            for j in range(n-1, i, -1):
                if a[i]>a[j]:
                    a[i], a[j] = a[j], a[i]
    else:
        for i in range(n):
            for j in range(n-1, i, -1):
                if a[i]<a[j]:
                    a[i], a[j] = a[j], a[i]
 
#Horner rule for evaluating a polynomial   
def horner(p, x, reverse=False):
    n = len(p)
    if not reverse:
        val = x*p[n-1]
        for i in range(n-2, 0, -1):
            val=x*(val+p[i])
        val+=p[0]        
    else:
        val = x*p[0]
        for i in range(1, n-1):
            val=x*(val+p[i])
        val+=p[-1]        
    return val


    
#a=[int(i) for i in input().split()]
a=[10, 5, 2, 7, 6, 8, 4, 3, 9, 1]
print(a)
#print(msort(a, 0, len(a)))
#print(bsearch(a, 90))
bsort(a, reverse=True)
print(a)
print(horner([1, 0, 1, 1], 2, reverse=True))
a=vector(1, 2, 5)
b=[3, 2, 1]
print(a, a+b)