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
};
int main(){
    List l;
    l.addToTail(1);
    l.addToTail(2);
    l.addToTail(3);
    l.addToTail(4);
    l.Display();
    cout << '\n';
    l.deleteSpecificNode(1);
    l.Display();
    return 0;
}