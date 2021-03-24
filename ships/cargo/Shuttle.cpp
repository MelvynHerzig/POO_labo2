/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : Shuttle.cpp
 Auteur(s)   : Forestier Quentin & Melvyn Herzig
 Date        : 17/03/2021
 -----------------------------------------------------------------------------------
 */
#include "Shuttle.h"

unsigned Shuttle::count = 0;

Shuttle::Shuttle(double loadWeight, const std::string& nickname)
        : super(++count, loadWeight, nickname)
{}

double Shuttle::getEmptyWeight() const
{
    return 360.0;
}

unsigned Shuttle::getSpeed() const
{
    return 54;
}

std::string Shuttle::getModel() const
{
    return "Lambda-class shuttle";
}

double Shuttle::getMaxCargoWeight() const
{
    return 80.0;
}
