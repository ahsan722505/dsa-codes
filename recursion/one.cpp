#include<iostream>
using namespace std;
void ascending(int n){
    if(n>0){
        ascending(n-1);
        cout << n << '\n';
    }
}
void descending(int n){
    if(n>0){
        cout << n << '\n';
        descending(n-1);
    }
}
int main(){
    ascending(10);
    cout << "-----------\n";
    descending(10);
    return 0;
}