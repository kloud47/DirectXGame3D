#include <DX3D/Game/Game.h>
#include <Windows.h>

void dx3dEngine::Game::run()
{
	while (m_isRunning)
	{
		MSG msg{};
		while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))// PeekMessage retrieves messages from the message queue
		{
			if (msg.message == WM_QUIT)
			{
				m_isRunning = false;
				break;
			}
			TranslateMessage(&msg);// Translate virtual key messages into character messages
			DispatchMessageW(&msg);// Dispatch the message to the window procedure
		} 
		OnInternalUpdate(); // Sleep to avoid busy waiting // It happens once per "frame" or "tick" of your main game loop
	}
}