#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *root;
    struct Node *left;
    struct Node *right;
};

int height(struct Node *node) {
    if(node==NULL) return 0;
    else {
        int lheight = height(node -> left);
        int rheight = height(node -> right);
        
        if(lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}

void printCurrentLevel(struct Node *root, int level) {
    if(root == NULL) return;
    if(level == 1)
        printf("%d ", root->data);
    else if(level>1) {
        printCurrentLevel(root->left, level-1);
        printCurrentLevel(root->right, level-1);
    }
}

void printLevelOrder(struct Node *root) {
    int h = height(root);
    int i;
    for(i=1; i<=h; i++)
        printCurrentLevel(root, i);
}

struct Node *newNode(int key) {
    struct Node *p = (struct Node*)malloc(sizeof(struct Node));
    p->data = key;
    p->left = NULL;
    p->right = NULL;
    return(p);
}

struct Node *insert(struct Node *node, int key) {
    if(node==NULL)
        return newNode(key);
    
    if(key%4==0)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);
    
    return node;
}

int main() {
    int i, j, t, n, arr[1000];
    scanf("%d", &t);
    
    for(j=0; j<t; j++){
        struct Node *root = NULL;
        
        scanf("%d", &n);
        for(i=0; i<n; i++)
            scanf("%d", &arr[i]);
        
        root = insert(root, arr[0]);
        for(i=1; i<n; i++)
            insert(root,arr[i]);
        
        printLevelOrder(root);
        printf("\n");
    }
    
    return 0;
}
