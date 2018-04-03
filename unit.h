//
// Created by zzyyy on 2018/4/3.
//

#ifndef SIMPLEFACTORY_UNIT_H
#define SIMPLEFACTORY_UNIT_H

class Unit{
public:
    Unit(){};
    virtual ~Unit();
    virtual void run() = 0;
};
#endif //SIMPLEFACTORY_UNIT_H
