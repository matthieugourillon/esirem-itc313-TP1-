#include <iostream>
#include "chambre.h"
#include "date.h"
using namespace std;

	Chambre::Chambre() : _idChambre(00001), _type(1), _prix(100) {}
	Chambre::Chambre(int idChambre): _idChambre(idChambre) {}
	Chambre::Chambre(int idChambre, int type, int prix ) : _idChambre(idChambre), _type(type), _prix(prix) {}

	int Chambre::idChambre () const{
		return _idChambre;
	}
	int Chambre::type() const{
		return _type;
	}
	int Chambre::prix() const{
		return _prix;
	}
	void Chambre::setidChambre(int idChambre){
     		_idChambre=idChambre;
     	} 
    void Chambre::setType(int type){
     		_type=type;
     	} 
    void Chambre::setPrix(int prix){
     		_prix=prix;
     	} 


    //Fonction pour modifier les paramètres de la chambre 	
	void Chambre::modifChambre(int idChambren,int typen,int prixn){
       		setidChambre(idChambren);
       		setType(typen);
       		setPrix(prixn);
        }


    //Fonction pour afficher les informations de la chambre  
    void Chambre::displayChambre(){
		cout << "Chambre: " << idChambre() << " | Type:" << type() << " | Prix:" << prix() << endl;
	}

	//Surcharge de l'oppérateur << de la classe Chambre
	ostream& operator<<(ostream& os, const Chambre& chambre)
	{
    os << "Chambre: "<< chambre._idChambre << " | Type:" << chambre._type << " | Prix:" << chambre._prix;
    return os;
	}

	