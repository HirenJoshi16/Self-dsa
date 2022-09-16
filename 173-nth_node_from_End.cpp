// Program to find nth node from the end of the list
#include <iostream>
#include <malloc.h>
using namespace std;

struct node
{
    int data;
    node *next;
};

void listTraversel(node *head)
{
    if (head == NULL)
    {
        return;
    }
    cout << head->data << " ";
    listTraversel(head->next);
}

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
    while (q != NULL)
    {
        p = p->next;
        q = q->next;
    }
    return p;
}

int main()
{
    node *head = new node;
    node *second = new node;
    node *third = new node;
    node *fourth = new node;
    node *fifth = new node;

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

    node *n = nthNode(head, 4);
    if (n != NULL)
    {
        cout << n->data;
    }
    else
    {
        cout << "invalid node";
    }
    return 0;
}