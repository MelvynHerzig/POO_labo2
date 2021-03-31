/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : main.cpp
 Auteur(s)   : Forestier Quentin & Melvyn Herzig
 Date        : 17/03/2021

 But         : Tester l'utilisation de la classe Squadron.

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#include <cstdlib>                        // EXIT_SUCCESS
#include <stdexcept>                      // invalid_argument
#include <iostream>                       // cout endl
#include <vector>                         // vector
#include "ships/cargo/Shuttle.h"          // Shuttle et ses fonctions
#include "ships/cargo/StarDestroyer.h"    // StarDestroyer et ses fonctions
#include "ships/fighter/TIELN.h"          // TIELN et ses fonctions
#include "ships/fighter/TIEIN.h"          // TIEIN et ses fonctions
#include "squadron/Squadron.h"            // Squad et ses fonctions

using namespace std;

/**
 * @brief exemple de base de manipulation issus du cahier des charges.
 */
void testCahierCharche()
{
   TIELN* blackLeader = new TIELN();
   blackLeader->setNickname("Black leader");
   TIELN* blackTwo = new TIELN();
   Shuttle* shuttle = new Shuttle(23.4); // 23.4 tonnes de marchandises
   Squadron squad("Black Squadron");
   squad += blackLeader;
   squad += blackTwo;
   squad += shuttle;
   squad.setLeader(blackLeader);
   cout << squad << endl;

   delete blackLeader;
   delete blackTwo;
   delete shuttle;
}

/**
 * Test la construction et les méthodes des vaisseaux (constant et non constant)
 */
void testShips()
{
   // Test des constructeurs
   StarDestroyer emptyStarDestroyer;
   Shuttle       emptyShuttle      ;
   TIEIN         emptyInterceptor  ;
   TIELN         emptyHunter       ;

   TIEIN         namedInterceptor  ("Intercepteur TIE avec nom");
   TIELN         namedHunter       ("Chasser TIE avec nom");

   StarDestroyer ChargedStarDestroyer(10);
   Shuttle       ChargedShuttle      (20);

   StarDestroyer namedStarDestroyer(10, "destoryer avec nom");
   Shuttle       namedShuttle      (20, "Shuttle vec nom");

   // Test constructeur copie. Ne compile pas, c'est normal, constructeur supprimé.
   //StarDestroyer copiedStarDestroyer(emptyStarDestroyer);
   //Shuttle       copiedShuttle      (emptyShuttle);
   //TIEIN         copiedIntercepteur (emptyInterceptor);
   //TIELN         copiedChasseur     (emptyHunter);

   // Test opérateur d'affectation. Ne compile pas, c'est normal, opérateur supprimé.
   //StarDestroyer namedStarDestroyer = emptyStarDestroyer;
   //Shuttle       namedShuttle       = emptyShuttle      ;
   //TIEIN         namedInterceptor   = emptyInterceptor  ;
   //TIELN         namedHunter        = emptyHunter       ;

   // Création de deux gammes une constante et l'autre non
   StarDestroyer normalDestroyer    (20, "const destroyer");
   Shuttle       normalShuttle      (50, "const Shuttle"  );
   TIEIN         normalInterceptor  ("const intercepteur");
   TIELN         normalHunter       ("const chasseur"    );

   const StarDestroyer constDestroyer    (30,"const destroyer");
   const Shuttle       constShuttle      (40,"const Shuttle"  );
   const TIEIN         constInterceptor  ("const intercepteur");
   const TIELN         constHunter       ("const chasseur"    );

   // Test d'affichage
   // Permet de tester: getModel, getId, getWeight, getSpeed
   // De plus pour les cargos: getMaxLoadWeight et getEmptyweight
   cout << "------------------------------------------------" << endl;
   cout << "Test affichage et getter vaisseaux non constants" << endl;
   cout << "------------------------------------------------" << endl;
   cout << normalDestroyer   <<endl  << endl
        << normalShuttle     << endl << endl
        << normalInterceptor << endl << endl
        << normalHunter      << endl << endl;

   cout << "--------------------------------------------" << endl;
   cout << "Test affichage et getter vaisseaux constants" << endl;
   cout << "--------------------------------------------" << endl;
   cout << constDestroyer   << endl << endl
        << constShuttle     << endl << endl
        << constInterceptor << endl << endl
        << constHunter      << endl << endl;

   cout << "------------------------------------------------" << endl;
   cout << "Test consommation vaisseaux non constants" << endl;
   cout << "------------------------------------------------" << endl;
   cout << "Consommation star destroyer "<< normalDestroyer.consumption(100)  << endl
        << "Consommation shuttle        "<< normalShuttle.consumption(100)    << endl
        << "Consommation intercepteur   "<< normalInterceptor.consumption(100)<< endl
        << "Consommation chasseur       "<< normalHunter.consumption(100)     << endl;

   cout << "--------------------------------------------" << endl;
   cout << "Test consommation vaisseaux constants" << endl;
   cout << "--------------------------------------------" << endl;
   cout << "Consommation star destroyer "<< constDestroyer.consumption(100)  << endl
        << "Consommation shuttle        "<< constShuttle.consumption(100)    << endl
        << "Consommation intercepteur   "<< constInterceptor.consumption(100)<< endl
        << "Consommation chasseur       "<< constHunter.consumption(100)     << endl;

   cout << "------------------------------------------------" << endl;
   cout << "Test set nickname sur vaisseaux non constant" << endl;
   cout << "------------------------------------------------" << endl;
   normalDestroyer.setNickname("renameDestroyer");
   normalShuttle.setNickname("renameShuttle");
   normalInterceptor.setNickname("renameInterceptor");
   normalHunter.setNickname("renameHunter");

   cout << normalDestroyer   << endl << endl
        << normalShuttle     << endl << endl
        << normalInterceptor << endl << endl
        << normalHunter      << endl << endl;

   cout << "--------------------------------------------" << endl;
   cout << "Test set nickname sur vaisseaux constants" << endl;
   cout << "--------------------------------------------" << endl;
   cout << "Ne compile pas, c'est normal ce sont des vaisseaux constants" << endl;
   //constDestroyer.setNickname("renameDestroyer");
   //constShuttle.setNickname("renameShuttle");
   //constInterceptor.setNickname("renameInterceptor");
   //constHunter.setNickname("renameHunter");

   cout << "------------------------------------------------" << endl;
   cout << "Test set loadWeight sur vaisseaux non constant" << endl;
   cout << "------------------------------------------------" << endl;
   normalDestroyer.setLoadWeight(10);
   normalShuttle.setLoadWeight(10);

   cout << normalDestroyer   << endl << endl
        << normalShuttle     << endl << endl;

   try { normalDestroyer.setLoadWeight(1000000000000); }
   catch (const invalid_argument& e) { cout << "(Destroyer) Poids trop grand, exception attrapee" << endl;}

   try { normalShuttle.setLoadWeight(1000000000000); }
   catch (const invalid_argument& e) { cout << "(Shuttle) Poids trop grand, exception attrapee" << endl;}

   try { normalDestroyer.setLoadWeight(-1); }
   catch (const invalid_argument& e) { cout << "(Destroyer) Poids negatif, exception attrapee" << endl;}

   try { normalShuttle.setLoadWeight(-1); }
   catch (const invalid_argument& e) { cout << "(Shuttle) Poids negatif, exception attrapee" << endl << endl;}

   cout << "--------------------------------------------" << endl;
   cout << "Test set loadWeight sur vaisseaux constants" << endl;
   cout << "--------------------------------------------" << endl;
   cout << "Ne compile pas, c'est normal ce sont des vaisseaux constants" << endl;
   //constDestroyer.setNickname("renameDestroyer");
   //constShuttle.setNickname("renameShuttle");
}

/**
 * Test la création et la manipulation d'escadrilles (constantes ou non)
 */
void testSquad()
{

   // Création des escadrilles
   const Squadron constSquadNoName;
         Squadron normalSquadNoName;

   const Squadron constSquadnamed ("A named const squad");
         Squadron normalNamedSquad("A named squad");


   // Création de deux gammes une constante et l'autre non
   StarDestroyer normalDestroyer    (20, "const destroyer");
   Shuttle       normalShuttle      (50, "const Shuttle"  );
   TIEIN         normalInterceptor  ("const intercepteur");
   TIELN         normalHunter       ("const chasseur"    );

   const StarDestroyer constDestroyer    (30,"const destroyer");
   const Shuttle       constShuttle      (40,"const Shuttle"  );
   const TIEIN         constInterceptor  ("const intercepteur");
   const TIELN         constHunter       ("const chasseur"    );

   // Ajout de vaisseau op +
   // Test l'opérateur ship + squad test également squad + ship , add, opCopy
   cout << "---------------------------------------------" << endl;
   cout << "Ajout de vaisseau avec operateur +           " << endl;
   cout << "---------------------------------------------" << endl;
   const Squadron constNewSquad1 = &constShuttle + constSquadnamed;
   cout << "Nouvelle escadron " << constNewSquad1 << endl;
   cout << "Escadron de base  " << normalNamedSquad << endl;

   Squadron normalNewSquad1 = &constShuttle + normalNamedSquad;
   cout << "Nouvelle escadron " << normalNewSquad1 << endl;
   cout << "Escadron de base  " << normalNamedSquad << endl;

   try{ nullptr + constNewSquad1; }
   catch (const invalid_argument& e){ cout << "retrait nullptr: exception attrappee" << endl; }
   try{ nullptr + normalNewSquad1; }
   catch (const invalid_argument& e){ cout << "retrait nullptr: exception attrappee" << endl; }

   // Retrait de vaisseau op -
   // Test l'opérateur ship - squad test également squad - ship , remove, opCopy
   cout << "---------------------------------------------" << endl;
   cout << "Retrait de vaisseau avec operateur -           " << endl;
   cout << "---------------------------------------------" << endl;
   Squadron constNewSquad2 = &constShuttle - constNewSquad1;
   cout << "Nouvelle escadron " << constNewSquad2 << endl;
   cout << "Escadron de base  " << normalNamedSquad << endl;

   Squadron normalNewSquad2 = &normalShuttle - normalNewSquad1;
   cout << "Nouvelle escadron " << normalNewSquad2 << endl;
   cout << "Escadron de base  " << normalNamedSquad << endl;

   try{ nullptr - constNewSquad2; }
   catch (const invalid_argument& e){ cout << "retrait nullptr: exception attrappee" << endl; }
   try{ nullptr - normalNewSquad2; }
   catch (const invalid_argument& e){ cout << "retrait nullptr: exception attrappee" << endl; }

   // Ajout de vaisseau op +
   // Test l'opérateur squad += ship test également addSelf, opSelf
   cout << "---------------------------------------------" << endl;
   cout << "Ajout de vaisseau avec operateur +=           " << endl;
   cout << "---------------------------------------------" << endl;
   //const Squadron constNewSquad3 = constSquadnamed += &constDestroyer;

   normalNamedSquad += &normalDestroyer;
   cout << "Nouvelle escadron " << normalNamedSquad << endl;

   try{  normalNamedSquad += nullptr; }
   catch (const invalid_argument& e){ cout << "retrait nullptr: exception attrappee" << endl; }

   // Retrait de vaisseau
   // Test l'opérateur ship - squad test également squad - ship , remove, opCopy
   cout << "---------------------------------------------" << endl;
   cout << "Retrait de vaisseau avec operateur -         " << endl;
   cout << "---------------------------------------------" << endl;
   //const Squadron constNewSquad3 = constSquadnamed += &constDestroyer;

   normalNamedSquad -= &normalDestroyer;
   cout << "Nouvelle escadron " << normalNamedSquad << endl;

   try{  normalNamedSquad -= nullptr; }
   catch (const invalid_argument& e){ cout << "retrait nullptr: exception attrappee" << endl; }

   cout << "---------------------------------------------" << endl;
   cout << "Set name                                     " << endl;
   cout << "---------------------------------------------" << endl;
   //constSquadNoName.setName("Test");
   cout << "Avant renommage: " << normalSquadNoName << endl;
   normalSquadNoName.setName("I got a squad name!");
   cout << "Apres renommage: " << normalSquadNoName << endl;

   cout << "---------------------------------------------" << endl;
   cout << "SetLeader                                    " << endl;
   cout << "---------------------------------------------" << endl;

   cout << "------------------ Vaisseau membre ------------------" << endl;
   cout << "Avant leader: " << normalSquadNoName << endl;
   normalSquadNoName += &normalHunter;
   normalSquadNoName.setLeader(&normalHunter);
   //constSquadNoName.setLeader(&normalHunter);
   cout << "Apres leader: " << normalSquadNoName << endl;

   cout << "------------------ Vaisseau non membre ------------------" << endl;
   cout << "Avant leader: " << normalSquadNoName << endl;
   normalSquadNoName.setLeader(&constInterceptor);
   //normalSquadNoName.setLeader(&constInterceptor);
   cout << "Apres leader: " << normalSquadNoName << endl;

   cout << "------------------ Nullptr ------------------" << endl;
   cout << "Avant leader: " << normalSquadNoName << endl;
   normalSquadNoName.setLeader(nullptr);
   //normalSquadNoName.setLeader(&constInterceptor);
   cout << "Apres leader: " << normalSquadNoName << endl;


   cout << "---------------------------------------------" << endl;
   cout << "unsetLeader                                  " << endl;
   cout << "---------------------------------------------" << endl;

   cout << "------------------ Leader préalable ------------------" << endl;
   normalSquadNoName += &constShuttle;
   cout << "Avant leader: " << normalSquadNoName << endl;
   normalSquadNoName.unsetLeader();
   //constSquadNoName.unsetLeader();
   cout << "Apres leader: " << normalSquadNoName << endl;

   cout << "------------------ Pas de leader prealable ------------------" << endl;
   cout << "Avant leader: " << normalSquadNoName << endl;
   normalSquadNoName.unsetLeader();
   //constSquadNoName.unsetLeader();
   cout << "Apres leader: " << normalSquadNoName << endl;


   cout << "---------------------------------------------" << endl;
   cout << "consumption                                  " << endl;
   cout << "---------------------------------------------" << endl;

   cout << "------------------ Consommation sans vaisseau  ------------------" << endl;
   cout << constSquadNoName;
   cout << "Consommation : " << constSquadNoName.consumption(100) << endl << endl;

   cout << normalNamedSquad;
   cout << "Consommation : " << constSquadNoName.consumption(100) << endl << endl;

   cout << "------------------ consommation avec vaisseaux et leader ------------------" << endl;
   (normalSquadNoName += &constShuttle) += &normalHunter;
   normalSquadNoName.setLeader(&normalHunter);
   cout << normalSquadNoName;
   cout << "Consommation : " << normalSquadNoName.consumption(100) << endl << endl;

   cout << "---------------------------------------------------" << endl;
   cout << "Dépassement de la capacité de base (>10 vaisseaux) " << endl;
   cout << "---------------------------------------------------" << endl;

   Squadron resizableSquad ("I have 20 interceptor");
   vector<const Ship*> ships;
   for(size_t i = 0; i < 20; ++i)
   {
      const Ship* ship = new TIEIN();
      ships.emplace_back(ship);
      resizableSquad += ship;
   }

   cout << resizableSquad << endl;

   for(size_t i = 0; i < 20; ++i)
   {
      delete ships[i];
      ships[i] = nullptr;
   }


}

/**
 * @brief lance diverses manipulations d'escadrilles et
 *         de vaisseau dans le but d'analyser la sortie et valider
 *         leur fonctionnement.
 * @return
 */
int main()
{
    testCahierCharche();
    testShips();
    testSquad();

    return EXIT_SUCCESS;
}
