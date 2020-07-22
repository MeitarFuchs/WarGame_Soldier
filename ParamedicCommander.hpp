//
// Created by Yirat and Orian on 19/05/2020.
//

#pragma once

#include "Soldier.hpp"
using namespace std;

class ParamedicCommander : public Soldier{
public:

    ParamedicCommander(int num_payer): Soldier(200,num_payer,0,200){}

    void take_activity(std::pair<int,int> source,std::vector<std::vector<Soldier*>>& board) override;
};
