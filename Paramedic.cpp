#include "Paramedic.hpp"

void Paramedic::take_activity(std::pair<int,int> source,std::vector<std::vector<Soldier*>>& board){

    int myTeam = board[source.first][source.second]->player;
    for(int i = source.first-1;i<=source.first+1;i++){
        for(int j = source.second-1;j<=source.second+1;j++){
            if(i>=0 && i<board.size() && j>=0 && j<board[i].size()) { // if the Paramedic is on the Kzavot so he dont have for exampel some one in the left because it is out of the board!!!
                if (board[i][j]!=nullptr && i!= source.first && j!=source.second && board[i][j]->player == myTeam)// if threr is a Soldier and it is not me and he is in my team
                    board[i][j]->HP = board[i][j]->maxHP;// give the full life
            }
        }
    }

}



