#include "rez.h"
#include "client.h"
#include "hotel.h"
#include "date.h"
#include "chambre.h"
#include <iostream>
#include <time.h>
#include <stdio.h>
using namespace std;

	//Permet de contrôler si les dates sont bonnes dirrectement dans le constructeur
	//Je controle si la date de début est supérieur ou égal à la date du jour actuel pour évité de réserver dans le passé
	//Je controle si la date de fin est supérieur ou égal à la date du jour actuel pour évité de réserver dans le passé
	//Je controle si la date de fin n'est pas anterieur à la date de début 
	Réservation::Réservation(int idRéservation, date::Date startDate, date::Date endDate, string idHotel, int idChambre, int idClient, double total) : 
	_idRéservation(idRéservation), _startDate(startDate), _endDate(endDate), Hotel(idHotel), Chambre(idChambre), Client(idClient), _total(total) {
		time_t secondes;
   	 	struct tm instant;
    	time(&secondes);
    	instant=*localtime(&secondes);
    	validation = 0;    	
   		if ((_startDate.year() < instant.tm_year+1900) || (_startDate.year() <= instant.tm_year+1900 && _startDate.month() < instant.tm_mon+1) || (_startDate.year() <= instant.tm_year+1900 && _startDate.month() <= instant.tm_mon+1 && _startDate.day() < instant.tm_mday))
			{
				validation = 1;
				cout << "Date de début invalide, vous essayez de réserver dans le passé.. veuillez ressaisir vos dates de réservation" << endl;
				
			}
		if ((_endDate.year() < instant.tm_year+1900) || (_endDate.year() <= instant.tm_year+1900 && _endDate.month() < instant.tm_mon+1)  || (_endDate.year() <= instant.tm_year+1900 && _endDate.month() <= instant.tm_mon+1 && _endDate.day() < instant.tm_mday))
			{
				validation = 1;
				cout << "Date de fin invalide, vous essayez de réserver dans le passé.. veuillez ressaisir vos dates de réservation" << endl;
			}
		if ((_startDate.year() > _endDate.year()) || (_startDate.year() >= _endDate.year() && _startDate.month() > _endDate.month()) || (_startDate.year() >= _endDate.year() && _startDate.month() >= _endDate.month() && _startDate.day() > _endDate.day()))
			{
				validation = 1;
				cout << "Dates invalides, la date de fin est anterieur à la date de début" << endl;
				 
			}
		}

	int Réservation::idRéservation() const{
		return _idRéservation;
	}
	double Réservation::total() const{
		return _total; 
	}
	date::Date Réservation::startDate()const{
		return _startDate;
	}	
	date::Date Réservation::endDate()const{
		return _endDate;
	}	

	void Réservation::modifidRéservation(int idRéservation){
     		_idRéservation=idRéservation;
     	}
	void Réservation::modifidChambre(int idChambre){
     		Chambre::setidChambre(idChambre);
     	}     	
    void Réservation::modifTotal(double total){
     		_total=total;
     	} 
     void Réservation::modifidHotel(string idHotel){
			Hotel::setidHotel(idHotel);
		}
	void Réservation::modifidClient(int idClient){
			Client::setidClient(idClient);
		}

    
    //On contrôle dans la fonction pour modifier les dates de début, si elles sont correcte ou non
	void Réservation::modifstartDate(int annee, int mois, int jour)	{
		time_t secondes;
   	 	struct tm instant;
    	time(&secondes);
    	instant=*localtime(&secondes); 

		if ((_startDate.year() > _endDate.year()) || (_startDate.year() >= _endDate.year() && _startDate.month() > _endDate.month()) || (_startDate.year() >= _endDate.year() && _startDate.month() >= _endDate.month() && _startDate.day() > _endDate.day()))
			{
			date::Date startDate(annee,mois,jour);
			 _startDate= startDate;
			}
		else 
			{
			validation = 1;
			cout << "Date invalide, veuillez ressaisir la date de début de la réservation" << endl;
			}

	}		
	//On contrôle dans la fonction pour modifier les dates de fin, si elles sont correcte ou non
	void Réservation::modifendDate(int annee, int mois, int jour)	{
			
		if ((_startDate.year() > _endDate.year()) || (_startDate.year() >= _endDate.year() && _startDate.month() > _endDate.month()) || (_startDate.year() >= _endDate.year() && _startDate.month() >= _endDate.month() && _startDate.day() > _endDate.day()))
			{
			date::Date endDate(annee,mois,jour);
			_endDate = endDate;
			}
		else 
			{
			validation = 1;
			cout << "Date invalide, veuillez ressaisir la date de début de la réservation" << endl;
			}
		}
	//Fonction pour afficher la date de début
	void Réservation::showstartDate() const {

		cout << _startDate.toString() << endl;
	}
	//Fonction pour afficher la date de fin
	void Réservation::showstendDate() const {

		cout << _endDate.toString() << endl;
	}
	//Fonction pour afficher les informations de la réservation
	void Réservation::displayReservation(){
		cout << idRéservation() << " " << _startDate.toString() << " " << _endDate.toString() << " " << idHotel() << " " << idChambre() << " " << idClient() << " " << total() <<endl;
	}
	//Fonction permettant de calculé le montant de la réservation
	double Réservation::totalmontant(int nbnuit, int prix, int fidélité){

		cout << (nbnuit*prix-(nbnuit*prix*fidélité/100)) << endl;

	}
	//Fonction permettant de calculé le nombre de jours entre le début et la fin du séjour
	int Réservation::nbNuitRez(){

		struct tm d1 = {0};
   		struct tm d2 = {0};
 
  		d1.tm_mday = _startDate.day();
  		d1.tm_mon  = _startDate.month() - 1;
   		d1.tm_year = _startDate.year()- 1900;
 	
   		d2.tm_mday = _endDate.day();
  	 	d2.tm_mon  = _endDate.month() - 1;
   		d2.tm_year = _endDate.year() - 1900;
 
   		return difftime(mktime(&d2), mktime(&d1)) / 86400;
	}

	//Renvoi la valeur de la variable validation, pour pouvoir resaisir la date en cas d'erreur
	int Réservation::valid(){
		return validation;
	}
	//QUESTION 11
	//Fonction permettant de modifier une réservation
	void Réservation::modifRéservation(int idRéservation,int annee, int mois, int jour, int annee1, int mois1, int jour1, string idHotel, int idChambre, int idClient, double total){
			modifidRéservation(idRéservation);
			modifstartDate(annee,mois,jour);
			modifendDate(annee1,mois1,jour1);
			modifidHotel(idHotel);
			modifidChambre(idChambre);
			modifidClient(idClient);
			modifTotal(total);
}
	
	string Réservation::infoReservation() const {
    string str;
    str = "Réservation N° " + to_string(idRéservation())
     + " du " + startDate().toString()
     + " au " + endDate().toString() 
     + " " + to_string(total()) 
     + "€ \n";
    return str;
}
	
	