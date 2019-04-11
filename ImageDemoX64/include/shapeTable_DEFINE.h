#if !defined(AFX_SHAPETABLE_DEFINE_20120923__INCLUDE)
#define AFX_SHAPETABLE_DEFINE_20120923__INCLUDE

#ifdef shapeTable_DEF
#define shapeTable_PORT __declspec(dllexport)
#else
#define shapeTable_PORT __declspec(dllimport)
#endif

#ifdef shapeTable_CCS
#define shapeTable_API extern "C" __declspec(dllexport)
#else
#define shapeTable_API extern "C" __declspec(dllimport)
#endif

#endif