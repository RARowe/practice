#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl.h>
#include <GLFW/glfw3.h>

int main() {
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    float xs[3] = { 0.0f, -0.2f, 0.2f };
    float inc[3] = { 0.01, 0.02, 0.04 };
    float colors[3] = { 1.0f, 0.85f, 0.35f };
    float colors_inc[3] = { 0.01, 0.02, 0.04 };
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(colors[0], colors[1], colors[2]);
        glBegin(GL_TRIANGLES);
        {
            glVertex3f(  xs[0],  0.6, 0.0);
            glVertex3f( xs[1], -0.3, 0.0);
            glVertex3f(  xs[2], -0.3 ,0.0);
        }
        glEnd();


        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
        for (int i = 0; i < 3; i++) {
            if (xs[i] > 1.0f || xs[i] < -1.0f) {
                inc[i] = -1 * inc[i];
            }
            xs[i] += inc[i];

            if (colors[i] > 1.0f || colors[i] < 0.0f) {
                colors_inc[i] = -1 * colors_inc[i];
            }
            colors[i] += colors_inc[i];
        }
    }

    glfwTerminate();
    return 0;
}
