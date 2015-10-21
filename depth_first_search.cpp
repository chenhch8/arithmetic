#include<iostream>
#include<ctime>
#include<cstdlib>
#include<queue>

void DFS_VIST(int index, int depth, int & count);

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

void DFS(Grapa* Node, int n) {
    srand(unsigned(time(NULL)));
    int count = 0;
    while (count < n) {
        int origin = rand()%n;

        while (!if_whilte(origin)) {
            origin = rand()%n;
        }
        count++; 

        std::cout << "origin = " << origin << std::endl;

        Node[origin]._colour = G;
        Node[origin]._depth = 0;
        Node[origin]._father = 33;
        Next* nextPtr = Node[origin]._next;

        while (nextPtr != NULL && Node[nextPtr->index]._colour != B) {
            DFS_VIST(nextPtr->index, Node[origin]._depth, count);
            Node[nextPtr->index]._colour = B;
            if (nextPtr != NULL && Node[nextPtr->index]._colour == B)
                nextPtr = nextPtr->next;
        }
        Node[origin]._colour = B;
    }
    return;
}

void DFS_VIST(int index, int depth, int & count) {
    count++;
    Node[index]._colour = G;
    Node[index]._depth = depth + 1;
    Next* nextPtr = Node[index]._next;
    while (nextPtr != NULL && Node[nextPtr->index]._colour != B) {
        DFS_VIST(nextPtr->index, Node[index]._depth, count);
        Node[nextPtr->index]._colour = B;
        if (nextPtr != NULL && Node[nextPtr->index]._colour == B)
            nextPtr = nextPtr->next;
    }
    Node[index]._colour = B;
    return;
}

int main() {
    int i, j;
    while (std::cin >> i >> j) {
        Initialzation_Of_AdjacencyList(i, j);
    }
    DFS(Node, 10);
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
