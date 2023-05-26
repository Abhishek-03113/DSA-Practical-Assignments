n=int(input("Enter the value of hashtable = "))
hashtable=[[],[],[],[],[],[],[],[],[],[]]

def linear_probing(val,phone):
    temp=[]
    temp.append(phone)
    while hashtable[val]!=[]:
        val=val+1
        if val>10:
            val=0
    hashtable[val].append(temp)
    return val

def seperate_chaining(val,phone):
    hashtable[val].append(phone)

def hash_fun(phone):
    return phone%10

def insert_value(phone):
    val=hash_fun(phone)
    if(hashtable[val]==[]):
        temp=[]
        temp.append(phone)
        hashtable.insert(val,temp)

    else:
        value=int(input("\n Colllision has occured \n 1.Linear probing \t 2.Seperate chaining"))
        if value==1:
            val=linear_probing(val,phone)
        if value==2:
            seperate_chaining(val,phone)
    print("Inserted at hash value = "+str(val))

def display():
    for i in range (10):
        print(str(i)+"->"+str(hashtable[i]))

def search(phone):
    for i in range(10):
        for j in range(len(hashtable[i])):
            if hashtable[i][j]==phone:
                return i

for i in range(n):
    pno=int(input("Enter the phone number"))
    insert_value(pno)

print("\n Hashtable \n")
display()

s=int(input("Enter the number to be searched"))
print("Phone number found at position :",search(s))
    
