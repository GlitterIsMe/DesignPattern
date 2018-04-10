//
// Created by 张艺文 on 2018/4/10.
//

#ifndef DESIGNPATTERN_MASTER_STRATEGY_H
#define DESIGNPATTERN_MASTER_STRATEGY_H
#include "unit.h"
class StrategyUnit : public Unit{
public:
    StrategyUnit();
    ~StrategyUnit();
    void run();
};
#endif //DESIGNPATTERN_MASTER_STRATEGY_H
