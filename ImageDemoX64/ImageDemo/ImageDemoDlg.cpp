
// ImageDemoDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ImageDemo.h"
#include "ImageDemoDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CImageDemoDlg �Ի���




CImageDemoDlg::CImageDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CImageDemoDlg::IDD, pParent)
	,binPic(FALSE)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CImageDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_IMAGE_SHOW, m_showPic);
}

BEGIN_MESSAGE_MAP(CImageDemoDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_EXIT, &CImageDemoDlg::OnBnClickedExit)
END_MESSAGE_MAP()


// CImageDemoDlg ��Ϣ�������

BOOL CImageDemoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	OnInitPic();

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CImageDemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CImageDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CImageDemoDlg::OnBnClickedExit()
{
	CDialog::OnOK();
}


BOOL CImageDemoDlg::OnInitPic()
{
	try
	{
		GetDlgItem(IDC_IMAGE_SHOW)->GetWindowRect(&m_Rect);
		ScreenToClient(&m_Rect);
		
		m_showPic.drawType = 1;
		CString IO_PATH = _T("");
		wchar_t str[MAX_PATH], drive[MAX_PATH], dir[_MAX_DIR], fname[_MAX_FNAME], ext[_MAX_EXT];
		wchar_t str_Current_Path[MAX_PATH];
		GetModuleFileName(NULL, str, sizeof(str));
		_wsplitpath(str, drive, dir, fname, ext);
		wcscat(drive, dir);
		wcscpy(str_Current_Path, drive);
		IO_PATH.Format(_T("%s"), str_Current_Path);
		IO_PATH += _T("demo.bmp");
		m_showPic.InitBitmapControlFromFile(IO_PATH, m_Rect.left, m_Rect.top, RGB(0, 0, 255), 0);
	///< Ĭ�ϴ�Ӳ�̶���ͼƬ
	}
	catch(...)
	{
		return FALSE;
	}
	return TRUE;
}

BOOL CImageDemoDlg::OnClearPic()
{
	try
	{
		if(binPic)
		{
			if((tinPic.m_nImgHeight !=0) && (tinPic.m_nImgWidth !=0) &&(tinPic.m_pImgBuf != NULL))
			{
				delete[]tinPic.m_pImgBuf; 
			}
		}

	}
	catch(...)
	{
		return FALSE;
	}
	return TRUE;
}