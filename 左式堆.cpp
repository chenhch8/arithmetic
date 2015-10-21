#include<iostream>

template<class ElementType>
class TreeNode {
 public:
    typedef TreeNode<ElementType> * PriorityQueue;
    TreeNode(): Left(NULL), Right(NULL), Npl(0){}
    ~TreeNode() {}  // 此处有问题，内存可能泄露，回头再想

    template<class T>
    friend PriorityQueue Mergett(TreeNode<T> * H1, TreeNode<T> * H2);

    template<class T>
    friend PriorityQueue Insert(TreeNode<T> * X, TreeNode<T> * H);

    ElementType FindMin(PriorityQueue H);

    template<class T>
    friend PriorityQueue DeleteMin(TreeNode<T> * H);

    ElementType & element() {return Element;}
    int npl() {return Npl;}
    bool IsEmpty();
    void Swap();
 private:
    ElementType Element;
    PriorityQueue Left, Right;
    int Npl;
};

template<class T>
TreeNode<T> * Mergett(TreeNode<T> * H1, TreeNode<T> * H2) {
    if (H1 == NULL) {
        return H2;
    } else {
        TreeNode<T> * pt1, pt2;
        if (H1->Element < H2->Element) {
            pt1 = H1; pt2 = H2;
        } else {
            pt1 = H2; pt2 = H1;
        }
        if (pt1->Left == NULL) {
            pt1->Left = pt2;
            pt1->Npl = 0;
        } else {
            pt1->Right = Merge(pt1->Right, pt2);
            if (pt1->Left->Npl < pt1->Right->Npl)
                pt1.Swap();
            pt1->Npl = pt1->Right->Npl + 1;
        }
        return pt1;
    }
}

template<class T>
TreeNode<T> * Insert(T X, TreeNode<T> * H) {
    TreeNode<T> * pt = new TreeNode<T>();
    if (pt == NULL) {
        std::cout << "Out of space." << std::endl;
        return NULL;
    }
    pt->element() = X;
    return Mergett(H, pt);
}

template<class T>
TreeNode<T> * DeleteMin(TreeNode<T> * H) {
    if (!H.IsEmpty()) {
        TreeNode<T> * H1 = H->Left, H2 = H->Right;
        delete H;
        return Merge(H1, H2);
    }
}

template<class ElementType>
bool TreeNode<ElementType>::IsEmpty() {
    return this==NULL;
}

template<class ElementType>
void TreeNode<ElementType>::Swap() {
    PriorityQueue pt = Left;
    Left = Right;
    Right = pt;
    return;
}

int main() {
    TreeNode<int> H1, H2;
    int n;
    while (std::cin >> n)
        Insert(n, &H1);
    while (!H1.IsEmpty())
        std::cout << H1.element() << " ";
    return 0;
}