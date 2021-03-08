#define GL_SILENCE_DEPRECATION
#include <GLFW/glfw3.h>
#include <math.h>

float calcX(float x, float y) {
    return x * cos(0.01) - y * sin(0.01);
}

float calcY(float x, float y) {
    return x * sin(0.01) + y * cos(0.01);
}

typedef struct {
    float x, y;
} Point;
    const char *vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";
const char *fragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n\0";

int main(void)
{
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

    Point points[3] = {
    {  0.0,  0.6 },
    { -0.2, -0.3 },
    {  0.2, -0.3 }};
    //points[0] = {  0.0,  0.6 };
    //points[1] = { -0.2, -0.3 };
    //points[2] = {  0.2, -0.3 };
    unsigned int vertexShader;
vertexShader = glCreateShader(GL_VERTEX_SHADER);
glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
glCompileShader(vertexShader);
    unsigned int fragmentShader;
fragmentShader = glCreateShader(GL_VERTEX_SHADER);
glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
glCompileShader(fragmentShader);
unsigned int shaderProgram;
shaderProgram = glCreateProgram();
glAttachShader(shaderProgram, vertexShader);
glAttachShader(shaderProgram, fragmentShader);
glLinkProgram(shaderProgram);
glUseProgram(shaderProgram);


    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glUseProgram(shaderProgram);
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0f, 0.85f, 0.35f);
        glBegin(GL_TRIANGLES);
        {
            glVertex3f(points[0].x, points[0].y, 0.0);
            glVertex3f(points[1].x, points[1].y, 0.0);
            glVertex3f(points[2].x, points[2].y, 0.0);
        }
        glEnd();

        for (int i = 0; i < 3; i++) {
            float x = points[i].x;
            float y = points[i].y;
            points[i].x = calcX(x, y);
            points[i].y = calcY(x, y);
        }

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
