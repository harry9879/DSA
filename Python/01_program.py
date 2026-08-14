var = int(input("Enter the number"))

# 1234
# x = 4
# 123
ans = ""
y = 1
while var > 0:
    rem = var % 10
    ans += str(rem)
    var //= 10

print(ans)
