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

// Finds starting point of the loop
struct node *findFirst(struct node *head)
{
    struct node *slow = head;
    struct node *fast = head;

    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    while (slow != NULL && fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            break;
        }
    }
    if (slow != fast)
    {
        return NULL;
    }
    slow = head;

    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
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
    node *sixth = new node;
    node *seventh = new node;
    node *eight = new node;

    // Linking each node and initializing their data
    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = fifth;

    fifth->data = 5;
    fifth->next = sixth;

    sixth->data = 6;
    sixth->next = seventh;

    seventh->data = 7;
    seventh->next = eight;

    eight->data = 8;
    eight->next = third;

    // Function call
    struct node *first = findFirst(head);
    if (first != NULL)
    {
        cout << "starting point of loop is : " << first->data;
    }
    else
    {
        cout << "point invalid ";
    }
    return 0;
}