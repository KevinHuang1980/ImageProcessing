#pragma once

#if !defined(AFX_PhotoControl_DEFINE_20120924__INCLUDE)
#define AFX_PhotoControl_DEFINE_20120924__INCLUDE

#include "displayFunction_Define.h"
#include "IMAGE_DATA.h"
#include "ControlOperation.h"

#define UPDATE_DRAWMESSAGE   WM_USER+200
#define UPDATE_IMAGE         WM_USER+300
#define CONTROLOPERATE_INFO  WM_USER+500
#define CONTROLACTIVE_INFO   WM_USER+501
#define CONTROLMOUSE_INFO    WM_USER+800
#define CONTROL_LBTNDOWN     WM_USER+1000
#define CONTROL_RBTNDOWN     WM_USER+1001
#define CONTROL_MBTNDOWN     WM_USER+1002
#define CONTROL_LBTNUP       WM_USER+1003

class displayFunction_PORT CPhotoControl : public CStatic
{
	DECLARE_DYNAMIC(CPhotoControl)

public:
	CPhotoControl();
	virtual ~CPhotoControl();

protected:
	DECLARE_MESSAGE_MAP()

///< protected:
public:
	afx_msg void OnPaint();

	afx_msg void OnViewAll();
	afx_msg void OnViewMove();
	afx_msg void OnViewScale();
	afx_msg void OnViewLock();

	afx_msg void OnDrawCircle();
	afx_msg void OnDrawRect2();
	afx_msg void OnCalipersLine();
	afx_msg void OnCalipersCircle();
	afx_msg void OnMaskCircle();
	afx_msg void OnMaskRect();
	afx_msg void OnSearchCircle();
	afx_msg void OnSearchRect();

	afx_msg void OnImageOpen();
	afx_msg void OnClearCurves();
	void OpenImage(CString);
	void Refresh();
	
protected:
	unsigned char  *ImageBufferData;           
	ULONG_PTR      mGdiplusToken;              
	LoadBmpType    mLoadFromType;              
	GILBERT_IMG_OBJ mImageObject;              
	TunnelType     mTunnelType;                
	BOOL           bShowMengBan;               
	COLORREF       transparentBackgroundColor; 
	CPoint         bitmapOrignPoint;           
	CRect          RectBitMap;                 
	CRect          ControlRect;                
	float          constScale;                 
	float          dynamicScale;               
	BOOL           bControlInit;               
				   
	CPoint         mMousePoint;                
	CPoint         mMouseNote;                 
	Conntrol_State mControlState;              
	Draw_State     mDrawState;                 

	BOOL ShiftBitMapToCenter();             
	BOOL DrawBitMapRect(CDC *cdc);          

	BOOL LoadFromFile(LPCTSTR BmpPath);     
	BOOL LoadFromBuffer(GILBERT_IMG_OBJ *); 
	void RepaintControl(CDC *);
	int menuLeve;

public: ///< 供外部调用
	///< void OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);  ///< 滚动鼠标中建
	///< void OnMouseMove(UINT nFlags, CPoint point);			   ///< 移动鼠标
	///< void OnLButtonDown(UINT nFlags, CPoint point);			   ///< 左键压下
	///< void OnRButtonDown(UINT nFlags, CPoint point);			   ///< 右键压下
	///< void OnLButtonUp(UINT nFlags, CPoint point);			   ///< 左键弹上 
	///< void OnSize(UINT nType, int cx, int cy);				   ///< 移动大小
	///< void LButtonDblClk(UINT nFlags, CPoint point);			   ///< 左键双击

	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);;
	afx_msg void OnMButtonDown(UINT   nFlags, CPoint   point);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	BOOL OnTestAlgorithm();
	BOOL SET_MENU_LEVEL(int inLevel);
	

public: ///< 图片资源来源
	BOOL bImageBufferInit;
	CString ImagePath;

	void InitBitmapControlFromBuffer(GILBERT_IMG_OBJ*, int, int, COLORREF, float);  ///< 如果是转为32位时，非透明像素，最后一个字节用FF代替
	void InitBitmapControlFromFile(LPCTSTR,int,int,COLORREF,float);		             ///< 从文件导入数据
	
	void LoadBitmapFromBuffer(GILBERT_IMG_OBJ*);								///< 未初始化，用当前环境显示
	void OutSideProcessDc(ProcessImageFromDc);							       ///< 回调函数，用来处理外部绘制要求
	
public: ///< 几何图形操作
	CShapeTabel_Interface mShapeContour;
	BOOL Draw_Mark_Contour(CDC* pDC, vector<CDBPOINT>&inPoint, COLORREF inColor = RGB(0, 250, 0));
	BOOL Draw_Mark_Points(CDC*pDC, vector<CDBPOINT>&inPoint, COLORREF inColor = RGB(0, 250, 0));
	int drawType;
};

#endif


