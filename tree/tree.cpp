#include<iostream>
using namespace std;
template<class T>
class Queue{
    T *arr;
    int front,rear,size;
public:
    Queue(int size){
        this->size=size;
        arr=new T[size];
        front=rear=0;
    }
    bool isEmpty(){
        return front == rear;
    }
    bool isFull(){
        return  ((rear + 1) % size) == front;
    }
    void enqueue(T element){
        if(!isFull()){
            rear=(rear + 1) % size;
            arr[rear]=element;
        }else{
            cout << "Queue is full\n";
        }
    }
    T dequeue(){
        T x=0;
        if(!isEmpty()){
            front = (front + 1) % size;
            x=arr[front];
        }else{
            cout << "Queue is empty\n";
        }
        return x;
    }
};
class Node{
    public:
        int data;
        Node* lChild;
        Node* rChild;
};
class Tree{
public:
    Node *root;
    Tree(){
        root=0;
    }
    void createTree(){
        Node *p,*t;
        int x;
        Queue<Node*> q(100);
        cout << "Enter value for root node: \n";
        cin >> x;
        root=new Node;
        root->data=x;
        root->lChild=root->rChild=0;
        q.enqueue(root);
        while(!q.isEmpty()){
            p=q.dequeue();
            cout << "Enter value of left child for " << p->data << ": ";
            cin >> x;
            if(x != -1){
                t=new Node;
                t->data=x;
                t->lChild=t->rChild=0;
                p->lChild=t;
                q.enqueue(t);
            }
            cout << "Enter value of right child for " << p->data << ": ";
            cin >> x;
            if(x != -1){
                t=new Node;
                t->data=x;
                t->lChild=t->rChild=0;
                p->rChild=t;
                q.enqueue(t);
            }

        }


    }
    void preOrder(Node *p){
            if(p != 0){
                cout << p->data << ' ';
                preOrder(p->lChild);
                preOrder(p->rChild);
            }
    }
};
int main(){
    Tree t;
    t.createTree();
    t.preOrder(t.root);
    
    return 0;
}