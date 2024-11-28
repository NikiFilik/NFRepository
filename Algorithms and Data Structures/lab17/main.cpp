#include <iostream>
#include <string>

class Node {
public:
    int value;
    Node *right = NULL, *left = NULL;
};

Node* createTree(std::string str) {
    int valueIndex = -1, leftIndex = -1;
    
    int openBracketCounter = 0, closeBracketCounter = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(') {
            openBracketCounter++;
        }
        if (str[i] == ')') {
            closeBracketCounter++;
        }

        if ((str[i] < '0' || str[i] > '9') && valueIndex == -1) {
            valueIndex = i;
        }
        if (str[i] == ',' && openBracketCounter - closeBracketCounter == 1 && leftIndex == -1) {
            leftIndex = i;
            break;
        }
    }
    if (valueIndex == -1) {
        valueIndex = str.size();
    }
    
    std::string valueStr, leftStr, rightStr;

    for (int i = 0; i < valueIndex; i++) {
        valueStr += str[i];
    }
    for (int i = valueIndex + 1; i < leftIndex; i++) {
        leftStr += str[i];
    }
    if (leftIndex != -1) {
        for (int i = leftIndex + 1; i < str.size() - 1; i++) {
            rightStr += str[i];
        }
    }
    /*
    std::cout << "INPUT: " << str << std::endl;
    std::cout << "VALUE: "<< valueStr << std::endl;
    std::cout << "LEFT SUBTREE: " << leftStr << std::endl;
    std::cout << "RIGHT SUBTREE: " << rightStr << std::endl << std::endl << std::endl;
    */
    Node* root = new Node;

    root->value = std::stoi(valueStr);
    if (leftStr != "") {
        root->left = createTree(leftStr);
    }
    if (rightStr != "") {
        root->right = createTree(rightStr);
    }

    return root;
}

void deleteTree(Node* root) {
    if (root->right != NULL) {
        deleteTree(root->right);
    }
    if (root->left != NULL) {
        deleteTree(root->left);
    }
    delete root;
}

Node* findElement(Node* root, int value) {
    if (root->value == value) {
        return root;
    }
    if (root->left != NULL && value < root->value) {
        return findElement(root->left, value);
    }
    if (root->right != NULL && value > root->value) {
        return findElement(root->right, value);
    }
    return NULL;
}

void printTree(Node* root) {
    std::cout << root->value;

    if (root->left != NULL || root->right != NULL) {
        std::cout << '(';
        if (root->left != NULL) {
            printTree(root->left);
        }
        std::cout << ',';
        if (root->right != NULL) {
            printTree(root->right);
        }
        std::cout << ')';
    }
}

int main(){
    //TREE EXAMPLE: 8(3(1,6(4,7)),10(,14(13,)))
    std::string str;
    std::getline(std::cin, str);
    
    Node* root = createTree(str);

    while (true) {
        int chosenOperation = -1;
        std::cout << "\nChoose next operation. \n1 - Add new element to tree. \n2 - Delete element from tree. \n3 - Find element in tree. \n9 - Exit. \n";
        std::cin >> chosenOperation;

        if (chosenOperation == 1) {

        }

        else if (chosenOperation == 2) {

        }

        else if (chosenOperation == 3) {
            std::cout << "Enter the element you want to find: ";

            int element;
            std::cin >> element;

            if (findElement(root, element) != NULL) {
                std::cout << "Element found!\n";
            }
            else {
                std::cout << "There is no such element in the tree!\n";
            }
        }

        else if (chosenOperation == 9) {
            break;
        }

        else {
            std::cout << "Error" << std::endl;
        }
    }

    std::cout << "\nFinal tree:\n";
    printTree(root);

    deleteTree(root);

    return 0;
}