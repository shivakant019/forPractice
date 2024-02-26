#include<bits/stdc++.h>
using namespace std;

class PowerRating{
    float CurrentOperatingVoltage;
public:
    void setPowerRating(float){}
    float getPowerRating(){}

};

class ChargingMode{
    string solarPanel;
public:
    string getSolarPanel(){}
    void setSolarPanel(){}

};


class Inverter{
    PowerRating powerRating;
public:
    void addInList(string name) = 0;
    PowerRating getPowerRating(){}
    void setPowerRating(PowerRating){}
};


class SolarOperated : Inverter{
    ChargingMode chargeMode;
    GRID grid;
public:
    get(){}
    set(){}

};

class GRID{
    bool serviceAvailable;
public:
    set(){}
    get(){}
};

class BatteryOperated:SolarOperated{
    float capacity;
    vector<string> list;
public:
    void displayList(){}
    vector<string> getList(){}

};

class NoBatteryOperated:SolarOperated{
    vector<string> list;
public:
    void setGrid(bool){}
    void displayList(){}
    vector<string>getList(){}
    void addToList(string){}
};


class NonSolarOperated: Inverter{
    vector<string> list;
public:
    void displayList(){}
    vector<string>getList(){}
    void addToList(string){}

};

