#include <windows.h>
#include <gl\gl.h>
#include <gl\glu.h>
#include <glaux.h>
#include <conio.h>

HGLRC hRC=NULL;
HDC hDC=NULL;
HWND hWnd=NULL;
HINSTANCE hinstance;

bool keys[256];
bool active=true;
bool fullscreen=true;

      glColor3d(1,0,0,1)
      auxSolidSphere(1);
