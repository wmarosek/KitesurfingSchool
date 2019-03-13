#include <iostream>
#include <cstdio>
#include "../include/Person.hpp"
#include "../include/Client.hpp"
#include "../include/KitesurfingSchool.hpp"
#include "../include/Activites.hpp"
#include "../include/Term.hpp"

using namespace std;

void test();

int main()
{
    test();
    return 0;
}

void test(){

    cout << "\n====== TEST 1 =======\n" << endl;
    //Creating new school
    KitesurfingSchool* sw = new KitesurfingSchool("SurfWojtek", "ul.Super Projekt", "123 456 789", "www.projektyna5.pl");
    sw->showInfo();
    //Now some info shoube be visible, otherwise it is a error


    //Creating new Client
    cout << "\n====== Creating new Client =======\n" << endl;
    Client* p = new Client(2782, "Piotr", "Czajkowski", 22, 78, "Male",130,2);
    Client* s = new Client(288, "Super", "Project", 80, 80, "Male");
    cout << *p << endl;
    cout << *s << endl;
    //Now some info shoube be visible, otherwise it is a error, 
    //Client s should be have price = 130 , and hours = 0

    //Creating new Instructors
    cout << "\n====== Creating new Instructors =======\n" << endl;
    Instructor* w = new Instructor(2, "Wojciech", "Marosek", 22, 70, "Male", 50, 100);
    Instructor* t = new Instructor(28, "Super", "Project", 80, 80, "Male", 30);
    cout << *w << endl;
    cout << *t << endl;
    //Now some info shoube be visible, otherwise it is a error, 
    //Instructor t should be have hours = 0


    //Creating new Kites
    cout << "\n====== Creating new Kites =======\n" << endl;
    Kite* k = new Kite(1,"Nobile", 10);
    Kite* k2 = new Kite(2,"Nobile", 8);
    Kite* k3 = new Kite(3,"Nobile", 8);
    cout << *k << endl;
    cout << *k2 << endl;
    cout << *k3 << endl;
    //Now some info shoube be visible, otherwise it is a error

    //Adding Kite to school
    cout << "\n====== Adding Kite to school =======\n" << endl;
    sw->addKite(k);
    sw->addKite(k2);
    sw->addKite(k3);
    sw->printKiteList();
    //Print the whole list of kite, otherwise it is a error

    //Hiring instrutor and adding Instructor to school
    cout << "\n====== Adding Instructor to school =======\n" << endl;

    sw->addInstructor(t);
    sw->addInstructor(3,"Nowy", "Instructor", 20, 60,"Female", 30,20);
    sw->addInstructor(5, "Jerzy","Myszka",21,60,"Male",50,20);
    sw->addInstructor(w);
    sw->printInstructorList();
    //Print 3 element list of kite, otherwise it is a error

    //Resign instructor and remove from list
    cout << "\n====== Resign Instructor from school =======\n" << endl;

    sw->resignInstructor(t);
    sw->printInstructorList();

    cout << "\n====== Adding Client to school =======\n" << endl;
    //Adding Client
    sw->addClient(p);
    sw->addClient(s);
    sw->addClient(10, "Adam", "Kowalski", 12, 58, "Male", 130,2);
    sw->addClient(102, "Robet", "Musial", 12, 58, "Male", 130,2);
    sw->addClient(100, "Michal", "Kaniuk", 20, 58, "Male",130,2);
    sw->printClientList();

    cout << "\n====== Adding Activities to school =======\n" << endl;
    //Create Activites
    sw->addActivite(3,p,k,12,15,1,1);
    Activites* a = new Activites(2,s,10,12,1,1,k2);
    sw->addActivite(a);
    sw->printActiviteList();

    sw->addActivite(23,p,k3,13,15,1,1);
    sw->printActiviteList();
    //Don't add this activites because this time this kite is using 

    Client* u = sw->findClient(102);
    if(u!=NULL){
        sw->addActivite(35,u,k,15,18,1,1);
        sw->addActivite(36,u,k,15,18,2,1);
        sw->addActivite(37,u,k,15,18,5,1);
        sw->addActivite(38,u,k,10,12,4,1);

        sw->printActiviteList();
    }
    
    sw->printInstructorList();

    cout << "\n====== Printing Activities of client =======\n" << endl;

    //Schedule client
    sw->printScheduleClient(102);

    cout << "\n====== Printing Activities of instrutor =======\n" << endl;

    //Schedule instructor
    sw->printClientOfInstructor(5);
    sw->printClientOfInstructor(3);
    sw->printScheduleClient(288);
    Instructor* in3 = sw->findInstructor(3);
    cout << *in3 << endl;

    cout << "\n====== Paying salary  =======\n" << endl;

    //Paying salarry
    sw->paySalary(5);
    Instructor* in = sw->findInstructor(5);
    cout << *in << endl;

    cout << "\n====== Getting pay  =======\n" << endl;

    //Getting pay
    cout << *u << endl;
    u->getPay();
    cout << *u << endl;

    cout << "\n====== Removing Activities  =======\n" << endl;

    //Remove Activite
    sw->removeActivite(35);
    sw->removeActivite(23);
    sw->printActiviteList();

    //Remove all activite
    sw->clearActivite();
    sw->printActiviteList();
    //List is empty

    cout << "\n====== Removing Clients  =======\n" << endl;

    //Remove all client
    sw->clearClient();
    sw->printClientList();
        //List is empty

    cout << "\n====== Removing Kites  =======\n" << endl;

    //Remove all kites
    sw->clearKite();
    sw->printKiteList();
    //List is empty


    //Remove all instrutor
   //sw->clearInstructor();
    sw->printInstructorList();
    //List is empty



}
