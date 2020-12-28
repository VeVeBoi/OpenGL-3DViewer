//
// Created by retr0 on 2020-11-17.
//

#include "openglwindow.h"

using namespace std;

OpenGLWindow::OpenGLWindow(string title, int width, int height) {
    if(!glfwInit())
        exit(EXIT_FAILURE);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    windowWidth = width;
    windowHeight = height;
    glfwWindow = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    if (glfwWindow == nullptr) {
        glfwTerminate();
        cerr << "Could not open window or initialize OpenGL context." << endl;
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(glfwWindow);
    glfwSwapInterval(1);

    // Initialize glew
    glewExperimental = GL_TRUE;
    GLenum glewError = glewInit();
    if (glewError != GLEW_OK) {
        cout << "glew init error:" << endl << glewGetErrorString(glewError) << endl;
        exit(EXIT_FAILURE);
    }

    if ( !GLEW_VERSION_4_3 ) {
        cout << "Warning: OpenGL 4.3+ not supported by the GPU!" << endl;
        cout << "Decreace supported OpenGL version if needed." << endl;
    }

    // Set graphics attributes
    glPointSize(5.0); // Unsupported in OpenGL ES 2.0 (Qt on MS Windows)
    glLineWidth(1.0);
    glViewport(0, 0, width, height);

    start();
}

OpenGLWindow::~OpenGLWindow() {
    glfwDestroyWindow(glfwWindow);
    glfwTerminate();
}

void
OpenGLWindow::start() {
    while(!glfwWindowShouldClose(glfwWindow)){
        glfwPollEvents();

        glClearColor(0.0, 1.0, 0.0, 0.0);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

        glfwSwapBuffers(glfwWindow);
        glFlush();
    }   
}

