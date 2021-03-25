//
// Created by melvy on 24/03/2021.
//

#include <limits>    // numeric_limits<std::size_t>
#include <stdexcept> // invalid_argument
#include "SquadronRemove.h"

using namespace std;

void SquadronRemove::operator() (Squadron &squadron, const Ship* ship) const
{
   if(ship == nullptr) throw invalid_argument("Cannot add nullptr ship to squad.");

   size_t pos = squadron.contains(ship);
   if(pos != numeric_limits<std::size_t>::max())
   {
      if(squadron.squadSize > 1)
      {
         // Le vaisseau retiré est remplacé par le dernier
         squadron.squad[pos] = squadron.squad[squadron.squadSize - 1];
      }

      --squadron.squadSize;
   }
}

