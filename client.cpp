#include "client.h"
#include <iostream>
using namespace std;

	Client::Client() : _idClient(00000), _nom("MIMICHE"), _prenom("Jean"), _fidélité(0) {}
	Client::Client(int idClient) : _idClient(idClient) {}
	Client::Client(int idClient, string nom, string prenom, int fidélité ) : _idClient(idClient), _nom(nom), _prenom(prenom), _fidélité(fidélité) {}

	int Client::idClient () const{
		return _idClient;
	}
	string Client::nom() const{
		return _nom;
	}
	string Client::prenom() const{
		return _prenom;
	}
	int Client::fidélité() const{
		return _fidélité;
	}
	void Client::setidClient(int idClient){
		_idClient=idClient;
	} 
	void Client::setNom(string nom){
     		_nom=nom;
     	} 
    void Client::setPrenom(string prenom){
     		_prenom=prenom;
     	} 
    //Fonction pour modifier un client 	
	void Client::modifClient(string nomn, string prenomn){
       		setNom(nomn);
       		setPrenom(prenomn);
        }
    //Fonction pour afficher les informations du client
    void Client::displayClient(){
		cout << "Client:" << idClient() << " | Nom:" << nom() << " | Prenom:" << prenom() << " | Fidélité:" << fidélité()<< endl;

	}

	//Surcharge de l'oppérateur << de la classe Client
	ostream& operator<<(ostream& os, const Client& client)
	{
    os << "Client:" << client._idClient << " | Nom:" << client._nom << " | Prenom:" << client._prenom << " | Fidélité:" << client._fidélité;
    return os;
	}