#include<iostream>
using namespace std;
class DLLNode{
public:
    int data;
    DLLNode *prev;
    DLLNode *next;
    DLLNode(){
        prev=next=0;
    }
    DLLNode(int data, DLLNode *prev=0, DLLNode *next=0){
        this->data=data;
        this->prev=prev;
        this->next=next;
    }
};
class DLL{
public:
    DLLNode *Head,*Tail;
    DLL(){
        Head=Tail=0;
    }
    bool isEmpty(){
        return Head == 0;
    }
    void addToTail(int e){
        if(Tail == 0){
            Head=Tail=new DLLNode(e);
        }
        else{
            Tail=new DLLNode(e,Tail,0);
            Tail->prev->next=Tail;
        }
    }
    int deleteFromTail(){
        if(!isEmpty()){
            int e = Tail->data;
            if(Tail == Head){
                delete Tail;
                Head=Tail=0;
            }else{
                Tail=Tail->prev;
                delete Tail->next;
                Tail->next=0;
            }
            return e;
        }
        return -1;
    }
    void addToHead(int e){
        if(Head == 0){
            Head=Tail=new DLLNode(e);
        }else{
            Head = new DLLNode(e,0,Head);
            Head->next->prev=Head;

        }
    }
    int deleteFromHead(){
        if(!isEmpty()){
            int e=Head->data;
            if(Head == Tail){
                delete Head;
                Head=Tail=0;
            }else{
                Head=Head->next;
                delete Head->prev;
                Head->prev=0;

            }
            return e;
        }
        return -1;
    }
    void deleteSpecificNode(int e){
        if(!isEmpty()){
            if(Head == Tail && Head->data == e){
                delete Head;
                Head=Tail=0;
            }else if(Head->data == e){
                Head=Head->next;
                delete Head->prev;
                Head->prev=0;
            }
            else if(Tail->data == e){
                Tail=Tail->prev;
                delete Tail->next;
                Tail->next=0;
            }else{
                DLLNode *temp=Head;
                while(temp->data != e && temp !=0) temp=temp->next;
                if(temp != 0){
                    temp->prev->next=temp->next;
                    temp->next->prev=temp->prev;
                    delete temp;
                }
            }

        }
    }
    void Display(){
            DLLNode *p=Head;
            while(p != 0){
                cout << p->data << ' ';
                p=p->next;
            }
        }
};
int main(){
    DLL l;
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