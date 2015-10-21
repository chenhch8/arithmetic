#include<iostream>
#include<queue>
#include<cstring>

void Error(std::string st) {
    std::cout << st << std::endl;
    return;
}

struct s_node;
typedef struct s_node Int;

struct s_node {
    int index;
    Int* Next;
    s_node(int i = -1, Int* pt = NULL): index(i), Next(pt) {}
};

class Node {
 public:
    typedef Node* Grapa;
    int TopNum;
    int InDegree;
    Int* Next;
    Node(): TopNum(-1), InDegree(0), Next(NULL) {}
    ~Node() {}

    void ptTONode(int index) {
        if (Next == NULL)
            Next = new Int(index, NULL);
        else {
           Int* next = Next;  //////////////////
           while (next->Next != NULL)
               next = next->Next;
           next->Next = new Int(index, NULL);
        }
    }

    friend void CountInDegree(Grapa node, int n) {
        int i = 0;
        while (i < n) {
            Int* next = node[i].Next;
            while (next != NULL) {
                node[next->index].InDegree++;
                next = next->Next;
            }
            i++;
        }
        return;
    }

    friend void TopoSort(Grapa node, int n) {
        CountInDegree(node, n);
        std::queue<int> qe;
        int i = 0, count = 0;
        while (i < n) {
            if (!node[i].InDegree)
                qe.push(i);
            i++;
        }
        while (!qe.empty()) {
            Int* next =  node[qe.front()].Next;
            node[qe.front()].TopNum = ++count;
            qe.pop();
            while (next != NULL) {
                if (--node[next->index].InDegree == 0)
                    qe.push(next->index);
                next = next->Next;
            }
        }
        if (count != n)
            Error("Grapa has a cycle");

        Free(node, n);
    }

    friend void Free(Grapa node, int n) {
        //Int* temp, next;  // 此处很有疑惑，在此处声明时会有编译错误，在下面声明时则行！
        for (int i = 0; i < n; i++) {
            Int* next = node[i].Next;
            while (next != NULL) {
                Int* temp = next;
                next = next->Next;
                delete temp;
            }
        }
        return;
    }
};

int main() {
    return 0;
}