/**********************************************************************************************************************************
David Eiber, Daniel Lang
Blatt 1, Aufgabe 1-3, Kalenderklasse
C++ Kurs Sommersemester 2016
**********************************************************************************************************************************/


#include<iostream>
#include<math.h>
#include<string>

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



// Error exit
class KalenderdatumException : std::exception{};
void Kalenderdatum::emergencyStop (int i) const{
	std::cout << std::endl << "+++ Error in class Kalenderdatum; Error number: " << i << std::endl;
	throw new KalenderdatumException;
}

// globale Operatoren
long int operator- (const Kalenderdatum X, const Kalenderdatum Y ){
	return abs( X.tage() - Y.tage() );
}

// Operatoren die auf private Member zugreifen dürfen
Kalenderdatum Kalenderdatum::operator+ (long int x){
	lt = lt + x;
	return *this;
}
Kalenderdatum Kalenderdatum::operator- (long int x){
	lt = lt - x;
	return *this;
}
Kalenderdatum::Kalenderdatum( int a, int b, int c, std::string d){
	if ( d == "j" ){
		lt = jul_to_lt(a, b, c);
	}
	else if ( d == "g" ){
		lt = greg_to_lt(a, b, c);
	}
	else { emergencyStop(1); }
}
Kalenderdatum::~Kalenderdatum(){}
int Kalenderdatum::get_mk_jul(int b){
	int mk;
	switch (b){
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
Kalenderdatum & Kalenderdatum::operator= (const Kalenderdatum &x){
	if (this != &x){
		lt = x.lt;
	}
	return *this;
}
int Kalenderdatum::get_mk_greg(int b){
	int mk;
	switch (b){
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
long int Kalenderdatum::jul_to_lt( int a, int b, int c){
	//Hilfsvariablen für die Rechnungen
	int sk, mk, N4, N1, tag, jahr;
	//Setzt sk auf 1 wenn Schaltjahr und Monat nach Februar liegt
	if ( b > 2 && ((c<0 && (abs(c%4)==1)) || (c>0 && (c%4==0))) ){
		sk=1;
	}
	else{
		sk=0;
	}
	//Setzt die Korrektur der Tage je nach Monat
	mk = get_mk_jul(b);
	tag = a + 30*(b-1) + sk + mk;
	jahr = 4715 + c;
	if ( c < 0 ){
	jahr++;}
	N4 = jahr/4;
	N1 = jahr%4;
	if ( N1 == 4 ){
		N1 = 3;
		tag = 365;
	}
	lt = 1461*N4 + 365*(N1-3) + tag;
	return lt;
}
long int Kalenderdatum::greg_to_lt(int a, int b, int c){
	//Hilfsvariablen für die Rechnungen
	int sk, mk, N400, R400, N100, R100, N1, N4, tag, jahr;
	//Setzt sk auf 1 wenn Schaltjahr und Monat nach Februar liegt
	if ( b > 2 && ( (c%4==0)&&( (c%100!=0)||((c%100==0)&&(c%400==0))) ) ){
		sk=1;
	}
	else{
		sk=0;
	}
	mk = get_mk_greg(b);
	tag = a + 30*(b-1) + sk + mk;
	jahr = c -1;
	N400 = jahr / 400;
	R400 = jahr % 400;
	N100 = R400 / 100;
	R100 = R400 % 100;
	N4 = R100 / 4;
	N1 = R100 % 4;
	lt = 1721426 + N400*146097 + N100* 36524 + N4 * 1461 + N1*365 + tag;
	return lt;
}
int* Kalenderdatum::lt_to_jul(long int lt){
	//Hilfsvariablen
	int sk, mk, N4, R4, N1, tag, jahr;
	static int date_jul [3];
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
	date_jul[3] = -( 4716 - jahr);}
	else{
	date_jul[3] = jahr - 4715;}
	date_jul[2] = ( tag + 1 ) / 30 + 1;
	//sk und mk berechnen wie vorher
	if ( date_jul[2] > 2 && ((date_jul[3]<0 && (abs(date_jul[3]%4)==1)) || (date_jul[3]>0 && (date_jul[3]%4==0)) ) ){
	sk=1;
	}
	else{
	sk=0;
	}
	mk = get_mk_jul(date_jul[2]);
	date_jul[1] = tag - 30*(date_jul[2]-1) - (sk + mk);
	if ( (date_jul[2] > 12) || (date_jul[1] < 1)){
	date_jul[2] = date_jul[2] - 1;
	mk = get_mk_jul(date_jul[2]);
	date_jul[1] = tag - 30*(date_jul[2]-1) - (sk + mk) ;
	}
	return date_jul;
}
int* Kalenderdatum::lt_to_greg(long int lt){
	//Hilfsvariablen
	int sk, mk, N400, R400, N100, R100, N4, R4, N1, tag, jahr;
	static int date_greg [3];
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
	date_greg[3] = jahr + 1;
	date_greg[2] = ( tag + 1 ) / 30 + 1;
	//sk und mk berechnen wie vorher
	if ( date_greg[2] > 2 && ( (date_greg[3]%4==0)&&( (date_greg[3]%100!=0)||((date_greg[3]%100==0)&&(date_greg[3]%400==0))) ) ){
		sk=1;
	}
	else{
		sk=0;
	}
	mk = get_mk_greg(date_greg[2]);
	date_greg[1] = tag - 30*(date_greg[2]-1) - (sk + mk);
	if ( (date_greg[2] > 12) || (date_greg[1] < 1)){
	date_greg[2] = date_greg[2] - 1;
	mk = get_mk_greg(date_greg[2]);
	date_greg[1] = tag - 30*(date_greg[2]-1) - (sk + mk);
	}
	return date_greg;
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
long int Kalenderdatum::einlesen_jul(){
	int day_jul, month_jul, year_jul;
	long int lt;
	std::cout << "Geben Sie ein Julianisches Datum ein.\nBitte hintereinander Tag, Monat und Jahr eingeben:\n";
	std::cin >> day_jul;
	std::cin >> month_jul;
	std::cin >> year_jul;
	std::cout << "\n";
	lt	=	jul_to_lt(day_jul, month_jul, year_jul);
	return lt;
}
long int Kalenderdatum::einlesen_greg(){
	int day_greg, month_greg, year_greg;
	long int lt;
	std::cout << "Geben Sie ein Gregorianisches Datum ein.\nBitte hintereinander Tag, Monat und Jahr eingeben:\n";
	std::cin >> day_greg;
	std::cin >> month_greg;
	std::cin >> year_greg;
	std::cout << "\n";
	lt	=	greg_to_lt(day_greg, month_greg, year_greg);
	return lt;
}
long int Kalenderdatum::einlesen_lt(){
	long int lt;
	std::cout << "Geben Sie eine Anzahl an Tagen ein, die seit dem 01.01.4715 v.Chr. vergangen sind.\n";
	std::cin >> lt;
	std::cout << "\n";
	return lt;
}
void Kalenderdatum::ausgabe_lt(){
	std::cout << "Für Ihre Eingabe sind seit dem 01.01.4713 v.Chr. genau " << lt << " Tage vergangen.\n";
}
void Kalenderdatum::ausgabe_jul(){
	int *date_jul=lt_to_jul(lt);
	if (date_jul[3]>0){
	std::cout << "Im julianischen Kalender ist das der " << date_jul[1] << "." << date_jul[2] << "." << date_jul[3] << " n.Chr.\n";
	}
	else{
	std::cout << "Im julianischen Kalender ist das der " << date_jul[1] << "." << date_jul[2] << "." << abs(date_jul[3]) << " v.Chr.\n";
	}
}
void Kalenderdatum::ausgabe_greg(){
	int *date_greg=lt_to_greg(lt);
	if (date_greg[3]>0){
	std::cout << "Im gregorianischen Kalender ist das der " << date_greg[1] << "." << date_greg[2] << "." << date_greg[3] << " n.Chr.\n";
	}
	else{
	std::cout << "Im gregorianischen Kalender ist das der " << date_greg[1] << "." << date_greg[2] << "." << abs(date_greg[3]) << " v.Chr.\n";
	}
}
void Kalenderdatum::inputform(){
	std::cout << "Was möchten Sie eingeben? Bitte wählen Sie\n1) Für ein Datum im gregorianischen Kalender\n2) Für ein Datum im julianischen Kalender\n3) Für eine Anzahl von vergangenen Tagen seit dem 01.01.4713 v.Chr.\n";
	int decide;
	std::cin >> decide;
	std::cout << "\n";
	switch ( decide ){
		case 1 :	lt	=	einlesen_greg();
				break;
		case 2 :	lt	=	einlesen_jul();
				break;
		case 3 :	lt	=	einlesen_lt(); break;
		default :	emergencyStop(2);
		}
}
void Kalenderdatum::outputform(){
	int decide;
	std::cout << "Was möchten Sie ausgeben? Bitte wählen Sie\n1) Für ein Datum im gregorianischen Kalender\n2) Für ein Datum im julianischen Kalender\n3) Für eine Anzahl von vergangenen Tagen seit dem 01.01.4713 v.Chr.\n";
	std::cin >> decide;
	std::cout << "\n";
	switch ( decide ){
		case 1 :	lt_to_greg(lt);
				ausgabe_greg();
				break;
		case 2 : 	lt_to_jul(lt);
				ausgabe_jul();
				break;
		case 3 : 	ausgabe_lt(); break;
		default : 	emergencyStop(3);
	}
}
std::string Kalenderdatum::wochentag(long int lt){
	int x = (lt + 0 ) % 7;
	std::string a;
	switch ( x ) {
	case 0 : 	a = "Montag";		break;
	case 1 : 	a = "Dienstag";		break;
	case 2 : 	a = "Mittwoch";		break;
	case 3 : 	a = "Donnerstag";	break;
	case 4 : 	a = "Freitag";		break;
	case 5 : 	a = "Samstag";		break;
	case 6 : 	a = "Sonntag";		break;
	}
	return a;
}
std::string Kalenderdatum::wochentag(int a2, int b, int c, std::string d){
	Kalenderdatum x(a2, b, c, d);
	int y = (x.lt + 0) % 7;
	std::string a;
	switch ( y ) {
	case 0 : 	a = "Montag";		break;
	case 1 : 	a = "Dienstag";		break;
	case 2 : 	a = "Mittwoch";		break;
	case 3 : 	a = "Donnerstag";	break;
	case 4 : 	a = "Freitag";		break;
	case 5 : 	a = "Samstag";		break;
	case 6 : 	a = "Sonntag";		break;
	}
	return a;
}
int* Kalenderdatum::easterdate(long int lt){
	int *date_greg = lt_to_greg(lt);
	int a,b,c,d,e,k,m,n,p,q;
	static int date [3];
	
	a	=	date_greg[3] % 19;
	b	=	date_greg[3] % 4;
	c	=	date_greg[3] % 7;
	k	=	date_greg[3] / 100;
	p	=	(8*k + 13) / 25;
	q	=	k / 4;
	m	=	(15 + k - p - q) % 30;
	d	=	(19*a + m) % 30;
	n	=	(4 + k - q) % 7;
	e	=	(2*b + 4*c + 6*d + n) % 7;
	if ( 22 + d + e < 32){
		date[1]	= 22 + d + e;
		date[2]	= 3;
	}
	else {
		date[1] = d + e - 9;
		date[2] = 4;
	}
	if ( (date[1] == 26) && (date[2] == 4)){
		date[1] = 19;
	}
	if ( (date[1]==25) && (date[2]==4) && (d==28) && (e==6) && (((11*m + 11) % 30) < 19) ){
		date[1] = 18;
	}
	date[3] = date_greg[3];
	return date;
}
int* Kalenderdatum::weiberfastnacht(long int lt){
	int* date = easterdate(lt);
	Kalenderdatum x(date[1], date[2], date[3], "g");
	x = x - 52;
	date = x.lt_to_greg(lt);
	static int weiberfastnacht [2];
	weiberfastnacht[1] = date[1];
	weiberfastnacht[2] = date[2];
	weiberfastnacht[3] = date[3];
	return weiberfastnacht;
}
int* Kalenderdatum::rosenmontag(long int lt){
	int* date = easterdate(lt);
	Kalenderdatum x(date[1], date[2], date[3], "g");
	x = x - 48;
	date = x.lt_to_greg(x.lt);
	static int rosenmontag [2];
	rosenmontag[1] = date[1];
	rosenmontag[2] = date[2];
	rosenmontag[3] = date[3];
	return rosenmontag;
}
int* Kalenderdatum::fastnachtdienstag(long int lt){
	int* date = easterdate(lt);
	Kalenderdatum x(date[1], date[2], date[3], "g");
	x = x - 47;
	date = x.lt_to_greg(x.lt);
	static int fastnachtdienstag [2];
	fastnachtdienstag[1] = date[1];
	fastnachtdienstag[2] = date[2];
	fastnachtdienstag[3] = date[3];
	return fastnachtdienstag;
}
int* Kalenderdatum::aschermittwoch(long int lt){
	int* date = easterdate(lt);
	Kalenderdatum x(date[1], date[2], date[3], "g");
	x = x - 46;
	date = x.lt_to_greg(x.lt);
	static int aschermittwoch [2];
	aschermittwoch[1] = date[1];
	aschermittwoch[2] = date[2];
	aschermittwoch[3] = date[3];
	return aschermittwoch;
}
int* Kalenderdatum::gruendonnerstag(long int lt){
	int* date = easterdate(lt);
	Kalenderdatum x(date[1], date[2], date[3], "g");
	x = x - 3;
	date = x.lt_to_greg(x.lt);
	static int gruendonnerstag [2];
	gruendonnerstag[1] = date[1];
	gruendonnerstag[2] = date[2];
	gruendonnerstag[3] = date[3];
	return gruendonnerstag;
}
int* Kalenderdatum::karfreitag(long int lt){
	int* date = easterdate(lt);
	Kalenderdatum x(date[1], date[2], date[3], "g");
	x = x - 2;
	date = x.lt_to_greg(x.lt);
	static int karfreitag [2];
	karfreitag[1] = date[1];
	karfreitag[2] = date[2];
	karfreitag[3] = date[3];
	return karfreitag;
}
int* Kalenderdatum::ostermontag(long int lt){
	int* date = easterdate(lt);
	Kalenderdatum x(date[1], date[2], date[3], "g");
	x = x + 1;
	date = x.lt_to_greg(x.lt);
	static int ostermontag [2];
	ostermontag[1] = date[1];
	ostermontag[2] = date[2];
	ostermontag[3] = date[3];
	return ostermontag;
}
int* Kalenderdatum::christihimmel(long int lt){
	int* date = easterdate(lt);
	Kalenderdatum x(date[1], date[2], date[3], "g");
	x = x + 39;
	date = x.lt_to_greg(x.lt);
	static int christihimmel [2];
	christihimmel[1] = date[1];
	christihimmel[2] = date[2];
	christihimmel[3] = date[3];
	return christihimmel;
}
int* Kalenderdatum::mariahimmel(long int lt){
	int* date = easterdate(lt);
	Kalenderdatum x(date[1], date[2], date[3], "g");
	x = x + 46;
	date = x.lt_to_greg(x.lt);
	static int mariahimmel [2];
	mariahimmel[1] = date[1];
	mariahimmel[2] = date[2];
	mariahimmel[3] = date[3];
	return mariahimmel;
}
int* Kalenderdatum::pfingstsonntag(long int lt){
	int* date = easterdate(lt);
	Kalenderdatum x(date[1], date[2], date[3], "g");
	x = x + 49;
	date = x.lt_to_greg(x.lt);
	static int pfingstsonntag [2];
	pfingstsonntag[1] = date[1];
	pfingstsonntag[2] = date[2];
	pfingstsonntag[3] = date[3];
	return pfingstsonntag;
}
int* Kalenderdatum::pfingstmontag(long int lt){
	int* date = easterdate(lt);
	Kalenderdatum x(date[1], date[2], date[3], "g");
	x = x + 50;
	date = x.lt_to_greg(x.lt);
	static int pfingstmontag [2];
	pfingstmontag[1] = date[1];
	pfingstmontag[2] = date[2];
	pfingstmontag[3] = date[3];
	return pfingstmontag;
}
int* Kalenderdatum::fronleichnam(long int lt){
	int* date = easterdate(lt);
	Kalenderdatum x(date[1], date[2], date[3], "g");
	x = x + 60;
	date = x.lt_to_greg(x.lt);
	static int fronleichnam [2];
	fronleichnam[1] = date[1];
	fronleichnam[2] = date[2];
	fronleichnam[3] = date[3];
	return fronleichnam;
}
