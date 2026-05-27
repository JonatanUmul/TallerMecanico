#include "MenuPrincipal.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace TallerMecanico;

[STAThreadAttribute]
int main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MenuPrincipal());
	return 0;
}