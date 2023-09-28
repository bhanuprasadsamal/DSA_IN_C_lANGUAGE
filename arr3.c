// Date-26-09-2023
// 
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* newNode(int value);

struct Node* insert(struct Node *root, int value);

struct Node* search(struct Node* root, int value);

void inorderTraversal(struct Node *root);

void postorderTraversal(struct Node *root);

void preorderTraversal(struct Node *root);

struct Node* delete(struct Node *root, int value);

struct Node* findMin(struct Node* node);

int main(){
    struct Node *root = NULL;
    root = insert(root , 50);
    insert(root , 30);
    insert(root , 20);
    insert(root , 40);
    insert(root , 70);
    insert(root , 60);
    insert(root , 80);

    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");
    printf("postorder Traversal: ");
    postorderTraversal(root);
    printf("\n");
    printf("preorder Traversal: ");
    preorderTraversal(root);

    printf("\n");
    int valueToDelete =30;
    root = delete(root , valueToDelete);
    printf("Inorder traversal after deletion of %d: ",valueToDelete);
    inorderTraversal(root);
    printf("\n");
    
    int valueToSearch = 60;
    struct Node* foundNode = search(root, valueToSearch);
    if(foundNode){
        printf("%d was found in BST. \n",valueToSearch);

    } else{
        printf("%d was not found in BST. \n",valueToSearch);
    }
    return 0;
}

struct Node* newNode(int value){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* insert(struct Node *root, int value){
    if(root == NULL){
        return newNode(value);
    }

    if (value < root->data){
        root->left = insert(root->left, value);

    }else if (value > root->data)
    {
        root->right = insert(root->right,value);
    }
    return root;
}

struct Node* search(struct Node* root, int value){
    if (root== NULL || root->data == value){
        return root;
    }
    if (value < root->data){
        return search(root->left, value);
    }
    return search(root->right,value);
}

void inorderTraversal(struct Node *root){
    if(root != NULL){
       inorderTraversal(root->left);
       printf("%d ", root->data);
       inorderTraversal(root->right); 
    }
}

void postorderTraversal(struct Node *root){
    if(root != NULL){
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}
void preorderTraversal(struct Node *root){
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

struct Node* delete(struct Node *root,int value){
    if(root ==NULL){
        return root;
    }

    if(value < root->data){
        root->left= delete(root->left,value);

    }else if(value > root->data ){
        root->right = delete(root->right,value);
    }else
    {
        if(root->left == NULL){
            struct Node* temp = root->right;
            free(root);
            return temp;

        }else if(root->right == NULL)
        {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);

    }
    return root; // Added return statement
}

struct Node* findMin(struct Node* node)
{
    while(node->left != NULL)
    {
        node = node->left;
    }
    return node;
}
