// Date-26-09-2023
// min - max (tree)
//leaf node
//sum of leaf node

#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* newNode(int value){
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->data = value;
	node->left = NULL;
	node->right = NULL;
	return node;
}

struct Node* insert(struct Node* root, int value){
	if(root == NULL){
		return newNode(value);
	}
	
	if(value < root->data){
		root->left = insert(root->left, value);
	} else if(value > root->data){
		root->right = insert(root->right, value);
	}
	return root;
}

struct Node* search(struct Node* root, int value){
	if(root == NULL || root->data == value){
		return root;
	}
	if (value < root->data){
		return search(root->left, value);
	}
	return search(root->right, value);
}

void inorderTraversal(struct Node* root){
	if (root != NULL){
		inorderTraversal(root->left);
		printf("%d ",root->data);
		inorderTraversal(root->right);
	}
}

void postorderTraversal(struct Node* root){
	if(root != NULL){
		postorderTraversal(root->left);
		postorderTraversal(root->right);
		printf("%d ",root->data);
	}
}

void preorderTraversal(struct Node* root){
	if(root != NULL){
		printf("%d ",root->data);
		preorderTraversal(root->left);
		preorderTraversal(root->right);
	}
}

struct Node* deletion(struct Node* root, int value){
	if(root == NULL){
		return root;
	}
	if(value < root->data){
		root->left = deletion(root->left, value);
	} else if(value > root->data){
		root->right = deletion(root->right, value);
	} else {
		if(root->left == NULL){
			struct Node* temp = root->right;
			free(root);
			return temp;
		} else if (root->right == NULL){
			struct Node* temp = root->left;
			free(root);
			return temp;
		}
		
		struct Node* temp = root->right;
		root->data = temp->data;
		root->right = deletion(root->right, temp->data);
	}
}

int findMin(struct Node* root){
	if(root == NULL){
		printf("Tree is empty\n");
	}
	while(root->left != NULL){
		root = root->left;
	}
	return root->data;
}

int findMax(struct Node* root){
	if(root == NULL){
		printf("Tree is empty\n");
	}
	while(root->right != NULL){
		root = root->right;
	}
	return root->data;
}
int countLeafNodes(struct Node* root){
    if(root == NULL)
        return 0;
    if(root->left==NULL && root->right==NULL)
        return 1;
    
    return countLeafNodes(root->left)+countLeafNodes(root->right);
}
int sumofLeafNodes(struct Node* root){
    if(root == NULL)
        return 0;
    if(root->left==NULL && root->right==NULL)
        return root->data;
    return sumofLeafNodes(root->left)+sumofLeafNodes(root->right);
}

int main(){
	struct Node* root = NULL;
	root = insert(root,50);
	insert(root,30);
	insert(root,20);
	insert(root,40);
	insert(root,70);
	insert(root,60);
	insert(root,80);
	
	printf("Inorder Traversal : ");
	inorderTraversal(root);
	printf("\n");	
	printf("Postorder Traversal : ");
	postorderTraversal(root);
	printf("\n");
	printf("Preorder Traversal : ");
	preorderTraversal(root);
	
	printf("\n");
	
	int valueToSearch = 60;
	struct Node* foundNode = search(root, valueToSearch);
	if(foundNode){
		printf("\n%d was found in the BST", valueToSearch);
	}else{
		printf("\n%d was not found in the BST", valueToSearch);
	}
	
	printf("\n");
	
	int valueToDelete = 30;
	root = deletion(root, valueToDelete);
	printf("\nInorder Traversal after deletion of %d : ", valueToDelete);
	inorderTraversal(root);
	printf("\n");
	
	printf("\nMinimum element is %d",findMin(root));
	printf("\nMaximum element is %d",findMax(root));
    printf("\n");

    printf("the leaf node is : %d ",countLeafNodes(root));
    printf("\n");
    printf("The Sum of leafnode is : %d ",sumofLeafNodes(root));
	
	return 0;
}