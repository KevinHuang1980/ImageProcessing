
// ImageDemoDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ImageDemo.h"
#include "ImageDemoDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CImageDemoDlg 对话框




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


// CImageDemoDlg 消息处理程序

BOOL CImageDemoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	OnInitPic();

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CImageDemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
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
	///< 默认从硬盘读入图片
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