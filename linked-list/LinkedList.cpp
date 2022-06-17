#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node *next;
        Node(int data){
            this->data=data;
            this->next=0;
        }
};
class List{
public:
    Node *Head,*Tail;
    
        List(){
            Head=Tail=0;
        }
        List(List *l){
            Head=Tail=0;
            Node *p=l->Head;
            while(p != 0){
                this->addToTail(p->data);
                p=p->next;
            }
        }
        bool isEmpty(){
            return Head == 0;
        }
        void addToHead(int e){
            Node *temp=new Node(e);
            temp->next=Head;
            Head=temp;
            if(Tail == 0) Tail=Head;
        }
        void addToTail(int e){
            if(Tail != 0){
                Tail->next=new Node(e);
                Tail=Tail->next;
            }
            else{
                Tail=Head=new Node(e);
            }
            
        }
        int deleteFromHead(){
            if(!isEmpty()){
                int e=Head->data;
                Node *temp=Head;
                if(Head == Tail) Head=Tail=0;
                else Head=Head->next;
                delete temp;
                return e;
            }else{
                return -1;
            }

        }
        int deleteFromTail(){
            if(!isEmpty()){
                int e = Tail->data;
                Node *temp=Tail;
                if(Head == Tail) Head=Tail=0;
                else{
                    Node *p = Head;
                    while(p->next != Tail) p=p->next;
                    Tail=p;
                    Tail->next=0;
                }
                delete temp;
                return e;
            }else{
                return -1;
            }

        }
        void Display(){
            Node *p=Head;
            while(p != 0){
                cout << p->data << ' ';
                p=p->next;
            }
        }
        void recursiveDisplay(Node *p){
            if(p != 0){
                cout << p->data << ' ';
                recursiveDisplay(p->next);
            }
        }
        void recursiveDisplayReverse(Node *p){
            if(p != 0){
                recursiveDisplayReverse(p->next);
                cout << p->data << ' ';
                
            }
        }
        int countNodes(Node *p){
            int c=0;
            while(p != 0){
                c++;
                p=p->next;
            }
            return c;
        }
        int countNodesRecursive(Node *p){
            if(p == 0) return 0;
            else return countNodesRecursive(p->next) + 1;
        }
        void deleteSpecificNode(int e){
            if(!isEmpty()){
                if(Head == Tail && Head->data == e){
                    delete Head;
                    Head=Tail=0;
                }else if(Head->data == e){
                    Node *temp=Head;
                    Head=Head->next;
                    delete temp;
                }else{
                    Node *pre,*temp;
                    pre=Head;
                    temp=pre->next;
                    while(temp->data != e && temp !=0){
                        pre=pre->next;
                        temp=temp->next;
                    }
                    if(temp != 0){
                        pre->next=temp->next;
                        if(Tail == temp) Tail=pre;
                        delete temp;
                        
                    }

                }
            }
        }
        int recursiveMax(Node *p){
            int x;
            if(p == 0) return INT16_MIN;
            else{
                x=recursiveMax(p->next);
                if(p->data > x) return p->data;
                else return x;
            }
        }
        Node* recursiveSearch(Node *p,const int key){
            if(p == 0) return 0;
            else if(p->data == key) return p;
            return recursiveSearch(p->next,key);
        }
        bool isSorted(Node *p){
            int x=INT8_MIN;
            while(p != 0){
                if(p->data < x) return false;
                x=p->data;
                p=p->next;
            }
            return true;
        }
        void removeDuplicateInSorted(Node *p){
            Node *q=p->next;
            while(q != 0){
                if(p->data != q->data){
                    p=q;
                    q=q->next;
                }else{
                    p->next=q->next;
                    delete q;
                    q=p->next;
                }
            }
        }
        void reverseLinkedList(Node *p){
            Tail=p;
            Node *q=0;
            Node *r=0;
            while(p != 0){
                r=q;
                q=p;
                p=p->next;
                q->next=r;
            }
            Head=q;
        }
        void recursiveReverseLinkedList(Node *q,Node *p){
                if(p != 0){
                    recursiveReverseLinkedList(p,p->next);
                    p->next=q;
                    if(q == 0) Tail=p;
                }else{
                    Head=q;
                }
        }
        List* concat(List *l2){
            List *newl=new List(this);
            List *newL2=new List(l2);
            List *l3=new List;
            l3->Head=newl->Head;
            l3->Tail=newL2->Tail;
            Node *p=l3->Head;
            while(p->next !=0) p=p->next;
            p->next=newL2->Head;
            return l3;

            
        }
        
};
int main(){
    List* l=new List;
    l->addToTail(1);
    l->addToTail(2);
    l->addToTail(3);
    l->addToTail(4);
    List* l2=new List;
    l2->addToTail(5);
    l2->addToTail(6);
    l2->addToTail(7);
    l2->addToTail(8);
    List* l3=l->concat(l2);
    l3->recursiveDisplay(l3->Head);
    return 0;
}