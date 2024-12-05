#include <stdio.h>
#include <stdlib.h>

//TODO All attribute of Node on Tree
typedef struct Node {
    char data;
    struct Node* left;
    struct Node* right;
} Node;

//TODO Add element on Tree
Node* create_node(char data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

//TODO Initialize Tree
Node* create_root(char data) {
    Node* root = create_node(data);
    return root;
}

//TODO Check the Tree is Empty or not
int is_empty(Node* root) {
    return root == NULL;
}

//TODO In-order DFS: Left, Root, Right
void inOrder(Node* node) {
    if(node == NULL) return;
    inOrder(node->left);
    printf("%c ", node->data);
    inOrder(node->right);
}

//TODO Pre-order DFS: Root, Left, Right
void preOrder(Node* node) {
    if(node == NULL) return;
    printf("%c ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}

//TODO Post-order DFS: Left, Right, Root
void postOrder(Node* node) {
    if(node == NULL) return;
    postOrder(node->left);
    postOrder(node->right);
    printf("%c ", node->data);
}

//* Driver code
int main() {

    //* Create Root of Tree
    Node* root = create_root('+');

    //* Left Tree
    root->left = create_node('-');
    root->left->left = create_node('*');
    root->left->left->left = create_node('a');
    root->left->left->right = create_node('5');
    root->left->right = create_node('*');
    root->left->right->left = create_node('b');
    root->left->right->right = create_node('/');
    root->left->right->right->left = create_node('^');
    root->left->right->right->left->left = create_node('c');
    root->left->right->right->left->right = create_node('6');
    root->left->right->right->right = create_node('d');

    //* Right Tree
    root->right = create_node('*');
    root->right->left = create_node('-');
    root->right->left->left = create_node('h');
    root->right->left->right = create_node('f');
    root->right->right = create_node('^');
    root->right->right->left = create_node('e'); 
    root->right->right->right = create_node('/');
    root->right->right->right->left = create_node('1');
    root->right->right->right->right = create_node('2');

    //* Print all elements on Tree by three algorithms
    postOrder(root);
    printf("\n");

    inOrder(root);
    printf("\n");

    preOrder(root);
    printf("\n");
    return 0;
}