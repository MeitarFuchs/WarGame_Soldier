
#pragma once
#include <vector>
#include <utility>
#include <limits>
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <iomanip>


class Soldier{
public:
    int HP;
    int player;
    const int maxHP;
    const int AP;


    Soldier(int HP, int player,int AP,int maxHP): HP(HP), player(player) , AP(AP) ,maxHP(maxHP) {}

    virtual ~Soldier(){

    }

    virtual void take_activity(std::pair<int,int> source,std::vector<std::vector<Soldier*>>& board)=0;

    std::pair<int,int> minDistance (std::pair<int,int> source,const std::vector<std::vector<Soldier*>>& board){
        std::pair<int,int> ans;
        int min=std::numeric_limits<int>::max();
        ans.first=min;
        ans.second=min;
        int toAttack;
        double distance;
        if(board[source.first][source.second]->player==1) toAttack=2; //check who i need to attack;
        else toAttack=1;
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[i].size(); j++){
                if(board[i][j]!=nullptr && board[i][j]->player==toAttack){
                    distance=sqrt(pow(source.first-i,2)+pow(source.second-j,2));
                    if(distance<min) {
                        min=distance;
                        ans.first=i;
                        ans.second=j;
                    }
                }
            }
        }
     //   print_board(board,source);
        return ans;
    }
//    void print_board( const std::vector<std::vector<Soldier*>> &board,std::pair<int,int> source){
//         std::cout << std::fixed << std::setprecision(2) << std::setfill('0');
//        for(int i=0; i<board.size();i++){
//            for(int j=0; j< board.size();j++){
//                if( i == source.first && j == source.second){
//                     std::cout << "||" << std::setw(9) << "!!!!!!!!!";
//                }
//                else if (board[i][j]==0)
//                {
//                     std::cout << "||" << std::setw(9)<< "000000000";
//                }
//                else
//                {
//                     std::cout << "||" << std::setw(9)<<  board[i][j];
//                }
//
//
//            }
//             std::cout << "||" << std::endl;
//        }
//         std::cout << "" << std::endl;
//    }


};

//int Soldier::num1=0;
//int Soldier::num2=0;


