#if !defined(AFX_SHAPE_DEFINE_20130920__INCLUDE)
#define AFX_SHAPE_DEFINE_20130920__INCLUDE

#ifdef shapeDefine_DEF
#define shapesPort __declspec(dllexport)
#else
#define shapesPort __declspec(dllimport)
#endif

#ifdef shapeDefine_CCS
#define shapesAPI extern "C" __declspec(dllexport)
#else
#define shapesAPI extern "C" __declspec(dllimport)
#endif

#endif