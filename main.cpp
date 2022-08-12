#include <iostream>
#include "menu.h"
#include "game.h"
#include <stdlib.h>
#include <algorithm>
using namespace std;
void printGameInterface_Stairs(gameInterface *interface){
    interface->printStairNumber();
    interface->printWinStatus();
    interface->locatePlayers();
    interface->printStairs();
}
void printUserComputerPick(pair<int,int> user, pair<int,int> computer){
    cout<<"1. Sicssors 2. Rock 3. Paper\n";
    cout<<"User pick:"<<user.first<<" "<<user.second<<"\n";
    cout<<"Computer Pick:"<<computer.first<<" "<<computer.second<<"\n";
    cout<<"Select your final pick:"<<user.first<<" "<<user.second<<">>";
}
void printStat(int playerWin, int computerWin){
    float winPercentage;
    if(playerWin == 0 && computerWin ==0)
        winPercentage = 0;
    else
        winPercentage = 100*playerWin/(playerWin+computerWin);
    cout<<"Player: "<<playerWin<<"\n"<<"Computer: "<<computerWin<<"\n";
    cout<<"Percentage: "<<winPercentage<<"\n";
}
bool checkUserFinalPick(pair<int,int> userPick,int finalPick){
    bool value;
    if(userPick.first == finalPick)
        value = true;
    else if(userPick.second == finalPick)
        value = true;
    else
        value = false;
    return value;
}
int main(){
    int menuUserSelect, stairNumber;
    int isUserWin;
    bool gameContinue;
    bool checkUserRSP;
    pair <int,int> selectRSP;
    int userFinalPick,computerFinalPick,userWinDrawLose;
    int playerWinCount = 0;
    int computerWincount = 0;
    while(1){
        printMenu();
        cin>>menuUserSelect;
        switch(menuUserSelect){
            case 1:{
                gameContinue = true;
                stairNumber = printMenuandGetStairs();
                system("clear");
                gameInterface objectGame(stairNumber);
                objectGame.fillStairs();
                while(gameContinue){
                    pair<bool,int> gameinfo;
                    bool isValid;
                    printGameInterface_Stairs(&objectGame);
                    do{
                    cout<<"\n 가위<1>, 바위<2>, 보<3> >> ";
                    cin>>selectRSP.first>>selectRSP.second;
                    if(selectRSP.first == selectRSP.second)
                        checkUserRSP = false;
                    else if(selectRSP.first >3 || selectRSP.first < 1)
                        checkUserRSP = false;
                    else if(selectRSP.second >3 || selectRSP.second < 1)
                        checkUserRSP = false;
                    else
                        checkUserRSP = true;
                    }while(!checkUserRSP);
                    objectGame.generateComputerPick();
                    system("clear");
                    printUserComputerPick(selectRSP,objectGame.getComputerPick());
                    do{
                        cin>>userFinalPick;
                        isValid = checkUserFinalPick(selectRSP,userFinalPick);
                        if(isValid == false)
                            cout<<"Select Proper option\n";
                    }while(!isValid);
                    objectGame.generateFinalComputerPick(selectRSP);
                    userWinDrawLose = objectGame.judgeOneGame(userFinalPick);
                    gameinfo = objectGame.isGameOver();
                    if(gameinfo.first == true){
                        isUserWin = gameinfo.second;
                        gameContinue = false;
                    }
                    else{
                        gameContinue = true;
                        objectGame.calculateLocation(userWinDrawLose);
                    }
                    
                }
                if(isUserWin){
                    playerWinCount++;
                    cout<<"Player Win!\n";
                }
                else{
                    computerWincount++;
                    cout<<"Computer Win!\n";
                }
                break;
            }
       
            case 2:{
                printStat(playerWinCount, computerWincount);
                break;
            }
            case 3:{
                return 0;
            }
        }
    }
    
}
