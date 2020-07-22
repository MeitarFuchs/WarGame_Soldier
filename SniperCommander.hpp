#pragma once

#include "Soldier.hpp"

class SniperCommander : public Soldier{
public:

    SniperCommander(int num_player):Soldier(120,num_player,100,120){}

    void take_activity(std::pair<int,int> source,std::vector<std::vector<Soldier*>>& board) override;

};