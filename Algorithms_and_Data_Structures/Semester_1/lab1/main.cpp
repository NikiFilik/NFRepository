#include <iostream>
#include <string>

int main(){
    setlocale(LC_ALL, "Russian");

    std::string str;
    bool isCorrect = true;

    std::cout << "Введите строку из скобок:\n";
    std::cin >> str;

    long long iter = -1;
    char *stack = new char[str.size()];

    for(long long i = 0; i < str.size(); i++){
        if(str[i] == '(' || str[i] == '{' || str[i] == '['){
            iter++;
            stack[iter] = str[i];
        }

        if(str[i] == ')'){
            if(iter > -1){
                if(stack[iter] == '('){
                    iter--;
                }
                else{
                    isCorrect = false;
                }
            }
            else{
                isCorrect = false;
            }
        }

        if(str[i] == '}'){
            if(iter > -1){
                if(stack[iter] == '{'){
                    iter--;
                }
                else{
                    isCorrect = false;
                }
            }
            else{
                isCorrect = false;
            }
        }

        if(str[i] == ']'){
            if(iter > -1){
                if(stack[iter] == '['){
                    iter--;
                }
                else{
                    isCorrect = false;
                }
            }
            else{
                isCorrect = false;
            }
        }
    }

    if (iter != -1) {
        isCorrect = false;
    }

    delete[] stack;

    if(isCorrect){
        std::cout << "Последовательность скобок верна!";
    }
    else{
        std::cout << "Последовательность скобок неверна!";
    }

    return 0;
}