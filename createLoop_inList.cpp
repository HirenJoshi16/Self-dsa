#include <iostream>
#include <stdlib.h>
using namespace std;

struct node{
    int data;
    node *next;
};

void createList(node *head){
    node *p = head;
    int i=1, limitSize=4, data;

    while(i <= limitSize){
        node *node = (struct node*)malloc(sizeof(node));
        if(node == NULL){
            cout<<"node creation failed"<<endl;
        }
                else{
                    cout<<"enter data for "<<i<<" node "<<endl;
                    cin>>data;
                    if(i == 1){
                    head->data = data;  
                }
                    else{
                    node->data = data;
                    p->next = node;
                    p = p->next;
                }
        }
        node->next = NULL;
        i++;
    }
}

void createNode(node *head, node* posNode){
    node *p = head;
    node *q = posNode;
    int i=1, limitSize=4, data;

    node *n = (struct node*)malloc(sizeof(node));
    while(i <= limitSize){
        if(n == NULL){
            cout<<"node creation failed"<<endl;
        }
                else{
                    cout<<"enter data for "<<i<<" node for cycle list"<<endl;
                    cin>>data;

                    if(i == 1){
                    posNode->next = n;
                    n->data = data;  
                }
                    else{
                    n->data = data;
                    q = q->next;
                    q->next = n;
                }
        }
        i++;
    }
    n->next = posNode;
}

void traversel(node *head){
    node *p = head;
    while(p != NULL){
        cout<<p->data<<" ";
        p = p->next;
    }
}

node* makeCycle(node* head, int pos){
    node* p = head;
    int i = 1;
    while(i < pos){
        p = p->next;
    }
    createNode(head, p);
    return head;
}

int main(){
    node *head = (node*)malloc(sizeof(node));
    head->next = NULL;

    cout<<"Enter elements of 1st list : "<<endl;
    createList(head);
    cout<<endl;
    cout<<"Elements of 1st list : ";
    traversel(head);

    cout<<endl;
    cout<<"Enter elements of 2nd list : "<<endl;
    createList(head);
    cout<<endl;  
    cout<<"Elements of 2nd list : ";
    traversel(head);
    
    cout<<endl<<endl;
    cout<<"Loop created ! :"<<endl;
    makeCycle(head, 4);
    traversel(head);
    return 0;
}