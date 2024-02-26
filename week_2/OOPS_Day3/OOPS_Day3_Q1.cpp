#include<bits/stdc++.h>
using namespace std;

//Abstract Class
class Person{
    string name;
public:
    string getName() = 0;
    void setName(string) = 0;
};

//Abstract class
class BrickDetails{
   virtual void setComment() = 0;
   virtual string readComment() = 0;
   virtual void dedicateTo() = 0; //dedicate brick to someone
   virtual string dedicatedTo() = 0 //return the person the whom the brick is dedicated
};

//Abstract class
class AdminControls{
    virtual void changeBrickContent() = 0;
    virtual void readBrickContent() = 0;
    virtual void getBrickDetails() = 0;
    virtual void getUserDetails() = 0;//return the full details of user
    virtual void addNewUser(string) = 0;//register new user
    virtual void deleteExistingUser() = 0;//delete existing user
};

//Abstract class
class ShowAnimation{
    virtual bool isInCityRange(User) = 0;
};

//Abstract Class
class WallDetails{
    virtual int numberOfBricksOccupied() = 0;
    virtual int getTotalNumberOfBricks() = 0;//returns the total numbers of bricks in a wall
    virtual int numberOfBrickRemaining() = 0;
    virtual bool isPreviousWallFilled() = 0;//return true if the previous wall is fully filled
    virtual int getTotalBricksInitiated(Wall) = 0; // return the total bricks initiated
    virtual User hottestPerson(Wall) = 0; //return the hottest guy
    virtual User lonliestPerson(Wall) = 0; // return the lonliest boy or girl
};

//Abstract class
class UserDetails{
public:
    {
        get,
        set
    };
    virtual string getFullDetails() = 0;


};


//Abstract class
class CityDetails{
    virtual int numberOfWallInitiated() = 0; // return the number of walls initiated
    virtual int getTotalNumberOfWalls() = 0;
    virtual bool isUserInCity() = 0;

};

//Abstract Class
class CountryDetials{
    virtual string getCountryDetails() = 0;
    virtual int getNumberofCities () = 0;
};


class Brick : BrickDetails{
    bool flagged;
    int brickId;
    string comment;
    User owner;
};



class User : UserDetails , Person{
    int id;
    Person newPerson;
    vector<Brick> brickId; //vector of Brick is because a single user can own more than one brick
public:
    void changeComment(){}
};


class InvisibleMode{
public:
    bool numberOfFlaggedBricks(){} //check if there are more than 10 flagged bricks
};


class Wall : WallDetails{
    const int MAX = 90;
    static bool isPrevioudOccupied = false;
    vector<Brick> numberOfBricks(MAX);
    InvisibleMode invisible;
};

class Cities : CityDetails{
    vector<Wall> walls;
};

class Country : CountryDetials{
    vector<Cities> cities;
};

//single functionality class
class HottestPerson{
    Wall wall;
public:
    User hottestPerson(wall);

};

//single functionality class
class LoneliestPerson{
    Wall wall;
public:
    User lonliestPerson(wall);
};

class Animate : ShowAnimation{ //animate if user is in city range
    User user;
};

//Admin Panel
class Admin : AdminControls{
    User User;
};
