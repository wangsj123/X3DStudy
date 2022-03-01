#ifndef _D3DAPP_H
#define _D3DAPP_H

#include <wrl/client.h>
#include <d3d11_1.h>
#include <string>
#include <DirectXMath.h>
#include "GameTimer.h"

#pragma comment(lib,"d3d11.lib")
#pragma comment(lib,"dxgi.lib")
#pragma comment(lib,"dxguid.lib")
#pragma comment(lib,"D3DCompiler.lib")
#pragma comment(lib,"winmm.lib")

class D3DApp
{
public:
	D3DApp(HINSTANCE hInstance);
	virtual ~D3DApp();

	HINSTANCE AppInst() const;
	HWND MainWnd() const;
	float AspectRatio() const;

	int Run();

	virtual bool Init();
	virtual void OnResize();
	virtual void UpdateScene(float dt) = 0;
	virtual void DrawScene() = 0;
	virtual LRESULT MsgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
	
protected:
	bool InitMainWindow();
	bool InitDirect3D();
	void CalculateFrameStats();

protected:
	HINSTANCE m_hAppInst;  //应用程序实例句柄
	HWND m_hMainWnd;       //主窗口句柄
	bool m_appPaused;      //是否暂停
	bool m_minimized;
	bool m_maximized;
	bool m_resizing;
	bool m_enable4xMsaa;
	UINT m_4xMsaaQuality;

	GameTimer m_timer;

protected:
	//使用模板别名(C++11)简化类型名
	template <class T>
	using ComPtr = Microsoft::WRL::ComPtr<T>;

	//Direct3D 11
	ComPtr<ID3D11Device> m_pD3DDevice;
	ComPtr<ID3D11DeviceContext> m_pD3DImmediateContext;
	ComPtr<IDXGISwapChain> m_pSwapChain;

	//Direct3D 11.1
	ComPtr<ID3D11Device1> m_pD3DDevice1;
	ComPtr<ID3D11DeviceContext1> m_pD3DImmediateContext1;
	ComPtr<IDXGISwapChain1> m_pSwapChain1;

	ComPtr<ID3D11Texture2D> m_pDepthStencilBuffer;
	ComPtr<ID3D11RenderTargetView> m_pRenderTargetView;
	ComPtr<ID3D11DepthStencilView> m_pDepthStencilView;
	D3D11_VIEWPORT m_screenViewport;

	std::wstring m_mainWndCaption;
	int m_clientWidth;
	int m_clientHeight;
};
#endif

