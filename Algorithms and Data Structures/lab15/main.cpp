#include <iostream>
#include <string>

class Node {
public:
    int value;
    Node *right = NULL, *left = NULL;
};

Node* createTree(std::string str) {

}

void deleteTree(Node *node) {
    if (node->right != NULL) {
        deleteTree(node->right);
    }
    if (node->left != NULL) {
        deleteTree(node->left);
    }
    delete node;
}



int main(){
    std::string str;
    std::getline(std::cin, str);
    
    Node* root = createTree(str);

    deleteTree(root);

    return 0;
}