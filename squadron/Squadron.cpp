/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : Squadron.cpp
 Auteur(s)   : Forestier Quentin & Melvyn Herzig
 Date        : 17/03/2021
 -----------------------------------------------------------------------------------
 */

#include <limits>
#include <stdexcept>
#include <sstream>
#include <iomanip>
#include "operation/SquadronOperation.h"
#include "operation/SquadronRemove.h"
#include "operation/SquadronAdd.h"
#include "Squadron.h"

size_t Squadron::DEFAULT_SQUAD_SIZE = 10;

using namespace std;

Squadron operator+ (const Squadron &squadron, const Ship* ship)
{
   return squadron.add(ship);
}
Squadron operator+ (const Ship* ship, const Squadron &squadron)
{
   return operator+(squadron, ship);
}

// operateur -
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

   return os << fixed << setprecision(2)
             << "Squadron : " << squadron.name << endl
             << "\tmax speed : " << maxSpeed << " MGLT" << endl
             << "\ttotal weight : " << totalWeight << " tons" << endl << endl
             << "-- Leader: " << endl
             << *squadron.leader << endl << endl << ss.str();

}

void Squadron::init (const string &name, size_t squadCapacity, const Ship *leader)
{
   this->name = name;
   this->squadCapacity = squadCapacity;
   this->leader = leader;

   squad = new const Ship*[squadCapacity];
   squadSize = 0;
}

Squadron::Squadron (const string &name, size_t capacity, const Ship *leader)
{
   init(name, capacity, leader);
}

Squadron::Squadron (const string& name): Squadron(name , DEFAULT_SQUAD_SIZE, nullptr)
{}

Squadron::Squadron (const Squadron& otherSquadron) : Squadron(otherSquadron.name, otherSquadron.squadCapacity, otherSquadron.leader)
{
   copySquad(otherSquadron.squad, otherSquadron.squadSize);
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

Squadron::~Squadron()
{
   freeSquad();
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
   size_t capacityToAllocate = ( squadSize < squadCapacity) ? squadCapacity : squadCapacity * 2;
   Squadron newSquadron{name, capacityToAllocate, leader};
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

Squadron& Squadron::operator+= (const Ship *ship)
{
   return addSelf(ship);
}

Squadron& Squadron::operator-= (const Ship *ship)
{
   return removeSelf(ship);;
}

Squadron Squadron::add (const Ship *ship) const
{

   SquadronAdd op =  SquadronAdd();
   return opCopy(ship, op);
}

Squadron Squadron::remove (const Ship *ship) const
{
   SquadronRemove op =  SquadronRemove();
   return opCopy(ship, op);
}

Squadron& Squadron::addSelf (const Ship *ship)
{
   SquadronAdd op =  SquadronAdd();
   return opSelf(ship, op);
}

Squadron& Squadron::removeSelf (const Ship *ship)
{
   SquadronRemove op =  SquadronRemove();
   return opSelf(ship, op);
}

void Squadron::setName (const string &name)
{
   this->name = name;
}

void Squadron::unsetLeader ()
{
   leader = nullptr;
}

void Squadron::setLeader (const Ship *leader)
{
   if(contains(leader) != numeric_limits<size_t>::max())
   {
      this->leader = leader;
   }
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

Squadron& Squadron::operator= (const Squadron &otherSquadron)
{
   if(this == &otherSquadron) return *this;

   freeSquad();
   init(otherSquadron.name, otherSquadron.squadCapacity, otherSquadron.leader);
   copySquad(otherSquadron.squad, otherSquadron.squadSize);
   return *this;
}


