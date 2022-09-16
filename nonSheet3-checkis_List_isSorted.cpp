#include <bits/stdc++.h>
using namespace std;

// Basic Template
struct node{
    int data;
    struct node* next;
};

// Traverses each element 
void traversel(struct node *head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}

// Checks list is sorted or not
bool isSorted(struct node* head){
    bool sorted = true;

    while(head->next != NULL){
        if(head->data <= head->next->data){
            sorted = true;
        }
        else{
            sorted = false;
        }
        head = head->next;
        if(sorted == false){
            return false;
        }
    }
    return true;
}

// Driver code
int main(){
    // Creating nodes
    struct node* head = (struct node*)malloc(sizeof(struct node));
    struct node* second = (struct node*)malloc(sizeof(struct node));
    struct node* third = (struct node*)malloc(sizeof(struct node));
    struct node* fourth = (struct node*)malloc(sizeof(struct node));
    struct node* fifth = (struct node*)malloc(sizeof(struct node));
    struct node* sixth = (struct node*)malloc(sizeof(struct node));

    // Connecting the nodes & initializing their data
    head->data = 1;
    head->next = second;

    second->data = 5;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = fifth;

    fifth->data = 5;
    fifth->next = sixth;

    sixth->data = 20;
    sixth->next = NULL;

    traversel(head);
    cout<<endl;

    if(isSorted(head)){
        cout<<"list is sorted";
    }
    else{
        cout<<"list is not sorted";
    }
    return 0;
}