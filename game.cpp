#include "game.h"

gameInterface::gameInterface(int number){
    numberofStairs = number;
    int checkEven = numberofStairs%2;
    if(checkEven)
        isEven = false;
    else
        isEven = true;
    if(isEven){
        boardRow = numberofStairs/2 + 1;
    }
    else{
        boardRow = numberofStairs/2 +2;
    }
    stairs = new string*[boardRow];
    boardColumn = numberofStairs + 1;
    for(int i = 0 ; i <boardRow;i++){
        stairs[i] = new string[boardColumn];
    }
    numberWinComputer = 0;
    numberWinPlayer = 0;
    playerPos.first = 0;
    playerPos.second = 0;
    computerPos.first = 0;
    computerPos.second = boardColumn -1;
}
void gameInterface::printStairNumber(){
    cout<<"총 계단수: "<<numberofStairs<<"\n";
}

void gameInterface::printWinStatus(){
    cout<<"PLAYER: \t◓"<<"<"<<numberWinPlayer<<">\n";
    cout<<"COMPUTER: \t◒"<<"<"<<numberWinComputer<<">\n";
    cout<<"\n";
}
void gameInterface::fillStairs(){
    for(int i = 0;i<boardColumn;i++)
        stairs[0][i] = ' ';
    for(int i = 1;i<boardRow;i++)
    {
        int j;
        for(j = 0;j<i ;j++){
            stairs[i][j] = "▧";
        }
        for(int k = 0;k<(numberofStairs-1)-(2*(i-1));k++){
            stairs[i][j] = " ";
            j++;
        }
        for(j=j;j<boardColumn;j++){
            stairs[i][j] = "▧";
        }
    }
}
void gameInterface::locatePlayers(){
    if(playerPos == computerPos){
        stairs[playerPos.first][playerPos.second] = "⊕";
        return;
    }
    stairs[playerPos.first][playerPos.second] = "◓";
    stairs[computerPos.first][computerPos.second] = "◒";
}
void gameInterface::printStairs(){
    for(int i = 0;i<boardRow;i++)
    {
        for(int j = 0; j<boardColumn;j++)
            cout<<stairs[i][j];
        cout<<endl;
    }
}
void gameInterface::generateComputerPick(){
    srand((unsigned int)time(NULL));
    do{
    computerPick.first = rand()%3+1;
    computerPick.second =rand()%3+1;
    }while(computerPick.first == computerPick.second);
    if(computerPick.first> computerPick.second){
        int temp = computerPick.first;
        computerPick.first = computerPick.second;
        computerPick.second = temp;
    }
}
pair<int,int> gameInterface::getComputerPick(){
    return computerPick;
}
void gameInterface::generateFinalComputerPick(pair<int,int> userPick){
    int finalPick;
    if(userPick == computerPick){
        if(computerPick.first == 1){
            if(computerPick.second == 2){
                finalPick = 2;
            }
            else if(computerPick.second == 3){
                finalPick = 1;
            }
        }
        else if(computerPick.first == 2){
            if(computerPick.second == 3){
                finalPick = 3;
            }
        }
    }
    else{
        srand((unsigned int)time(NULL));
        if(rand()%2 == 0){
            finalPick = computerPick.first;
        }
        else{
            finalPick = computerPick.second;
        }
    }
    computerFinalPick = finalPick;
}
int gameInterface::judgeOneGame(int userFinalPick){
    int userWinDrawLose;
    if(userFinalPick == 1){
        switch(computerFinalPick){
            case 1: userWinDrawLose = 1;
            break;
            case 2: userWinDrawLose = 2;
            break;
            case 3: userWinDrawLose = 0;
        }
    }
    else if(userFinalPick == 2){
        switch(computerFinalPick){
            case 1: userWinDrawLose = 0;
            break;
            case 2: userWinDrawLose = 1;
            break;
            case 3: userWinDrawLose = 2;
        }
    }
    else if(userFinalPick == 3){
        switch(computerFinalPick){
            case 1: userWinDrawLose = 2;
            break;
            case 2: userWinDrawLose = 0;
            break;
            case 3: userWinDrawLose = 1;
        }
    }
    if(userWinDrawLose == 0)
        numberWinPlayer++;
    else if(userWinDrawLose == 2)
        numberWinComputer++;
    return userWinDrawLose;

}
pair<bool,int> gameInterface::isGameOver(){
    pair<bool,int> gameInfo;
    if(numberWinPlayer == numberofStairs){
        gameInfo.first = true;
        gameInfo.second = 1;
    }
    else if(numberWinComputer == numberofStairs){
        gameInfo.first = true;
        gameInfo.second = 0;
    }
    else{
        gameInfo.first = false;
        gameInfo.second = -1;
    }
    return gameInfo;
}
void gameInterface::calculateLocation(int whoWin){
    if(whoWin == 0){
        stairs[playerPos.first][playerPos.second] = " ";
        switch(isEven){
            case true:{
                if(playerPos.second < numberofStairs / 2)
                {
                    playerPos.first++;
                    playerPos.second++;
                }
                else{
                    playerPos.first--;
                    playerPos.second++;
                }
                break;
            }
            case false:{
                if(playerPos.second < numberofStairs / 2)
                {
                    playerPos.first++;
                    playerPos.second++;
                }
                else if(playerPos.second == numberofStairs / 2)
                    playerPos.second++;
                else{
                    playerPos.first--;
                    playerPos.second++;
                    
                }
            }
        }
    }
    else if(whoWin == 2){
        stairs[computerPos.first][computerPos.second] = " ";
        switch(isEven){
            case true:{
                if(computerPos.second <= numberofStairs / 2)
                {
                    computerPos.first--;
                    computerPos.second--;
                }
                else{
                    computerPos.first++;
                    computerPos.second--;
                }
                break;
            }
            case false:{
                if(computerPos.second <= numberofStairs / 2)
                {
                    computerPos.first--;
                    computerPos.second--;
                }
                else if(computerPos.second == numberofStairs / 2 + 1)
                    computerPos.second--;
                else{
                    computerPos.first++;
                    computerPos.second--;
                }
            }
        }
    }
    return;
}
