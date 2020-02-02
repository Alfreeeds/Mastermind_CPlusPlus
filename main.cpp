#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include <iomanip>

#include "fonction.h"




using namespace std;

int main()
{	//déclaration de toutes les variables
	srand((unsigned)time(0));
	string ouiOuNon;
	int const min = 1;
	int const max = 8;
	int const nbCouleurs = 8;
	int const nbPions = 4;
	int codeSecret[nbPions];
	int codeSaisie[nbPions];
	bool restart = true;
	bool victoire;
	bool voulezVousRejouer = true;
	string choixMenuSaisie;
	int choixMenu = 0;
	string test;
	bool InteractionMenu = true;

	int couleurDuTexte = 13; //violet
	color(couleurDuTexte);
	Introduction();

	couleurDuTexte = 9; //bleu
	color(couleurDuTexte);
	while (InteractionMenu)			// Menu principal 
	{
		cout << endl;
		cout << right << setw(41) << setfill(' ') << "";
		cout << "Choisir entre 1 / 2 / 3 :\n" << endl << endl;
		cout << right << setw(50) << setfill(' ') << ""; 
		cout << "1: Jouer \n" << endl;
		cout << right << setw(50) << setfill(' ') << ""; 
		cout << "2: Regles \n" << endl;
		cout << right << setw(50) << setfill(' ') << "";
		cout << "3: Quitter \n" << endl;
		cin >> choixMenuSaisie;

		try
		{
			choixMenu = stoi(choixMenuSaisie);
		}
		catch (invalid_argument e)
		{

		}

		switch (choixMenu)
		{
		case 1:
			while (restart)
			{
				int nbEssais = 12;
				victoire = false;
				bool voulezVousRejouer = true;
				ChoisirCombinaison(codeSecret, min, nbCouleurs, nbPions); //création de la combinaison aléatoire		

				while (!victoire && nbEssais > 0)
				{
					//cout <<"Le code secret est: "<< codeSecret[0] << codeSecret[1] << codeSecret[2] << codeSecret[3] << endl;
					//Décommenter la ligne au desssus pour afficher le code secret

					couleurDuTexte = 15; //blanc
					color(couleurDuTexte);

					cout << "Il vous reste " << nbEssais << " coups a jouer." << endl;			

					couleurDuTexte = 9;	//bleu
					color(couleurDuTexte);

					SaisirCombinaison(codeSaisie, nbPions);
					victoire = TesterCombinaison(codeSecret, codeSaisie, nbPions, couleurDuTexte);
					cout << endl;					
					nbEssais--;
				}
				if (victoire)
				{
					VictoireCombinaison(codeSecret, couleurDuTexte);
				}
				else
				{
					DefaiteCombinaison(codeSecret, couleurDuTexte);
				}
				cout << endl;

				while (voulezVousRejouer)
				{
					cout << "voulez-vous rejouer ? (o / n)" << endl;
					cin >> ouiOuNon;
					if (ouiOuNon.compare("o") == 0 || ouiOuNon.compare("O") == 0)
					{
						restart = true;
						voulezVousRejouer = false;
					}
					else if (ouiOuNon.compare("n") == 0 || ouiOuNon.compare("N") == 0)
					{
						restart = false;
						voulezVousRejouer = false;
					}
					else
					{
						couleurDuTexte = 12; //rouge
						color(couleurDuTexte);

						cout << endl << "! Erreur ! : champs mal renseigne !" << endl;						
						
						couleurDuTexte = 9; //bleu
						color(couleurDuTexte);

						voulezVousRejouer = true;
						cout << endl << endl << endl;
					}
				}
				cout << endl << endl;
			}
			InteractionMenu = false;
			break;
		case 2:					// affichage des regles
			Regles();
			InteractionMenu = true;
			break;
		case 3:					// Quitter le jeu
			restart = false;
			InteractionMenu = false;
			break;
		default:
			couleurDuTexte = 12; //rouge
			color(couleurDuTexte);

			cout << "!Erreur! veuillez renseigner un bon numero !" << endl;
			
			couleurDuTexte = 9;
			color(couleurDuTexte);
			InteractionMenu = true;
					// à corriger: bug si on rentre un mauvais carractère loop infini

			break;
		}
	}
	cout << "A bientot !" << endl;
	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	return 0;	
}	

	