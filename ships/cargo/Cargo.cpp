/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : Cargo.cpp
 Auteur(s)   : Forestier Quentin & Melvyn Herzig
 Date        : 17/03/2021
 -----------------------------------------------------------------------------------
 */

#include "Cargo.h"

#include <ostream>   // ostream
#include <sstream>   // ostringstream
#include <stdexcept> // invalid_argument
#include <iomanip>   // setprecision

using namespace std;

Cargo::Cargo(unsigned int count, double loadWeight, const std::string& nickname)
 : super(count, nickname), loadWeight(loadWeight)
{}

std::ostream& Cargo::toStream(std::ostream& os) const
{
    return super::toStream(os) << endl << "\t cargo : " << loadWeight << " tons (max : " << getMaxCargoWeight() << ")";
}

void Cargo::setLoadWeight (double loadWeight)
{
   if(loadWeight > getMaxCargoWeight())
   {
      // Formattage du poids avec deux décimales.
      ostringstream stringStream;
      stringStream << fixed << setprecision(2) << getMaxCargoWeight();
      throw invalid_argument("Load weight must be smaller than " + stringStream.str());
   }
}

double Cargo::getWeight () const
{
   return loadWeight + getEmptyWeight();
}





