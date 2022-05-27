#include<iostream>
using namespace std;
template <class T>
class Stack{
    public:
    T *arr;
    int capacity,top;

    Stack(int size){
        capacity=size;
        top=-1;
        arr=new T[capacity];
    }
    bool isFull(){
        return top == (capacity - 1);
    }
    bool isEmpty(){
        return top == -1;
    }
    void push(T val){
        if(!isFull()) arr[++top]=val;
        else{
            cout << "Stack is full\n";
        }
    }
    T pop(){
        if(!isEmpty()) return arr[top--];
        cout << "Stack is empty\n";
        return -1;
    }
    T seeTop(){
        if(!isEmpty()) return arr[top];
        cout << "Stack is empty\n";
        return -1;
    }

};
template <class T2>
class Queue{
    Stack<T2> s1,s2;
    public:
    Queue():s1(100),s2(100){}
    void enqueue(T2 element){
        s1.push(element);
    }
    T2 dequeue(){
        int x=-1;
        if(s2.isEmpty()){
            if(s1.isEmpty()){
                cout << "Stack is empty\n";
                return x;
            }
            else{
                 while(!s1.isEmpty()) {
                     s2.push(s1.pop());
                     }
            }
        }

        x=s2.pop();
        return x;
    }

};
int main(){
    Queue<int> q;
    q.enqueue(1);
    q.enqueue(2);
    cout << q.dequeue() << '\n';
    cout << q.dequeue() << '\n';
    cout << q.dequeue() << '\n';
    q.enqueue(3);
    cout << q.dequeue() << '\n';
    return 0;
}