#pragma once
#include "SHAPE.h"

#if !defined(AFX_RECTANGLE2SHAPE_20130922__INCLUDED_)
#define AFX_RECTANGLE2SHAPE_20130922__INCLUDED_


class shapesPort CRECTANGLE2SHAPE: public CSHAPE
{
public:
	CRECTANGLE2SHAPE(void);
	CRECTANGLE2SHAPE(CDBPOINT ptCenter, double len1 = 60, double len2 =40,double angle = 0);
	~CRECTANGLE2SHAPE(void);

public: 
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
	CDBPOINT ptCENTER;
	double ptLEN1,ptLEN2,ptANGLE;

	bool SET_CENTER_POINT(CDBPOINT inPOINT);
	bool SET_LENGTH1(double inLen);
	bool SET_LENGTH2(double inLEN);
	bool SET_ANGLE(CDBPOINT inPOINT);
	bool SET_ANGLE(double inANGLE);

	bool GET_CENTER_POINT(CDBPOINT& inPOINT)const;
	bool GET_LENGTH1(double& inLen)const;
	bool GET_LENGTH2(double& inLEN)const;
	bool GET_ANGLE(double& inANGLE)const;
};

#endif

