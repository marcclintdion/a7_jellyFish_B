    if(room_10_softDiffuse_NORMALMAP != 0)                      
    {                                                              
        glDeleteTextures(1, &room_10_softDiffuse_NORMALMAP);    
        room_10_softDiffuse_NORMALMAP = 0;                      
    }                                                              
    if(room_10_softDiffuse_TEXTUREMAP  != 0)                    
    {                                                              
        glDeleteTextures(1, &room_10_softDiffuse_TEXTUREMAP);   
        room_10_softDiffuse_TEXTUREMAP  = 0;                    
    }                                                              
    //===========================================================  

    if(room_10_softDiffuse_VBO  != 0)                           
    {                                                              
        glDeleteBuffers(1, &room_10_softDiffuse_VBO);           
        room_10_softDiffuse_VBO  = 0;                           
    }                                                              
    if(room_10_softDiffuse_INDICES_VBO  != 0)                   
    {                                                              
        glDeleteBuffers(1, &room_10_softDiffuse_INDICES_VBO);   
        room_10_softDiffuse_INDICES_VBO  = 0;                   
    }                                                              
