#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
int num1,num2;
cout<<"Enter The First Value =";
cin>>num1;
char task;
cout<<"Enter The Task ('+','-','*','/','%') =";
cin>>task;
cout<<"Enter The Second Value =";
cin>>num2;
//HERE WE PERFORM THE TASK
switch(task)
{
    case '+':
    cout<<"After The Addition ="<<num1+num2;
    break;
    case '-':
    cout<<"After The Subtraction ="<<num1-num2;
    break;
    case '*':
    cout<<"After The Multiplycation ="<<num1*num2;
    break;
    case '/':
    if(num2==0){
        cout<<"Devition is Not Allow by =0"<<endl;
        return 1;
    }
    cout<<"After The Devition="<<num1/num2;
    break;
    case '%':
    if(num2==0){
        cout<<"This Task is Not Valid="<<endl;
        return 1;
    }
    cout<<"After The Persent of Value="<<num1%num2;
    break;
    default:
    cout<<"Enter The Give Operaters Like '+'...'-'...'*'etc..!";
    break;
}
return 0;
}