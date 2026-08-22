#include <iostream>
using namespace std;

struct node {
    int data;
    struct node *next;
};

node *top = NULL;


void push(int a) {
    node *newnode = new node();

    newnode -> data = a;
    newnode -> next = top;
    top = newnode;

    cout << a << " pushed into stack\n";

}

void pop() {
    node *p = top;

    if(p == NULL) {
        cout << "Stack Underflow " << endl;
    }

    cout << top->data << " popped from stack\n";

    top = top -> next;
    delete p;
}

void display() {
    if (top == NULL) {
        cout << "Stack is empty\n";
        return;
    }

    node* temp = top;

    cout << "Stack: ";

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main() {
    push(10);
    push(20);
    push(30);

    display();

    pop();
    display();

    pop();
    display();

    return 0;
}