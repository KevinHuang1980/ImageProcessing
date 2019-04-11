#if !defined(AFX_DISPLAYFUNCTION_DEFINE_2021223__INCLUDE)
#define AFX_DISPLAYFUNCTION_DEFINE_2021223__INCLUDE
#ifdef displayFunction_DEF
#define displayFunction_PORT __declspec(dllexport)
#else
#define displayFunction_PORT __declspec(dllimport)
#endif

#ifdef displayFunction_CCS
#define displayFunction_API extern "C" __declspec(dllexport)
#else
#define displayFunction_API extern "C" __declspec(dllimport)
#endif

#endif