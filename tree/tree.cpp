#include<iostream>
#include<stack>
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
    int searchInorder(int inArray[], int inStart, int inEnd, int data){
    for (int i=inStart; i<=inEnd; i++){
        if (inArray[i] == data){
            return i;
        }
    }
    return -1;
}
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
    void inOrder(Node *p){
        if(p != 0){
            inOrder(p->lChild);
            cout << p->data << ' ';
            inOrder(p->rChild);
        }
    }
    void postOrder(Node *p){
        if(p != 0){
            inOrder(p->lChild);
            inOrder(p->rChild);
            cout << p->data << ' ';
        }
    }
    void iterativePreOrder(Node *p){
            stack<Node*> s;
            while(p != 0 || !s.empty()){
                if(p !=0){
                    cout << p->data << ' ';
                    s.push(p);
                    p=p->lChild;
                }else{                
                    p=s.top();
                    s.pop();
                    p=p->rChild;
                }
            }
    }
    void iterativeInOrder(Node *p){
            stack<Node*> s;
            while(p != 0 || !s.empty()){
                if(p !=0){
                    s.push(p);
                    p=p->lChild;
                }else{                
                    p=s.top();
                    s.pop();
                    cout << p->data << ' ';
                    p=p->rChild;
                }
            }
    }
    void levelOrder(Node *root){
            Node* p;
            Queue<Node*> q(100);
            cout << root->data << ' ';
            q.enqueue(root);
            while(!q.isEmpty()){
                p=q.dequeue();
                if(p->lChild){
                    cout << p->lChild->data << ' ';
                    q.enqueue(p->lChild);
                }
                if(p->rChild){
                    cout << p->rChild->data << ' ';
                    q.enqueue(p->rChild);
                }
            }
    }
    Node* generateFromTraversal(int *inorder, int *preorder, int inStart, int inEnd) {
    static int preIndex = 0;
 
    if (inStart > inEnd){
        return nullptr;
    }
 
    Node* node = new Node;
    node->data=preorder[preIndex++];
 
    if (inStart == inEnd){
        return node;
    }
 
    int splitIndex = searchInorder(inorder, inStart, inEnd, node->data);
    node->lChild = generateFromTraversal(inorder, preorder, inStart, splitIndex-1);
    node->rChild = generateFromTraversal(inorder, preorder, splitIndex+1, inEnd);
 
    return node;
}
    int countNodes(Node *root){
        if(root) return countNodes(root->lChild) + countNodes(root->rChild) + 1;
        return 0;
    }
    int countLeafNodes(Node *root){
        if(root){
            int x=countLeafNodes(root->lChild);
            int y=countLeafNodes(root->rChild);
            if(!root->lChild && !root->rChild) return x+y+1;
            return x+y;
            
        } 
        return 0;
    }
    int countDegTwoNodes(Node *root){
        if(root){
            int x=countDegTwoNodes(root->lChild);
            int y=countDegTwoNodes(root->rChild);
            if(root->lChild && root->rChild) return x+y+1;
            return x+y;
            
        } 
        return 0;
    }
    int countDegOneOrTwoNodes(Node *root){
        if(root){
            int x=countDegOneOrTwoNodes(root->lChild);
            int y=countDegOneOrTwoNodes(root->rChild);
            if(root->lChild || root->rChild) return x+y+1;
            return x+y;
            
        } 
        return 0;
    }
    int countDegOneNodes(Node *root){
        if(root){
            int x=countDegOneNodes(root->lChild);
            int y=countDegOneNodes(root->rChild);
            if(!root->lChild ^ !root->rChild) return x+y+1;
            return x+y;
            
        } 
        return 0;
    } 
};
int main(){
    // int preorder[]={1,2,4,5,3,6,7};
    // int inorder[]={4,2,5,1,6,3,7};
    // Tree bt;
    // Node* root=bt.generateFromTraversal(inorder, preorder, 0, sizeof(inorder)/sizeof(inorder[0])-1);
    // bt.preOrder(root);
    Tree bt;
    bt.createTree();
    cout << bt.countDegOneNodes(bt.root);
    return 0;
}