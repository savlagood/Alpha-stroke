#include <string>
#include <regex>
#include <stack>
#include <cmath>


using namespace std;


const double PI = 3.141592653589793238462643383279502884;

namespace fcalc {
    string mul_correct(string str1) {
        int j, kol = 1;
        char a;
        string str2 = regex_replace(str1, regex(" "), "");;

        for (int i = 0; str1[i + 1]; i++) {
            if (
                ((str1[i] == 'x' || str1[i] == 'p' || str1[i] == 'e') && ( toupper(str1[i + 1]) >= 65 && (toupper(str1[i + 1]) <= 90))) ||
                ((str1[i] == 'x' || str1[i] == 'p' || str1[i] == 'e')&& ((str1[i + 1] >= 48) && (str1[i + 1] <=57 ))) ||
                ((str1[i + 1] == 'x' || str1[i + 1] == 'p' || str1[i + 1] == 'e')&& ((str1[i] >= 48) && (str1[i] <= 57))) ||
                (str1[i] == ')' && str1[i + 1]== '(') ||
                ((str1[i] == ')') && ( toupper(str1[i + 1]) >= 65 && (toupper(str1[i + 1]) <= 90))) ||
                (((str1[i] >= 48) && (str1[i] <= 57)) && ( toupper(str1[i + 1]) >= 65 && (toupper(str1[i + 1]) <= 90))) ||
                ((str1[i] == 'x' || str1[i] == 'p' || str1[i] == 'e')&& str1[i + 1] == '(') ||
                ((str1[i + 1] == 'x' || str1[i + 1] == 'p' || str1[i + 1] == 'e') && str1[i] == ')') ||
                (((str1[i] >= 48) && (str1[i] <= 57)) && ( str1[i + 1] == '(')) ||
                (str1[i] == ')' && ((str1[i + 1] >= 48) && (str1[i + 1] <= 57))) ||
                (str1[i - 1] == 'p' && str1[i] == 'i' && str1[i + 1] == '(') ||
                (str1[i - 1] == 'p' && str1[i] == 'i' && ((toupper(str1[i + 1]) >= 65) && (toupper(str1[i + 1]) <= 90)))  ||
                (str1[i - 1] == 'p' && str1[i] == 'i' && ((str1[i + 1] >= 48) && (str1[i + 1] <=57 )))
            ) {
                j = i;
                if (str1[i] != 'p' || str1[i + 1] != 'i') {
                    str1 += ' ';
                    str2 += ' ';

                    while((j + 2) != ((int) str1.size())) {
                        a = str1[j + 1];
                        str2[j + 2] = a;
                        j++;
                    }

                    str2[i + 1] = '*';
                    kol++;
                    str1 = str2;}
            }
        }

        return str2;
    }

    void replace_funcs(string &str) {
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


    bool is_number(char ch) {
        return isdigit(ch) || ch == '.';
    }


    bool is_unary_operator(char ch) {
        return ch == 's' || ch == 'c' || ch == 't' || ch == 'f' ||
               ch == 'l' || ch == 'q';
    }


    bool is_bin_operator(char ch) {
        return ch == '+' || ch == '-' || ch == '*' || ch == '/' ||
               ch == '^';
    }


    bool is_operator(char ch) {
        return is_unary_operator(ch) || is_bin_operator(ch);
    }


    int operator_precedence(char ch) {
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


    double evaluate_unary_operator(char op, double num) {
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


    double evaluate_binary_operator(char op, double num1, double num2) {
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


    double evaluate_rpn(string rpn, double x) {
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


    string convert_to_rpn(string expression) {
//        expression = mul_correct(expression);
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
}
