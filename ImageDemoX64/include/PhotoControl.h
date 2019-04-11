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

public: ///< ���ⲿ����
	///< void OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);  ///< ��������н�
	///< void OnMouseMove(UINT nFlags, CPoint point);			   ///< �ƶ����
	///< void OnLButtonDown(UINT nFlags, CPoint point);			   ///< ���ѹ��
	///< void OnRButtonDown(UINT nFlags, CPoint point);			   ///< �Ҽ�ѹ��
	///< void OnLButtonUp(UINT nFlags, CPoint point);			   ///< ������� 
	///< void OnSize(UINT nType, int cx, int cy);				   ///< �ƶ���С
	///< void LButtonDblClk(UINT nFlags, CPoint point);			   ///< ���˫��

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
	

public: ///< ͼƬ��Դ��Դ
	BOOL bImageBufferInit;
	CString ImagePath;

	void InitBitmapControlFromBuffer(GILBERT_IMG_OBJ*, int, int, COLORREF, float);  ///< �����תΪ32λʱ����͸�����أ����һ���ֽ���FF����
	void InitBitmapControlFromFile(LPCTSTR,int,int,COLORREF,float);		             ///< ���ļ���������
	
	void LoadBitmapFromBuffer(GILBERT_IMG_OBJ*);								///< δ��ʼ�����õ�ǰ������ʾ
	void OutSideProcessDc(ProcessImageFromDc);							       ///< �ص����������������ⲿ����Ҫ��
	
public: ///< ����ͼ�β���
	CShapeTabel_Interface mShapeContour;
	BOOL Draw_Mark_Contour(CDC* pDC, vector<CDBPOINT>&inPoint, COLORREF inColor = RGB(0, 250, 0));
	BOOL Draw_Mark_Points(CDC*pDC, vector<CDBPOINT>&inPoint, COLORREF inColor = RGB(0, 250, 0));
	int drawType;
};

#endif


