#include <iostream>
#include <string>
#include <windows.h>

#ifndef DEF_FONCTION
#define DEF_FONCTION

int GetNombreAleatoire(int min, int max);

int * SaisirCombinaison(int combi[], int nbPions);

int * ChoisirCombinaison(int combi[], int nbPions, int nbCouleurs, int mini);

bool TesterCombinaison(int combiCache[], int combiSaisie[], int nbPions, int couleurDuTexte);

void VictoireCombinaison(int combi[],int couleurDuTexte);

void DefaiteCombinaison(int combi[], int couleurDuTexte);

void Introduction();

void Regles();

void color(int couleurDuTexte);


#endif

