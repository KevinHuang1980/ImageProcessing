
// ImageDemoDlg.h : ͷ�ļ�
//

#pragma once

#include "PhotoControl.h"
#include "afxwin.h"


// CImageDemoDlg �Ի���
class CImageDemoDlg : public CDialogEx
{
// ����
public:
	CImageDemoDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_IMAGEDEMO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

public:
	BOOL binPic;
	GILBERT_IMG_OBJ tinPic;
	CDC *picDC;
	CRect m_Rect;
	CPhotoControl m_showPic;
// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedExit();
	BOOL OnInitPic();
	BOOL OnClearPic();

};
