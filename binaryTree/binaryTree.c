#include <stdio.h>

struct Node {
    int val;
    struct Node *left, *right;
};

typedef struct Node Tree;

Tree *newItem(int val){
    Tree *node = (Tree *) malloc(sizeof(Tree));
    node->left = NULL;
    node->right = NULL;
    node->val = val;
    
    return node;
}

Tree *insertNode(Tree *root , int val){
    if(!root){
        return newItem(val);
    }else{
        if(root->val > val){
            root->left = insertNode(root->left, val);
        }else if(root->val < val){
            root->right = insertNode(root->right, val);
        }
    }
    
    return root;
}


int searchValue(Tree *root , int val ){
    if(!root){
        return 0;
    }else{
        if(root->val == val){
            return 1;
        }else if(root->left && root->val > val){
            return searchValue(root->left , val);
        }else if(root->right && root->val < val){
            return searchValue(root->right , val);
        }else{
            return 0;
        }
    }
}

void printUpToDown(Tree *root) {
    if (root) {
        printf("value is =  %d\n", root->val);
        printUpToDown(root->left);
        printUpToDown(root->right);
    }
}

void printDownToUp(Tree *root) {
    if (root) {
        
        printDownToUp(root->left);
        printDownToUp(root->right);
        
        printf("value is = %d\n", root->val);
    }
}

void printLeftToRight(Tree *root) {
    if (root) {
        printLeftToRight(root->left);
        printf("value is =  %d\n", root->val);
        printLeftToRight(root->right);
    }
}

Tree *deleteNode(Tree *root , int val){
    Tree *tmpNode;
    if(!root){
        return NULL;
    }else{
        if(root->val == val){
            if(root->right && !root->left){
                root = root->right;
            }else if(root->left && !root->right){
                
                root = root->left;
            }else if(root->left && root->right){
                
                tmpNode = root->left;
                
                if(tmpNode->right){
                    while(tmpNode->right){
                        tmpNode = tmpNode->right;
                    }
                }
                
                root->val = tmpNode->val;
                
                root->left = deleteNode(root->left,tmpNode->val);
                
            }else{
                root = NULL;
            }
        }else if(root->left && root->val > val){
            root->left = deleteNode(root->left , val);
        }else if(root->right && root->val < val){
            root->right = deleteNode(root->right , val);
        }
    }
    return root;
}



int main(int argc, const char * argv[]) {
    Tree * tree = insertNode(NULL, 20);
    insertNode(tree, 10);
    insertNode(tree, 5);
    insertNode(tree, 11);
    insertNode(tree, 30);
    insertNode(tree, 35);
    insertNode(tree, 29);
    insertNode(tree, 12);
    insertNode(tree, 9);
    insertNode(tree, 31);
    
    printf("Up Down print\n");
    printUpToDown(tree);
    
    if(searchValue(tree , 10)){
        printf("\n\nvalue exist in tree\n\n" );
    }else{
        printf("\n\nvalue doesn't exist in tree\n\n" );
    }
    
    
    
    printf("Down Up print\n");
    
    printDownToUp(tree);
    
    
    printf("\n\nLeft down print\n");
    
    printLeftToRight(tree);
    
    
    deleteNode(tree , 30);
    printf("\n\nUp Down print\n");
    printUpToDown(tree);
    
    
}






