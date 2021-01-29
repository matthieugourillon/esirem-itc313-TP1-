#include "hotel.h"
#include "chambre.h"
#include <iostream>
#include <vector>
using namespace std;

	Hotel::Hotel() {}
	Hotel::Hotel(string idHotel) : _idHotel(idHotel) {}
	Hotel::Hotel(string idHotel, string nomHotel, string ville, vector<Chambre> tableau) : _idHotel(idHotel), _nomHotel(nomHotel), _ville(ville), _tableau(tableau) {}

	string Hotel::idHotel () const{
		return _idHotel;
	}
	string Hotel::nomHotel() const{
		return _nomHotel;
	}
	string Hotel::ville() const{
		return _ville;
	}
	vector<Chambre> Hotel::tableau() const{ 
		return _tableau;
	}
	void Hotel::setidHotel(string idHotel){
     		_idHotel=idHotel;
     	} 
    void Hotel::setnomHotel(string nomHotel){
     		_nomHotel=nomHotel;
     	} 
    void Hotel::setVille(string ville){
     		_ville=ville;
     	} 
    void Hotel::afficheTailleTableau(){
        	cout << _tableau.size() << endl;
     	} 


    //Fonction permettant d'afficher le contenu du vecteur tableau	
    void Hotel::afficheValeurTableau() const{
     	int size;
     	size = _tableau.size();
     		for (int i =0; i< size; i++){
     			cout << _tableau[i] << " ";
     		}
        	cout << endl;
     	} 
	void Hotel::clearTableau(){
        	_tableau.clear();

     	} 

    //Fonction permettant de rajouter une chambre dans le vecteur tableau
    void Hotel::addChambre(Chambre chambre){
    	_tableau.push_back(chambre);
    }

    //Fonction pour afficher les informations de le hotel
	void Hotel::displayHotel(){
		cout << "Hotel:" << idHotel() << " | Nom de L'hotel:" << nomHotel() << " | Ville:" << ville() << " | Nombre de chambre:"; afficheValeurTableau();

	}
	//Surcharge de l'oppérateur << du vecteur tableau
	ostream& operator<<(ostream& os, const vector<Chambre> tableau)
	{
		auto i=tableau.begin();
    while (i!=tableau.end()){
     			os << " - " << *i << " " << "\n";
     			++i;
     		}
        	
    os << endl;
    return os;
    
	}
	//Surcharge de l'oppérateur << de la classe Hotel 
	ostream& operator<<(ostream& os, const Hotel& hotel)
	{
    os << "Hotel:" << hotel.idHotel() << " | Nom de L'hotel:" << hotel._nomHotel << " | Ville:" << hotel._ville << " | liste de chambre:" << endl << hotel._tableau;

    cout << endl;
    return os;
    
	}


	//Fonction pour verifier si le type de la chambre choisi est disponible
	//On compare alors le type de la chambre choisi avec tous les autres types des chambres dans le vecteur tableau
	//Si il y a une correspondance alors on affiche seulement la première chambre disponible
	void Hotel::checkChambre(int type){
		int i =0;
		int size = _tableau.size();
		int x=0;
			
		for(i=0; i<size; i++)
			{
     			if (type ==_tableau.at(i).type() && x==0)
     			{
      				cout << _tableau[i] << endl;
     				x++;
     				ichambre = i;
 	    			validation=0;
     			}	   		
     				
     		}
     	//QUESTION 8
     	//On affiche un message d'erreur 	
     	if (x==0){
     		cout << "Il n'y à pas de chambre de ce type disponible" << endl;
     		validation=1;
     		}	 				
     } 

	 //Renvoi le prix de la chambre choisi
     int Hotel::prixChambre(){
     	ichambre = _tableau.at(ichambre).prix();
     	return ichambre;
     }
     //Renvoi le id de la chambre choisi
     int Hotel::numChambre(){
     	ichambre2 = _tableau.at(ichambre).idChambre();
     	return ichambre2;
     }

    /*Renvoi la valeur de la variable validation, pour pouvoir resaisir le type 
    validation = 0 Chambre est diponible
    validation = 1 Chambre non disponible*/ 
	int Hotel::valid(){
		return validation;
	}
	