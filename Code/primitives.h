#pragma once

#include "libs.h"
#include "vertex.h"

class Primativ{
    private:
        std::vector<Vertex> vertices;
        std::vector<GLuint> indicies;
    public:
        Primativ(){}
        virtual ~Primativ(){}

        //func
        void set(const Vertex* vertices, const unsigned nrOfVertices, 
            const GLuint* indicies, const unsigned nrOfIndicies){
            for (size_t i = 0; i < nrOfVertices; i++)
            {
                this->vertices.push_back(vertices[i]);
            }
            
            for (size_t i = 0; i < nrOfIndicies; i++)
            {
                this->indicies.push_back(indicies[i]);
            }
            
        }

        inline Vertex* getVerticies(){
            return this->vertices.data();
        }

        inline GLuint* getindicies(){
            return this->indicies.data();
        }

        inline const unsigned getNrOfVerticies(){
            return this->vertices.size();
        }

        inline const unsigned getNrOfIndicies(){
            return this->indicies.size();
        }

}; 

class Quad : public Primativ
{
    public:
        Quad()
            : Primativ()
        {
            Vertex vertices[] = 
            {
                //position                      //color                     //texcoord              //normals
                glm::vec3(-0.5f, 0.5f, 0.f),    glm::vec3(1.f, 0.f, 0.f),   glm::vec2(0.5f, 1.f),   glm::vec3(0.f, 0.f, 1.f),
                glm::vec3(-0.5f, -0.5f, 0.f),   glm::vec3(0.f, 1.f, 0.f),   glm::vec2(0.f, 0.f),    glm::vec3(0.f, 0.f, 1.f),    
                glm::vec3(0.5f, -0.5f, 0.f),    glm::vec3(0.f, 0.f, 1.f),   glm::vec2(1.f, 0.f),    glm::vec3(0.f, 0.f, 1.f),
                glm::vec3(0.5f, 0.5f, 0.f),     glm::vec3(1.f, 1.f, 0.f),   glm::vec2(0.f, 0.f),    glm::vec3(0.f, 0.f, 1.f)
            };
            unsigned nrOfVerticies = sizeof(vertices) / sizeof(Vertex); 

            GLuint indices[] = 
            {
                0, 1, 2, //triangle 2
                0, 2, 3 //Triangle 2    
            };
            unsigned nrOfIndices = sizeof(indices) / sizeof(GLuint); 
            
            this->set(vertices, nrOfVerticies, indices, nrOfIndices);
        }
};

class Triangle : public Primativ
{
    public:
        Triangle()
            : Primativ()
        {
            Vertex vertices[] = 
            {
                //position                      //color                     //texcoord              //normals
                glm::vec3(0.f, 0.5f, 0.f),    glm::vec3(1.f, 0.f, 0.f),   glm::vec2(0.5f, 1.f),   glm::vec3(0.f, 0.f, 1.f),
                glm::vec3(-0.5f, -0.5f, 0.f),   glm::vec3(0.f, 1.f, 0.f),   glm::vec2(0.f, 0.f),    glm::vec3(0.f, 0.f, 1.f),    
                glm::vec3(0.5f, -0.5f, 0.f),    glm::vec3(0.f, 0.f, 1.f),   glm::vec2(1.f, 0.f),    glm::vec3(0.f, 0.f, 1.f)
            };
            unsigned nrOfVerticies = sizeof(vertices) / sizeof(Vertex); 

            GLuint indices[] = 
            {
                0, 1, 2, //triangle 2  
            };
            unsigned nrOfIndices = sizeof(indices) / sizeof(GLuint); 
            this->set(vertices, nrOfVerticies, indices, nrOfIndices);
        }
};

class Pyramid : public Primativ{
    public:
        Pyramid()
            : Primativ()
        {
            Vertex vertices[] = 
            {
                //triangle front
                //position                      //color                     //texcoord              //normals
                glm::vec3(0.f, 0.5f, 0.f),       glm::vec3(1.f, 0.f, 0.f),   glm::vec2(0.5f, 1.f),   glm::vec3(0.f, 0.f, 1.f),
                glm::vec3(-0.5f, -0.5f, 0.5f),   glm::vec3(0.f, 1.f, 0.f),   glm::vec2(0.f, 0.f),    glm::vec3(0.f, 0.f, 1.f),    
                glm::vec3(0.5f, -0.5f, 0.5f),    glm::vec3(0.f, 0.f, 1.f),   glm::vec2(1.f, 0.f),    glm::vec3(0.f, 0.f, 1.f),

                //Triagle left
                //position                        //color                     //texcoord              //normals
                glm::vec3(0.f, 0.5f, 0.f),        glm::vec3(1.f, 1.f, 0.f),   glm::vec2(0.5f, 1.f),   glm::vec3(-1.f, 0.f, 0.f),
                glm::vec3(-0.5f, -0.5f, -0.5f),   glm::vec3(0.f, 1.f, 1.f),   glm::vec2(0.f, 0.f),    glm::vec3(-1.f, 0.f, 0.f),    
                glm::vec3(-0.5f, -0.5f, 0.5f),    glm::vec3(0.f, 0.f, 1.f),   glm::vec2(1.f, 0.f),    glm::vec3(-1.f, 0.f, 0.f),

                //Triagle back
                //position                        //color                     //texcoord              //normals
                glm::vec3(0.f, 0.5f, 0.f),        glm::vec3(1.f, 1.f, 0.f),   glm::vec2(0.5f, 1.f),   glm::vec3(0.f, 0.f, -1.f),
                glm::vec3(0.5f, -0.5f, -0.5f),    glm::vec3(0.f, 0.f, 1.f),   glm::vec2(0.f, 0.f),    glm::vec3(0.f, 0.f, -1.f),    
                glm::vec3(-0.5f, -0.5f, -0.5f),   glm::vec3(0.f, 0.f, 1.f),   glm::vec2(1.f, 0.f),    glm::vec3(0.f, 0.f, -1.f),

                //Triagle right
                //position                        //color                     //texcoord              //normals
                glm::vec3(0.f, 0.5f, 0.f),        glm::vec3(1.f, 1.f, 0.f),   glm::vec2(0.5f, 1.f),   glm::vec3(1.f, 0.f, 0.f),
                glm::vec3(0.5f, -0.5f, 0.5f),     glm::vec3(0.f, 0.f, 1.f),   glm::vec2(0.f, 0.f),    glm::vec3(1.f, 0.f, 0.f),    
                glm::vec3(0.5f, -0.5f, -0.5f),    glm::vec3(0.f, 0.f, 1.f),   glm::vec2(1.f, 0.f),    glm::vec3(1.f, 0.f, 0.f),
            };
            unsigned nrOfVerticies = sizeof(vertices) / sizeof(Vertex); 

            this->set(vertices, nrOfVerticies, nullptr, 0);
        }
};

class Cube : public Primativ
{
public:
	Cube()
		: Primativ()
	{
		Vertex vertices[] =
		{
			//Position								//Color							//Texcoords					//Normals
			glm::vec3(-0.5f, 0.5f, 0.5f),			glm::vec3(1.f, 0.f, 0.f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(-0.5f, -0.5f, 0.5f),			glm::vec3(0.f, 1.f, 0.f),		glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(0.5f, -0.5f, 0.5f),			glm::vec3(0.f, 0.f, 1.f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, 1.f),
			glm::vec3(0.5f, 0.5f, 0.5f),			glm::vec3(1.f, 1.f, 0.f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, 1.f),

			glm::vec3(0.5f, 0.5f, -0.5f),			glm::vec3(1.f, 0.f, 0.f),		glm::vec2(0.f, 1.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(0.5f, -0.5f, -0.5f),			glm::vec3(0.f, 1.f, 0.f),		glm::vec2(0.f, 0.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(-0.5f, -0.5f, -0.5f),			glm::vec3(0.f, 0.f, 1.f),		glm::vec2(1.f, 0.f),		glm::vec3(0.f, 0.f, -1.f),
			glm::vec3(-0.5f, 0.5f, -0.5f),			glm::vec3(1.f, 1.f, 0.f),		glm::vec2(1.f, 1.f),		glm::vec3(0.f, 0.f, -1.f)
		};
		unsigned nrOfVertices = sizeof(vertices) / sizeof(Vertex);

		GLuint indices[] =
		{
			0, 1, 2,
			0, 2, 3,

			7, 6, 1,
			7, 1, 0,

			4, 5, 6,
			4, 6, 7,

			3, 2, 5,
			3, 5, 4
		};
		unsigned nrOfIndices = sizeof(indices) / sizeof(GLuint);

		this->set(vertices, nrOfVertices, indices, nrOfIndices);
	}
};