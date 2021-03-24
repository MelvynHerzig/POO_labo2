/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : Cargo.cpp
 Auteur(s)   : Forestier Quentin & Melvyn Herzig
 Date        : 17/03/2021
 -----------------------------------------------------------------------------------
 */

#include "Cargo.h"

#include <iostream>

Cargo::Cargo(unsigned int count, double loadWeight, const std::string& nickname)
 : super(count, nickname), loadWeight(loadWeight)
{}

std::ostream& Cargo::toStream(std::ostream& os) const
{
    return super::toStream(os) << "\t cargo : " << loadWeight << " tons (max : " << getMaxCargoWeight() << ")" << std::endl;
}



