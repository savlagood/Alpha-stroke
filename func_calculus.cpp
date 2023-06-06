#include <string>
#include <stack>
#include <cmath>
#include <vector>
#include <sstream>


using namespace std;


const double PI = 3.141592653589793238462643383279502884;

namespace fcalc {
    string replace_all(string str, const string& from, const string& to) {
        if(from.empty())
            return str;

        size_t start_pos = 0;
        while((start_pos = str.find(from, start_pos)) != std::string::npos) {
            str.replace(start_pos, from.length(), to);
            start_pos += to.length();
        }

        return str;
    }


    void replace_funcs(string &str) {
        str = replace_all(str, " ", "");
        str = replace_all(str, "(-", "(0-");
        str = replace_all(str, "(+", "(");

        str = replace_all(str, "pi", "p");

        str = replace_all(str, "sin", "s");
        str = replace_all(str, "cos", "c");
        str = replace_all(str, "tan", "t");
        str = replace_all(str, "tg", "t");
        str = replace_all(str, "ctg", "f");
        str = replace_all(str, "ln", "l");
        str = replace_all(str, "sqrt", "q");
    }


    string mul_correct(string str1) {
        int j, kol = 1;
        char a;

        string str2 = replace_all(str1, " ", "");

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

    long unsigned int next_char(string s)
    // Данная функция ищет номер первого вхождения одного
    // из знаков + - * / в строке.
    // Если ни один из этих символов не встречается,
    // например, в строке sinx, то функция возвращает
    // длину всей строки.
    {
        long unsigned int min = size(s);
        if (min > s.find("+", 0))
            min = s.find("+", 0);

        if (min > s.find("*", 0))
            min = s.find("*", 0);

        if (min > s.find("-", 0))
            min = s.find("-", 0);

        if (min > s.find("/", 0))
            min = s.find("/", 0);

        return min;
    }


    string insert_brackets(string s)
    // Данная функция вставляет скобки, но только в строку,
    // не содержащую знаков арифметических операций.
    // Например:
    // sin15tan6ln23x --> sin(15(tan(61ln(23x))))
    // но
    // sinx+cosx --> sin(x+cos(x))
    {
        int i = 0;
        while (s[i] != '\0') {
            if ((s.substr(i, 3) == "sin" || s.substr(i, 3) == "cos"
                || s.substr(i, 3) == "tan" || s.substr(i, 3) == "ctg")
                && !(s.substr(i, 4) == "sin(" || s.substr(i, 4) == "cos("
                || s.substr(i, 4) == "tan(" || s.substr(i, 4) == "ctg(")) {
                s.insert(i + 3, "(");
                s.append(")");
                }

            if (s.substr(i, 2) == "ln" && !(s.substr(i, 3) == "ln(")) {
                s.insert(i + 2, "(");
                s.append(")");
            }

            if (s.substr(i, 4) == "sqrt" && !(s.substr(i, 5) == "sqrt(")) {
                s.insert(i + 4, "(");
                s.append(")");
            }

            i++;
        }

        return s;
    }


    string brackets_correct(string s)
    // как именно оно работает:
    // sinx --> sin(x)
    // sinx+cosx*tanx --> sin(x)+cos(x)*tan(x)
    // sinx+cos15tanlnsqrt12341 --> sin(x)+cos(15tan(ln(sqrt(12341))))
    // sin(x) + cosx --> sin(x) + cos(x)
    {
        string subs, ch, result;


        result = "\0"; //сам результат - вначале равен пустой строке

        while (size(s) > 0) { // если >= поставить,
                              //то возникают некоторые ошибки
            ch = "\0";
            subs = s; // подстрока всей строки s
            ch = s; // знак арифметической операции: + - * /

            subs = subs.erase(next_char(subs));
            // отрезаем слева от всей входной строки
            // часть, идущую до первого знака арифметической операции,
            // т.е. для sinx+cosx+lnx: subs = sinx;
            // для sinx: subs = sinx;
            // см. также функцию next_char

            ch = ch.erase(0, next_char(ch));
            if (ch != "\0")
                ch = ch.erase(next_char(ch) + 1);
            // первый знак арифметической операции
            // sinx+cosx-lnx: ch = +;
            // sinx: ch = "\0";

            if (size(subs) != 0) {
                result = result.append(insert_brackets(subs));
                // обрабатываем подстроку и вставляем в конец result
                result = result.append(ch);
                // аналогично, после обработанной подстроки
                // вставляем знак

                s = s.erase(0, size(subs) + 1); // обрезаем строку
                // например, sinx+cosx-lnx --> cosx-lnx;
            }
            else { // если нет знаков, соответвенно,
                   // незачем разделять на подстроки,
                   // т.е. с помощью функции insert_brackets можно
                   // обработать все сразу
                result = result.append(insert_brackets(s));
                break;
            }
        }

        return result;
    }


    bool is_correct_expression(string str) {
        const vector<string> symbols = {
            "sin", "cos", "ctg", "tg", "ln", "sqrt", ".",
            "+", "-", "*", "/", "^", "pi", "p", "e", "(", ")",
            "x", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9",
        };

        for (size_t i = 0; i < symbols.size(); i++)
            str = replace_all(str, symbols[i], "");

        if (str.size() > 0)
            return false;
        return true;
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
