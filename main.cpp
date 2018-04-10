#include "unit.h"
#include "simple_factory.h"
#include "strategy.h"

int main(){
    //Unit *imlearning = new SimpleFactoryUnit();
    Unit *imlearning = new StrategyUnit();
    imlearning->run();
    delete imlearning;
    return 0;
}
