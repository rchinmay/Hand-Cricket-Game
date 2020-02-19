#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <thread>
#include <chrono>
using namespace std;
int Toss(){
    char input_toss, user_input_toss=0;
    do
    {
        cout<<"Enter H for Heads and T for Tails"<<endl;
        cin>>input_toss;
    }while(input_toss!='H' && input_toss!='T' && input_toss!='h' && input_toss!='t');
    //cin.ignore();
    /*The character c stores input given by user either H of T until it is a 
    valid input. */
    if(input_toss=='h' || input_toss=='H')
        user_input_toss=0;
    if(input_toss=='t' || input_toss=='T')
        user_input_toss=1;
    int bat_bowl=0;
    int cpu_input_toss=rand()%2;
    if(cpu_input_toss == user_input_toss){
        cout<<"Congrats...You have won the toss. Would you like to Bat or Bowl?"<<endl;
        do{
            cout<<"Enter 1 to BAT and 2 to Bowl:"<<endl;
            cin>>bat_bowl;
        }while(bat_bowl>2 || bat_bowl<1);
    }
    else{
        cout<<"CPU won the toss."<<endl;
        bat_bowl=rand()%2 + 1;
    }
    if(bat_bowl==1)
        cout<<("You are batting first.")<<endl;
    else
        cout<<("CPU is batting first.")<<endl;
    return bat_bowl;
}
long long int Batting(int balls){
    long long int score=0;
    while(balls>0){
        cout<<"Balls left: "<<balls<<endl;
        cout<<"Your Score: "<<score<<endl;
        int run=0;
        do{
            cout<<"Enter the runs (an integer in set{0,1,2,3,4,5,6}) which you want to hit: ";
            cin>>run;
        }while(run<0 || run>6);
        int cpu_run=rand()%7;
        if(cpu_run==run){
            cout<<"You are out!!!"<<endl;
            break;
        }
        else{
            cout<<"Your input: "<<run<<endl;
            cout<<"CPU input: "<<cpu_run<<endl;
            score+=run;
        }
        balls--;
    }
    return score;
}
long long int Bowling(int balls){
    long long int score=0;
    while(balls>0){
        cout<<"Balls left: "<<balls<<endl;
        cout<<"CPU Score: "<<score<<endl;
        int run=0;
        do{
            cout<<"Enter the runs (an integer in set{0,1,2,3,4,5,6}) which you want to bowl: ";
            cin>>run;
        }while(run<0 || run>6);
        int cpu_run=rand()%7;
        if(cpu_run==run){
            cout<<"CPU is out!!!"<<endl;
            break;
        }
        else{
            cout<<"Your input: "<<run<<endl;
            cout<<"CPU input: "<<cpu_run<<endl;
            score+=cpu_run;
        }
        balls--;
    }
    return score;
}
int main(){
    cout<<"WELCOME To"<<endl;
    cout<<"HAND CRICKET"<<endl;
    cout<<"-----------------------------------------------------------------"<<endl;
    cout<<"-----------------------------------------------------------------"<<endl;
    srand(time(NULL));
    cout<<"Choose the number of balls in the match:";
    int overs;
    cin>>overs;
    cout<<endl;
    cout<<"-----------------------------------------------------------------"<<endl;
    cout<<"Its TOSS time"<<endl;
    int toss_result=Toss();
    cout<<"-----------------------------------------------------------------"<<endl;
    int result=2;
    do{
        cout<<"Get Ready for the match"<<endl;
        int counter=5;
            cout<<"Time Remaining: ";
        while(counter>=0){
            cout<<counter<<" ";
            std::this_thread::sleep_for (std::chrono::milliseconds(200));
            counter--;
        }
        cout<<"-----------------------------------------------------------------"<<endl;
        cout<<"-----------------------------------------------------------------"<<endl;
        cout<<"ITS MATCH TIME"<<endl;
        long long int score=0, cpu_score=0;
        if(toss_result==1){
            //The user is batting.
            score= Batting(overs);
            cout<<"Target for CPU: "<<score+1<<endl;
            cpu_score= Bowling(overs);
        }
        else{
            cpu_score= Bowling(overs);
            cout<<"Target for You: "<<cpu_score+1<<endl;
            score= Batting(overs);
        }
        if(score>cpu_score){
            result=0;
            cout<<"Congrats... YOU WIN!!!"<<endl;
        }
        else if(cpu_score>score){
            result=1;
            cout<<"YOU LOSE... Better Luck Next Time!!!"<<endl;
        }
        cout<<"-----------------------------------------------------------------"<<endl;
        cout<<"-----------------------------------------------------------------"<<endl;
        cout<<"Match Summary"<<endl;
        cout<<"Toss Result: "<<((toss_result==1)?("You batted first"): ("CPU batted first"))<<endl;
        cout<<"Your Score: "<<score<<endl;
        cout<<"CPU Score: "<<cpu_score<<endl;
        cout<<"RESULT: ";
        if(result==0){
            cout<<"You WON by "<<(score-cpu_score)<<" runs"<<endl;
        }
        else if(result==1){
            cout<<"You Lost by "<<(cpu_score-score)<<" runs"<<endl;
        }
        else{
            cout<<"Match Tied!!!"<<endl;
            cout<<"SUPER BALL!!!!"<<endl;
            overs=1;
        }
    }while(result==2);
    return 0;
}