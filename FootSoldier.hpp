#pragma once

#include "Soldier.hpp"

class FootSoldier : public Soldier{

public:

    FootSoldier(int num_player):Soldier(100,num_player,10,100){}

    void take_activity(std::pair<int,int> source,std::vector<std::vector<Soldier*>>& board) override; // now we know that he will overide this function
};
