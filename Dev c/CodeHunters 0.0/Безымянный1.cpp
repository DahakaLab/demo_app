//-----------------------------------------------------------------------------
// Файл: CreateDevice.cpp
//
// Описание: Это первый туториал по использованию Direct3D. В этом туториале всё что
//       мы делаем - это создаём Direct3D устройство и используем его для очистки
//       окна.
//
// Copyright (c) Micro$oft Corporation. All rights reserved.
//-----------------------------------------------------------------------------
#include <d3d9.h>




//-----------------------------------------------------------------------------
// Глобальные переменные
//-----------------------------------------------------------------------------
LPDIRECT3D9             g_pD3D       = NULL; // Используется для создания D3D устройства
LPDIRECT3DDEVICE9       g_pd3dDevice = NULL; // Наше устройство рендеринга




//-----------------------------------------------------------------------------
// Имя: InitD3D()
// Описание: Инициализация Direct3D
//-----------------------------------------------------------------------------
HRESULT InitD3D( HWND hWnd )
{
    // Создаём D3D объект, который необходим для создания D3D устройства.
    if( NULL == ( g_pD3D = Direct3DCreate9( D3D_SDK_VERSION ) ) )
        return E_FAIL;

    D3DPRESENT_PARAMETERS d3dpp; 
    ZeroMemory( &d3dpp, sizeof(d3dpp) );
    d3dpp.Windowed = TRUE;
    d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
    d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;

    if( FAILED( g_pD3D->CreateDevice( D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd,
                                      D3DCREATE_SOFTWARE_VERTEXPROCESSING,
                                      &d3dpp, &g_pd3dDevice ) ) )
    {
        return E_FAIL;
    }

    // Если устройство создано - возвращаем S_OK

    return S_OK;
}




//-----------------------------------------------------------------------------
// Имя: Cleanup()
// Описание: Освобождаем все ранее инициализируемые объекты
//-----------------------------------------------------------------------------
VOID Cleanup()
{
    if( g_pd3dDevice != NULL) 
        g_pd3dDevice->Release();

    if( g_pD3D != NULL)
        g_pD3D->Release();
}




//-----------------------------------------------------------------------------
// Имя: Render()
// Описание: Рисование сцены
//-----------------------------------------------------------------------------
VOID Render()
{
    if( NULL == g_pd3dDevice )
        return;

    // Очистка backbuffer'а в голубой цвет
    g_pd3dDevice->Clear( 0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(78,124,255), 1.0f, 0 );
    
    // начало сцены
    if( SUCCEEDED( g_pd3dDevice->BeginScene() ) )
    {
        // Рендеринг объектов сцены должен находиться здесь
    
        // Конец сцены
        g_pd3dDevice->EndScene();
    }

    // Выводим содержимое backbuffer'a на экран
    g_pd3dDevice->Present( NULL, NULL, NULL, NULL );
}




//-----------------------------------------------------------------------------
// Имя: MsgProc()
// Описание: Обработка сообщений
//-----------------------------------------------------------------------------
LRESULT WINAPI MsgProc( HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam )
{
    switch( msg )
    {
        case WM_DESTROY:
            Cleanup();
            PostQuitMessage( 0 );
            return 0;

        case WM_PAINT:
            Render();
            ValidateRect( hWnd, NULL );
            return 0;
    }

    return DefWindowProc( hWnd, msg, wParam, lParam );
}




//-----------------------------------------------------------------------------
// Имя: WinMain()
// Описание: Точка входа приложения
//-----------------------------------------------------------------------------
INT WINAPI WinMain( HINSTANCE hInst, HINSTANCE, LPSTR, INT )
{
    // Регистрируем класс окна
    WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, MsgProc, 0L, 0L, 
                      GetModuleHandle(NULL), NULL, NULL, NULL, NULL,
                      "D3D Tutorial", NULL };
    RegisterClassEx( &wc );

    // Создание окна программы
    HWND hWnd = CreateWindow( "D3D Tutorial", "CodeHunter 00_01", 
                              WS_OVERLAPPEDWINDOW, 0, 0, 1024, 768,
                              GetDesktopWindow(), NULL, wc.hInstance, NULL );

    // Инициализация Direct3D
    if( SUCCEEDED( InitD3D( hWnd ) ) )
    { 
        // Показываем окно
        ShowWindow( hWnd, SW_SHOWDEFAULT );
        UpdateWindow( hWnd );

        // Ввод петли сообщений
        MSG msg; 
        while( GetMessage( &msg, NULL, 0, 0 ) )
        {
            TranslateMessage( &msg );
            DispatchMessage( &msg );
        }
    }

    UnregisterClass( "D3D Tutorial", wc.hInstance );
    return 0;
}



