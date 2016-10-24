#include <d3d9.h>

LPDIRECT3D9 g_pD3D = NULL;
LPDIRECT3DDEVICE9 g_pd3dDIVICE = NULL;

HRESULT InitD3D (HWND hWnd)
{
        if(NULL == (g_pD3D = Direct3DCreate9(D3D_SDK_VERSION)))
                return E_FAIL;
                
        D3DPRESENT_PARAMETERS d3dpp;
        ZeroMemory(&d3dpp, sizeof(d3dpp));
        d3dpp.Windowed = TRUE;
        d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
        d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
        
        if()
        {
            retorn E_FAIL;
        }
}

