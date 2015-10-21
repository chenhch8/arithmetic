// 用贪心算法实现最小生成树

#include<iostream>
#include<ctime>
#include<cstdlib>

struct ED {
    int x, y;
    int w;
    ED() {w = INT_MAX;}
} Edge[50];

int father[50];

int size[50];

bool Is_same(int x, int y) {
    while (father[x] != x) {
        father[x] = father[father[x]];
        x = father[x];
    }
    while (father[y] != y) {
        father[y] = father[father[y]];
        y = father[y];
    }
    return x==y;
}

void Union(int x, int y) {
    while (father[x] != x) {
        father[x] = father[father[x]];
        x = father[x];
    }
    while (father[y] != y) {
        father[y] = father[father[y]];
        y = father[y];
    }
    if (size[x] < size[y]) {
        size[y] += size[x];
        father[x] = y;
    } else {
        size[x] += size[y];
        father[y] = x;
    }
    return;
}

void edgeSort(int left, int right) {
    if (left >= right) return;
    srand(unsigned(time(NULL)));
    int n = rand()%(right - left + 1) + left;
    int temp = Edge[n].w;
    ED ttp = Edge[n];
    Edge[n] = Edge[left];
    int i = left + 1, j = right;
    while (i <= j) {
        while (Edge[i].w < temp && i <= right) i++;
        while (Edge[j].w > temp && j >= left + 1) j--;
        if (i <= j) {
            ED tp = Edge[i];
            Edge[i++] = Edge[j];
            Edge[j--] = tp;
        } 
    }
    if (j >= 0) {
        Edge[left] = Edge[j];
        Edge[j] = ttp;
    }
    edgeSort(left, j - 1);
    edgeSort(j + 1, right);
    return;
}

void Kruskal(int n) {
    edgeSort(0, n);
//for (int i = 0; i <= n; i++)
//std::cout << Edge[i].w << " " << Edge[i].x << " " << Edge[i].y << std::endl;
    int m = 0, sum_w = 0;
    while (m < n) {  ///////////////////////////////////////////////////////
        if (!Is_same(Edge[m].x, Edge[m].y)) {
            sum_w += Edge[m].w;
            std::cout << Edge[m].x << " " << Edge[m].y << std::endl;
            Union(Edge[m].x, Edge[m].y);
        }
        m++;
    }
    std::cout << "sum_w = " << sum_w << std::endl;
}

int main() {
    int i, j, w, n = 0;
    for (int k = 0; k < 50; k++) {
        father[k] = k;
        size[k] = 1;
    }
    std::cout << "请输入各边权：\n";
    while (std::cin >> i >> j >> w) {
        Edge[n].x = i;
        Edge[n].y = j;
        Edge[n++].w = w;
    }
    Kruskal(n - 1);
    return 0;
}

/*
0 1 6
1 4 3
4 5 6
5 3 2
0 2 1
1 2 5
4 2 6
5 2 4
3 2 5
a
*/