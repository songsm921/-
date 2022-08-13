#include <iostream>
#include<cstdlib>
#include<ctime>
#include <string>
#include <algorithm>
using namespace std;

class gameInterface{
    public:
        gameInterface(int number);
        void printStairNumber();
        void printWinStatus();
        void fillStairs();
        void locatePlayers();
        void printStairs();
        void generateComputerPick();
        pair<int,int> getComputerPick();
        void generateFinalComputerPick(pair<int,int> userPick);
        int judgeOneGame(int userFinalPick);
        pair<bool,int> isGameOver();
        void calculateLocation(int whoWin);
    private:
        int numberofStairs;
        bool isEven;
        int numberWinPlayer;
        int numberWinComputer;
        int boardRow;
        int boardColumn;
        int computerFinalPick;
        pair<int,int> playerPos;
        pair<int,int> computerPos;

        pair<int,int> computerPick;
        string** stairs;
};
