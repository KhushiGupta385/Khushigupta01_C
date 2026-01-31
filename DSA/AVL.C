#include<stdio.h>
#include<stdlib.h>
struct Node {
    int key;
    struct Node* left;
    struct Node* right;
    int height;
};

/*koi node NULL ho toh height 0
else us node ki stored height return karo */

int height(struct Node* node) {
    if (node == NULL)
    return 0;
    return node->height;
}

int max(int a, int b) {
    return (a>b) ? a:b;
}

struct Node* createNode(int key) {
struct Node* node = (struct Node*)malloc(sizeof(struct Node));

    node->key = key;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

/*jab left-heavy imbalance ho (LL case)
Tree l=ko right rotate karta hai.*/
struct Node* rightRotate(struct Node* y) {
    struct Node* x = y->left;
    struct Node* T2 = x->right;

    x->right = y;
    y->left = T2;

  y->height = max(height(y->left),height(y->right))+1;
  x->height = max(height(x->left),height(x->right))+1;
  return x;
}

/*jab right-heavy imbalance ho (RR case)
Tree ko left rotate karta hai.*/
struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T2 = y->left;

    y->left = x;
    x->right = T2;

  x->height = max(height(x->left),height(x->right))+1;
  y->height = max(height(y->left),height(y->right))+1;
  return y;
}

int getBalance(struct Node* node) {
    if(node == NULL)
    return 0;
    return height(node->left) - height(node->right);
}

struct Node* insert(struct Node* node, int key) {
    if(node == NULL)
    return createNode(key);

    if(key < node->key)
     node->left = insert(node->left,key);
    else if(key > node-> key)
     node->right = insert(node->right,key);
    else
     return node;

    node->height = 1 + max(height(node->left),height(node->right));
     int balance = getBalance(node) ;

    if (balance > 1 && key < node->left->key)
       return rightRotate(node);
    if (balance > 1 && key < node->right->key)
       return leftRotate(node);
    if (balance > 1 && key < node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance > 1 && key < node->right->key) {
        node->right= rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

void inorder(struct Node* root) {
    if (root !=NULL) {
        inorder(root->left);
        printf("%d ",root->key);
        inorder(root->right);
    }
}

int main() {
    struct Node* root =NULL;

    int keys[] = {10,20,30,40,50,25};
    int n = sizeof(keys) / sizeof(keys[0]);

    for(int i=0;i<n;i++)
    root = insert(root, keys[i]);

    printf("Inorder traversal of the constructed AVL tree:\n");
    inorder(root);
    printf("\n");
    return 0;
}

/* If imabalance detect ho:
LL Case -> Right Rotate
RR Case -> left Rotate
LR Case -> left Rotate child, then Right Rotate parent
RL Case -> Right Rotate child, then Left Rotate Parent */