def judge_4(ll):
    if not ll.__len__() == 4:
        print("error: the length of list")
        return False
    flag1, flag2 = True, True
    for i in range(1, 5):
        for j in ll:
            if i == j:
                flag1 = True
                break
            else:
                flag1 = False
        if not flag1:
            flag2 = False
            break
    return flag2


def change_22_4(ll):
    l1 = []
    l2 = []
    for i in range(0, 3, 2):
        for j in range(0, 3, 2):
            l1.append(ll[i][j])
            l1.append(ll[i][j + 1])
            l1.append(ll[i + 1][j])
            l1.append(ll[i + 1][j + 1])
            l2.append(list(l1))
            l1.clear()
    return l2


def judge(ll):
    l2 = change_22_4(ll)
    flag = True
    for i in range(4):
        if not judge_4(ll[i]):
            flag = False
            break
        if not judge_4(ll[:][i]):
            flag = False
            break
        if not judge_4(l2[i]):
            flag = False
            break
    return flag


if __name__ == "__main__":
    ll = ((1, 2, 3, 4), (3, 4, 1, 2), (4, 3, 2, 1), (2, 1, 4, 3))
    ju = judge(ll)
    print(ju)
