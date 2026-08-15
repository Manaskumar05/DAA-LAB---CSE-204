//3. Create a Binary Search Tree and perform the insertion, deletion operations.

#include <iostream>
using namespace std;

struct node{
    struct node *lptr;
    int data;
    struct node *rptr;
};

struct node *newnode(int a){
    struct node *abc = (struct node *)malloc(sizeof(struct node));
    abc -> lptr = NULL;
    abc -> rptr = NULL;
    abc -> data = a;

    return abc;
}

struct node *insert(struct node *root,int value) {
    if(root == NULL)    return newnode(value);
    else{
        if(value < root -> data) {
            root -> lptr = insert(root -> lptr,value);
        }
        else if(value > root -> data) {
            root -> rptr = insert(root -> rptr,value);
        }
    }
    return root;
}


struct node *delete_node(struct node *root , int value) {
    if(root == NULL)    return NULL;

    if(value < root -> data) {
        root -> lptr = delete_node(root -> lptr , value);
    }

    else if(value > root -> data) {
        root -> rptr = delete_node(root -> rptr , value);
    }

    else{
        if(root -> lptr == NULL && root -> rptr == NULL){
            free(root);
            return NULL;
        }
        
        else if(root -> lptr == NULL) {
            struct node *temp = root -> rptr;
            free(root);
            return temp;
        }
        
        else if(root -> rptr == NULL) {
            struct node *temp = root -> lptr;
            free(root);
            return temp;
        }

        else{
            struct node *temp = root -> rptr;

            while(temp -> lptr != NULL){
                temp = temp -> lptr;
            }

            root -> data = temp -> data;
            root -> rptr = delete_node(root -> rptr, temp -> data);
        }
    }

    return root;
}

void inorder(struct node *root) {
    if (root == NULL) return;

    inorder(root -> lptr);
    cout << root -> data << " ";
    inorder(root -> rptr);

}

int main() {

    struct node *root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    root = insert(root, 100);
    root = insert(root, 120);

    inorder(root);
    cout << endl;
    
    delete_node(root,120);
    inorder(root);
    cout << endl;

    delete_node(root,80);
    inorder(root);
    cout << endl;

    delete_node(root,50);
    inorder(root);
    cout << endl;

    return 0;
}