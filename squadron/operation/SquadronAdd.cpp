//
// Created by melvy on 24/03/2021.
//

#include <limits>     // numeric_limits<std::size_t>
#include <stdexcept>  // invalid_argument
#include "SquadronAdd.h"

using namespace std;

void SquadronAdd::operator() (Squadron &squadron, const Ship* ship) const
{
   if(ship == nullptr) throw invalid_argument("Cannot add nullptr ship to squad.");

   if(squadron.contains(ship) == numeric_limits<std::size_t>::max())
   {
      if(squadron.squadSize == squadron.squadCapacity)
      {
         squadron.increaseCapacity();
      }

      squadron.squad[squadron.squadSize] = ship;
      ++squadron.squadSize;
   }
}
