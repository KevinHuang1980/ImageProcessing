#pragma once
#include "PATH_DEFINE.h"

#include <afxtempl.h>
#include <string>
#include <algorithm>
using namespace std;

////<  

class path_PORT CPATH_LIBRARY
{
public:

	CPATH_LIBRARY();
	~CPATH_LIBRARY();


public:
	static BOOL API_CREATE_WFOLDER(const char* szDirPath);
	static BOOL API_CREATE_TFOLDER(LPCTSTR szDirPath);    
		 
	static BOOL API_DELETE_WFOLDER(const char* szDirPath); 
	static BOOL API_DELETE_TFOLDER(LPCTSTR szDirPath);     
	static BOOL API_DELETE_DIRECTORY(CString strDir);      

	static int API_GET_CURRENT_WPATH(char* szDirPath);   
	static int API_GET_CURRENT_WPATH(wchar_t* szDirPath);
	static int API_GET_CURRENT_TPATH(LPTSTR szDirPath);  
	static int API_RELATIVE_WABSOLUTE(const char* FileName, char *szDirPath);
	static int API_RELATIVE_TABSOLUTE(LPCTSTR FileName, LPTSTR szDirPath);   

	static BOOL API_CREATE_WFILE(const char* szDirPath); 
	static BOOL API_CREATE_TFILE(LPCTSTR szDirPath);     
	static BOOL API_DELETE_WFILE(const char* szDirPath); 
	static BOOL API_DELETE_TFILE(LPCTSTR szFileName);    

	static BOOL API_GET_FILE_WEXIST(const char* szFileName); 
	static BOOL API_GET_FILE_TEXIST(LPCTSTR szFileName);     		 
	static BOOL API_GET_PATH_FILE(CString in_str, CString& out_path, CString& out_file);  


	static BOOL   API_SET_WINDOWDOUBLE(CWnd *pWnd, double lfValue, CString strFormat = _T("%.3lf"));
	static double API_GET_WINDOWDOUBLE(CWnd *pWnd);

	static BOOL   API_SET_WINDOWINT(CWnd *pWnd, int lfValue);
	static int    API_GET_WINDOWINT(CWnd *pWnd);

	static string  API_WS2AS(const wstring& ws, unsigned int nACP);
	static string  API_UNICODE2UTF8(const wstring& ws);

};

