#include<bits/stdc++.h>
using namespace std;

//Abstract Class
class Denominations{ //all the notes should implement this
    virtual int getCount() = 0;
    virtual void AddNotes() = 0;
    virtual bool isAvailable() = 0;
};

class CheckBalanace{
        void showMyBalance() = 0;
};

//Abstract Class
class WithDrawServices,CheckBalanace{
    virtual vector<NoteTypes> getNotes() = 0;
    virtual void inSufficientBalance() = 0;
    virtual bool isAmountValid() = 0;//throws error if entered amount is in multiple denominations
    virtual int showUpdatedBalance() = 0;
};

//Abstract Class
class ATMServices{
    virtual void withDraw(int amount) = 0;
    virtual void checkMyBalance() = 0;
};


class Note2000 : Denominations{
    bool isAvailable;
    int count;
};

class Note1000 : Denominations{
    bool isAvailable;
    int count;
};

class Note500 : Denominations{
    bool isAvailable;
    int count;
};

class Note200 : Denominations{
    bool isAvailable;
    int count;
};

class Note100 : Denominations{
    bool isAvailable;
    int count;
};

class NotesTypes {
    Note2000 twoThousand;
    Note1000 thousand;
    Note500 fiveHundred;
    Note100 hundred;
    Note200 twoHundred;
};


class WithDraw : WithDrawServices{
    //vector is taken if in future new denomination is added or any existing is removed
    vector<NoteTypes> availabeNotes;
    int amount;

};


//Single Responsibility
class ATM : ATMServices,CheckBalanace{
    WithDraw withDraw;
    int amount;
    int myBalance;
public:
};

int main(){
    ATM atm;
    int amount = 41000;
    atm.withDraw(amount);
}


