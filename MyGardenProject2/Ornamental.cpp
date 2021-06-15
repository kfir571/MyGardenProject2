#include "pch.h"
#include "Ornamental.h"

IMPLEMENT_SERIAL(Ornamental, Plant, 1)

Ornamental::Ornamental()
{
}

Ornamental::Ornamental(CString Name, CString Species, CString Breeding_Grund, CString Sun_Exposure, CString Watering, CString Planting_season, CString Growing_Area, CString Info) :
	Plant(Name, Species, Breeding_Grund, Sun_Exposure, Watering, Planting_season, Info)
{
	this->Growing_Area = Growing_Area;
}

void Ornamental::Set_Information(CString Info)
{
	this->Growing_Area = Info;
}

CString Ornamental::Get_Information() const
{
	return this->Growing_Area;
}

void Ornamental::Set_Father_Information(CString Info)
{
}

CString Ornamental::Get_Father_Information() const
{
	return CString();
}

CString Ornamental::Return_Type() const
{
	return CString("An ornamental plant");
}

void Ornamental::Serialize(CArchive& archive)
{
	Plant::Serialize(archive);
	
	if (archive.IsStoring())
	{
		archive << Growing_Area;
	}
	else
	{
		archive >> Growing_Area;
	}
}
