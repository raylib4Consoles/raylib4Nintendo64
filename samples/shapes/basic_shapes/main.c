/*******************************************************************************************
*
*   raylib [shapes] example - Draw basic shapes 2d (rectangle, circle, line...)
*
*   Example originally created with raylib 1.0, last time updated with raylib 4.2
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2014-2024 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include <libdragon.h>

#include <GL/gl.h>
#include <GL/glu.h>
#include <raylib.h>

#define ATTR_NINTENDO64_WIDTH 320
#define ATTR_NINTENDO64_HEIGHT 240
bool flag=true;


void updateController()
{
    /*cont = maple_enum_type(0, MAPLE_FUNC_CONTROLLER);

    if(cont)
    {
        pad_state = (cont_state_t *)maple_dev_status(cont);

        if(!pad_state)
        {
            printf("Error reading controller\n");
        }

        if(pad_state->buttons & CONT_START)
        {
            flag=0;
        }        
        if(pad_state->buttons & CONT_A) 
        {
            xflag = !xflag;
        }
    }*/
}

bool initApp()
{
    return true;
}
void finishApp()
{
    
    
}

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = ATTR_NINTENDO64_WIDTH;
    const int screenHeight = ATTR_NINTENDO64_HEIGHT;

    InitWindow(screenWidth, screenHeight, "raylib [shapes] example - basic shapes");
    
    float rotation = 0.0f;

   

    SetTargetFPS(30);               // Set our game to run at 60 frames-per-second
    //----------------------------------------------------------

    // Main game loop
    while (flag)    // Detect window close with Start button
    {
        // Update
        //-----------------------------------------------------
        updateController();

         //----------------------------------------------------------------------------------
        rotation += 0.2f;
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);
            
            DrawText("some basic shapes available on raylib", 10, 10, 10, DARKGRAY);

            // Circle shapes and lines
            DrawCircle(screenWidth/5, screenHeight/4, 20, DARKBLUE);
            DrawCircleGradient(screenWidth/5, 55+screenHeight/4, 30, GREEN, SKYBLUE);
            DrawCircleLines(screenWidth/5, 130+screenHeight/4, 40, DARKBLUE); 

            // Rectangle shapes and lines
            DrawRectangle(screenWidth/4*2 - 35, 5+screenHeight/6, 70, 30, RED);
            DrawRectangleGradientH(screenWidth/4*2 - 50, 55+screenHeight/6, 100, 45, MAROON, GOLD);
            DrawRectangleLines(screenWidth/4*2 - 20, 130+screenHeight/6, 40, 30, ORANGE);  // NOTE: Uses QUADS internally, not lines

            // Triangle shapes and lines
            DrawTriangle((Vector2){ 20+screenWidth/4.0f *3.0f, 40.0f },
                         (Vector2){ 20+screenWidth/4.0f *3.0f - 30.0f, 70.0f },
                         (Vector2){ 20+screenWidth/4.0f *3.0f + 30.0f, 70.0f }, VIOLET);

            DrawTriangleLines((Vector2){ 20+screenWidth/4.0f*3.0f, 90.0f },
                              (Vector2){ 20+screenWidth/4.0f*3.0f - 20.0f, 140.0f },
                              (Vector2){ 20+screenWidth/4.0f*3.0f + 20.0f, 140.0f }, DARKBLUE);

            // Polygon shapes and lines
            DrawPoly((Vector2){ 20+screenWidth/4.0f*3, 130+screenHeight/4 }, 6, 30, rotation, BROWN);
            DrawPolyLines((Vector2){ 20+screenWidth/4.0f*3, 130+screenHeight/4 }, 6, 40, rotation, BROWN); 
            DrawPolyLinesEx((Vector2){ 20+screenWidth/4.0f*3, 130+screenHeight/4 }, 6, 35, rotation, 6, BEIGE);

            // NOTE: We draw all LINES based shapes together to optimize internal drawing,
            // this way, all LINES are rendered in a single draw pass
            DrawLine(8, 22, screenWidth - 8, 22, BLACK); 
        EndDrawing();

    
        //-----------------------------------------------------
    }

    // De-Initialization
    //---------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //----------------------------------------------------------
    
    finishApp();
    return 0;
}
