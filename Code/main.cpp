#include"Engine.h"

int main(){
    Engine loop("Part1", 1000, 1000);

   //Main loop
    while(!loop.getWindowShouldClose()){
        //check update input ---
        loop.update();
        loop.render();
    } 
    return 0;
}