// 求最小生成树（用二维数组）

#include<iostream>
#include<ctime>
#include<cstdlib>

const int N = 50;

struct low {
    int length;
    int father;
    bool if_in;
    low(): length(INT_MAX), if_in(false) {}
} Low[N];

int map[N][N];

void Prim(int n) {

    srand(unsigned(time(NULL)));
    int k = rand() % n, sum = 1, min, pt, all = 0;
    Low[k].length = 0;
    Low[k].father = k;
    Low[k].if_in = true;
    while (sum < n) {
        min = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (!Low[i].if_in) {
                if (map[k][i] < Low[i].length) {
                    Low[i].length = map[k][i];
                    Low[i].father = k;
                }
                if (Low[i].length < min) {
                    min = Low[i].length;
                    pt = i;
                }
            }
        }
        if (!Low[pt].if_in) {
            std::cout << Low[pt].father << " " << pt << " " << Low[pt].length << std::endl;
            Low[pt].if_in = true;
            all += Low[pt].length;
            k = pt;
            sum++;
        }
    }
    std::cout << "total min length = " << all << std::endl;
    return;
}

int main() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            map[i][j] = INT_MAX;
    }
    int n, k, p, w;
    std::cout << "请输入顶点个数（<= 50 ）：";
    std::cin >> n;
    std::cout << "输入边和权值(默认无向边)：\n";
    while (std::cin >> k >> p >> w) {
        map[k][p] = w;
        map[p][k] = w;
    }
    /*for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] != INT_MAX)
                std::cout << map[i][j] << " ";
            else
                std::cout << "  ";
        }
        std::cout << std::endl;
    }*/
    Prim(n);
    return 0;
}

/*
6
0 1 6
1 4 3
4 5 6
5 3 2
3 0 5
0 2 1
1 2 5
4 2 6
5 2 4
3 2 5
a
*/