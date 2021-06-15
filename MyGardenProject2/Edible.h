#pragma once
#include "Plant.h"
class Edible : public Plant
{
public:
	DECLARE_SERIAL(Edible)

	Edible();
	Edible(CString Name, CString  Species, CString  Breeding_Grund, CString Sun_Exposure, CString Watering, CString Planting_season,
		CString Eating_Season, CString Info);
	
	virtual void Set_Information(CString Info);
	virtual CString Get_Information()const;
	virtual void Set_Father_Information(CString Info);
	virtual CString Get_Father_Information()const;
	virtual CString Return_Type()const;

	virtual void Serialize(CArchive& archive);
protected:
	CString Eating_Season;

};

