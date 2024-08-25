﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PvPShootoutPlayerController.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "LobbyMenu.generated.h"

/**
 *
 */
UCLASS()
class PVPSHOOTOUT_API ULobbyMenu : public UUserWidget
{
    GENERATED_BODY()

protected:
    virtual void NativeConstruct() override;

private:
    UFUNCTION()
    void OnCreateSessionButtonClick();

    UPROPERTY(meta=(BindWidget))
    UButton* CreateSessionButton;

    TWeakObjectPtr<APvPShootoutPlayerController> ShootoutPlayerController;
};
