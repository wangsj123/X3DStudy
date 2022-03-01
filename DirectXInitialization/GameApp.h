#ifndef _GAMEAPP_H
#define _GAMEAPP_H
#include "D3DApp.h"

class GameApp :
    public D3DApp
{
public:
    GameApp(HINSTANCE hInstance);
    ~GameApp();

    bool Init() override;
    void OnResize() override;
    void UpdateScene(float dt) override;
    void DrawScene() override;
};

#endif

