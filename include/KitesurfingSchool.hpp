#define KitesurfingSchool_hpp
#ifndef KitesurfinSchool_hpp
#include "Instructor.hpp"
#include "Client.hpp"
#include "Kite.hpp"
#include "Activites.hpp"
#include <list>
#include <algorithm>

using std::list;

class KitesurfingSchool {
private:
    string name;
    string adress;
    string tel;
    string site;

    list<Instructor>listOfInstructor;
    list<Client> listOfClient;
    list<Kite> listOfKite;
    list<Activites> listofActivites;


public:
    KitesurfingSchool(string name, string addres, string tel, string site);
    ~KitesurfingSchool();
    
    void showInfo();  //Show information of the kitesurfing school


    void addClient(Client *cl); //Finding instructor to client and add a client to list
    void addClient(int id, string name, string surname, int age, int weight, string sex, int price, int hours);
    //Finding instructor to client and add a client to list by 
    void printClientList(); //Print the whole list of clients
    void printClientOfInstructor(int id); //Print list of clients of instutor of this id
    bool checkExistingClient(int id); //Checking such client of this id alredy exist
    void removeClient(Client *cl); //Remove client from list
    void removeClient(int id); //Remove client from list by id
    Client* findClient(int id); //Return client of this id
    void clearClient(); //remove whole list of client


    void addInstructor(Instructor *in); //Add instructor to list
    void addInstructor(int id,string name, string surname, int age, int weight, string sex, int salary, int workedHours); 
    //Add instructor to list 
    void printInstructorList(); //Print the whole list of instructor
    bool checkExistingInstructor(int id); //Checking such client of this id alredy exist
    void resignInstructor(Instructor *in); //Resign instructor and remove from list,
    // but first it check that instructor have some client if he have finding new for client
    void resignInstructor(int id); //Resign instructor and remove from list by id
    // but first it check that instructor have some client if he have finding new for client
    Instructor* findInstructor(int id); //Return instrutor of this id
    Instructor* findTheBest();
    Instructor* findTheBestWithout(Instructor* in);
    void clearInstructor(); //remove whole list of instructor
    void paySalary(int id);//Pay salary to instructor 


    void addKite(Kite *k); //Add kite to list
    void printKiteList(); //Print list to kite
    bool checkExistingKite(int id);
    void removeKite(int id); //Remove kite from list 
    void clearKite(); //remove whole list of kite

    void addActivite(int id, Client *c, Kite* k, int startTime, int endTime, int day,int month);
    //Add activites to list with checking availability of instructor and kite 
    void addActivite(Activites* a);
    //Add activites to list with checking availability of instructor and kite
    void printActiviteList(); //printing whole activites list 
    void printScheduleClient(int id); //printig activites list of client
    void printScheduleInstructor(int id);  //printing activites list of instructor
    void removeActivite(Activites* a); //remove activite from list
    void removeActivite(int id);  //remove activite from list by id
    bool checkExistingActivites(int id);
    void clearActivite(); //remove whole list of activites
    Activites* findActivite(int id);



};
#endif