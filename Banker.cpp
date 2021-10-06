/*

******************************
******************************
**  THE BANKER CARD GAME    **
**      ባንከሩ የካርታ ጨዋታ      ** 
******************************
******************************
Code by:  Bereket Lemma
Language: C++

facebook -- @beckypac1996
twitter  -- @Berek_et
github   -- @Bereky
Telegram -- @Berek_et

*/

#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<dos.h>
#include<unistd.h>

using namespace std;

class Bank{
    public:
        int how,pick;
        char ch;
        void start();
        void generate();
        void go();
        void field();
        void howmuch();
        void pic();
        void restart();
        void check();
        void update();
}bank;

class Balance{
    public:
        int bal,re;    
        void recharge();
        void print();
}balance;

class Player_A{
    public: 
        int A_1,A_2,MIN,MAX;
        void input();
        void go();
        void won();
        void lost();
}a;

class Player_B{
    public:
        int B_1,B_2,MIN,MAX;
        void input();
        void go();
        void won();
        void lost();
}b;

class Player_C{
    public:
        int C_1,C_2,MIN,MAX;
        void input();
        void go();
        void won();
        void lost();
}c;

void Bank:: start(){
    //clrscr();
    system("cls");
    balance.recharge();
    //clrscr();
    system("cls");
    //balance.print();
    bank.generate();
    bank.field();
    cout<<"\n\nBet or Restart?";
    cout<<"\n\t1.Bet";
    cout<<"\n\t*.Quit Game";
    cout<<"\n\tOther key to Restart";
    cout<<"\n\nEnter: ";
    cin>>bank.ch;
    switch(bank.ch){
        case '1': bank.go(); break;
        case '*': cout<<"\n\nYou Quit the game, Bye!"; break;
        default : bank.start(); break;
    }  
}
void Bank:: generate(){
    cout<<"\nPress any key to generate card ";
    getch();
    cout<<"\nPlease wait...";
    a.input(); b.input(); c.input(); 
}
void Bank:: go(){
    //clrscr();
    system("cls");
    bank.field();
    bank.howmuch();
    cout<<"\nWhich player?";
    cout<<"\n\t1.Player 1";
    cout<<"\n\t2.Player 2";
    cout<<"\n\t3.Player 3";
    cout<<"\n\tEnter Player number: ";
    cin>>bank.ch;       
    switch(bank.ch){
        case '1': a.go(); break;
        case '2': b.go(); break;
        case '3': c.go(); break;
        default : "\n\nTry again!"; bank.go(); break;
    }
}
void Bank:: field(){
    system("cls");
	//clrscr();
    balance.print();
    cout<<"\n\n\t\tPLAYERS CARD";
cout<<"\n*****************************************";
    cout<<"\n\nPlayer 1\tPlayer 2\tPlayer 3 \n\n";
    cout<<a.MIN<<"  "<<a.MAX<<"\t\t"<<b.MIN<<"  "<<b.MAX<<"\t\t"<<c.MIN<<"  "<<c.MAX;
}
void Bank:: howmuch(){
    cout<<"\n\nFor how much birr: ";
    cin>>bank.how;
    if(bank.how>balance.bal){
        cout<<"\nBank balance not enough! Try Again!\n";
        bank.howmuch();
        }    
}
void Bank:: pic(){
    cout<<"\n\n\tYOUR LIFE CARD IS: ";
    //delay(2000);
    sleep(2);
    srand((int)time(0));
    bank.pick = (rand() % 13)+ 1;
    cout<<bank.pick<<"\n";
}
void Bank:: restart(){
    cout<<"\n\n\tPress Any key to Restart";
    getch();
    bank.start();    
}
void Bank:: check(){
    cout<<"\n\n\tContinue Bet or Restart?";
    cout<<"\n\t\t1.Continue";
    cout<<"\n\t\tOther key to restart";
    cout<<"\n\t\tEnter your choice: ";
    cin>>bank.ch;
    switch(bank.ch){
        case '1': bank.go(); break;
        default : bank.start(); break;
    }
}
void Bank:: update(){
    cout<<"\n\nLoading...";
    //delay(3000); // 3 seconds delay
    sleep(3);
}

void Balance:: recharge(){
    if(balance.bal==0){
        cout<<"\nBank is Empty, Recharege You Bank!"; 
        cout<<"\n\nEnter Amount: ";
        cin>>balance.re;
        if(balance.re<=0){           
            balance.recharge();
        }
        balance.bal = balance.re;
        bank.update();
    }
}
void Balance:: print(){
cout<<"*****************************************";
    cout<<"\nBANK BALANCE: "<<balance.bal<<" Birr";    
    cout<<"\n*****************************************";
}

void Player_A:: input(){
    srand((int)time(0));
    a.A_1 = (rand() % 13)+ 1;
    a.A_2 = (rand() % 13)+ 1;    
    if(a.A_1>a.A_2){
       a.MAX = a.A_1;
       a.MIN = a.A_2;
    }
    else if(a.A_1<a.A_2){
       a.MIN = a.A_1;
       a.MAX = a.A_2;
    }
    //delay(1000);
    sleep(1);
}
void Player_A:: go(){
    bank.pic();
    if(bank.pick>a.MIN && bank.pick<a.MAX){
        balance.bal -= bank.how;
        a.won();
        bank.restart(); 
    }
    else{
        balance.bal += bank.how;
        a.lost();
        bank.check();
    }   
}
void Player_A:: won(){
    cout<<"\tPlayer A won: "<<bank.how<<" Birr";
}
void Player_A:: lost(){
     cout<<"\tPlayer A lost: "<<bank.how<<" Birr";
}

void Player_B:: input(){
    srand((int)time(0));
    b.B_1 = (rand() % 13)+ 1;
    b.B_2 = (rand() % 13)+ 1;    
    if(b.B_1>b.B_2){
       b.MAX = b.B_1;
       b.MIN = b.B_2;
    }
    else if(b.B_1<b.B_2){
       b.MIN = b.B_1;
       b.MAX = b.B_2;
       }
       //delay(1000);
       sleep(1);
}      
void Player_B:: go(){
    bank.pic();
    if(bank.pick>b.MIN && bank.pick<b.MAX){
        balance.bal -= bank.how;
        b.won();
        bank.restart(); 
    }
    else{
        balance.bal += bank.how;
        b.lost();
        bank.check();
    }
}
void Player_B:: won(){
    cout<<"\tPlayer B won: "<<bank.how<<" Birr";
}
void Player_B:: lost(){
     cout<<"\tPlayer B lost: "<<bank.how<<" Birr";
}

void Player_C:: input(){
    srand((int)time(0));
    c.C_1 = (rand() % 13)+ 1;
    c.C_2 = (rand() % 13)+ 1;    
    if(c.C_1>c.C_2){
       c.MAX = c.C_1;
       c.MIN = c.C_2;
    }
    else if(c.C_1<c.C_2){
       c.MIN = c.C_1;
       c.MAX = c.C_2;
       }
       //delay(1000);
       sleep(1);
}
void Player_C:: go(){
    bank.pic();
    if(bank.pick>c.MIN && bank.pick<c.MAX){
        balance.bal -= bank.how;
        c.won();
        bank.restart(); 
    }
    else{
        balance.bal += bank.how;
        c.lost();
        bank.check();
    }    
}
void Player_C:: won(){
    cout<<"\tPlayer C won: "<<bank.how<<" Birr";
}
void Player_C:: lost(){
     cout<<"\tPlayer C lost: "<<bank.how<<" Birr";
}
        
int main(){
	system("cls");
    //clrscr();
    bank.start();
    getch();
    return 0;
}






