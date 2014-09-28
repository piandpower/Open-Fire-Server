

#include "Prepare.h"
#include "PrepareGameMode.h"
#include "PreparePlayerController.h"

APrepareGameMode::APrepareGameMode(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	PlayerControllerClass = APreparePlayerController::StaticClass();
}


