#ifndef FUNC_CALCULUS_H
#define FUNC_CALCULUS_H

#include <string>


using namespace std;

namespace fcalc {
    string mul_correct(string str1);
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


#endif // FUNC_CALCULUS_H
