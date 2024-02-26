#include<bits/stdc++.h>
using namespace std;

class Person{
    string name;
public:
    Person(string name){
        this->name = name;
    }
    void setName() = 0;
    string getName() = 0;
};

class SpecialBenifits{
    string arrestMinister;
    string Aircraft;
public:

}

class Car{
    string name;
    string color;
public:
    getColor(){ }
    setColor(){ }
    getDetails() { }
};

class Driver{
    int yearsOfExperience;
    string name;
public:
    getName(){ }
    setName(){ }
    getDetails() { }
};

class SpendingLimit{
    string designation;
    float limit;
public:
    SpendingLimit(float l):limit(l){ }
    float setLimit(float limit) { }
    float getLimit() { }

};

class Constinuency{
    string name;
    float area;
    string MPofConstituency;
public:
    void getConstituencyInfo(){ }
};

class MP:Person{
    Constituency constituency;
    SpendingLimit spendingLimit());
    Car car;
    Driver driver;
public:
    MP(string name):Person(name){}
    getDetails() { }
    string getConstituency() { }
    string getDriver() { }
    string getCar(){ }
    bool exceedsSpendingLimit(){ }

};

class Minister:MP{
    Driver driver;
    Car car;
public:
    void getDetails() { }
    string getName(){ }
    string getConstituency(){ }
    bool exceedsSpendingLimit(){ }
    string getDriver(){ }
    string getCar(){ }

};


class PM : Minister{
    Car car;
    Driver driver;
public:
    string getConstituency(){}
    string getDriver(){}
    string getCar(){}
    bool permission(){}
    bool exceedsSpendingLimit(){}

};

class Commissioner : protected MP{
    MP mp;
    Minister minister;
    PM pm;
public:
    void getName();
    bool exceedsSpendingLimit(){}
    void arrest(MP){}
    void arrest(Minister){
        PM::permission();
    }
};
