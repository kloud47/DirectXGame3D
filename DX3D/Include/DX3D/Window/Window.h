#pragma once  
#include <DX3D/Core/Base.h>


namespace dx3dEngine  
{  
	class Window : public Base  
	{  
	public:  
		explicit Window(const WindowDesc& desc);
		virtual ~Window() override;  
	protected:  
		void* m_handle{};  
		Rect m_size{};
	};  
}
