#include<iostream>
using namespace std;
class Element{
    public:
        int i,j,e;
};
class Sparse{
    int m,n,num;
    Element *elements;
public:
    Sparse(int m,int n,int num){
        this->m=m;
        this->n=n;
        this->num=num;
        elements=new Element[num];
    }

    Sparse operator + (Sparse &s){
        if(n != s.n || m != s.m) return Sparse(0,0,0);
        Sparse *sum;
        sum=new Sparse(m,n,num + s.num);
        int i,j,k;
        i=j=k=0;
        while(i < num && j < s.num ){
            if(elements[i].i < s.elements[j].i) sum->elements[k++]=elements[i++];
            else if(elements[i].i > s.elements[j].i) sum->elements[k++]=s.elements[j++];
            else{
                if(elements[i].j < s.elements[j].j) sum->elements[k++]=elements[i++];
                else if(elements[i].j > elements[j].j) sum->elements[k++]=s.elements[j++];
                else{
                    sum->elements[k]=elements[i];
                    sum->elements[k++].e=elements[i++].e + elements[j++].e;
                } 
            }
        }
        for(;i<num;) sum->elements[k++]=elements[i++];
        for(;j<s.num;) sum->elements[k++]=s.elements[j++];
        sum->num=k;
        return *sum;
    }
    friend ostream& operator<<(ostream &os, Sparse &s){
            int k=0;
            for(int i=0 ; i< s.m ; i++){
                for(int j=0 ; j< s.n ; j++){
                    if(s.elements[k].i == i && s.elements[k].j == j) os << s.elements[k++].e << ' ';
                    else os << 0 << ' ';
                }
                cout << '\n';
            }
            return os;
    }
    friend istream& operator>>(istream &is, Sparse &s){
            for(int i=0 ; i< s.num ; i++){
                cin >> s.elements[i].i >> s.elements[i].j >> s.elements[i].e;
            }
            return is;
    }
};

int main(){
    Sparse s1(5,5,5);
    Sparse s2(5,5,5);
    cin >> s1;
    cin >> s2;
    cout << s1;
    cout << "-------------\n";
    cout << s2;
    cout << "-------------\n";
    Sparse sum=s1 + s2;
    cout << sum;
    return 0;
}