#pragma once

//STD Libs
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<sstream>
#include<algorithm>

//OpenGL Math libs
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>

//Own libs
#include"vertex.h"
#include"libs.h"

float manhattanDistance(glm::vec3 v);

static std::vector<Vertex> loadOBJ(const char* file_name)
{
	//Vertex portions
	std::vector<glm::fvec3> vertex_positions;
	std::vector<glm::fvec2> vertex_texcoords;
	std::vector<glm::fvec3> vertex_normals;

	std::vector<Vertex> trueVertices;
	std::vector<GLuint> indices;

	//Face vectors
	std::vector<GLint> vertex_position_indicies;
	std::vector<GLint> vertex_texcoord_indicies;
	std::vector<GLint> vertex_normal_indicies;

	//Vertex array
	std::vector<Vertex> vertices;

	std::stringstream ss;
	std::ifstream in_file(file_name);
	std::string line = "";
	std::string prefix = "";
	glm::vec3 temp_vec3;
	glm::vec2 temp_vec2;
	GLint temp_glint = 0;
	int vnCounter = 0;
	int vtCounter = 0;

	//File open error check
	if (!in_file.is_open())
	{
		throw "ERROR::OBJLOADER::Could not open file.";
	}
	float largestvector = 0;
	//Read one line at a time
	while (std::getline(in_file, line))
	{
		//Get the prefix of the line
		ss.clear();
		ss.str(line);
		ss >> prefix;
		
		if (prefix == "v") //Vertex position
		{
			/*
			Vertex v;
			ss >> v.position.x;
			ss >> v.position.y;
			ss >> v.position.z;

			float vectorlenght = abs(v.position.x * v.position.y * v.position.z);
			if(vectorlenght > largestvector) largestvector = vectorlenght;

			v.color = glm::vec3(1.f);
			
			vertices.push_back(v);
			*/
			
			ss >> temp_vec3.x >> temp_vec3.y >> temp_vec3.z;
			vertex_positions.push_back(temp_vec3);
			
		}
		
		else if (prefix == "vt")
		{
			ss >> temp_vec2.x >> temp_vec2.y;
			vertex_texcoords.push_back(temp_vec2);
			vtCounter++;
		}
		else if (prefix == "vn")
		{
			ss >> temp_vec3.x >> temp_vec3.y >> temp_vec3.z;
			vertex_normals.push_back(temp_vec3);
			vnCounter++;
		}
		else if (prefix == "f")
		{
			
			/*
			int index;
			int vAmount = 0;

			std::vector<GLuint> temp_indices;

			//read all vertecies
			while(ss.peek() != '\n'){
				ss >> prefix;
				index = std::stoi(prefix, nullptr, 10);
				temp_indices.push_back(index-1);
				vAmount++;
			}

			for(unsigned int i = 2; i < temp_indices.size(); i++){
				indices.push_back(temp_indices[0]);
				indices.push_back(temp_indices[i-1]);
				indices.push_back(temp_indices[i]);
			}
			*/
			 
			std::vector<GLuint> temp_indices;
			int counter = 0;
			while (ss >> temp_glint)
			{
					//Pushing indices into correct arrays
					if (counter == 0){
						vertex_position_indicies.push_back(temp_glint);	
						//temp_indices.push_back(temp_glint);
						printf("counter: %d :: Vertex_Pos_indicies: %ld\n",counter, vertex_position_indicies.size());
					}
					else if (counter == 1){
						vertex_texcoord_indicies.push_back(temp_glint);
						//temp_indices.push_back(temp_glint);
						printf("counter: %d :: Vertex_tex_indicies: %ld\n",counter, vertex_texcoord_indicies.size());
					}
					else if (counter == 2){
						vertex_normal_indicies.push_back(temp_glint);
						//temp_indices.push_back(temp_glint);
						printf("counter: %d :: Vertex_norm_indicies: %ld\n",counter, vertex_normal_indicies.size());
					}
	
				//Handling characters
				if (ss.peek() == '/')
				{
					counter++;
					ss.ignore(1, '/');
				}
				else if (ss.peek() == ' ')
				{
					counter++;
					ss.ignore(1, ' ');
				}
				else if(ss.peek() == '\n'){
					counter = 0;
					ss.ignore(1, '\n');
				}
				//Reset the counter
				if (counter > 2)
				/*
					for(unsigned int i = 2; i < temp_indices.size(); i++){
						indices.push_back(temp_indices[0]);
						indices.push_back(temp_indices[i-1]);
						indices.push_back(temp_indices[i]);
					}
				*/
				counter = 0;
			}	
		}
		else
		{

		}
	}

	in_file.close();


	//nomramlize mesh
	float normalize = sqrt(largestvector);
	/*
	for(unsigned int i = 0; i < vertices.size(); i++){
		vertices[i].position = vertices[i].position / normalize;
	}
	*/

	
	
	//Build final vertex array (mesh)
	vertices.resize(vertex_position_indicies.size(), Vertex());

	//Load in all indices
	for (size_t i = 0; i < vertices.size(); ++i)
	{
		vertices[i].position = vertex_positions[vertex_position_indicies[i] - 1];
	
		if(vtCounter > 0){
			printf("vertex texcoords: %ld\n", sizeof(vertex_texcoords));
			vertices[i].texcoord = vertex_texcoords[vertex_texcoord_indicies[i] - 1];
		}
		if(vnCounter > 0){
			printf("vertex normals: %ld\n", sizeof(vertex_normals));
			vertices[i].normal = vertex_normals[vertex_normal_indicies[i] - 1];

		}	
		vertices[i].color = glm::vec3(1.f, 0.f, 1.f);
	}
	
	/*
	std::pair <std::vector<Vertex>,std::vector<GLuint>> ret;
	ret.first = vertices;
	ret.second = indices;
	*/

	//new Mesh(vertices.data(), vertices.size(), nullptr, 0);

	//DEBUG
	std::cout << "Nr of vertices: " << vertices.size() << "\n";
	
	//Loaded success
	std::cout << "OBJ file loaded!" << "\n";
	return vertices;
}
