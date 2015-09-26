setupTransforms_MainColor();                                                    
//==========================                                                    
    glBindBuffer(GL_ARRAY_BUFFER, room_10_VBO);                  
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, room_10_INDICES_VBO);  
    //------------------------------------------------------------------------  
    LoadIdentity(modelWorld);                                                   
    //------------------------                                                  
    Translate(modelWorld, room_10_POSITION[0],                   
                          room_10_POSITION[1],                   
                          room_10_POSITION[2]);                  

    Rotate(modelWorld,    room_10_ROTATE[0],                     
                          room_10_ROTATE[1],                     
                          room_10_ROTATE[2],                     
                          room_10_ROTATE[3]);                    

    //------------------------------------------------------                    
    LoadIdentity(modelRotation);                                                
    //------------------------                                                  
    Rotate(modelRotation, room_10_ROTATE[0],                     
                          room_10_ROTATE[1],                     
                          room_10_ROTATE[2],                     
                          room_10_ROTATE[3]);                    

//=========================                                                     
SelectShader(shaderNumber);                                                     
//=========================                                                     

    glActiveTexture ( GL_TEXTURE1 );                                            
    glBindTexture(GL_TEXTURE_2D, room_10_NORMALMAP);             
    //---                                                                       
    glActiveTexture (GL_TEXTURE0);                                              
    glBindTexture(GL_TEXTURE_2D, room_10_TEXTUREMAP);            
    //--------------------------------------------------------------            
    glDrawElements(GL_TRIANGLES, 30, GL_UNSIGNED_INT, 0);           

