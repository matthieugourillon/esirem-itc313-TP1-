#ifndef HOTEL_H
#define HOTEL_H
#include <iostream>
#include <string>
#include <vector>
#include "chambre.h"
using namespace std;

class Hotel 
	{
	public:
		Hotel();
		Hotel(string idHotel);
		Hotel(string idHotel, string nomHotel, string ville, vector<Chambre> tableau);
		string idHotel() const;
        string nomHotel() const;
        string ville() const;
        vector<Chambre> tableau() const; //Création du vecteur tableau contenant les chambres 
        void setidHotel(string idHotel);
        void setnomHotel(string nomHotel);
        void setVille(string ville);
        void afficheTailleTableau();
        void afficheValeurTableau() const; //Fonction permettant d'afficher le contenu du vecteur tableau	
        void clearTableau();
        void displayHotel(); //Fonction pour afficher les informations de le hotel
        void addChambre(Chambre chambre); //Fonction permettant de rajouter une chambre dans le vecteur tableau
        void checkChambre(int type); // Fonction pour verifier si le type choisi est disponible

        int validation=0;
        int ichambre=0;
        int ichambre2=0;
        int prixChambre();
        int numChambre();
        int valid();

        //SURCHARGES
        friend ostream& operator<<(ostream& os, const Hotel& hotel); //Surcharge de l'oppérateur << de la classe Hotel 
        friend ostream& operator<<(ostream& os, const vector<Chambre> tableau); //Surcharge de l'oppérateur << du vecteur tableau
		
	private:
		string _idHotel;
		string _nomHotel;
		string _ville;
		vector<Chambre> _tableau;
	};

#endif