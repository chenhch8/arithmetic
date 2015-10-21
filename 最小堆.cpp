#include<iostream>
#include<cstring>

const unsigned MinCapacity = 16;

void Error(std::string str) {
    std::cout << str << std::endl;
    return;
}

template<class ElementType>
class PriorityQueue {
 private:
    int capacity;
    int size;
    ElementType * element;
 public:
    typedef PriorityQueue<ElementType> * ptrToQueueh;
    typedef ElementType * ptrToElement;

    PriorityQueue(): capacity(0), size(0), element(NULL) {}
    ~PriorityQueue() {
	if (element != NULL)
	    delete []element;
    }
    void creatQueue(unsigned _capacity = MinCapacity);
    void Insert(ElementType E);
    ElementType DeleteMin();
    void MakeEmpty() {size = 0;}
    int Size() {return size;}
    int Capacity() {return capacity;}
    ptrToElement Element() {return element;}
    friend bool IsEmpty(ptrToQueueh H) {return H->size == 0;}
    friend bool IsFull(ptrToQueueh H) {return H->size == H->capacity;}
};

template<class ElementType>
void PriorityQueue<ElementType>::Insert(ElementType E) {
    if (IsFull(this)) {
	Error("Priority queue is full.");
	return;
    }
//std::cout << "here 2." << std::endl;/////////////////////////////////
    int i;
    for (i = this->size++; i > 0 && this->element[(int)((i-1)/2)] > E; i = (i - 1) / 2)// 注意数组下标不能越界，否则运行失败
	    this->element[i] = this->element[(int)((i-1)/2)];
    //std::cout << this->size << std::endl; 
    this->element[i] = E;
    return;
}

template<class ElementType>
void PriorityQueue<ElementType>::creatQueue(unsigned _capacity) {
    	if (_capacity < MinCapacity) {
	    Error("Priority queue is too small.");
	    return;
    	} else {
	    this->element = new ElementType[_capacity];
	    if (this->element == NULL) {
	        Error("Out of space.");
	  	return;
	    }
	    this->capacity = _capacity;
	    this->size = 0;
	    return;
   	}
}

template<class ElementType>
ElementType PriorityQueue<ElementType>::DeleteMin() {
//std::cout << "here 3." << std::endl;///////////////////
    ElementType tp = this->element[0], child, last = this->element[--this->size];
    int i;
    for (i = 0; i * 2 + 1 < this->size; i = child) { //  i * 2 + 1 < this->size判断有无左子树 
 	child = i * 2 + 1;
	if (child != this->size - 1 && this->element[child] > this->element[child + 1])
	    child++;  // child != this->size - 1 判断有无右子树 
  	if (this->element[child] < last)
 	    this->element[i] = this->element[child];
	else break;
    }
    this->element[i] = last;
    return tp;
}

int main() {
    PriorityQueue<int> pt;
    pt.creatQueue();
    int n;
    while (std::cin >> n) {
        pt.Insert(n);
    }
//std::cout << "here 1." << std::endl;
    while (pt.Size() != 0)
        std::cout << pt.DeleteMin() << " ";
    std::cout << std::endl;
    getchar();
    return 0;
}
