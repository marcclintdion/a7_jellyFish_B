glUseProgram(jadeMonkey_SHADER);      
//================================================================================== 
 

   MultiplyMatrix(mvpMatrix, projection, modelView);                                                                                                                         
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__LIGHT             
    LoadIdentity(lightMatrix);                                                                                                                                                
    InvertMatrix(lightMatrix, modelView);                                                                                                                                     
    //---------------------------------------------------------------------------------------------------------------------------------------------------|__LIGHT             
    LoadIdentity(textureMatrix);
    //Translate(textureMatrix, shadowsPositionOffset[0], shadowsPositionOffset[1], shadowsPositionOffset[2]);
    //Scale(textureMatrix, scaleShadows, scaleShadows, scaleShadows);   
    //======================================================================================================                                                                  
    glVertexAttribPointer(0,   3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(0));                                                                                                  
    glEnableVertexAttribArray(0);	                                                                                                                                          
    glVertexAttribPointer(1,   3, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(12));                                                                                                 
    glEnableVertexAttribArray(1);  
    glVertexAttribPointer(2,   2, GL_FLOAT, GL_FALSE, 32, BUFFER_OFFSET(24));                                                                                                 
    glEnableVertexAttribArray(2);     
    //======================================================================================================                
    glUniformMatrix4fv(UNIFORM_MODELVIEWPROJ_jadeMonkey,   1,0,  mvpMatrix); 
    glUniformMatrix4fv(UNIFORM_MODELVIEW_jadeMonkey,       1,0,  modelView);                                                                                                          
    //---------------     
    glUniformMatrix4fv(UNIFORM_viewMatrix_jadeMonkey,      1,0,  viewMatrix);     
    //---------------  
    glUniformMatrix4fv(UNIFORM_SHADOW_PROJ_jadeMonkey,     1,0,  ProjectionShadow);   
    glUniformMatrix4fv(UNIFORM_modelViewShadow_jadeMonkey, 1,0,  modelViewShadow);     
    //----------------     
    glUniformMatrix4fv(UNIFORM_LIGHT_MATRIX_jadeMonkey,    1,0,  lightMatrix);
    glUniformMatrix4fv(UNIFORM_textureMatrix_jadeMonkey,   1,0,  textureMatrix);  
    
    //---------------------------------------------------------------------------------    
    glUniform4f(UNIFORM_LIGHT_POSITION_01_jadeMonkey, jadeMonkey_LIGHT_POSITION_01[0]+eyeposition[0]+ eyeStartPosition[0], 
                                                  jadeMonkey_LIGHT_POSITION_01[1]+eyeposition[1]+ eyeStartPosition[1], 
                                                  jadeMonkey_LIGHT_POSITION_01[2]+eyeposition[2]+ eyeStartPosition[2], 
                                                  jadeMonkey_LIGHT_POSITION_01[3]+eyeposition[3]+ eyeStartPosition[3]); 
    //--------------------------------------------  
    glUniform4f(UNIFORM_LIGHT_POSITION_02_jadeMonkey, jadeMonkey_LIGHT_POSITION_02[0]+eyeposition[0]+ eyeStartPosition[0], 
                                                  jadeMonkey_LIGHT_POSITION_02[1]+eyeposition[1]+ eyeStartPosition[1], 
                                                  jadeMonkey_LIGHT_POSITION_02[2]+eyeposition[2]+ eyeStartPosition[2], 
                                                  jadeMonkey_LIGHT_POSITION_02[3]+eyeposition[3]+ eyeStartPosition[3]);                                                   
    //--------------------------------------------  
    glUniform4f(UNIFORM_LIGHT_POSITION_03_jadeMonkey, jadeMonkey_LIGHT_POSITION_03[0]+eyeposition[0]+ eyeStartPosition[0], 
                                                  jadeMonkey_LIGHT_POSITION_03[1]+eyeposition[1]+ eyeStartPosition[1], 
                                                  jadeMonkey_LIGHT_POSITION_03[2]+eyeposition[2]+ eyeStartPosition[2], 
                                                  jadeMonkey_LIGHT_POSITION_03[3]+eyeposition[3]+ eyeStartPosition[3]);                                                        
    //--------------------------------------------  
    glUniform4f(UNIFORM_LIGHT_POSITION_04_jadeMonkey, jadeMonkey_LIGHT_POSITION_04[0]+eyeposition[0]+ eyeStartPosition[0], 
                                                  jadeMonkey_LIGHT_POSITION_04[1]+eyeposition[1]+ eyeStartPosition[1], 
                                                  jadeMonkey_LIGHT_POSITION_04[2]+eyeposition[2]+ eyeStartPosition[2], 
                                                  jadeMonkey_LIGHT_POSITION_04[3]+eyeposition[3]+ eyeStartPosition[3]);                                                          
                                                     
                                                       
                                                       
    //---------------------------------------------------------------------------------     
    glUniform1f(UNIFORM_SHININESS_jadeMonkey, jadeMonkey_SHININESS);  
    
    glUniform1f(UNIFORM_GENERIC_jadeMonkey, adjust_w);     
    //---------------------------------------------------------------------------------       
    
    glUniform1i (UNIFORM_TEXTURE_SHADOW_jadeMonkey, 3);      
    
    glUniform1i (UNIFORM_TEXTURE_DOT3_jadeMonkey, 1);                                                                                                                             
    glUniform1i (UNIFORM_TEXTURE_jadeMonkey, 0 );                                                                                                                                 
    //======================================================================================================                                                                  
     
    glActiveTexture ( GL_TEXTURE3 );                                                                                                                                          
    glBindTexture(GL_TEXTURE_2D, m_uiShadowMapTexture);                                                                                                                          
    //---     
