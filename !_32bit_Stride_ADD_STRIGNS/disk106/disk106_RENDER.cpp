setupTransforms_MainColor();                                                    
//==========================                                                    
    glBindBuffer(GL_ARRAY_BUFFER, disk106_VBO);                  
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, disk106_INDICES_VBO);  
    //------------------------------------------------------------------------  
    LoadIdentity(modelWorld);                                                   
    //------------------------                                                  
    Translate(modelWorld, disk106_POSITION[0],                   
                          disk106_POSITION[1],                   
                          disk106_POSITION[2]);                  

    Rotate(modelWorld,    disk106_ROTATE[0],                     
                          disk106_ROTATE[1],                     
                          disk106_ROTATE[2],                     
                          disk106_ROTATE[3]);                    

    //------------------------------------------------------                    
    LoadIdentity(modelRotation);                                                
    //------------------------                                                  
    Rotate(modelRotation, disk106_ROTATE[0],                     
                          disk106_ROTATE[1],                     
                          disk106_ROTATE[2],                     
                          disk106_ROTATE[3]);                    

//=========================                                                     
SelectShader(shaderNumber);                                                     
//=========================                                                     

    glActiveTexture ( GL_TEXTURE1 );                                            
    glBindTexture(GL_TEXTURE_2D, disk106_NORMALMAP);             
    //---                                                                       
    glActiveTexture (GL_TEXTURE0);                                              
    glBindTexture(GL_TEXTURE_2D, disk106_TEXTUREMAP);            
    //--------------------------------------------------------------            
    glDrawElements(GL_TRIANGLES, 6864, GL_UNSIGNED_INT, 0);           

