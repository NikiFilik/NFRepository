#include <iostream>
#include <string>
#include <vector>

bool isBracketsCorrect(std::string str) {
    std::vector<char> stack;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(') {
            stack.push_back(str[i]);
        }

        if (str[i] == ')') {
            if (!stack.empty()) {
                if (stack.back() == '(') {
                    stack.pop_back();
                }
                else {
                    return false;
                }
            }
            else {
                return false;
            }
        }
    }

    if (!stack.empty()) {
        return false;
    }

    return true;
}

int getPriority(char oper) {
    if (oper == '+' || oper == '-') {
        return 1;
    }
    if (oper == '*' || oper == '/') {
        return 2;
    }
    return -1;
}

bool isDigit(char ch) {
    if (ch >= '0' && ch <= '9') {
        return true;
    }
    return false;
}

bool isOperation(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

std::vector<std::string> toReversePolishNotation(std::string expression) {
    std::vector<std::string> output;
    std::vector<char> operators;

    int i = 0;
    while (i < expression.size()) {
        char ch = expression[i];

        if (ch == '-' && (i == 0 || expression[i - 1] == '(')) {
            std::string number;
            number += ch;
            i++;
            while (i < expression.size() && isDigit(expression[i])) {
                number += expression[i];
                i++;
            }
            output.push_back(number);
            continue;
        }

        if (isDigit(ch)) {
            std::string number;
            number += ch;
            while (i + 1 < expression.size() && isDigit(expression[i + 1])) {
                i++;
                number += expression[i];
            }
            output.push_back(number);
        }

        else if (isOperation(ch)) {
            while ((!operators.empty()) && isOperation(operators.back()) && (getPriority(operators.back()) >= getPriority(ch))) {
                std::string oper;
                oper += operators.back();
                output.push_back(oper);
                operators.pop_back();
            }
            operators.push_back(ch);
        }
        else if (ch == '(') {
            operators.push_back(ch);
        }
        else if (ch == ')') {
            while ((!operators.empty()) && (operators.back() != '(')) {
                std::string oper;
                oper += operators.back();
                output.push_back(oper);
                operators.pop_back();
            }
            operators.pop_back();
        }
        i++;
    }

    while (!operators.empty()) {
        std::string oper;
        oper += operators.back();
        output.push_back(oper);
        operators.pop_back();
    }

    return output;
}

bool isNumber(std::string str) {
    if (str[0] == '-' && str.size() >= 2) {
        for (int i = 1; i < str.size(); i++) {
            if (str[i] < '0' || str[i] > '9') {
                return false;
            }
        }
        return true;
    }
    else {
        for (int i = 0; i < str.size(); i++) {
            if (str[i] < '0' || str[i] > '9') {
                return false;
            }
        }
        return true;
    }
}

std::string calculateReversePolishNotation(std::vector<std::string> rpn){
    std::vector<float> stack;

    for (int i = 0; i < rpn.size(); i++) {
        if (isNumber(rpn[i])) {
            stack.push_back(std::stoi(rpn[i]));
        }
        else {
            float b = stack.back();
            stack.pop_back();
            float a = stack.back();
            stack.pop_back();

            if (rpn[i] == "+") {
                stack.push_back(a + b);
            }
            if (rpn[i] == "-") {
                stack.push_back(a - b);
            }
            if (rpn[i] == "*") {
                stack.push_back(a * b);
            }
            if (rpn[i] == "/") {
                if (b != 0) {
                    stack.push_back(a / b);
                }
                else {
                    return "ERROR! Division by 0";
                }
            }
        }
    }

    return std::to_string(stack[0]);
}

std::string deleteSpaces(std::string str) {
    std::string result;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] != ' ') {
            result += str[i];
        }
    }
    return result;
}

int main(){
    std::string str;
    std::cout << "Enter your math expression: ";
    std::getline(std::cin, str);

    std::cout << "Result: ";

    if (!isBracketsCorrect(str)) {
        std::cout << "ERROR! The brackets are in the wrong order";
        return 0;
    }

    str = deleteSpaces(str);
    std::vector<std::string> rpn = toReversePolishNotation(str);
    std::string result = calculateReversePolishNotation(rpn);

    std::cout << result;
    return 0;
}