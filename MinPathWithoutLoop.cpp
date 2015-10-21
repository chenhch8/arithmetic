#include<iostream>
#include<vector>
#include<queue>

std::vector<int> Vect;  // 储存拓扑顺序的对应点的下标

struct adjacentNode {
    int _index, _weigth;  // _index代表所指的顶点号，_weigth代表(u,v)长度
    adjacentNode* _next;
    adjacentNode(): _index(-1), _weigth(INT_MAX), _next(NULL) {}
};

struct Node {
    int _d, _father, _inDegree, _topNum;  // _d代表起点到该点的最短距离,_father代表该点的父点,_inDegree代表该点的入度总数, _topNum代表拓扑序号
    adjacentNode* _Next;         // _Next代表其直接指向的子点
    Node(): _d(INT_MAX), _father(-1), _topNum(-1), _inDegree(0), _Next(NULL) {}
};

void countInDegree(Node * ve, int size) {  // 计算各点的入度
    for(int i = 0; i < size; i++) {
        adjacentNode* next = ve[i]._Next;
        while (next != NULL) {
            ve[next->_index]._inDegree++;
            next = next->_next;
        }
    }
}

void fountAdjacentList(Node * ve, int father, int son, int weigth) {
    if (!ve[father]._Next) {
        ve[father]._Next = new adjacentNode;
        ve[father]._Next->_index = son;
        ve[father]._Next->_weigth = weigth;
    } else {
        adjacentNode* next = ve[father]._Next;
        while (next->_next != NULL)
             next = next->_next;
        next->_next = new adjacentNode;
        next->_next->_index = son;
        next->_next->_weigth = weigth;
    }
    return;
}

void TopoSort(Node * ve, int size) {  // 进行拓扑排序
    countInDegree(ve, size);
    std::queue<int> que;
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (ve[i]._inDegree == 0) {
            que.push(i);
            Vect.push_back(i);
        }
    }
    while (!que.empty()) {
        int n = que.front();
        que.pop();
        ve[n]._topNum = ++sum;
        adjacentNode* next = ve[n]._Next;
        while (next) {
            if (--(ve[next->_index]._inDegree) == 0) {
                que.push(next->_index);
                Vect.push_back(next->_index);
            }
            next = next->_next;
        }
    }
    return;
}

void PrintPath(Node * ve, int, int);

void MinPathWithoutLoop(Node * ve, int start, int terminal) {
    int s = 0, e = 0;
    for (int k = 0; k < Vect.size(); k++) {  // 扫描起点和终点的拓扑序
        if (Vect[k] == start)
            s = k;
        if (Vect[k] == terminal)
            e = k;
    }
    if (s > e) {  // 判断起点能否到达终点
        std::cout << "Start Point cannot reach Terminal Point." << std::endl;
        return;
    }
    ve[Vect[s]]._father = -2;
    ve[Vect[s]]._d = 0;
    for (int i = s; i < e; i++) {  // 对路径进行松弛
        adjacentNode* next = ve[Vect[i]]._Next;
        while (next) {
            if (next->_weigth + ve[Vect[i]]._d < ve[next->_index]._d) {  // 对边进行松弛
                ve[next->_index]._d = next->_weigth + ve[Vect[i]]._d;
                ve[next->_index]._father = Vect[i];
            }
            next = next->_next;
        }

    }
    PrintPath(ve, start, terminal);
}

void PrintPath(Node * ve, int start, int terminal) {
    if (terminal != start)
        PrintPath(ve, start, ve[terminal]._father);
    std::cout << terminal << " ";

    return;
}

int main() {
    int n, x, y, w, s, e;
    std::cout << "请输入顶点个数：";
    std::cin >> n;
    std::cout << "请输入起点：\n\tstart = ";
    std::cin >> s;
    std::cout << "请输入终点：\n\tterminal = ";
    std::cin >> e;
    Node* pt = new Node[n];
    std::cout << "请输入边及其权值：\n";
    while (std::cin >> x >> y >> w) {
        fountAdjacentList(pt, x, y, w);
    }
    TopoSort(pt, n);
    MinPathWithoutLoop(pt, s, e);
    return 0;
}

/*
0 1 7
0 2 9
2 1 4
1 4 5
1 3 6
2 3 2
2 5 5
3 4 2
3 6 4
3 5 1
4 6 7
5 6 5
a

0: 1 2
1: 4 3
2: 1 3 5
3: 4 6 5
4: 6
5: 6
6:

0 2 1 3 4 5 6
*/