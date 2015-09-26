glEnable(GL_DEPTH_TEST);	
        glEnable(GL_DEPTH_TEST);
        glDepthMask(1);
        glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE); 
        glDepthFunc(GL_LESS);
      
      
        glBindFramebuffer(GL_FRAMEBUFFER, m_uiFrameBufferObject);   

#ifdef WIN32
        //----------------------------------------------------------------
        glClear (GL_DEPTH_BUFFER_BIT);
        glViewport(1, 1, (GLsizei)(viewWidth), (GLsizei)(viewHeight));
        //----------------------------------------------------------------

    
        PerspectiveMatrix(ProjectionShadow, fieldOfView, (GLfloat)viewWidth * 1.2 /  (GLfloat)viewHeight,  adjustNearFar[0],  adjustNearFar[1]);
#endif
   
#ifdef   __APPLE__     
        //----------------------------------------------------------------
        glClear (GL_DEPTH_BUFFER_BIT);
        glViewport(1, 1, 2000 - 2, 1000 - 2);
        //----------------------------------------------------------------
        glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE); 
    
        PerspectiveMatrix(ProjectionShadow, fieldOfView, 2000 / 1000,  adjustNearFar[0],  adjustNearFar[1]);
#endif          
      
        


        //================================================================================================================================
        shaderNumber = 47;//shadow_32bit_Stride
        setupTransforms_Shadows();       
        //#include "_MODEL_FOLDERS_/monkey/monkey_Render.cpp"  
        //================================================================================================================================
                


//========================================================================================================================================



//############################################################################################################################################### 
//###############################################################################################################################################   
//###############################################################################################################################################   
        
	                       
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
	
	
        //glDepthMask(0);
        glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE); 
        //glDepthFunc(GL_EQUAL);	
	
    //=================================================================================
    #include "_MODEL_FOLDERS_/disk106/disk106_SHADOW_00.cpp"
    //=================================================================================
    #include "_MODEL_FOLDERS_/tentacles/tentacles_SHADOW_00.cpp"
