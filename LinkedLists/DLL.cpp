#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *back;

public:
    Node(int data1, Node *next1, Node *back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node *converttoDLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *prev = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

// deleting head of the LL
Node *Deletionhead(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    Node *prev = head;
    head = head->next;
    head->back = nullptr;
    prev->next = nullptr;
    delete prev;
    return head;
}

// deleting tail of the LL.
Node *Deletiontail(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    Node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    Node *prev = tail->back;
    prev->next = nullptr;
    tail->back = nullptr;
    delete tail;
    return head;
}

// deleting kth element of the DLL.
Node *removeKthElement(Node *head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }
    int cnt = 0;
    Node *KNode = head;
    while (KNode != NULL)
    {
        cnt++;
        if (cnt == k)
            break;
        KNode = KNode->next;
    }
    Node *prev = KNode->back;
    Node *front = KNode->next;

    if (prev == NULL && front == NULL)
    {
        return NULL;
    }
    else if (front == NULL)
    {
        return Deletiontail(head);
    }
    else if (prev == NULL)
    {
        return Deletionhead(head);
    }

    prev->next = front;
    front->back = prev;

    KNode->next = nullptr;
    KNode->back = nullptr;

    delete KNode;
    return head;
}

// Removing a node if node pointer is pass.
void deleteNode(Node *temp)
{
    Node *prev = temp->back;
    Node *front = temp->next;
    if (front == NULL)
    {
        prev->next = nullptr;
        temp->back = nullptr;
        free(temp);
        return;
    }
    if (prev == NULL)
    {
        prev = temp;
        temp = temp->next;
        temp->back = nullptr;
        prev->next = nullptr;
        free(prev);
        return;
    }
    prev->next = front;
    front->back = prev;
    temp->next = temp->back = nullptr;
    free(temp);
}

// Inserting of Node before the  head
Node *insertbeforehead(Node *head, int val)
{
    Node *newhead = new Node(val, head, nullptr);
    head->back = newhead;
    return newhead;
}

// Insertion before the tail of the Linked List.
Node *insertbeforetail(Node *head, int val)
{
    if (head->next == NULL)
    {
        return insertbeforehead(head, val);
    }
    Node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    Node* prev = tail->back;
    Node* newNode = new Node(val, tail, prev);
    prev->next=newNode;
    tail->back = newNode;
    return head;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "  ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {1, 4, 3, 5, 6, 8};
    Node *head = converttoDLL(arr);
    // deleteNode(head);
    // Node* LL=removeKthElement(head,3);
    print(head);
    Node *newhead = insertbeforehead(head, 2);
    print(newhead);
    Node *newtail = insertbeforetail(newhead, 13);
    print(newtail);
}