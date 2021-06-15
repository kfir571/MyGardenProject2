#include "pch.h"
#include "Edible.h"
#include <iostream>
using namespace std;

IMPLEMENT_SERIAL(Edible,Plant,1)
Edible::Edible()
{
}

Edible::Edible(CString Name, CString Species, CString Breeding_Grund, CString Sun_Exposure, CString Watering, CString Planting_season,
	CString Eating_Season, CString Info) :
	Plant(Name, Species, Breeding_Grund, Sun_Exposure, Watering,Planting_season,Info)
{
	this->Eating_Season = Eating_Season;
}

void Edible::Set_Information(CString Info)
{
	this->Eating_Season = Info;
}

CString Edible::Get_Information() const
{
	return this->Eating_Season;
}

void Edible::Set_Father_Information(CString Info)
{
}

CString Edible::Get_Father_Information() const
{
	return CString();
}

CString Edible::Return_Type() const
{
	return CString("Edible plant");
}

void Edible::Serialize(CArchive& archive)
{
	Plant::Serialize(archive);
	if (archive.IsStoring())
	{
		archive << Eating_Season;
	}
	else
	{
		archive >> Eating_Season;
	}
}
