    if(room_10_NORMALMAP != 0)                      
    {                                                              
        glDeleteTextures(1, &room_10_NORMALMAP);    
        room_10_NORMALMAP = 0;                      
    }                                                              
    if(room_10_TEXTUREMAP  != 0)                    
    {                                                              
        glDeleteTextures(1, &room_10_TEXTUREMAP);   
        room_10_TEXTUREMAP  = 0;                    
    }                                                              
    //===========================================================  

    if(room_10_VBO  != 0)                           
    {                                                              
        glDeleteBuffers(1, &room_10_VBO);           
        room_10_VBO  = 0;                           
    }                                                              
    if(room_10_INDICES_VBO  != 0)                   
    {                                                              
        glDeleteBuffers(1, &room_10_INDICES_VBO);   
        room_10_INDICES_VBO  = 0;                   
    }                                                              
