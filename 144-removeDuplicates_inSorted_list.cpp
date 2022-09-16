// Remove duplicates in a sorted linked list ~ T.C - O(n), S.C - O(1)
#include <bits/stdc++.h>
using namespace std;

// Basic Template
struct node
{
    int data;
    struct node *next;
};

// Traverses each node
void traversel(struct node *head)
{
    struct node *tmp = head;
    do
    {
        cout << tmp->data << " ";
        tmp = tmp->next;
    } while (tmp != head);
}

// Removes duplicates to list
struct node* removeDuplicate(struct node* head){
    struct node* p = head;
    struct node* q = head->next;

    if(head == NULL){
        return NULL;
    }

    while(p->next != NULL){

        if(p->data != q->data){
            p = p->next;
            q = q->next;
        }
        else{
            struct node* t = q;
            p->next = q->next;
            q = q->next;
            free(t);
        }
    }
    return head;
}

// Driver code
int main()
{
    // Creating nodes and allocating their memory dynamically
    struct node *head = new node;
    struct node *second = new node;
    struct node *third = new node;
    struct node *fourth = new node;
    struct node *fifth = new node;

    // Connecting the nodes & initializing their data
    head->data = 10;
    head->next = second;

    second->data = 40;
    second->next = third;

    third->data = 40;
    third->next = fourth;

    fourth->data = 40;
    fourth->next = fifth;

    fifth->data = 40;
    fifth->next = NULL;

    // traversel(head);
    cout<<endl;
    head = removeDuplicate(head);
    traversel(head);
    return 0;
}