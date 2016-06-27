/**********************************************************************************************************************************
David Eiber, Daniel Lang
Blatt 1, Aufgabe 1-3, Kalenderklasse
C++ Kurs Sommersemester 2016
**********************************************************************************************************************************/


#include "kalender.h"
using namespace std;

int main (){
	
		// Erstelle Kalenderobjekte
		Kalenderdatum date1(2421540);
		Kalenderdatum date2(25, 10, 1917, "j");
		Kalenderdatum date3(1, 1, 2000, "g");
		Kalenderdatum date4(29, 1, 2000, "g");
		// spezielle Daten für den Test von Ostern
		Kalenderdatum date5(1, 1, 1908, "j");
		Kalenderdatum date6(1, 1, 1954, "j");

		cout << "\n\nUmrechnen von Tagen in julianisches Datum:\n";
		date1.ausgabe_jul();
		cout << "\n\n";
		
		cout << "Umrechnen von julianischem Datum in Tage:\n";
		date2.ausgabe_lt();
		cout << "\n\n";
		
		cout << "Umrechnen von Tagen in gregorianisches Datum:\n";
		date1.ausgabe_greg();
		cout << "\n\n";
		
		cout << "Umrechnen von gregorianischem Datum in Tage:\n";
		date3.ausgabe_lt();
		cout << "\n\n";
		
		cout << "Berechnen des Abstands zweier Daten mit großem Abstand:\n";
		ausgabe_abstand(date2, date3);
		cout << "\n\n";
		
		cout << "Berechnen des Abstands zweier Daten mit kleinem Abstand:\n";
		ausgabe_abstand(date3, date4);
		cout << "\n\n";
		
		cout << "Berechnen des Osterdatums:\n";
		int *ostern;
		long int tage = date4.tage();
		ostern = date4.easterdate(tage);
		cout << "Ostern fällt im Jahr " << ostern[3] << " auf den " << ostern[1] << "." << ostern[2] << ".\n";
		tage = date5.tage();
		ostern = date5.easterdate(tage);
		cout << "Ostern fällt im Jahr " << ostern[3] << " auf den " << ostern[1] << "." << ostern[2] << ".\n";
		tage = date6.tage();
		ostern = date6.easterdate(tage);
		cout << "Ostern fällt im Jahr " << ostern[3] << " auf den " << ostern[1] << "." << ostern[2] << ".\n\n\n";
		
		cout << "Addieren einer Anzahl von Tagen zu einem Datum:\n";
		cout << "Ursprüngliches julianisches Datum: " << date1.tage() << "\n";
		date1 = date1 + 1000;
		cout << "Neues Datum nach Addieren von 1000 Tagen: " << date1.tage() << "\n";
		date1 = date1 -1000;
		cout << "Zurückrechnen auf das alte Datum: " << date1.tage() << "\n";
		cout << "\n\n";
		
		cout << "Berechnen der Feiertage inklusive des Wochentages:\n";
		int *feiertag;
		tage = date4.tage();
		feiertag = date4.rosenmontag(tage);
		cout << "Rosenmontag ist am " << feiertag[1] << "." << feiertag[2] << ". Das ist ein " << date4.wochentag(feiertag[1], feiertag[2], feiertag[3], "g") << ".\n";
		feiertag = date4.fastnachtdienstag(tage);
		cout << "Fastnachtdienstag ist am " << feiertag[1] << "." << feiertag[2] << ". Das ist ein " << date4.wochentag(feiertag[1], feiertag[2], feiertag[3], "g") << ".\n";
		feiertag = date4.aschermittwoch(tage);
		cout << "Aschermittwoch ist am " << feiertag[1] << "." << feiertag[2] << ". Das ist ein " << date4.wochentag(feiertag[1], feiertag[2], feiertag[3], "g") << ".\n";
		feiertag = date4.gruendonnerstag(tage);
		cout << "Gründonnerstag ist am " << feiertag[1] << "." << feiertag[2] << ". Das ist ein " << date4.wochentag(feiertag[1], feiertag[2], feiertag[3], "g") << ".\n";
		feiertag = date4.karfreitag(tage);
		cout << "Karfreitag ist am " << feiertag[1] << "." << feiertag[2] << ". Das ist ein " << date4.wochentag(feiertag[1], feiertag[2], feiertag[3], "g") << ".\n";
		feiertag = date4.ostermontag(tage);
		cout << "Ostermontag ist am " << feiertag[1] << "." << feiertag[2] << ". Das ist ein " << date4.wochentag(feiertag[1], feiertag[2], feiertag[3], "g") << ".\n";
		feiertag = date4.christihimmel(tage);
		cout << "Christihimmelfahrt ist am " << feiertag[1] << "." << feiertag[2] << ". Das ist ein " << date4.wochentag(feiertag[1], feiertag[2], feiertag[3], "g") << ".\n";
		feiertag = date4.mariahimmel(tage);
		cout << "Mariähimmelfahrt ist am " << feiertag[1] << "." << feiertag[2] << ". Das ist ein " << date4.wochentag(feiertag[1], feiertag[2], feiertag[3], "g") << ".\n";
		feiertag = date4.pfingstsonntag(tage);
		cout << "Pfingstsonntag ist am " << feiertag[1] << "." << feiertag[2] << ". Das ist ein " << date4.wochentag(feiertag[1], feiertag[2], feiertag[3], "g") << ".\n";
		feiertag = date4.pfingstmontag(tage);
		cout << "Pfingstmontag ist am " << feiertag[1] << "." << feiertag[2] << ". Das ist ein " << date4.wochentag(feiertag[1], feiertag[2], feiertag[3], "g") << ".\n";
		feiertag = date4.fronleichnam(tage);
		cout << "Fronleichnam ist am " << feiertag[1] << "." << feiertag[2] << ". Das ist ein " << date4.wochentag(feiertag[1], feiertag[2], feiertag[3], "g") << ".\n";
		cout << "\n\n";
		
		//cout << "Test für Error Nr. 1:\n";
		//Kalenderdatum date7(27, 04, 1965, "d");
		//cout << "\n\n";
		
		/* Mit Konsoleneingabe
		Kalenderdatum datek1:
		Kalenderdatum datek2;
		int decide = 3;
		cout << "Was möchten Sie berechnen? Bitte wählen Sie\n1) Für das Umwandeln eines Datums in einen anderen Kalender\n2) Für die Berechnung eines Abstandes zweier Daten\n";
		while ( (decide<1)||(decide>2)){
			cin >> decide;
			cout << "\n";
			switch ( decide ){
			case 1 :	datek1.inputform();
					datek1.outputform();
				break;
			case 2 :	cout << "Geben Sie das erste Datum ein: \n";
					datek1.inputform();
					cout << "Geben Sie das zweite Datum ein: \n";
					datek2.inputform();
					ausgabe_abstand(datek1, datek2);
				break;
		default : cout << "Ungültige Auswahl, bitte nochmal\n1) Für das Umwandeln eines Datums in eine andere Form\n2) Für die Berechnung eines Abstandes zweier Daten\n";
			}
		}*/
}