//
// Created by yirat on 19/05/2020.
//
#include "FootSoldier.hpp"

void FootSoldier::take_activity(std::pair<int,int> source,std::vector<std::vector<Soldier*>>& board){
    std::pair<int,int> toAttack = this->minDistance(source,board);
    if(toAttack.first == std::numeric_limits<int>::max()) return;
    int life =board[toAttack.first][toAttack.second]->HP;
    int hit = board[source.first][source.second]->AP;
    board[toAttack.first][toAttack.second]->HP=life-hit;
    if(board[toAttack.first][toAttack.second]->HP<=0) {
        delete board[toAttack.first][toAttack.second];
        board[toAttack.first][toAttack.second]= nullptr;
    }
}

