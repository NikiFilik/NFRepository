#include <iostream>
#include <string>
#include <vector>

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

void deleteTree(Node *root) {
    if (root->right != NULL) {
        deleteTree(root->right);
    }
    if (root->left != NULL) {
        deleteTree(root->left);
    }
    delete root;
}

void iterativePreorderTreeTraversal(Node* root) {
    if (root == NULL) {
        return;
    }

    std::vector<Node*> stack;
    stack.push_back(root);

    while (!stack.empty()) {
        Node* node = stack.back();
        stack.pop_back();
        std::cout << node->value << " ";

        if (node->right != NULL) {
            stack.push_back(node->right);
        }
        if (node->left != NULL) {
            stack.push_back(node->left);
        }
    }
}

int main(){
    //TREE EXAMPLE: 8(3(1,6(4,7)),10(,14(13,)))
    std::string str;
    std::getline(std::cin, str);
    
    Node* root = createTree(str);

    iterativePreorderTreeTraversal(root);

    deleteTree(root);

    return 0;
}