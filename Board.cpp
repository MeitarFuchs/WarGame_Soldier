#include "Board.hpp"
#include <iostream>
using namespace std;

bool WarGame::Board::has_soldiers(uint player_number) const{// if there is a soldier from the get group

   for(int i =0;i<board.size();i++){
       for(int j =0 ;j <board[i].size();j++){
           if(board[i][j]!=nullptr && board[i][j]->player==player_number) return true;
       }
   }
   return false;
}

void WarGame::Board::move(uint player_number, pair<int,int> source, MoveDIR direction){
    if(source.first<0 || source.first>=board.size()|| source.second<0 || source.second>=board[source.first].size()) {
        throw invalid_argument("Action out of Board");
    }

    // Action IN of Board
    Soldier* mover= (*this)[source];
    std::pair<int,int> target;

    switch(direction){
        case Up:
            target.first=source.first+1;
            target.second=source.second;
            break;
        case Down:
            target.first=source.first-1;
            target.second=source.second;
            break;
        case Left:
            target.first=source.first;
            target.second=source.second-1;
            break;
        case Right:
            target.first=source.first;
            target.second=source.second+1;
            break;
    }

    if(target.first<0 || target.first>=board.size()|| target.second<0 || target.second>=board[target.first].size()) { // if the new place is out of the board
        throw invalid_argument("Action out of Board");
    }

    if(mover == nullptr || mover->player!=player_number || (*this)[target]!= nullptr){ // if the soldier that i want to move null or he is no in the team that i want or there is alredy a soldier in the dest place
        throw invalid_argument("Cant move");
    }

    (*this)[target]=mover;//move to the new place
    (*this)[source]=nullptr;//free the src place
    mover->take_activity(target,board);// after you move take an action!!!

}


Soldier* WarGame::Board::operator[](std::pair<int,int> location) const{
    return this->board[location.first][location.second];
}

Soldier*& WarGame::Board::operator[](std::pair<int,int> location){
    return this->board[location.first][location.second];
}

