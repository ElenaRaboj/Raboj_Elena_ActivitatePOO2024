#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

//relatii has a si is a
//subordonare->is a 
//seminar 11

using namespace std;
class Angajat {
protected:
	string nume;
	int marca;
	float salariu;

public:
	Angajat() {
		this->marca = 1234;
		this->nume = "no name";
		this->salariu = 3000;
	}

	Angajat(int marca, string nume,float salariu) {
		this->marca = marca;
		this->nume = nume;
		this->salariu = salariu;
	}
	/*float getSalariu() {
		return this->salariu;
	}*/
	virtual float getVenitIncasat() = 0;

};
class Cercetator :public Angajat {
public:
	Cercetator(string nume, int marca, float salariu) :Angajat(marca, nume, salariu) {

	}
	float getVenitIncasat() {
		return this->salariu;
	}

};
class Manager: public Angajat {
private:
	int nrSubordonati;
	float sporPerSubordonat;

public:
	Manager() :Angajat() {
		this->nrSubordonati = 0;
		this->sporPerSubordonat = 0;
	}
	Manager(int nrSubordonati, float sporPerSubordonat) :Angajat() {
		this->nrSubordonati = nrSubordonati;
		this->sporPerSubordonat = sporPerSubordonat;
	}
	float getSporConducere() {
		return this->nrSubordonati * this->sporPerSubordonat;
	}
  };

class ManagerDepartament :public Manager {
private:
	string numeDepartament;
	bool deCercetare;
public:
	ManagerDepartament() : Manager() {
		this->numeDepartament = "departament";
		this->deCercetare = false;
	}

	ManagerDepartament(string nume, bool deCercetare, int nrSubordonati, float sporPerSubordonat):Manager(nrSubordonati, sporPerSubordonat) {
		this->numeDepartament = nume;
		this->deCercetare = deCercetare;
	}
		float getVenitIncasat() {
			float venit = this->salariu;
			venit += this->getSporConducere();
			if (this->deCercetare) {
				venit += (10 / 100) * salariu;
			}

		return venit;
	}
};

class ManagerDeProiect :public Manager {
private:
	string numeProiect;
	int nrZile;
	float sporPerZi;
public:
	ManagerDeProiect() :Manager() {
		this->numeProiect = "project";
		this->nrZile = 0;
		this->sporPerZi = 0;
	}

	ManagerDeProiect( string nume,int nrZile,float sporPerZi,int nrSubordonati,float sporPerAngajat) :Manager(nrSubordonati, sporPerAngajat) {
		this->numeProiect = nume;
		this->nrZile = nrZile;
		this->sporPerZi = sporPerZi;

	}

	float getVenitIncasat() {
		float venit = this->salariu;
		venit += this->getSporConducere();
		venit += (this->nrZile * this->getVenitIncasat());
		
		return venit;
	}
};
int main() {
	//ManagerDepertament = md;
	Angajat* pointer;
	pointer = new ManagerDepartament();
	pointer->getVenitIncasat();
	int nrAngajati = 5;
	Angajat** vector = new Angajat * [nrAngajati];
	vector[0] = new ManagerDepartament();
	vector[1] = new ManagerDeProiect();
	vector[2] = new ManagerDeProiect("todo list", 10, 30, 3, 15);
	vector[3] = new ManagerDepartament("ai", true, 10, 15);
	vector[4] = new Cercetator("popescu",9876,6000);
	for(int i=0;i<nrAngajati;i++){
		cout << (i + 1) << "." << vector[i]->getVenitIncasat();
}}