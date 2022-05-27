#include<iostream>
#include<cmath>
using namespace std;
class Term{
    public:
        int coef,exp;
};
class Polynomial{
    int n;
    Term *terms;
public:
    int evaluate(int x){
        int result=0;
        for(int i=0 ; i< n ; i++){
            result+=(terms[i].coef * pow(x,terms[i].exp));
        }
        return result;

    }

    Polynomial operator + (Polynomial &p){
        Polynomial np;
        np.terms=new Term[n + p.n];
        int i,j,k;
        i=j=k=0;
        while(i< n && j< p.n){
            if(terms[i].exp > p.terms[j].exp) np.terms[k++]= terms[i++];
            else if(terms[i].exp < p.terms[j].exp) np.terms[k++]=p.terms[j++];
            else{
                np.terms[k].exp=terms[i].exp;
                np.terms[k++].coef=terms[i++].coef + p.terms[j++].coef;
            }
        }
        for(;i< n;) np.terms[k++]=terms[i++];
        for(;j< p.n;) np.terms[k++]=p.terms[j++];
        np.n=k;
        return np;
    }
    friend istream& operator >> (istream &is,Polynomial &p){
        cout << "Enter number of terms: ";
        is >> p.n;
        p.terms=new Term[p.n];
        for(int i=0 ; i < p.n ; i++){
            cout << "Term " << i+1 << " :";
            is >> p.terms[i].coef >> p.terms[i].exp;
        }
        return is;
    }
    friend ostream& operator << (ostream &os, Polynomial &p){
        for(int i=0 ; i< p.n ; i++){
            os << p.terms[i].coef << "x^" << p.terms[i].exp;
            if(i != p.n -1) os << " + ";
        }
        os << '\n';
        return os;
    }
};
int main(){
    Polynomial p1;
    Polynomial p2;
    cin >> p1;
    cin >> p2;
    cout << p1;
    cout << "-----------\n";
    cout << p2;
    cout << "-----------\n";
    Polynomial p3=p1+p2;
    cout << p3;


    return 0;
}