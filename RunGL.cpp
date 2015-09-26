#define var GLfloat
//####################################################################################################################

#ifdef WIN32
        #define   glGenerateMipmap       glGenerateMipmapEXT
        #define   glGenFramebuffers      glGenFramebuffersEXT
        #define   glBindFramebuffer      glBindFramebufferEXT
        #define   glFramebufferTexture2D glFramebufferTexture2DEXT
         
        #define   STRICT
        #define   WIN32_LEAN_AND_MEAN
        #include <windows.h>
       // #include <iostream.h>
        #include <fstream.h>
        //using namespace std; //___used for string object

        //-----------------------------------------------------------------------------

        #include <GL/gl.h>
        #include <GL/glu.h>
        #include "headerFiles/glext.h"
        #include "headerFiles/glext_Init_A.cpp"


        
        void InitGL(void);
        void RenderGL(void);
        void KillALData(void);
        void ProcessKeyboard(void);
                
        var  viewWidth;
        var  viewHeight;
        
        //----------------------------------------------------------------------
        GLfloat  PassMouseMovement[2];

        //-------------------------------
        bool keys[256], keypressed[256];
        bool mkeyIsReset = true;
        
        #include "cpp/WGL_ARB_multisample.h"
        //-------------------------------

        #include "headerFiles/VSync.h"
        
        #include <windows.h>
/*
typedef struct 
{
	GLubyte r, g, b;
} pixel;


//the global structure
typedef struct 
{
	pixel *data;
	int w, h;
} glob;
glob global;      
 */


        void      ConfigureAndLoadTexture(GLubyte *textureData, GLint texWidth, GLint texHeight );
        #include "headerFiles/glaux.h"
        #include "headerFiles/FreeImage.h"
        #include "cpp/freeImage.cpp"
        //------------------------------------------


#endif

//####################################################################################################################

        GLfloat  PassTouchMovement[3];

//####################################################################################################################

bool sound_API_selector = 1;//_0_is_openAL_/_1_is_fMod

//=========================================================
GLfloat frequency[512];
GLfloat audioRotation[] = {1.0, 0.0, 1.0, 0.0};
GLfloat directionSoundTravels = 1.0;
GLuint  selectFrequency = 4;
//----------------------------------------------
#ifdef __APPLE__
        
        
        #include "AUDIO/openAL_iOS/openAL_iOS_GLOBALS.cpp"
        //-----------------------------------------------
//        #import "fmod.hpp"
//        #import "fmod_errors.h"
        GLfloat frequency_fMod_iOS[64];

//        #include "AUDIO/fMod_iOS/fMod_iOS_GLOBALS.cpp" //_____found_in_EAGLView

        

#endif
//=========================================================
#ifdef WIN32
        
        #include "AUDIO/openAL_WIN/openAL_WIN_GLOBALS.cpp"
        //-----------------------------------------------
        #include "AUDIO/fMod_WIN/fMod_WIN_GLOBALS.cpp"
        int        playing  = 0;
        int       *channel  = 0;
        bool       playOnce = true;
        
#endif
//=========================================================

//####################################################################################################################
GLfloat adjust_w = 1.0;

#include <math.h>
  
//####################################################################################################################

#include "MATRIX_MATH.cpp"

//####################################################################################################################

//--------------------------------------------------------------------------------------------------------------
#define BUFFER_OFFSET(i) ((char *)0 + (i))
//----------------------------------------------------------------------------------------

        extern GLuint msaaFramebuffer;

        void RenderGL(void);
        void InitGL  (void);
        void shutDownGL(void);
      
        #ifdef __APPLE__
               var viewWidth;
               var viewHeight;
               GLuint  viewFramebuffer;
        #endif
          
        //-------------------------------------------------------------------------------


        GLuint m_uiShadowMapTexture;
        GLuint m_uiFrameBufferObject;



//#########################################################################################################


void ConfigureAndLoadTexture(GLubyte *textureData, GLint texWidth, GLint texHeight )
{

        #ifdef __APPLE__
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        //glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_NEAREST);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texWidth, texHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, textureData);
        glGenerateMipmap(GL_TEXTURE_2D);
        #endif
        
        #ifdef WIN32
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri( GL_TEXTURE_2D, GL_GENERATE_MIPMAP_SGIS, GL_TRUE );
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texWidth, texHeight, 0, GL_BGRA, GL_UNSIGNED_BYTE, textureData);
        #endif
}

//===============================================================================================================================


var     modelView[16];
var     projection[16];
var     mvpMatrix[16];
var     mvpMatrixInverse[16];
var     lightMatrix[16];
var     moveSetMatrix[16];
var     ProjectionShadow[16];
var     modelViewShadow[16];
var     viewMatrix[16];

var     LightModelViewMatrix[16];


float   modelWorld[16];
float   LightView[16];
float   LightProjection[16];
float   modelViewInverse[16];

float   tempMatrix[16];

var     textureMatrix[16] = {   0.5f, 0.0f, 0.0f, 0.0f,
                                0.0f, 0.5f, 0.0f, 0.0f,
                                0.0f, 0.0f, 0.5f, 0.0f,
                                0.5f, 0.5f, 0.5f, 1.0f   };

var     inverseMatrix[16];


//============================================================================================================================

var     moveShadowPivot_Z = 0.0;


#include "GLOBALS.cpp"

   
//============================================================================================================================

void setupTransforms_MainColor(void)
{
        
        LoadIdentity(modelView);
        
        LookAt(modelView,    eyeposition[0],
                             eyeposition[1],
                             eyeposition[2],
                             lookAt[0],
                             lookAt[1],
                             lookAt[2],
                             upVector[0],
                             upVector[1],
                             upVector[2]);
        
        Rotate(modelView, 0.0, 1.0, 0.0, turnTable);
        Rotate(modelView, 1.0, 0.0, 0.0, audioRotation[3]);        
        //--------------------------------------------------------------------------------------
        LoadIdentity(viewMatrix);
        AssignMatrix(viewMatrix, modelView);
        InvertMatrix(viewMatrix, viewMatrix);
        //--------------------------------------------------------------------------------------
        Translate(modelView, moveSet[0] , moveSet[1] , moveSet[2] );
        Rotate(modelView, 1.0, 0.0, 0.0, rotateModelWithLeftMouse[0]);
        Rotate(modelView, 0.0, 1.0, 0.0, rotateModelWithLeftMouse[1]);
       
        Rotate(modelView, 0.0, 0.0, 1.0, turnTable);

}

//============================================================================================================================


void setupTransforms_Shadows(void)
{
     
        
        
        LoadIdentity(LightModelViewMatrix);
        LookAt(LightModelViewMatrix,  eyeposition[0] + eyeposition_SHADOW[0] - eyeposition[0] * adjustLookAtMove[0],
                                      eyeposition[1] + eyeposition_SHADOW[1] - eyeposition[1] * adjustLookAtMove[1],
                                      eyeposition[2] + eyeposition_SHADOW[2] - eyeposition[2] * adjustLookAtMove[2],
                                      lookAt[0]      + lookAt_SHADOW[0],
                                      lookAt[1]      + lookAt_SHADOW[1],
                                      lookAt[2]      + lookAt_SHADOW[2],
                                      upVector[0],
                                      upVector[1],
                                      upVector[2]);

        Rotate(LightModelViewMatrix, 0.0, 1.0, 0.0, turnTable);
        Rotate(modelView, 1.0, 0.0, 0.0, audioRotation[3]);     
        //--------------------------------------------------------------------------------------
        AssignMatrix(modelViewShadow, LightModelViewMatrix);
        //--------------------------------------------------------------------------------------
        Translate(LightModelViewMatrix, moveSet[0] + moveShadow[0] , moveSet[1] + moveShadow[1] , moveSet[2] + moveShadow[2]);
        Rotate(LightModelViewMatrix, 1.0, 0.0, 0.0, rotateModelWithLeftMouse[0]);
        Rotate(LightModelViewMatrix, 0.0, 1.0, 0.0, rotateModelWithLeftMouse[1]);

}
//############################################################################################################################
//############################################################################################################################
//############################################################################################################################

var shaderNumber = 0;

void SelectShader(var shaderNumber)
{
        
        //--------------------------------------------------------------------------------------
        if(shaderNumber == 26)
        {
                #include "_SHADERS/stone/jadeMonkey/jadeMonkey_SHADER_RENDER.cpp"
        }
        //--------------------------------------------------------------------------------------


}

//################################################################################################################################
//################################################################################################################################
//################################################################################################################################



void InitGL( void )//__BEGIN_INIT__@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
{
        //==========================================================================
        #ifdef WIN32
            #include "cpp/setPixelFormat.cpp"
            #include "headerFiles/glext_Init_B.cpp"
            alutInit(NULL, 0);
            //-------------------------------------
            SetVSyncState(true);
            //-------------------------------------
            PassMouseMovement[0]        = rotateModelWithLeftMouse[0];
            PassMouseMovement[1]        = rotateModelWithLeftMouse[1];
        

        //=================
        #endif
                   
//################################################################################################################################
/*
        #ifdef __APPLE__
        
                if(sound_API_selector == 0)
                {
                        #include "AUDIO/openAL_iOS/openAL_iOS_Init.cpp"
                }        
                if(sound_API_selector == 1)
                {        
                        //#include "AUDIO/fMod_iOS/fMod_iOS_Init.cpp" //_____found_in_EAGLView
                }
        
        #endif
        //=========================================================
        #ifdef WIN32
                
                if(sound_API_selector == 0)
                {
                        #include "AUDIO/openAL_WIN/openAL_WIN_Init.cpp"
                }
                
                if(sound_API_selector == 1)
                {    
                        #include "AUDIO/fMod_WIN/fMod_WIN_Init.cpp"
                }
        
        #endif
*/
//###########################################################################################################################################
         
#ifdef WIN32        
        //===================================================================================================
        glGenTextures(1, &m_uiShadowMapTexture);
	    glBindTexture(GL_TEXTURE_2D, m_uiShadowMapTexture);
        //-------------------------------------------------
        glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, (GLsizei)viewWidth, (GLsizei)viewHeight, 0, GL_DEPTH_COMPONENT,  GL_UNSIGNED_INT,  NULL);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        //------------------------------------------------------------------
	    glGenFramebuffers(1, &m_uiFrameBufferObject);
	    glBindFramebuffer(GL_FRAMEBUFFER, m_uiFrameBufferObject);
        //---------------------
        glDrawBuffer(GL_NONE);//_ON_SOME_MACHINES_THIS_IS_REQUIRED / ON_SOME_IT_FAILS
        glReadBuffer(GL_NONE);//_SAME_AS_ABOVE
	    //---------------------
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, m_uiShadowMapTexture, 0);     
        glBindFramebuffer(GL_FRAMEBUFFER, 0);        
        //====================================================================================================
#endif
        
//==================================================================================================================================================        

#ifdef __APPLE__
        //====================================================================================================
        glGenTextures(1, &m_uiShadowMapTexture);
	    glBindTexture(GL_TEXTURE_2D, m_uiShadowMapTexture);
        //-------------------------------------------------
	    glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, 2000, 1000, 0, GL_DEPTH_COMPONENT, GL_UNSIGNED_INT, 0);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        //------------------------------------------------------------------
	    glGenFramebuffers(1, &m_uiFrameBufferObject);
	    glBindFramebuffer(GL_FRAMEBUFFER, m_uiFrameBufferObject);
        //---------------------
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, m_uiShadowMapTexture, 0);     
        glBindFramebuffer(GL_FRAMEBUFFER, 0);        
        //====================================================================================================
 #endif

//###########################################################################################################################################        



#include "INITIALIZE.cpp"

        
//====================================================================================================================================
    
#ifdef WIN32   
        atexit(KillALData);//__tell_openAL_to_run_KillALData_function_at_shutdown 
#endif    
        
        glEnable(GL_DEPTH_TEST);
    //glDepthFunc(GL_LEQUAL);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    //glAlphaFunc(GL_GREATER, 0.1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
        
//====================================================================================================================================

    



}//__END_INIT__@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@



//#####################################################################################################################################
//#####################################################################################################################################
//#####################################################################################################################################
//#####################################################################################################################################


void RenderGL(void)
{
        #ifdef __APPLE__  
        if(directionSoundTravels > 0.0)
        {
               // audioRotation[3] += (GLfloat)(frequency_fMod_iOS[60]*200.0);       
        }
        
        if(directionSoundTravels < 0.0)
        {
              //  audioRotation[3] -= (GLfloat)(frequency_fMod_iOS[60]*200.0);       
        }              
        #endif
       
        #ifdef WIN32  
               
               if(directionSoundTravels > 0.0)
               {
                       
                    //   audioRotation[3] += frequency[selectFrequency]*.1;       
               
               }
        
               if(directionSoundTravels < 0.0)
               {
                       
                  //     audioRotation[3] -= frequency[selectFrequency]*.1;       
               
               }              
        
        #endif        
        
        
//####################################################################################################

#ifdef __APPLE__
        
        if(sound_API_selector == 0)
        {
               // #include "AUDIO/openAL_iOS/openAL_iOS_Render.cpp"
        }        
        if(sound_API_selector == 1)
        {        
               // #include "AUDIO/fMod_iOS/fMod_iOS_Render.cpp"
        }
        
#endif
        //=========================================================
#ifdef WIN32
        
        if(sound_API_selector == 0)
        {
              //  #include "AUDIO/openAL_WIN/openAL_WIN_Render.cpp"
        }
        
        if(sound_API_selector == 1)
        {    
              //  #include "AUDIO/fMod_WIN/fMod_WIN_Render.cpp"
                
        }
        
        
        
        
#endif       
//#################################################################
        
        
        
        
        
                        #ifdef __APPLE__   
                        //***************************************************************
                        //eyeposition[0] -= PassTouchMovement[0];
                        //eyeposition[1] -= PassTouchMovement[1];
                        //eyeposition[2] -= PassTouchMovement[2];                   
                        
                        //PassTouchMovement[0] = 0.0;
                        //PassTouchMovement[1] = 0.0;
                        //PassTouchMovement[2] = 0.0;
                //***************************************************************
                        #endif               
        
                        #ifdef WIN32  
                        //***************************************************************
                        rotateModelWithLeftMouse[0] = PassMouseMovement[0];
                        rotateModelWithLeftMouse[1] = PassMouseMovement[1];
                        //***************************************************************
                        #endif            
           
        
//turnTable += 0.1;


//====================================================================================================================================
///////////////________FRAMEBUFFER_SHADOWS_BEGINS_HERE______________FRAMEBUFFER_SHADOWS_BEGINS_HERE___________________________________
///////////////________FRAMEBUFFER_SHADOWS_BEGINS_HERE______________FRAMEBUFFER_SHADOWS_BEGINS_HERE___________________________________
//====================================================================================================================================
        #include "runDepth_FBO.cpp"
//====================================================================================================================================
///////////////________FRAMEBUFFER_SHADOWS_BEGINS_HERE______________FRAMEBUFFER_SHADOWS_BEGINS_HERE___________________________________
///////////////________FRAMEBUFFER_SHADOWS_BEGINS_HERE______________FRAMEBUFFER_SHADOWS_BEGINS_HERE___________________________________
//====================================================================================================================================
//=============
//====================================================================================================================================
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//====================================================================================================================================    
        //glActiveTexture (GL_TEXTURE0);
        //glBindTexture(GL_TEXTURE_2D, shadowMap_TEXTURE);  
        //#include "flatten_3D_RENDER.cpp"
//====================================================================================================================================
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//====================================================================================================================================
//=============
//====================================================================================================================================
//************************************************************************************************************************************
//************************************************************************************************************************************
//====================================================================================================================================
        //#include "_MODEL_FOLDERS_/lightSpheres/lightSpheres_Render.cpp"
        //*****************************************************************
        //#include "_MODEL_FOLDERS_/lightSpheres/blurLightSpheres_Render.cpp"
//====================================================================================================================================
//************************************************************************************************************************************
//************************************************************************************************************************************
//====================================================================================================================================
//=============
//====================================================================================================================================
//####################################################################################################################################
//####################################################################################################################################
//====================================================================================================================================
#ifdef __APPLE__
        glBindFramebuffer(GL_FRAMEBUFFER, msaaFramebuffer);
#endif       
        //=====================================================================   

        #include "drawMainColor_FBO.cpp"
        
        //------------------------------------------
//glBindFramebuffer(GL_FRAMEBUFFER, 0);
        //------------------------------------------     
//====================================================================================================================================
//####################################################################################################################################
//####################################################################################################################################
//====================================================================================================================================
//=============
//====================================================================================================================================
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//====================================================================================================================================
/*
        glActiveTexture (GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, m_uiShadowMapTexture);
        glActiveTexture (GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, m_uiShadowMapTexture);//facing_UP_TEXTUREMAP
        #include "_MODEL_FOLDERS_/frameBufferPlane/frameBufferPlane_Render.cpp"
*/
 //====================================================================================================================================
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//====================================================================================================================================

        
      
        
        
        
}//_END_RenderGL()


//####################################################################################################################################
//####################################################################################################################################
//####################################################################################################################################
//####################################################################################################################################

#ifdef WIN32
void ProcessKeyboard(void)
{

    //=======================================================================================





   //=======================================================================================
    if (keys['L'])
    {
             jadeMonkey_LIGHT_POSITION_01[0]         +=  .1;
    }
    if (keys['J'])
    {
             jadeMonkey_LIGHT_POSITION_01[0]         -=  .1;
    }    
    if (keys['I'])
    {
             jadeMonkey_LIGHT_POSITION_01[1]         += .1;
    } 
    if (keys['K'])
    {
             jadeMonkey_LIGHT_POSITION_01[1]         -=  .1;
    }
    if (keys['O'])
    {
             jadeMonkey_LIGHT_POSITION_01[2]         +=  .1;
    }
    if (keys['U'])  
    {
             jadeMonkey_LIGHT_POSITION_01[2]         -=  .1;
    }
    //--------------------------------------------------------------------------
    if (keys['X'])
    {
             jadeMonkey_minAdjust                       +=  0.01;
    }
    if (keys['Z'])
    {
             jadeMonkey_minAdjust                       -=  0.01;
    }
    //==================================================================================================================================
    if (keys['C'])
    {
             jadeMonkey_powAdjust                       +=  0.01;
    }
    if (keys['V'])
    {
             jadeMonkey_powAdjust                       -=  0.01;
    }
    //==================================================================================================================================
    if (keys['N'])
    {
             jadeMonkey_divisorAdjust                       +=  0.01;
    }
    if (keys['M'])
    {
             jadeMonkey_divisorAdjust                       -=  0.01;
    }
    //==================================================================================================================================

 
 
 
 
 
  
    if(keys[VK_F8])
    {
         ofstream outSettings("settings.cpp");
             
         //------------------------------------------------------------------------------------------------------------------------------
         outSettings << "var         jadeMonkey_LIGHT_POSITION_01[]      =  {"   
                                 << jadeMonkey_LIGHT_POSITION_01[0]     << ", "
                                 << jadeMonkey_LIGHT_POSITION_01[1]     << ", "
                                 << jadeMonkey_LIGHT_POSITION_01[2]     << ", "           
                                  
                                 << jadeMonkey_LIGHT_POSITION_01[3]     << "};\n\n";            
         
         
         //------------------------------------------------------------------------------------------------------------------------------

  
         //-------------------------------------------------------------------------------------------------------------------------------
         outSettings << "var         jadeMonkey_powAdjust        =  "    
                                  << jadeMonkey_powAdjust       << ";\n";   
         //------------------------------------------------------------------------------------------------------------------------------
   
         outSettings << "var         jadeMonkey_minAdjust        =  "    
                                  << jadeMonkey_minAdjust       << ";\n";   
         //------------------------------------------------------------------------------------------------------------------------------
          
         outSettings << "var         jadeMonkey_divisorAdjust        =  "    
                                  << jadeMonkey_divisorAdjust       << ";\n";   
         //------------------------------------------------------------------------------------------------------------------------------
                  
       
        // for(int i = 0; i < 512; i++)
        // {
        //          outSettings << "var         frequency[" << i << "] = "     << frequency[i]         << ";\n";
        // }
         
        // outSettings << "var         selectFrequency      =  "    
         //                         << selectFrequency     << ";\n\n";          
         //---------------------------------------------------------------------------------------------------------------------------         
      
         outSettings << "var           eyeposition[]      =  {"   
                                    << eyeposition[0]     << ", "
                                    << eyeposition[1]     << ", "
                                    << eyeposition[2]     << ", 0.0};\n";                
         //------------------------------------------------------------------------------------------------------------------------------
         outSettings << "var           lookAt[]        =  {"   
                                    << lookAt[0]       << ", "
                                    << lookAt[1]       << ", "
                                    << lookAt[2]       << ", 0.0};\n";             
         //------------------------------------------------------------------------------------------------------------------------------
         outSettings << "var           rotateModelWithLeftMouse[]       =  {"   
                                    << rotateModelWithLeftMouse[0]      << ", "
                                    << rotateModelWithLeftMouse[1]      << "};\n\n"; 
         //------------------------------------------------------------------------------------------------------------------------------
         outSettings << "var           eyeposition_SHADOW[]       =  {"   
                                    << eyeposition_SHADOW[0]      << ", "
                                    << eyeposition_SHADOW[1]      << ", "
                                    << eyeposition_SHADOW[2]      << ", 1.0};\n";                
         //------------------------------------------------------------------------------------------------------------------------------
         outSettings << "var           eyeposition_SHADOW[]       =  {"   
                                    << eyeposition_SHADOW[0]      << ", "
                                    << eyeposition_SHADOW[1]      << ", "
                                    << eyeposition_SHADOW[2]      << "}; \n";         
    //----------------------------------------------------------------------------------------------------------------

          GLubyte *pixmap =(GLubyte *)malloc(GLsizei(viewWidth*viewHeight*4));
    
          glReadPixels(0, 0, GLsizei(viewWidth), GLsizei(viewHeight), GL_BGRA,GL_UNSIGNED_BYTE, pixmap);
    
          FIBITMAP *texture = FreeImage_ConvertFromRawBits( pixmap, GLsizei(viewWidth), GLsizei(viewHeight), GLsizei(viewWidth*4), 32, 0xFF0000, 0x00FF00, 0x0000FF, true);    
          FreeImage_Save(FIF_BMP, texture, "AAAAA.bmp", 0);         
        
        free(pixmap); 
      
/*      
// FIBITMAP *bitmapTexture = FreeImage_Allocate(GLsizei(viewWidth), GLsizei(viewHeight), 24);    
// FreeImage_Save(FIF_PNG, bitmapTexture,  "fileName.png", 0);
*/      
/*  BYTE* pixels = new BYTE[ 4 * GLsizei(viewWidth) * GLsizei(viewHeight)];

glReadPixels(0, 0, GLsizei(viewWidth), GLsizei(viewHeight), GL_BGRA, GL_UNSIGNED_BYTE, pixels);

// Convert to FreeImage format & save to file
FIBITMAP* image = FreeImage_ConvertFromRawBits(pixels,  GLsizei(viewWidth), GLsizei(viewHeight), 3 *  GLsizei(viewWidth), 24, 0x0000FF, 0xFF0000, 0x00FF00, false);



FreeImage_Save(FIF_BMP, image, "test.bmp", 0);

// Free resources
FreeImage_Unload(image);
delete [] pixels;    
*/


    }
      
    //====================================================================================================================================
    //====================================================================================================================================
/*   
    if (keys['Y'] && KEY_Y_IS_RESET)
	{      
          GLubyte *pixmap =(GLubyte *)malloc(1920*1080*4);
    
          glReadPixels(0,0,1920,1080,GL_BGRA,GL_UNSIGNED_BYTE,pixmap);
    
          FIBITMAP *texture = FreeImage_ConvertFromRawBits( pixmap, 1920, 1080, 1920*4, 32, 0xFF0000, 0x00FF00, 0x0000FF, true);    
          FreeImage_Save(FIF_BMP, texture, "AAAAA.bmp", 0);         
        
        free(pixmap); 
        
        KEY_Y_IS_RESET = false;
    }  
    //------------------------------------
    if (!keys['Y'])
	{     
         KEY_Y_IS_RESET = true;   
    
    }
*/
    //====================================================================================================================================
    //====================================================================================================================================
  
 

//=======================================================================================
    if (keys['A'] && !keys[VK_SHIFT])
	{
          eyeposition[0] += 0.15;
          lookAt[0]      += 0.15;
    }	
//-----------------------------------     
    if (keys['D'] && !keys[VK_SHIFT])
	{
          eyeposition[0] -= 0.15;
          lookAt[0]      -= 0.15;    
    }
//=================================== 
    if (keys['S'] && !keys[VK_SHIFT])
	{
          eyeposition[1]  += 0.15;
          lookAt[1]       += 0.15;   
    }
//-----------------------------------	
    if (keys['W'] && !keys[VK_SHIFT])
	{
          eyeposition[1]  -= 0.15;       
          lookAt[1]       -= 0.15;    
//-----------------------------------  
    }    
    if (keys['Q'] && !keys[VK_SHIFT])
	{
          eyeposition[2]  += 0.15;      
          lookAt[2]       += 0.15;     
    }
//===================================   
    if (keys['E'] && !keys[VK_SHIFT])
	{
          eyeposition[2]  -= 0.15;
          lookAt[2]       -= 0.15;     
    }
//===================================  	

//=======================================================================================
//=======================================================================================
    if (keys['A'] && keys[VK_SHIFT])
	{
          eyeposition_SHADOW[0]    += 0.01;
    }	
//-----------------------------------     
    if (keys['D'] && keys[VK_SHIFT])
	{ 
          eyeposition_SHADOW[0]    -= 0.01;
    }
//=================================== 
    if (keys['S'] && keys[VK_SHIFT])
	{
          eyeposition_SHADOW[1] += 0.01;
    }
//-----------------------------------
    if (keys['W'] && keys[VK_SHIFT])
	{
          eyeposition_SHADOW[1] -= 0.01;
    }
//===================================
    if (keys['Q'] && keys[VK_SHIFT])
	{
          eyeposition_SHADOW[2] += 0.01;
    }
//-----------------------------------  	
    if (keys['E'] && keys[VK_SHIFT])
	{
          eyeposition_SHADOW[2] -= 0.01;
    }
//=======================================================================================
     
}//_END_ProcessKeyboard()
#endif


//#####################################################################################################################################
//#####################################################################################################################################
//#####################################################################################################################################
//#####################################################################################################################################



void shutDownGL( void )
{
     

//###########################################################################################################################################
        
/*
//#################################################################
        #ifdef __APPLE__
        
        if(sound_API_selector == 0)
        {
                #include "AUDIO/openAL_iOS/openAL_iOS_Shutdown.cpp"
        }        
        if(sound_API_selector == 1)
        {        
                #include "AUDIO/fMod_iOS/fMod_iOS_Shutdown.cpp"
        }
        
        #endif
        //=========================================================
        #ifdef WIN32
        
        if(sound_API_selector == 0)
        {
                #include "AUDIO/openAL_WIN/openAL_WIN_Shutdown.cpp"//____VERIFY_
        }
        
        if(sound_API_selector == 1)
        {    
                #include "AUDIO/fMod_WIN/fMod_WIN_Shutdown.cpp"
        }
        
        #endif       
//#################################################################
*/        

        
       

       //=================================================================================================================
         #include "_SHADERS/stone/jadeMonkey/jadeMonkey_SHADER_SHUTDOWN.cpp"
       //====================================================================================
       //#include "_SHADERS/SHADOWS/shadows_32bit_Stride_SHADER_SHUTDOWN.cpp"
       //#include "_SHADERS/SHADOWS/shadows_44bit_Stride_SHADER_SHUTDOWN.cpp"
       //####################################################################################

        //====================================================================================
        #include "_MODEL_FOLDERS_/monkey/monkey_Shutdown.cpp"      
        //====================================================================================
    
                    


}
//=====================================================================================================================================
//-------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------
//=====================================================================================================================================

#ifdef WIN32
void KillALData()
{
	alDeleteBuffers(1, &Buffer_dungeonWAV);
	alDeleteSources(1, &Source_dungeonWAV);
    alutExit();
}
#endif




