#include<iostream>
#include "Test.h"
using namespace std;
static int idn =1;
Test::Test():ele(0),next(0){
    this->ID = idn++;
}
Test::Test(int ele, Test * next){
    this->ele = ele;
    this->next = next;
    this->ID = idn++;
}
int Test::getElement(){
    return ele;
}
Test * Test::getNext(){
    return next;
}
int Test::getID(){
    return this->ID;
}
