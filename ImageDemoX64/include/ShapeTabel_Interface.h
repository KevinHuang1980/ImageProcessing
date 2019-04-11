#pragma once
#include "shapeTable_DEFINE.h"

#if !defined(AFX_ShapeTabel_Interface_20190923__INCLUDED_)
#define AFX_ShapeTabel_Interface_20190923__INCLUDED_

class shapeTable_PORT CShapeTabel_Interface
{
public:
	CShapeTabel_Interface(void);
	~CShapeTabel_Interface(void);
public:
	void DrawShapeContour(CDC *cdc, double ctScale,double dyScale,double xOff,double yOff);
	
	void Add_Search(CDBPOINT inPoint, int inType);
	void Add_Shape(CDBPOINT inPoint,int inType);  
	void Add_Contour(CDBPOINT inPoint,int inType);
	void Add_Mask(CDBPOINT inPoint,int inType);
	
	bool Get_Search_Active(CDBPOINT inPoint);
	bool Get_Shape_Active(CDBPOINT inPoint);
	bool Get_Caliper_Active(CDBPOINT inPoint);
	bool Get_Mask_Active(CDBPOINT inPoint);
	
	bool MoveSearchByHandle(CDBPOINT inPoint);
	bool MoveShapeByHandle(CDBPOINT inPoint);
	bool MoveContourByHandle(CDBPOINT inPoint);
	bool MoveMaskByHandle(CDBPOINT inPoint);
	
	bool Delete_Search_Selected(int searchIndex = -1);
	bool Delete_Shape_Selected(int shapeIndex = -1);
	bool Delete_Contour_Selected(int caliperIndex = -1);
	bool Delete_Mask_Selected(int maskIndex = -1);

public:
	shapesEntityUnit  mSearchEntity;   
	shapesEntityUnit  mShapeEntity;    
	contourEntityUnit mContourEntity;  
	maskEntityUnit    mMaskEntity;     
	
	int activeSearchIndex;
	int activeShapeIndex;
	int activeCaliperIndex;
	int activeMaskIndex;

public:
    showCurvesUnit mCurvesEntity;
	showCurveUnit  mCurveEntity;
	void DrawCurveContour(CDC *cdc, double ctScale, double dyScale, double xOff, double yOff, int inType = 0);
	void ClearCurveContour();
};

#endif

