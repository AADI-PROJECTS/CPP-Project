#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    string mfile,cfile;
    cout<<"Enter The Main File Name :";
    getline(cin,mfile);
    cout<<"Enter The Copy File Name :";
    getline(cin,cfile);
  //OPEN IN BINARY FORM
    ifstream mainfile(mfile,ios::binary);
    ofstream copyfile(cfile,ios::binary);
   //HERE WE CHECK THE FILE IS EMPTY OR NOT
    if(!mainfile || !copyfile){
        cerr<<"File Not Found";
        exit(1);
    }
    copyfile<<mainfile.rdbuf();
    cout<<"Data Transfer Sucessful";
    mainfile.close();
    copyfile.close();
    return 0;
}