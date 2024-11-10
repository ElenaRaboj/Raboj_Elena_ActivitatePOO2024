#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

class Floare {
private:

	string numeFloare;
	const int id_floare;
	static  float  TVAfloare;
	char* culoare;

public:
	static float getTvaFloare() {
		return Floare::TVAfloare;
	}

	// constructor implicit
	Floare() : id_floare(2) {

		this->numeFloare = "lalea";
		;	this->culoare = new char[strlen("rosie") + 1];
		strcpy_s(this->culoare, strlen("rosie") + 1, "rosie");

	}

	// constructor cu toti parametrii
	Floare(string numeFloare, int id_floare, const char* culoare) : id_floare(id_floare) {
		this->numeFloare = numeFloare;
		this->culoare = new char[strlen(culoare) + 1];
		strcpy_s(this->culoare, strlen(culoare) + 1, culoare);


	}

	// constructor cu 2 parametrii
	Floare(string numeFloare, const char* culoare) : id_floare(6) {
		this->numeFloare = numeFloare;
		this->culoare = new char[strlen(culoare) + 1];
		strcpy_s(this->culoare, strlen(culoare) + 1, culoare);
	}
	//constructor de copiere
	Floare(const Floare& f) : id_floare(f.id_floare) {
		this->numeFloare = f.numeFloare;
		this->culoare = new char[strlen(f.culoare) + 1];
		strcpy_s(this->culoare, strlen(f.culoare) + 1, f.culoare);

	}

	void afisare() {

		cout << "numeFloare:" << this->numeFloare << endl;
		cout << "id floare:" << this->id_floare << endl;
		cout << "TVA Floare:" << this->TVAfloare << endl;
		cout << "culoarea:" << this->culoare << endl;


	}
	//destructor
	~Floare() {
		if (this->culoare != NULL) {
			delete[]this->culoare;
		}
	}

	string getnumeFloare() {
		return this->numeFloare;
	}

	char* getculoare() {
		return this->culoare;
	}

	void setNumeFloare(string numeFloare) {
		this->numeFloare = numeFloare;
	}
	void setCuloare(const char* culoare) {
		if (this->culoare != nullptr) {
			delete[]this->culoare;
		}  this->culoare = new char[strlen(culoare) + 1];
		strcpy_s(this->culoare, strlen(culoare) + 1, culoare);

	}
	// functie statica care  schimba tva

	static void  ModificaTva(float TVANou) {
		if (TVANou > 0) {
			Floare::TVAfloare = TVANou;
		}
	}

	//operator =(supraincarcare)
	Floare operator=(const Floare& f) {
		if (&f != this) {
			if (this->culoare != NULL) {
				delete[]this->culoare;
			}

		}
		this->numeFloare = f.numeFloare;
		this->culoare = new char[strlen(f.culoare) + 1];
		strcpy_s(this->culoare, strlen(f.culoare) + 1, f.culoare);
		return *this;
	}

	friend ostream& operator<<(ostream& out, Floare f);
	friend istream& operator>>(istream& input, Floare fo);
};
//operator<<
ostream& operator<<(ostream& out, Floare f) {
	out<< "numeFloare:" << f.numeFloare << endl;
	out << "id floare:" << f.id_floare << endl;
	out << "culoarea:" << f.culoare << endl;
	out << "TVA Floare:" << f.TVAfloare << endl;
	return out;
}
//operator>>
istream& operator>>(istream& input, Floare fo) {
	if (fo.culoare != NULL) {
		delete[]fo.culoare;
	}cout << "culoarea: ";
	input >> fo.culoare;
	fo.culoare = new char[strlen(fo.culoare) + 1];
	strcpy_s(fo.culoare, strlen(fo.culoare) + 1, fo.culoare);
	cout << "culoarea";
	input >> fo.culoare;

	return input;
}


float Floare::TVAfloare = 0.19;


class Florarie {
private:
	string NumeFlorarie;
	int NrFlori;
	int* preturi;
	const int Id_Florarie;
	static float ImpozitM2;
	string tipFloare;

public:

	static float getImpozitM2() {
		return Florarie::ImpozitM2;
	}

	//constructor implicit
	Florarie() :Id_Florarie(2) {
		this->NumeFlorarie = "RazaDeSoare";
		this->NrFlori = 0;
		this->tipFloare = "ghiocel";
		this->preturi = 0;

	}
	//constructor cu toti parametrii
	Florarie(string NumeFlorarie, int NrFlori, string tipFloare, int* preturi, int Id_Florarie) : Id_Florarie(Id_Florarie) {
		this->NumeFlorarie = NumeFlorarie;
		this->NrFlori = NrFlori;
		this->tipFloare = tipFloare;
		this->preturi = new int[this->NrFlori];
		if (this->NrFlori != 0) {
			for (int i = 0;i < this->NrFlori;i++) {
				this->preturi[i] = preturi[i];

			}
		}
		else this->preturi = 0;
	}

	// constructor cu 3 parametrii
	Florarie(string numeFlorarie, string tipFloare, int Id_Florarie) :Id_Florarie(Id_Florarie) {
		this->NumeFlorarie = numeFlorarie;
		this->tipFloare = tipFloare;
		this->preturi = nullptr;
		this->NrFlori = NULL;
	}

	//constructor de copiere
	Florarie(const Florarie& flor) :Id_Florarie(flor.Id_Florarie) {
		this->NumeFlorarie = flor.NumeFlorarie;
		this->tipFloare = flor.tipFloare;
		this->NrFlori = flor.NrFlori;
		this->preturi = new int[flor.NrFlori];
		for (int i = 0;i < flor.NrFlori;i++) {
			this->preturi[i] = flor.preturi[i];
		}


	}
	string getNumeFlorarie() {
		return this->NumeFlorarie;
	}
	string getTipFloare() {
		return this->tipFloare;
	}
	int getNRFlori() {
		return this->NrFlori;
	}
	int* getPreturi() {
		return this->preturi;
	}

	void setnumeflorarie(string NumeFlorarie) {
		this->NumeFlorarie = NumeFlorarie;
	}
	void setTIPFLOARE(string tipFloare) {
		this->tipFloare = tipFloare;
	}
	void setNumarFlori(int NrFlori) {
		this->NrFlori = NrFlori;
	}
	void setPreturi(int NrFlori, int* preturi) {
		if (this->preturi != NULL) {
			delete[]this->preturi;
		}this->NrFlori = NrFlori;
		this->preturi = new int[this->NrFlori];
		for (int i = 0;i < this->NrFlori;i++) {
			this->preturi[i] = preturi[i];
		}
	}

	void afisare() {
		cout << "Floraria numita:" << this->NumeFlorarie << endl;
		cout << "Avand Id:" << this->Id_Florarie << endl;
		cout << "cu tipul florii:" << this->tipFloare << endl;
		cout << "are un numar de flori de:" << this->NrFlori << endl;
		cout << "se percepe un impozit pe M^2 de :" << this->ImpozitM2 << endl;
		cout << "si pretul per floare este:";
		if (preturi != NULL) {
			for (int i = 0;i < NrFlori;i++) {
				cout << preturi[i] << ",";
			}
		}
		else {
			cout << "-";
		}
		cout << endl;
	}
	//destructor
	~Florarie() {
		if (this->preturi != NULL) {
			delete[]this->preturi;
		}
	}


	//functie statica

	static void ModificaImpozitM2(int ImpozitNouM2) {
		if (ImpozitNouM2 > 0) {
			Florarie::ImpozitM2 = ImpozitNouM2;
		}
	}
	//operator =(supraincarcare)

	Florarie operator=(const Florarie& flor) {
		if (&flor != NULL) {
			if (this->preturi != NULL) {
				delete[]this->preturi;
			}
			this->NumeFlorarie = flor.NumeFlorarie;
			this->tipFloare = flor.tipFloare;
			this->NrFlori = flor.NrFlori;
			this->preturi = new int[flor.NrFlori];
			for (int i = 0;i < flor.NrFlori;i++) {
				this->preturi[i] = flor.preturi[i];
			}
		}return *this;
	}
	//operator ++
	//preincrementare
	Florarie& operator++() {
		this->NrFlori++;
		return *this;
	}
	//postincrementare
	Florarie& operator++(int) {
		Florarie copie = *this;
		this->NrFlori++;
		return copie;
	}

	// operator--
	//predecrementare
	Florarie operator--() {
		this->NrFlori--;
		return*this;
	}
	//postdecrementare
	Florarie operator--(int) {
		Florarie copie = *this;
		this->NrFlori--;
		return copie;
	}

	friend ostream& operator<<(ostream& out, Florarie flor);
	friend istream& operator>>(istream& input, Florarie fl);
};
float Florarie::ImpozitM2 = 10;


ostream& operator<<(ostream& out, Florarie flor) {
	out << "Floraria numita:" << flor.NumeFlorarie << endl;
	out << "Avand Id:" << flor.Id_Florarie << endl;
	out << "cu tipul florii:" << flor.tipFloare << endl;
	out << "are un numar de flori de:" <<flor.NrFlori << endl;
	out << "se percepe un impozit pe M^2 de :" << flor.ImpozitM2 << endl;
	out << "si pretul per floare este:";
	for (int i = 0;i < flor.NrFlori;i++) {
		out << flor.preturi[i] << " "<<endl;
	}
	return out;
}
//operator>>
istream& operator>>(istream& input, Florarie fl) {
	cout << "floraria" << endl;
	input >> fl.NumeFlorarie;
	cout << "tip floare" << endl;
	input >> fl.tipFloare;
	if (fl.preturi != NULL) {
		delete[]fl.preturi;
	}cout << " preturile florilor sunt";
	for (int i = 0;i < fl.NrFlori;i++) {
		input >> fl.preturi[i];
	}cout << endl;
	return input;
}


class Clienti {
private:
	char* adresa;
	string nume;
	string prenume;
	int varsta;
	static int NrClienti;
	const int Id_Client;
public:

	static int getNrClienti() {
		return Clienti::NrClienti;
	}
	// constructor implicit:
	Clienti() : Id_Client(++NrClienti) {
		this->nume = "popescu";
		this->prenume = "ion";
		this->varsta = 20;
		this->adresa = new char[strlen("stradaA1,nr4,sector2") + 1];
		strcpy_s(this->adresa, strlen("stradaA1,nr4,sector2") + 1, "stradaA1,nr4,sector2");
	}

	// constructor cu toti parametrii

	Clienti(string nume, string prenume, int varsta, const char* adresa) :Id_Client(++NrClienti) {
		this->nume = nume;
		this->prenume = prenume;
		this->varsta = varsta;
		this->adresa = new char[strlen(adresa) + 1];
		strcpy_s(this->adresa, strlen(adresa) + 1, adresa);
	}

	// constructor cu 3 parametrii
	Clienti(string prenume, int varsta, const char* adresa) :Id_Client(++NrClienti) {
		this->nume = "";
		this->prenume = prenume;
		this->varsta = varsta;
		this->adresa = new char[strlen(adresa) + 1];
		strcpy_s(this->adresa, strlen(adresa) + 1, adresa);


	}
	//constructor de copiere
	Clienti(const Clienti& c) :Id_Client(++c.NrClienti) {
		this->nume = c.nume;
		this->prenume = c.prenume;
		this->varsta = c.varsta;
		this->adresa = new char[strlen(c.adresa) + 1];
		strcpy_s(this->adresa, strlen(c.adresa) + 1, c.adresa);
	}

	string getNume() {
		return this->nume;
	}
	string getPrenume() {
		return this->prenume;
	}
	char* getadresa() {
		return this->adresa;
	}
	int getvarsta() {
		return this->varsta;
	}

	void setAdresa(const char* adresa) {
		if (this->adresa != nullptr) {
			delete[]this->adresa;
		}  this->adresa = new char[strlen(adresa) + 1];
		strcpy_s(this->adresa, strlen(adresa) + 1, adresa);
	}
	void setNume(string nume) {
		this->nume = nume;
	}
	void setPrenume(string prenume) {
		this->prenume = prenume;
	}
	void setVarsta(int varsta) {
		this->varsta = varsta;
	}




	void afisare() {
		cout << "Clientul cu numele:" << this->nume << endl;
		cout << "si prenumele:" << this->prenume << endl;
		cout << " cu adresa:" << this->adresa << endl;
		cout << " avand id ul:" << this->Id_Client << endl;
		cout << " si varsta:" << this->varsta << endl;
		cout << "numar total de clienti:" << this->NrClienti << endl;
	}


	//destructor
	~Clienti() {
		if (this->adresa != NULL) {
			delete[]this->adresa;
		}
	}

	//functie statica care returneaza numarul de clienti

	static int getNumarClienti() {
		return NrClienti;
	}

	// o functie globala care afiseaza numele si varsta unui client
	friend void AfiseazaNumesiVarsta(const Clienti& c);


	//operator =(supraincarcare)

	Clienti operator=(const Clienti& c) {
		if (&c != NULL) {
			if (this->adresa != NULL) {
				delete[]this->adresa;
			}
		}
		this->nume = c.nume;
		this->prenume = c.prenume;
		this->varsta = c.varsta;
		this->adresa = new char[strlen(c.adresa) + 1];
		strcpy_s(this->adresa, strlen(c.adresa) + 1, c.adresa);
		return *this;
	}
	// operator+
	Clienti operator+(Clienti c) {
		Clienti temp = *this;
		temp.varsta = this->varsta + c.varsta;
		return *this;
	}
	// operator+=
	Clienti operator+=(Clienti c) {
		this->varsta += c.varsta;
		return *this;
	}
	friend ostream& operator<<(ostream& out, Clienti c);
	friend istream& operator>>(istream&, Clienti cli);

};
int Clienti::NrClienti = 0;

ostream& operator<<(ostream& out, Clienti c) {
	out << "Clientul cu numele:" << c.nume << endl;
	out << "si prenumele:" << c.prenume << endl;
	out << " cu adresa:" << c.adresa << endl;
	out << " avand id ul:" << c.Id_Client << endl;
	out << " si varsta:" << c.varsta << endl;
	out << "numar total de clienti:" << c.NrClienti << endl;
	return out;
}

istream& operator>>(istream& input, Clienti cli) {
	if (cli.adresa != NULL) {
		delete[]cli.adresa;
	}cout << "adresa" << endl;
	input >> cli.adresa;
	cout << "numele" << endl;
	cin >> cli.nume;
	cout << "prenumele" << endl;
	cin >> cli.prenume;
	cout << "varsta" << endl;
	cin >> cli.varsta;
	return input;
  }

void AfiseazaNumesiVarsta(const Clienti& c) {
	cout << "Nume: " << c.nume << endl;
	cout << "varsta: " << c.varsta << endl;
}
int main() {

	Clienti c1;
	c1.afisare();
	Clienti c2("Tanase", "Ana", 18, "stradaA2,nr5,sector1");
	c2.afisare();
	Clienti c3("Anghel", 12, "stradaA3,nr8,sector6");
	c3.afisare();
	cout << Clienti::getNumarClienti() << endl;

	Floare f1;
	f1.afisare();
	Floare f2("trandafir", 15, "roz");
	Floare* pointer = new Floare("bujor", 14, "mov");
	pointer->afisare();
	Floare f3("liliac", "mov");
	f3.afisare();
	Floare::ModificaTva(0.2);
	f1.afisare();
	f2.afisare();
	f3.afisare();


	Florarie flor1;
	flor1.afisare();
	int* preturi;
	preturi = new int[3];
	preturi[0] = 1;
	preturi[1] = 10;
	preturi[2] = 8;
	Florarie flor2("zambet", 3, "trandafir", preturi, 6);
	flor2.afisare();
	Florarie flor3("love", "zambila", 7);
	flor3.afisare();
	Florarie::ModificaImpozitM2(12);
	flor1.afisare();
	flor2.afisare();
	flor3.afisare();
	Floare f4(f2);
	f4.afisare();
	Florarie flor4(flor3);
	flor4.afisare();
	Clienti c4(c2);
	c4.afisare();
	cout << f2.getnumeFloare() << endl;
	cout << f2.getculoare() << endl;
	cout << flor2.getNumeFlorarie() << endl;
	cout << flor3.getTipFloare() << endl;
	cout << flor1.getNRFlori() << endl;
	for (int i = 0;i < flor3.getNRFlori();i++) {
		cout << flor3.getPreturi()[i] << "-";
	}
	cout << endl;
	cout << c2.getNume() << endl;
	cout << c2.getPrenume() << endl;
	cout << c2.getadresa() << endl;
	cout << c2.getvarsta() << endl;
	cout << c2.getNumarClienti << endl;

	f3.setNumeFloare("Zambila");
	f3.setCuloare("alba");
	flor3.setnumeflorarie("coquette");
	flor3.setTIPFLOARE("azalee");
	flor2.setPreturi(2, new int[2] {4, 5});

	c2.setNume("ciobanu");
	c2.setPrenume("alexandru");
	c2.setAdresa("sector3,strA4,nr3");
	c2.setVarsta(29);
	AfiseazaNumesiVarsta(c2);

	//// operator =
	c1 = c2;
	c1.afisare();
	f1 = f2;
	f1.afisare();
	flor1 = flor2;
	flor1.afisare();
	flor2 = ++flor1;// preincremenatare
	flor2 = flor1++; //postincrementare
	flor2 = --flor1;// predecrementare
	flor2 = flor1--;//postdecrementare
	// operator <<
	cout << f1;
	cout << c2;
	cout << flor3;
	cin >> f2;
	cin >>c4;
	cin >> flor2;
	c3 = c2 + c1;
	c2 += c1;
}