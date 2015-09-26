    //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-       
    setupTransforms_Shadows();                                                                   
    //========================                                                                   

    LoadIdentity(modelWorld);                                                                    
    //------------------------                                                                   
    glBindBuffer(GL_ARRAY_BUFFER, sphere_VBO);                                   
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, sphere_INDICES_VBO);                   
    //------------------------------------------------------------------------                   
    Translate(modelWorld, sphere_POSITION[0],                                    
                          sphere_POSITION[1],                                    
                          sphere_POSITION[2]);                                   
    //------------------------------------------------------------------------                   
    Rotate(modelWorld,    sphere_ROTATE[0],                                      
                          sphere_ROTATE[1],                                      
                          sphere_ROTATE[2],                                      
                          sphere_ROTATE[3]);                                     
//=============================================                                                  
SelectShader(shaderNumber);                                                                      
//=============================================                                                  
    glDrawElements(GL_TRIANGLES, 4992, GL_UNSIGNED_INT, 0);      
