//
// Created by 张艺文 on 2018/4/10.
//
#include <cstdio>
#include "strategy.h"

//策略模式：定义算法家族，并分别封装起来，让其相互可以被替换，这样的模式在算法变化的时候不会影响到使用算法的客户
//1.定义算法公共接口
//2.实现具体算法
//3.使用一个context维护一个对象的引用

class CashSuper{
//算法的公共接口
public:
    CashSuper(){};
    virtual ~CashSuper() = 0;
    virtual double Receive(double money) = 0;
};

CashSuper::~CashSuper() {}

class CashNormal:public CashSuper{
//每一个派生类代表一种算法
public:
    CashNormal():CashSuper(){}
    ~CashNormal(){}
    double Receive(double money){
        return money;
    }
};

class CashRebate:public CashSuper{
public:
    CashRebate(double factor):CashSuper(), factor_(factor){}
    ~CashRebate(){}
    double Receive(double money){
        return money * factor_;
    }

private:
    double factor_;
};

class CashContext{
    //统一管理策略的类
public:
    CashContext(CashSuper* su):su_(su){}
    ~CashContext(){delete su_;}
    double GetMoney(double ori_money){
        return su_->Receive(ori_money);
    }
private:
    CashSuper* su_;
};

/*
class Cashier{
    //问题：程序死板不灵活，如果需要增加打折信息需要重新添加代码
public:
    Cashier(): total(0){

    }
    ~Cashier(){
        printf("Welcome next time\n");
    }
    void Add(double price, int cnt){
        total += price * cnt;
    }
    double Account(){
        return total;
    }

private:
    double total;
};
*/

StrategyUnit::StrategyUnit() :Unit(){

}

StrategyUnit::~StrategyUnit() {

}

void StrategyUnit::run() {
    printf("start counting\nend with 0 0\n0: normal, 1: 0.8\n");
    double price;
    int cnt;
    int flag;
    double total = 0;
    CashContext *cc;
    scanf("%lf%d%d", &price, &cnt, &flag);
    while(price != 0 && cnt != 0){
        printf("get : $%lf * %d %s\n", price, cnt, flag?"normal":"0.8");
        //可以把这个过程转移到CashContex里面，通过CashContex实现一个工厂模式
        /*
         * 将这个选择的过程封装起来，消除条件语句
         * */
        switch (flag){
            case 0:
                cc = new CashContext(new CashNormal());
                total += cc->GetMoney(price) * cnt;
                break;
            case 1:
                cc = new CashContext(new CashRebate(0.8));
                total += cc->GetMoney(price) * cnt;
                break;

        }
        delete cc;
        scanf("%lf%d", &price, &cnt);
    }
    printf("total : $%lf\n", total);
}

/*
 * 总结：策略模式定义了一些列的算法（CashNormal、CashRebate），本质上这些算法的工作是相同的（都是打折），只是实现不同（打折方式不同）
 * 每种算法的调用方式一样，减少了每个算法实现与算法调用之间的耦合
 * 使用场景：《封装变化》，需要在不同的时间使用不同的规则
 * */




