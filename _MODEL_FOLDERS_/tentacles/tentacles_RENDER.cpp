setupTransforms_MainColor();                                                    
//==========================                                                    
    glBindBuffer(GL_ARRAY_BUFFER, tentacles_VBO);                  
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, tentacles_INDICES_VBO);  
    //------------------------------------------------------------------------  
    LoadIdentity(modelWorld);                                                   
    //------------------------                                                  
    Translate(modelWorld, tentacles_POSITION[0],                   
                          tentacles_POSITION[1],                   
                          tentacles_POSITION[2]);                  

    Rotate(modelWorld,    tentacles_ROTATE[0],                     
                          tentacles_ROTATE[1],                     
                          tentacles_ROTATE[2],                     
                          tentacles_ROTATE[3]);                    

    //------------------------------------------------------                    
/*    LoadIdentity(modelRotation);                                                
    //------------------------                                                  
    Rotate(modelRotation, tentacles_ROTATE[0],                     
                          tentacles_ROTATE[1],                     
                          tentacles_ROTATE[2],                     
                          tentacles_ROTATE[3]);                    
*/
//=========================                                                     
SelectShader(shaderNumber);                                                     
//=========================                                                     

    glActiveTexture ( GL_TEXTURE1 );                                            
    glBindTexture(GL_TEXTURE_2D, tentacles_NORMALMAP);             
    //---                                                                       
    glActiveTexture (GL_TEXTURE0);                                              
    glBindTexture(GL_TEXTURE_2D, tentacles_TEXTUREMAP);            
    //--------------------------------------------------------------            
    glDrawElements(GL_TRIANGLES, 2976, GL_UNSIGNED_INT, 0);           

