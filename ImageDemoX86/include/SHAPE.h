#pragma once

#include <WinDef.h>
#include "SHAPE_DEFINE.h"
#include "DBPOINT.h"
#include "ALGORITHM_BOX.h"

///< 
class shapesPort CSHAPE
{
public:
	CSHAPE(void);
	~CSHAPE(void);
private:
	int shapePENSTYLE;       
	int shapeWIDTH;          
	COLORREF shapeCOLOR;     
	bool shapeSELECTED;      
	int  shapeControlHANDLES;
	int  shapeControlAcitve; 
	double shapeControlSIZE; 

public:
	char m_SHAPE_TYPE;           
	int& PEN_STYLE();            
	int& WIDTH();                
	COLORREF& COLOR();           
	bool& IS_SELECTED();         
	int& SHAPE_CONTROL_HANDLES();
	int& SHAPE_CONTROL_ACTIVE(); 
	double& SHAPE_CONTROL_SIZE();
	

public: 
	virtual void DO_ROTATE(CDBPOINT ptFIX, CDBPOINT ptMOVE);
	virtual void DO_MOVE(CDBPOINT ptSOURCE,CDBPOINT ptDEST);
	virtual void DO_MODFIY(int inPENSTYLE, int inWIDTH, COLORREF inCOLOR);
	virtual void DO_DRAW(CDC *pDC,double ctScale,double dySCale, double mOrignX, double mOrignY, bool mActive = false);
	

	virtual bool IS_HITON(CDBPOINT ptPOS);
	virtual void INIT_SIZE(CDC* pDC);

	virtual double distToCloseHandle(CDBPOINT inPOINT);
	virtual void displayActive();
	virtual void movebyHandle(CDBPOINT inPOINT);

};

