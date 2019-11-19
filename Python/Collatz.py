def collatz(n):
    if n%2==0:
        return n//2
    else:
        return 3*n+1
a=[0 for i in range(1, 1000001)]
n=2
l=0
while n<1000000:
    k=n
    while k>=n:
        k=collatz(k)
        l+=1
        #print(77)
    a[n]=l+a[k]
    l=0
    n+=1
m=0
j=0
for i in range(len(a)):
    if a[i]>m:
        m=a[i]
        j=i
print(j)

'''
#pow of 2
a=[1]
n=int(input())
for i in range(n):
    d=0
    for j in range(len(a)):
        x= a[j]*2+d
        a[j]=x%1000000
        d=x//1000000
    if d>0:
        a.append(d)
x=0
for i in a:
    for j in str(i):
        x+=int(j)
print(x)
'''
'''
#number to word converter
def readnum(n):
    a=["", 'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine'] 
    a2=["", 'ten', 'eleven', 'twelve', 'thirteen', 'fourteen', 'fifteen', 'sixteen', 'seventeen', 'eighteen', 'nineteen']
    a3=["", 'twenty', 'thirty', 'forty', 'fifty', 'sixty', 'seventy', 'eighty', 'ninety']
    if 0<n and n<10:
        return a[n]
    elif 9<n and n<20:
        return a2[n-9]
    elif 19<n and n<100:
        return a3[n//10-1]+a[n%10]
    elif 99<n and n<1000:
        if 0<n%100 and n%100<10:
            return a[n//100]+'hundredand'+a[n%100]
        elif 9<n%100 and n%100<20:
            return a[n//100]+'hundredand'+a2[(n%100)-9]
        elif 19<n%100 and n%100<100:
            return a[n//100]+'hundredand'+a3[(n%100)//10-1]+a[(n%100)%10]
        else:
            return a[n//100]+'hundred'
    elif n==1000:
        return 'onethousand'
'''
