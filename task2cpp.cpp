#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;


class Floare {
public:
	
	string numeFloare;
	const int id_floare;
	static  float  TVAfloare;
	char* culoare;
	

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
		this->numeFloare =numeFloare;
		this->culoare = new char[strlen(culoare) + 1];
		strcpy_s(this->culoare, strlen(culoare) + 1, culoare);
	}

	
	void afisare() {
		
		cout << "numeFloare:" << this->numeFloare << endl;
		cout << "id floare:" << this->id_floare << endl;
		cout << "TVA Floare:" << this->TVAfloare << endl;
		cout << "culoarea:" << this->culoare << endl;


	}

	~Floare() {
		if (this->culoare!= NULL) {
			delete[]this->culoare;
		}
	}
	// functie statica care  schimba tva

	static void  ModificaTva(float TVANou) {
		if (TVANou > 0) {
			Floare::TVAfloare = TVANou;
		}
	}
};

float Floare::TVAfloare = 0.19;
/*
int main()
{
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
}
	*/

class Florarie {
public:
	string NumeFlorarie;
	int NrFlori;
	int* preturi;
	const int Id_Florarie;
	static float ImpozitM2;
	string tipFloare;


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




	void afisare() {
		cout << "Floraria numita:" << this->NumeFlorarie << endl;
		cout << "Avand Id:" << this->Id_Florarie << endl;
		cout << "cu tipul florii:" << this->tipFloare << endl;
		cout << "are un numar de flori de:" << this->NrFlori << endl;
		cout << "se percepe un impozit pe M^2 de :" << this->ImpozitM2 << endl;
		cout << "si pretul per floare este:";
		if (preturi != NULL) {
			for (int i= 0;i <NrFlori;i++) {
				cout << preturi[i] << ",";
			}
		}
		else {
			cout << "-";
		}
		cout << endl;
	}
	~Florarie() {
		if (this->preturi != NULL) {
			delete[]this->preturi;
		}
	}


	//functie statica

	static void ModificaImpozitM2(int ImpozitNouM2) {
		if (ImpozitNouM2 >0) {
			Florarie::ImpozitM2 = ImpozitNouM2;
		}
	}

};
float Florarie::ImpozitM2 = 10;
/*
int main() {

	Florarie flor1;
	flor1.afisare();

	int *preturi;
	preturi = new int[3];
	preturi[0] = 1;
	preturi[1] = 10;
	preturi[2] = 8;

	Florarie flor2("zambet",3,"trandafir",preturi,6);
	flor2.afisare();
	
	Florarie flor3("love", "zambila",7);
	flor3.afisare();
	Florarie::ModificaImpozitM2(12);
	flor2.ModificaImpozitM2(13);
	flor1.afisare();
	flor2.afisare();
	flor3.afisare();


	}*/
 
class Clienti{
public:
	char* adresa;
	string nume;
	string prenume;
	int varsta;
	static int NrClienti;
	const int Id_Client;

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
	Clienti(string prenume,int varsta, const char* adresa) :Id_Client(++NrClienti) {
		this->nume = "";
		this->prenume =prenume;
		this->varsta = varsta;
		this->adresa = new char[strlen(adresa) + 1];
		strcpy_s(this->adresa, strlen(adresa) + 1, adresa);
		
		
	}
	void afisare() {
		cout << "Clientul cu numele:" << this->nume << endl;
		cout << "si prenumele:" << this->prenume << endl;
		cout << " cu adresa:" << this->adresa << endl;
		cout << " avand id ul:" << this->Id_Client << endl;
		cout << " si varsta:" << this->varsta << endl;
		cout << "numar total de clienti:" << this->NrClienti << endl;
	}
	~Clienti() {
		if (this->adresa != NULL) {
			delete[]this->adresa;
		}
	}

	//functie statica care returneaza numarul de clienti

	static int getNumarClienti() {
		return NrClienti;
	}
};
     int Clienti::NrClienti = 0;

	 int main() {

		 Clienti c1;
		 c1.afisare();
		 Clienti c2("Tanase", "Ana", 18, "stradaA2,nr5,sector1");
		 c2.afisare();
		 Clienti c3("Anghel",12,"stradaA3,nr8,sector6");
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
	int *preturi;
	preturi = new int[3];
	preturi[0] = 1;
	preturi[1] = 10;
	preturi[2] = 8;
	Florarie flor2("zambet",3,"trandafir",preturi,6);
	flor2.afisare();
	Florarie flor3("love", "zambila",7);
	flor3.afisare();
	Florarie::ModificaImpozitM2(12);
	flor1.afisare();
	flor2.afisare();
	flor3.afisare();
	 } 