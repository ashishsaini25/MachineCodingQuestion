

/* problem statement : https://workat.tech/machine-coding/practice/snake-and-ladder-problem-zgtac9lxwntg */
// Basic Version of Snake and Ladder Game
#include<bits/stdc++.h>
using namespace std;

class Snake {
    public:
      int head;
      int tail;
       Snake (){
          head = 0;
          tail = 0;
      }
      Snake (int head, int tail){
          head = head;
          tail = tail;
      }
};

class Ladder {
    public:
    int start;
    int end;
    Ladder (int start , int end){
        start = start;
        start = end;
    }
     Ladder (){
        start = 0;
        start = 0;
    }
};

class Player {
    public :
     int position;
     string name;
     Player (){
         name = "";
         position = 0;
     }
};

int rollDice (){
    return (rand() % 6) +1;
}

int checkSnakeOrLadder (int currPosition,vector<Snake>snakeArray, vector<Ladder>ladderArray){
    bool snakePresent = false, ladderPresent = false;
    int newPos=currPosition;
    for(int i =0 ;i<snakeArray.size();i++){
        if(snakeArray[i].head == currPosition) {
            snakePresent = true;
            newPos = snakeArray[i].tail;
        }
    }
    if (snakePresent) currPosition = checkSnakeOrLadder (newPos, snakeArray,ladderArray);
    
    for(int i =0 ;i<ladderArray.size();i++){
        if(ladderArray[i].start == currPosition) {
            ladderPresent = true;
            newPos = ladderArray[i].end;
        }
    }
    if (ladderPresent) currPosition = checkSnakeOrLadder (newPos, snakeArray,ladderArray);
    return currPosition;
}

bool play (int currentDiceValue,Player &x, vector<Snake>snakeArray,vector<Ladder>ladderArray){
    if(x.position+currentDiceValue>100) return false;
    int newPosition = x.position+currentDiceValue;
    x.position = checkSnakeOrLadder (newPosition,snakeArray,ladderArray);
    if (x.position  == 100) return true;
    return false;
}


int main (){
    int numberOfSnakes, numberOfLadder, numberOfPlayers;
    cin>>numberOfSnakes;
    vector<Snake> snakeArray(numberOfSnakes);
    for(int i=0;i<numberOfSnakes;i++){
        cin>>snakeArray[i].head>>snakeArray[i].tail;
    }
    cin>>numberOfLadder;
    vector<Ladder>ladderArray(numberOfLadder);
    for(int i=0;i<numberOfLadder;i++){
        cin>>ladderArray[i].start>>ladderArray[i].end;
    }
    cin>>numberOfPlayers;
    Player players[numberOfPlayers];
    for(int i =0;i<numberOfPlayers ;i++){
        cin>>players[i].name;
    }
    bool gameWon = false;
    while(!gameWon){
        int i =0;
        for(;i<numberOfPlayers;i++){
            int diceVal = rollDice ();
            int currPosition = players[i].position;
            bool isWon = play (diceVal,players[i],snakeArray,ladderArray);
            if(isWon){
                gameWon = true;
                break;
            }
            cout<<players[i].name <<" rolled a "<<diceVal <<" and moved from " <<currPosition <<" to "<<players[i].position <<"\n";
        }
        if (gameWon){
            cout<<players[i].name << " wins the game";
        }
    }
    
}