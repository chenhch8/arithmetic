
/*���㷨Ҫ�����бߵ�Ȩֵ�Ǹ������������·��*/

#include<iostream>

const int N = 20;

bool if_in[N];  // ���ڱ�Ƕ���i�Ƿ��Ѽ������·���У�falseΪ��trueΪ��
int father[N], d[N];  // father[i]���涥��i�����·���еĸ��㣬d[i]���涥��i����������̹��ƾ���

struct Node {
    int _index, _weight;  // _index���浱ǰ�Ķ���ţ�_weight������ֱ֮�������ĸ������Ȩֵ
    Node* _next;
    Node(int index = -1, int weight = INT_MAX, Node* next = NULL)
    : _index(index), _weight(weight), _next(next) {}
};

struct HeadNode {
    Node* _next;
    HeadNode(): _next(NULL) {}
    ~HeadNode() {
        Node* next = _next, *temp;
        while (next != NULL) {
            temp = next;
            next = next->_next;
            delete temp;
        }
        return;
    }
};

class MinHeap {
 private:
    int _size, _capacity;
    Node* next;
 public:
    MinHeap(int capacity = 16): _size(0), _capacity(capacity) {
        next = new Node[_capacity];
    }
    void Insert(Node tp);
    Node DeleteMin();
    void MakeEmpty() {_size = 0;}
    bool IsFull() {return _size == _capacity;}
    bool IsEmpty() {return _size == 0;}
};

void MinHeap::Insert(Node tp) {
    if (!IsFull()) {
        int i;
        for (i = _size++; i > 0 && tp._weight < next[(i - 1) / 2]._weight; i = (i - 1) / 2)
            next[i] = next[(i - 1) / 2];
        next[i] = tp;
    } else {
        std::cout << "Heap is full." << std::endl;
    }
    return;
}

Node MinHeap::DeleteMin() {
    if (!IsEmpty()) {
        Node tp = next[0], last = next[--_size];
        int i, child;
        for (i = 0; i * 2 + 1 < _size; i = child) {
            child = i * 2 + 1;
            if (child < _size - 1 && next[child]._weight > next[child + 1]._weight)
                child++;
            if (next[child]._weight < last._weight)
                next[i] = next[child];
            else
                break;
        }
        next[i] = last;
        return tp;
    }
}

void foundAdjacentList(HeadNode* pt, int first, int second, int w) {  // �����ڽӱ�
    if (pt[first]._next == NULL) {
        pt[first]._next = new Node;
        pt[first]._next->_index = second;
        pt[first]._next->_weight = w;
    } else {
        Node* next = pt[first]._next;
        while (next->_next != NULL)
            next = next->_next;
        next->_next = new Node;
        next->_next->_index = second;
        next->_next->_weight = w;
    }
    return;
}

void Dijkstra(HeadNode* pt, int n, int s) {  // n�����������s�������
    MinHeap heap(n);
    for (int i = 0; i < N; i++) {
        d[i] = INT_MAX; father[i] = -1; if_in[i] = false;
    }
    d[s] = 0; father[s] = -2;
    heap.Insert(Node(s, d[s]));
    while (!heap.IsEmpty()) {
        Node tp = heap.DeleteMin();
        heap.MakeEmpty();
        if_in[tp._index] = true;
        Node* next = pt[tp._index]._next;
        while (next != NULL) {
            if (d[tp._index] + next->_weight < d[next->_index]) {  // �ɳڱ�
                d[next->_index] = d[tp._index] + next->_weight;
                father[next->_index] = tp._index;
            }
            next = next->_next;
        }
        for (int i = 0; i < n; i++) {  // ��δ����Ķ��������С��
            if (!if_in[i]) {
                heap.Insert(Node(i, d[i]));
            }
        }
    }
    return;
}

void PrintPath(int s, int e) {  // ��ӡ���·�����䳤��
    if (s != e) {
        PrintPath(s, father[e]);
    }
    std::cout << e << " ";
    return;
}

int main() {
    int n, s, e, x, y, w;
    std::cout << "�����붥�������";
    std::cin >> n;

    HeadNode* pt = new HeadNode[n];

    std::cout << "��������㣺";
    std::cin >> s;
    std::cout << "�������յ㣺";
    std::cin >> e;
    std::cout << "������߼���Ȩֵ��\n";
    while (std::cin >> x >> y >> w)
        foundAdjacentList(pt, x, y, w);
    Dijkstra(pt, n, s);
    PrintPath(s, e);
    delete []pt;
    return 0;
}

/*
0 1 10
0 2 5
1 3 1
1 2 2
2 4 2
2 3 9
2 1 3
3 4 4
4 3 6
4 0 7
a

0: 1 2
1: 3 2
2: 4 3 1
3: 4
4: 3 0
*/
