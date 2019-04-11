#if !defined(AFX_EDIT_DEFINE_20121101__INCLUDE)
#define AFX_EDIT_DEFINE_20121101__INCLUDE

#ifdef edit_DEF
#define edit_PORT __declspec(dllexport)
#else
#define edit_PORT __declspec(dllimport)
#endif

#ifdef edit_CCS
#define edit_API extern "C" __declspec(dllexport)
#else
#define edit_API extern "C" __declspec(dllimport)
#endif

#endif