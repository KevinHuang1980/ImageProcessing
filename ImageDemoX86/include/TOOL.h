#pragma once

#if !defined(AFX_ABSTRIC_TOOLS_20120920__INCLUDED_)
#define AFX_ABSTRIC_TOOLS_20120920__INCLUDED_

#include "TOOL_DEFINE.h"

///< 
class tools_PORT CTOOL
{
public:
	CTOOL(void);
	~CTOOL(void);
public: ///< ½Ó¿Ú
	virtual void OnLButtonUp(CDC* pDC, CDBPOINT in_POINT);         ///< Êó±ê×ó¼ü UP
	virtual void OnLButtonDown(CDC* pDC, CDBPOINT in_POINT);       ///< Êó±ê×ó»÷
	virtual void OnRButtonDown(CDC* pDC, CDBPOINT in_POINT);       ///< Êó±êÓÒ»÷
	virtual void OnMouseMove(CDC* pDC, CDBPOINT in_POINT);	       ///< Êó±êÒÆ¶¯
	virtual void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);

public:
	static BOOL  CreateImage(INT width, INT height, INT stride, INT formate, void* pVoid, CBitmap &outbitmap);

};

#endif

