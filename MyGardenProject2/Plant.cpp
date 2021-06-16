#include "pch.h"
#include "Plant.h"

//IMPLEMENT_SERIAL(Plant, CObject, 1)

Plant::Plant()
{
}

Plant::Plant(CString Name, CString Species, CString Breeding_Grund, CString Sun_Exposure, CString Watering, CString Planting_season, CString Info)
{
	this->Name = Name;
	this->Species = Species;
	this->Breeding_Grund = Breeding_Grund;
	this->Sun_Exposure = Sun_Exposure;
	this->Watering = Watering;
	this->Planting_season = Planting_season;
	this->Info = Info;
}

void Plant::Set_Name(CString Name)
{
	this->Name = Name;
}

void Plant::Set_Species(CString Species)
{
	this->Species = Species;
}

void Plant::Set_Breeding_Grund(CString Breeding_Grund)
{
	this->Breeding_Grund = Breeding_Grund;
}

void Plant::Set_Sun_Exposure(CString Sun_Exposure)
{
	this->Sun_Exposure = Sun_Exposure;
}

void Plant::Set_Watering(CString Watering)
{
	this->Watering = Watering;
}

void Plant::Set_Planting_season(CString Planting_season)
{
	this->Planting_season = Planting_season;
}

void Plant::Set_Mor_Info(CString Info)
{
	this->Info = Info;
}



CString Plant::Get_Name() 
{
	return this->Name;
}

CString Plant::Get_Species() 
{
	return this->Species;
}

CString Plant::Get_Breeding_Grund() 
{
	return this->Breeding_Grund;
}

CString Plant::Get_Sun_Exposure() 
{
	return this->Sun_Exposure;
}

CString Plant::Get_Watering() 
{
	return this->Watering;
}

CString Plant::Get_Planting_season()
{
	return this->Planting_season;
}

CString Plant::Get_Mor_Info()
{
	return this->Info;
}

void Plant::Serialize(CArchive& archive)
{
	CObject::Serialize(archive);
	if (archive.IsStoring())
	{			
		archive << Name;
		archive << Species;
		archive << Breeding_Grund;
		archive << Sun_Exposure;			
		archive << Watering;
		archive << Planting_season;
		archive << Info;
	}
	else		
	{
		archive >> Name;
		archive >> Species;
		archive >> Breeding_Grund;
		archive >> Sun_Exposure;
		archive >> Watering;
		archive >> Planting_season;
		archive >> Info;
	}
}
