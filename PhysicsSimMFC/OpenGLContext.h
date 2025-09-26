// OpenGLContext.h: interface for the COpenGLContext class
//

#pragma once

class COpenGLContext
{
public:
	COpenGLContext();
	virtual ~COpenGLContext();

	bool Create(HWND hWnd);
	void Destroy();
	void Render();
	void Resize(int width, int height);

private:
	HWND m_hWnd;
	HDC m_hDC;
	HGLRC m_hRC;
};

