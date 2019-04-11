#if !defined(AFX_TOOL_DEFINE_20120920__INCLUDE)
#define AFX_TOOL_DEFINE_20120920__INCLUDE

#ifdef toolDefine_DEF
#define tools_PORT __declspec(dllexport)
#else
#define tools_PORT __declspec(dllimport)
#endif

///< 

#ifdef toolDefine_CCS
#define tools_API extern "C" __declspec(dllexport)
#else
#define tools_API extern "C" __declspec(dllimport)
#endif

#endif