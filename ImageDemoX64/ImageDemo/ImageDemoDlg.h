
// ImageDemoDlg.h : 头文件
//

#pragma once

#include "PhotoControl.h"
#include "afxwin.h"


// CImageDemoDlg 对话框
class CImageDemoDlg : public CDialogEx
{
// 构造
public:
	CImageDemoDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_IMAGEDEMO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

public:
	BOOL binPic;
	GILBERT_IMG_OBJ tinPic;
	CDC *picDC;
	CRect m_Rect;
	CPhotoControl m_showPic;
// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedExit();
	BOOL OnInitPic();
	BOOL OnClearPic();

};
