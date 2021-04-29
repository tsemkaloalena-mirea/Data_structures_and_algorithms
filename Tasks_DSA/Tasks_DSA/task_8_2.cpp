#include <iostream>
#include <queue>
#include "task_8_2_list.h"
using namespace std;

void pop(listStack <char>* St, queue <char>* Q) {
	while (!(*St).empty()) {
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
	listStack <char> St;
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

int main() {
	string expression_infix = "a+(b-c*k)-d*e-f";
	cout << "infix notation of expression: " << expression_infix << endl;
	string expression_prefix;
	expression_prefix = infix_to_prefix(expression_infix);
	cout << "prefix notation of expression: " << expression_prefix << endl;
	return 0;
}