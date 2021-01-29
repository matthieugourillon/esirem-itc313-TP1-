#include "client.h"
#include "chambre.h"
#include "hotel.h"
#include "date.h"
#include "rez.h"
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <time.h>
#include <stdio.h>
using namespace std;

	//QUESTION 11


	//Retourne l'objet Client possédant l'ID en paramètre
	Client rechercheClient(vector<Client> listeclient,int idClient){
	int fin=listeclient.size();
	int i = 0;

		while(i<fin){

			if(idClient==listeclient.at(i).idClient()){
					return listeclient.at(i);
			}
		i++;
		}
	}

	//Affiche la réservation possédant l'ID en paramètre
	void afficherReservations(vector<Réservation> listeRéservation, int idRéservation){
	int fin=listeRéservation.size();
	int i = 0;

		while(i<fin){
			if(listeRéservation.at(i).idRéservation() == idRéservation){
			cout << listeRéservation.at(i).infoReservation();
			cout << endl;
			}
			i++;
		}
	}


	//Affiche les réservations au nom d'un client ou de son ID
	void afficherReservationsClient(vector<Réservation> listeRéservation,  int recherche){
	int fin=listeRéservation.size();
	int i = 0;
	cout << "Reservations du client n°" << recherche << " :" <<endl;
		while(i<fin){
			if(listeRéservation.at(i).idClient() == recherche){
				cout << listeRéservation.at(i).infoReservation() << endl;
			}
			i++;
		}
		cout << endl;
	}

	//Efface la réservation possédant l'ID en praramètre
	vector<Réservation> annulerReservation(vector<Réservation> listeRéservation, int réservation){
	int fin=listeRéservation.size();
	int i = 0;

		while(i<fin){
			if(listeRéservation.at(i).idRéservation() == réservation){
				listeRéservation.erase(listeRéservation.begin() + i);
				return listeRéservation;
			}
			i++;
		}
	cout << "Aucune réservation avec cet ID" << endl;
	return listeRéservation;

}
	

	int main(){
		
		cout << "################### Principal ####################" << endl;
		// PARTI II
		// QUESTION 6
		//On créer notre Hotel	
     	Hotel Hotel1("AZURE14","PALACE","Paris", vector<Chambre> ());	

     	/* On défini des valeurs qui correspond a un type de chambre et à un prix.
		Valeur 1 : Chambre Single, Prix 100€
		Valeur 2 : Chambre Double, Prix 125€
		Valeur 3 : Chambre Suite, Prix 200€
		nomchambre(idchambre,type,prix)*/

     	Chambre chambre1(1,2,180);
     	Chambre chambre2(2,2,180);
     	Chambre chambre3(3,2,180);
     	Chambre chambre4(4,3,200);
     	Chambre chambre5(5,3,200);
     	Chambre chambre6(6,1,100);
     	Chambre chambre7(7,1,100);
     	Chambre chambre8(8,2,180);
     	Chambre chambre9(9,1,100);
     	Chambre chambre10(10,3,200);

     	//On ajoute les chambres préalablement crée à notre hôtel
     	Hotel1.addChambre(chambre1);
     	Hotel1.addChambre(chambre2);
     	Hotel1.addChambre(chambre3);
     	Hotel1.addChambre(chambre4);
     	Hotel1.addChambre(chambre5);
     	Hotel1.addChambre(chambre6);
     	Hotel1.addChambre(chambre7);
     	Hotel1.addChambre(chambre8);
     	Hotel1.addChambre(chambre9);
     	Hotel1.addChambre(chambre10);

     	//On affiche notre hôtel graçe a la surcharge de l'opérateur << de la classe Hotel
        cout << Hotel1 << endl;  

        // On créer 10 clients
		Client Client1(1,"CASTEX","Jean", 1);
		Client Client2(2,"MACRON","Emmanuel",3);
		Client Client3(3,"TRUMP","Donald", 1);
		Client Client4(4,"HOLLANDE", "François", 6);
		Client Client5(5,"VERAN", "Olivier", 3);
		Client Client6(6,"BLANQUER", "Jean-Michel", 4);
		Client Client7(7,"CASTEX", "Joe", 4);
		Client Client8(8,"PHILIPPE", "Edouard", 7);
		Client Client9(9,"MERKEL", "Angela", 1);
		Client Client10(10,"II", "Élisabeth", 2);

		//On créer un vecteur listeclient regroupant tous les clients
		vector<Client> listeclient;

		//On insère les clients préalablement créé dans le vecteur listeclient
		listeclient.push_back(Client1);
		listeclient.push_back(Client2);
		listeclient.push_back(Client3);
		listeclient.push_back(Client4);
		listeclient.push_back(Client5);
		listeclient.push_back(Client6);
		listeclient.push_back(Client7);
		listeclient.push_back(Client8);
		listeclient.push_back(Client9);
		listeclient.push_back(Client10);

		//Permet d'afficher les infomations de tous les clients graçe à la surcharge de l'opérateur << de la classe Client
		int size = listeclient.size();
		for (int i =0; i< size; i++){
     			cout << listeclient[i] << endl;
     		}
     	int repetition=0;

     	//QUESTION 7	
     	//On demande de saisir au clavier les dates du séjour.	
     	goto saisidate;
     	saisidate:
     	cout << "Entrez les dates de votre séjour:" << endl;
     	cout << "Date d'arrivée (jour mois année): " << endl;
      	int jo1,mo1,an1;
     	cin >> jo1 >> mo1 >> an1;
     	cout << "Date de départ (jour mois année):" << endl;
     	int jo2,mo2,an2;
     	cin >> jo2 >> mo2 >> an2;

     	//On insère les dates dans le constructeur, on pourra verrifier si il y a une erreur
     	Réservation Réservation1(1, date::Date(an1,mo1,jo1), date::Date(an2,mo2,jo2),"AZURE14", 0, 0, 0); 

     	//Si validation dans la classe reservation = 1 alors il y a une erreur dans nos dates, on ressaisi à nouveaux
     	if (Réservation1.valid() == 1){
       		goto saisidate;
     	}

     	

     	//On fait appelle à notre fonction permettant de calculer le nombre de nuits du séjour et on l'affiche.
     	cout << "Nombre de nuit du séjour: ";
     	cout << Réservation1.nbNuitRez() << endl;
		
     	//QUESTION 8

     	//Création du vecteur Réservation regroupant la liste des réservations.
     	vector<Réservation> listeRéservation;
     	listeRéservation.push_back(Réservation1);

     	//On demande de saisir au clavier le type de la chambre souhaité.
     	goto saisichambre;
     	saisichambre:
     	cout << "Choisissez le type de la Chambre (1-Single, 2-Double, 3-Suite):";
        int type;
        cin >> type; 
     	
     	//On appelle la fonction permettant de vérifier si une chambre de ce type est disponible dans l'hôtel
       	Hotel1.checkChambre(type);

       	//Si le type demandé n'est pas disponible on redemande la saisi du type
    	if (Hotel1.valid() == 1){
       		goto saisichambre;
     	}
     	
     	//Fonction non fonctionnelle permettant de vérifier la disponibilité de la chambre au date voulu
     	//La syntax n'est pas bonne, ne reconnait pas listeRéservation.at(i)startDate()..
     	//Mon but était de retourné un vecteur contenant les ID des chambres occupées suivant les dates de réservations choisi
  		/*
		int checkDispo(date debut, Date fin, vector<Réservation> listeRéservation){
  		int i=0;
		int size2 = listeRéservation.size();
		std::vector<int> indisponible;
		date::Date debut(an1,mo1,jo1);
		date::Date fin(an2,mo2,jo2);
		while (i<size2)
			{
				if ((listeRéservation.at(i)startDate()< debut && listeRéservation.at(i)endDate()< fin)||(listeRéservation.at(i)startDate()> debut && listeRéservation.at(i)endDate()>fin)){

				}
				else {
					indisponible.push_back(listeRéservation.at(i).idChambre());
				}
				i++;
			}
		}
		return indisponible; 
	}
	*/
     	//QUESTION 9
  		//On demande de saisir au clavier le nom du client souhaité.
		goto saisinom;
     	saisinom:
     	cout << "Saisissez un nom:" << endl;
        string nom;
        cin >> nom;

        //Permet de verifier si le nom choisi est disponible
		//On compare alors le nom choisi avec tous les autres nom dans le vecteur listeclient
		//Si il y a une correspondance on regarde qu'il n'y a pas d'homonyme. Si il ya un ou des homonymes on affiche les homonymes et on demande de saisir le numéro de idClient que l'on veut.
     	//N'a pas été construit au départ comme une fonction, dans une prochaine version être construit et appelé comme fonction
     	//int clientNom(string nom, vector<Client> listeclient){}
        int w=0;
        int iclient;	
        for (int i =0; i< size; i++){

     		if (nom == listeclient.at(i).nom())
     			{
      				cout << listeclient[i] << endl;//On affiche a l'écran les informations du client sélectionné
      				iclient = i;
      				w++;
     				i++;
     			}
     	}		
     	//Erreur de nom ou nom inconnus, on redemande la saisi
     	if (w==0){
      		cout << "Nom inconnu :" << endl;
     		goto saisinom;
     		}

     	//Lorsque qu'il ya un ou des homonymes
     	if (w>1){ 
     		cout << "Plusieurs clients on le même nom !(Homonymes)" << endl;  
     		cout << "Quels clients voulez-vous choisir ? Entrez son identifiant:" << endl;
     		int id;
     		cin >> id;
     		
     		for (int i =0; i< size; i++){

     			if (id == listeclient.at(i).idClient()){
     				cout << "Vous avez choisi:" << endl;
     			    cout << listeclient[i] <<endl; //On affiche a l'écran les informations du client sélectionné
     			    iclient = i;

     			}
     			
     		}
     	}

     	//QUESTION 10
     	//On récupère le id de la chambre choisi
     	int numChambre = Hotel1.numChambre();

     	cout << "Prix total du sejour:" << endl;

     	//On calcul le prix exact du séjour, avec la fidélité du client.
     	//Fidélité = 4 correspond à 4% de réduction; 

     	int Prix=0;
     	int nbNuitRez = Réservation1.nbNuitRez();
     	//On récupère le prix de la chambre choisi
     	int prixChambre = Hotel1.prixChambre();
     	//On récupère le nombre de fidélité du client choisi

     	int fidélité = listeclient.at(iclient).fidélité();
        Prix = (nbNuitRez*prixChambre)-(nbNuitRez*prixChambre*fidélité/100);
        cout << Prix << endl;

        //On affiche la nouvelle réservation avec les informations 
        Réservation Réservation2(2,date::Date(an1,mo1,jo1), date::Date(an2,mo2,jo2),"AZURE14",numChambre,listeclient.at(iclient).idClient(),Prix);
      	Réservation2.displayReservation();
      	//On ajoute cette nouvelle réservation dans le vecteur listeRéservation
      	listeRéservation.push_back(Réservation2);
      	

      	repetition++;

      	//DEBUT CREATION RESERVATIONS
		
		while(repetition<=2){//Nombre de répétition a modifier dans le while. Ici le nombre de répétion est de 2;

      			goto saisidate;
      		}
      	

    return 0;


}
