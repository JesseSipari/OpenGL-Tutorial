// Packt-OpenGL-GLSL.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <GLFW/glfw3.h>

int main()
{
    GLFWwindow * window; // Create a windowed mode window and its OpenGL context

    if (!glfwInit())
	{
        std::cerr << "Failed to initialize GLFW\n";
		return -1;
	}

    window = glfwCreateWindow(800, 600, "Hello World", 0, 0); // Create a windowed mode window and its OpenGL context

    if (!window) 
    {
		std::cerr << "Failed to create window\n";
		glfwTerminate();
		return -1;
	
    }

	glfwMakeContextCurrent(window); // Make the window's context current

	bool toggle = false;


	// Rendering loop
	while (!glfwWindowShouldClose(window))
	{

		glClearColor(1.0f, 1.0f, 1.0f, 0.0f); // Set the clear color




		glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer

		glBegin(GL_TRIANGLES); // Begin drawing a triangle

		glColor3f(1.0f, 0.0f, 0.0f); // Set the color of the triangle
		glVertex3f(-0.6f, -0.4f, 0.0f); // Bottom left vertex
		glColor3f(0.0f, 1.0f, 0.0f); // Set the color of the triangle
		glVertex3f(0.6f, -0.4f, 0.0f); // Bottom right vertex
		glColor3f(0.0f, 0.0f, 1.0f); // Set the color of the triangle
		glVertex3f(0.0f, 0.6f, 0.0f); // Top vertex

		glEnd(); // End drawing the triangle
		
		glfwSwapBuffers(window); // Swap the front and back buffers
		glfwPollEvents(); // Poll for events
	}

	glfwTerminate();

}
