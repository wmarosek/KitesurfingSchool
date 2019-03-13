#include "../include/Kite.hpp"
#include <iostream>

using namespace std;

Kite::Kite(int id, string brand, int size)
{
    this->id = id;
    this->brand = brand;
    this->size = size;
}


Kite::~Kite()
{
    cout << "\nKite deleted!" << endl;

}

int Kite::getId() const {
    return id;
}

void Kite::setSize(int size){
    this->size = size;
}

int Kite::getSize(){
    return size;
}

void Kite::setBrand(string brand){
    this->brand = brand;
}

string Kite::getBrand(){
    return this->brand;
}
ostream& operator<<(std::ostream &os, const Kite &k){
    os << "Id: " << k.id << "\nBrand: " << k.brand << " Size: " << k.size << endl;
    return os;
}

bool Kite::operator==(const Kite &k) const{
    return (this->getId() == k.getId());
}

bool Kite::operator<(const Kite &a) const
{
	return brand < a.brand;
}