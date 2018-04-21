li = [1, 2, 3, 4, 5, 6, 7, 8, 9]
flag1, flag2 = True, True
for i in range(1, 10):
    for j in li:
        if i == j:
            flag1 = True
            break
        else:
            flag1 = False
    if not flag1:
        flag2 = flag1
print(flag2)
