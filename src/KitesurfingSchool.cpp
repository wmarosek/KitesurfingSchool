#include "../include/KitesurfingSchool.hpp"
#include "../include/Instructor.hpp"
#include "../include/Client.hpp"
#include "../include/Kite.hpp"
#include "../include/Activites.hpp"

using namespace std;

KitesurfingSchool::KitesurfingSchool(string name, string adress, string tel, string site)
{
    cout << "Creating new Kitesurfing School" << endl;
    this->name = name;
    this->site = site;
    this->adress = adress;
    this->tel = tel;
}

KitesurfingSchool::~KitesurfingSchool()
{
    cout << "\nKiteSurfing school deleted!" << endl;
}

void KitesurfingSchool::showInfo(){
    cout << name << "\n" << adress << "\n" <<  tel << "\n" << site << "\nCount of instructors: "<< listOfInstructor.size() <<  endl;
}


/*==================
   CLIENT METHODS
==================*/



/*Creating new Client and adding to list*/
void KitesurfingSchool::addClient(int id, string name, string surname, int age, int weight, string sex, int price, int hours){
    if(listOfClient.empty()){
        if(age<1 || weight<40 || (sex!="Male" && sex!="Female")  || price <0 || hours <0 || listOfInstructor.empty()){
            cout << "Invalid data" << endl;
        }
        else{
            Client n(id, name,surname,age,weight,sex,price,hours);
            Instructor* temp = this->findTheBest();
            temp->setNumberOfClient(temp->getNumberOfClient()+1);
            n.setInstructor(temp); 
            listOfClient.push_front(n);
        }
        
    }
    else{
        if(this->checkExistingClient(id)==false){
            cout << "This client already exist on list!\n\n" << endl;
        }
        else if(age<1 || weight<40 || (sex!="Male" && sex!="Female") || price <0 || hours <0 || listOfInstructor.empty()){
            cout << "Invalid data" << endl;
        }
        else{
            Client n(id,name,surname,age,weight,sex,price,hours);
            Instructor* temp = this->findTheBest();
            temp->setNumberOfClient(temp->getNumberOfClient()+1);
            n.setInstructor(temp); 
            listOfClient.push_back(n);
            listOfClient.sort();

        }

    }
}

/*Adding to list already existing client*/
void KitesurfingSchool::addClient(Client *cl){
    if(listOfClient.empty()){
        if(cl->getAge() < 1 || cl->getWeight() < 40 || (cl->getSex()!="Male" && cl->getSex()!="Female")  || cl->getPrice() <0 || cl->getHours() <0){
            cout << "Invalid data" << endl;
        }
        else{
            Instructor* temp = this->findTheBest();
            temp->setNumberOfClient(temp->getNumberOfClient()+1);
            cl->setInstructor(temp); 
            listOfClient.push_front(*cl);
        }
    }
    else{
        if(this->checkExistingClient(cl->getId())==false){
            cout << "This client already exist on list!\n\n" << endl;
        }
        else if(cl->getAge() < 1 || cl->getWeight() < 40 || (cl->getSex()!="Male" && cl->getSex()!="Female")  || cl->getPrice() <0 || cl->getHours() <0){
            cout << "Invalid data" << endl;
        }
        else{
            Instructor* temp = this->findTheBest();
            temp->setNumberOfClient(temp->getNumberOfClient()+1);
            cl->setInstructor(temp); 
            listOfClient.push_back(*cl);
            listOfClient.sort();

        }

    }
}

/*Printing whole Client list*/
void KitesurfingSchool::printClientList()
{   
    cout << "\n=====List of Client!=====" << endl;    

    if(listOfClient.empty()){
        cout << "List is empty!" << endl;
    }
    else{
        list<Client>::iterator it;
        for (it = listOfClient.begin(); it != listOfClient.end(); it++)
        {
            cout << *it;
            cout << "Instructor:\n" << it->getInstructor()->getId() << ". " << it->getInstructor()->getName()<< " " << it->getInstructor()->getSurname()<< endl;
        }
    }
   
}


void KitesurfingSchool::printClientOfInstructor(int id)
{
    Instructor *temp = findInstructor(id);
    if(temp!=NULL){
        cout << "===== "<< temp->getName() << "'s list of Clients!=====" << endl;
        if (listOfClient.empty() || temp->getNumberOfClient() == 0)
        {
            cout << "List is empty!" << endl;
        }
        else
        {
            list<Client>::iterator it;
            for (it = listOfClient.begin(); it != listOfClient.end(); it++)
            {
                if (it->getInstructor() == temp)
                {
                    cout << *it;
                    cout << "Instructor:\n" << it->getInstructor()->getId() << ". " << it->getInstructor()->getName() << " " << it->getInstructor()->getSurname() << endl;
                }
            }
        }
    }
    else{
        cout << "This instructor doesn't exist!\n" << endl;
    }
}
/*Checking that Client with this name and surname already exist*/
bool KitesurfingSchool::checkExistingClient(int id){
    list<Client>::iterator it;
    for (it = listOfClient.begin(); it != listOfClient.end(); it++)
    {            
        if(id == it->getId()){
            return false;
        }
    }
    return true;
}

void KitesurfingSchool::removeClient(Client *c){
    if(this->checkExistingClient(c->getId())==false && c!=NULL){
        list<Client>::iterator it;
        for(it = listOfClient.begin(); it!=listOfClient.end(); it++){
            if(it->getInstructor()->getId() == c->getId()){
                it->getInstructor()->setNumberOfClient(it->getInstructor()->getNumberOfClient()-1);
                it->setInstructor(NULL);
                break;
            }
        }
        if(it->getInstructor()==NULL){
            listOfClient.remove(*c);
            delete c;
            c = NULL;            
        }
    }
    else{
        cout << "This client doesn't exist!\n" << endl;
    }
}

void KitesurfingSchool::removeClient(int id){
    if(this->checkExistingClient(id)==false){
        Client* c = findClient(id);
        if(c!=NULL){
            list<Client>::iterator it;
            for(it = listOfClient.begin(); it!=listOfClient.end(); it++){
                if(it->getInstructor()->getId() == c->getId()){
                    it->getInstructor()->setNumberOfClient(it->getInstructor()->getNumberOfClient()-1);
                    it->setInstructor(NULL);
                    break;
                }
            }
            if(it->getInstructor()==NULL){
                listOfClient.remove(*c);
                delete c;
                c = NULL;            
            }
        }
       
    }
    else{
        cout << "This client doesn't exist!\n" << endl;
    } 
}

Client* KitesurfingSchool::findClient(int id){
    if(checkExistingClient(id)==false){
        list<Client>::iterator it;
        Client* temp = &listOfClient.front();
        for (it = listOfClient.begin(); it != listOfClient.end(); it++)
        {  
            if(it->getId() == id){
                temp = &(*it);
            }
        }
        return temp;
    }
    return NULL;
}

void KitesurfingSchool::clearClient(){
    if(listofActivites.empty()){
        cout << "The whole list of client removed!" << endl;
        list<Instructor>::iterator it;
        for (it = listOfInstructor.begin(); it != listOfInstructor.end(); it++)
        {
            it->setNumberOfClient(0);
        }
        listOfClient.clear();
    }
    else{
        cout << "\nTo clear list of Clients you have to remove all activites!" << endl;
    }

}


/*==================
   INSTRUCTOR METHODS
  ==================*/


/*Creating new Client and adding to list*/
void KitesurfingSchool::addInstructor(int id,string name, string surname, int age, int weight, string sex, int salary, int workedHours){
    if(listOfInstructor.empty()){
        Instructor in(id,name,surname,age,weight,sex,salary,workedHours);
        listOfInstructor.push_front(in);
    }
    else{
        if(this->checkExistingInstructor(id)==false){
            cout << "This client already exist on list!\n\n" << endl;
        }
        else if(age<1 && weight>=40 && (sex=="Male" || sex=="Female") && salary<0 && workedHours <0 ){
            cout << "Invalid data" << endl;
        }
        else{
            Instructor in(id,name,surname,age,weight,sex,salary, workedHours);
            listOfInstructor.push_back(in);
            listOfInstructor.sort();
        }

    }
}

/*Adding to list already existing instructor*/
void KitesurfingSchool::addInstructor(Instructor *in){
    if(listOfInstructor.empty() && in!=NULL){
        listOfInstructor.push_front(*in);
    }
    else if(in!=NULL){
        if(this->checkExistingInstructor(in->getId())==false){
            cout << "This instructor already exist on list!\n\n" << endl;
        }
        else{
             listOfInstructor.push_back(*in);
             listOfInstructor.sort();
        }
    }
    else{
        cout << "This instructor isn't valid\n";
    }
    
}

/*Printing whole Instructor list*/
void KitesurfingSchool::printInstructorList()
{
    cout << "\n=====List of Instructor!=====" << endl;
    if(listOfInstructor.empty()){
    cout << "List is empty!" << endl;
    }
    else{
        int i=1;
        list<Instructor>::iterator it;
        for (it = listOfInstructor.begin(); it != listOfInstructor.end(); it++)
        {
            
            cout << *it << endl;
            i++;
        }     
    }
}



bool KitesurfingSchool::checkExistingInstructor(int id){
    list<Instructor>::iterator it;
    for (it = listOfInstructor.begin(); it != listOfInstructor.end(); it++)
    {            
        if(id == it->getId()){
            return false;
        }
    }
    return true;
}

//Resign instructor and remove from list,
// but first it check that instructor have some client if he have finding new for client
void KitesurfingSchool::resignInstructor(Instructor *in){
    if(this->checkExistingInstructor(in->getId())==false){
        list<Client>::iterator it;
        for(it = listOfClient.begin(); it!=listOfClient.end(); it++){
            if(it->getInstructor()->getId() == in->getId()){
                Instructor* temp = this->findTheBest();
                temp->setNumberOfClient(temp->getNumberOfClient()+1);
                it->setInstructor(temp); 

            }
        }
        if(in->getNumberOfClient()==0){
            listOfInstructor.remove(*in);
            delete in;
            in = NULL;            
        }
    }    
}

//Resign instructor and remove from list,
// but first it check that instructor have some client if he have finding new for client
void KitesurfingSchool::resignInstructor(int id){
    if(this->checkExistingInstructor(id)==false){
        list<Client>::iterator it;
        for(it = listOfClient.begin(); it!=listOfClient.end(); it++){
            if(it->getInstructor()->getId() == id){
                Instructor* temp = this->findTheBest();
                temp->setNumberOfClient(temp->getNumberOfClient()+1);
                it->setInstructor(temp); 

            }
        }
        Instructor* in = findInstructor(id);
        if(in->getNumberOfClient()==0 && in!=NULL){
            listOfInstructor.remove(*in);
            delete in;
            in = NULL;            
        }
    }    
}

Instructor* KitesurfingSchool::findInstructor(int id){
    if(checkExistingInstructor(id)==false){
        list<Instructor>::iterator it;
        Instructor* temp = &listOfInstructor.front();
        for (it = listOfInstructor.begin(); it != listOfInstructor.end(); it++)
        {  
            if(it->getId() == id){
                temp = &(*it);
            }
        }
        return temp;
    }
    return NULL;
}


Instructor* KitesurfingSchool::findTheBest(){
    list<Instructor>::iterator it;
    Instructor* temp = &listOfInstructor.front();
    for (it = listOfInstructor.begin(); it != listOfInstructor.end(); it++)
    { 
        if(it->getNumberOfClient() < temp->getNumberOfClient()){
            temp = &(*it);
        }
    }
    return temp;
}

Instructor* KitesurfingSchool::findTheBestWithout(Instructor *in){
    list<Instructor>::iterator it;
    Instructor* temp = &listOfInstructor.front();
    for (it = listOfInstructor.begin(); it != listOfInstructor.end(); it++)
    {
        if(*in == *it){
            continue;
        }
        else if(it->getNumberOfClient() < temp->getNumberOfClient()){
            temp = &(*it);
        }
    }
    return temp;
}
void KitesurfingSchool::clearInstructor(){
    if(listofActivites.empty()){
        listOfInstructor.clear();

    }
    else{
        cout << "\nTo clear list of instructors you have to remove all activites!" << endl;  
    }
}
void KitesurfingSchool::paySalary(int id){
    Instructor* in = findInstructor(id);

    cout << "Paying salary to " << in->getName() << " equal to " << (in->getSalary()*in->getWorkedHours())<< endl;
    in->setWorkedHours(0);
}
/*==================
     KITE METHODS
  ==================*/


//Adding to list already existing kite
void KitesurfingSchool::addKite(Kite *k)
{  
    if(listOfKite.empty()){
        listOfKite.push_front(*k);
    }
    else{
        if(checkExistingKite(k->getId())==true && k!=NULL){
            listOfKite.push_back(*k);
            listOfKite.sort();
        }
        else{
            cout << "Kite of this id already exist!\n"; 
        }
    } 

}

/*Printing list of kite*/
void KitesurfingSchool::printKiteList(){
    cout << "\n=====List of Kites!=====\n" << endl;
    list<Kite>::iterator it;
    if(listOfKite.empty()){
        cout << "List is empty!" << endl;
    }
    else{
        for (it = listOfKite.begin(); it != listOfKite.end(); it++)
        {
            cout << *it;
        }
    }

}

void KitesurfingSchool::removeKite(int id){
    if(listOfKite.size()!=0)
    {    
        list<Kite>::iterator it;
        for (it = listOfKite.begin(); it != listOfKite.end(); it++)
        {
            if(it->getId()==id){
                break;
            }
        }
        listOfKite.erase(it);
    }
    else{
        cout << "List is already empty" << endl;
    }
}

void KitesurfingSchool::clearKite(){
    if(listofActivites.empty()){
        listOfKite.clear();
    }
    else {
        cout << "\nTo clear list of kites you have to remove all activites!" << endl;
    }
}

bool KitesurfingSchool::checkExistingKite(int id){
    list<Kite>::iterator it;
    for (it = listOfKite.begin(); it != listOfKite.end(); it++)
    {            
        if(id == it->getId()){
            return false;
        }
    }
    return true;
}

/*======================
     ACTIVITE METHODS
 =======================*/




void KitesurfingSchool::addActivite(int id, Client *c, Kite* k, int startTime, int endTime, int day,int month){
    if(listofActivites.empty()){
            Term* t = new Term(startTime,endTime,day,month);
            Activites *temp = new Activites(id, c, t, k);
            list<Client>::iterator it;
            for (it = listOfClient.begin(); it != listOfClient.end(); it++)
            {  
                if(it->getId() == c->getId()){
                    temp->setInstructor(it->getInstructor());
                }
            }
            listofActivites.push_front(*temp);
            Client* c = findClient(temp->getClient()->getId());
            Instructor* in = findInstructor(c->getInstructor()->getId());
            int h = abs((temp->getTerm()->getEnd())-(temp->getTerm()->getStart()));
            c->setHours(c->getHours()+h);
            in->setWorkedHours(in->getWorkedHours()+h);
        }
    else{
        Term* t = new Term(startTime,endTime,day,month);
        list<Activites>::iterator it;
        bool free = true;
        for (it = listofActivites.begin(); it != listofActivites.end(); it++){
            if((*(it->getTerm())==*t && it->getKite() == k) || ((*(it->getTerm()))==*t && (it->getClient()->getInstructor() == c->getInstructor() && it->getClient()==c ))){
                free=false;
            }
        }
        if(free==true){
            Activites *temp = new Activites(id, c, t, k);
            list<Client>::iterator it;
            for (it = listOfClient.begin(); it != listOfClient.end(); it++)
            {  
                if(it->getId() == c->getId()){
                    temp->setInstructor(c->getInstructor());
                }
            }
            listofActivites.push_back(*temp); 
            Client* c = findClient(temp->getClient()->getId());
            Instructor* in = findInstructor(c->getInstructor()->getId());
            int h = abs((temp->getTerm()->getEnd())-(temp->getTerm()->getStart()));
            c->setHours(c->getHours()+h);
            in->setWorkedHours(in->getWorkedHours()+h);
            listofActivites.sort();
        }
    } 
}



void KitesurfingSchool::addActivite(Activites* a){
    if(listofActivites.empty()){
            list<Client>::iterator it;
            for (it = listOfClient.begin(); it != listOfClient.end(); it++)
            {  
                if(it->getId() == a->getClient()->getId()){
                    a->setInstructor(it->getInstructor());
                }
            }
            listofActivites.push_front(*a);
            Client* c = findClient(a->getClient()->getId());
            Instructor* in = findInstructor(c->getInstructor()->getId());
            int h = abs((a->getTerm()->getEnd())-(a->getTerm()->getStart()));
            c->setHours(c->getHours()+h);
            in->setWorkedHours(in->getWorkedHours()+h);
        }
    else{
        list<Activites>::iterator it;
        bool free = true;
        for (it = listofActivites.begin(); it != listofActivites.end(); it++){
            if((*(it->getTerm())==*(a->getTerm()) &&  it->getKite() == a->getKite()) || (*(it->getTerm())==*(a->getTerm()) && (it->getClient()->getInstructor() ==a->getInstructor() && it->getClient()==a->getClient()))){
                free=false;
            }
        }
        if(free==true){
            list<Client>::iterator it;
            for (it = listOfClient.begin(); it != listOfClient.end(); it++)
            {  
                if(it->getId() == a->getClient()->getId()){
                    a->setInstructor(it->getInstructor());
                }
            }
            listofActivites.push_back(*a); 
            Client* c = findClient(a->getClient()->getId());
            Instructor* in = findInstructor(c->getInstructor()->getId());
            int h = abs((a->getTerm()->getEnd())-(a->getTerm()->getStart()));
            c->setHours(c->getHours()+h);
            in->setWorkedHours(in->getWorkedHours()+h);
            listofActivites.sort();

        }
    } 
}

void KitesurfingSchool::printActiviteList(){
    cout << "\n=====Activites!=====" << endl;
    list<Activites>::iterator it;
    if(listofActivites.empty()){
        cout << "List is empty!" << endl;
    }
    else{
        for (it = listofActivites.begin(); it != listofActivites.end(); it++)
        {
            cout << *it << endl;
        }
    }
}

void KitesurfingSchool::printScheduleClient(int id){
    Client* c = findClient(id);
    if(c!=NULL && listofActivites.size()!=0){
        list<Activites>::iterator it;
        cout << "\n===== Schedule of "<< c->getName() << " " << c->getSurname() << "!=====" << endl;
        for(it = listofActivites.begin(); it != listofActivites.end(); it++)
        {
            if(it->getClient()->getId() == c->getId()){
                cout << *it << endl;    
            }
        }
    }
    else{
        cout << "List is empty!" << endl;

    }

}

void KitesurfingSchool::printScheduleInstructor(int id){
    Instructor* in = findInstructor(id);
    if(in!=NULL && listofActivites.size()!=0){
        list<Activites>::iterator it;
        cout << "\n===== Schedule of "<< in->getName() << " " << in->getSurname() << "!=====" << endl;
        for(it = listofActivites.begin(); it != listofActivites.end(); it++)
        {
            if(it->getInstructor() == in){
                cout << *it << endl;    
            }
        }
    }
    else{
        cout << "List is empty!" << endl;

    }
}

Activites* KitesurfingSchool::findActivite(int id){
    if(checkExistingActivites(id)==false){
        list<Activites>::iterator it;
        Activites* temp = &listofActivites.front();
        for (it = listofActivites.begin(); it != listofActivites.end(); it++)
        {  
            if(it->getId() == id){
                temp = &(*it);
            }
        }
        return temp;
    }
    return NULL;
}

void KitesurfingSchool::removeActivite(int id)
{
    Activites *c = findActivite(id);
    if (c != NULL)
    {
        if (listofActivites.size() != 0)
        {
            list<Activites>::iterator it;
            for (it = listofActivites.begin(); it != listofActivites.end(); it++)
            {
                if (it->getId() == id)
                {
                    break;
                }
            }

            listofActivites.erase(it);
        }
        else
        {
            cout << "List is already empty" << endl;
        }
    }
}

void KitesurfingSchool::removeActivite(Activites* a)
{
    if (a != NULL)
    {
        if (listofActivites.size() != 0)
        {
            list<Activites>::iterator it;
            for (it = listofActivites.begin(); it != listofActivites.end(); it++)
            {
                if (it->getId() == a->getId())
                {
                    break;
                }
            }
            listofActivites.erase(it);
        }
        else
        {
            cout << "List is already empty" << endl;
        }
    }
}

bool KitesurfingSchool::checkExistingActivites(int id){
    list<Activites>::iterator it;
    for (it = listofActivites.begin(); it != listofActivites.end(); it++)
    {            
        if(id == it->getId()){
            return false;
        }
    }
    return true;
}

void KitesurfingSchool::clearActivite(){
    listofActivites.clear();
}


