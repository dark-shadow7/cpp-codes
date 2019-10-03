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
/////////////////////////
#include<bits/stdc++.h>
/*2
1 2
1
3
1
7 8
0*/

using namespace std;
class station;
class ttime;
class train{
public:
    int tno;
    train *dp;
    ttime *rp;
    train(int data){
        tno=data;
        rp=NULL;
        dp=NULL;
    }
};
class station{
public:
    int sno;
    station *rp;
    ttime *dp;
    station(int data){
        sno=data;
        rp=NULL;
        dp=NULL;
    }
};
class ttime{
public:
    int avt;
    int dpt;
    ttime *dp;
    ttime *rp;
    ttime(int data1,int data2){
        avt=data1;
        dpt=data2;
        dp=rp=NULL;
    }
};
int main(){
    int no_tr;
    cin>>no_tr;
    train *start_train=NULL,*next_train=NULL;
    for(int i=0;i<no_tr;i++){
        int tno;
        cin>>tno;
        train *temp=new train(tno);
        if(start_train==NULL){
            start_train=temp;
        }
        else{
            next_train->dp=temp;
        }
        next_train=temp;
    }
    int no_st;
    cin>>no_st;
    station *start_station=NULL,*next_station=NULL;
    for(int i=0;i<no_st;i++){
        int sno;
        cin>>sno;
        station *temp=new station(sno);
        if(start_station==NULL){
            start_station=temp;
        }
        else{
            next_station->rp=temp;
        }
        next_station=temp;
    }
    train *temp_t=start_train;
    station *temp_s=start_station;
    while(temp_t!=NULL){
        while(temp_s!=NULL){
            int ch;
            cout<<"if train for"<<temp_t->tno<<temp_s->sno<<" cout 1"<<endl;
            cin>>ch;
            ttime *start_ttime=NULL,*next_ttime,*next_ttime_down=NULL;
            if(ch){
                int avt, dpt;
                cin>>avt>>dpt;
                ttime *temp_ttime=new ttime(avt,dpt);
                if(start_ttime==NULL){
                    start_ttime=temp_ttime;
                }
                else{
                    next_ttime->rp=temp_ttime;
                }
                next_ttime=temp_ttime;
                if(next_ttime_down==NULL){
                    temp_s->dp=next_ttime_down;
                }
                else{
                    next_ttime_down->dp=temp_ttime;
                }
            }
            temp_s=temp_s->rp;
        }
        temp_s=start_station;
        temp_t=temp_t->dp;
    }
    return 0;
}
/////////////////////////////////////
#include<bits/stdc++.h>
using namespace std;
/*class dnode{
public:
    int data;
    dnode* dptr;
    dnode(int data){
        this->data=data;
        dptr=NULL;
    }
};*/
class mnode{
public:
    int data;
    mnode* rptr;
    mnode* dptr;
    mnode(int data){
        this->data=data;
        rptr=NULL;
        dptr=NULL;
    }
};
mnode* createmulilist(mnode*head){
    int ele;
    cout<<"\neneter main data :";
    cin>>ele;
    mnode* tail;
    do{
        if(head==NULL){
            head=new mnode(ele);
            tail=head;
        }
        else{
            mnode* temp=new mnode(ele);
            tail->rptr=temp;
            tail=temp;
        }
        cout<<"enter down ele: ";
        int k;
        cin>>k;
        mnode *taildptr;
        while(k!=-1){
            mnode *temp=new mnode(k);
            if(tail->dptr==NULL){
                tail->dptr=temp;
                taildptr=temp;
            }
            else{
                taildptr->dptr=temp;
                taildptr=temp;
            }
            cin>>k;
        }
        cout<<"\neneter main data :";
    cin>>ele;
    }while(ele!=-1);
    return head;
}
mnode *merge(mnode*a, mnode *b){
    mnode* result=NULL;
    if(a==NULL)
        return b;
    else if(b==NULL)
        return a;
    if(a->data < b->data){
        result=a;
        result->dptr=merge(a->dptr,b);
    }
    else{
        result=b;
        result->dptr=merge(a,b->dptr);
    }
    return result;
}
void printflattenlist(mnode *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->dptr;
    }
}

mnode *flattenlist(mnode *head){
    if(head->rptr==NULL || head==NULL){
        return head;
    }
    mnode*ans= (merge(head,flattenlist(head->rptr)));
    return ans;
}

//1 4 5 -1 2 8 9 -1 47 89 -1 -1
//1 2 3 -1 4  5-1 7 8 -1 -1
int main(){
    mnode *head=createmulilist(NULL);
    head=flattenlist(head);
    cout<<endl;
    printflattenlist(head);
    cout<<endl;
    return 0;
}
