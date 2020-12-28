 //
// Created by retr0 on 2020-11-17.
//

#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>

#include "3Dstudio.h"

class OpenGLWindow
{
public:
    OpenGLWindow(std::string title, int width, int height);
    ~OpenGLWindow();

    void start();

private:
    GLFWwindow* glfwWindow;
    int windowWidth = 0;
    int windowHeight = 0;

};