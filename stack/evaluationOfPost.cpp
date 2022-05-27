#include<iostream>
using namespace std;
template <class T>
class Stack{
    T *arr;
    int capacity,top;
public:
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
bool isOperand(char ch){
    if(ch == '+' || ch == '-' || ch == '/' || ch == '*' || ch == '^') return false;
    return true;
}
int evaluate(char *postFix){
    Stack<int> s(100);
    int i,x,y,r;
    for(i=0 ; postFix[i] != '\0' ; i++){
        if(isOperand(postFix[i])) s.push(postFix[i] - '0');
        else{
            y=s.pop();
            x=s.pop();
            switch (postFix[i])
            {
            case '+':
                r=x+y;
                break;
            case '-':
                r=x-y;
                break;
            case '*':
                r=x*y;
                break;
            case '/':
                r=x/y;
                break;
            }
            s.push(r);
        }

    }
    return s.pop();
}
int main(){
    char postFix[]="35*62/+4-";
    int result=evaluate(postFix);
    cout << result << '\n';
    return 0;
}