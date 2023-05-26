hashtable=[[],[],[],[],[],[],[],[],[],[]]
count=[-1,-1,-1,-1,-1,-1,-1,-1,-1,-1]

def insert1():
    n = int(input("Enter the number of elements: "))
    for i in range(n):
        val = int(input("Enter the element: "))
        key = val % 10
        if hashtable[key] == []:
            hashtable[key].append(val)
            hashtable[key].append(-1)
            if count[key] == -1:
                count[key] = key
        else:
            temp = key
            temp1 = hashtable[key]
            ele = temp1[0]
            kn = ele % 10
            if kn == key:
                a = temp1[1]
                if key < 9:
                    key = key + 1
                else:
                    key = 0
                while key != temp:
                    if key <= 9:
                        if hashtable[key] == []:
                            hashtable[key].append(val)
                            hashtable[key].append(-1)
                            if count[temp] == -1:
                                count[temp] = key
                            else:
                                a = count[temp]
                                l = hashtable[a]
                                l[1] = key
                                count[temp] = key
                                break
                        else:
                            key = key + 1
                    else:
                        key = 0
            else:
                hashtable[key] = [val, -1]
                
                if count[temp] == -1:
                    count[temp] = key
                if key < 9:
                    key = key + 1
                else:
                    key = 0
                while key != temp:
                    if key <= 9:
                        if hashtable[key] == []:
                            for i in range(0, 10):
                                if hashtable[i] != []:
                                    b = hashtable[i]
                                    if b[1] == temp:
                                        b[1] = key
                                        hashtable[key] = temp1
                                        flag = 1
                                        break
                            if flag == 1:
                                break
                        else:
                            key = key + 1
                    else:
                        key = 0

def insert2():
    n = int(input("Enter the number of elements: "))
    for i in range(n):
        val = int(input("Enter the element: "))
        key = val % 10
        if hashtable[key] == []:
            hashtable[key].append(val)
            hashtable[key].append(-1)
            if count[key] == -1:
                count[key] = key
        else:
            temp = key
            temp1 = hashtable[temp]
            a = temp1[1]
            if key < 9:
                key = key + 1
            else:
                key = 0
            while key != temp:
                if key <= 9:
                    if hashtable[key] == []:
                        hashtable[key].append(val)
                        hashtable[key].append(-1)
                        if count[temp] == -1:
                            count[temp] = key
                        else:
                            a = count[temp]
                            l = hashtable[a]
                            l[1] = key
                            count[temp] = key
                            break
                    else:
                        key = key + 1
                else:
                    key = 0

def display():
    print('__________________________________________________________')
    print('index ------>> data chain')
    for i in range(0, 10):
        if hashtable[i] != []:
            a = hashtable[i]
            if a[1] == -1:
                print(' ', i, ' ------>> ', a[0], ' ', a[1])
            else:
                print(' ', i, ' ------>> ', a[0], ' ', a[1])
    print('__________________________________________________________')

def search():
    val = int(input('Enter the value to be searched: '))
    flag = 0
    for i in range(0, 10):
        if hashtable[i] != []:
            a = hashtable[i]
            if a[0] == val:
                print('Success!! value', val, 'found at index:', i)
                flag = 1
                break
    if flag == 0:
        print('Sorry..The value was not found')
    print('__________________________________________________________')

def delete():
    val = int(input('Enter the value in the table to be deleted: '))
    flag1 = 0
    b = 0

    for i in range(0, 10):
        if hashtable[i] != []:
            a = hashtable[i]
            if a[0] == val:
                hashtable[i] = []
                flag1 = 1
                b = i
                break
    
    for i in range(0, 10):
        if hashtable[i] != []:
            c = hashtable[i]
            if c[1] == b:
                c[1] = a[1]
                break
    
    if flag1 == 0:
        print("The value is not present in the Hashtable")
    
print('Enter 1 for chaining with replacement')
print('Enter 2 for chaining without replacement')
cho = int(input('Enter your choice: '))
print('__________________________________________________________')
    
if cho == 1:
    insert1()
else:
    insert2()
    
display()
search()
delete()
display()

