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

void deleteTree(Node *root) {
    if (root->right != NULL) {
        deleteTree(root->right);
    }
    if (root->left != NULL) {
        deleteTree(root->left);
    }
    delete root;
}

void preorderTreeTraversal(Node* root) {
    std::cout << root->value << " ";

    if (root->left != NULL) {
        preorderTreeTraversal(root->left);
    }

    if (root->right != NULL) {
        preorderTreeTraversal(root->right);
    }
}

void inorderTreeTraversal(Node* root) {
    if (root->left != NULL) {
        inorderTreeTraversal(root->left);
    }

    std::cout << root->value << " ";

    if (root->right != NULL) {
        inorderTreeTraversal(root->right);
    }
}

void postorderTreeTraversal(Node* root) {
    if (root->left != NULL) {
        postorderTreeTraversal(root->left);
    }

    if (root->right != NULL) {
        postorderTreeTraversal(root->right);
    }

    std::cout << root->value << " ";
}

int main(){
    //TREE EXAMPLE: 8(3(1,6(4,7)),10(,14(13,)))
    std::string str;
    std::getline(std::cin, str);
    
    Node* root = createTree(str);

    preorderTreeTraversal(root);
    std::cout << std::endl;

    inorderTreeTraversal(root);
    std::cout << std::endl;

    postorderTreeTraversal(root);
    std::cout << std::endl;

    deleteTree(root);

    return 0;
}