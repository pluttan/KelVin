f2=open("p/2")
mas=[]
for i in range(243):
    try:
        a=f2.readline()
        p=a.find("0x")
        m=""
        for l in range(6):m+=a[p+l+2]
        mas.append(m)
    except:
        mas.append("")
f1=open("p/1")
l=0
for i in f1:
    k=i.replace("()",'("'+mas[l]+'")',1)
    mas[l]=k
    l+=1
for i in range(len(mas)):
    fl=True
    st=mas[i]
    stn=""
    for l in st:
        if l=="_":fl=False
        if l=="(":fl=True
        if fl:
            stn+=l
    mas[i]=stn
f1.close()
f=open("p/1","w")
k=""
for i in mas:k+=i
f.write(k)
print(mas)
