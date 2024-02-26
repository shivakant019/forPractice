#include<bits/stdc++.h>
using namespace std;

class ReservationStatus{
    bool isReserved;
};

class ManageCriteria{
    virtual void addCriteria() = 0;
    virtual void deleteCriteria() = 0;
    virtual void modifyCriteria() = 0;
};

class Criteria{
    vector<string> criteria;
};

class SearchHotelRoom : Criteria{
    vector<Hotel> hotels;
};

class Room{
    int roomId;
    Criteria criteria;
    ReservationStatus reservationStatus;
public:

};

class Register{
    virtual void newRegistration() = 0;
};


class RegisterAsUser : Register{};

class RegisterAsHotel : Register{};



class BookHotel{};

class ModifyUserDetails{
    virtual void updateName() = 0;
    virtual void updateAdharNumber() = 0;
    virtual void updateLocation() = 0;
};


class UserDetails{
   string name;
   string AdharNumber;
   string location;
   string email;
};

class HotelList{};

class UserPower : RegisterAsUser,SearchHotelRoom,
                  ModifyUserDetails,BookHotel,HotelList,
                  {
    virtual void search(vector<Criteria>&) = 0;
    virtual void bookRoom() = 0;
};


class User : UserPower{
    UserDetails myProfile;
    vector<Criteria> myCriteria;
public:
};

class ManageFacilites{
    virtual void addFacility() = 0;
    virtual void removeFacility() = 0;
    virtual void showAllFacility() = 0;
};

class Facilities {};

class ModifyHotelDetails{
    virtual void ModifyRoom() = 0;
    virtual void addRoom() = 0;
    virtual void deleteRoom() = 0;
    virtual void addCriteria() = 0;
    virtual void deleteCriteria() = 0;
    virtual void modifyCritera() = 0;
};

class HotelDetails{
    string name;
    string location;
    int TotalNumberOfRooms;

public:
    {
        getters;
        setters;
    }
};

class HotelPower : RegisterAsHotel,ManageFacilites,
                   ModifyHotelDetails,ManageCriteria{
    virtual void showUserList() = 0;
    virtual void showRoomList() = 0;
    virtual void showFacilities() = 0;
};

class Hotel : HotelPower{
    HotelDetails hotel;
    vector<Room> roomList;
    vector<Criteria> roomsCriteria;
    vector<User> myUsers;
    vector<Facilities> facilites;
};

class HotelAgent{
    Hotel myHotel;
};

class FeedBack{
    string message;
    virtual void takeFeedback() = 0;
};


class Rating{
    virtual void giveRatingStars() = 0;
};

class RatingStars : Rating{};

class ModifyHotel : {
    virtual void addHotel() = 0
    virtual void removeHotel() = 0;
    virtual void modifyHotel() = 0;
};


class HotelApproval{
    virtual bool isApproved() = 0;
};




class AdministratorPower : HotelApproval,ModifyHotel,
                           Register,ModifyUserDetails,
                           FeedBack{

};


class AppAdministrator : AdministratorPower{
    vector<Hotel>  hotelList;
    vector<User> userList;
};
