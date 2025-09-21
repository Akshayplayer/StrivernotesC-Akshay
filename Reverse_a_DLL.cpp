#include<iostream>
#include<stack>
using namespace std;

class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

// solution using stack but it will take O(2n) time complexity
class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
       stack<int> st;
       Node* temp=head;
       while(temp!=NULL){
           st.push(temp->data);
           temp=temp->next;
       }
       Node* temp2=head;
       while(!st.empty()){
           temp2->data=st.top();
           st.pop();
           temp2=temp2->next;
       }
       return head;
    }
};


// by changing links of next and prev from the head.
class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
        Node* temp=head->next;
        while(temp!=NULL){
            Node* temp2=head->prev;
            head->next=head->prev;
            temp2=temp;
            head=temp;
            temp=head->next;
        }
        Node* temp2=head->prev;
        head->next=head->prev;
        temp2=temp;
        return head;
    }
};


// problem link= https://www.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1
// TC= O(n)
// SC= O(1)