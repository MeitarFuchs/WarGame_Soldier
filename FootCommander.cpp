#include "FootCommander.hpp"
#include "FootSoldier.hpp"

void FootCommander::take_activity(std::pair<int,int> source,std::vector<std::vector<Soldier*>>& board) {
    std::pair<int,int> toAttack = this->minDistance(source,board);//call the function that tell me who is tha closer to me that I will attack
    if(toAttack.first == std::numeric_limits<int>::max())
        return;  // if there is no someone like this- break
    int life =board[toAttack.first][toAttack.second]->HP;// the life that the attack soldier have before the hit
    int hit = board[source.first][source.second]->AP;// the hit point
    board[toAttack.first][toAttack.second]->HP=life-hit; // update the points life to attack soldier
    if(board[toAttack.first][toAttack.second]->HP<=0) {// if he deid
        delete board[toAttack.first][toAttack.second]; //delete
        board[toAttack.first][toAttack.second]= nullptr;//free
    }

    //now we active all the FS that they are in my team
    int myTeam  = board[source.first][source.second]->player; //check the number of FC team

    for(int i = 0; i<board.size(); i++){
        for(int j =0; j<board[i].size() ; j++){
            if(board[i][j]!=nullptr && board[i][j]->player==myTeam && dynamic_cast<FootSoldier*>(board[i][j]))
                board[i][j]->take_activity({i,j},board); // take active!!!!
        }
    }
}