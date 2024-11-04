#define _CRT_NO_WARNINGS
#include<iostream>
using namespace std;
//-o clasa definita Vacanta care contine atributele de mai jos
//- constructor cu toti parametrii, implicit, destructorul si constructorul de copiere
//- get + set
//- testare in main
//- calculare bugetMediu;

class Vacanta {
private:	char* destinatie;  // tarile care vor fi vizitate
	static int nrVacante; //contor al numarului de vacante
	bool inEuropa;  // este in europa sau nu
	float* buget;  // vector dinamic reprezentand bugetul alocat de fiecare persoana 
	int nrPersoane; // cate persoane se afla in vacanta
	int durataZile; // cate zile dureaza vacanta

public:
	//constructor cu toti parametrii
	Vacanta(const char*destinatie,bool inEuropa,float*buget,int nrPersoane,int durataZile) {
		this->destinatie = new char[strlen(destinatie) + 1];
		strcpy_s(this->destinatie, strlen(destinatie) + 1, destinatie);
		this->inEuropa = inEuropa;
		this->durataZile = durataZile;
		this->nrPersoane = nrPersoane;
		this->buget = new float[this->nrPersoane];
		for (int i = 0;i < this->nrPersoane;i++) {
			this->buget[i] = buget[i];
		}nrVacante++;
	}
	//constructor fara parametrii
	Vacanta() {
		this->destinatie = nullptr;
		this->inEuropa = false;
		this->durataZile = NULL;
		this->buget = NULL;
		this->nrPersoane = NULL;
		nrVacante++;
	}
	//destructor
	~Vacanta() {
		if (this->destinatie != nullptr) {
			delete[]this->destinatie;
		}
		if (this->buget != NULL) {
			delete[]this->buget;
		}
	}

	//constructor de copiere
	Vacanta(const Vacanta& v) {
		this->destinatie = new char[strlen(v.destinatie) + 1];
		strcpy_s(this->destinatie, strlen(v.destinatie) + 1, v.destinatie);
		this->inEuropa = v.inEuropa;
		this->durataZile = v.durataZile;
		this->nrPersoane = v.nrPersoane;
		this->buget = new float[this->nrPersoane];
		for (int i = 0;i < this->nrPersoane;i++) {
			this->buget[i] = v.buget[i];
		}nrVacante++;
	}

	void afisare() {
		if (this->destinatie != nullptr) {
			cout << " destinatia vacantei este: " << this->destinatie << endl;
		}
		else {
			cout << "nu avem destinatie";
		}cout << endl;

		if (this->inEuropa == true) {
			cout << " vacanta este in Europa";
		}
		else {
			cout << "vacanta nu este in europa";
		}cout << endl;

		cout << "vacanta are un numar de zile de: " << this->durataZile << endl;
		cout << "in vacanta avem un numar de persoane de:" << this->nrPersoane << endl;
		if (this->buget != NULL) {
			cout << "persoanele au bugete de: " << endl;
			for (int i = 0;i < this->nrPersoane;i++) {
				cout << this->buget[i] << " ";
			}
		}
		else {
			cout << "nu exista buget!";
		}cout << endl;
	}
	//metode accesor
	int getNumarZile() {
		return this->durataZile;
	}
	char* getDestinatie() {
		return this->destinatie;
	}
	void setDurataZile(int durataZile) {
		this->durataZile = durataZile;
	}
	void setInEuropa(bool inEuropa) {
		this->inEuropa = inEuropa;
	}
	//calcul buget mediu
	float getBugetMediu() {
		float buget = 0.0f;
		if (this->buget != NULL) {
			for (int i = 0;i < this->nrPersoane;i++) {
				buget = buget + this->buget[i];
			}
		}
		else {
			return 0;
		}return buget / this->nrPersoane;
	}
};
int Vacanta::nrVacante = 0;
int main() {
	Vacanta vac1;
	vac1.afisare();

	Vacanta vac2("Germania", true, new float[4] {1000, 1500, 2000, 1800}, 4, 2);
	vac2.afisare();

	Vacanta vac3(vac2);
	vac3.afisare();

	cout << vac2.getDestinatie() << endl;
	cout << vac1.getNumarZile() << endl;
	vac2.setDurataZile(2);
	vac2.afisare();
	vac3.setInEuropa(false);
	vac3.afisare();
	cout << "bugetul mediu al unei persoane este:" << vac2.getBugetMediu() << endl;
}