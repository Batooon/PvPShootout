// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/PlayerController.h"
#include "ShootoutPlayerController.generated.h"

/**
 *
 */
UCLASS()
class PVPSHOOTOUT_API AShootoutPlayerController : public APlayerController
{
    GENERATED_BODY()
protected:
    virtual void BeginPlay() override;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
    UInputMappingContext* InputMappingContext;

    UPROPERTY(EditDefaultsOnly, Category = "Weapon")
    TSubclassOf<AActor> RifleClass;

private:
    AActor* SpawnWeapon();
    void AssignWeapon();
};
