#if !defined(AFX_PATH_DEFINE_20121205__INCLUDE)
#define AFX_PATH_DEFINE_20121205__INCLUDE

#ifdef path_DEF
#define path_PORT __declspec(dllexport)
#else
#define path_PORT __declspec(dllimport)
#endif

#ifdef path_CCS
#define path_API extern "C" __declspec(dllexport)
#else
#define path_API extern "C" __declspec(dllimport)
#endif

#endif