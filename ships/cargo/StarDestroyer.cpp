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
const double StarDestroyer::WEIGHT = 9000000000.0;
const double StarDestroyer::MAX_LOAD_WEIGHT = 250000.0;
const unsigned StarDestroyer::SPEED = 40;
const std::string StarDestroyer::MODEL = "Super-class Star Destroyer";

StarDestroyer::StarDestroyer(double loadWeight, const std::string& nickname)
 : super(++count, loadWeight, nickname)
{}

unsigned StarDestroyer::getSpeed() const
{
    return SPEED;
}

std::string StarDestroyer::getModel() const
{
    return MODEL;
}

double StarDestroyer::getMaxLoadWeight() const
{
    return MAX_LOAD_WEIGHT;
}

double StarDestroyer::getEmptyWeight() const
{
   return WEIGHT;
}
