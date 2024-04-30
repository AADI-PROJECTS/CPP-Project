#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//GENERATE THE OTP
int gen(int size){
    srand(time(0));
    int m=10;
    for(int i=0;i<size-2;i++){
        m*=10;
    }
    return rand()%(9*m)+m;
}
//HERE WE CHECK THE OTP
void check(int s){
    int value;
    cout<<"Enter The OTP :";
    cin>>value;
    if(value!=s){
        cout<<"Invalid";
    }   
    else{
        cout<<"\t'SUCCESSFUL'";
    } 
}
int main(){
    int size;
    cout<<"Enter The Size of OTP :";
    cin>>size;
    cout<<"YOUR OTP :";
    cout<<gen(size)<<endl;
 int s=gen(size);
  check(s);
  return 0;                 
}