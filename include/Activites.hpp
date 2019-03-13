#ifndef Activites_hpp
#define Activites_hpp
#include "Client.hpp"
#include "Kite.hpp"
#include "Term.hpp"
#include "Instructor.hpp"

class Activites{
private:
    int id;
    Client* c;
    Instructor *in;
    Kite* k;
    Term* t;
           
public:
    //Constructor and destructor
    Activites(int id, Client *c, int startTime, int endTime, int day, int month, Kite* k);
    Activites(int id, Client *c, Term* t, Kite* k);
    ~Activites();    
    //Getters and setters
    Client* getClient() const;
    Instructor* getInstructor() const;
    Term* getTerm() const;
    Kite* getKite() const;
    int getId() const;
    void setInstructor(Instructor* in);
    void setKite(Kite* k); 

    friend ostream& operator<<(ostream &os, const Activites &a);
    bool operator<(const Activites &a) const;
};

#endif