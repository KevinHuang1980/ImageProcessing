#pragma once

///< #include<atltypes.h>
///< #include<afxwin.h>
#if !defined(AFX_Control_Operate_20121223__INCLUDE)
#define AFX_Control_Operate_20121223__INCLUDE

enum Conntrol_State
{
	enControl_Idle = 0, 
	enControl_Move,     
	enControl_Lock,     
	enControl_Num,      
};

enum Draw_State
{
	enDraw_Idle = 0,
	enDraw_Circle,
	enDraw_Rect2,
	enDraw_LineContour,
	enDraw_CircleContour,
	enDraw_CircleMask,
	enDraw_RectMask,	
	enDraw_CircleSearch,
	enDraw_RectSearch,
	enDraw_ModifyShape,
	enDraw_ModifyContour,
	enDraw_ModifyMask,
	enDraw_ModifySearch,
	enDraw_ActiveShape,
	enDraw_ActiveContour,
	enDraw_ActiveMask,
	enDraw_ActiveSearch,
	enDraw_Num,
};

enum Draw_Operate
{
	enOperate_Idle = 0,
	enOperate_AddCricle,
	enOperate_AddRect,
	enOperate_AddSearchCircle,
	enOperate_AddSearchRect,
	enOperate_AddMaskCircle,
	enOperate_AddMaskRect,
	enOperate_AddContourLine,
	enOperate_AddContourCircl,
	enOperate_RectifyCricle,
	enOperate_RectifyRect,
	enOperate_RectifySearchCircle,
	enOperate_RectifySearchRect,
	enOperate_RectifyMaskCircle,
	enOperate_RectifyMaskRect,
	enOperate_RectifyContourLine,
	enOperate_RectifyContourCircl,
	enOperate_DeleteCricle,
	enOperate_DeleteRect,
	enOperate_DeleteSearchCircle,
	enOperate_DeleteSearchRect,
	enOperate_DeleteMaskCircle,
	enOperate_DeleteMaskRect,
	enOperate_DeleteContourLine,
	enOperate_DeleteContourCircl,
	enOperate_Num,	
};

typedef struct Operate_Value
{
public:
	Operate_Value()
	{
	  inType = inKey = 0;
	}
public:
  int inType; ///< ÀàÐÍ
  int inKey;  ///< Ë÷Òý
}opValue,*popValue;

#endif