#include<bits/stdc++.h>
using namespace std;

class Movie;
class Customer;
class Rental;
class Subject;
class Observer;
class Singleton;
class MovieRentalSystem;
class Date;

class Date{
    int day;
    int month;
    int year;

    public:
    Date(){}
    Date(int day,int month,int year){
        this->day = day;
        this->month = month;
        this->year = year;
    }

    int getMonth(){
        return month;
    }
};


//Observer Design Pattern
class Observer{
public:
        virtual void update() = 0;
};


class Subject{
public:
    virtual void subscribe(Observer* observer) = 0;
    virtual void unsubscribe(Observer* Observer) = 0;
    virtual void notifyAll() = 0;
};



class Movie{
    string title;
    string genre;
    int rentalPrice;

public:
    Movie(){}

    //builder design pattern
    void setTitle(string title){
        this->title = title;
    }

    void setGenre(string genre){
        this->genre = genre;
    }

    void setRentalPrice(int rentalPrice){
        this->rentalPrice = rentalPrice;
    }

    string getTitle(){
        return title;
    }

    string getGenre(){
        return genre;
    }

    int getRentalPrice(){
        return rentalPrice;
    }

};

class Rental{
    Movie* movie;
    Customer* customer;
    Date issueDate;
    Date returnDate;

public:
    //Rental(){}

    Rental(Movie* movie,Customer* customer,Date rentalDate){
        this->movie = movie;
        this->customer = customer;
        this->returnDate = rentalDate;
    }

    Movie& getMovie(){
        return *movie;
    }

    Customer& getCustomer(){
        return *customer;
    }

    Date getRentalDate(){
        return returnDate;
    }

    void setReturnDate(Date returnDate){
        this->returnDate = returnDate;
    }

    bool isReturned(){
        returnDate.getMonth() != 0;
    }
};


class CustomerPower{
    virtual void addRental(Rental*) = 0;
    virtual vector<Rental*> getRentals() = 0;
};

class Customer : public Observer , CustomerPower{

    string name;
    vector<Rental*> rentals;


    public:

    Customer(){}

    void setName(string name){
        this->name = name;
    }

    string getName() {
        return name;
    }

    void addRental(Rental* rental) override {
        rentals.push_back(rental);
    }

    vector<Rental*> getRentals() override {
        return rentals;
    }

    void update() override {
        cout<<"Customer " << name << "notified"<<endl;
    }
};


class CalculateRevenue{
    virtual int calculateRevenue() = 0;
};


class MovieRentalSystemPower : CalculateRevenue{
    virtual void addMovie(Movie* movie) = 0;
    virtual void addCustomer(Customer* customer) = 0;
    virtual void rentMovie(Movie& movie,Customer& customer,Date) = 0;
    virtual void returnMovie(Rental& rental,Date) = 0;
    virtual vector<Rental*> displayRentals(Customer&) = 0;
    virtual vector<Movie*> getMovies() = 0;
    virtual vector<Rental*> getRental() = 0;
};


class MovieRentalSystem : public Subject , MovieRentalSystemPower{
    vector<Movie*> movies;
    vector<Customer*> customers;
    vector<Rental*> rentals;
    vector<Observer*> observers;

    //static MovieRentalSystem* instance;

    MovieRentalSystem(){}

public:

    static MovieRentalSystem& getInstance(){
        static MovieRentalSystem obj;
        return obj;//returning the instance
    }

    /*
    static MovieRentalSystem* getInstance(){
        if(instance == NULL)
            instance = new MovieRentalSystem();
        return instance;
    }
    */

    void addMovie(Movie* movie) override {
        movies.push_back(movie);
        notifyAll();
    }

    void addCustomer(Customer* customer) override {
        customers.push_back(customer);
        notifyAll();
    }

    void rentMovie(Movie& movie,Customer& customer,Date rentalDate) override {
        Rental* rental = new Rental(&movie,&customer,rentalDate);
        rentals.push_back(rental);
        customer.addRental(rental);
        notifyAll();
    }

    void returnMovie(Rental& rental,Date returnDate) override {
        rental.setReturnDate(returnDate);
        notifyAll();
    }

    vector<Rental*> displayRentals(Customer& customer) override {
        vector<Rental*> customerRentals;
        for(Rental* rental : rentals){
            if(&rental->getCustomer() == &customer)
                customerRentals.push_back(rental);
        }

        return customerRentals;
    }

    int calculateRevenue() override {
        int total = 0;
        for(Rental* rental : rentals){

            if(rental->isReturned())
                total += rental->getMovie().getRentalPrice();
        }
        return total;
    }

    void subscribe(Observer* observer) override {
        observers.push_back(observer);
    }

    void unsubscribe(Observer* observer) override {
        observers.erase(remove(observers.begin(),observers.end(),observer),observers.end());
    }

    void notifyAll() override {
        for(Observer* observer : observers){
            observer->update();
        }
    }

    vector<Movie*> getMovies() override {
        return movies;
    }

    vector<Rental*> getRental() override {
        return rentals;
    }
};

class Singleton{
    public:
    MovieRentalSystem system = MovieRentalSystem::getInstance();
};


int main(){

    Singleton object; //only single object

    Movie* m1;
    m1->setTitle("Dhadkan");
    m1->setGenre("Action");
    m1->setRentalPrice(100);

    object.system.addMovie(m1);

    Customer* shiva = new Customer();
    shiva->setName("shiva");

    object.system.addCustomer(shiva);

    Date issueDate(25,02,2023);
    Date returnDate(25,03,2023);

    object.system.rentMovie(*m1,*shiva,issueDate);

    object.system.returnMovie(*shiva->getRentals()[0],returnDate);

    cout<<"Total revenue: " << object.system.calculateRevenue()<<endl;
}

