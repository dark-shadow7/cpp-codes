#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node*next;
    node(int data){
    this->data=data;
    next=NULL;
    }
};
node* createlist(node* head){
    int ele;
    node *tail;
    cin>>ele;
    do{
        if(head==NULL){
            head=new node(ele);
            tail=head;
        }
        else{
            node* temp=new node(ele);
            tail->next=temp;
            tail=temp;
        }
        cin>>ele;
    }while(ele!=-1);
    return head;
}
void print(node *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}
node* mid(node* head){
    node *mid=head;
    int count=0;
    if(head==NULL){
        return head;
    }
    while(head->next!=NULL){
        if(count%2!=0){
            mid=mid->next;
        }
        count++;
        head=head->next;
    }
    return mid;
}
node *merge(node*a, node *b){
    node* result=NULL;
    if(a==NULL)
        return b;
    else if(b==NULL)
        return a;
    if(a->data < b->data){
        result=a;
        result->next=merge(a->next,b);
    }
    else{
        result=b;
        result->next=merge(a,b->next);
    }
    return result;
}
node* sort(node* head){
    if(head==NULL || head->next==NULL)
        return head;
    node* temp=mid(head);
    node* m=temp->next;
    temp->next=NULL;
    node *a=sort(head);
    node *b=sort(m);
    node*ans= merge(a,b);
    return ans;
}
int length(node *head){
    int count=0;
    while(head!=NULL){
        count++;
        head=head->next;
    }
    return count;
}
void findmergepoint(node* head1 , node* head2)
{
    int l1=length(head1);
    int l2=length(head2);
    int s=0;
    if(l1>=l2){
        s=l1-l2;
    }
    else{
        s=l2-l1;
        node* temp=head1;
        head1=head2;
        head2=temp;
    }
    int count=0;
    while(count!=s){
        head1=head1->next;
        count++;
    }
    while(head1!=head2 && head1!=NULL && head2!=NULL){

        head1=head1->next;
        head2=head2->next;
    }
   // cout<<head1->data<<" "<<head2->data<<endl;
    if(head1 == NULL || head2==NULL){
        cout<<"no";
    }
    else{
        cout<<head1->data;
    }
}
// 1 2 3 4 5 -1
int main(){
    node* head=createlist(NULL);
    node* head2=createlist(NULL);
    head2->next->next=head->next->next->next;
    print(head);
    cout<<endl;
    print(head2);
    findmergepoint(head,head2);
    /*print(head);
    cout<<endl;
    head=sort(head);
    print(head);*/
   // node *m = mid(head);
   // cout<<m->data;
    return 0;
}
