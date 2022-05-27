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
int findLength(char *str){
    int length=0;
    for(int i=0 ; str[i] != '\0' ; i++) length++;
    return length;
}
bool isOperand(char ch){
    if(ch == '+' || ch == '-' || ch == '/' || ch == '*' || ch == '^') return false;
    return true;
}
int pre(char ch){
    if(ch == '-' || ch == '+') return 1;
    if(ch == '/' || ch == '*') return 2;
    if(ch == '^') return 3;
    return 0;
}
char* inToPost(char *infix){
    Stack<char> s(100);
    char *postFix=new char[findLength(infix) +1];
    int i=0,j=0;
    while(infix[i] != '\0'){
        if(infix[i] == '('){
            s.push(infix[i++]);
            continue;
        }
        if(infix[i] == ')'){
            while(s.seeTop() != '('){
                postFix[j++]=s.pop();
            }
            s.pop();
            i++;
            continue;
        }
        if(isOperand(infix[i])){
            postFix[j++]=infix[i++];
            continue;
        }
        if(pre(infix[i]) > pre(s.seeTop())){
            s.push(infix[i++]);
            continue;
        }
        postFix[j++]=s.pop();
    }
    while(!s.isEmpty()){
        postFix[j++]=s.pop();
    }
    return postFix;

}
int main(){
    char infix[]="(3^2*5)/(3*2-3)+5";
    char *postFix=inToPost(infix);
    cout << postFix;
    return 0;
}