#ifndef CHAMBRE_H
#define CHAMBRE_H
#include <iostream>
#include <string>

using namespace std;

class Chambre
	{
	public:
		Chambre();
		Chambre (int idChambre);
		Chambre (int idChambre, int type, int prix);
		int idChambre() const;
        int type() const;
        int prix() const;
        void setPrix(int prix);
        void setType(int type);
        void setidChambre(int idChambre);//Fonction pour modifier l'id de la chambre
        void modifChambre(int idChambren,int typen,int prixn); //Fonction pour modifier les paramètres de la chambre
        void displayChambre(); //Fonction pour afficher les informations de la chambre

        friend ostream& operator<<(ostream& os, const Chambre& chambre);//Surcharge

		
	private:
		int _idChambre;
		int _type;
		int _prix;
	};

#endif