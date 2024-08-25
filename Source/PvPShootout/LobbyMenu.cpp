// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyMenu.h"

#include "PvPShootoutPlayerController.h"
#include "Kismet/GameplayStatics.h"

void ULobbyMenu::NativeConstruct()
{
    Super::NativeConstruct();

    APlayerController* playerController=UGameplayStatics::GetPlayerController(this, 0);
    ShootoutPlayerController=Cast<APvPShootoutPlayerController>(playerController);

    if(CreateSessionButton)
    {
        CreateSessionButton->OnClicked.AddDynamic(this, &ThisClass::OnCreateSessionButtonClick);
    }
}

void ULobbyMenu::OnCreateSessionButtonClick()
{
    ShootoutPlayerController->TryCreateAndJoinNewSession();
}
