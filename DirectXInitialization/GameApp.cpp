#include "GameApp.h"
#include "D3DUtil.h"
#include "DXTrace.h"

GameApp::GameApp(HINSTANCE hInstance) : D3DApp(hInstance)
{
}

GameApp::~GameApp()
{
}

bool GameApp::Init()
{
	if (!D3DApp::Init())
	{
		return false;
	}
    return true;
}

void GameApp::OnResize()
{
	D3DApp::OnResize();
}

void GameApp::UpdateScene(float dt)
{

}

void GameApp::DrawScene()
{
	assert(m_pD3DImmediateContext);
	assert(m_pSwapChain);
	static float blue[4] = { 0.0f,0.0f,1.0f,1.0f };
	m_pD3DImmediateContext->ClearRenderTargetView(m_pRenderTargetView.Get(),blue);
	m_pD3DImmediateContext->ClearDepthStencilView(m_pDepthStencilView.Get(), D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0F, 0);

	HR(m_pSwapChain->Present(0, 0));
}
