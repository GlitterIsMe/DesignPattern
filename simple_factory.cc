//
// Created by zzyyy on 2018/4/3.
//
#include "simple_factory.h"
#include <iostream>
#include <cstdio>
#include <sstream>

//operator类，给出两个操作数，给定操作符，计算返回结果
class Operator{
public:
    Operator(double left, double right, char op) :
            left_(left),
            right_(right),
            op_(op){

    }

    ~Operator();

    double Calculate(){
        double result;
        std::string error_msg;
        switch (op_) {
            case '+':
                result = (left_ + right_);
                break;
            case '-':
                result = (left_ - right_);
                break;
            case '*':
                result = (left_ * right_);
                break;
            case '/':
                result = (left_ / right_);
                break;
            default:
                error_msg = "illegal symbol";
                throw error_msg;
        }
    };

private:
    double left_, right_;
    char op_;
};

SimpleFactoryUnit::SimpleFactoryUnit() : Unit() {}

SimpleFactoryUnit::~SimpleFactoryUnit() {
    printf("deconstruct SimpleFactoryUnit\n");
}

Unit::~Unit() {
    printf("deconstruct Unit\n");
}

void SimpleFactoryUnit::run() {
//没有异常机制，尝试添加异常机制
/*
    double left, right, result;
    char op;
    scanf("%lf%lf%c", &left, &right, &op);
    printf("%lf, %lf, %c\n", left, right, op);//这个%c会把空格读进去，输入的时候不要加空格
    switch(op){
        case '+':
            result = left + right;
            break;
        case '-':
            result = left - right;
            break;
        case '*':
            result = left * right;
            break;
        case '/':
            result = left / right;
            break;
        default:
            printf("cannot recognize this symbol\n");

    }
    printf("result = %lf\n", result);
    return ;
}*/

/*
 * 存在的问题：不易维护，不易扩展
 * 面向对象：通过封装、继承、多态把程序的耦合度降低，使程序易于修改和复用
 * 改进：分离业务逻辑和界面逻辑，业务逻辑在这里就是计算相关，界面逻辑就是输入相关的内容
 * */
    /*try {
        double left, right, result;
        char op;
        std::string result_str;
        std::ostringstream convert;
        std::string error_msg;
        scanf("%lf%lf%c", &left, &right, &op);
        printf("%lf, %lf, %c\n", left, right, op);//这个%c会把空格读进去，输入的时候不要加空格
        //std::exception e;
        switch (op) {
            case '+':
                convert << (left + right);
                break;
            case '-':
                convert << (left - right);
                break;
            case '*':
                convert << (left * right);
                break;
            case '/':
                convert << (left / right);
                break;
            default:
                error_msg = "illegal symbol";
                //throw "illegal symbol";///TODO:不能直接throw一个临时变量？
                throw error_msg;

        }
        result_str = convert.str();
        printf("result is %s\n", result_str.c_str());
    } catch (std::string s) {
        printf("error : %s\n", s.c_str());
    }

    return;*/

    try{
        double left, right, result;
        char op;
        std::string result_str;
        std::ostringstream convert;
        std::string error_msg;
        scanf("%lf%lf%c", &left, &right, &op);
        printf("%lf, %lf, %c\n", left, right, op);//这个%c会把空格读进去，输入的时候不要加空格
        Operator* oprt = new Operator(left, right, op);
        convert << oprt->Calculate();
        result_str = convert.str();
        printf("result is %s\n", result_str.c_str());
    }catch(std::string s){
        printf("error : %s\n", s.c_str());
    }

}

