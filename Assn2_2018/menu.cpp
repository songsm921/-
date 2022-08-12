#include "menu.h"

void printMenu(){
    for(int i = 0 ; i<32 ; i++)
        cout<<"▨";
    cout<<"\n";
    cout<<"\t 1. 게임 시작 \t\t \n";
    cout<<"\t 2. 전적 및 승률 \t\t \n";
    cout<<"\t 3. 게임 종료 \t\t \n";
    for(int i = 0 ; i<32 ; i++)
        cout<<"▨";
    cout<<"\n"; 
    cout<<"메뉴 번호 입력 >>";      
}
int printMenuandGetStairs(){
    int stairNumber;
    bool checkStairNumber;
    do{
    cout<<"게임을 위한 계단의 개수를 입력<10~30> >>";
    cin>>stairNumber;
    if(stairNumber>= MIN_STAIRS && stairNumber <= MAX_STAIRS)
        checkStairNumber = true;
    else
        checkStairNumber = false;
    }while(!checkStairNumber);
    return stairNumber;
}