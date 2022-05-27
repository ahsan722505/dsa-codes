#include<iostream>
using namespace std;
int sum(int n){
    if(n==0) return 0;
    else return sum(n-1) + n;
}
int main(){
    cout << sum(3) << '\n';
    return 0;
}
// sum of n natural numbers using recursion