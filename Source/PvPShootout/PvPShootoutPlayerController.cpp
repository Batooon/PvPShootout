// Copyright Epic Games, Inc. All Rights Reserved.


#include "PvPShootoutPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "PvPShootoutCharacter.h"
#include "Engine/LocalPlayer.h"
#include "EnhancedInputComponent.h"
#include "SessionSubsystem.h"
#include "Kismet/GameplayStatics.h"

void APvPShootoutPlayerController::PointerPressed()
{
    UE_LOG(LogTemp, Display, TEXT("Character Pressed"));
    if(const APvPShootoutCharacter* Ch = Cast<APvPShootoutCharacter>(GetPawn()))
    {
        UE_LOG(LogTemp, Display, TEXT("Character Pressed"));
        if(Ch->Interaction)
        {
            UE_LOG(LogTemp, Display, TEXT("Character Pressed"));
            Ch->Interaction->PressPointerKey(EKeys::LeftMouseButton);
        }
    }
}

void APvPShootoutPlayerController::BeginPlay()
{
	Super::BeginPlay();

    if(!IsLocalPlayerController())
        return;

	// get the enhanced input subsystem
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		// add the mapping context so we get controls
		Subsystem->AddMappingContext(InputMappingContext, 0);
	}
}

void APvPShootoutPlayerController::PointerRelease()
{
    if(const APvPShootoutCharacter* Ch = Cast<APvPShootoutCharacter>(GetPawn()))
    {
        if(Ch->Interaction)
        {
            Ch->Interaction->ReleasePointerKey(EKeys::LeftMouseButton);
        }
    }
}

void APvPShootoutPlayerController::TryCreateAndJoinNewSession()
{
    UGameInstance* gameInstance=GetWorld()->GetGameInstance();
    USessionSubsystem* sessionSubsystem=gameInstance->GetSubsystem<USessionSubsystem>();
    sessionSubsystem->OnCreateSessionCompleteEvent.AddDynamic(this, &ThisClass::JoinSessionIfSucceeded);
    sessionSubsystem->CreateSession(5, false);
}

void APvPShootoutPlayerController::JoinSessionIfSucceeded(bool success)
{
    UGameInstance* gameInstance=GetWorld()->GetGameInstance();
    USessionSubsystem* sessionSubsystem=gameInstance->GetSubsystem<USessionSubsystem>();
    sessionSubsystem->OnCreateSessionCompleteEvent.RemoveDynamic(this, &ThisClass::JoinSessionIfSucceeded);
    if(success)
    {
        UGameplayStatics::OpenLevel(GetWorld(), "StarterMap", true, "listen");
    }
}

void APvPShootoutPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    if(UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
    {
        EnhancedInputComponent->BindAction(Interact, ETriggerEvent::Triggered, this, &APvPShootoutPlayerController::PointerPressed);
        EnhancedInputComponent->BindAction(Interact, ETriggerEvent::Completed, this, &APvPShootoutPlayerController::PointerRelease);
    }
}
