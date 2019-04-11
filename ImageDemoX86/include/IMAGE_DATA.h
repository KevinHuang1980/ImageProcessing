#pragma once

#include<atltypes.h>
#include<afxwin.h>

#if !defined(AFX_IMAGE_DATA_20120924__INCLUDE)
#define AFX_IMAGE_DATA_20120924__INCLUDE

#define IPL_DEPTH_1U     1  
#define IPL_DEPTH_8U     8  
#define IPL_DEPTH_16U   16	
#define IPL_DEPTH_24U	24	
#define IPL_DEPTH_32U   32	


//
typedef struct BMP_DEFINE
{
public:
	BMP_DEFINE()
	{
		m_nBufSize = 0;
		m_imgType = 0;
		m_nImgHeight = 0;
		m_nImgWidthBytes = 0;
		m_nImgWidth = 0;
		m_nHorzResolution = 0;
		m_nVertResolution = 0;
		m_pImgBuf = NULL;
	}
public:
	int			m_nBufSize;			
	int			m_imgType;			
	int			m_nImgHeight;		
	int			m_nImgWidthBytes; 
	int			m_nImgWidth;		
	int			m_nHorzResolution;
	int			m_nVertResolution;
	char*		m_pImgBuf; 

}GILBERT_IMG_OBJ;

typedef void (*ProcessImageFromDc)(CDC*);

enum READ_MODULE_VERSION_STATUS
{
	RMV_OK,                           
	RMV_ERROR_NO_MEMORY,              
	RMV_ERROR_VERSIONS_NOT_COMPATIBLE,
	RMV_ERROR_OTHERS                  
};

struct MODULE_VERSION_NODE
{
	const char *pcVersionString;                        
	const char *pcErrorMsg;                             
	int  nSubModuleNum;                                 
	const MODULE_VERSION_NODE **ppsSubModuleVersionNode;
};

enum RectCorner
{
	LeftTop,
	RightTop,
	RightBottom,
	LeftBottom,
};

enum TunnelType
{
	RTunnel,
	GTunnel,
	BTunnel,
	AllTunnel,
};

enum LoadBmpType
{
	BmpFileType,
	DefinitionType, 
};

struct PointLable
{
	int Figure_id;
	CPoint Figure_point;
};

#endif