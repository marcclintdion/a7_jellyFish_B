GLuint          fbo,
                color,
                depth,
                mainLightPass_fboId,
                mainLightPass_depth,
                textureID,
                fboId_3D,
                fboId,
                componentShaderPass_fbo,
                componentShaderPass_color,
                componentShaderPass_depth,
                flatten_3D_SHADOW_fboId,
                flatten_3D_SHADOW_TEXTURE,
                framebuffer,
                colorRenderbuffer,
                depthRenderbuffer;

//---------------------------------------------------------------------------------------

var           fieldOfView                                      =     30.0;

//---------------------------------------------------------------------------------------
GLsizei       resize_SHADOW_FBO = 1;
GLsizei       resize_LIGHTS_FBO = 4;

var           adjustNearFar[]                                  =  {  0.1, 250.0 };

//---------------------------------------------------------------------------------------
var           moveSet[]                                        =  {  0.0, 0, 1.0, 1.0};
//---------------------------------------------------------------------------------------
var           eyepositionCamera[]                              =  {  0, 0.0, 0.0, 0.0};
//---------------------------------------------------------------------------------------
var           eyeStartPosition[]                               =  {0, 5.95, 22.6999, 0.0};

var           eyeposition[]      =  {0, 1.6, 10.2499, 0.0};
var           lookAt[]        =  {0, -11.95, -49.5502, 0.0};
var           rotateModelWithLeftMouse[]       =  {15.3, 18.9};
//---------------------------------------------------------------------------------------
var           turnTable                                        =     0.0;
var           scaleTurnTable                                   =     1.0;//=     0.01178;
//---------------------------------------------------------------------------------------
var           upVector[]             	                       =  {  0.0, 1.0, 0.0};
//---------------------------------------------------------------------------------------
var           moveShadow[]                                     =  {  0.0, 0.0, 0.0};
var           matchColorModelToShadowPosition[]                =  {  0.0, 0.0, 0.0, 0.0};

var           eyeposition_SHADOW[]                             =  {4.75, 3.65, 5.7, 1.0};
var           lookAt_SHADOW[]                                  =  {  0.0, 0.0, 0.0};
var           adjustLookAtMove[]                               =  {  0.0, 0.0, 0.0};


var           shadowsPositionOffset[]	                       =  {  0.5, 0.5, 0.5 };//BIAS_MATRIX
var           scaleShadows                                     =     0.5;//__________//BIAS_MATRIX

var           offset[]                                         =  {  0.0, 0.0, 0.0, 0.0};
var           offset_ShadowShader[]                            =  {  0.0, 0.0, 0.0, 0.0};

var           scaleShadowSize                                  =     1.0;

var           offsetFinalShadow[]                              =  {  0, 0, 0, 0.0}; //_ADJUSTMENT_IN_THE_FINAL_COLOR_SHADER

var           scaleMoveShadows[]	                           =  {  1.0, 1.0, 1.0, 0.0};//=  {0.971, 0.937001, 1.043, 0.0};
//============================================================================================================================


GLuint        fboId_2D;
GLuint        shadowMap_TEXTURE;
#include    "_SHADERS/SHADOWS/shadows_32bit_Stride_SHADER_GLOBALS.cpp"
#include    "_SHADERS/SHADOWS/shadows_44bit_Stride_SHADER_GLOBALS.cpp"
//===========================================================================================
#include    "_SHADERS/SHADOWS/flatten_3D_shadow_SHADER_GLOBALS.cpp"
//===========================================================================================
GLfloat      frameBufferPlane_SCALE[]                                                    =  { 1.84778, 1.0,  1.0, 1.0};
#include    "_MODEL_FOLDERS_/frameBufferPlane/frameBufferPlane_Globals.cpp"
//===============================================================================================================================
GLuint       UNIFORM_screenRatio_frameBufferPlane_GaussianVertical;
GLfloat      screenRatio;
//------------------------------------------
GLuint       gaussianBlurHorizontal_TEXTURE, gaussianBlurVertical_TEXTURE, mainLightPass_TEXTURE, geometryLightPass_TEXTURE;
GLfloat      frameBufferPlane_GaussianHorizontal_blurRadius                              =   0.00530001;
GLfloat      frameBufferPlane_GaussianVertical_blurRadius                                =   0.00530001;
#include    "_MODEL_FOLDERS_/frameBufferPlane/gaussianBlur_GLOBALS.cpp"
//============================================================================================================================================
                          
                               //#######################################___SHADERS___##################################################
                               
                               
                               //====================================================================================
                               #include "_SHADERS/stone/jadeMonkey/jadeMonkey_SHADER_GLOBALS.cpp"
                               //====================================================================================
 
                               //#####################################___MODELS___#######################################################
                               
                               //====================================================================================
                               #include "_MODEL_FOLDERS_/monkey/monkey_Globals.cpp"
                               //====================================================================================







    //=================================================================================
    #include "_MODEL_FOLDERS_/disk106/disk106_GLOBALS.cpp"
    //=================================================================================
    #include "_MODEL_FOLDERS_/tentacles/tentacles_GLOBALS.cpp"
