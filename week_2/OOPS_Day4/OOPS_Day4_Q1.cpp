#include<std/bitsc++.h>
using namespace std;


//Abstract Class
class ParkingSpotTypeCompact{};

//Abstract Class
class ParkingSpotTypeLarge{};


//Abstract Class
class ParkingSpotTypeHandicapped{};


//Abstract Class
class ParkingSpotTypeMotorCycle{};

// Abstract Class which further extends all ParkingSpotType Abstract classes
class ParkingSpotType : ParkingSpotTypeCompact, ParkingSpotTypeHandicapped, ParkingSpotTypeLarge, ParkingSpotTypeMotorCycle{
    string getParkingSpotType() = 0;

;}

//Abstract Class
class ParkingSpotControls{
    virtual void assignVehicle(int) = 0;
    virtual void removeVehicle(int) = 0;
    virtual bool isOccupited() = 0;
    virtual string getParkingSpotType() = 0;
    virtual void getVehicleFullDetails() = 0;
};

//Abstract Classes
class VehicleTypeCar{};
class VehicleTypeTruck{};
class VehicleTypeVan{};
class VehicleTypeMotorcycle{};


//Abstract Class
class ManageDisplayBoard{
    virtual void addDisplayBoard() = 0;
    virtual void removeDisplayBoard() = 0;
};


//Abstract Class
class DisplayBoardControls{
  virtual void showTotalSpots() = 0;
  virtual void showAvailabeSpots() = 0;
  virtual void showOccupiedSpots() = 0;
  virtual void showIsFullMessage() = 0;
};

class DisplayBoard : DisplayBoardControls{
    int boardNumber;
    Floor floor;
};

//Abstract Class
class ManagingParkingSpots{
    virtual void addParkingSpot() = 0;
    virtual void removeParkingSpot() = 0;
    virtual void modifyParkingSpot() = 0;
};

//Abstract Class which
class VehicleType : VehicleTypeCar, VehicleTypeTruck, VehicleTypeVan, VehicleTypeMotorcycle{
    string getVehicleType() = 0;
};


class Vehicle{
    int licenceNumber;
    VehicleType type;
public:
        void getVehicleFullDetails(){}
};



class ParkingSpot : ParkingSpotType,ParkingSpotControls{
    int spotNumber;
    bool isOccupited;
    bool isReservedForElectricVehicle;
    ParkingSpotType spotType;
    Vehicle parkedVehicle;

};

class ElectricVehicleParkingSpotControls{
    void plugIn() = 0;
    void plugOut() = 0;
};

class ElectricVehicleParkingSpot: ParkingSpot,ElectricVehicleParkingSpotControls{ //extends ParkingSpot and implements ElectricVehicleParkingSpotControls
    string ElectricPanel;

};

//Abstract Class
class CustomerInfoPortalServices{
    virtual void processTicket() = 0;
};

class CustomerInfoPortal : FareModel,CustomerInfoPortalServices{
    Customer customer;
};



class ParkingFloor : ManagingParkingSpots,ManageDisplayBoard{
    int floorNumber;
    CustomerInfoPortal portal;
    vector<ParkingSpot> parkingSpots;
    vector<DisplayBoard> displayBoards;
};

//Abstract Classes
class PaymentModeCash{};
class PaymentModeCard{};

//Abstract class
class PaymentMode : PaymentModeCash, PaymentModeCard{
};

//Abstract class
class HourlyParkingRate{};

class ManagingFareModel : HourlyParkingRate{
    virtual void modifyRate() = 0;
};

class FareModel : HourlyParkingRate,VehicleType{
    double price;
};

//returns the amount;
class TicketScanner : FareModel{
    void getTicketPrice(){}
};


class Tickets{
    int ticketId;
    Vehicle vehicle;
    LocalTime startTime;
    LocalTime endTime;
    FareModel price;
    bool isPaid;
    PaymentMode paymentMode;

};

//Abstract Class
class EntryPanelControls{
    void issueTicket() = 0;
};
//Abstract Class
class ExitPanelControls{
    void processTicket() = 0; //pay the amount
};

class EntryPanel : EntryPanelControls{
    int panelNumber;
    Ticket ticket;
};

class ExitPanel : ExitPanelControls{
    int panelId;
    TicketScanner ticketScan;
    Ticket ticket;
};

//
class ManagingAttendent{
    virtual void addAttendent() = 0;
    virtual void removeAttendent() = 0;
};

class ManagingPanel{
    virtual void addEntryPanel() = 0;
    virtual void removerEntryPanel() = 0;
    virtual void addExitPanel() = 0;
    virtual void removeExitPanel() = 0;
};

class ManagingFloor{
    virtual void addFloor() = 0;
    virtual void removeFloor() = 0;
    virtual void modifyFloor() = 0;
};

//Abstract Class
class ManageParkingLot : ManagingAttendent,ManagingPanel,ManagingFloor{
    virtual void findParkingSpot(Vehicle) = 0;
    virtual void isFull() = 0;
};

class ParkingLot : ManageParkingLot{
    int id;
    vector<Floor> floors;
    vector<EntryPanel> entryPanel;
    vector<ExitPanel> exitPanel;
    vector<Vehicles> parkedVehicles;
    vector<ParkingAttendent> attendents;
    int capacity;
};

//Abstract Class
class HandOverToParkingAttendent{
    virtual void handOverToParkingAttendent() = 0;
    virtual void payToParkingAttendent() = 0;
};

//Abstract Class
class CustomerPower{
    virtual void getTicket() = 0;
    virtual void payAmount() = 0;
};

class Customer : CustomerPower,HandOverToParkingAttendent{
    string name;
    bool isHandedToAttendent;
    ParkingSpot myparkingSpot;
};

//Abstract Class
class ParkingAttendentPower : CustomerPower{
    virtual void getCustomer(Customer&) = 0;
};

class ParkingAttendent : ParkingAttendentPower{
    int attendentId;
    vector<Customer> customer;
};

class System : SystemControls {
    DisplayBoard displayBoard;
    ParkingLot parkingLot;
};

class AmdinControls : ManagingFareModel,
                      ManagingParkingSpots,ManagingPanel,ManagingFloors,
                      ManageParkingLot,ManagingAttendent,ManageDisplayBoard{
    virtual void getAllFloorDetails() = 0;
    virtual void getAllParkingSpotDetails = 0;
};

class Admin : AdminControls{
    ParkingLot master;
};
