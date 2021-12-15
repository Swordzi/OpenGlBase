#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"
#include "shaderClass.h"




int main() {

    int width = 800;
    int height = 600;


    GLfloat vertices[] =
    {
       -0.5, -0.5 * float(sqrt(3)) / 3, 0.0f,
       0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
       0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f,
       -0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f,
       0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f,
       0.0f, -0.5f * float(sqrt(3)) / 3, 0.0f

    };


    GLuint indices[] =
    {
        0, 3, 5, // Ala vasen kulma
        3, 2, 4, // Ala oikea kulma
        5, 4, 1 //Ylä Kolmio
    };


    //Start GLFW
    glfwInit();
    //Tell GLFW the version of OPENGL used
    //Tell GLFW that we are using opengl 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //tell GLFW we are using core profile
    //Create a GLFWWindow size of the integers chosen. Also Picking a name for the window
    GLFWwindow* window = glfwCreateWindow(width, height, "Window Testing", NULL, NULL);
    //Error Checking
    if (window == NULL) {
        std::cout << "Failed to create the window" << std::endl;
        glfwTerminate();
        return -1;
    }
    //Tell the context of the window
    glfwMakeContextCurrent(window);
    gladLoadGL();

    glViewport(0, 0, width, height);
    

    Shader shaderProgram("default.vert", "default.frag");

    VAO VAO1;
    VAO1.Bind();

    VBO VBO1(vertices, sizeof(vertices));
    EBO EBO1(indices, sizeof(indices));

    VAO1.LinkVBO(VBO1, 0);
    VAO1.Unbind();
    VBO1.Unbind();
    EBO1.Unbind();


    glClearColor(0.7f, 0.13f, 0.17f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);
    


    //Keep the window open and draw the objects

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.4f, 0.44f, 0.34f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        //Telling OpenGl Which program we want to use
        shaderProgram.Activate();
        VAO1.Bind();
        glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(int), GL_UNSIGNED_INT, 0);
        glfwSwapBuffers(window);
        //Taking care of all GLFW stuff
        glfwPollEvents();
    }

    //Delete all the objects
    VAO1.Delete();
    VBO1.Delete();
    EBO1.Delete();
    shaderProgram.Delete();

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
