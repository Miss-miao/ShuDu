import demo4_4


def choose(i, j):
    l1 = list(range(1, 5))
    l2 = list(range(1, 5))
    for num in range(4):
        if not ll[i][num] == 0:
            l1.remove(ll[i][num])
        if not ll[num][j] == 0:
            l2.remove(ll[num][j])
    l3 = []
    for num in l1:
        if num in l2:
            l3.append(num)
    # print(l3)
    return l3


def error_or_success(ll):
    for i in range(4):
        for j in range(4):
            if ll[i][j] <= 0:
                list_possibility = choose(i, j)
                for num in list_possibility:
                    ll[i][j] = num
                    # print(ll)
                    error_or_success(ll)
            if i == 3 and j == 3:
                if demo4_4.judge(ll):
                    print(ll)
                    exit(0)
    # print(ll)


if __name__ == "__main__":
    ll = [[0, 0, 0, 0], [3, 4, 1, 2], [4, 3, 2, 1], [0, 0, 0, 0]]
    error_or_success(ll)
