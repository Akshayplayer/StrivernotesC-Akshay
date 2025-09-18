#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }

    public:
    Node(int data1){
        data=data1;
        next=nullptr;
    }
};

Node* convertArr2LL(vector<int>& arr){
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}

//Length of the LL
int LengthofLL(Node* head){
    int cnt=0;
    Node* temp=head;
    while(temp){
        temp=temp->next;
        cnt++;
    }
    return cnt;
}
int serachinLL(Node* head,int target){
    Node* temp=head;
    int i=0;
    while(temp){
        if(temp->data==target) return i;
        temp=temp->next;
        i++;
    }
    return -1;
}

//deleting head of the ll
Node* removehead(Node* head){
    if(head==NULL) return head;
    Node* temp=head;
    head=head->next;
    delete temp;
    return head;
}

//deleting tail of the ll
Node* removetail(Node* head){
    if(head==NULL || head->next==NULL) return NULL;
    Node* temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    delete temp->next;
    temp->next=NULL;
    return head;
}

//removing element at kth position.
Node* removek(Node* head, int k){
    if(head==NULL) return head;
    if(k==1){
        Node* temp=head;
        head=head->next;
        delete temp;
        return head;
    }
    int cnt=0;
    Node* temp=head;
    Node* prev=NULL;
    while(temp!=NULL){
        cnt++;
        if(cnt==k){
            prev->next=prev->next->next;
            delete temp;
            return head;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}
// Remove element from the LL
Node* removeEl(Node* head, int element){
    if(head==NULL) return head;
    if(head->data==element){
        Node* temp=head;
        head=head->next;
        delete temp;
        return head;
    }
    Node* temp=head;
    Node* prev=NULL;
    while(temp!=NULL){
        if(temp->data==element){
            prev->next=prev->next->next;
            delete temp;
            return head;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}

//inserting in head
Node* inserthead(Node* head, int val){
    return new Node(val,head);
}

//creating a new tail element.
Node* inserttail(Node* head,int val){
    if(head==NULL){
        return new Node(val);
    }
    Node* newNode=new Node(val);
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    return head;
}

//creating a new element at kth position.
Node* insertatk(Node* head, int val, int k){
    if(head==NULL){
        if(k==1){
            return new Node(val);
        }
        else{
            return head;
        }
    }
    if(k==1){
        return new Node(val,head);
    }
    int cnt=0;
    Node* temp=head;
    while(temp!=NULL){
        cnt++;
        if(cnt==k-1){
            Node* newNode=new Node(val,temp->next);
            temp->next=newNode;
            break;
        }
        temp=temp->next;
    }
    return head;
}

//Inserting an element just before an element x.
Node* insertbeforeX(Node* head, int val, int x){
    if(head==NULL){
        return head;
    }
    
    if(head->data==x){
        return new Node(val,head);
    }
    Node* temp=head;
    while(temp->next!=NULL){
        if(temp->next->data==x){
            Node* newNode=new Node(val,temp->next);
            temp->next=newNode;
            break;
        }
        temp=temp->next;
    }
    return head;
}

void print(Node* head){
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
int main(){
    vector<int> arr={2,5,8,7};
    // Node* y=new Node(arr[0]);
    Node* head=convertArr2LL(arr);
    cout<<head->data<<endl;;

    //traversal in a LL
    Node* temp=head;
    
    cout<<endl;
    cout<<LengthofLL(head)<<endl;
    cout<<serachinLL(head,8)<<endl;
    head=inserthead(head,10);
    head=inserttail(head,9);
    head=insertatk(head,6,3);
    head=insertbeforeX(head, 5,6);
    print(head);
}

