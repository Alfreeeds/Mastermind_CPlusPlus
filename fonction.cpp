#include "fonction.h"
#include <iostream>
#include <windows.h>

#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

void Introduction()
{
	SetConsoleTitle("Mastermind");
	HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(H, BACKGROUND_RED);

	cout << right << setw(120) << setfill('#') << "" << endl << endl;
	SetConsoleTextAttribute(H, FOREGROUND_GREEN);
	cout << right << setw(40)<< setfill(' ') << "";
	cout << " Bienvenue dans Mastermind. " << endl << endl;
	SetConsoleTextAttribute(H, BACKGROUND_RED);
	cout << right << setw(120) << setfill('#') <<""<< endl;
	
}

void Regles()
{
	HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(H, BACKGROUND_RED);
	cout << right << setw(120) << setfill('#') << "";
	SetConsoleTextAttribute(H, FOREGROUND_GREEN);		
	cout << endl << endl << endl;
	cout << "Regles du jeu: " << endl;
	cout << endl;
	cout << "Le Mastermind est a la base un jeu de societe dont l'objectif est de deviner le code couleur imagine par l'adversaire." << endl;
	cout << "en l'ocurrence, l'adversaire est l'ordinateur et les couleurs sont (pour le moment) remplaces par des chiffres" << endl;
	cout << "4 chiffres seront donc choisis aleatoirement entre 1 et 8" << endl;
	cout << "l'objectif est de trouver la combinaison de chiffres en moins de 12 essais" << endl;
	cout << "! Attention ! il est possible que deux chiffres similaire ou + soit generes dans un meme code (exemple: 4 4 3 2)" << endl;
	cout << endl;
	cout << "Bonne chance !" << endl;
	cout << endl;
	SetConsoleTextAttribute(H, BACKGROUND_RED);
	cout << right << setw(120) << setfill('#') << "";
	SetConsoleTextAttribute(H, FOREGROUND_BLUE);
	cout << endl << endl;


}

int GetNombreAleatoire(int min, int max)
{
	int nbAleatoire = (rand() % max) + min;
	return nbAleatoire; 
}

int * SaisirCombinaison(int combi[], int nbPions)
{
	cout << "Veuillez entrer une combinaison: " << endl;
	for (int i = 0; i < nbPions; i++)
	{
		cin >> combi[i];
	}
	return combi;
} 

 int * ChoisirCombinaison(int combi[], int min, int nbCouleurs, int nbPions)
{
	for (int i = 0; i < nbPions; i++)
	{

		combi[i] = GetNombreAleatoire(min, nbCouleurs);
	}
	return combi; 
} 

bool TesterCombinaison(int codeSecret[], int codeSaisie[], int nbPions, int couleurDuTexte)
{
	int bienPlace = 0;
	int bonneCouleur = 0;
	bool exclure[4];
	bool exclureCouleur[4];
	bool inList = false;
	int grab;
	
	for (int i = 0; i < nbPions; i++)
	{
		exclure[i] = false;
		exclureCouleur[i] = false;
	}

	for (int i = 0; i < nbPions; i++)
	{
		if (codeSaisie[i] == codeSecret[i])
		{
			bienPlace++;
			exclure[i] = true;
		}
	}
	for (int i = 0; i < nbPions; i++)
	{
		if (!exclure[i])
		{
			for (int j = 0; j < nbPions; j++)				
			{
				if (!exclure[j] && i != j)
				{
					if (( codeSaisie[i] == codeSecret[j]) && !exclureCouleur[j])
					{
						inList = true;
						grab = j;
					}
				}
			}
			if (inList)
			{
				bonneCouleur++;
				inList = false;
				exclureCouleur[grab] = true;
			}
		}
	}
	if (bienPlace == 4)
		return true;
	else
	{
		int couleurDuTexte = 14;
		color(couleurDuTexte);
		cout << "Votre combinaison " << codeSaisie[0] << " " << codeSaisie[1]
			<< " " << codeSaisie[2] << " " << codeSaisie[3] << " " << " contient "<< bienPlace << " pion(s) bien place(s) et " << bonneCouleur << " pion(s) mal place(s)."<< endl;
		couleurDuTexte = 9;
		color(couleurDuTexte);
		return false;
	}
}

void VictoireCombinaison(int codeSecret[],int couleurDuTexte)
{
	couleurDuTexte = 2;
	color(couleurDuTexte);
	cout << "Gagner ! la reponse etait bien " << codeSecret[0] << " " << codeSecret[1]
		<< " " << codeSecret[2] << " " << codeSecret[3] << " !" << endl;	
	couleurDuTexte = 9;
	color(couleurDuTexte);
}

void DefaiteCombinaison(int codeSecret[], int couleurDuTexte)
{
	couleurDuTexte = 12;
	color(couleurDuTexte);
	cout << "Perdu ! la reponse etait " << codeSecret[0] << " " << codeSecret[1]
		<< " " << codeSecret[2] << " " << codeSecret[3] << " " << endl;
	couleurDuTexte = 9;
	color(couleurDuTexte);
}

void color(int couleurDuTexte)
{
	HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(H, couleurDuTexte );
}
