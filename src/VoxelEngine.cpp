#include "window.h"





int main()
{
    
    window* app = new window(1280, 720, "Voxel Engine Aragon");
    
    app->onStart();

    
    app->onUpdate();

  

    
    return 0;

}


