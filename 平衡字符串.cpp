#include<iostream>
#include<stack>
#include<cstring>

bool check_symbol_balance(std::string symbol) {
    std::stack<char> Stack;
    if (symbol.empty()) return true;
    for (unsigned i = 0; i < symbol.length(); i++) {
	if (symbol[i] == '[' || symbol[i] == '(' || symbol[i] == '{')
	    Stack.push(symbol[i]);
	else
	    switch (symbol[i]) {
		case ']':
		    if (Stack.top() != '[') return false;
		    else Stack.pop();
		break;
		case ')':
		    if (Stack.top() != '(') return false;
		    else Stack.pop();
		break;
 		case '}':
		    if (Stack.top() != '{') return false;
		    else Stack.pop();
		break;
	    }
    }
    return true;
}

int main() {
    std::string str;
    std::cout << "ÇëÊäÈëÆ½ºâÀ¨ºÅ£º";
    std::cin >> str;
    std::cout << (check_symbol_balance(str) == true ? "Yes" : "No") << std::endl;
    return 0;
}
