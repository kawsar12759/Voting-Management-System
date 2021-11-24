
#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
using namespace std;
queue<int>line[3];
int waiting[4], cnt[4][100], n, x, total[100];
vector<string>name;
void stand_In_Line(){
    //system("cls");
    system("Color 9");
    cout << "\n\n\t\t\tHOW MANY PEOPLE WENT TO GIVE VOTE : ";
    int a;
    cin>>a;
    cout << "\t\t\tWhich Line They Choose : ";
    int b;
    cin>>b;
    waiting[b]+=a;
    system("cls");
}
void cast_Vote(){
    system("cls");
    system("Color 1");
    cout<<"\n\n\t\t\tEnter The Line Number Of The Voter : ";
    int a;
    cin>>a;
    if(!waiting[a]){
        cout<<"\t\t\tSorry, the line is empty \n";
        return;
    }
    int i=1;
    for(auto x:name) cout<<"\t\t\tTo Vote For "<<x<<" Press "<<i++<<"\n";
    int b;
    cout<<"\t\t\tInput Choice : ";
    cin>>b;
    cnt[a][b]++;
    waiting[a]--;
    total[b]++;
    system("cls");
}
void display(){
    system("Color 8");
    int i=1;
    cout<<"\n\n";
    for(auto x:name) cout<<"\t\t\tTotal Vote For "<<x<<" = "<<total[i]<<"[Line 1:"<<cnt[1][i]<<"; Line 2:"<<cnt[2][i]<<"; Line 3:"<<cnt[3][i++]<<"]\n";
    for(int i=1; i<4; i++) cout<<"\t\t\t"<<waiting[i]<<" Voters Are Waiting In Line "<<i<<"\n";
    cout<<"\n\t\t\tPress Any Key to Return to Menu ";
    getch();
    system("cls");
}
void pre(){
    system("Color 9");
    cout << "\n\n\n\t\t        ==================================";
    cout << "\n\t\t\t     VOTING MANAGEMENT SYSTEM";
    cout << "\n\t\t        ==================================";
    cout<<"\n\n\t\t\tEnter Total Number of Contestant: ";
    cin>>n;
    cout<<"\t\t\tEnter Their Names\n";
    for(int i=1; i<=n; i++){
        cout<<"\t\t\t"<<i<<"# ";
        string t;
        cin>>t;
        name.push_back(t);
    }
    system("cls");
}
void leading(){
    int maxx=0,wh=-1,coun=0;
    for(int i=0; i<=n; i++){
        if(total[i]>maxx){
            maxx=total[i];
            wh=i;
        }
    }
    for(int i=0; i<=n; i++){
        if(total[i]==maxx){
            coun++;
        }
    }
    if(maxx==0)
    {
        cout<<"\n\n\t\t\tNo Voter Has Voted Yet";
    }
    else if(coun>1)
    {
        cout<<"\n\n\t\t\t"<<coun<<" Contestant Are Leading With The Same Number of Vote ("<<maxx<<" vote)";
    }
    else{
        cout<<"\n\n\t\t\t"<<name[--wh]<<" is The Leading Contestant With A Total of "<<maxx<<" vote";
    }
    cout<<"\n\n\t\t\tPress Any Key to Return to Menu ";
        getch();
    system("cls");
}
int main(){
    if(!x)pre();
    system("Color 5");
    cout << "\n\n\n\t\t\t========================";
    cout << "\n\t\t\tVOTING MANAGEMENT SYSTEM";
    cout << "\n\t\t\t========================";
    cout << "\n\n\t\t\t1. ADD NEW VOTER\n";
    cout << "\t\t\t2. ENTER FOR VOTE\n";
    cout << "\t\t\t3. DISPLAY CURRENT LIST\n";
    cout << "\t\t\t4. CHECK LEADING CONTESTANT\n";
    cout << "\t\t\t0. EXIT \n";
    cout << "\t\t\tEnter your choice: ";
    cin>> x;
    switch(x){
    case 1:
        stand_In_Line();
        break;
    case 2:
        cast_Vote();
        break;
    case 3:
        display();
        break;
    case 4:
        leading();
        break;
    case 0:
        cout << "\t\t\tTHANKS for VOTING\n";
        exit(1);
    default:
        cout << "\t\t\tOPPS! TRY AGAIN!";
        main();
    }
    if(x!=0)main();
}
