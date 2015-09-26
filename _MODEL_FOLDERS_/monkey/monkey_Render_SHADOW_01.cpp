    glBindBuffer(GL_ARRAY_BUFFER, monkey_VBO);                                                                                                 
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, monkey_INDICES_VBO);                                                                                                                                
    //----------------------------------------------------------------------------------------------------------------------------------------------           
    Translate(modelView, monkey_POSITION[0] * scaleMoveShadows[0], 
                         monkey_POSITION[1] * scaleMoveShadows[0], 
                         monkey_POSITION[2] * scaleMoveShadows[0]);    
                                               
    Rotate(modelView, monkey_ROTATE[0], monkey_ROTATE[1], monkey_ROTATE[2], monkey_ROTATE[3]); 
    Scale(modelView,  monkey_SCALE[0],  monkey_SCALE[1],  monkey_SCALE[2]); //SCALE = 0.3
    //======================================================================================================                                                       
    SelectShader(shaderNumber);                                                                                                                              
    //======================================================================================================                                                       
    
    glDrawElements(GL_TRIANGLES, 3498, GL_UNSIGNED_INT, 0);


