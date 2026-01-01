#include <iostream>
#include "raylib.h"
#include <raymath.h>

int main()
{
    // Andaze Safhe
    const int screenWidth = 1366;
    const int screenHeight = 768;
    InitWindow(screenWidth, screenHeight, NULL);

    // Icon Window
    Image img = LoadImage("gravity.png");
    //img.height = 100;
    //img.width = 100;
    SetWindowIcon(img);


    SetWindowTitle("Circle Physics");

    // FPS
    SetTargetFPS(100);
    //SetTargetFPS(10);

    
    

    // Music
    InitAudioDevice();
    Music mc = LoadMusicStream("Source Music");
    PlayMusicStream(mc);


    // Center safhe
    float taghsim = screenWidth / 2.0f;
    float taghsim2 = screenHeight / 2.0f;

    Vector2 circlePos = { taghsim, taghsim2 };
    float radius = 50.0f;
    float speed = 5.0f;

    int num = 0;
    while (!WindowShouldClose())
    {
        UpdateMusicStream(mc);


        // Stop music
        if (IsKeyPressed(KEY_SPACE)) 
        {
            StopMusicStream(mc);
        }

        // Start music
        if (IsKeyPressed(KEY_SPACE))
        {
            PlayMusicStream(mc);
        }


        // Jahat ha
        if (IsKeyDown(KEY_RIGHT))
            circlePos.x += speed;
        if (IsKeyDown(KEY_LEFT))
            circlePos.x -= speed;
        if (IsKeyDown(KEY_UP))
            circlePos.y -= speed;
        if (IsKeyDown(KEY_DOWN))
            circlePos.y += speed;

        // Safhe
        BeginDrawing();
        ClearBackground(GREEN);


        //DrawCircle3D(circlePos,radius, circlePos,radius,RED);
        //DrawFPS(5, 5);
        
        // Made
        DrawText("Coded By MamaD", 10, 50, 100, RED);
        
        // Circle
        DrawCircleV(circlePos, radius, PURPLE);
        DrawCircle(GetMouseX(), GetMouseY(), radius, YELLOW);


        // FPS and Frame Time
        DrawText(TextFormat("Frame Time: %f", GetFrameTime()), 10, 35, 20, BLUE);
        DrawText(TextFormat("FPS: %i", GetFPS()), 10, 10, 20, BLUE);

        //std::cout <<  "frameee: " << GetFrameTime() << '\n';
        
        /*
            float x;     // Rectangle top-left corner position x
            float y;     // Rectangle top-left corner position y
            float width; // Rectangle width
            float height;// Rectangle height
        */
        //Bug dare hanoz takmil nist
        Rectangle rec = { 0.0, 0.0,screenWidth,screenHeight };
        if (circlePos.x - radius <= rec.x)
        {
            speed = 0;
            if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_UP) || IsKeyDown(KEY_DOWN))
            {
                if (!IsKeyDown(KEY_LEFT))
                {
                    speed = 5.0f;
                }

            }
        }
        if (circlePos.y - radius <= rec.y)
        {
            speed = 0;
            if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_DOWN))
            {
                if (!IsKeyDown(KEY_UP))
                {
                    speed = 5.0f;
                }

            }
        }
        if (circlePos.y + radius >= rec.y + rec.height) {
            speed = 0;
            if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_UP) || IsKeyDown(KEY_LEFT))
            {
                if (!IsKeyDown(KEY_DOWN))
                {
                    speed = 5.0f;
                }

            }
        }
        if (circlePos.x + radius >= rec.x + rec.width)
        {
            speed = 0;
            if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_UP) || IsKeyDown(KEY_DOWN))
            {
                if (!IsKeyDown(KEY_RIGHT))
                {
                    speed = 5.0f;
                }

            }
        }

        //std::cout << "Time: " << GetTime() << '\n';
        
        //circle
        //cirle
        //DrawCircle(circlePos.x, circlePos.y, radius, PURPLE);
        //Vector3 center3D = { 0.0f, 0.0f, 0.0f };
        //Vector2 circlePos22 = { taghsim, taghsim2 };
        /*int num = 0;
        if (CheckCollisionCircles(circlePos, 0.0f, circlePos, 0.0f))
        {
            std::cout << "Barkhord kard: " << num << '\n';
            num++;
        }*/
        //std::cout << "x: " << GetMouseX() << " Y: " << GetMouseY() << '\n';


        //DrawCircleV(circlePos, radius, RED);
        EndDrawing();
    }

    UnloadMusicStream(mc);
    CloseWindow();

    return 0;
}
