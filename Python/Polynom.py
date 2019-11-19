import time
start=time.time()


class poly:
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

a1=poly()
for i in range(201):
    a1.val.append(1)
a2=poly()
for i in range(201):
    if i%2==0:
        a2.val.append(1)
    else:
        a2.val.append(0)
a5=poly()
for i in range(201):
    if i%5==0:
        a5.val.append(1)
    else:
        a5.val.append(0)
a10=poly()
for i in range(201):
    if i%10==0:
        a10.val.append(1)
    else:
        a10.val.append(0)
a20=poly()
for i in range(201):
    if i%20==0:
        a20.val.append(1)
    else:
        a20.val.append(0)
a50=poly()
for i in range(201):
    if i%50==0:
        a50.val.append(1)
    else:
        a50.val.append(0)
a100=poly()
for i in range(201):
    if i%100==0:
        a100.val.append(1)
    else:
        a100.val.append(0)
a200=poly()
for i in range(201):
    if i%200==0:
        a200.val.append(1)
    else:
        a200.val.append(0)
#a1.printf()
print(a1.val, len(a1.val))
#a2.printf()
a1.mult(a2)
#a1.printf()
a1.mult(a5)
a1.mult(a10)
a1.mult(a20)
a1.mult(a50)
a1.mult(a100)
a1.mult(a200)
print(a1.val[200])
            

stop=time.time()
print('running time:', stop-start)
