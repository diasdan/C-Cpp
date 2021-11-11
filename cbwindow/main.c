#if defined(UNICODE) && !defined(_UNICODE)
	#define_UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
	#define UNICODE
#endif	

/* Um esqueleto mínimo Windows */

#include <windows.h>
#include <stdio.h>

LRESULT CALLBACK WindowFunc(HWND, UINT, WPARAM, LPARAM);

char szWinName[] = "Janela";

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpszArgs, int nWinMode)
{

    HWND hwnd;
    MSG msg;
    WNDCLASS wcl;

    /* Define uma classe de janela */
    wcl.hInstance = hInstance; /* handle desta instância */
    wcl.lpszClassName = szWinName; /* Nome da classe de janela */
    wcl.lpfnWndProc = WindowFunc; /* função de janela */
    wcl.style = 0; /* estilo padrão */

    wcl.hIcon = LoadIcon(NULL, IDI_APPLICATION); /* estilo de ícone */

    wcl.hCursor = LoadCursor(NULL, IDC_ARROW); /* estilo de cursor */

    wcl.lpszMenuName = NULL; /* sem menu */

    wcl.cbClsExtra = 0; /* nenhuma informação */
    wcl.cbWndExtra = 0; /*extra é necessária*/

    /* Registra a classe de janela */
    if (!RegisterClass(&wcl)) return 0;

    /* Com a classe janela registrada, pode ser criada uma janela */
    hwnd = CreateWindow(
        szWinName, /* nome da classe da janela */
        "Janela", /* título */
        WS_OVERLAPPEDWINDOW, /* estilo da janela - normal */
        CW_USEDEFAULT, /* coordenada X - deixe o Windows decidir */
        CW_USEDEFAULT, /* coordenada Y - deixe o Windows decidir */
        CW_USEDEFAULT, /* largura - deixe o Windows decidir */
        CW_USEDEFAULT, /* altura - deixe o Windows decidir */
        HWND_DESKTOP, /* nenhuma janela-pai */
        NULL, /* sem menu */
        hInstance, /* handle desta instâncias do programas */
        NULL /* nenhum argumento adcional */
    );


    /* Exibe a janela */
    ShowWindow(hwnd, nWinMode);
    UpdateWindow(hwnd);

    /* Cria a repetição de mensagens */
    while(GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg); /* permite uso do teclado */
        DispatchMessage(&msg); /* retorna o controle ao Windows */
    }
    return msg.wParam;
}

    /* Esta função é chamada pelo Windows e recebe mensagens
        da fila de mensagens */

    LRESULT CALLBACK WindowFunc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
    {
        switch (message) {
            case WM_DESTROY: /* encerra o programa */
                PostQuitMessage(0);
                break;
            default:
                /* Deixe o Windows processar quaisquer mensagens
                    não especificadas no comando switch acima */
                return DefWindowProc(hwnd, message, wParam, lParam);
        }
        return 0;
    }

