#include<iostream>
using namespace std;
bool BinarySearch(int *arr ,const int key){
    int l,h,m;
    l=0;
    h=(sizeof(arr)/sizeof(arr[0])) - 1;
    while(l<=h){
        m=(l+h)/2;
        if(arr[m] == key) return true;
        else if(key < arr[m]) h=m-1;
        else l= m +1;
    }
    return false;
}
bool RecursiveBinarySearch(int *arr,int l,int h,int key){
    if(l<=h){
        int m=(l+h)/2;
        if(key == arr[m]) return true;
        else if(key < arr[m]) return RecursiveBinarySearch(arr,l,m-1,key);
        else return RecursiveBinarySearch(arr,m+1,h,key);
    }
    return false;
}
int main(){
    int arr[]={1,2,3,4,6,7};
    if(RecursiveBinarySearch(arr,0,5,7)){
        cout << "Element found\n";
    }else{
        cout << "Element not found\n";
    }
    return 0;
}