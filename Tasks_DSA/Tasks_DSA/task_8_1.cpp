#include <iostream>
#include <queue>
#include <stack>
#include <string>
using namespace std;

void pop(stack <char>* St, queue <char>* Q) {
	for (int i = 0; i < (*St).size(); i++) {
		if ((*St).top() == '(') {
			(*St).pop();
			break;
		}
		(*Q).push((*St).top());
		(*St).pop();
	}
}

string reverse_expression(string expression) {
	string new_expression = "";
	for (int i = expression.size() - 1; i >= 0; i--) {
		if (expression[i] == '(') {
			new_expression += ')';
		}
		else if (expression[i] == ')') {
			new_expression += '(';
		}
		else {
			new_expression += expression[i];
		}
	}
	return new_expression;
}

string infix_to_postfix(string expression) {
	stack <char> St;
	queue <char> Q;
	for (int i = 0; i < expression.size(); i++) {
		if (expression[i] == '(') {
			St.push(expression[i]);
		}
		else if (expression[i] == ')') {
			pop(&St, &Q);
		}
		else if (expression[i] == '+' || expression[i] == '-') {
			if (St.empty() || St.top() == '(') {
				St.push(expression[i]);
			}
			else if (St.top() == '*' || St.top() == '/') {
				pop(&St, &Q);
				St.push(expression[i]);
			}
			else {
				Q.push(St.top());
				St.pop();
				St.push(expression[i]);
			}
		}
		else if (expression[i] == '*' || expression[i] == '/') {
			if (!St.empty() && (St.top() == '*' || St.top() == '/')) {
				pop(&St, &Q);
			}
			St.push(expression[i]);
		}
		else {
			Q.push(expression[i]);
		}
	}
	while (!St.empty()) {
		if (St.top() != '(') {
			Q.push(St.top());
		}
		St.pop();
	}
	string new_expression = "";
	while (!Q.empty()) {
		new_expression += Q.front();
		Q.pop();
	}
	return new_expression;
}

string infix_to_prefix(string expression) {
	expression = reverse_expression(expression);
	expression = infix_to_postfix(expression);
	expression = reverse_expression(expression);
	return expression;
}

int calculate_postfix(string expression) {
	stack <int> St;
	for (int i = 0; i < expression.size(); i++) {
		if (expression[i] == '+') {
			int a = St.top();
			St.pop();
			a += St.top();
			St.pop();
			St.push(a);
		}
		else if (expression[i] == '*') {
			int a = St.top();
			St.pop();
			a *= St.top();
			St.pop();
			St.push(a);
		}
		else if (expression[i] == '/') {
			int a = St.top();
			St.pop();
			a = St.top() / a;
			St.pop();
			St.push(a);
		}
		else if (expression[i] == '-') {
			int a = St.top();
			St.pop();
			a = St.top() - a;
			St.pop();
			St.push(a);
		}
		else {
			//sscanf(expression[i], &a);
			int a = static_cast<int>(expression[i]) - '0';
			St.push(a);
		}
	}
	return St.top();
}

int calculate_prefix(string expression) {
	stack <int> St;
	for (int i = expression.size() - 1; i >= 0; i--) {
		if (expression[i] == '+') {
			int a = St.top();
			St.pop();
			a += St.top();
			St.pop();
			St.push(a);
		}
		else if (expression[i] == '*') {
			int a = St.top();
			St.pop();
			a *= St.top();
			St.pop();
			St.push(a);
		}
		else if (expression[i] == '/') {
			int a = St.top();
			St.pop();
			a /= St.top();
			St.pop();
			St.push(a);
		}
		else if (expression[i] == '-') {
			int a = St.top();
			St.pop();
			a -= St.top();
			St.pop();
			St.push(a);
		}
		else {
			St.push(static_cast<int>(expression[i]) - '0');
		}
	}
	return St.top();
}

int main() {
	string expression_infix = "a+(b-c*k)-d*e-f";
	string expression_postfix;
	string expression_prefix;
	expression_postfix = infix_to_postfix(expression_infix);
	//expression_prefix = infix_to_prefix(expression_infix);
	cout << expression_postfix << endl;
	//cout << expression_prefix << endl;
	//cout << calculate_postfix(expression_postfix) << endl;
	//cout << calculate_prefix(expression_prefix);
	return 0;
}
