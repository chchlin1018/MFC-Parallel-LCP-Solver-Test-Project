// OpenGLContext.cpp : implementation of the COpenGLContext class
//

#include "pch.h"
#include "OpenGLContext.h"
#include <gl/GL.h>

#pragma comment(lib, "opengl32.lib")

COpenGLContext::COpenGLContext() : m_hWnd(NULL), m_hDC(NULL), m_hRC(NULL)
{
}

COpenGLContext::~COpenGLContext()
{
    Destroy();
}

bool COpenGLContext::Create(HWND hWnd)
{
    m_hWnd = hWnd;
    m_hDC = GetDC(m_hWnd);

    PIXELFORMATDESCRIPTOR pfd = {
        sizeof(PIXELFORMATDESCRIPTOR),
        1,
        PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
        PFD_TYPE_RGBA,
        32,
        0, 0, 0, 0, 0, 0,
        0,
        0,
        0,
        0, 0, 0, 0,
        24,
        8,
        0,
        PFD_MAIN_PLANE,
        0,
        0, 0, 0
    };

    int pixelFormat = ChoosePixelFormat(m_hDC, &pfd);
    SetPixelFormat(m_hDC, pixelFormat, &pfd);

    m_hRC = wglCreateContext(m_hDC);
    wglMakeCurrent(m_hDC, m_hRC);

    return true;
}

void COpenGLContext::Destroy()
{
    if (m_hRC)
    {
        wglMakeCurrent(NULL, NULL);
        wglDeleteContext(m_hRC);
        m_hRC = NULL;
    }

    if (m_hDC)
    {
        ReleaseDC(m_hWnd, m_hDC);
        m_hDC = NULL;
    }
}

void COpenGLContext::Render()
{
    glClearColor(0.0f, 0.0f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // TODO: Add your rendering code here
}

void COpenGLContext::Resize(int width, int height)
{
    glViewport(0, 0, width, height);
}

