/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : Shuttle.cpp
 Auteur(s)   : Forestier Quentin & Herzig Melvyn
 Date        : 17/03/2021
 -----------------------------------------------------------------------------------
 */
#include "Shuttle.h"

unsigned Shuttle::count = 0;
const double Shuttle::WEIGHT = 360;
const double Shuttle::MAX_LOAD_WEIGHT = 80.0;
const unsigned Shuttle::SPEED = 54;
const std::string Shuttle::MODEL = "Lambda-class shuttle";

Shuttle::Shuttle(double loadWeight, const std::string& nickname)
        : super(++count, loadWeight, nickname)
{}

unsigned Shuttle::getSpeed() const
{
    return SPEED;
}

std::string Shuttle::getModel() const
{
    return MODEL;
}

double Shuttle::getMaxLoadWeight() const
{
    return MAX_LOAD_WEIGHT;
}

double Shuttle::getEmptyWeight() const
{
   return WEIGHT;
}
