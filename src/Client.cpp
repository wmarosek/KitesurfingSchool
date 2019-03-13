#include "../include/Client.hpp"

using namespace std;

Client::Client(int id, string name, string surname, int age, int weight, string sex, int price, int hours) : Person(id, name, surname, age, weight, sex)
{
    this->price = price;
    this->hours = hours;
}

Client::~Client()
{
    cout << "\nClient deleted!" << endl;

}

ostream& operator<<(ostream &os, const Client &c){
    os << "\n" << c.id << ". " << c.name << " " << c.surname << endl;
    os << "Age: " << c.age << " Weight: " << c.weight << " Sex: " << c.sex << endl;
    os << "Price: " << c.price << " Hours: " << c.hours<< endl;
    return os;
}


void Client::setPrice(int price){
    this->price = price;
}

void Client::setHours(int hours){
    this->hours = hours;
}

int Client::getPrice(){
    return price;
}

int Client::getHours(){
    return hours;
}


void Client::setInstructor(Instructor * in){
    this->in = in;
}

Instructor* Client::getInstructor(){
    return this->in;
}

void Client::getPay(){
    cout << "Getting money from " << this->getName() << "which equal to " << (this->getPrice()*this->getHours())<< endl;
    this->setHours(0);
}