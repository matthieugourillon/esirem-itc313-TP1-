# Esirem-itc313-TP1

TP1 GOURILLON - FARIN

Mail: matthieu.gourillon@gmail.com
      matthieu_gourillon@etu-u.bourgogne.fr

Compte Rendu TP C++ Sujet n°1 : Ne vous endormez pas

Nous avons choisi de traiter le TP n°1 ce TP consiste à concevoir une application de gestion des réservations d'un hôtel.
Nous avons réalisé les 11 premières questions que comporte le sujet.
Des indications sont données plus bas sur notre démarche.

Partie 1 : Création des classes
Dans cette partie 1 (Question de 1 à 5)
Nous avons commencé par la création des classes comme indiqué dans le sujet.
Nous obtenons alors 4 classes (Client,Chambre,Hôtel,Réservation).
Chacune des classes comprend des getters pour récupérer les valeurs et des setters pour pouvoir modifier les valeurs.
Nous récupérons également la classe Date qui a été vue en cours et nous assurons de son bon fonctionnement dans notre programme.

Question 1 : Classe Date repris du cours

Question 2 : Création de la classe Client, syntaxe reprise du cours

Question 3 : Création de la classe Chambre. Nous avons choisi arbitrairement de prendre 3 types de chambres:
              Type : 1_Simple
                     2_Double 
                     3_Suite
 
Question 4 : Création de la classe Hôtel. On utilise un tableau de vecteur pour stocker les chambres.

Question 5 : La création de la classe Réservation était plus complexe. Dans la classe nous héritons des classes Client, Hôtel, Chambre et également de Date. Nous n'avons pas voulu utiliser les pointeurs pour accéder directement aux objets des classes. Nous avons alors utilisé les entiers qui représentent alors les ID des objets, que nous pouvons récupérer par la suite avec les vecteurs.
Concernant le calcul du montant total, nous avons établi que 1 réservation correspondait à 1% de remise.

Partie 2 : Utilisation des classes dans une application

Question 6 : Nous avons créé 10 chambres que nous avons associées à un même hôtel graçe à la fonction addChambre permettant d'ajouter une chambre que nous venons de créé dans le vecteur pour stocker les chambres.
Les chambres comme vues plus haut sont réparties en 3 types : Simple, Double, Suite.
Nous n'oublions pas de surcharger l'opérateur << pour faciliter l'affichage des informations de l'hôtel.

Question 7 : Nous ajoutons la possibilité de saisir les dates du séjour au clavier. Plusieurs tests sont effectués pour s'assurer de la conformité des dates saisies. 
Nous testons si la date saisie n'est pas inférieure à la date du jour actuel. Car nous ne pouvons bien évidemment pas réserver dans le passé.
Nous testons également si la chronologie de nos deux dates saisies est bonne, pour éviter que la date de fin du séjour soit antérieure à la date du début du séjour.
Si nos deux dates ne sont pas conformes, on ressaisit à nouveau en faisant plus attention.
Une fois nos deux dates conformes nous pouvons alors calculer le nombre de nuits du séjour.
Pour ce calcul j'utilise une fonction venant de la bibliothèque time.h. J'aurai pue également calculé le nombre d'itérations entre les deux dates en utilisant nextday() de la classe date, mais je n'y est pas pensé avant.

Question 8 : Nous ajoutons la possibilité de saisir le type de chambre souhaité au clavier. Nous faisons deux tests. 

  -Le premier test compare le type demandé avec tous les types de chambres dans le vecteur qui stocke les chambres. S'il n'y a pas de correspondance, il n'y a pas de chambre du type demandé.
  
  -Le deuxième test on regarde sur les chambres du bon type, si la réservation est possible au dates indiquées. 
  Pour ce deuxième test, nous n'avons pas réussi à réaliser le test. Nous avons la bonne logique, mais nous n'avons pas trouvé la bonne syntaxe pour effectuer le test.
  Plus de détail en commentaire dans le main au niveau du test.
 
Question 9 : Nous ajoutons la possibilité de saisir le nom du client au clavier
Dans notre cas deux personnes s'appellent "CASTEX", nous avons alors deux homonymes.
Nous faisons plusieurs tests, en premier nous vérifions que le nom saisi existe bien. En second nous vérifions si nous avons des homonymes avec le nom saisi et nous affichons les informations de ses personnes.
Enfin nous demandons de saisir l'idClient pour choisir le client voulu.

Question 10 : Avec les paramètres saisi nous pouvons alors calculer le prix éxact du séjour. Dans notre cas nous faison : Nombre de jours du séjour *  Le prix de la chambre choisi * fidélité.
Nous avons précisé plus haut que 1 réservation correspondait à 1% de remise.
Une fois le prix calculé nous pouvons alors crée une nouvelle réservation avec tous nos paramètres préalablement choisis. Et nous affichons les informations de la réservation.
Nous ajoutons notre réservation dans le vecteur listeRéservation avec un push_back.

Question 11 : La fonction « afficherReservations » permet d’afficher toutes les réservations à l’aide d’une boucle while.
La fonction « afficherReservations » fonctionne de la même manière, mais compare l’ID entré en paramètre avec l’ID de chaque réservation pour afficher seulement le bon élément
La fonction « afficherReservationClient » prend en paramètre l’ID du client dont on souhaite afficher les réservations et fonctionne pareil que la fonction précédente. Cependant, l’utilisateur peut saisir directement l’ID mais aussi le nom du client. 
La fonction de modification de la réservation est située dans la classe Réservation.
La fonction d’annulation recherche la bonne réservation comme la 2ème fonction de cette question, puis utilise « vecteur.erase(i) » pour supprimer la ième case.










  


