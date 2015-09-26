GLfloat     marble_LIGHT_POSITION_01[] =  {80.8253, 45.3438, -5.15, 1};
GLfloat     marble_LIGHT_POSITION_02[] =  {-104.599, 100, 12.5, 1};
GLfloat     marble_LIGHT_POSITION_03[] = {  -2.505,  -100,   0.0, 1.0};
GLfloat     marble_LIGHT_POSITION_04[] = {  -0.005,   0.5,   5, 1.0};

//----                                                                                                
GLuint      UNIFORM_LIGHT_POSITION_01_marble; 
GLuint      UNIFORM_LIGHT_POSITION_02_marble;        
GLuint      UNIFORM_LIGHT_POSITION_03_marble; 
GLuint      UNIFORM_LIGHT_POSITION_04_marble; 

//------------------------------------------------  

GLfloat     marble_ATTENUATION         =    0.72;
GLfloat     marble_SHININESS           =   900.00;

GLuint      marble_SHADER_VERTEX;                                                                                                      
GLuint      marble_SHADER_FRAGMENT;                                                                                                    
GLuint      marble_SHADER;                                                                                                             
//--------------------------------------                                                                                                  
GLuint      UNIFORM_MODELVIEWPROJ_marble;  
GLuint      UNIFORM_MODELVIEW_marble;                                                                                             
//----
GLuint      UNIFORM_SHADOW_PROJ_marble;   
GLuint      UNIFORM_modelViewShadow_marble; 
//----
GLuint      UNIFORM_viewMatrix_marble; 
//----
GLuint      UNIFORM_LIGHT_MATRIX_marble;  
GLuint      UNIFORM_textureMatrix_marble;
GLuint      UNIFORM_INVERSEMATRIX_marble;
                                                                                  
//------------------------------------------------  


GLuint      UNIFORM_SHININESS_marble; 
GLuint      UNIFORM_GENERIC_marble; 

GLuint      UNIFORM_zDirBias_marble;  
GLuint      UNIFORM_TEXTURE_LightMap_marble;
GLuint      UNIFORM_TEXTURE_SHADOW_marble;                                                                                              
GLuint      UNIFORM_TEXTURE_HEIGHT_marble;
GLuint      UNIFORM_TEXTURE_DOT3_marble;
GLuint      UNIFORM_TEXTURE_marble;                                                                                                    
//--------------------------------------                                                                                                  
GLfloat     marble_POSITION[]            =  {  0.0, 0.0,  0.0, 1.0};                                                                    
GLfloat     marble_ROTATE[]              =  {  0.0, 1.0,  0.0, 0.0};                                                                   
GLfloat     marble_SCALE[]               =  {  1.0, 1.0,  1.0, 1.0};                                                                   
