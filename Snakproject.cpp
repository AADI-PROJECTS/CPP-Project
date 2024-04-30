#include<iostream>
#include<windows.h>
#include<conio.h>
using namespace std;
enum operate{STOP= 0,RIGHT,LEFT,UP,DOWN};
operate dir;
bool gameplay;
const int height=20;
const int width=20;
int headsnak,headsnak1,foodh,foodw,total_score;
int taila[100],tailb[100];
int snak_size;
void work();
void output();
void input();
void fun();

int main()
{
    int start;
    cout<<"\t !enter the key for start game!"<<endl;
    cout<<"\t.............5................"<<endl;
    cin>>                start;
    if(start!=5){
    cout<<"\t......#Press 5 for Play#......";
        return 0;
    }
    cout<<"\t........#Game * start#........"<<endl;
    if(start==5){
        work();
        while(!gameplay){
            output();
             input();
             fun();
            //windose functio to slow the snak
            Sleep(120);
            //for remove the older screen
            system("cls");
            
        }

    }
    return 0;
    
}
void work(){
    gameplay=false;
    dir=STOP;
    headsnak=width/2;
    headsnak=height/2;
    foodh=rand()%width;
    foodw=rand()%height;
    total_score=0;
}
void output(){
    system("cls");
    //for upper border
    cout<<"\t\t";

    for(int i=0;i<width-8;i++){
        cout<<"||";
    }
    cout<<endl;
    //for print the snak food and side border score
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
          //for print left border
            if(j==0){
                cout<<"\t\t##";
            }
            if(i==headsnak && j==headsnak1){
                   cout<<"O";
            }
            else if(i==foodh && j==foodw){
                cout<<"*";
            }
            else{
                bool space=false;
               for(int k=0;k<snak_size;k++){
                if (taila[k]==j && tailb[k]==i){
                    cout<<"o";
                    space=true;
                }
               }
               //space 
               if(!space){
                cout<<" ";
               }
            }
            //for print right border
            if(j==width-1){
                cout<<"##";
            }
        }
        cout<<endl;
    }
    cout<<"\t\t";
    for(int i=0;i<width-8;i++){
        cout<<"||";
    }
    cout<<endl;
    cout<<"\t\t score"<<total_score<<endl;
    
}
void input(){
    if(_kbhit())
switch(getch())
 {
    case 'a':
    dir = LEFT;
    break;
    case 'd':
    dir = RIGHT;
    break;
    case 's':
    dir =DOWN;
    break;
    case 'w':
    dir=UP;
break;
    default:
        break;
 }
}
void fun()
{
    int prevx=taila[0];
    int prevy=tailb[0];
    int prev2x,prev2y;
    taila[0]=headsnak;
    tailb[0]=headsnak1;
    //for follow stor the lenght of the snak
    for(int i=1;i<snak_size;i++){
        prev2x=taila[i];
        prev2y=tailb[i];
        taila[i]=prevx;
        tailb[i]=prevy;
        prevx=prev2x;
        prevy=prev2y;
    }
    switch(dir)
    {
     case LEFT:
     headsnak--;
     break;
     case RIGHT:
     headsnak++;
     break;
     case UP:
     headsnak1--;
     break;
     case DOWN:
     headsnak1++;
     break;
     
    }
    // snak tuch the wall
    if(headsnak>= width){
        headsnak=0;
    }
    else if(headsnak < 0){
        headsnak=width-1;
    }
    if(headsnak1>= height){
        headsnak1=0;
    }
    else if (headsnak1>0){
        headsnak1=height-1;
    }
    //snak bits itself
    for(int i=0;i<snak_size;i++){
        if(taila[i]==headsnak && tailb[i]==headsnak1){
            gameplay=true;
        }
    }
    //snak eat food
    if(headsnak==foodh && headsnak1==foodw){
        total_score+=5;
        foodh=rand()%width;
        foodw=rand()%height;
        snak_size++;
    }
}