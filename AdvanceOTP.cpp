#include <iostream>
#include<vector>
#include<ctime>
using namespace std;
//HERE GENERATE THE RANDOM OTP
int otp(int lenght){
   srand(time(0));
    int m=10;
    for(int i=0;i<lenght-2;i++){
        m*=10;
    }
    return rand()%(9*m)+m;
}
//THIS FUNCTION FOR CONVERT THE INT VALUES TO STRING VALUES
void str(int ans){
    vector<string>vec={"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
    string words[4];
    for(int i=0;i<=ans;i++){
        int temp=ans%10;
        ans/=10;
        words[i]=vec[temp];
    }
    for(int i=3;i>=0;i--){
        cout<<words[i]<<" ";
    }
}
//THIS FUNCTION FOR CHECK
void check(int ans){
    int input;
    cout<<"Enter OTP!= ";
    cin>>input;
    if(input==ans){
        cout<<"Transation Successful";
    }
    else{
     cout<<"Enter Right OTP";
    }
}
int main() {
    
    int lenght=4;
    int ans=otp(lenght);
    str(ans);
    cout<<endl;
    check(ans);
    return 0;
}