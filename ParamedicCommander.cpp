#include "ParamedicCommander.hpp"
#include "Paramedic.hpp"

void ParamedicCommander::take_activity(std::pair<int, int> source, std::vector<std::vector<Soldier *> > &board) {
    int check  = board[source.first][source.second]->player;
    for(int i = source.first-1;i<=source.first+1;i++){
        for(int j = source.second-1;j<=source.second+1;j++){
            if(i>=0 && i<board.size() && j>=0 && j<board[i].size()) {
                if (board[i][j]!=nullptr && i != source.first && j != source.second && board[i][j]->player == check)
                    board[i][j]->HP = board[i][j]->maxHP;
            }
        }
    }
    for(int i = 0; i<board.size(); i++){
        for(int j =0; j<board[i].size() ; j++){
            if(board[i][j]!=nullptr && board[i][j]->player==check && dynamic_cast<Paramedic*>(board[i][j]))
                board[i][j]->take_activity({i,j},board);
        }
    }
}