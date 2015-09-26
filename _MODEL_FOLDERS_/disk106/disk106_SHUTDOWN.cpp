    if(disk106_NORMALMAP != 0)                      
    {                                                              
        glDeleteTextures(1, &disk106_NORMALMAP);    
        disk106_NORMALMAP = 0;                      
    }                                                              
    if(disk106_TEXTUREMAP  != 0)                    
    {                                                              
        glDeleteTextures(1, &disk106_TEXTUREMAP);   
        disk106_TEXTUREMAP  = 0;                    
    }                                                              
    //===========================================================  

    if(disk106_VBO  != 0)                           
    {                                                              
        glDeleteBuffers(1, &disk106_VBO);           
        disk106_VBO  = 0;                           
    }                                                              
    if(disk106_INDICES_VBO  != 0)                   
    {                                                              
        glDeleteBuffers(1, &disk106_INDICES_VBO);   
        disk106_INDICES_VBO  = 0;                   
    }                                                              
