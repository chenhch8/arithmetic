#include<iostream>
#include<ctime>
#include<cstdlib>
#include<queue>

enum Colour {W, G, B};

struct Next {
    int index;
    Next* next;
};

struct Grapa{
    Colour _colour;
    int _father;
    int _depth;
    Next* _next;
    Grapa(): _colour(W), _father(-1), _depth(INT_MAX), _next(NULL) {}
} Node[10];

void Initialzation_Of_AdjacencyList(int first, int second) {
    if (Node[first]._next == NULL) {
    	Node[first]._next = new Next;
    	Node[first]._next->index = second;
    	Node[first]._next->next = NULL;
    	return;
    }
    Next* ptr = Node[first]._next;
    while (ptr->next != NULL)   // 此处注意是ptr->next,而不能是ptr(真是笨啊你！！)
        ptr = ptr->next;
    ptr->next = new Next;
    ptr->next->index = second;
    ptr->next->next = NULL;
    return;
}

bool if_whilte(int index) {
    return Node[index]._colour == W;
}

void BFS(Grapa* Node, int n) {
    srand(unsigned(time(NULL)));
    std::queue<int> que;
    int origin = rand()%n;

    while (!if_whilte(origin)) {origin = rand()%n;}

    std::cout << "origin = " << origin << std::endl;

    Node[origin]._colour = G;
    Node[origin]._depth = 0;
    Node[origin]._father = 33;
    que.push(origin);

    while (!que.empty()) {
        int i = que.front();
        que.pop();
        Next* nextPtr = Node[i]._next;                                  // Node[nextPtr->index]._colour != B
        while (nextPtr != NULL && Node[nextPtr->index]._colour != B) {  // 需要有，防止因有回路导致死循环！！
            Node[nextPtr->index]._colour = G;
            Node[nextPtr->index]._depth = Node[i]._depth + 1;
            Node[nextPtr->index]._father = i;
            que.push(nextPtr->index);
            nextPtr = nextPtr->next;
        }
        Node[i]._colour = B;
    }

    return;
}

int main() {
    int i, j;
    while (std::cin >> i >> j) {
        Initialzation_Of_AdjacencyList(i, j);
    }
    BFS(Node, 10);
    for (int i = 0; i < 10; i++) {
        std::cout << "Node[" << i <<"]._colour = " << Node[i]._colour
        << "\nNode[" << i <<"]._father = " << Node[i]._father << "\nNode[" << i <<"]._next:"
        << i << " -> ";
        Next* ne = Node[i]._next;
        while (ne != NULL) {
            std::cout << ne->index;
            ne = ne->next;
            if (ne != NULL)
                std::cout << " -> ";
        }
        std::cout << "\n" << std::endl;
    }
    for (int i = 0; i < 10; i++) {
        Next* ne = Node[i]._next;
        while (ne != NULL) {
            Next* temp = ne;
            ne = ne->next;
            delete temp;
        }
    }
    return 0;
}


/*
0 1
0 2
0 6
1 4
2 3
3 5
3 9
3 8
4 5
4 7
5 9
6 2
7 6
8 7
a
*/
