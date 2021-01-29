#ifndef REZ_H
#define REZ_H
#include <iostream>
#include <string>
#include "client.h"
#include "hotel.h"
#include "date.h"
#include "chambre.h"

using namespace std;

//Heritage public des classes : client, chambre, hotel
class Réservation :  public Client, public Chambre, public Hotel 
 {
	public:
		Réservation (int idRéservation, date::Date startDate, date::Date endDate, string idHotel, int idChambre, int idClient, double total);
        int idRéservation() const;
		double total() const;
		date::Date startDate() const;
		date::Date endDate() const;
		void modifidRéservation(int idRéservation);
		void modifidChambre(int idChambre);
		void modifTotal(double total);
		void modifstartDate(int annee, int mois, int jour); //Fonction pour modifier la date de début de la réservation
		void modifendDate(int annee, int mois, int jour); //Fonction pour modifier la date de fin de la réservation
		void modifidHotel(string idHotel);
		void modifidClient(int idClient);
		void showstartDate() const;	//Fonction pour afficher la date de début
		void showstendDate() const; //Fonction pour afficher la date de fin
		void modifChambre(int idChambren,string typen,int prixn);
		void displayReservation(); //Fonction pour afficher les informations de la réservation
		double totalmontant(int nbnuit, int prix, int fidélité); //Fonction permettant de calculé le montant de la réservation
       	int nbNuitRez(); //Fonction permettant de calculé le nombre de jours entre le début et la fin du séjour
       	int validation;
       	int valid(); //Renvoi la valeur de la variable validation, pour pouvoir resaisir la date en cas d'erreur
       	
       	//QUESTION 11
       	//Fonction permettant de modifier une réservation
       	void modifRéservation(int idRéservation,int annee, int mois, int jour, int annee1, int mois1, int jour1, string idHotel, int idChambre, int idClient, double total);

       	std::string infoReservation() const;
       	

	private:
		int _idRéservation = 0;
		double _total = 0;
		date::Date _startDate;
		date::Date _endDate;
	};

#endif