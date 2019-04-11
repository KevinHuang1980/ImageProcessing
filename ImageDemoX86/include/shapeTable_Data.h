
#pragma once
#if !defined(AFX_SHAPETABLE_DATA_20120923__INCLUDED_)
#define AFX_SHAPETABLE_DATA_20120923__INCLUDED_

#include <afxstr.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "SHAPE_DEFINE.h"
#include "CIRCLESHAPE1.h"
#include "RECTANGLE2SHAPE.h"
#include "LINECONTOURSHAPE.h"
#include "CIRCLECONTOURSHAPE.h"
#include "CIRCLEMASKSHAPE.h"
#include "RECTANGLEMASKSHAPE.h"

///< 
enum NODE_TYPE
{
	enNODE_NULL = 0,
	enNODE_CIRCLE1,
	enNODE_RECT2,
	enNODE_NUM,
};

enum OPSHAPE_TYPE
{
	enOP_Union =0,
	enOP_Differnce,
	enOP_Intersection,
	enOP_Shape_NUM,
};

typedef struct NODE_SHAPE
{
public:
	NODE_SHAPE()
	{
		nodeTye = (int)enNODE_NULL;
		nodeIndex = 0;
		nodeLoad = false;
		nodeOp = (int)enOP_Union;

		m_pCIRCLE1 = NULL;
		m_pRECT2  = NULL;
	}

public:

	CCIRCLESHAPE1     *m_pCIRCLE1;
	CRECTANGLE2SHAPE  *m_pRECT2 ;

	int nodeTye;      ///< 节点类型
	UINT nodeIndex;   ///< 节点索引
	bool nodeLoad;    ///< 节点加载
	int nodeOp;       ///< 节点算法

public:
	void CLEAR_NODE_SHAPE()
	{
		if (m_pCIRCLE1 != NULL)
		{
			delete m_pCIRCLE1;
			m_pCIRCLE1 = NULL;
		}

		if (m_pRECT2 != NULL)
		{
			delete m_pRECT2;
			m_pRECT2 = NULL;
		}

		nodeTye = (int)enNODE_NULL;
		nodeIndex = 0;
		nodeLoad = false;
		nodeOp = (int)enOP_Union;

		m_pCIRCLE1 = NULL;
		m_pRECT2  = NULL;
	}
}nodeShape, *pnodeShape;

typedef struct SHAPES_ENTITY_UNIT
{
public:
	SHAPES_ENTITY_UNIT()
	{
		SHAPES_NAME = _T("");
		m_SHAPES.clear();
	}

public:
	bool ADD_NODE_SHAPE(nodeShape inNode)
	{
		try
		{
			m_SHAPES.push_back(inNode);
		}
		catch(...)
		{
			return false;
		}
		return true;
	}

	bool DELETE_NODE_SHAPE(UINT inID)
	{
		try
		{
			if (!m_SHAPES.empty())
			{
				if ( (int)inID > ((int)m_SHAPES.size()) ) return false;
				m_SHAPES[inID-1].CLEAR_NODE_SHAPE();
				m_SHAPES.erase( m_SHAPES.begin()+(inID-1) );
			}
		}
		catch(...)
		{
			return false;
		}
		return true;
	}

	bool CLEAR_ENTITY_UNIT()
	{
		try
		{
			if (!m_SHAPES.empty())
			{
				int nodeCount = (int)m_SHAPES.size();
				for(int i=0; i<nodeCount; i++)
				{
					DELETE_NODE_SHAPE((UINT)(nodeCount-i));
				}
				SHAPES_NAME = _T("");
				m_SHAPES.clear();
			}
		}
		catch(...)
		{
			return false;
		}
		return  true;
	}

public:
	CString SHAPES_NAME;
	vector<nodeShape> m_SHAPES;
}shapesEntityUnit, *pshapeEntityUnit;

enum CONTOUR_TYPE
{
	enContour_Null =0,
	enContour_Line,
	enContour_Circle,
	enCoutour_NUM,
};

typedef struct NODE_CONTOUR
{
public:
	NODE_CONTOUR()
	{
		contourType = (int)enContour_Null;
		contourIndex = 0;
		contourLoad = false;
		m_pContourLine = NULL;
		m_pContourCircle = NULL;
	}
public:
	CLINECONTOURSHAPE   *m_pContourLine;
	CCIRCLECONTOURSHAPE *m_pContourCircle;

	int   contourType; 
	UINT  contourIndex;
	bool  contourLoad; 
public:
	void CLEAR_NODE_CONTOUR()
	{
		if ( m_pContourLine!=NULL )
		{
			delete m_pContourLine;
			m_pContourLine = NULL;
		}

		if (m_pContourCircle != NULL)
		{
			delete m_pContourCircle;
			m_pContourCircle = NULL;
		}

		contourType = (int)enContour_Null;
		contourIndex = 0;
		contourLoad = false;
		m_pContourLine = NULL;
		m_pContourCircle = NULL;
	}

}nodeContour,*pnodeContour;

typedef struct CONTOUR_ENTITY_UNIT
{
public:
	CONTOUR_ENTITY_UNIT()
	{
		CONTOUR_NAME = _T("");
		m_CONTROURS.clear();
	}
public:
	CString CONTOUR_NAME;
	vector<nodeContour> m_CONTROURS;

public:
	bool ADD_NODE_CONTOUR(nodeContour inNode)
	{
		try
		{
			m_CONTROURS.push_back(inNode);
		}
		catch(...)
		{
			return false;
		}
		return true;
	}

	bool DELETE_NODE_CONTOUR(UINT inID)
	{
		try
		{
			if ( (int)inID > ((int)m_CONTROURS.size()) ) return false;
			m_CONTROURS[inID-1].CLEAR_NODE_CONTOUR();
			m_CONTROURS.erase( m_CONTROURS.begin()+(inID-1) );
		}
		catch(...)
		{
			return false;
		}
		return true;
	}

	bool CLEAR_ENTITY_UNIT()
	{
		try
		{
			int nodeCount = (int)m_CONTROURS.size();
			for(int i=0; i<nodeCount; i++)
			{
				DELETE_NODE_CONTOUR((UINT)(nodeCount-i));
			}
			CONTOUR_NAME = _T("");
			m_CONTROURS.clear();
		}
		catch(...)
		{
			return false;
		}
		return true;
	}

}contourEntityUnit,*pcontourEntityUnit;


enum MASK_TYPE
{
	enMask_Null =0,
	enMask_Cricle,
	enMask_Rect,
	enMask_NUM,
};


typedef struct NODE_MASK
{
public:
	NODE_MASK()
	{
		maskType = (int)enMask_Null;
		maskIndex = 0;
		maskLoad = false;
		pMaskCircle = NULL;
		pMaskRect = NULL;
	}

public:
	void CLEAR_NODE_MASK()
	{
		if(pMaskCircle!=NULL)
		{
			delete pMaskCircle;
			pMaskCircle = NULL;
		}

		if(pMaskRect != NULL)
		{
			delete pMaskRect;
			pMaskRect = NULL;
		}

		maskType = (int)enMask_Null;
		maskIndex = 0;
		maskLoad = false;
		pMaskCircle = NULL;
		pMaskRect = NULL;
	}


public:
	CCIRCLEMASKSHAPE    *pMaskCircle;
	CRECTANGLEMASKSHAPE *pMaskRect;
	int  maskType;
	UINT maskIndex;
	bool maskLoad;

}nodeMask,*pnodeMask;

typedef struct MASK_ENTITY_UNIT
{
public:
	MASK_ENTITY_UNIT()
	{
		MASK_NAME = _T("");
		m_MASK.clear();
	}

public:
	CString MASK_NAME;
	vector<nodeMask>m_MASK;

public:
	bool ADD_NODE_MASK(nodeMask inNode)
	{
		try
		{						
			this->m_MASK.push_back(inNode);
		}
		catch(...)
		{
			return false;
		}
		return true;
	}

	bool DELETE_NODE_MASK(UINT inID)
	{
		try
		{
			if ( (int)inID > ((int)this->m_MASK.size()) ) return false;
			this->m_MASK[inID-1].CLEAR_NODE_MASK();
			this->m_MASK.erase( m_MASK.begin()+(inID-1) );
		}
		catch(...)
		{
			return false;
		}
		return true;
	}

	bool CLEAR_ENTITY_UNIT()
	{
		try
		{
			int nodeCount = (int)m_MASK.size();
			for(int i=0; i<nodeCount; i++)
			{
				this->DELETE_NODE_MASK((UINT)(nodeCount-i));
			}
			this->MASK_NAME = _T("");
			this->m_MASK.clear();
		}
		catch(...)
		{
			return false;
		}
		return true;
	}

}maskEntityUnit,*pmaskEntityUnit;

typedef struct SHOW_CURVE_UNIT
{
public:
	SHOW_CURVE_UNIT()
	{
		m_CURVES.clear();
	}
	bool ADD_POINT(CDBPOINT inPOINT)
	{
		try
		{
			this->m_CURVES.push_back(inPOINT);
		}
		catch(...)
		{
		  return false;
		}
		return true;
	}

	bool CLEAR_POINTS()
	{
		try
		{
			if(!m_CURVES.empty())
			{
				this->m_CURVES.clear();
			}			
		}
		catch(...)
		{
		  return false;
		}
		return true;
	}

public:
	vector<CDBPOINT> m_CURVES;
}showCurveUnit,*pShowCurveUnit;


typedef struct SHOW_CURVES_UNIT
{
public:
	SHOW_CURVES_UNIT()
	{
		vec_CURVES.clear();
	}
	bool ADD_CURVE(showCurveUnit inCurve)
	{
		try
		{
			this->vec_CURVES.push_back(inCurve);
		}
		catch(...)
		{
		  return false;
		}
		return true;
	}

	bool ClEAR_CURVE()
	{
		try
		{
			if(!vec_CURVES.empty())
			{
				int nSize = this->vec_CURVES.size();
				for(int i = 0; i<nSize; i++)
				{
					this->vec_CURVES[i].CLEAR_POINTS();
				}
				vec_CURVES.clear();
			}			
		}
		catch(...)
		{
		  return false;
		}
		return true;
	}

public:
     vector<showCurveUnit>vec_CURVES;
}showCurvesUnit,*pShowCurvesUnit;


#endif