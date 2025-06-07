#include <DX3D/CoreMinimal.h>

int main()
{
	try
	{
		dx3dEngine::Game game{};
		game.run();
	}
	catch (const std::runtime_error&)
	{
		return EXIT_FAILURE;
	}
	catch (const std::exception&)
	{
		return EXIT_FAILURE;
	}
	catch (...)
	{
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}