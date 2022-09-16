// Program to find and delete the nth node from the end of the list
#include <iostream>
#include <malloc.h>
using namespace std;

//Basic template
struct node
{
    int data;
    node *next;
};

//Traverses each node
void listTraversel(node *head)
{
    if (head == NULL)
    {
        return;
    }
    cout << head->data << " ";
    listTraversel(head->next);
}

//Creates a node and initializes its data
node* createNode(int data, node* next){
    node *n = (node*)malloc(sizeof(node));
    n->data = data;
    n->next = next;
    return n;
}

//To find the nth node from the end of the linked list
node *nthNode(node *head, int n)
{
    int i = 0;
    node *p, *q;
    p = q = head;

    while (i != n)
    {
        q = q->next;
        i++;
    }
    while(q != NULL)
    {
        p = p->next;
        q = q->next;
    }
    return head;
}

//To find and delete nth node from the end of the linked list
node *deleteNthNode(node *head, int n)
{
    int i = 0;
    node *p, *q;
    //Dummy node is created which contains zero data and points before head usually helpful to delete the nth node by removing the links
    node *dummy = createNode(0, head);

    p = dummy;
    q = head;

    while (i != n)
    {
        q = q->next;
        i++;
    }
    while(q != NULL)
    {
        p = p->next;
        q = q->next;
    }
    
    //Deletion strategy after node is found
    p->next = p->next->next;
    return dummy->next;
}

//Driver code
int main()
{
    //Node created dynamically
    node *head = new node;
    node *second = new node;
    node *third = new node;
    node *fourth = new node;
    node *fifth = new node;

    //Linking each node and initializing their data
    head->data = 12;
    head->next = second;

    second->data = 30;
    second->next = third;

    third->data = 50;
    third->next = fourth;

    fourth->data = 80;
    fourth->next = fifth;

    fifth->data = 68;
    fifth->next = NULL;

    //Function call
    head = deleteNthNode(head, 5);
    listTraversel(head);
    return 0;
}