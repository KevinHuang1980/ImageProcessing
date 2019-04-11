#pragma once

#if !defined(AFX_DBPOINT_DEFINE_20121220__INCLUDE)
#define AFX_DBPOINT_DEFINE_20121220__INCLUDE

#include "ALGORITHM_DEFINE.h"


class algorithm_PORT CDBPOINT
{
public:
	CDBPOINT(void);
	CDBPOINT(double inX, double inY);
	CDBPOINT(CPoint point);
	CDBPOINT(const CDBPOINT& lTPoint);

	CDBPOINT& operator = (CDBPOINT& LPCT_PT);
	CDBPOINT operator + (CDBPOINT& LPCT_PT);
	bool operator == (CDBPOINT LPCT_PT);
	bool operator != (CDBPOINT LPCT_PT);

	~CDBPOINT(void);
public:
	double x;
	double y;
};

#endif

