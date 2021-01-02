#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>


/******************** Variables globales *******************/

/* Données de l'enonce*/

#define longIndiv 8
#define A -1
#define B 1

/********************** Typedef ******************************/


/* On décide que chaque individu est un tableau de bit */
	typedef struct individu{
		unsigned char Bit;
	}individu;
	
	
/*****************Fonctions annexes ***********************/


 /* Pour concatener les bits aléatoirement choisis */
unsigned concatenate(unsigned x, unsigned y) {
    unsigned pow = 10;
    while(y >= pow)
        pow *= 10;
    return x * pow + y;
}


unsigned r_individu(int x, unsigned a)
{
	if (x >= longIndiv)
	{
		return a;
	}
	else
	{
		struct individu TabIndiv2[longIndiv];
			int j = 2;
			int bit = rand() % j; // 0 ou 1
			TabIndiv2[x].Bit = (unsigned char)bit;	
			unsigned b = (unsigned)TabIndiv2[x].Bit;
		return r_individu(x+1, concatenate(a,b));	

	}
}

	
/* POur la conversion de binaire vers décimal */
int conversion(int bin)
{
	int resultat = 0;
	int y = 0;
	int i = 7;
	while (i>=0)
	{
		if (bin%10 == 1)
		{
			resultat += pow(2,y);
		}
		y+=1;
		bin= (int)bin/10;
		i-=1;
	}
	printf("la convertion en binaire : %d\n",resultat);
	return resultat;
}

float f1(int x)
{
	float X = (x/pow(2,longIndiv))*(B-A)+A;
	return -pow(X,2);
}
 
 
 
/**************************** Foncion principale **************************/
int main(){
	
	
	
	time_t t; // doc time du langage C
	srand((unsigned) time(&t)); // initialisation du générateur de nombres aléatoires
	struct individu TabIndiv[longIndiv];			
		for(int i = 0; i<=longIndiv-1;i++)
			{
			int j = 2;
			int bit = rand() % j; // 0 ou 1
			TabIndiv[i].Bit = (unsigned char)bit; // a chaque itération, on rajoute un 0 ou 1 dans individu 
			}
		unsigned a = TabIndiv[0].Bit;
		for(int i=1;i<longIndiv;i++){
			//printf("%d",TabIndiv[i].Bit);
			unsigned b = (unsigned)TabIndiv[i].Bit;
			a = concatenate(a,b);	
		}
	printf("la liste de bit correspondant la l'individu est = %d\n",(int)a);
	
	/* en recursif cf. fonction annexe*/
	unsigned r_a = r_individu(0, rand()%2);
	printf(" la liste de bit en recursif est = %d\n",(int)r_a);
	
	/* decodage et valeur entiere */
	int resultat = conversion((int)a);
	/* retour sur la qualité de l'individu*/
	float qualite = f1(resultat);
	printf(" f1 vaut = %f\n",qualite);
	return 0;
}
