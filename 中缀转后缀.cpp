#include<cstring>
#include<iostream>
#include<stack>

// �����������Ƿ�ִ�еĹؼ����������ȼ��Ƿ���ڻ�������ұߵ�һ��������
// stack.top()�ڵ�stackΪ��ʱ�ᷢ������
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
    std::cout << "��������ʽ���ʽ ��";
    std::cin >> st;
    std::cout << calculateFromString(st) << std::endl;
    return 0;
}