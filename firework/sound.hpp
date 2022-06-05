#pragma once
#include <string>
#include <windows.h>

#include "mmsystem.h"
#pragma comment(lib,"winmm.lib")

namespace animation
{
	class sound
	{
	public:
		sound(std::wstring path, long p1, long p2);
		void Play();
		~sound();
	private:
		std::wstring m_path;			// ÒôÀÖÎÄ¼şÂ·¾¶
		TCHAR		 m_commandBuff[64];
		long		 m_startMs;
		long		 m_endMs;

		bool		 openFlag;
	};
}

#pragma once
