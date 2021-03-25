/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : Squadron.h
 Auteur(s)   : Forestier Quentin & Melvyn Herzig
 Date        : 17/03/2021

 But         : Implémente une esquadrille. Il est possible d'ajouter ou d'enlever
               des vaisseaux qui la compose. Il est possible d'ajouter ou
               supprimer son chef (facultatif). Elle peut être renommée.
               Il est possible d'afficher la consommation totale de l'esquadrille.

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef LABO2_SQUADRON_H
#define LABO2_SQUADRON_H

#include <cstdlib>
#include <vector>
#include <string>
#include <ostream>
#include "../ships/Ship.h"

class SquadronOperation;
class SquadronAdd;
class SquadronRemove;

class Squadron
{
   friend SquadronAdd;
   friend SquadronRemove;

   // operateur +
   // Throws invalid_argument
   friend Squadron operator+ (const Squadron &squadron, const Ship* ship);
   friend Squadron operator+ (const Ship* ship, const Squadron &squadron);

   // operateur -
   // Throws invalid_argument
   friend Squadron operator- (const Squadron &squadron, const Ship* ship);
   friend Squadron operator- (const Ship* ship, const Squadron &squadron);

   // operateur <<
   friend std::ostream& operator<<(std::ostream& os, const Squadron& squadron);

private:

   static size_t DEFAULT_SQUAD_SIZE;

   const Ship** squad;
   size_t squadCapacity;
   size_t squadSize;

   const Ship*  leader;
   std::string  name;

private:
   Squadron(const std::string& name, size_t capacity, const Ship* leader);

public:
   // Constructeurs
   Squadron(const std::string& name = "");
   Squadron(const Squadron& otherSquadron);

   // Destructeur
   ~Squadron();

   // Opérateurs
   // Throws invalid_argument
   Squadron& operator+=(const Ship* ship);
   Squadron& operator-=(const Ship* ship);

   Squadron& operator =(const Squadron& otherSquadron);

   // Throws invalid_argument
   Squadron add(const Ship* ship) const;
   Squadron remove(const Ship* ship) const;

   // Throws invalid_argument
   Squadron& addSelf(const Ship* ship);
   Squadron& removeSelf(const Ship* ship);

   void setName(const std::string& name);

   void setLeader(const Ship* leader);
   void unsetLeader();


   double consumption(double distance) const;


private:

   void init(const std::string& name, size_t capacity, const Ship* leader);

   // throw out_of_range exception
   void copySquad(const Ship** otherSquad, size_t otherSquadLength);

   void increaseCapacity();

   // Throws invalid_argument
   size_t contains(const Ship* ship) const;

   Squadron& opSelf(const Ship* ship,const SquadronOperation& op);
   Squadron  opCopy(const Ship* ship,const SquadronOperation& op) const;

   void freeSquad();

};


#endif //LABO2_SQUADRON_H
