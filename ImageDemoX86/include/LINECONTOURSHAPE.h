#pragma once
#include "SHAPE.h"
#if !defined(AFX_LINECONTOURSHAPE_20130924__INCLUDED_)
#define AFX_LINECONTOURSHAPE_20130924__INCLUDED_

///< 
class shapesPort CLINECONTOURSHAPE: public CSHAPE
{
public:
	CLINECONTOURSHAPE(void);
	CLINECONTOURSHAPE(CDBPOINT ptBegin, CDBPOINT ptEnd);
	CLINECONTOURSHAPE(CDBPOINT ptBegin, CDBPOINT ptEnd,double ptWidth, double ptHeight,int ptNum, bool ptOutin);
	~CLINECONTOURSHAPE(void);

public: ///< ½Ó¿Úº¯Êý
	virtual void DO_ROTATE(CDBPOINT ptFIX, CDBPOINT ptMOVE);
	virtual void DO_MOVE(CDBPOINT ptSOURCE,CDBPOINT ptDEST);
	virtual void DO_MODFIY(int inPENSTYLE, int inWIDTH, COLORREF inCOLOR);
	virtual void DO_DRAW(CDC *pDC, double ctScale,double dySCale, double mOrignX, double mOrignY, bool mActive = false);	

	virtual bool IS_HITON(CDBPOINT ptPOS);
	virtual void INIT_SIZE(CDC* pDC);

	virtual double distToCloseHandle(CDBPOINT inPOINT);
	virtual void displayActive();
	virtual void movebyHandle(CDBPOINT inPOINT);

public:
	double mARROW;         
	CDBPOINT mPOINT[2];    
	int    mPOINTS;        
	double mWIDTH;         
	double mHEIGHT;        
	bool   mOUTIN;         
	double mSIGMA;
	double mTHRESHOLD;
	int    mSELECT;
	int    mTRANSITION;
	
	bool SET_START_POINT(CDBPOINT);
	bool SET_END_POINT(CDBPOINT);
	bool SET_POINTS(int inNum);
	bool SET_WIDTH(double inWidth);
	bool SET_HEIGHT(double inHeight);
	bool SET_DIRECTION(bool inOutIn);
	bool SET_ARROW(double inArrow);
	bool SET_CONTROL_POINT(CDBPOINT);

	bool SET_SIGMA(double inSIGMA);
	bool SET_THRESHOLD(double inTHRESHOLD);
	bool SET_SELECET(int inSELECT);
	bool SET_TRANSITION(int inTRANSITION);


	bool GET_START_POINT(CDBPOINT&)const;
	bool GET_END_POINT(CDBPOINT&)const;
	bool GET_POINTS(int& inNum)const;	
	bool GET_WIDTH(double& inWidth)const;
	bool GET_HEIGHT(double& inHeight)const;
	bool GET_DIRECTION(bool& inOutIn)const;
	bool GET_ARROW(double& inArrow)const;
	int  GET_CONTROL_POINT(CDBPOINT&)const;

	bool GET_SIGMA(double& inSIGMA) const;
	bool GET_THRESHOLD(double& inTHRESHOLD) const;
	bool GET_SELECET(int& inSELECT) const;
	bool GET_TRANSITION(int& inTRANSITION) const;

};

#endif

