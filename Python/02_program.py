l1 = [12, 34, 435]
l2 = []
for num in l1:
    count = 0
    while num > 0:
        x = num % 10
        l2.append(x)
        count += 1
        num //= 10
    if count == 3:
        print("List contain number greater than 2")
        break

l2.sort()

ans = 0
d = 1
for i in range(0, len(l2)):
    ans += l2[i] * d
    d *= 10

print(ans)
