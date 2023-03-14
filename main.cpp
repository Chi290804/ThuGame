#include<iostream>
#include<string>
#include<SDL.h>
#include<SDL_image.h>

using namespace std;
 
const int WIDTH = 1280, HEIGHT = 720;
 
int main( int argc, char *argv[] ) {
    SDL_Surface *imageSurface = NULL;
    SDL_Surface *windowSurface = NULL;
 
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
 
    }
 
    SDL_Window *window = SDL_CreateWindow( "Hello SDL World", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI );
    windowSurface = SDL_GetWindowSurface( window );
 
    // Check that the window was successfully created
    if ( NULL == window )
    {
        // In the case that the window could not be made...
        cout << "Could not create window: " << SDL_GetError() << endl;
        return 1;
    }
 
    if( !( IMG_Init( IMG_INIT_PNG ) & IMG_INIT_PNG ) )
    {
        cout << "Failed to initialise SDL_image for PNG files: " << IMG_GetError( ) << endl;
        return 1;
    }
 
    SDL_Event windowEvent;
 
    imageSurface = IMG_Load( "background.png" );
 
    if ( NULL == imageSurface )
    {
        cout << "SDL could not load image! SDL Error: " << SDL_GetError( ) << endl;
    }
 
    while ( true )
    {
        if ( SDL_PollEvent( &windowEvent ) )
        {
            if ( SDL_QUIT == windowEvent.type )
            {
                break;
            }
        }
 
        SDL_BlitSurface( imageSurface, NULL, windowSurface, NULL );
 
        SDL_UpdateWindowSurface( window );
    }
 
    SDL_FreeSurface( imageSurface );
    SDL_FreeSurface( windowSurface );
 
    imageSurface = NULL;
    windowSurface = NULL;
 
    SDL_DestroyWindow( window );
    SDL_Quit( );
 
    return EXIT_SUCCESS;
}