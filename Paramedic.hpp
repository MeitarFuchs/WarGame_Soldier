#pragma once

#include "Soldier.hpp"

class Paramedic : public Soldier{

public:

    Paramedic(int num_player): Soldier(100, num_player, 0,100){}

    void take_activity(std::pair<int,int> source,std::vector<std::vector<Soldier*>>& board) override;

};