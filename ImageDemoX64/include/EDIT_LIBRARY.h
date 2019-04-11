#pragma once

#include "EDIT_DEFINE.h"
#include<afxwin.h>

// EDIT_LIBRARY
#define EDIT_MESSAGE WM_USER+100

class edit_PORT EDIT_LIBRARY : public CEdit
{
	DECLARE_DYNAMIC(EDIT_LIBRARY)

public:
	EDIT_LIBRARY();
	virtual ~EDIT_LIBRARY();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKillFocus(CWnd* pNewWnd);
};


