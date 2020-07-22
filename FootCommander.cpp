//
// Created by yirat on 19/05/2020.
//

#include "FootCommander.hpp"
#include "FootSoldier.hpp"

void FootCommander::take_activity(std::pair<int,int> source,std::vector<std::vector<Soldier*>>& board) {
    std::pair<int,int> toAttack = this->minDistance(source,board);
    if(toAttack.first == std::numeric_limits<int>::max()) return;
    int life =board[toAttack.first][toAttack.second]->HP;
    int hit = board[source.first][source.second]->AP;
    int check  = board[source.first][source.second]->player;
    board[toAttack.first][toAttack.second]->HP=life-hit;
    if(board[toAttack.first][toAttack.second]->HP<=0) {
        delete board[toAttack.first][toAttack.second];
        board[toAttack.first][toAttack.second]= nullptr;
    }
    for(int i = 0; i<board.size(); i++){
        for(int j =0; j<board[i].size() ; j++){
            if(board[i][j]!=nullptr && board[i][j]->player==check && dynamic_cast<FootSoldier*>(board[i][j]))
                board[i][j]->take_activity({i,j},board);
        }
    }

}