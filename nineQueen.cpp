#include<iostream>

const int N = 8;

bool Judge(bool (*map)[N], int x, int y) {
    int i = x, j = y;

    while (i > 0 && j > 0)
        if (map[--i][--j] == 1)
            return false;

    i = x; j = y;
    while (i < 	N - 1 && j < N - 1)
        if (map[++i][++j] == 1)
            return false;

    i = x; j = y;
    while (i < N - 1)
        if (map[++i][j] == 1)
            return false;

    i = x; j = y;
    while (i > 0)
        if (map[--i][j] == 1)
            return false;

    i = x; j = y;
    while (j < N - 1)
        if (map[i][++j] == 1)
            return false;

    i = x; j = y;
    while (j > 0)
        if (map[i][--j] == 1)
            return false;

    i = x; j = y;
    while (i < 	N - 1 && j > 0)
        if (map[++i][--j] == 1)
            return false;

    i = x; j = y;
    while (i > 0 && j <  N - 1)
        if (map[--i][++j] == 1)
            return false;

//std::cout << "here 1" << std::endl;
    return true;
}

int Counter = 0;

void count(bool (*map)[N], int x) {
    for (int i = 0; i < N; i++) {
        if (Judge(map, x, i)) {
            if (x < N - 1) {
                map[x][i] = 1;
                count(map, x + 1);
                map[x][i] = 0;
            } else {
                Counter++;
/*
map[x][i] = 1;

for (int k = 0; k < N + 1; k++) {
    for (int j = 0; j < N + 1; j++) {
       if (k != 0 && j != 0)
           if (map[k - 1][j - 1] == 1)
               std::cout << map[k - 1][j - 1] << " ";
           else
               std::cout << "  ";
       else if (k == 0)
           if (j == 0)
               std:: cout << "  ";
           else
               std::cout << j << " ";
       else if (j == 0)
               std::cout << k << " ";
    }
    std::cout << std::endl;
}
std::cout << std::endl;

map[x][i] = 0;
*/
            }
        }
    }
    return;
}

int main() {
    bool map[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            map[i][j] = 0;
    count(map, 0);
    std::cout << Counter << std::endl;
    return 0;
}
