/**********************************************************************************************************************************
David Eiber, Daniel Lang
Blatt 1, Aufgabe 1-3, Kalenderklasse
C++ Kurs Sommersemester 2016
**********************************************************************************************************************************/

#ifndef __kalender_h
#define __kalender_h

#include<string>
#include<iostream>
#include<math.h>

class Kalenderdatum
{
private:
	// Memberfeld
	long int lt;
	// Error exception
	void emergencyStop (int i) const;
public:	
	// Konstruktoren, Destruktoren und Assignment Operator
	Kalenderdatum()			{this->lt = 1;}	
	Kalenderdatum( int lt )		{this->lt = lt;}
	Kalenderdatum( int , int , int , std::string );
	Kalenderdatum(const Kalenderdatum &x) { lt=x.lt; }		// Copy Constructor
	~Kalenderdatum();						// Destructor
	Kalenderdatum & operator= (const Kalenderdatum &x);		// Assignment Operator
	
	
	// Membermethoden
	long int tage () const { return this->lt; }			// Access Method
	int get_mk_jul(int);						// Berechnet Monatskorrektur
	int get_mk_greg(int);
	/* Umrechnungen zwischen den verschiedenen Kalendern. Erweiterungen um andere Kalender leicht möglich indem man hier einfach 
	Funktionen einfügt die die jeweiligen Kalender in lt umrechnen und umgekehrt.*/
	long int jul_to_lt(int, int, int);	
	long int greg_to_lt(int, int, int);
	int* lt_to_jul(long int);	
	int* lt_to_greg(long int);
	long int einlesen_jul();					// Funktionen zum Einlesen und Ausgeben der Daten
	long int einlesen_greg();
	long int einlesen_lt();
	void ausgabe_lt();
	void ausgabe_jul();
	void ausgabe_greg();
	void inputform();						// Entscheidung was man eingeben/ausgeben will
	void outputform();
	int* easterdate(long int);					// Berechnung des Osterdatums
	std::string wochentag(long int);				// Berechnung des Wochentages
	std::string wochentag(int, int, int, std::string);
	int* weiberfastnacht(long int);					// Berechnung der Feiertage die von Ostern abhängen
	int* rosenmontag(long int);
	int* fastnachtdienstag(long int);
	int* aschermittwoch(long int);
	int* gruendonnerstag(long int);
	int* karfreitag(long int);
	int* ostermontag(long int);
	int* christihimmel(long int);
	int* mariahimmel(long int);
	int* pfingstsonntag(long int);
	int* pfingstmontag(long int);
	int* fronleichnam(long int);
	Kalenderdatum operator+(long int);				// Additionsoperator
	Kalenderdatum operator-(long int);				// Subtraktionsoperator
};

void ausgabe_abstand(Kalenderdatum, Kalenderdatum);
long int operator - (const Kalenderdatum, const Kalenderdatum);

#endif
