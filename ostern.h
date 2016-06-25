#include "kalender.h"

int* Kalenderdatum::easterdate(){
	int *date_greg = lt_to_greg(lt);
	int a,b,c,d,e,k,m,n,p,q;
	static int date [2];
	
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
	return date;
};