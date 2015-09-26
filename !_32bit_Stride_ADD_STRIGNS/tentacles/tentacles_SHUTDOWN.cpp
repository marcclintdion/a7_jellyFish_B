    if(tentacles_NORMALMAP != 0)                      
    {                                                              
        glDeleteTextures(1, &tentacles_NORMALMAP);    
        tentacles_NORMALMAP = 0;                      
    }                                                              
    if(tentacles_TEXTUREMAP  != 0)                    
    {                                                              
        glDeleteTextures(1, &tentacles_TEXTUREMAP);   
        tentacles_TEXTUREMAP  = 0;                    
    }                                                              
    //===========================================================  

    if(tentacles_VBO  != 0)                           
    {                                                              
        glDeleteBuffers(1, &tentacles_VBO);           
        tentacles_VBO  = 0;                           
    }                                                              
    if(tentacles_INDICES_VBO  != 0)                   
    {                                                              
        glDeleteBuffers(1, &tentacles_INDICES_VBO);   
        tentacles_INDICES_VBO  = 0;                   
    }                                                              
