#include <stdio.h>
#include <string>
#include <list>
#include <iostream>

using namespace std;

class Rating
{
private:
    int stars;
    string name;
    string Comment;
public:
    Rating (int, string, string);
    Rating (const Rating &);
    int getstars();
    string getname ();
    string getComment ();
};

Rating::Rating (int s, string n, string comment)
{
    stars = s;
    name = n;
    Comment = comment;
}

Rating::Rating (const Rating & R)
{
    stars = R.stars;
    name = R.name;
    Comment = R.Comment;
}

int Rating::getstars ()
{
    return stars;
}

string Rating::getname ()
{
    return name;
}

string Rating::getComment ()
{
    return Comment;
}

class Constr {
	int code;
	string name;
	string mail;
	
public:
	Constr(int,string,string);
	int getCode();
	string getName();
	string getMail();
	
};

Constr::Constr(int _code,string _name,string _mail) {
	code = _code;
	name = _name;
	mail = _mail;

}

int Constr::getCode() {
	int code;
}
string Constr::getName(){
	return name;
}

string Constr::getMail() {
	return mail;
}


class App {
	protected:
	string code;
	Constr *constructor;
	string version;
	float timh;
	list<Rating *> Ratings;

public:
	App(string,Constr *,string,float);
	App(const App &);
	void AddRating(Rating *);
	virtual void Print(ostream &) = 0;		//pure virtual 
	void ShowRatings(ostream &);
};

App::App(string c,Constr *cons,string v,float t) {
	code =c;
	constructor=cons;
	version=v;

	timh = t;
}

App::App(const App& copy) {
	
	code =copy.code;
	constructor=copy.constructor;
	version=copy.version;
	
	timh = copy.timh;
	
}

void App::AddRating( Rating *A) {
	Ratings.push_back(A);
}

void App::ShowRatings(ostream& os) {
	list <Rating *>::iterator it;
	cout<<endl<<endl<<"---ratings---"<<endl;
	for (it = Ratings.begin(); it != Ratings.end(); it++)
		os << "\tstars: " << (*it)->getstars() <<"    "<< "name: " << (*it)->getname() <<"   "<< "Comment: " << (*it)->getComment() << endl;
}

//          -------------------Game--------------------

class Game : public App {
	string name;
	bool online;
	string category;
public:
	Game(string,bool,string,string,Constr *,string,float);
	void Print(ostream &);
};


Game::Game(string _name,bool _online,string _category,string _code,Constr *cons,string v,float _timh):App (_code,cons,v,_timh) {
	name = _name;
	online=_online;
	category = _category;
	
}

void Game::Print(ostream & cha) {
	cha << "--------------------" << endl;
	cha << "Name..............:" << name << endl;
	cha << "Online............:" << online << endl;
	cha << "Category............:" << category << endl;
	cha << "Code................:" << code << endl;
	cha << "Constructor.........: " <<constructor->getName() <<"---"<<constructor->getCode()<<"---"<<constructor->getMail()<<endl;
	cha << "version................:" << version << endl;
	cha << "Timh................:" << timh << endl;
	ShowRatings(cha);

}



class Desktop : public App {
	string name;
	string typeFile;
public:
	Desktop(string,string,string,Constr*,string,float);
	void Print(ostream &);
};

Desktop::Desktop(string n,string type,string c,Constr* cons,string v,float t):App(c,cons,v,t){
	name=n;
	typeFile=type;
}

void Desktop::Print(ostream & cha) {
	cha << "--------------------" << endl;
	cha << "Name..............:" << name << endl;
	cha << "TypeFile............:" << typeFile << endl;
	cha << "Code................:" << code << endl;
	cha << "Constructor.........: " <<constructor->getName() <<"---"<<constructor->getCode()<<"---"<<constructor->getMail()<<endl;
	cha << "Timh................:" << timh << endl;
	ShowRatings(cha);
	
}
/*
class AppSystem {
	list<Efarmogh *> efarmoges;
public:
	void AddEfarm(Efarmogh *);
	void AddConst(Constr *);
	Efarmogh *listFree(string);
	
};


void AppSystem::AddEfarm(Efarmogh *E) {
	efarmoges.push_back(E);
}

void AppSystem::AddConst() */

int main (int argc, char **argv)
{
   Rating r(4,"frag","best app"); 
   Rating r1(1,"rakas","worst app"); 
   Constr cons(2,"kostas","kostas@gmail.com");
   Game app("pro evolution",true,"kategory1","1",&cons,"version1",60.2);
   app.AddRating(&r); 
   app.Print(cout);
   
   Desktop app1("fifa","typefile1","1",&cons,"version1",60.2);
   app1.AddRating(&r1); 
   app1.Print(cout);
    
 return 0;   
}


