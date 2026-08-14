var = int(input("enter the number"))
for i in range(1, var + 1):
    for j in range(1, i + 1):
        print(j, end=" ")
    print()
for i in range(var - 1, 0, -1):
    for j in range(1, i + 1):
        print(j, end=" ")
    print()
