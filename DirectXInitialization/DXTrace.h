#ifndef _DXTRACE_H
#define _DXTRACE_H
#include <windows.h>

//DXTraceW函数，在调试窗口输出格式化错误信息
HRESULT WINAPI DXTraceW(_In_z_ const WCHAR* strFile, _In_z_ DWORD dwLine, _In_ HRESULT hr, _In_opt_ const WCHAR* strMsg, _In_ bool bPopMsgbox);

//HR 宏
#if defined(DEBUG) | defined(_DEBUG)
#ifndef HR
#define HR(x)                                                \
{                                                            \
	HRESULT hr = (x);                                        \
	if (FAILED(hr))                                          \
	{                                                        \
		DXTraceW(__FILEW__, (DWORD)__LINE__, hr, L#x, true); \
	}                                                        \
}
#endif
#else
#ifndef HR
#define HR(x) (x)
#endif
#endif

#endif
