// Program to insert node such list is in ascending order ~ O(n) & O(1) ~ coded by vHiren
#include <bits/stdc++.h>
using namespace std;

// Basic Template
struct node{
    int data;
    struct node* next;
};

// Creates node to list
struct node* createNode(int data){
    struct node* n = new node;

    n->data = data;
    n->next = NULL;
    return n;
}

// Traverses each node
void traversel(struct node* head){
    struct node* p = head;

    while(p != NULL){
        cout<<p->data<<" ";
        p = p->next;
    }
}

// Inserts node such list is in ascending order
struct node* insertNode(struct node* head, int data){
    struct node* p = head;
    struct node* q = head->next;

    // Edge case
    if(head == NULL || head->next == NULL){
        return head;
    }

    // When given data is lesser than head's data
    if(head->data > data){
        struct node* n = new node;
        n->data = data;
        n->next = head;
        head = n;
        return head;
    }
    else{
        // Iterate till end & insert data at aggregate position
        while(q != NULL){
            if(q->data > data){
            struct node* n = new node;

                n->data = data;
                n->next = p->next;
                p->next = n;
                return head;
            }
            p = p->next;
            q = q->next;
        }
    }
    // When given data is greater then last node
    if(p->data < data){
        struct node* n = new node;

        n->data = data;
        p->next = n;
        n->next = NULL;
        return head;
    }
}

// Driver code
int main(){
    // Creating, connecting nodes & initializing their data
    struct node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);
    head->next->next->next->next = createNode(50);
    traversel(head);

    cout<<endl;
    // Inserting node
    head = insertNode(head, 37);
    traversel(head);
    return 0;
}