#pragma once
#include "Plant.h"
class Ornamental :
    public Plant
{
public:
	DECLARE_SERIAL(Ornamental)

	Ornamental();
	Ornamental(CString Name, CString  Species, CString  Breeding_Grund, CString Sun_Exposure, CString Watering,
		CString Planting_season, CString Growing_Area, CString Info);

	virtual void Set_Information(CString Info);
	virtual CString Get_Information()const;
	virtual void Set_Father_Information(CString Info);
	virtual CString Get_Father_Information()const;
	virtual CString Return_Type()const;

	virtual void Serialize(CArchive& archive);
protected:

	CString Growing_Area;
};

