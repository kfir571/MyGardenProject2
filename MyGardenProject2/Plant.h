#pragma once

#include <afx.h>
#include "framework.h"

class Plant : public CObject
{
public:
	//DECLARE_SERIAL(Plant)

	Plant();
	Plant(CString Name, CString  Species, CString  Breeding_Grund, CString Sun_Exposure, CString Watering, CString Planting_season, CString Info);
	void Set_Name(CString Name);
	void Set_Species(CString Species);
	void Set_Breeding_Grund(CString Breeding_Grund);
	void Set_Sun_Exposure(CString Sun_Exposure);
	void Set_Watering(CString Watering);
	void Set_Planting_season(CString Planting_season);
	void Set_Mor_Info(CString Info);



	CString Get_Name();
	CString Get_Species();
	CString Get_Breeding_Grund();
	CString Get_Sun_Exposure();
	CString Get_Watering();
	CString Get_Planting_season();
	CString Get_Mor_Info();

	virtual void Set_Information(CString Info) = 0;
	virtual CString Get_Information()const = 0;
	virtual void Set_Father_Information(CString Info) = 0;
	virtual CString Get_Father_Information()const = 0;
	virtual CString Return_Type()const = 0;
	virtual void Serialize(CArchive& archive) ;



protected:

	CString Name;
	CString  Species;        //זן 
	CString  Breeding_Grund; //מצא גדול
	CString Sun_Exposure;     //חשיפה לשמש באחוזים
	CString Watering;            //מספר פעמי השקייה
	CString Info;
	CString Planting_season;


};

