#include "pch.h"
#include "Climbing_Plant.h"

IMPLEMENT_SERIAL(Climbing_Plant, Ornamental, 1)
Climbing_Plant::Climbing_Plant()
{
}

Climbing_Plant::Climbing_Plant(CString Name, CString Species, CString Breeding_Grund,CString Sun_Exposure,
CString Watering, CString Planting_season, CString Growing_Area, CString Hadlaya, CString Info): Ornamental(Name, Species, Breeding_Grund,
	Sun_Exposure, Watering, Planting_season, Growing_Area, Info)
{
	this->Hadlaya = Hadlaya;
}

void Climbing_Plant::Set_Information(CString Info)
{
	this->Hadlaya = Info;
}

CString Climbing_Plant::Get_Information() const
{
	return this->Hadlaya;
}

void Climbing_Plant::Set_Father_Information(CString Info)
{
	Ornamental::Set_Information(Info);
}

CString Climbing_Plant::Get_Father_Information() const
{
	return Ornamental::Get_Information();
}

CString Climbing_Plant::Return_Type() const
{
	return CString("A climbing plant");
}

void Climbing_Plant::Serialize(CArchive& archive)
{
	Ornamental::Serialize(archive);

	if (archive.IsStoring())
	{
		archive << Hadlaya;
	}
	else
	{
		archive >> Hadlaya;
	}
}
