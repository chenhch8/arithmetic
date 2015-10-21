#include<iostream>
#include<deque>
#include<cmath>

int Max = -1000;
int Min = 1000;

void radix_sport(std::deque<int> & Deque, unsigned int digits) {
    std::deque<int> de[10];
    for (unsigned i = 0; i < digits; i++) {
	std::deque<int>::iterator it = Deque.begin();
	while (it != Deque.end()) {
	    int n = (int)(*it / pow(10, i)) % 10;  // 若直接写在de[..]内则会错误，为什么？
	    de[n].push_back(*(it++));
	}
	Deque.clear();
	for (int j = 0; j < 10; j++)
	    if (!de[j].empty()) {
		std::deque<int>::iterator pt = de[j].begin();
		while (pt != de[j].end())
		    Deque.push_back(*(pt++));
		de[j].clear();
	    }
    }
    return;
}

unsigned findDigit(int num) {
    unsigned digit = 1;
    while (num / 10) {
	digit++;
	num /= 10;
    }
    return digit;
}

int main() {
    std::cout << "请输入数据：";
    std::deque<int> Deque;
    int n;
    while (std::cin >> n) {
	if (n > Max) Max = n;
	if (n < Min) Min = n;
	Deque.push_back(n);
    }
    if (Min < 0) {
	unsigned len = Deque.size();
	while (len--) {
	    Deque.push_back(Deque.front() - Min);
	    Deque.pop_front();
	}
    } else {Min = 0;}
    radix_sport(Deque, findDigit(Max - Min));
    for (std::deque<int>::iterator it = Deque.begin(); it != Deque.end(); it++)
  	std::cout << (Min < 0 ? Min : 0) + *it << " ";
    std::cout << std::endl;
    return 0;
}
