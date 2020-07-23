#pragma  once

#include "Soldier.hpp"

class Sniper : public Soldier{

public:

    Sniper(int num_player) : Soldier(100,num_player,50,100){}

    void take_activity(std::pair<int,int> source,std::vector<std::vector<Soldier*>>& board) override ;
};
