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
#include <rlgl.h>
#define ATTR_NINTENDO64_WIDTH 320
#define ATTR_NINTENDO64_HEIGHT 240
bool flag=true;
bool xflag=false;




void updateController()
{
    joypad_poll();
    joypad_buttons_t pressed = joypad_get_buttons_pressed(JOYPAD_PORT_1);
    joypad_buttons_t held = joypad_get_buttons_held(JOYPAD_PORT_1);
    joypad_inputs_t inputs = joypad_get_inputs(JOYPAD_PORT_1);

    if (pressed.a)
    {
        xflag=!xflag;
    }
   
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
    

    InitWindow(screenWidth, screenHeight, "raylib [shapes] example - raylib logo animation");
    
   
   
    int logoPositionX = screenWidth/2 - 64;
    int logoPositionY = screenHeight/2 - 64;

    int framesCounter = 0;
    int lettersCount = 0;

    int topSideRecWidth = 8;
    int leftSideRecHeight = 8;

    int bottomSideRecWidth = 8;
    int rightSideRecHeight = 8;

    int state = 0;                  // Tracking animation states (State Machine)
    float alpha = 1.0f;             // Useful for fading

  
    SetTargetFPS(60);            
    //----------------------------------------------------------
    
    // Main game loop
    while (flag)    // Detect window close with Start button
    {
        // Update
        //-----------------------------------------------------
        updateController();

        if (state == 0)                 // State 0: Small box blinking
        {
            framesCounter++;

            if (framesCounter == 120)
            {
                state = 1;
                framesCounter = 0;      // Reset counter... will be used later...
            }
        }
        else if (state == 1)            // State 1: Top and left bars growing
        {
            topSideRecWidth += 4;
            leftSideRecHeight += 4;

            if (topSideRecWidth == 128) state = 2;
        }
        else if (state == 2)            // State 2: Bottom and right bars growing
        {
            bottomSideRecWidth += 4;
            rightSideRecHeight += 4;

            if (bottomSideRecWidth == 128) state = 3;
        }
        else if (state == 3)            // State 3: Letters appearing (one by one)
        {
            framesCounter++;

            if (framesCounter/12)       // Every 12 frames, one more letter!
            {
                lettersCount++;
                framesCounter = 0;
            }

            if (lettersCount >= 10)     // When all letters have appeared, just fade out everything
            {
                alpha -= 0.02f;

                if (alpha <= 0.0f)
                {
                    alpha = 0.0f;
                    state = 4;
                }
            }
        }
        else if (state == 4)            // State 4: Reset and Replay
        {
            if (xflag)
            {
                framesCounter = 0;
                lettersCount = 0;

                topSideRecWidth = 8;
                leftSideRecHeight = 8;

                bottomSideRecWidth = 8;
                rightSideRecHeight = 8;

                alpha = 1.0f;
                state = 0;          // Return to State 0
                xflag = 0;
            }
        }

        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
            ClearBackground(RAYWHITE);
   
            if (state == 0)
            {
                if ((framesCounter/15)%2) DrawRectangle(logoPositionX, logoPositionY, 8, 8, BLACK);
            }
            else if (state == 1)
            {
                DrawRectangle(logoPositionX, logoPositionY, topSideRecWidth, 8, BLACK);
                DrawRectangle(logoPositionX, logoPositionY, 8, leftSideRecHeight, BLACK);
            }
            else if (state == 2)
            {
                DrawRectangle(logoPositionX, logoPositionY, topSideRecWidth, 8, BLACK);
                DrawRectangle(logoPositionX, logoPositionY, 8, leftSideRecHeight, BLACK);

                DrawRectangle(logoPositionX + 120, logoPositionY, 8, rightSideRecHeight, BLACK);
                DrawRectangle(logoPositionX, logoPositionY + 120, bottomSideRecWidth, 8, BLACK);
            }
            else if (state == 3)
            {
                DrawRectangle(logoPositionX, logoPositionY, topSideRecWidth, 8, Fade(BLACK, alpha));
                DrawRectangle(logoPositionX, logoPositionY + 8, 8, leftSideRecHeight - 16, Fade(BLACK, alpha));

                DrawRectangle(logoPositionX + 120, logoPositionY + 8, 8, rightSideRecHeight - 16, Fade(BLACK, alpha));
                DrawRectangle(logoPositionX, logoPositionY + 120, bottomSideRecWidth, 8, Fade(BLACK, alpha));

                DrawRectangle(logoPositionX+8, logoPositionY+8, 112, 112, Fade(RAYWHITE, alpha));
                DrawText(TextSubtext("raylib", 0, lettersCount), GetScreenWidth()/2 - 22, GetScreenHeight()/2 + 24, 25, Fade(BLACK, alpha));
            }
            else if (state == 4)
            {
                DrawText("[A] REPLAY", screenWidth/2-60, screenHeight/2-50, 20, GRAY);
                DrawText("powered by raylib4Nintendo64", screenWidth/2-153, screenHeight/2-30, 20, GRAY);
                DrawText("February 28th Andalucía Day", screenWidth/2-153, screenHeight/2-10, 20, GREEN);

            }
            DrawFPS(10, 10);
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
