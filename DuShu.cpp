#include<iostream>
#include<cstdio>

const int N = 9;

bool Judge(int (*map)[N], int x, int y, int k) {
    if (k == 1)
        if (x == y) return false;
    // 判断每一宫是否符合独数
    int i = x / 3, j = y / 3;
    for (int ii = i * 3; ii < i * 3 + 3; ii++)
        for (int jj = j * 3; jj < j * 3 + 3; jj++)
            if (map[ii][jj] == k)
               return false;
    // 判断每一行每一列是否符合独数
    i = x; j = y;
    while (i > 0)
        if (map[--i][j] == k)
            return false;
    i = x; j = y;
    while (i < N - 1)
        if (map[++i][j] == k)
            return false;
    i = x; j = y;
    while (j > 0)
        if (map[i][--j] == k)
            return false;
    i = x; j = y;
    while (j < N - 1)
        if (map[i][++j] == k)
            return false;
    return true;
}
unsigned long long Count = 0;

void count(int (*map)[N], int x, int y) {
    for (int i = 1; i <= N; i++) {
        if (Judge(map, x, y, i)) {  // Judge(map, x, y, i)用于判断map[x][y] = i是否满足要求
            map[x][y] = i;
            if (y == N - 1 && x < N - 1) {
                count(map, x + 1, 0);
                map[x][y] = 0;
            } else if (y < N - 1) {
                count(map, x, y + 1);
                map[x][y] = 0;
            } else if (y == N - 1 && x == N - 1) {
                Count++;
                map[x][y] = 0;
                printf("%d\n", Count);
            }
        }
    }
    return;
}

int main() {
    int map[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            map[i][j] = 0;
    count(map, 0, 0);
    std::cout << Count << std::endl;
    return 0;
}
