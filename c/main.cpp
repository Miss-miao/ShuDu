#include <iostream>

#define N 4

class shudu {
private:
    int a[N][N] = {};
    int ll[N] = {};

    bool judgeRow(const int b[N]) {             //判断b[N]
        bool flag = true;
        bool flag1 = true;
        /*for (int i = 0; i < N; i++)
            std::cout << a[i] << "\t";
        std::cout << std::endl;*/
        for (int num = 1; num <= N; ++num) {
            for (int i = 0; i < N; i++) {
                if (b[i] == num) {
                    flag1 = true;
                    break;
                } else
                    flag1 = false;
            }
            if (!flag1)
                flag = false;
        }
        return flag;
    }

    void choose(int i, int j) {                 //将第(i+1)行,第(j+1)列位置所有可能性都求出，并放在数组ll[N]中
        int l1[N], l2[N];
        for (int k = 0; k < N; k++) {
            l1[k] = k + 1;
            l2[k] = k + 1;
        }
        for (int num = 0; num < N; ++num) {
            if (a[i][num] != 0) {
                for (int &k : l1) {
                    if (k == a[i][num])
                        k = 0;
                }
            }
            if (a[num][i] != 0) {
                for (int &k : l2) {
                    if (k == a[i][num])
                        k = 0;
                }
            }
        }
        int jk = 0;
        for (int k : l1) {
            for (int m : l2) {
                if ((k != 0) && (k == m)) {
                    ll[jk] = k;
                    jk++;
                }
            }
        }
    }


public:
    explicit shudu(int b[N][N]) {               //构造函数
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                a[i][j] = b[i][j];
        }
    }

    int getValue(int i, int j) {
        return a[i][j];
    }

    void get(int b[N][N]) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                b[i][j] = a[i][j];
        }
    }

    void setValue(int i, int j, int e) {
        a[i][j] = e;
    }

    void display() {
        std::cout << "----------------" << std::endl;
        for (auto &i : a) {
            for (int j : i) {
                std::cout << j << "\t";
            }
            std::cout << std::endl;
        }
        std::cout << "----------------" << std::endl;
    }

    bool judge() {                          //判断每一行每一列每一个小区域是否符合数独的规则
        int b[N];
        for (auto &i : a) {                 //每一行
            if (!judgeRow(i))
                return false;
        }
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                b[j] = a[j][i];
            }
            if (!judgeRow(b))               //每一列
                return false;
        }
        if (N == 4) {
            for (int i = 0; i < N; i += 2) {     //todo:4 or 9
                for (int j = 0; j < N; j += 2) {
                    b[0] = a[i][j];
                    b[1] = a[i][j + 1];
                    b[2] = a[i + 1][j];
                    b[3] = a[i + 1][j + 1];
                    if (!judgeRow(b))           //每一个小区域(N=4)
                        return false;
                }
            }
        }
        if (N == 9) {
            for (int i = 0; i < N; i += 3) {
                for (int j = 0; j < N; j += 3) {
                    b[0] = a[i][j];
                    b[1] = a[i][j + 1];
                    b[2] = a[i][j + 2];
                    b[3] = a[i + 1][j];
                    b[4] = a[i + 1][j + 1];
                    b[5] = a[i + 1][j + 1];
                    b[6] = a[i + 2][j];
                    b[7] = a[i + 2][j + 1];
                    b[8] = a[i + 2][j + 2];
                    if (!judgeRow(b))               //每一个小区域(N=9)
                        return false;
                }
            }
        }
        return true;
    }

    friend void success(shudu T);       //友元
};

bool judgeRow(const int a[N]);      //TODO:

bool judge(int a[N][N]);            //TODO:

bool judge(int a[N][N]) {
    int b[N];
    for (int i = 0; i < N; i++) {
        if (!judgeRow(a[i]))
            return false;
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            b[j] = a[j][i];
        }
        if (!judgeRow(b))
            return false;
    }
    if (N == 4) {
        for (int i = 0; i < N; i += 2) {     //todo:4 or 9
            for (int j = 0; j < N; j += 2) {
                b[0] = a[i][j];
                b[1] = a[i][j + 1];
                b[2] = a[i + 1][j];
                b[3] = a[i + 1][j + 1];
                if (!judgeRow(b))
                    return false;
            }
        }
    }
    if (N == 9) {
        for (int i = 0; i < N; i += 3) {
            for (int j = 0; j < N; j += 3) {
                b[0] = a[i][j];
                b[1] = a[i][j + 1];
                b[2] = a[i][j + 2];
                b[3] = a[i + 1][j];
                b[4] = a[i + 1][j + 1];
                b[5] = a[i + 1][j + 1];
                b[6] = a[i + 2][j];
                b[7] = a[i + 2][j + 1];
                b[8] = a[i + 2][j + 2];
                if (!judgeRow(b))
                    return false;
            }
        }
    }
    return true;
}

bool judgeRow(const int a[N]) {
    bool flag = true;
    bool flag1 = true;
    /*for (int i = 0; i < N; i++)
        std::cout << a[i] << "\t";
    std::cout << std::endl;*/
    for (int num = 1; num <= N; ++num) {
        for (int i = 0; i < N; i++) {
            if (a[i] == num) {
                flag1 = true;
                break;
            } else
                flag1 = false;
        }
        if (!flag1)
            flag = false;
    }
    return flag;
}

void success(shudu T) {                     //回溯，递归?
    auto *newbase = new shudu(T);
    for (int i = 0; i < N; i++) {           //从位置(0,0)开始向后寻找，如果某个位置没有置，就用choose(i,j)函数搜索这个位置可能的值，依次代入并建立子树进行递归
        for (int j = 0; j < N; j++) {
            if (newbase->a[i][j] <= 0) {
                newbase->choose(i, j);
                for (int k : newbase->ll) {
                    if (k > 0) {
                        newbase->a[i][j] = k;
                        success(*newbase);
                    }
                }
            }
            if (i == N - 1 && j == N - 1) {
                if (newbase->judge()) {
                    newbase->display();
                    exit(0);
                }
            }
        }
    }
    delete newbase;
}

int main() {
    int b[N][N] = {1, 2, 3, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    shudu a = shudu(b);
    success(a);
    /*a.display();
    std::cout << a.judge() << std::endl;
    int c[N][N];
    a.get(c);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << c[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    std::cout << judge(c) << std::endl;*/
    return 0;

}

/*一点说明：
1.通过修改宏定义的值可以进行维度为4或9的数独的切换
2.需要注意的是约束条件应足量的多即数独中的未知数应尽可能少，否则计算的时间和消耗的资源会很多
3.在程序搜索到第一个符合的结果程序便会退出
*/