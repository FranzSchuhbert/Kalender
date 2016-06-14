#include<iostream>
#include<math.h>
#include<string>

class Kalenderdatum
{
private:
	//Variablen für die Umrechnung in Gregorianischen und Julianischen Kalender
	int day_greg, day_jul, month_greg, month_jul, year_greg, year_jul;
	//Int zum Durchzählen der Tage ab 1.1.4712 v.Chr.
	int lt;
	
	// Private Memberfunktionen die in den Public Funktionen verwendet werden
	//Berechnet Monatskorrektur mk jeweils für Julianischen und Gregorianischen Kalender
	int get_mk_jul();
	int get_mk_greg();
	//Umrechnung von Datum im Julianischem Kalender in laufende Tage lt
	void jul_to_lt();	
	//Umrechnung von Datum im Gregorianischen Kalender in laufende Tage lt
	void greg_to_lt();
	//Umrechnung von laufendem Tag ab 1.1.... in jul. Datum
	void lt_to_jul();	
	//Umrechnung von laufendem Tag ab 1.1.... in greg. Datum
	void lt_to_greg();
	
	
	//Funktionen zum einlesen und ausgeben der Daten
	void einlesen_jul(){
		std::cout << "Geben Sie ein Julianisches Datum ein.\nBitte hintereinander Tag, Monat und Jahr eingeben:\n";
		std::cin >> day_jul;
		std::cin >> month_jul;
		std::cin >> year_jul;
		std::cout << "\n";
		jul_to_lt();
	}
	void einlesen_greg(){
		std::cout << "Geben Sie ein Gregorianisches Datum ein.\nBitte hintereinander Tag, Monat und Jahr eingeben:\n";
		std::cin >> day_greg;
		std::cin >> month_greg;
		std::cin >> year_greg;
		std::cout << "\n";
		greg_to_lt();
	}
	void einlesen_lt(){
		std::cout << "Geben Sie eine Anzahl an Tagen ein, die seit dem 01.01.4715 v.Chr. vergangen sind.\n";
		std::cin >> lt;
		std::cout << "\n";
	}
	void ausgabe_lt(){
		std::cout << "Für Ihre Eingabe sind seit dem 01.01.4713 v.Chr. genau " << lt << " Tage vergangen.\n";
	}
	void ausgabe_jul(){
		if (year_jul>0){
		std::cout << "Im julianischen Kalender ist das der " << day_jul << "." << month_jul << "." << year_jul << " n.Chr.\n";
		}
		else{
		std::cout << "Im julianischen Kalender ist das der " << day_jul << "." << month_jul << "." << abs(year_jul) << " v.Chr.\n";
		}
	}
	void ausgabe_greg(){
		if (year_greg>0){
		std::cout << "Im gregorianischen Kalender ist das der " << day_greg << "." << month_greg << "." << year_greg << " n.Chr.\n";
		}
		else{
		std::cout << "Im gregorianischen Kalender ist das der " << day_greg << "." << month_greg << "." << abs(year_greg) << " v.Chr.\n";
		}
	}

	
	
	//Emergency function
	void emergencyStop (int i) const;
public:
	//Konstruktoren und Destruktoren
	Kalenderdatum()			{this->lt = 1;}
	Kalenderdatum( int lt )		{this->lt = lt;}
	Kalenderdatum( int , int , int , std::string );
	
	// Big Three
	
	
	// Access Methods
	long int tage () const { return this->lt; }
	
	//Entscheidung was man eingeben will um Umrechnung in laufende Tage lt
	void inputform(){
		std::cout << "Was möchten Sie eingeben? Bitte wählen Sie\n1) Für ein Datum im gregorianischen Kalender\n2) Für ein Datum im julianischen Kalender\n3) Für eine Anzahl von vergangenen Tagen seit dem 01.01.4713 v.Chr.\n";
		int decide;
		std::cin >> decide;
		std::cout << "\n";
		switch ( decide ){
			case 1 :	einlesen_greg();
					break;
			case 2 :	einlesen_jul();
					break;
			case 3 :	einlesen_lt(); break;
			default :	emergencyStop(2);
			}
	}
	
	
	//Entscheidung was man ausgeben will und Berechnung aus laufenden Tagen lt
	void outputform(){
		int decide;
		std::cout << "Was möchten Sie ausgeben? Bitte wählen Sie\n1) Für ein Datum im gregorianischen Kalender\n2) Für ein Datum im julianischen Kalender\n3) Für eine Anzahl von vergangenen Tagen seit dem 01.01.4713 v.Chr.\n";
		std::cin >> decide;
		std::cout << "\n";
		switch ( decide ){
			case 1 :	lt_to_greg();
					ausgabe_greg();
					break;
			case 2 : 	lt_to_jul();
					ausgabe_jul();
					break;
			case 3 : 	ausgabe_lt(); break;
			default : 	emergencyStop(3);
		}
	}
};

// Error exit
class KalenderdatumException : std::exception{};
void Kalenderdatum::emergencyStop (int i) const{
	std::cout << std::endl << "+++ Error in class Kalenderdatum; Error number: " << i << std::endl;
	throw new KalenderdatumException;
}


// globaler Operator der Abstand zwischen zwei Kalenderdaten berechnet in Tagen
long int operator - (const Kalenderdatum X, const Kalenderdatum Y ){
	return abs( X.tage() - Y.tage() );
}


// Operatoren die auf private Member zugreifen dürfen
Kalenderdatum::Kalenderdatum( int a, int b, int c, std::string d){
	if ( d == "j" ){
		day_jul		= a;
		month_jul	= b;
		year_jul	= c;
		jul_to_lt();
	}
	else if ( d == "g" ){
		day_greg	= a;
		month_greg	= b;
		year_greg	= c;
		greg_to_lt();
	}
	else { emergencyStop(1); }
}
int Kalenderdatum::get_mk_jul(){
	int mk;
	switch (month_jul){
		case 1 : 
		case 4 :
		case 5 : mk=-1; 	break;
		case 3 : mk=-2; 	break;
		case 8 : mk=1; 		break;
		case 9 :
		case 10 : mk=2; 	break;
		case 11 :
		case 12 : mk=3; 	break;
		default : mk=0;
	}
	return mk;
}
int Kalenderdatum::get_mk_greg(){
	int mk;
	switch (month_greg){
		case 1 : 
		case 4 :
		case 5 : mk=-1; 	break;
		case 3 : mk=-2; 	break;
		case 8 : mk=1; 		break;
		case 9 :
		case 10 : mk=2; 	break;
		case 11 :
		case 12 : mk=3; 	break;
		default : mk=0;
	}
	return mk;
}
void Kalenderdatum::jul_to_lt(){
	//Hilfsvariablen für die Rechnungen
	int sk, mk, N4, N1, tag, jahr;
	//Setzt sk auf 1 wenn Schaltjahr und Monat nach Februar liegt
	if ( month_jul > 2 && ((year_jul<0 && (abs(year_jul%4)==1)) || (year_jul>0 && (year_jul%4==0))) ){
		sk=1;
	}
	else{
		sk=0;
	}
	//Setzt die Korrektur der Tage je nach Monat
	mk = get_mk_jul();
	tag = day_jul + 30*(month_jul-1) + sk + mk;
	jahr = 4715 + year_jul;
	if ( year_jul < 0 ){
	jahr++;}
	N4 = jahr/4;
	N1 = jahr%4;
	if ( N1 == 4 ){
		N1 = 3;
		tag = 365;
	}
	lt = 1461*N4 + 365*(N1-3) + tag;
}
void Kalenderdatum::greg_to_lt(){
	//Hilfsvariablen für die Rechnungen
	int sk, mk, N400, R400, N100, R100, N1, N4, tag, jahr;
	//Setzt sk auf 1 wenn Schaltjahr und Monat nach Februar liegt
	if ( month_greg > 2 && ( (year_greg%4==0)&&( (year_greg%100!=0)||((year_greg%100==0)&&(year_greg%400==0))) ) ){
		sk=1;
	}
	else{
		sk=0;
	}
	mk = get_mk_greg();
	tag = day_greg + 30*(month_greg-1) + sk + mk;
	jahr = year_greg -1;
	N400 = jahr / 400;
	R400 = jahr % 400;
	N100 = R400 / 100;
	R100 = R400 % 100;
	N4 = R100 / 4;
	N1 = R100 % 4;
	lt = 1721426 + N400*146097 + N100* 36524 + N4 * 1461 + N1*365 + tag;
}
void Kalenderdatum::lt_to_jul(){
	//Hilfsvariablen
	int sk, mk, N4, R4, N1, tag, jahr;
	N4 = ( lt + 1095) / 1461;
	R4 = ( lt + 1095) % 1461;
	N1 = R4 / 365;
	tag = R4 - N1*365;
	if ( N1 == 4 ){
		N1 = 3;
		tag = 365;
	}
	jahr = 4 * N4 + N1;
	if ( jahr <= 4715){
	year_jul = -( 4716 - jahr);}
	else{
	year_jul = jahr - 4715;}
	month_jul = ( tag + 1 ) / 30 + 1;
	//sk und mk berechnen wie vorher
	if ( month_jul > 2 && ((year_jul<0 && (abs(year_jul%4)==1)) || (year_jul>0 && (year_jul%4==0)) ) ){
	sk=1;
	}
	else{
	sk=0;
	}
	mk = get_mk_jul();
	day_jul = tag - 30*(month_jul-1) - (sk + mk);
	if ( (month_jul > 12) || (day_jul < 1)){
	month_jul = month_jul - 1;
	mk = get_mk_jul();
	day_jul = tag - 30*(month_jul-1) - (sk + mk) ;
	}
}
void Kalenderdatum::lt_to_greg(){
	//Hilfsvariablen
	int sk, mk, N400, R400, N100, R100, N4, R4, N1, tag, jahr;
	N400 = (lt - 1721426) / 146097;
	R400 = (lt - 1721426) % 146097;
	N100 = R400 / 36524;
	R100 = R400 % 36524;
	if ( (N100==4)&&(R100==0) ){
		N100 = 3;
		R100 = 36524;
	}
	N4 = R100 / 1461;
	R4 = R100 % 1461;
	N1 = R4 / 365;
	tag = R4 % 365;
	if ( (N1==4)&&(tag==0) ){
		N1 = 3;
		tag = 365;
	}
	jahr = 400*N400 + 100*N100 + 4*N4 + N1;
	year_greg = jahr + 1;
	month_greg = ( tag + 1 ) / 30 + 1;
	//sk und mk berechnen wie vorher
	if ( month_greg > 2 && ( (year_greg%4==0)&&( (year_greg%100!=0)||((year_greg%100==0)&&(year_greg%400==0))) ) ){
		sk=1;
	}
	else{
		sk=0;
	}
	mk = get_mk_greg();
	day_greg = tag - 30*(month_greg-1) - (sk + mk);
	if ( (month_greg > 12) || (day_greg < 1)){
	month_greg = month_greg - 1;
	mk = get_mk_greg();
	day_greg = tag - 30*(month_greg-1) - (sk + mk);
	}	
}
//Gibt Datum in Tagen aus für unter 1000 Tage, sonst in Jahren
void ausgabe_abstand(Kalenderdatum X, Kalenderdatum Y){
	if ( X - Y > 1000 ){
	std::cout << "Die eingegebenen Daten liegen " << (X - Y) / 365.2425 << " Jahre auseinander.\n";
	}
	else{
	std::cout << "Die eingegebenen Daten liegen " << X-Y << " Tage auseinander.\n";
	}
}
