/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : Squadron.cpp
 Auteur(s)   : Forestier Quentin & Herzig Melvyn
 Date        : 17/03/2021
 -----------------------------------------------------------------------------------
 */

#include <limits>                        // numeric_limit<size_t>::max()
#include <stdexcept>                     // std::invalid_argument
#include <sstream>                       // std::stringstream
#include <iomanip>                       // std::fixed, std::precision
#include "operation/SquadronOperation.h" // SquadronOperation
#include "operation/SquadronRemove.h"    // SquadronRemove
#include "operation/SquadronAdd.h"       // SquadronAdd
#include "Squadron.h"



using namespace std;


// ----------------- Constantes statiques -------------------
const SquadronOperation& Squadron::APPLY_ADD    = SquadronAdd();
const SquadronOperation& Squadron::APPLY_REMOVE = SquadronRemove();

const size_t Squadron::DEFAULT_SQUAD_CAPACITY = 10;


// ----------------- Opérateurs amis -------------------
Squadron operator+ (const Squadron &squadron, const Ship* ship)
{
   return squadron.add(ship);
}
Squadron operator+ (const Ship* ship, const Squadron &squadron)
{
   return operator+(squadron, ship);
}

Squadron operator- (const Squadron &squadron, const Ship* ship)
{
   return squadron.remove(ship);
}
Squadron operator- (const Ship* ship, const Squadron &squadron)
{
   return operator-(squadron, ship);
}

std::ostream& operator<<(std::ostream& os, const Squadron& squadron)
{
   double totalWeight = 0;
   std::size_t maxSpeed  = numeric_limits<size_t>::max();

   stringstream ss;

   ss << "-- Members:" << endl;

   // Récupération de la vitesse du poids et lecture des vaisseaux
   for(size_t i = 0; i < squadron.squadSize; ++i)
   {
      totalWeight += squadron.squad[i]->getWeight();
      maxSpeed = (maxSpeed < squadron.squad[i]->getSpeed()) ? maxSpeed : squadron.squad[i]->getSpeed();

      if(squadron.squad[i] != squadron.leader)
      {
         ss << *(squadron.squad[i]) << endl << endl;
      }
   }

   maxSpeed = (maxSpeed == numeric_limits<size_t>::max()) ? 0 : maxSpeed;

   // Informations générales
   os << fixed << setprecision(2)
      << "Squadron : " << squadron.name << endl
      << "\tmax speed : " << maxSpeed << " MGLT" << endl
      << "\ttotal weight : " << totalWeight << " tons" << endl << endl;

   // Leader
   os << "-- Leader: " << endl;
   if(squadron.leader != nullptr)
   {
         os << *squadron.leader << endl << endl;
   }

   // Vaisseaux membres
   os << ss.str();

   return os;
}

// -----------------Constructeurs / Destructeur -------------------
Squadron::Squadron (const string& name)
{
   init(name , DEFAULT_SQUAD_CAPACITY, nullptr);
}

Squadron::Squadron (const Squadron& otherSquadron)
{
   init(otherSquadron.name, otherSquadron.squadCapacity, otherSquadron.leader);
   copySquad(otherSquadron.squad, otherSquadron.squadSize);
}

Squadron::~Squadron()
{
   freeSquad();
}

// ----------------- Opérateurs -------------------
Squadron& Squadron::operator+= (const Ship *ship)
{
   return addSelf(ship);
}

Squadron& Squadron::operator-= (const Ship *ship)
{
   return removeSelf(ship);;
}

Squadron& Squadron::operator= (const Squadron &otherSquadron)
{
   if(this == &otherSquadron) return *this;

   freeSquad();
   init(otherSquadron.name, otherSquadron.squadCapacity, otherSquadron.leader);
   copySquad(otherSquadron.squad, otherSquadron.squadSize);
   return *this;
}

Squadron Squadron::add (const Ship *ship) const
{
   return opCopy(ship, APPLY_ADD);
}

Squadron Squadron::remove (const Ship *ship) const
{
   return opCopy(ship, APPLY_REMOVE);
}

Squadron& Squadron::addSelf (const Ship *ship)
{
   return opSelf(ship, APPLY_ADD);
}

Squadron& Squadron::removeSelf (const Ship *ship)
{
   return opSelf(ship, APPLY_REMOVE);
}

// ----------------- Mutateur -------------------

void Squadron::setName (const string &name)
{
   this->name = name;
}

void Squadron::setLeader (const Ship *leader)
{
   if(leader == nullptr || contains(leader) != numeric_limits<size_t>::max())
   {
      this->leader = leader;
   }
}

void Squadron::unsetLeader ()
{
   leader = nullptr;
}

double Squadron::consumption (double distance) const
{
   double totalConsumption = 0.0;

   for(size_t i = 0; i < squadSize; ++i)
   {
      totalConsumption += squad[i]->consumption(distance);
   }
   return totalConsumption;
}

// ----------------- Private -------------------

void Squadron::init (const string &name, size_t squadCapacity, const Ship *leader)
{
   this->name = name;
   this->squadCapacity = squadCapacity;
   this->leader = leader;

   squad = new const Ship*[squadCapacity];
   squadSize = 0;
}

void Squadron::copySquad (const Ship **otherSquad, size_t otherSquadLength)
{
   for(size_t i = 0; i < otherSquadLength; ++i)
   {
      squad[i] = otherSquad[i];
   }

   squadSize = otherSquadLength;
}

void Squadron::increaseCapacity ()
{
   const Ship** temp = new const Ship*[2*squadCapacity];
   swap(temp, squad);
   squadCapacity *= 2;
   copySquad(temp, squadSize);
   delete[] temp;
}

size_t Squadron::contains (const Ship* ship) const
{
   if(ship == nullptr) throw invalid_argument("Cannot look for nullptr spaceship.");
   for(size_t i = 0; i < squadSize; ++i)
   {
      if(squad[i] == ship)
      {
         return i;
      }
   }
   return numeric_limits<size_t>::max();
}

Squadron& Squadron::opSelf (const Ship *ship, const SquadronOperation& op)
{
   op(*this, ship);
   return *this;
}

Squadron Squadron::opCopy (const Ship *ship, const SquadronOperation& op) const
{
   Squadron newSquadron(*this);
   newSquadron.opSelf(ship, op);
   return  newSquadron;
}

void Squadron::freeSquad ()
{
   delete[] squad;
   squad = nullptr;
   squadCapacity = 0;
   squadSize = 0;
}





