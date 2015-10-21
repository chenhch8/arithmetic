#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>

struct Edge {
    int x, y;
    int w;
    bool x_in, y_in;
    Edge(): x_in(false), y_in(false) {}
    Edge(int _x, int _y, int _w): x(_x), y(_y), w(_w), x_in(false), y_in(false) {}
};

const int MinSum = 16;

class MinHeap {
 private:
    Edge* pt;
    int _size;
    int _capacity;
 public:
    MinHeap(int capt = MinSum): _size(0), _capacity(capt) {
        pt = new Edge[_capacity];
    }
    ~MinHeap() {
        if (pt != NULL)
            delete []pt; 
    }
    void Insert(Edge element);
    Edge DeleteMin();
    bool IsFull() {return _size == _capacity;}
    bool IsEmpty() {return _size == 0;}
    int Size() {return _size;}
    int Capacity() {return _capacity;}
    void MakeEmpty() {_size = 0;}
};

void MinHeap::Insert(Edge element) {
    if (!IsFull()) {
        int i;
        for (i = _size++; i > 0 && pt[(i - 1) / 2].w > element.w; i = (i - 1) / 2)
            pt[i] = pt[(i - 1) / 2];
        pt[i] = element;
    } else {
       std::cout << "Priority queue is full." << std::endl;
    }
    return;
}

Edge MinHeap::DeleteMin() {
    Edge temp = pt[0], last = pt[--_size];
    int i, child;
    for (i = 0; i * 2 + 1 < _size; i = child) {
        child = i * 2 + 1;
        if (child < _size - 1 && pt[child].w > pt[child + 1].w)
            child++;
        if (pt[child].w < last.w)
            pt[i] = pt[child];
        else {
            pt[i] = last;
            break;
        }
    }
    return temp;
}

void PrimByMinHeap(std::vector<Edge> & ve, int s) {
    int sum_of_edge = 0, sum = ve.size();
    MinHeap heap(32);
    for (unsigned i = 0; i < ve.size(); i++) {
        if (ve[i].x == s || ve[i].y == s) {
            heap.Insert(ve[i]);
        }
    }
    while (sum_of_edge < sum) {
        if (!heap.IsEmpty()) {
            Edge min = heap.DeleteMin();
            // 根据节点有无被标来找到不在生长树内的边
            for (int i = 0; i < sum; i++) {
                if (ve[i].x == min.x && ve[i].y == min.y) {
                    if (ve[i].x_in && ve[i].y_in && !heap.IsEmpty()) {
                        min = heap.DeleteMin();
                        i = -1;
                    } else if (ve[i].x_in && ve[i].y_in && heap.IsEmpty()) {
                        sum = 0;
                        break;
                    }
                }
            }
            // 标记被选择的最小边对应的顶点
            for (int i = 0; i < sum; i++) {
                if (ve[i].x == min.x || ve[i].x == min.y)
                    ve[i].x_in = true;
                if (ve[i].y == min.x || ve[i].y == min.y)
                    ve[i].y_in = true;
            }
            // 将最小边所在顶点所连接的未在生长树中的边全部放入最小堆中
            for (int i = 0; i < sum; i++) {

                if (ve[i].x == min.x || ve[i].x == min.y) {
                    if (!ve[i].x_in || !ve[i].y_in) {
                        heap.Insert(ve[i]);
                    }
                }

                if (ve[i].y == min.x || ve[i].y == min.y) {
                    if (!ve[i].x_in || !ve[i].y_in) {
                        heap.Insert(ve[i]);
                    }
                }
            }
            if (sum != 0)
                std::cout << min.x << " " << min.y << " " << min.w << std::endl;
        }
        sum_of_edge++;
    }
    return;
}

int main() {
    int x, y, w;
    std::vector<struct Edge> ve;
    while (std::cin >> x >> y >> w) {
        ve.push_back(Edge(x, y, w));
    }
    PrimByMinHeap(ve, 0);
    return 0;
}

/*
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