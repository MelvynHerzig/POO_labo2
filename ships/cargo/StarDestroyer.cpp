/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : StarDestroyer.cpp
 Auteur(s)   : Forestier Quentin & Melvyn Herzig
 Date        : 17/03/2021
 -----------------------------------------------------------------------------------
 */

#include "StarDestroyer.h"

unsigned StarDestroyer::count = 0;

StarDestroyer::StarDestroyer(double loadWeight, const std::string& nickname)
 : super(++count, loadWeight, nickname)
{}

double StarDestroyer::getEmptyWeight() const
{
    return 9000000000.0;
}

unsigned StarDestroyer::getSpeed() const
{
    return 40;
}

std::string StarDestroyer::getModel() const
{
    return "Super-class Star Destroyer";
}

double StarDestroyer::getMaxCargoWeight() const
{
    return 250000.0;
}
