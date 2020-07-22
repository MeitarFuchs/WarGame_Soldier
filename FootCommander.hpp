//
// Created by yirat on 19/05/2020.
//

#pragma once

#include "Soldier.hpp"

class FootCommander : public Soldier{
public:

    FootCommander(int num_player):Soldier(150,num_player,20,150){}
    void take_activity(std::pair<int,int> source,std::vector<std::vector<Soldier*>>& board) override;
};