//Ágúst Örn Eiðsson	- Lokaverkefni - C++
#include "pch.h"
#include <iostream>
#include <sstream>

using namespace std;

// Geri fyrsta klassan
class Bokun {
protected:
	int plass;
	int fratekid;
public:
	int id;
	int tegund;
	Bokun(int i, int pla, int fra, int teg)
	{
		id = i;
		plass = pla;
		fratekid = fra;
		tegund = teg;
	}
	Bokun()
	{
		id = 0;
		plass = 0;
		fratekid = 0;
		tegund = 0;
	}

	void virtual Birta_bokun()
	{
		if (fratekid < 0) {
			fratekid = 0;
		}

		int prosentur = ((double)fratekid / plass) * 100;

		if (prosentur > 105) {
			cout << "Of margar bokanir";
		}
		else if (id < 0) {

		}
		else {
			std::cout << "filler " << id << " : " << fratekid << " af " << plass << " " << prosentur << "% saeti eru fratekinn" << endl;
		}
	}
	
	void fratekinsaeti(int fjoldi_saeta)//bý til bókun
	{
		if (fjoldi_saeta < 0) {
			cout << "Fjoldi saeta ma ekki vera minni en 0" << endl;
		}
		else if ((((double)fratekid + fjoldi_saeta / plass) * 100) <= 105) {
			fratekid += fjoldi_saeta;
		}
		else {
			cout << "Einhvad for urskeidis" << endl;
		}
	}

	//fjarlægi bókuð sæti
	void haettiVidBokun(int fjoldi_saeta)
	{
		if (fjoldi_saeta < 0) {
			cout << "Fjoldi saeta ma ekki vera minni en 0" << endl;
		}
		else if ((((double)fratekid - fjoldi_saeta / plass) * 100) >= 0) {
			fratekid -= fjoldi_saeta;
		}
		else {
			cout << "Einhvad for urskeidis" << endl;
		}
	}
	int returnId() {
		return id;
	}
};

//Bý flug,skip og rutur
class bokaFlug : public Bokun {
public:
	bokaFlug(int id, int plass, int fratekid, int tegund) : Bokun(id, plass, fratekid, tegund) {}
	void Birta_bokun()
	{
		if (fratekid < 0) {
			fratekid = 0;
		}

		int prosentur = ((double)fratekid / plass) * 100;

		if (prosentur > 105) {
			cout << "Thvi midur eru oll saeti fratekin";
		}
		else if (id < 0) {

		}
		else {
			std::cout << "Flug " << id << " : " << fratekid << "/" << plass << " " << prosentur << "% saeti eru fratekinn" << endl;
		}
	}

};
class bokaSkip : public Bokun {
public:
	bokaSkip(int id, int plass, int fratekid, int tegund) : Bokun(id, plass, fratekid, tegund) {}
	void Birta_bokun()
	{
		if (fratekid < 0) {
			fratekid = 0;
		}

		int prosentur = ((double)fratekid / plass) * 100;

		if (prosentur > 105) {
			cout << "Thvi midur eru oll saeti fratekin";
		}
		else if (id < 0) {

		}
		else {
			std::cout << "Skip " << id << " : " << fratekid << "/" << plass << " " << prosentur << "% saeti eru fratekinn" << endl;
		}
	}

};
class bokaRutu : public Bokun {
public:
	bokaRutu(int id, int plass, int fratekid, int tegund) : Bokun(id, plass, fratekid, tegund) {}
	void Birta_bokun()
	{
		if (fratekid < 0) {
			fratekid = 0;
		}

		int prosentur = ((double)fratekid / plass) * 100;

		if (prosentur > 105) {
			cout << "Thvi midur eru oll saeti fratekin";
		}
		else if (id < 0) {

		}
		else {
			std::cout << "Ruta " << id << " : " << fratekid << "/" << plass << " " << prosentur << "% saeti eru fratekinn" << endl;
		}
	}

};


//dynamic array
class dynamic_list {
private:
	Bokun **listinn;
	int next;
	int lengd;
public:
	dynamic_list() {
		this->lengd = 2;
		listinn = new Bokun*[lengd];
		next = 0;
	}

	//bý til functions
	void baetaVidFlug(bokaFlug x) {

		if (next <= lengd - 1)
			listinn[next++] = new bokaFlug(x);

		else {
			Bokun **temp = new Bokun*[lengd * 2];

			for (int x = 0; x < lengd; x++)
				temp[x] = listinn[x];

			delete[]listinn;
			listinn = temp;
			lengd *= 2;
			listinn[next++] = new bokaFlug(x);
		}
	}


	
	void baetiVidSkip(bokaSkip x) {
		if (next <= lengd - 1)
			listinn[next++] = new bokaSkip(x);
		else {

			Bokun **temp = new Bokun*[lengd * 2];

			for (int i = 0; i < lengd; i++)
				temp[i] = listinn[i];

			delete[]listinn;
			listinn = temp;
			lengd *= 2;
			listinn[next++] = new bokaSkip(x);
		}
	}

	void baetiVidRutu(bokaRutu x) {
		if (next <= lengd - 1)
			listinn[next++] = new bokaRutu(x);

		else {

			Bokun **temp = new Bokun*[lengd * 2];

			for (int i = 0; i < lengd; i++)
				temp[i] = listinn[i];

			delete[]listinn;
			listinn = temp;
			lengd *= 2;
			listinn[next++] = new bokaRutu(x);
		}
	}

	int id(int b , int t) {
		for (int x = 0; x < next; x++)
		{
			if (listinn[x]->id == b && listinn[x]->tegund == x) {
				return x;
			}
		}
	}
	
	void birtaFlug() {
		for (int i = 0; i < next; i++) {
			if (listinn[i]->tegund == 1) {
				listinn[i]->Birta_bokun();
			}
		}
	}
	void birtaSkip() {
		for (int i = 0; i < next; i++) {
			if (listinn[i]->tegund == 2) {
				listinn[i]->Birta_bokun();
			}
		}
	}
	void birtaRutu(){
		for (int i = 0; i < next; i++) {
			if (listinn[i]->tegund == 3) {
				listinn[i]->Birta_bokun();
			}
		}
	}


	void birta() {
		birtaFlug();
		birtaSkip();
		birtaRutu();
	}

	void add(int b, int fratekid) {
		listinn[b]->fratekinsaeti(fratekid);
	}

	void haettaVid(int b, int fratekid) {
		listinn[b]->haettiVidBokun(fratekid);
	}

	void eyda(int b) {
		listinn[b]->id = -1;
	}

	~dynamic_list() {
		delete[]listinn;
	}
};


int main() {
	dynamic_list Bokun = dynamic_list();

	Bokun.baetiVidSkip(bokaSkip(15, 600, 0, 2));
	Bokun.baetaVidFlug(bokaFlug(93, 400, 0, 1));
	Bokun.baetiVidRutu(bokaRutu(2, 80, 0, 3));

	Bokun.birta();

	string skipun = "";
	string tegund = "";

	int n;
	int id;
	int teljari = 0;
	int s = 0;
	int t = 0;

	while (skipun != "stop")
	{
		//bý til cskipanir
		cout << "Hvad viltu gera?: ";

		getline(cin, skipun);

		stringstream ss;
		ss << skipun;
		cout << endl;
		ss >> skipun >> tegund >> id >> n;

		if (tegund == "flug") {
			t = 1;
		}

		else if (tegund == "skip") {
			t = 2;
		}

		else if (tegund == "ruta") {
			t = 3;
			cout << t;
		}

		int s = Bokun.id(id,t);

		if (skipun == "add") {
			Bokun.add(s, n);
		}

		else if (skipun == "cancel") {
			Bokun.haettaVid(s, n);
		}

		else if (skipun == "create") {

			if (tegund == "skip") {
				Bokun.baetiVidSkip(bokaSkip(id, n, 0, 2));
			}

			else if (tegund == "flug") {
				Bokun.baetaVidFlug(bokaFlug(id, n, 0, 1));
			}

			else if (tegund == "ryta") {
				Bokun.baetiVidRutu(bokaRutu(id, n, 0, 3));
			}
		}

		else if (skipun == "delete") {
			Bokun.eyda(s);
		}

		Bokun.birta();
	}

	cout << endl;
	return 0;
}