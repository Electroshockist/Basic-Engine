#include "Base/GameEngine.h"

int main(int argc, char* argv[]) {
	if(!GameEngine::GetInstance()->OnCreate(argc, argv)) {
		return EXIT_FAILURE;
	}

	if(!GameEngine::GetInstance()->Run()) {
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}