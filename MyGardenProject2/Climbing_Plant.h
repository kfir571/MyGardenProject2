#pragma once
#include "Ornamental.h"
class Climbing_Plant : public Ornamental
{
public:
	DECLARE_SERIAL(Climbing_Plant)

	Climbing_Plant();
	Climbing_Plant(CString Name, CString  Species, CString  Breeding_Grund, CString Sun_Exposure, CString Watering, CString Planting_season
		, CString Growing_Area, CString Hadlaya, CString Info);
	
	virtual void Set_Information(CString Info);
	virtual CString Get_Information()const;
	virtual void Set_Father_Information(CString Info);
	virtual CString Get_Father_Information()const;
	virtual CString Return_Type()const;

	virtual void Serialize(CArchive& archive);
protected:

	CString Hadlaya; 
};

