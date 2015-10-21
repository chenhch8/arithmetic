#include<cstring>
#include<iostream>
#include<stack>

// 决定操作符是否执行的关键在与其优先级是否高于或等于它右边第一个操作符
// stack.top()在当stack为空时会发生错误
std::string calculateFromString(std::string formula) {
    std::string st = "";
    std::stack<char> Stack;
    for (unsigned i = 0; i < formula.length(); i++) {
	if (formula[i] >= 'a' && formula[i] <= 'z') {
	    st += formula[i];
	} else {
	    if (formula[i] == ')') {
		if (!Stack.empty())
		while (Stack.top() != '(') {
	            st += Stack.top();
	            Stack.pop();
		    if (!Stack.empty()) {
			if (Stack.top() == '(') {Stack.pop(); break;}
		    } else break;
		}
	    } else if (formula[i] == '(') {
		Stack.push(formula[i]);
	    } else {
		if (formula[i] == '*' || formula[i] == '/') {
		    if (Stack.empty()) {
			Stack.push(formula[i]);
		    } else {
			if (Stack.top() == '+' || Stack.top() == '-' || Stack.top() == '(')
			    Stack.push(formula[i]);
			else {
			    while (Stack.top() != '(') {
			        st += Stack.top();
				Stack.pop();
				if (Stack.empty() || Stack.top() == '+' || Stack.top() == '-') break;
			    }
		 	    Stack.push(formula[i]);
			}
		    }
		} else {
		    //std::cout << Stack.top() << std::endl;
		    if (!Stack.empty())
		    while (Stack.top() != '(') {
			st += Stack.top();
	                Stack.pop();
			if (Stack.empty()) break;
		    }
		    Stack.push(formula[i]);
		}
	    }
	}
    }
    while (!Stack.empty()) {
 	st += Stack.top();
	Stack.pop();
    }
    return st;
}

int main() {
    std::string st;
    std::cout << "请输入算式表达式 ：";
    std::cin >> st;
    std::cout << calculateFromString(st) << std::endl;
    return 0;
}