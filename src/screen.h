#pragma once
#include <thread>

#include "app/window.h"
#include "app/input.h"

#include "drawing/bitmap.h"

#include "pathTracing/pathTracer.h"

class screen :
    public window
{
public:
    screen(std::wstring name, uint witdh, uint height);
    ~screen(void);

    void onInit() override;
    void onClosing() override {};
    void onUpdate() override {};
    void onRender() override {};
    void onTick() override {};

    void onKeyUp(keyboardEventArgs* args);

private:
    void initInput();
    void initPathTracer();
    void initScene();
    void launchPathTracer();
    void doubleSsp();
    void halveSsp();
    void doubleResolution();
    void halveResolution();
    void updateTitle();
    void writeInstructionsInConsole();

private:
    const float ASPECT;
    const uint MIN_SSP;
    const uint MAX_SSP;
    const uint MIN_WIDTH;
    const uint MAX_WIDTH;
    const uint TILE_WIDTH;
    const uint TILE_HEIGHT;

    bool _processing;
    uint _resultWidth;
    uint _resultHeight;
    uint _currentSsp;

    camera* _camera;
    
    scene* _scene0;
    scene* _scene1;
    scene* _scene2;
    scene* _scene3;
    scene* _scene4;
    scene* _scene5;

    pathTracer* _pathTracer;
};