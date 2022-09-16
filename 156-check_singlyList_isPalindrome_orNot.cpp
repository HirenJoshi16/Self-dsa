// Programt to check is linked list palindrome or not
#include <bits/stdc++.h>
using namespace std;

// Basic Template
struct node{
    char data;
    struct node* next;
};

// Reverses list
struct node* listReverse(struct node* head){
    struct node* prev = NULL;
    struct node* curr = head;
    struct node* nexxt;
        
        while(curr != NULL){
            nexxt = curr->next;
            curr->next = prev;

            prev = curr;
            curr = nexxt;
        }
    return prev;
}

// Converts data to single string
string makeString(struct node* head){
    struct node *p = head;
    string newNum;

        while(p != NULL){
            newNum += to_string(p->data); 
            p = p->next;
        } 
    return newNum;
}

// Compares both string & returns aggregate value
bool isPalindrome(string str1, string str2){
    if(str1 == str2){
        return true;
    }
    return false;
} 

// Traverses each node
void Traversel(struct node* head){
    struct node *p = head;
    if(head == NULL){
        return;
    }
    cout<<head->data<<" ";
    Traversel(head->next);
}

int main(){
    // Creating nodes
    struct node* head = (struct node*)malloc(sizeof(struct node));
    struct node* second = (struct node*)malloc(sizeof(struct node));
    struct node* third = (struct node*)malloc(sizeof(struct node));
    struct node* fourth = (struct node*)malloc(sizeof(struct node));
    struct node* fifth = (struct node*)malloc(sizeof(struct node));

    // Connecting the nodes & initializing their data
    head->data = 'R';
    head->next = second;

    second->data = 'A';
    second->next = third;

    third->data = 'D';
    third->next = fourth;

    fourth->data = 'A';
    fourth->next = fifth;

    fifth->data = 'R';
    fifth->next = NULL;

    // Concate each node's data in string 1 before reversel
    string str1 = makeString(head);
    
    Traversel(head);
    cout<<endl;
    head = listReverse(head);

    // Concate each node's data in string 2 after reversel
    string str2 = makeString(head);
    
    // Function call
    if(isPalindrome(str1, str2)){
        cout<<"list is palindrome";
    }
    else{
        cout<<"list is not palindrome";
    }

    return 0;
}