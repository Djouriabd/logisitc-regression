/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute 'raylib_compile_execute' script
*   Note that compiled executable is placed in the same folder as .c file
*
*   To test the examples on Web, press F6 and execute 'raylib_compile_execute_web' script
*   Web version of the program is generated in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   Example originally created with raylib 1.0, last time updated with raylib 1.0
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2013-2024 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

/*
#include "raylib.h"
#include<stdio.h>
#include<stdlib.h>
#include <math.h>

int linear_regression(int w, int b, int x) {
    return (w * x) + b;
}

float logistic(int x) {
    return 1 / (1 + exp(-x));
}

float odd(float y) {
    if (y == 1 || y == 0) {
        return -1;
    }
    return y / (1 - y);
}

float log_odd(float z) {
    return log(z);
}


int main(void)
{

    int t1[20]={31449,31886,46500,71082,71168,71774,79213,83488,83615,83974,88545,94259,94674,95376,96861,96927,102512,106182,108781,117936};
    int t2[20]={24,19,63,18,25,42,37,20,23,27,64,25,45,51,50,55,27,63,58,48};
    int t3[20]={1,0,1,1,1,0,0,0,0,1,1,0,0,1,0,1,0,0,1,1};
    int fx[20];
    float z[20],k[20],j[20];
    int y=6,i;

    for (i=0;i<20;i++) {
        fx[i]=linear_regression(t1[i],t2[i],y);
        printf("  %d   ",fx[i]);
        z[i]=logistic(fx[i]);
        printf("  %f   ",z[i]);
        k[i]=odd(z[i]);
        printf("  %f   ",k[i]);
        j[i]=log_odd(k[i]);
        printf("  %f   ",j[i]);
        //j[i]=(k[i] > 0) ? log_odd(k[i]) : -1;
    }
    const int screenWidth=1200;
    const int screenHeight=580;

    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(screenWidth, screenHeight, "raylib [shapes] example - cubic-bezier lines");

    Vector2 startPoint={50,(float)screenHeight-30};
    Vector2 endPoint = {(float)screenWidth-30,50};

    SetTargetFPS(60); 
    // Main game loop
    
    while (!WindowShouldClose())
    {
        DrawLineBezier(startPoint, endPoint, 2.0f, RED);
        ClearBackground(RAYWHITE);
        BeginDrawing();

        DrawText("Logistic Regression Visualization:", 60, 5, 20, BLACK);
        DrawLine(50, screenHeight-30, screenWidth-50, screenHeight-30, GRAY);//-30 //-50 //-30 //x-axis
        DrawLine(50, screenHeight - 30, 50, 20, GRAY); //30                                    //y-axis1
        DrawLine(600, screenHeight-30, screenWidth/2, 20, RED); //30                           //y-axis1
        //DrawLine(50, 550, 750, 550, GRAY);
        //DrawLine(50, 550, 50, 50, GRAY);
        //DrawText("1", 60, 560, 10, BLACK);
        DrawText("0",30,551, 10,BLACK);
        DrawText("1", 30, 45, 10, BLACK);
        DrawText("0,5", 30, 300, 10, BLACK);


        for (int i = 0; i < 20; i++) {
            
            //int x = 50 + i * 60;

            for (int i = 0; i < 20; i++) {
            int xx = 50 + i * 55;

            int salaries = screenHeight - 30 - (int)(t3[i] * 0.0002); 
            //int age = screenHeight - 30 - (t2[i] * 6); //0.43   
            //int buy = screenHeight - 30 - (t3[i] * 20);                           
            int pred = screenHeight - 30 - (int)(fx[i] * 0.00045); //1    
            int logg = screenHeight - 30 - (int)(z[i] * 240);//20
            //int oddY = (k[i] > 0) ? screenHeight - 30 - (int)(k[i] * 50) : screenHeight - 30;//?
            //int l_o = (j[i] > 0) ? screenHeight - 30 - (int)(j[i] * 50) : screenHeight - 30;//?
            
            //int pred = 550 - (int)(fx[i] * 0.001); //fx[i]/550
            //int logg = 550 - (int)(z[i] * 500);
            int odd = (k[i] > 0) ? 550 - (int)(k[i] * 50) : 240; //550
            //int l_o = (j[i] > 0) ? 550 - (int)(j[i] * 50) : 550;

            DrawCircle(xx, salaries, 2, GRAY);
            //DrawCircle(xx,buy,5,YELLOW);
            //DrawCircle(xx, age, 5, GREEN);    // Age
            DrawCircle(xx, pred, 5, GREEN);  // Prediction
            DrawCircle(xx, logg, 5, RED);     // Logistic
            DrawCircle(xx, odd, 5, PURPLE);  // Odds
            //DrawCircle(xx, l_o, 5, BLUE); // Salaries
            

            /*int x = 50 + i * 60; //35
            int salaries=550 - (int)(t1[i] * 0.001);
            int age=550 - (int)(t2[i] * 0.001);
            int pred = 550 - (int)(fx[i] * 0.001); //fx[i]/550
            int logg = 550 - (int)(z[i] * 500);
            int odd = (k[i] > 0) ? 550 - (int)(k[i] * 50) : 550; 
            int l_o = (j[i] > 0) ? 550 - (int)(j[i] * 50) : 550;
            
            //hna i need to fix it:
            //void DrawLineV(Vector2 startPoint,Vector2 endPoint, Color BLUE); 
            //Draw(x, salaries , 5, BLUE);  
            //DrawCircle(x, pred , 5, BLUE);//pred
            //DrawCircle(x, logg, 5, GREEN);   
            //DrawCircle(x, odd, 5, ORANGE);  
            //DrawCircle(x, l_o, 5, RED);//30*/
            
           /* DrawText("31449",90,555, 10,BLACK); //
            DrawCircle((50 + 1 * 55),50, 3,BLUE);
            DrawText("31886",145,555, 10,BLACK);
            DrawCircle((50 + 2 * 55),550, 3,RED);
            DrawText("46500",200,555, 10,BLACK); //
            DrawCircle((50 + 3 * 55),50, 3,BLUE);
            DrawText("71082",257,555, 10,BLACK); //
            DrawCircle((50 + 4 * 55),50, 3,BLUE);
            DrawText("71168",315,555, 10,BLACK); //
            DrawCircle((50 + 5 * 55),50, 3,BLUE);
            DrawText("71774",368,555, 10,BLACK);
            DrawCircle((50 + 6 * 55),550, 3,RED);
            DrawText("79213",421,555, 10,BLACK);
            DrawCircle((50 + 7 * 55),550, 3,RED);
            DrawText("83488",475,555, 10,BLACK);
            DrawCircle((50 + 8 * 55),550, 3,RED);
            DrawText("83615",530,555, 10,BLACK);
            DrawCircle((50 + 9 * 55),550, 3,RED);
            DrawText("83974",585,555, 10,BLACK);//
            DrawCircle((50 + 10 * 55),50, 3,BLUE);
            DrawText("88545",642,555, 10,BLACK);//
            DrawCircle((50 + 11 * 55),50, 3,BLUE);
            DrawText("94259",695,555, 10,BLACK);
            DrawCircle((50 + 12 * 55),550, 3,RED);
            DrawText("94674",750,555, 10,BLACK);
            DrawCircle((50 + 13 * 55),550, 3,RED);
            DrawText("95376",806,555, 10,BLACK);//
            DrawCircle((50 + 14 * 55),50, 3,BLUE);
            DrawText("96861",860,555, 10,BLACK);
            DrawCircle((50 + 15 * 55),550, 3,RED);
            DrawText("96927",915,555, 10,BLACK);//
            DrawCircle((50 + 16 * 55),50, 3,BLUE);
            DrawText("102512",970,555, 10,BLACK);
            DrawCircle((50 + 17 * 55),550, 3,RED);
            DrawText("106182",1025,555, 10,BLACK);
            DrawCircle((50 + 18 * 55),550, 3,RED);
            DrawText("108781",1080,555, 10,BLACK);//
            DrawCircle((50 + 19 * 55),50, 3,BLUE);
            DrawText("117936",1135,555, 10,BLACK);//
            DrawCircle((50 + 20 * 55),50, 3,BLUE);
            
            /*if (i<12 && i!=10){
                int pred = screenHeight - 30 - (int)(fx[i] * 6.0); //5.5
                DrawCircle(xx, pred, 5, GREEN);
                DrawText(TextFormat("%.2f", fx[i]), xx , pred - 20, 5, GREEN);}
            else if (i==10){
                int pred = screenHeight - 30 - (int)(fx[i] * 6.0); //3.5
                DrawCircle(xx, pred, 5, RED);
                DrawText(TextFormat("%.2f", fx[i]), xx , pred - 20, 5, RED);
            }
            else{
                int pred = screenHeight - 30 - (int)(fx[i] * 6.0); //3.5
                DrawCircle(xx, pred, 5, RED);
                DrawText(TextFormat("%.2f", fx[i]), xx , pred - 20, 5, RED);
            }*/
            
            
            //DrawText(TextFormat("s="))*/
            //DrawText(TextFormat("%d", t1[0]), x - 30, salaries - 20, 10, BLUE);
            //DrawText(TextFormat("P: %.2f", fx[i]), x , pred - 20, 10, BLUE); //20
            //DrawText(TextFormat("salaries: %.2f", t1[i]), x - 30, salaries - 20, 10, CYAN); 
            //DrawText(TextFormat("buy: %.2f", t2[i]), x - 30, buy - 20, 10, BLACK); 
            //DrawText(TextFormat("L: %.2f", z[i]), x - 30, logg - 20, 10, GREEN);
            //DrawText(TextFormat("O: %.2f", k[i]), x - 30, odd - 20, 10, ORANGE);
            //DrawText(TextFormat("LO: %.2f", j[i]), x - 30, l_o - 20, 10, RED);
        //ClearBackground(RAYWHITE);*/
       /* }
        }
        EndDrawing();
    }
    CloseWindow();

    return 0;
    }

/*
#include "raylib.h"
#include<math.h>

int main(void) {
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Raylib - Label X-axis");

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        // Drawing
        BeginDrawing();
        ClearBackground(RAYWHITE)4;

        // Draw axes
        int centerX = screenWidth / 2;
        int centerY = screenHeight / 2;
        DrawLine(50, centerY, screenWidth - 50, centerY, BLACK); // X-axis
        DrawLine(centerX, 50, centerX, screenHeight - 50, BLACK); // Y-axis

        // Draw labels on X-axis
        for (int i = -8; i <= 8; i++) {
            int x = centerX + i * 50; // Scale: 50 pixels per unit
            DrawLine(x, centerY - 5, x, centerY + 5, BLACK); // Small ticks on the axis
            DrawText(TextFormat("%d", i), x - 10, centerY + 10, 10, BLACK); // Label the tick
        }

        // Draw labels on Y-axis
        for (int i = 0; i <= 1; i++) {
            int y = centerY - i * 250; // Scale: 250 pixels per unit
            DrawLine(centerX - 5, y, centerX + 5, y, BLACK); // Small ticks on the axis
            DrawText(TextFormat("%.1f", (float)i), centerX + 10, y - 5, 10, BLACK); // Label the tick
        }

        // Draw the logistic function
        Vector2 previousPoint = { centerX - 8 * 50, centerY + 250 };
        for (float z = -8.0; z <= 8.0; z += 0.1) {
            float phi = 1.0f / (1.0f + expf(-z)); // Logistic function
            Vector2 currentPoint = { centerX + z * 50, centerY - phi * 250 }; // Scale logistic values
            DrawLineV(previousPoint, currentPoint, BLUE);
            previousPoint = currentPoint;
        }

        EndDrawing();
    }

    // De-initialization
    CloseWindow();

    return 0;
}*/

/*
#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int linear_regression(int w, int b, int x) {
    return (w * x) + b;
}

float logistic(int x) {
    return 1 / (1 + exp(-x));
}

float odd(float y) {
    if (y == 1 || y == 0) {
        return -1;
    }
    return y / (1 - y);
}

float log_odd(float z) {
    return log(z);
}

int main(void) {
    // Data points
    int t1[20] = {31449, 31886, 46500, 71082, 71168, 71774, 79213, 83488, 83615, 83974,
                  88545, 94259, 94674, 95376, 96861, 96927, 102512, 106182, 108781, 117936};
    int t2[20] = {24, 19, 63, 18, 25, 42, 37, 20, 23, 27, 64, 25, 45, 51, 50, 55, 27, 63, 58, 48};
    int t3[20] = {1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1};
    int fx[20];
    float z[20], k[20], j[20];
    int y = 6;

    // Precompute values for visualization
    for (int i = 0; i < 20; i++) {
        fx[i] = linear_regression(t1[i], t2[i], y);
        z[i] = logistic(fx[i]);
        k[i] = odd(z[i]);
        j[i] = log_odd(k[i]);
    }

    // Screen setup
    const int screenWidth = 1200;
    const int screenHeight = 580;

    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(screenWidth, screenHeight, "raylib [shapes] example - Logistic Regression Visualization");

    SetTargetFPS(60);

    // Animation variables
    float animationProgress = 0.0f; // Progress from 0.0 to 1.0
    const float animationSpeed = 0.01f;

    while (!WindowShouldClose()) {
        // Update animation progress
        animationProgress += animationSpeed;
        if (animationProgress > 1.0f) {
            animationProgress = 0.0f; // Loop the animation
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw axes
        DrawText("Logistic Regression Visualization:", 60, 5, 20, BLACK);
        DrawLine(50, screenHeight - 30, screenWidth - 50, screenHeight - 30, GRAY); // X-axis
        DrawLine(50, screenHeight - 30, 50, 20, GRAY);                              // Y-axis

        // Draw data points as animated circles
        for (int i = 0; i < 20; i++) {
            int xx = 50 + i * 55; // X-coordinate
            int pred = screenHeight - 30 - (int)(fx[i] * 0.00003); // Prediction (scaled)
            int logg = screenHeight - 30 - (int)(z[i] * 500);      // Logistic (scaled)
            int oddY = (k[i] > 0) ? screenHeight - 30 - (int)(k[i] * 50) : screenHeight - 30;
            int l_o = (j[i] > 0) ? screenHeight - 30 - (int)(j[i] * 50) : screenHeight - 30;

            // Add animation effect by interpolating positions
            float animatedY = oddY + (pred - oddY) * animationProgress;

            DrawCircle(xx, animatedY, 5, PURPLE); // Animated point
            DrawCircle(xx, logg, 5, RED);        // Logistic
            DrawCircle(xx, l_o, 5, BLUE);        // Log-Odds
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}



#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function for linear regression
float calculate_best_fit_line_slope(const int x[], const int y[], int n) {
    float sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;
    for (int i = 0; i < n; i++) {
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumX2 += x[i] * x[i];
    }
    return (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
}

float calculate_best_fit_line_intercept(const int x[], const int y[], int n, float slope) {
    float sumX = 0, sumY = 0;
    for (int i = 0; i < n; i++) {
        sumX += x[i];
        sumY += y[i];
    }
    return (sumY - slope * sumX) / n;
}

int main(void)
{
    // Data points
    int t1[20] = {31449, 31886, 46500, 71082, 71168, 71774, 79213, 83488, 83615, 83974,
                  88545, 94259, 94674, 95376, 96861, 96927, 102512, 106182, 108781, 117936};
    int t2[20] = {24, 19, 63, 18, 25, 42, 37, 20, 23, 27, 64, 25, 45, 51, 50, 55, 27, 63, 58, 48};

    const int screenWidth = 1200;
    const int screenHeight = 600;

    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(screenWidth, screenHeight, "Raylib: Best-Fit Line Animation");

    int normalizedX[20];
    int normalizedY[20];

    // Normalize the data to fit within the screen
    for (int i = 0; i < 20; i++) {
        normalizedX[i] = 50 + (t1[i] - t1[0]) / 1000; // Normalize to range
        normalizedY[i] = screenHeight - 50 - t2[i] * 5; // Normalize Y
    }

    // Calculate best-fit line slope and intercept
    float slope = calculate_best_fit_line_slope(normalizedX, normalizedY, 20);
    float intercept = calculate_best_fit_line_intercept(normalizedX, normalizedY, 20, slope);

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Best-Fit Line Animation", 20, 20, 20, BLACK);

        // Draw Axes
        DrawLine(50, screenHeight - 50, screenWidth - 50, screenHeight - 50, GRAY); // X-axis
        DrawLine(50, 50, 50, screenHeight - 50, GRAY);                              // Y-axis

        // Draw circles for data points
        for (int i = 0; i < 20; i++) {
            DrawCircle(normalizedX[i], normalizedY[i], 5, BLUE);
        }

        // Draw the best-fit line
        float startX = 50;
        float endX = screenWidth - 50;
        float startY = slope * startX + intercept;
        float endY = slope * endX + intercept;

        DrawLine((int)startX, (int)startY, (int)endX, (int)endY, RED);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}*/

/*
#include <raylib.h>
#include <math.h>
#include <stdio.h>

// Sigmoid function
double sigmoid(double z) {
    return 1.0 / (1.0 + exp(-z));
}

// Predict function
double predict(double x1, double x2, double *weights) {
    double z = weights[0] + weights[1] * x1 + weights[2] * x2;
    return sigmoid(z);
}

// Logistic regression decision boundary visualization
int main() {
    // Initialize Raylib
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Logistic Regression Visualization");

    // Example dataset (scaled to fit the window)
    double X[][2] = {{200, 400}, {300, 300}, {400, 200}, {500, 100}};
    int y[] = {0, 0, 1, 1}; // Labels (0 or 1)
    int dataCount = 4;

    // Weights (after training, replace with your trained weights)
    double weights[] = {-0.5, 0.01, 0.01}; // Example weights

    // Main loop
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw data points
        for (int i = 0; i < dataCount; i++) {
            Color color = y[i] == 0 ? BLUE : RED;
            DrawCircle(X[i][0], screenHeight - X[i][1], 8, color);
        }

        // Draw decision boundary
        for (int x = 0; x < screenWidth; x++) {
            double y_boundary = -(weights[0] + weights[1] * x) / weights[2];
            if (y_boundary >= 0 && y_boundary <= screenHeight) {
                DrawPixel(x, screenHeight - (int)y_boundary, BLACK);
            }
        }

        DrawText("Logistic Regression Visualization", 10, 10, 20, DARKGRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}*/

/*
#include <raylib.h>
#include <math.h>
#include <stdio.h>

// Predict function
double predict(double x, double *weights) {
    return weights[0] + weights[1] * x;
}

// Mean Squared Error loss
double compute_loss(double *X, double *y, double *weights, int dataCount) {
    double loss = 0.0;
    for (int i = 0; i < dataCount; i++) {
        double prediction = predict(X[i], weights);
        double error = prediction - y[i];
        loss += error * error;
    }
    return loss / dataCount;
}

// Update weights using gradient descent
void gradient_descent(double *X, double *y, double *weights, int dataCount, double learning_rate, int max_iterations, double threshold) {
    for (int iter = 0; iter < max_iterations; iter++) {
        double gradient[2] = {0.0, 0.0};

        for (int i = 0; i < dataCount; i++) {
            double prediction = predict(X[i], weights);
            double error = prediction - y[i];

            gradient[0] += error;          // Bias term gradient
            gradient[1] += error * X[i];  // Slope gradient
        }

        weights[0] -= learning_rate * gradient[0] / dataCount;
        weights[1] -= learning_rate * gradient[1] / dataCount;

        // Compute loss and stop if below threshold
        double loss = compute_loss(X, y, weights, dataCount);
        if (loss < threshold) {
            printf("Converged at iteration %d with loss %.4f\n", iter, loss);
            break;
        }
    }
}

// Linear regression visualization for two classes
int main() {
    // Initialize Raylib
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Linear Regression Without Animation");

    // Example dataset (scaled to fit the window)
    double X[] = {150, 250, 350, 450, 550, 650}; // Data points (x-coordinates)
    double y[] = {200, 220, 300, 320, 400, 420}; // Data points (y-coordinates)
    int labels[] = {0, 0, 1, 1, 1, 0};           // Class labels (0 or 1)
    int dataCount = 6;

    // Initialize weights (bias and slope)
    double weights[2] = {10.0, 0.5}; // Start with non-zero values

    // Training parameters
    double learning_rate = 0.1;       // Increased for faster convergence
    int max_iterations = 1000;       // Maximum number of iterations
    double threshold = 0.001;        // Loss threshold for stopping

    // Perform gradient descent
    gradient_descent(X, y, weights, dataCount, learning_rate, max_iterations, threshold);

    // Draw the final result
    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw data points with class color
        for (int i = 0; i < dataCount; i++) {
            Color color = labels[i] == 0 ? BLUE : RED;
            DrawCircle(X[i], screenHeight - y[i], 8, color);
        }

        // Draw final regression line
        double x1 = 0, y1 = weights[0] + weights[1] * x1;
        double x2 = screenWidth, y2 = weights[0] + weights[1] * x2;
        DrawLine(x1, screenHeight - y1, x2, screenHeight - y2, DARKGREEN);

        // Display final weights and loss
        char info[100];
        sprintf(info, "Final Weights: w0 = %.4f, w1 = %.4f", weights[0], weights[1]);
        DrawText(info, 10, 10, 20, DARKGRAY);

        DrawText("Blue: Class 0 | Red: Class 1", 10, 40, 20, DARKGRAY);
        DrawText("Green line: Final regression boundary", 10, 70, 20, DARKGRAY);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}*/

/*
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "raylib.h"

float linear_regression(float w, float b, float x) {
    return (w * x) + b;
}

float logistic(float x) {
    return 1 / (1 + exp(-x));
}

float odd(float y) {
    if (y <= 0 || y >= 1) {
        return -1;  // Invalid probability
    }
    return y / (1 - y);
}

float log_odd(float z) {
    return log(z);
}

int main() {
    // Initialize Raylib
    InitWindow(800, 600, "Raylib Visualization");
    SetTargetFPS(60);

    float t1[10], t2[10];
    float y = 0.0f;
    int selectedIndex = 0;
    bool updated = false;

    // Main game loop
    while (!WindowShouldClose()) {
        // Update
        if (IsKeyPressed(KEY_ENTER)) {
            updated = true;
        }

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Enter the values for the first table (t1):", 10, 10, 20, BLACK);
        for (int i = 0; i < 10; i++) {
            char buffer[50];
            sprintf(buffer, "t1[%d]: %.2f", i, t1[i]);
            DrawText(buffer, 10, 40 + i * 30, 20, BLACK);
        }

        DrawText("Enter the values for the second table (t2):", 400, 10, 20, BLACK);
        for (int i = 0; i < 10; i++) {
            char buffer[50];
            sprintf(buffer, "t2[%d]: %.2f", i, t2[i]);
            DrawText(buffer, 400, 40 + i * 30, 20, BLACK);
        }

        if (updated) {
            DrawText("Press Enter to view predictions", 10, 350, 20, BLUE);
            for (int i = 0; i < 10; i++) {
                float fx = linear_regression(t1[i], t2[i], y);
                float z = logistic(fx);
                float k = odd(z);
                if (k != -1) {
                    float j = log_odd(k);
                    char output[200];
                    sprintf(output, "Prediction: %.2f, Logistic: %.4f, Odd: %.4f, Log-odd: %.4f", fx, z, k, j);
                    DrawText(output, 10, 500 + i * 30, 20, DARKGRAY);
                }
            }
        }

        // End Drawing
        EndDrawing();
    }

    // Close Raylib window
    CloseWindow();

    return 0;
}*/


#include "raylib.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float linear_regression(float w, float b, float x) {
    return (w * x) + b;
}

float logistic(float x) {
    return 1.0 / (1.0 + exp(-x));
}

float odd(float y) {
    if (y == 1 || y == 0) { return -1; }
    else {
        return y / (1 - y);
    }
}

float log_odd(float z) {
    return log(z);
}

int main(void) {
    int t1[20] = {2.3, 5.1, 1.2, 3.5, 4.1, 1.5, 3.5, 1.0, 5.0, 2.4, 2.6, 6.6, 0.5, 1.3, 1.4, 6.2, 10.4, 10.8, 4.2};
    int t2[20] = {22, 30, 25, 35, 15, 42, 37, 20, 23, 27, 64, 25, 45, 51, 50, 55, 27, 63, 58, 48};
    int t3[20] = {0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1};
    float fx[20];
    float z[20], k[20], j[20];
    int y = 2.6, i;

    for (i = 0; i < 20; i++) {
        fx[i] = linear_regression(t1[i], t2[i], y);
        z[i] = logistic(fx[i]);
        k[i] = odd(z[i]);
        if (k[i] != -1) {
            j[i] = log_odd(k[i]);
        }
    }

    const int screenWidth = 1200;
    const int screenHeight = 580;
    
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(screenWidth, screenHeight, "raylib [shapes] example - cubic-bezier lines");
    
    Vector2 startpoint={50,(float)screenHeight-30};
    Vector2 endPoint = {(float)screenWidth-30,50};

    Vector2 startPoint = {50, screenHeight / 1.84f};
    Vector2 dynamicEndPoint = {screenWidth - 30, screenHeight / 2.0f};

    SetTargetFPS(60);

    float speed = 3.0f;  // Speed of animation for dynamicEndPoint

    while (!WindowShouldClose()) {
        // Update the position of dynamicEndPoint to animate it
        dynamicEndPoint.x += speed;  // Move to the left
        
        /*while (dynamicEndPoint.x <30 ) {
            dynamicEndPoint.x = screenWidth - 30;  // Reset position to the right
        }*/
        
        if (dynamicEndPoint.x > screenWidth - 30) {
            dynamicEndPoint.x = 50;  // Reset to the left side
        }

        // Start drawing
        BeginDrawing();

        ClearBackground(BLACK);

        // Draw the animated line with dynamicEndPoint
        DrawLineBezier(startPoint, dynamicEndPoint, 2.0f, RED);
        DrawLineBezier(startpoint, (Vector2){screenWidth - 30, 50}, 2.0f, RAYWHITE);

        DrawText("Logistic Regression Visualization:", 60, 5, 20, RAYWHITE);
        DrawLine(50, screenHeight - 30, screenWidth - 50, screenHeight - 30, WHITE);  // x-axis
        DrawLine(50, screenHeight - 30, 50, 20, WHITE); // y-axis
        DrawText("0", 30, 551, 10, GRAY);
        DrawText("1", 30, 45, 10, GRAY);
        DrawText("0.5", 30, 300, 10, GRAY);

        // Loop to draw points and predictions
        for (int i = 0; i < 20; i++) {
            int xx = 50 + i * 55;
            int salaries = screenHeight - 30 - (int)(t3[i] * 0.0002);
            DrawCircle(xx, salaries, 2, GRAY);
            
            if (t3[i] == 1) {
                DrawCircle((50 + i * 55), 50, 5, YELLOW);
            } else {
                DrawCircle((50 + i * 55), 550, 5, ORANGE);
            }

            if (fx[i] < 40) {
                int pred = screenHeight - 30 - (int)(fx[i] * 6.0);
                DrawCircle(xx, pred, 5, GREEN);
                DrawText(TextFormat("%.2f", fx[i]), xx , pred - 20, 5, GREEN);
            } else {
                int pred = screenHeight - 30 - (int)(fx[i] * 6.0);
                DrawCircle(xx, pred, 5, RED);
                DrawText(TextFormat("%.2f", fx[i]), xx , pred - 20, 5, RED);
            }
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
