#include "pch.h"
#include "Carnivorous_plant.h"

IMPLEMENT_SERIAL(Carnivorous_plant, Ornamental, 1)

Carnivorous_plant::Carnivorous_plant()
{
}

Carnivorous_plant::Carnivorous_plant(CString Name, CString Species, CString Breeding_Grund, CString Sun_Exposure,
	CString Watering, CString Planting_season, CString Growing_Area, CString Feeding, CString Info):
	Ornamental(Name, Species, Breeding_Grund, Sun_Exposure, Watering, Planting_season, Growing_Area, Info)
{
	this->Feeding = Feeding;
}

void Carnivorous_plant::Set_Information(CString Info)
{
	this->Feeding = Info;
}

CString Carnivorous_plant::Get_Information() const
{
	return this->Feeding;
}

void Carnivorous_plant::Set_Father_Information(CString Info)
{
	Ornamental::Set_Information(Info);
}

CString Carnivorous_plant::Get_Father_Information() const
{
	return Ornamental::Get_Information();
}

CString Carnivorous_plant::Return_Type() const
{
	return CString("Carnivorous plant");
}

void Carnivorous_plant::Serialize(CArchive& archive)
{
	Ornamental::Serialize(archive);

	if (archive.IsStoring())
	{
		archive << Feeding;
	}
	else
	{
		archive >> Feeding;
	}
}


