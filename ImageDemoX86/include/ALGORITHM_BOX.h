#pragma once

#include <afxtempl.h>
#include "ALGORITHM_DEFINE.h"
#include "DBPOINT.h"
#include <vector>
using namespace std;
///< 
class algorithm_PORT CALGORITHM_BOX
{
public:
	CALGORITHM_BOX(void);
	~CALGORITHM_BOX(void);
public:
	static int nPEN_STYLE;       ///< 笔类型
	static int nWIDTH;           ///< 线宽度
	static COLORREF mCOLOR;      ///< 线颜色
	static CDBPOINT mORIGIN;     ///< 自定义坐标原点

	///< static double   mSCALE;      
	///< static CRect    mRECT;       
	///< static CSize    mPAPERSIZE;  
	///< static double   constSCALE;  

public: ///< 属性操作
	///< static bool SETCONSTRECT(CRect inRect);   
	///< static bool SETCONSTPAPER(CSize inSize);  
	
	static double GETDISTANCE(CDBPOINT startPoint,CDBPOINT endPoint); 
	static double GETANGLE(CDBPOINT beginPoint, CDBPOINT endPoint);   
	static double GETSLOPE(CDBPOINT beginPoint,CDBPOINT endPoint);    

	///< static CDBPOINT PAPER_TO_VIEW(CDBPOINT in_PAPER);                  
	///< static CDBPOINT VIEW_TO_PAPER(CDBPOINT in_PAPER);                  

	static CDBPOINT PAPER_TO_VIEW(CDBPOINT in_PAPER,double ctScale,double dySCale, double mOrignX, double mOrignY);  
	static CDBPOINT VIEW_TO_PAPER(CDBPOINT in_PAPER,double ctScale,double dySCale, double mOrignX, double mOrignY);  
	static CDBPOINT ROTATE_ANGLE_POINT(CDBPOINT in_POINT, double in_ANGLE, CDBPOINT base_POINT);                     

	static bool HITONLINE(CDBPOINT ptBEGIN, CDBPOINT ptEND, CDBPOINT ptPOS);
	static bool HITONCIRCLE(CDBPOINT in_POINT, CDBPOINT ptCENTER, CDBPOINT ptONCIRCLE);
	static bool HITONPOLY(CDBPOINT in_POINT,CDBPOINT in_POLYGON[],int nCOUNT);
	static bool HITONPOLY(CDBPOINT in_POINT,CArray<CDBPOINT,CDBPOINT>& inArray);
	

	static bool POINTINPOLYGON(CDBPOINT in_POINT, CDBPOINT in_POLYGON[], int nCOUNT);
	static bool POINTINCIRCLE(CDBPOINT in_POINT, CDBPOINT in_CENTER, double in_RADIUS);
public: 
	///< static void DRAW_LINE(CDC* pDC, CDBPOINT begin_POINT, CDBPOINT end_POINT);
	///< static void DRAW_RECTANGLE1(CDC* pDC, CDBPOINT ptBEGIN, CDBPOINT ptEND);
	///< static void DRAW_RECTANGLE2(CDC* pDC, CDBPOINT ptCENTER, double inLen1,double inLen2,double inRad);
	///< static void DRAW_CIRCLE(CDC* pDC, CDBPOINT ptCENTER, double in_R, double inAng1,double inAng2);
	///< static void DRAW_POLYGON(CDC* pDC, CArray<CDBPOINT, CDBPOINT> &ARYPT_POLYGON);

	static void DRAW_LINE(CDC* pDC, CDBPOINT begin_POINT, CDBPOINT end_POINT,double ctScale,double dySCale, double mOrignX, double mOrignY);
	static void DRAW_LINECONTOUR(CDC* pDC, CDBPOINT begin_POINT, CDBPOINT end_POINT,double ctScale,double dySCale, double mOrignX, double mOrignY, double mWidth, double mHeight, int mNumber, bool mOutin, double mArrySize = 15 );
	static void DRAW_CIRCLECONTOUR(CDC* pDC, CDBPOINT ptCENTER, double in_R, double inAng1,double inAng2,double ctScale,double dySCale, double mOrignX, double mOrignY, double mWidth, double mHeight, int mNumber, bool mOutin, double mArrySize = 15 );

	static void DRAW_RECTANGLE1(CDC* pDC, CDBPOINT ptBEGIN, CDBPOINT ptEND,double ctScale,double dySCale, double mOrignX, double mOrignY);
	static void DRAW_RECTANGLE2(CDC* pDC, CDBPOINT ptCENTER, double inLen1,double inLen2,double inRad,double ctScale,double dySCale, double mOrignX, double mOrignY);
	static void DRAW_RECT2(CDC* pDC, CDBPOINT ptCENTER, double inLen1,double inLen2,double inRad,double ctScale,double dySCale, double mOrignX, double mOrignY);
	static void DRAW_CIRCLE(CDC* pDC, CDBPOINT ptCENTER, double in_R, double inAng1,double inAng2,double ctScale,double dySCale, double mOrignX, double mOrignY);
	static void DRAW_POLYGON(CDC* pDC, CArray<CDBPOINT, CDBPOINT> &ARYPT_POLYGON,double ctScale,double dySCale, double mOrignX, double mOrignY);

	static void DRAW_COVER_CIRCLE(CDC* pDC, CDBPOINT ptCENTER, double inR, double ctScale,double dyScale, double mOrignX, double mOrignY,int mDrawModel = 15);
	static void DRAW_COVER_RECT(CDC* pDC, CDBPOINT ptCENTER,double inLen1,double inLen2, double inRad, double ctScale,double dyScale, double mOrignX, double mOrignY,int mDrawModel = 15);

	static bool DRAW_CONTOUR(CDC* pDC, vector<CDBPOINT>&inPoint, double ctScale, double dySCale, double mOrignX, double mOrignY, CRect inRect, COLORREF inColor = RGB(0,250,0));
	static bool DRAW_POINTS(CDC* pDC, vector<CDBPOINT>&inPoint, double ctScale, double dySCale, double mOrignX, double mOrignY, CRect inRect, COLORREF inColor  = RGB(0, 250, 0));

	static bool DRAW_CONTOUR(CDC* pDC, vector<CDBPOINT>&inPoint, double ctScale, double dySCale, double mOrignX, double mOrignY, COLORREF inColor = RGB(0, 250, 0));
	static bool DRAW_POINTS(CDC* pDC, vector<CDBPOINT>&inPoint, double ctScale, double dySCale, double mOrignX, double mOrignY, COLORREF inColor = RGB(0, 250, 0));

	static bool DRAW_CONTOUR_POINTS(CDC* pDC, vector<CDBPOINT>&inPoint, double ctScale, double dySCale, double mOrignX, double mOrignY, COLORREF inColor = RGB(0, 250, 0));

	static bool CHECK_CDC(CDC* pDC, CRect inRect);
};

