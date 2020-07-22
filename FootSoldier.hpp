//
// Created by yirat on 19/05/2020.
//

#pragma once

#include "Soldier.hpp"

class FootSoldier : public Soldier{
public:

    FootSoldier(int num_player):Soldier(100,num_player,10,100){}
    void take_activity(std::pair<int,int> source,std::vector<std::vector<Soldier*>>& board) override;
};
