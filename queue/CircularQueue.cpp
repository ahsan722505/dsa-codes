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
    int dequeue(){
        int x=-1;
        if(!isEmpty()){
            front = (front + 1) % size;
            x=arr[front];
        }else{
            cout << "Queue is empty\n";
        }
        return x;
    }
};
int main(){
    Queue<int> q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    cout << q.dequeue() << '\n';
    cout << q.dequeue() << '\n';
    cout << q.dequeue() << '\n';
    cout << q.dequeue() << '\n';
    cout << q.dequeue() << '\n';
    q.enqueue(8);
    cout << q.dequeue() << '\n';
    return 0;
}