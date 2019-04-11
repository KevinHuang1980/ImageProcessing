#if !defined(AFX_ALGORITHM_DEFINE_20121220__INCLUDE)
#define AFX_ALGORITHM_DEFINE_20121220__INCLUDE

#ifdef algorithm_DEF
#define algorithm_PORT __declspec(dllexport)
#else
#define algorithm_PORT __declspec(dllimport)
#endif

#ifdef algorithm_CCS
#define algorithm_API extern "C" __declspec(dllexport)
#else
#define algorithm_API extern "C" __declspec(dllimport)
#endif

#endif