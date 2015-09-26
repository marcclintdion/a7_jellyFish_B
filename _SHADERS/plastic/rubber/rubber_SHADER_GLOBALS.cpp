GLfloat     jadeMonkey_LIGHT_POSITION_01[] =  {43.2259, 52.5437, 26.15, 1};
GLfloat     jadeMonkey_LIGHT_POSITION_02[] = {  -30.5,  100, 12.5, 1.0};
GLfloat     jadeMonkey_LIGHT_POSITION_03[] = {  -2.505,  -100,   0.0, 1.0};
GLfloat     jadeMonkey_LIGHT_POSITION_04[] = {  -0.005,   0.5,   5, 1.0};

//----                                                                                                
GLuint      UNIFORM_LIGHT_POSITION_01_jadeMonkey; 
GLuint      UNIFORM_LIGHT_POSITION_02_jadeMonkey;        
GLuint      UNIFORM_LIGHT_POSITION_03_jadeMonkey; 
GLuint      UNIFORM_LIGHT_POSITION_04_jadeMonkey; 

//------------------------------------------------  

GLfloat     jadeMonkey_ATTENUATION         =    0.72;
GLfloat     jadeMonkey_SHININESS           =   1083.00;

GLuint      jadeMonkey_SHADER_VERTEX;                                                                                                      
GLuint      jadeMonkey_SHADER_FRAGMENT;                                                                                                    
GLuint      jadeMonkey_SHADER;                                                                                                             
//--------------------------------------                                                                                                  
GLuint      UNIFORM_MODELVIEWPROJ_jadeMonkey;  
GLuint      UNIFORM_MODELVIEW_jadeMonkey;                                                                                             
//----
GLuint      UNIFORM_SHADOW_PROJ_jadeMonkey;   
GLuint      UNIFORM_modelViewShadow_jadeMonkey; 
//----
GLuint      UNIFORM_viewMatrix_jadeMonkey; 
//----
GLuint      UNIFORM_LIGHT_MATRIX_jadeMonkey;  
GLuint      UNIFORM_textureMatrix_jadeMonkey;
GLuint      UNIFORM_INVERSEMATRIX_jadeMonkey;
                                                                                  
//------------------------------------------------  


GLuint      UNIFORM_SHININESS_jadeMonkey; 
GLuint      UNIFORM_GENERIC_jadeMonkey; 

GLuint      UNIFORM_zDirBias_jadeMonkey;  
GLuint      UNIFORM_TEXTURE_LightMap_jadeMonkey;
GLuint      UNIFORM_TEXTURE_SHADOW_jadeMonkey;                                                                                              
GLuint      UNIFORM_TEXTURE_HEIGHT_jadeMonkey;
GLuint      UNIFORM_TEXTURE_DOT3_jadeMonkey;
GLuint      UNIFORM_TEXTURE_jadeMonkey;                                                                                                    
//--------------------------------------                                                                                                  
GLfloat     jadeMonkey_POSITION[]            =  {  0.0, 0.0,  0.0, 1.0};                                                                    
GLfloat     jadeMonkey_ROTATE[]              =  {  0.0, 1.0,  0.0, 0.0};                                                                   
GLfloat     jadeMonkey_SCALE[]               =  {  1.0, 1.0,  1.0, 1.0};                                                                   
