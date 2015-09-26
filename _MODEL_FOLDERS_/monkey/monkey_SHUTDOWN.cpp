                    if(monkey_NORMALMAP != 0)                                                                                                      
                    {                                                                                                                                              
                            glDeleteTextures(1, &monkey_NORMALMAP);                                                                                
                            monkey_NORMALMAP = 0;                                                                                                  
                    }                                                                                                                                              
                    if(monkey_TEXTUREMAP  != 0)                                                                                                    
                    {                                                                                                                                              
                            glDeleteTextures(1, &monkey_TEXTUREMAP);                                                                               
                            monkey_TEXTUREMAP  = 0;                                                                                                
                    }                                                                                                                                              
                    if(monkey_VBO  != 0)                                                                                                           
                    {                                                                                                                                              
                            glDeleteBuffers(1, &monkey_VBO);                                                                                       
                            monkey_VBO  = 0;                                                                                                       
                    }                                                                                                                                              
                    if(monkey_INDICES_VBO  != 0)                                                                                                   
                    {                                                                                                                                              
                            glDeleteBuffers(1, &monkey_INDICES_VBO);                                                                               
                            monkey_INDICES_VBO  = 0;                                                                                               
                    }                                                                                                                                              
