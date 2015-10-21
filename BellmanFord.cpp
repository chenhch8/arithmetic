
// 适用于一般的求最短路径的图

#include<iostream>

const int N = 20;
const int MAX = 100000;

int father[N], d[N];

struct Node {
    int _index, _weight;
    Node* _next;
    Node(int id = -1, int wg = 0, Node* nt = NULL)
    : _index(id), _weight(wg), _next(nt) {}
};

struct HeadNode {
    Node* next;
    HeadNode(): next(NULL) {}
    ~HeadNode() {
        Node* pt = next, *temp;
        while (pt) {
            temp = pt;
            pt = pt->_next;
            delete temp;
        }
    }
};

void foundAdjacentList(HeadNode* pt, int first, int second, int weight) {
    if (!pt[first].next) {
        pt[first].next = new Node(second, weight);
    } else {
        Node* ptr = pt[first].next;
        while (ptr->_next)
            ptr = ptr->_next;
        ptr->_next = new Node(second, weight);
    }
    return;
}

bool BellmanFord(HeadNode* pt, int n, int s) {
    for (int i = 0; i < N; i++) {
        father[i] = -2; d[i] = MAX;
    }
    father[s] = -1; d[s] = 0;
    for (int i = 1; i < n; i++) {
        bool flag = false;
        for (int j = 0; j < n; j++) {
            Node* ptr = pt[j].next;
            while (ptr) {
                if (d[j] + ptr->_weight < d[ptr->_index]) {
                    d[ptr->_index] = d[j] + ptr->_weight;
                    father[ptr->_index] = j;
                    flag = true;
                }
                ptr = ptr->_next;
            }
        }
        if (!flag) break;
    }
    for (int i = 0; i < n; i++) {
        Node* ptr = pt[i].next;
        while (ptr) {
            if (d[ptr->_index] > d[i] + ptr->_weight)
                return false;
            ptr = ptr->_next;
        }
    }
    return true;
}

void printPath(int s, int e) {
    if (s != e)
        printPath(s, father[e]);
    std::cout << e << " ";
    return;
}

int main() {
    int n, x, y, w, s, e;
    std::cout << "请输入顶点个数：";
    std::cin >> n;
    HeadNode* pt = new HeadNode[n];
    std::cout << "请输入起点：";
    std::cin >> s;
    std::cout << "请输入终点：";
    std::cin >> e;
    std::cout << "请输入边及其权值\n";
    while (std::cin >> x >> y >> w)
        foundAdjacentList(pt, x, y, w);
    if (BellmanFord(pt, n, s)) {
        printPath(s, e);
        std::cout << "\n length = " << d[e];
    } else {
        std::cout << "图存在负权回路" << std::endl;
    }
    return 0;
}
