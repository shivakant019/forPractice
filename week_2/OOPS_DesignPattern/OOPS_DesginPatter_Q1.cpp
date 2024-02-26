#include<bits/stdc++.h>
using namespace std;

// declarations
class Object;
class Clonable;
class Singleton;
class HotelManagementSystem;
class User;
class NormalUser;
class HotelAgent;
class Administrator;
class Hotel;


class Object{};
//abstract class
class User {
public:
    virtual void registerUser() = 0;
    virtual void updateUser() = 0;
};

// NormalUser class
class NormalUser : public User {
private:
    string name;
    string email;
public:
    NormalUser(string email) : name(name), email(email) {}

    void registerUser(){
        cout << "Registering normal user " << name << " with email " << email << endl;
    }

    void updateUser() {
        cout << "Updating normal user " << name << " with email " << email << endl;
    }

    void searchHotels(){
        cout << "Searching hotels based on criteria" << endl;
    }

    void bookRoom(HotelManagementSystem& system){
        cout << "Booking a hotel room" << endl;
        //system.bookRoom(*this);
    }

    void displayReservationStatus(HotelManagementSystem& system) {
        cout << "Displaying reservation status" << std::endl;
        //system.displayReservationStatus(*this);
    }
};

// HotelAgent concrete class
class HotelAgent : public User {
private:
    string name;
    string email;
public:
    HotelAgent(string name, string email) : name(name), email(email) {}

    string getName(){
        return name;
    }

    void setName(string name){
        this->name = name;
    }

    void registerUser(){
        cout << "Registering hotel agent " << name << " with email " << email << endl;
    }

    void updateUser(){
        cout << "Updating hotel agent " << name << " with email " << email << endl;
    }
    void addHotel(HotelManagementSystem& system){
        cout << "Adding a hotel" <<endl;
        //system.addHotel(*this);
    }
    void updateHotel(HotelManagementSystem& system){
        cout << "Updating a hotel" <<endl;
        //system.updateHotel(*this);
    }
};


class Clonable{
    virtual Object getClone() = 0;
};

//contains Builder Design Pattern
//contains the prototype design pattern as cloning can be done --> extends the clonable interface
// Administrator concrete class
class Administrator : public User ,Object, Clonable {
    string name;
    string email;
public:

    Administrator(){}

    //here name is set without constructor
    void setName(string name){ //
        this->name = name;
    }

    //here email is set without constructor
    void setEmail(string email){
        this->email = email;
    }

    void registerUser() {

        cout << "Registering administrator " << name << " with email " << email<<endl;
    }

    void updateUser() {

        cout << "Updating administrator " << name << " with email " << email << endl;
    }

    void approveHotel(HotelManagementSystem& system) {
        cout << "Approving a hotel" << endl;
        //system.approveHotel(*this);
    }

    void deleteUser(HotelManagementSystem& system) {
        cout << "Deleting a user" <<endl;
        //system.deleteUser(*this);
    }

    void deleteHotel(HotelManagementSystem& system){
        cout << "Deleting a hotel" << endl;
        //system.deleteHotel(*this);
    }

    //cloning -> deep copying
    Object getClone(){
        Administrator newobj;
        newobj.name = this->name;
        newobj.email = this->email;
        return newobj;
    }
};



// Hotel abstract class
class Hotel {
public:
    virtual void addHotel(HotelAgent&) = 0;
    virtual void updateHotel(HotelAgent&) = 0;
    virtual void displayHotels() = 0;
    virtual void bookRoom(NormalUser& user) = 0;
    virtual void displayReservationStatus(NormalUser& user) = 0;
};

//Singleton Class
//Only one object can be created;
// HotelManagementSystem class
class HotelManagementSystem : Hotel{
private:
    vector<Hotel*> hotels;
    HotelManagementSystem(){} //private Constructor
public:



    static HotelManagementSystem& getInstance(){
        static HotelManagementSystem obj;
        return obj;//returning the instance
    }


    void addHotel(HotelAgent& agent){
        cout << "Adding a hotel " << agent.getName() << " to the system" << endl;
        //hotels.push_back(new Hotel());
    }

    void updateHotel(HotelAgent& agent) {
        cout << "Updating a hotel in the system" << endl;
    }

    void approveHotel(Administrator& admin) {
        cout << "Approving a hotel added by a hotel agent" << endl;
    }

    void displayHotels(){
        cout<<"Displaying List of hotels";
    }

    void deleteUser(Administrator& admin) {
        cout << "Deleting a user from the system" << endl;
    }

    void deleteHotel(Administrator& admin) {
        cout << "Deleting a hotel from the system" << endl;
    }

    void searchHotels() {
        cout << "Searching hotels based on criteria" << endl;
    }

    void bookRoom(NormalUser& user) {
        cout << "Booking a room in a hotel" << endl;
    }

    void displayReservationStatus(NormalUser& user) {
        cout << "Displaying reservation Status"<<endl;
    }
};

class Singleton{
public:
    HotelManagementSystem object = HotelManagementSystem::getInstance();
};

int main() {
    //HotelManagementSystem system;  //Object cannot be created
    HotelAgent hotelAgent("shiva","shiva@gmail.com");
    Singleton obj;
    obj.object.addHotel(hotelAgent);
}
