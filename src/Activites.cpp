#include "../include/Activites.hpp"
#include "../include/Instructor.hpp"
#include "../include/Client.hpp"
#include "../include/KitesurfingSchool.hpp"
#include <iostream>

using namespace std;

Activites::Activites(int id, Client *c, int startTime, int endTime, int day, int month, Kite* k)
{
    this->id = id;
    this->c = c;
    Term* t = new Term(startTime,endTime,day,month);
    this->t = t; 
    this->k = k;

}

Activites::Activites(int id, Client *c, Term* t, Kite* k){
    this->id = id;
    this->c = c;
    this->t = t;
    this->k = k;

}

Activites::~Activites(){
    int h = abs((this->getTerm()->getEnd())-(this->getTerm()->getStart()));
    if(c->getHours()-h >=0 ){
        this->c->setHours(c->getHours()-h);
    }
    Instructor* in = this->c->getInstructor();
    if(in->getWorkedHours()-h>=0){
        in->setWorkedHours(in->getWorkedHours()-h);
    }
    cout << "\nActivites deleted!" << endl;

}

ostream& operator<<(ostream &os, const Activites &a){
    os << "Activites id: " << a.getId() << endl;
    os << "Client: " << a.getClient()->getName() << " " << a.getClient()->getSurname() << endl;
    if(a.getInstructor()!=NULL){
        os << "Instructor: " << a.getInstructor()->getName() << " " << a.getInstructor()->getSurname() << endl;
    }
    os << "Term: " <<  a.getTerm()->getStart() << "/" << a.getTerm()->getEnd() << " " << a.getTerm()->getDay() << "."<< a.getTerm()->getMonth() <<  endl;
    os << "Kite: " << a.getKite()->getId() << ". " << a.getKite()->getBrand() << " " << a.getKite()->getSize() << endl;
    return os;
}

Client* Activites::getClient() const{
    return c;
}


Kite* Activites::getKite() const{
    return k;
}

Term* Activites::getTerm() const{
    return t;
}

Instructor* Activites::getInstructor() const{
    return in;
}


void Activites::setKite(Kite* k){
    this->k = k;
}

int Activites::getId() const{
    return id;
}
void Activites::setInstructor(Instructor* in){
    this->in = in;
}

bool Activites::operator<(const Activites &a) const
{
	return c->getSurname() < a.getClient()->getSurname();
}