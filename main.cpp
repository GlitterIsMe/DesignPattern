#include "unit.h"
#include "simple_factory.h"

int main(){
    Unit *imlearning = new SimpleFactoryUnit();
    imlearning->run();
    delete imlearning;
    return 0;
}
