#pragma once

#include "libs.h"
#include "Camera.h"

//ZOOOOOOOOOOOM IN BEFORE RECORDING!

//ENUMERATIONS
enum shader_enum { SHADER_CORE_PROGAM = 0 };
enum mesh_enum { MESH_QUAD = 0 };

class Engine
{
private:
//Variables
	//Window
	GLFWwindow* window;
	const int WINDOW_WIDTH;
	const int WINDOW_HEIGHT;
	int framebufferWidth;
	int framebufferHeight;

	//Delta time
	float dt;
	float curTime;
	float lastTime;

	//Mouse Input
	double lastMouseX;
	double lastMouseY;
	double mouseX;
	double mouseY;
	double mouseOffsetX;
	double mouseOffsetY;
	bool firstMouse;

	//Camera
	Camera camera;

	//Matrices
	glm::mat4 ViewMatrix;
	glm::vec3 cameraPos;
	glm::vec3 worldUp;
	glm::vec3 camFront;

	glm::mat4 ProjectionMatrix;
	float fov;
	float nearPlane;
	float farPlane;

	//Shaders
	std::vector<Shader*> shader;

	//Textures
	//std::vector<Texture*> textures;

	//Materials
	//std::vector<Material*> materials;

	//Models
	std::vector<Model*> models;

	//Lights
	std::vector<PointLight*> lights;

//Private functions
        void initGLFW();
        void initWindow(const char* title);
        void initGLEW();
        void initOpenGLOP();
        void initMatrices();
        void initShader();
        void initOBJloader();
        void initMesh();
        void initModel();
        void initPointLights();
        void initLights();
        void initUniformFunc();
        void updateUniform();

//Static variables

public:
//Constructors / Destructors
	Engine(
		const char* title,
		const int WINDOW_WIDTH, const int WINDOW_HEIGHT
	);
	virtual ~Engine();

//Accessors
	int getWindowShouldClose();

//Modifiers
	void setWindowShouldClose();

//Functions
	void updateDt();
	void updateMouseInput();
	void updateKeyboardInput();
	void updateInput();
	void update();
	void render();

//Static functions
	static void frameBuffer_resize_callback(GLFWwindow* window, int fbW, int fbH);
};


/*
#pragma once

#include "libs.h"
#include "objLoader.h"
//Enums
enum shader_enum{
    SHADER_CORE_PROGAM = 0  
};
enum Mesh_enum{
    MESH_QUAD = 0
};


class Engine{
    private:
        //variable
        GLFWwindow* window;
        //window
        const int WINDOW_WIDTH;
        const int WINDOW_HEIGHT;
        int framebufferWidth;
        int framebufferHeight;
        //matrices
        glm::mat4 ViewMatrix;
        glm::mat4 ProjectionMatrix;
        glm::vec3 cameraPos;
        glm::vec3 worldUp;
        glm::vec3 camFront;
        float fov;
        float nearPlane;
        float farPlane;
        //Meshes
        std::vector<Mesh*> Mesher;
        //Shaders
        std::vector<Shader*> shader;
        //light
        std::vector<PointLight*> lights;
        //model
        std::vector<Model*> models;


        //priv func
        void initGLFW();
        void initWindow(const char* title);
        void initGLEW();
        void initOpenGLOP();
        void initMatrices();
        void initShader();
        void initOBJloader();
        void initMesh();
        void initModel();
        void initPointLights();
        void initLights();
        void initUniformFunc();
        void updateUniform();

        //static var

    public:
        Engine(
            const char* title,
            const int WINDOW_WIDTH,
            const int WINDOW_HEIGHT);
        
        ~Engine();

        //access
        int getWindowShouldClose();

        //modifier
        void setWindowShouldClose();

        //functions
        void updateDt();
	    void updateMouseInput();
        void updateKeyboardInput();
        void updateInput();
        void update();
        void render();

        //static fuincs
        static void frameBuffer_resize_callback(GLFWwindow* window, int fbw, int fbh);
        //static void updatInput(GLFWwindow* window, Mesh &mesh);
};
*/