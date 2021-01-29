#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>
#include <string>
using namespace std;

class Client
	{
	public:
		Client();
		Client(int idClient);
		Client (int idClient, string nom, string prenom, int fidélité);
		int idClient() const;
        string nom() const;
        string prenom() const;
        int fidélité() const;
        void setidClient(int idClient);
        void setNom(string nom);
        void setPrenom(string prenom);
        void modifClient(string nomn, string prenomn); //Fonction pour modifier un client
        void displayClient(); //Fonction pour afficher les informations du client
		friend ostream& operator<<(ostream& os, const Client& client);//Surcharge


		
	private:
		int _idClient;
		string _nom;
		string _prenom;
		int _fidélité;
	};

#endif