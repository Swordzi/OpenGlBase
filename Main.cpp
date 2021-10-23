#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

using namespace std;


void resize(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void render(GLFWwindow* window) {

   

}

int main() {

    int width = 800;
    int height = 600;

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
    }
    //Tell the context of the window
    glfwMakeContextCurrent(window);
    gladLoadGL();

    
    glfwSetFramebufferSizeCallback(window, resize);


    //Keep the window open
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.7f, 0.13f, 0.17f, 1.0f);
        render(window);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}