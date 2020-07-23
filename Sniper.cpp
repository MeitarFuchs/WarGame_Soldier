#include "Sniper.hpp"

void Sniper::take_activity(std::pair<int,int> source,std::vector<std::vector<Soldier*>>& board){ // attack the strongest soldier that have the max
    //*******************find the strongest soldier from the ather group
        std::pair<int,int> toAttack;
        int max=std::numeric_limits<int>::min();
    toAttack.first=max;
    toAttack.second=max;
        int toAttackTeam;
        int tempHP;
        if(board[source.first][source.second]->player==1) //check which team I need to attack;
            toAttackTeam=2;
        else
            toAttackTeam=1;
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[i].size(); j++){
                if(board[i][j]!=nullptr && board[i][j]->player==toAttackTeam){

                    if(board[source.first][source.second]->HP>max){
                       max=board[source.first][source.second]->HP;
                        toAttack.first=i;
                        toAttack.second=j;
                    }
                }
            }
        }
    //******************* finish!!! to find the strongest soldier from the ather group

    if(toAttack.first == std::numeric_limits<int>::max())
        return; // if there is no someone like this- break

    int life =board[toAttack.first][toAttack.second]->HP;// the life that the attack soldier have before the hit
    int hit = board[source.first][source.second]->AP; // the hit point
    board[toAttack.first][toAttack.second]->HP=life-hit; // update the points life to attack soldier
    if(board[toAttack.first][toAttack.second]->HP<=0) {  // if he deid
        delete board[toAttack.first][toAttack.second];
        board[toAttack.first][toAttack.second]= nullptr;
    }
}

