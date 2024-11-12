#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//sa se creeze o clasa, cu atributele trecute in partea privata a clasei,iar metode+functii in public;
// va contine un constructor implict, constructor cu toti parametrii, destructorul clase, constructorul de copiere
//se va realiza o metoda  ce returneaza o medie
//se vor realiza supraincarcari de operatori
//se vor afisa si testa in main

class Oras {
private:
	char* denumire;
	float suprafata;
	int NrLocuitori;
	int* varste;
	bool esteInRomania;
	static int nrOrase;// imi incrementeaza numarul de orase
	const int ID;

public:
	//constructor fara fara parametrii
	Oras() :ID(0) {
		this->denumire = NULL;
		this->suprafata = 0;
		this->NrLocuitori = 0;
		this->varste = NULL;
		this->esteInRomania = false;
		nrOrase++;
	}
	//constructor cu toti parametrii
	Oras(const char* denumire, float suprafata, int NrLocuitori, int* varste, bool esteInRomania, int ID) :ID(ID) {
		this->denumire = new char[strlen(denumire) + 1];
		strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
		this->suprafata = suprafata;
		this->esteInRomania = esteInRomania;
		this->NrLocuitori = NrLocuitori;
		this->varste = new int[this->NrLocuitori];
		for (int i = 0;i < this->NrLocuitori;i++) {
			this->varste[i] = varste[i];
		}
		nrOrase++;
	}
	//destructor
	~Oras() {
		if (this->denumire != NULL) {
			delete[]this->denumire;
		}if (this->varste != NULL) {
			delete[]this->varste;

		}
		Oras::nrOrase--; //ca sa nu am pierderi de memorie
	}

	//constructor de copiere

	Oras(const Oras& o) :ID(o.ID) {
		this->denumire = new char[strlen(o.denumire) + 1];
		strcpy_s(this->denumire, strlen(o.denumire) + 1, o.denumire);
		this->suprafata = o.suprafata;
		this->esteInRomania = o.esteInRomania;
		this->NrLocuitori = o.NrLocuitori;
		this->varste = new int[o.NrLocuitori];
		for (int i = 0;i < o.NrLocuitori;i++) {
			this->varste[i] = o.varste[i];
		}
		nrOrase++;


	}

	//operator=
	Oras operator=(const Oras& o) {
		if (this != &o) {
			if (this->varste != NULL)
			{
				delete[]this->varste;
			}
			this->denumire = new char[strlen(o.denumire) + 1];
			strcpy_s(this->denumire, strlen(o.denumire) + 1, o.denumire);
			this->suprafata = o.suprafata;
			this->esteInRomania = o.esteInRomania;
			this->NrLocuitori = o.NrLocuitori;
			this->varste = new int[o.NrLocuitori];
			for (int i = 0;i < o.NrLocuitori;i++) {
				this->varste[i] = o.varste[i];
			}
			nrOrase++;

		}
		return *this;

	}
	//get+set

	char* getDenumire() {
		return this->denumire;
	}
	void setDenumire(const char* denumire) {
		if (this->denumire != NULL) {
			delete[]this->denumire;
		}
		this->denumire = new char[strlen(denumire) + 1];
		strcpy_s(this->denumire, strlen(denumire) + 1, denumire);
	 }


	float getSuprafata() {
		return this->suprafata;
	}
	void setSuprafata(float suprafata) {
		this->suprafata = suprafata;
	}

	//calculare VarstaMedie
	float getVarstaMedie() {
		int varsta = 0;
		if (this->varste != NULL)
		{
			for (int i = 0;i < this->NrLocuitori;i++) {
				varsta = varsta + this->varste[i];
			}
		}
		else {
			return 0;
		}
		return varsta / this->NrLocuitori;
	}

	void afisare() {
		if (this->denumire != NULL) {
			cout << "orasul se numeste: " << this->denumire;
		}
		else {
			cout << "nu avem oras!";
		}cout << endl;
		cout << "orasul are ID-ul: " << this->ID << endl;
		cout << "Orasul are o suprafata de: " << this->suprafata << endl;
		if (this->esteInRomania == true) {
			cout << "orasul este in romania!";
		}
		else {
			cout << "orasul nu se afla in Romania!";
		}cout << endl;
		cout << "avem un numar de locuitori: " << this->NrLocuitori << endl;
		if (this->varste != NULL) {
			cout << " locuitorii au varstele de:" << " " << endl;
			for (int i = 0;i < this->NrLocuitori;i++) {
				cout << this->varste[i] << " ";
			}
		}
		else {
			cout << " nu avem locuitori!";
		}cout << endl;
		cout << "numarul oraselor este: " << Oras::nrOrase << endl;
		cout << endl;
	}
	friend ostream& operator<<(ostream& out, Oras o);

	friend istream& operator>>(istream& input, Oras& r) {
		if (r.denumire != NULL) {
			delete[]r.denumire;
		} 
		r.denumire = new char[strlen(r.denumire) + 1];
		strcpy_s(r.denumire, strlen(r.denumire) + 1, r.denumire);
		
		cout << "suprafata: " << endl;
		input >> r.suprafata;
		if (r.esteInRomania == true) {
			cout << "este in romania" << endl;
			input >> r.esteInRomania;
		}
		else {
			cout << "nu este in romania!" << endl;
		}

		cout << "numar de locuitori: " << endl;
		input >> r.NrLocuitori;
		if (r.varste != NULL) {
			cout << "varstele sunt:";
			for (int i = 0;i < r.NrLocuitori;i++) {
				input >> r.varste[i];
			}
		}
		else {
			cout << "nu avem locuitori" << endl;
		}return input;

	}
	//operator+
	Oras operator+ (Oras o) const {
		Oras temp = *this;
		temp.suprafata = this->suprafata + o.suprafata;
		return temp;
	}
	//operator +=
	Oras operator+=(Oras o) {
		this->suprafata += o.suprafata;
		return *this;
	}

		//operator cast, operator functie
	 explicit operator float() {
		return this->suprafata;
		}

	explicit operator int() {
		return this->NrLocuitori;
	}
	//operator >
	bool operator>(Oras o) {
		return this->NrLocuitori > o.NrLocuitori;
	}
	//operator ==
	bool operator==(Oras o) {
		return this->suprafata == o.suprafata;
	}
	//operator index
	int& operator[](int index) {
		if (index > 0 && index < this->NrLocuitori)
		{
			return this->varste[index];
		}
		
	}
	
}; int Oras::nrOrase = 0;

//operator<<
ostream& operator<<(ostream& out, Oras o ) {
	out << "denumire:"<<o.denumire << endl;
	out << "suprafata:"<<o.suprafata << endl;
	out << "numar de locuitori: "<<o.NrLocuitori << endl;
	if (o.NrLocuitori != NULL) {
		for (int i = 0;i < o.NrLocuitori;i++) {
			out << o.varste[i] << " ";
		}
	}
	if (o.esteInRomania == true) {
		out << "orasul este in romania" << o.esteInRomania << endl;
	}
	else {
		return
			out << "nu este in romania!" << endl;
	}
	out << "id ul orasului este: " << o.ID << endl;
	out << "orasul cu numarul: " << Oras::nrOrase << endl;
	return out;
}


int main() {
	Oras oras1;
	oras1.afisare();
	Oras oras2("valcea", 600, 4, new int[4] {34, 12, 56, 22}, true, 3);
	oras2.afisare();

	Oras oras3(oras2);
	oras3.afisare();

	oras1 = oras2;
	oras1.afisare();

	Oras oras4("iasi", 800, 5, new int[5] {10, 6, 80, 5, 6}, true, 6);
	oras4.afisare();

	cout << "orasul se numeste:" << oras2.getDenumire() << endl;
	oras4.setDenumire("craiova");
	oras4.afisare();
	cout << "supafata orasului este: " << oras3.getSuprafata() << endl;
	oras1.setSuprafata(200);
	oras1.afisare();
	cout << "varsta medie a orasului este:" << oras2.getVarstaMedie() << endl;
	cout << oras2;
	cin >> oras1;

	Oras oras5;
	oras5 = oras2 + oras4;
	oras1 += oras2;
	float b = (float)oras2;
	int a = (int)oras2;
	oras3 > oras2;
	oras4 = oras5;
	cout << "locuitorul de pe pozitia 3 are varsta:" << oras2[2] << endl;
	
}