#if !defined(AFX_DISPLAYCONTROL_DEFINE_20121220__INCLUDE)
#define AFX_DISPLAYCONTROL_DEFINE_20121220__INCLUDE
#ifdef displayControl_DEF
#define displayControl_PORT __declspec(dllexport)
#else
#define displayControl_PORT __declspec(dllimport)
#endif

#ifdef displayControl_CCS
#define displayControl_API extern "C" __declspec(dllexport)
#else
#define displayControl_API extern "C" __declspec(dllimport)
#endif

#endif