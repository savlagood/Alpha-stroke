#include <iostream>
#include <string>
#include <regex>
#include <stack>
#include <cmath>

using namespace std;


const double PI = 3.141592653589793238462643383279502884;


namespace rpn {
	void replace_funcs(string &str);
	bool is_number(char ch);
	bool is_unary_operator(char ch);
	bool is_bin_operator(char ch);
	bool is_operator(char ch);
	int operator_precedence(char ch);
	double evaluate_unary_operator(char op, double num);
	double evaluate_binary_operator(char op, double num1, double num2);
	double evaluate_rpn(string rpn, double x);
	string convert_to_rpn(string expression);
}


void rpn::replace_funcs(string &str) {
	str = regex_replace(str, regex(" "), "");
	str = regex_replace(str, regex("\\(-"), "(0-");
	str = regex_replace(str, regex("\\(+"), "(");

    str = regex_replace(str, regex("pi"), "p");

	str = regex_replace(str, regex("sin"), "s");
	str = regex_replace(str, regex("cos"), "c");
	str = regex_replace(str, regex("tan"), "t");
    str = regex_replace(str, regex("tg"), "t");
	str = regex_replace(str, regex("ctg"), "f");
	str = regex_replace(str, regex("ln"), "l");
	str = regex_replace(str, regex("sqrt"), "q");
}


bool rpn::is_number(char ch) {
	return isdigit(ch) || ch == '.';
}


bool rpn::is_unary_operator(char ch) {
	return ch == 's' || ch == 'c' || ch == 't' || ch == 'f' ||
		   ch == 'l' || ch == 'q';
}


bool rpn::is_bin_operator(char ch) {
	return ch == '+' || ch == '-' || ch == '*' || ch == '/' ||
		   ch == '^';
}


bool rpn::is_operator(char ch) {
	return is_unary_operator(ch) || is_bin_operator(ch);
}


int rpn::operator_precedence(char ch) {
	if (ch == '+' || ch == '-')
		return 1;
	else if (ch == '*' || ch == '/')
		return 2;
	else if (ch == '^')
		return 3;
	else if (is_unary_operator(ch))
		return 4;
	else
		return 0;
}


double rpn::evaluate_unary_operator(char op, double num) {
	switch (op) {
		case 's':
			return sin(num);
		case 'c':
			return cos(num);
		case 't':
			return tan(num);
		case 'f':
			return 1 / tan(num);
		case 'l':
			return log(num);
		case 'q':
			return sqrt(num);
		default:
			return 0.0;
	}
}


double rpn::evaluate_binary_operator(char op, double num1, double num2) {
	switch (op) {
		case '+':
			return num1 + num2;
		case '-':
			return num1 - num2;
		case '*':
			return num1 * num2;
		case '/':
			return num1 / ((double) num2);
		case '^':
			return pow(num1, num2);
		default:
			return 0.0;
	}
}


double rpn::evaluate_rpn(string rpn, double x) {
	stack<double> num_stack;

	char ch;
	for (size_t i = 0; i < rpn.size(); i++) {
		ch = rpn[i];
		if (ch == 'x')
			num_stack.push(x);
		else if (ch == 'e')
			num_stack.push(exp(1));
		else if (ch == 'p')
			num_stack.push(PI);
		else if (is_number(ch)) {
			string num;
			while (i < rpn.size() && is_number(rpn[i])) {
				num += rpn[i];
				i++;
			}
			num_stack.push(stod(num)); // string to double

		} else if (is_operator(ch)) {
			if (is_unary_operator(ch)) {
				double num = num_stack.top();
				num_stack.pop();
				num_stack.push(evaluate_unary_operator(ch, num));
				// cout << num << " " << ch << "\n";

			} else {
				double num1 = num_stack.top();
				num_stack.pop();
				double num2 = num_stack.top();
				num_stack.pop();
				// cout << num1 << " " << num2 << " " << ch << "\n";

				num_stack.push(evaluate_binary_operator(ch, num2, num1));
			}
		}
	}

	return num_stack.top();
}


string rpn::convert_to_rpn(string expression) {
    replace_funcs(expression);

	if (expression.size() == 0)
		return expression;
	if (expression[0] == '-')
		expression = "0" + expression;

	stack<char> op_stack;
	stringstream result;

	char ch;
	for (size_t i = 0; i < expression.size(); i++) {
		ch = expression[i];
		if (is_number(ch) || ch == 'x' || ch == 'e' || ch == 'p') {
			result << ch;
		} else if (is_operator(ch)) {
			result << ' ';
			while (!op_stack.empty() && op_stack.top() != '(' &&
					operator_precedence(ch) <= operator_precedence(op_stack.top())) {
				result << op_stack.top() << ' ';
				op_stack.pop();
			}
			op_stack.push(ch);
		} else if (ch == '(') {
			op_stack.push(ch);
		} else if (ch == ')') {
			while (!op_stack.empty() && op_stack.top() != '(') {
				result << ' ' << op_stack.top() << ' ';
				op_stack.pop();
			}

			if (!op_stack.empty() && op_stack.top() == '(')
				op_stack.pop();
		}
	}

	while (!op_stack.empty()) {
		result << ' '<< op_stack.top() << ' ';
		op_stack.pop();
	}

	return result.str();
}


// int main() {
// 	string func;
// 	cout << "Function: ";
// 	getline(cin, func);

// 	replace_funcs(func);

// 	cout << func << "\n";
// 	func = convert_to_rpn(func);
// 	cout << func << "\n";

// 	double x;
// 	cout << "Enter value of x: ";
// 	cin >> x;
// 	cout << "f(" << x << ") = " << evaluate_rpn(func, x) << "\n";

// 	return 0;
// }
