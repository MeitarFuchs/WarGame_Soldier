#include "FootSoldier.hpp"

void FootSoldier::take_activity(std::pair<int,int> source,std::vector<std::vector<Soldier*>>& board){
    std::pair<int,int> toAttack = this->minDistance(source,board);//call the function that tell me who is tha closer to me that I will attack
    if(toAttack.first == std::numeric_limits<int>::max())
        return; // if there is no someone like this- break

    int life=board[toAttack.first][toAttack.second]->HP; // the life that the attack soldier have before the hit
    int hit = board[source.first][source.second]->AP; // the hit point
    board[toAttack.first][toAttack.second]->HP=life-hit; // update the points life to attack soldier
    if(board[toAttack.first][toAttack.second]->HP<=0) { // if he deid
        delete board[toAttack.first][toAttack.second]; // delete the soldier!!!!
        board[toAttack.first][toAttack.second]= nullptr; //free
    }
}

