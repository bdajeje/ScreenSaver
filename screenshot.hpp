#ifndef SCREENSHOT_H
#define SCREENSHOT_H

#include <string>

class ScreenShot final
{
	public:

		static bool captureScreen(const std::string& filepath);
		static const std::string& error() { return s_error; }

	protected:

		static std::string s_error;
};

#endif // SCREENSHOT_H
