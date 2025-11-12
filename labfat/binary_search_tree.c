#include <stdio.h>
#include <stdlib.h>
struct bst{
    int data;
    struct bst* right;
    struct bst* left; 
};
typedef struct bst bt;
void inorder(bt* tree){
    if(tree != NULL){
        inorder(tree->left);
        printf("%d ", tree->data);
        inorder(tree->right);
    }
}
bt* makenode(int val){
    bt* root = (bt*) malloc(sizeof(bt));
    root->data = val;
    root->right = NULL;
    root->left = NULL;
    return root; //DONT FORGET TO RETURN
}
bt* insert(bt* tree, int val){ //RETURN TREE ONLY
    if(!tree)
        return makenode(val); 
    if(tree->data > val)
        tree->left = insert(tree->left, val); //DONT FORGET TO ASSIGN
    else if(tree->data < val)
        tree->right = insert(tree->right, val);
    return tree; //DONT FORGET TO RETURN
}
int findmin(bt* tree){
    if(tree){
        if(tree->left != NULL)
            return findmin(tree->left);
        else
            return tree->data;
    }
}
bt* delete(bt* tree, int val){ //RETURN TREE ONLY
    if(tree){
        if(tree->data == val){
            if(tree->right == NULL && tree->left == NULL)
                return NULL;
            else if(tree->right == NULL)
                return tree->left;
            else if(tree->left == NULL)
                return tree->right;
            tree->data = findmin(tree->right);
            tree->right = delete(tree->right, tree->data );
            return tree;
        }
        else if(tree->data > val)
            tree->left = delete(tree->left, val); //DONT FORGET TO RETURN
        else
            tree->right = delete(tree->right, val);//DONT FORGET TO RETURN
        return tree;
    }
}
void main(){
    printf("Name : Niveditha A.\nReg No : 24BCE2000");
    bt* tree = makenode(19);
    tree = insert(tree, 10);
    tree = insert(tree, 7);
    tree = insert(tree, 20);
    tree = insert(tree, 25);
    tree = insert(tree, 15);
    tree = insert(tree, 18);
    printf("\nInorder traversal: ");
    inorder(tree);
    tree = delete(tree, 15);
    printf("\nInorder traversal: ");
    inorder(tree);
}