## Copyright

This library is compiled by KevinHuang、KevinTang etc. Because it involves company documents, it only provides the use of lib.

## introduction

            GNU LIB - imageProcess implementation library

This library provides an imageProcess implementation, for use on sImage processing UI.

It provides the following helps:

一、Provide the original image data display function，There are two ways of operation:

  1, through the function Initbitmapcontrolfrombuffer to assign value to Lib image directly.
  
  2, Open the original image directly by lib through the function Initbitmapcontrolfromfile.
  
  To use Initbitmapcontrolfrombuffer, you need to indicate the image data pointer, display the window position and 
  
  background color; to use Initbitmapcontrolfromfile, you need to specify the path to read the file, and others are 
  
  the same as above. In fact, both methods are the same, and lib will keep the image information.
  

二、Provides the display of points and lines:

  1, Draw_Mark_Points is used to draw points, color points and CDC points.
   
  2, Draw_Mark_Contour is used to draw outline, provide display CDC, corner set, brush color.
   
  
三、Provide simple drawing operation:

  Simple graphics can be drawn by interaction with lib through message CONTROLOPERATE_INFO、CONTROLACTIVE_INFO etc.
  
四、Provide simple operation menu

   The original plan is to configure the menu that is not understood by different users. There are other things 
   
   behind it that are not perfect.
  
  
introduction
---------

contact information
--------------

Name： KevinHuang 

e-mail address: <KevinHuang1998@126.com>