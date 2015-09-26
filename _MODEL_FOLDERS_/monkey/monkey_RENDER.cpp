    glBindBuffer(GL_ARRAY_BUFFER, monkey_VBO);                                                                                                 
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, monkey_INDICES_VBO);                                                                                                                                
    //----------------------------------------------------------------------------------------------------------------------------------------------           
    Translate(modelView, monkey_POSITION[0], monkey_POSITION[1], monkey_POSITION[2]);                          
    Rotate(modelView, monkey_ROTATE[0], monkey_ROTATE[1], monkey_ROTATE[2], monkey_ROTATE[3]); 

//======================================================================================================                                                       
    SelectShader(shaderNumber);                                                                                                                              
//======================================================================================================                                                       

    glActiveTexture ( GL_TEXTURE1 );                                                                                                                           
    glBindTexture(GL_TEXTURE_2D, monkey_NORMALMAP);                                                                                            
    //---                                                                                                                                                      
    glActiveTexture (GL_TEXTURE0);                                                                                                                             
    glBindTexture(GL_TEXTURE_2D, monkey_TEXTUREMAP);                                                                                           
    //---------------------------------------------------------------------------------------------------------------------------------------------------      
    glDrawElements(GL_TRIANGLES, 11808, GL_UNSIGNED_INT, 0);                                                                                                     

