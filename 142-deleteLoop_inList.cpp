// Program to detect loop in a list
#include <iostream>
#include <malloc.h>
using namespace std;

// Basic template
struct node
{
    int data;
    node *next;
};

// Traverses each node
void listTraversel(node *head)
{
    if (head == NULL)
    {
        return;
    }
    cout << head->data << " ";
    listTraversel(head->next);
}

// Creates a node and initializes its data
node *createNode(int data, node *next)
{
    node *n = (node *)malloc(sizeof(node));
    n->data = data;
    n->next = next;
    return n;
}

// To delete list is a cycle or not
void deleteLoop(node *head)
{
    node *fast, *slow;
    fast = slow = head;

    do
    {
        fast = fast->next->next;
        slow = slow->next;
    } while (slow != fast);

    fast = head;
    while (fast->next != slow->next)
    {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = NULL;
}

// Driver code
int main()
{
    // Node created dynamically
    node *head = new node;
    node *second = new node;
    node *third = new node;
    node *fourth = new node;
    node *fifth = new node;

    // Linking each node and initializing their data
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

    // Function call
    if (detectLoop(head))
    {
        cout << "list is cycled";
    }
    else
    {
        cout << "list is not cycled";
    }
    return 0;
}