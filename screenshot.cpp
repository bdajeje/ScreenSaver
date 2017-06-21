#include "screenshot.hpp"

std::string ScreenShot::s_error;

bool ScreenShot::captureScreen(const std::string& filepath)
{
	// Check if 'import' command exists
	if(system("which import") != 0)
	{
		s_error = "You need to install 'imagemagick' before using this program.";
		return false;
	}

	if(system((std::string("import -window root ") + filepath).c_str()) != 0)
	{
		s_error = "Startup screenshot failed";
		return false;
	}

	return true;
}
