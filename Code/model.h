#pragma once

#include "libs.h"
#include "objLoader.h"

class Model
{
private:
	std::vector<Mesh*> meshes;
	glm::vec3 position;

	void updateUniforms()
	{

	}

public:
	Model(
		glm::vec3 position, 
		std::vector<Mesh*>& meshes
		)
	{
		this->position = position;

		for (auto* i : meshes)
		{
			this->meshes.push_back(new Mesh(*i));
		}

		for (auto& i : this->meshes)
		{
			i->move(this->position);
			i->setOrigin(this->position);
		}
	}

	//OBJ file loaded model
	Model(
		glm::vec3 position,
		const char* objFile
	)
	{
		this->position = position;

		std::vector<Vertex> mesh = loadOBJ(objFile);
		this->meshes.push_back(new Mesh(mesh.data(), mesh.size(), NULL, 0, glm::vec3(1.f, 0.f, 0.f),
			glm::vec3(0.f),
			glm::vec3(0.f),
			glm::vec3(1.f)));

		for (auto& i : this->meshes)
		{
			i->move(this->position);
			i->setOrigin(this->position);
		}
	}

	~Model()
	{
		for (auto*& i : this->meshes)
			delete i;
	}

	//Functions
	void rotate(const glm::vec3 rotation)
	{
		for (auto& i : this->meshes)
			i->rotate(rotation);
	}

	void update()
	{

	}

	void render(Shader* shader)
	{
		//Update the uniforms
		this->updateUniforms();

		//Update uniforms
		//this->material->sendToShader(*shader);

		//Use a program (BECAUSE SHADER CLASS LAST UNIFORM UPDATE UNUSES IT)
		shader->use();

		//Draw
		for (auto& i : this->meshes)
		{   
			//Activate texture for each mesh

			i->render(shader); //Activates shader also
		}
	}
};