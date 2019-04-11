#pragma once
#include "SHAPE.h"
#if !defined(AFX_CIRCLECONTOURSHAPE_20130924__INCLUDED_)
#define AFX_CIRCLECONTOURSHAPE_20130924__INCLUDED_
#include "ALGORITHMDEFINE.h"

///< 
class shapesPort CCIRCLECONTOURSHAPE :public CSHAPE
{
public:
	CCIRCLECONTOURSHAPE(void);
	CCIRCLECONTOURSHAPE(CDBPOINT inCenter,double inRadius,double inWidth = 10,double inHeight = 30,int inPoints = 10,double inStart = 0, double inEnd = 2*PI,bool inOutIn = true,double inSize =10);
	~CCIRCLECONTOURSHAPE(void);

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

public:
	CDBPOINT ptCENTER;     
	double   ptRADIUS;     
	double   ptWIDTH;      
	double   ptHEIGHT;     
	int      ptPOINTS;     
	double   ptSTARTANGLE; 
	double   ptENDTANGLE;  
	bool     ptOutIn;      
	double   ptArrowSize;  

	double mSIGMA;
	double mTHRESHOLD;
	int    mSELECT;
	int    mTRANSITION;

	bool SET_CENTER_POINT(CDBPOINT inPOINT);
	bool SET_RADIUS(double inRADIUS);
	bool SET_WIDTH(double inWIDTH);
	bool SET_HEIGHT(double inHEIGHT);
	bool SET_POINTS(double inPOIONTS);
	bool SET_STARTANGLE(double inSTART);
	bool SET_ENDANGLE(double inEND);
	bool SET_OUTIN(bool inOutIn);
	bool SET_ARROWSIZE(double inSIZE);

	bool SET_SIGMA(double inSIGMA);
	bool SET_THRESHOLD(double inTHRESHOLD);
	bool SET_SELECET(int inSELECT);
	bool SET_TRANSITION(int inTRANSITION);


	bool GET_CENTER_POINT(CDBPOINT& inPOINT)const;
	bool GET_RADIUS(double& inRADIUS)const;
	bool GET_WIDTH(double& inWIDTH)const;
	bool GET_HEIGHT(double& inHEIGHT)const;
	bool GET_POINTS(double& inPOIONTS)const;
	bool GET_STARTANGLE(double& inSTART)const;
	bool GET_ENDANGLE(double& inEND)const;
	bool GET_OUTIN(bool& inOutIn)const;
	bool GET_ARROWSIZE(double& inSIZE)const;

	bool GET_SIGMA(double& inSIGMA) const;
	bool GET_THRESHOLD(double& inTHRESHOLD) const;
	bool GET_SELECET(int& inSELECT) const;
	bool GET_TRANSITION(int& inTRANSITION) const;
};

#endif

