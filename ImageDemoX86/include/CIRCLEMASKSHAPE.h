#pragma once


#include "SHAPE.h"
#if !defined(AFX_CIRCLEMASKSHAPE_20130928__INCLUDED_)
#define AFX_CIRCLEMASKSHAPE_20130928__INCLUDED_
#include "ALGORITHMDEFINE.h"

///< 
class shapesPort CCIRCLEMASKSHAPE : public CSHAPE
{
public:
	CCIRCLEMASKSHAPE(void);
	CCIRCLEMASKSHAPE(CDBPOINT inCENTER, double inRAD = 80);
	CCIRCLEMASKSHAPE(const CCIRCLEMASKSHAPE & CTCIRCLMASK);
	~CCIRCLEMASKSHAPE(void);

public: 
	virtual void DO_ROTATE(CDBPOINT ptFIX, CDBPOINT ptMOVE);
	virtual void DO_MOVE(CDBPOINT ptSOURCE,CDBPOINT ptDEST);
	virtual void DO_MODFIY(int inPENSTYLE, int inWIDTH, COLORREF inCOLOR);
	virtual void DO_DRAW(CDC *pDC,double ctScale,double dyScale, double mOrignX, double mOrignY, bool mActive = false);

	virtual bool IS_HITON(CDBPOINT ptPOS);
	virtual void INIT_SIZE(CDC* pDC);

	virtual double distToCloseHandle(CDBPOINT inPOINT);
	virtual void displayActive();
	virtual void movebyHandle(CDBPOINT inPOINT);

public:
	CDBPOINT ptCENTER;
	double   ptRADIUS;
	CDBPOINT ptControl;

public:
	bool SET_CENTER_POINT(CDBPOINT inPOINT);
	bool SET_RADIUS(double inRADIUS);
	bool SET_CONTROL_POINT(CDBPOINT inPOINT);
	///bool SET_DRAW_MODEL(int inModel);

	bool GET_CENTER_POINT(CDBPOINT& inPOINT) const;
	bool GET_RADIUS(double& inRADIUS) const;
	bool GET_CONTROL_POINT(CDBPOINT& inPOINT) const;
	///bool GET_DRAW_MODEL(int& inModel) const;

};

#endif

