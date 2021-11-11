#include <windows.h>
#include <stdio.h>


LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
    case WM_SETFOCUS:
       printf( "WM_SETFOCUS\n" );
       return 0;

    case WM_ACTIVATE:
        printf( "WM_ACTIVATE\n" );
        return 0;

    case WM_CREATE:
        printf( "WM_CREATE\n" );
        return 0;

    case WM_PAINT:
        //printf( "WM_PAINT\n" );
        return 0;

    case WM_DESTROY:
        printf( "WM_DESTROY\n" );
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, int nCmdShow)
{
    const char * CLASS_NAME = TEXT("CLASSE_WINDOWS");

    WNDCLASS wc = { };

    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    //Cria a Janela

    HWND hwnd = CreateWindowEx(
        0,                      // Estilos de Janela Opcionais
        CLASS_NAME,
        TEXT("CO-mpanion Beta 1.0"),
        WS_OVERLAPPEDWINDOW,

        // Tamanho e posição

        CW_USEDEFAULT, // x
        CW_USEDEFAULT, // y
        CW_USEDEFAULT, // width
        CW_USEDEFAULT, // height
        NULL, //janela pai
        NULL, //menu
        hInstance, //instance Handler
        NULL
        );

    if (hwnd == NULL)
    {
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);

    // Run the message loop

    MSG msg = { };

    while(GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}
