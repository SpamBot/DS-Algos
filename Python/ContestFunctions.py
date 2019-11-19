#Functions
#---------------------------------------------------------------------------------------
'''
#subset generator    
def tbin(n, f):
    x=n
    s=''
    while x>0:
        s=str(x%2)+s
        x//=2
    if f>len(s):
        s='0'*(f-len(s))+s
    return s

def allsubsets(a):
    for i in range(2**len(a)):
        print(subset(a, tbin(i, len(a))))
    

def subset(a, s):
    b=[]
    for i in range(len(s)):
        if s[i]=='1':
            b.append(a[i])
    return b
    
allsubsets(['a', 'b', 'c'])
'''
#get bit representation of number n
def getbit(n):
    s=''
    for i in range(31):
        if n&(1<<i):
            s='1'+s
        else:
            s='0'+s
    return s

#reverse string O(n)
def rstr(s):
    x=stack()
    s1=''
    for i in s:
        x.push(i)
    while not x.isEmpty():
        s1+=x.pop()
    return s1

#Primality checker
def isprime(n):
    if n<=1:
        return False
    elif n==2 or n==3:
        return True
    elif n%2==0:
        return False
    else:
        x=3
        while n%x!=0 and x<=int(n**(1/2)):
            x+=2
        if n%x!=0:
            return True #[True, n]
        else:
            return False #[False, x]

#Checks whether str is a palindrome
def ispalindrom(s):
    x=0
    if len(s)%2==0:
        n=len(s)//2
    else:
        n=len(s)//2+1
    for i in range(n):
        #print(i, s[i], s[len(s)-1-i])
        if s[i]==s[len(s)-1-i]:
            x+=1
        else:
            break
    if x==n:
        return True
    else:
        return False

#Parenthesis checker
def pcheck(s):
    x=stack()
    for i in s:
        if i=='(' or i=='[' or i=='{':
            	x.push(i)
        elif i==')' or i==']' or i=='}' and not x.isEmpty():
            test=x.pop()
            if (i==')' and test!='(') or (i==']' and test!='[') or (i=='}' and test!='{'):
                return False
        elif (i==')' or i==']' or i=='}') and x.isEmpty():
            return False
    return x.isEmpty()

#Base converter
def bconvert(n, base):
    s=''
    while(n>0):
        if n%base>9:
            t=str(chr(55+n%base))
        else:
            t=str(n%base)
        s=t+s
        n//=base
    return s

#LCM/NOD
def nod(a, b):
    x, y=a, b
    while x!=0 and y!=0:
        if x>y:
            x%=y
        else:
            y%=x
    return max(x, y)
 
#HCF/NOK  
def nok(a, b):
    return (a*b)//nod(a, b)

#divisor counter
def numofdiv(n):
    power=0
    while n%2==0:
        n//=2
        power+=1
    d=power+1
    j=1
    while n>1:
        power=0
        j+=2
        while n%j==0:
            n//=j
            power+=1
        d*=(power+1)
    return d

#binary representation with bits
def tbinb(n):
    s=''
    for i in range(32):
        if n & (1<<i)>0:
            s+='1'
        else:
            s+='0'
    return s

#Another subset generator
def getsub(a):
    n=len(a)
    for i in range(2**n):
        s=tbinb(i)
        for j in range(n):
            if s[j]=='1':
                print(a[j], end=' ')
        print()